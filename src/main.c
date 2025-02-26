#include <at32f421.h>
#include <stdint.h>
int main(void)
{

}

static void abc(void)
{
    const struct devinfo{
        uint32_t magic1;
        uint32_t magic2;
        const uint8_t deviceInfo[9];
    } *dinfo=(struct devinfo *)(0x1000-32);
    if (dinfo->magic1 !=0 ||
        dinfo->magic2 !=2 ){
        return;
    }
}
void _init(void)
{
    abc();
}