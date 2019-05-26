#include <mega32.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
// Declare your global variables here
char read_keypad()
{
    while(1)
    {
         PORTD.0=0;
         if(PIND.4==0)
         {
            return '7';
         }
         if(PIND.5==0)
         {
            return '8';
         }
         if(PIND.6==0)
         {
            return '9';
         }
         if(PIND.7==0)
         {
            return '/';
         }
         PORTD.0=1;   
         delay_ms(50);
         //******************************************************************
         PORTD.1=0;
         if(PIND.4==0)
         {
            return '4';
         }
         if(PIND.5==0)
         {
            return '5';
         }
         if(PIND.6==0)
         {
            return '6';
         }
         if(PIND.7==0)
         {
            return '*';
         }
         PORTD.1=1;
         delay_ms(50);
         //******************************************************************
         PORTD.2=0;
         if(PIND.4==0)
         {
            return '1';
         }
         if(PIND.5==0)
         {
            return '2';
         }
         if(PIND.6==0)
         {
            return '3';
         }
         if(PIND.7==0)
         {
            return '-';
         }
         PORTD.2=1;   
         delay_ms(50);
         //******************************************************************
         PORTD.3=0;
         if(PIND.4==0)
         {
            return 'c';
         }
         if(PIND.5==0)
         {
            return '0';
         }
         if(PIND.6==0)
         {
            return '=';
         }
         if(PIND.7==0)
         {
            return '+';
         }
         PORTD.3=1;   
         delay_ms(50);
         
    }
}
void cleaner(char* sumchar)
{
    int i=0;
    for(i=0;i<4;i++)
    {
        sumchar[i]='';
    }
}

void main(void)
{
 int number1,number2,sum,step=0;
 char func,mainfunc,sumchar[4],func2;

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(1<<PORTD7) | (1<<PORTD6) | (1<<PORTD5) | (1<<PORTD4) | (1<<PORTD3) | (1<<PORTD2) | (1<<PORTD1) | (1<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 3
// D5 - PORTC Bit 4
// D6 - PORTC Bit 5
// D7 - PORTC Bit 6
// Characters/line: 8
lcd_init(16);
lcd_clear();
while (1)
      {       
          PORTD.0=1;
          PORTD.1=1;
          PORTD.2=1;
          PORTD.3=1;
          func=read_keypad(); 
          func2=func; 
          switch(step)
          {
            case 0:    
                if((func>=48 && func<=57))
                {      
                    number1=atoi(&func2);
                    lcd_gotoxy(0,0);
                    lcd_puts(&func2);
                    step++;
                }
                else if(func=='c')
                {
                    step=0; 
                    number1=0;
                    number2=0;
                    sum=0;
                    cleaner(sumchar);
                    lcd_clear();
                } 
                else
                {
                    delay_ms(1);
                }
            break;
            case 1:    
                if((func=='+')||(func=='-')||(func=='/')||(func=='*'))
                {      
                    mainfunc=func;
                    lcd_gotoxy(1,0);
                    lcd_putchar(func);
                    step++;
                }
                else if(func=='c')
                {
                    step=0;   
                    number1=0;
                    number2=0;
                    sum=0; 
                    cleaner(sumchar);
                    lcd_clear();
                }     
                else
                {
                    delay_ms(1);
                }
            break;
            case 2:    
                if((func>=48 && func<=57))
                {      
                    number2=atoi(&func2);
                    lcd_gotoxy(2,0);
                    lcd_putchar(func);
                    step++;
                    switch(mainfunc)
                    {
                        case '+':
                            sum=number1+number2;
                        break;
                        case '-':
                            sum=number1-number2;
                        break;
                        case '*':
                            sum=number1*number2;
                        break;
                        case '/':
                            if(number2!=0)
                                sum=number1/number2;
                            else
                                sum=0;
                        break;
                    }  
                    lcd_gotoxy(3,0);
                    lcd_putchar('=');  
                    lcd_gotoxy(4,0);  
                    itoa(sum,sumchar);
                    lcd_puts(sumchar);
                    lcd_gotoxy(0,1);  
                    lcd_puts("press C to clear");                  
                }
                else if(func=='c')
                {
                    step=0;  
                    number1=0;
                    number2=0;
                    sum=0;   
                    cleaner(sumchar);
                    lcd_clear();
                } 
                else
                {
                    delay_ms(1);
                }
            break; 
            default :
                if(func=='c')
                {
                    step=0;  
                    number1=0;
                    number2=0;
                    sum=0;   
                    cleaner(sumchar);
                    lcd_clear();
                }
                else
                {
                    delay_ms(1);
                }
            break;
            
          }
          
      }
}
