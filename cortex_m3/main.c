void io_init(void);
void sysclock(void);
void start_echo(void);
void app_loop(void);

int main(void)
{
    sysclock();
    io_init();
    start_echo();
    app_loop();
    
}