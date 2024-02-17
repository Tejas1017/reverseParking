#include <LPC21xx.H>

extern void delay_sec(unsigned int);
extern void delay_ms(unsigned int);
extern void delay_us(unsigned int us);

extern void lcd_data(unsigned char);
extern void lcd_cmd(unsigned char);
extern void lcd_init(void);

extern void lcd_string(char *);
extern void lcd_scrolling(char *);
extern void lcd_circularscrolling(char *,char *);
extern void lcd_circularscrolling1(char *);

extern void lcd_integer(int);
extern void lcd_float(float);

extern void lcd_cgram(void);

extern void uart0_init(unsigned int);
extern void uart0_tx(unsigned char);
extern void uart0_tx_string(char *);
extern void uart0_tx_integer(int);
extern void uart0_tx_float(float);

extern unsigned char uart0_rx(void);
extern void uart0_rx_string(char *,unsigned int);

int uart0_integer(char *);

extern void adc_init(void);	 
extern int adc_read(int);

extern void config_vic(void);
extern void en_uart0_interrupt(void);
extern void en_can1_interrupt(void);
extern void enEintInterrupt(void);

typedef struct CAN1_msg{
	int id;
	char rtr;
	char dlc;
	int ByteA;
	int ByteB;
}CAN1;

extern void can1_init(void);
extern void can1_tx(CAN1);
extern void can1_rx(CAN1 *);

extern void ultrasonic_init(void);
extern void send_pulse(void);
extern unsigned int get_range(void);
