#include <stdint.h>
void PendSV_handler(void) __attribute__((naked));
void PendSV_handler(void)
{
    __asm volatile ("cpsid i" ::: "memory");
    __asm volatile ("mrs r0, psp" ::: );
#if defined(__thumb2__)
    __asm volatile(
        "stmdb   r0!,{r4-r11}\n"
        "msr     psp,r0\n"
        "pop     {r4-r11}\n"
    );
#elif defined(__thumb__)
    __asm volatile(
        "sub    r0,#16\n"
        "stmia  r0!,{r4-r7}\n"
        "mov    r4,r8\n"
        "mov    r5,r9\n"
        "mov    r6,r10\n"
        "mov    r7,r11\n"
        "sub    r0,#32\n"
        "msr    psp,r0\n"
        "stmia  r0!,{r4-r7}\n"
        "pop    {r4-r7}\n"
        "mov  r8,r4\n"
        "mov  r9,r5\n"
        "mov  r10,r6\n"
        "mov  r11,r7\n"
        "pop    {r4-r7}"

    );
#endif
    __asm volatile ("cpsie i\n"
        "ldr    r0,=0xfffffff9\n"
        "bx     r0\n"
    );
}

void SVCall_handler(void) __attribute__((naked));
void SVCall_handler(void) {
    __asm volatile ("cpsid i" ::: "memory");
    __asm volatile ("mrs r0, psp" ::: );
#ifdef __thumb2__
    __asm volatile (
        "push       {r4-r11}\n"
        "ldmia      r0!,{r4-r11}\n"
    );
#elif  defined(__thumb__) 
    __asm volatile ( 
        "push {r4-r7}\n"
        "mov  r4,r8\n"
        "mov  r5,r9\n"
        "mov  r6,r10\n"
        "mov  r7,r11\n"
        "push {r4-r7}\n"
        "ldmia r0!,{r4-r7}\n"
        "mov  r8,r4\n"
        "mov  r9,r5\n"
        "mov  r10,r6\n"
        "mov  r11,r7\n"
        "ldmia r0!,{r4-r7}\n"
    );
#endif

    __asm volatile (
        "msr   psp,r0\n"
        "cpsie i\n"
        "ldr        r0,=0xfffffffd\n"
        "bx r0\n"
    );

}
