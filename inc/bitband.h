/*
at32f421 的bitband 地址　0x2000 0000~ 0x200f ffff以及0x4000 0000~0x400f ffff
GPIO的全部设备都不能使用bitband
*/
#ifndef BITBAND_H_8E8HR8EWHUW8
#define BITBAND_H_8E8HR8EWHUW8

typedef struct {
    volatile uint32_t bit[32];
} _BitBand;
// bit band PM0056 page 24
// 注意：内存bit band不能使用这个宏,因为编译器会把代码设计得很复杂
#define BITBAND(p) ((_BitBand *)(((uint32_t)(&(p)) & 0xfff00000) + 0x2000000 + (( (uint32_t) (&(p)) & 0x000fffff) * 32)))

#endif