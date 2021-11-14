#include <stdint.h>
void PendSV_handler(void) __attribute__((naked));
void PendSV_handler(void)
{
    __asm volatile ("cpsid i" ::: "memory");
    __asm volatile ("MRS r0, psp" ::: );
#if defined(__thumb2__)
    __asm volatile(
        "stmdb   r0!,{r4-r11}\n"
        "msr     psp,r0\n"
        "pop     {r4-r11}\n"
    );
    __asm volatile(
        "ldr     lr,=0xfffffff9\n"
    );
#endif
    __asm volatile ("cpsie i" : : : "memory");
    __asm volatile ("bx lr");
}

void SVCall_handler(void) __attribute__((naked));
void SVCall_handler(void) {
    __asm volatile ("cpsid i" ::: "memory");
    __asm volatile ("MRS r0, psp" ::: );
#ifdef __thumb2__
    __asm volatile (
        "push       {r4-r11}\n"
        "mrs        r0,psp\n"
        "ldmia      r0!,{r4-r11}\n"
        "msr        psp,r0\n"
        "ldr        lr,=0xfffffffd\n"
    );
#endif
    __asm volatile ("cpsie i" : : : "memory");
    __asm volatile ("bx lr");

}
