#include "conf.h"
#ifdef 

#ifdef TMR1_CLK_EN
#define CRM_APB2EN_11 (1 << 11)
#else
#define CRM_APB2EN_11 0
#endif
#define CRM_APB2EN_VALUE CRM_APB2EN_0 | CRM_APB2EN_9
void crm_init(void)
{
#ifdef CRM_APB1RST_VALUE
    CRM->apb1rst=CRM_APB1RST_VALUE;
#endif
#ifdef CRM_APB2RST_VALUE
    CRM->apb2rst=CRM_APB2RST_VALUE;
#endif
#ifdef CRM_AHBRST_VALUE
    CRM->ahbrst=CRM_AHBRST_VALUE;
#endif
#ifdef CRM_APB1EN_VALUE
    CRM->apb1en=CRM_APB1EN_VALUE;
#endif
#ifdef CRM_APB2EN_VALUE
    CRM->apb2en=CRM_APB2EN_VALUE;
#endif
#ifdef CRM_AHBEN_VALUE
    CRM->ahben=CRM_AHBEN_VALUE;
#endif
}
