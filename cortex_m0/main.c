
void rcc_config(void);
void io_init(void);

void app_init(void);
int main(void) __attribute__ ((naked));
int main(void)
{
    rcc_config();
    io_init();
    app_init();
}