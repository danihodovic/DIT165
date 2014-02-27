/* ====================================
File name: main-6-2.c
Date: Feb 27, 2014
Group Number: 13
Members that contributed:
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <35047>]
====================================== */
// Following TYPES is defined, local in this modul,  and could be used to specify type of interrupt with
// the global variable int interruptType. ( Note : The name is convered to _interruptType by the C-compiler)

#define NO_IRQ_TYPE 0
#define SENSOR      1
#define CLOSED_DOOR 2
#define OPENED_DOOR 4

#define TIME_OUT    32   // Common define in the assembly file is needed

// Codes for closing/opening the door.
#define OPEN_DOOR   0x01
#define CLOSE_DOOR  0x02

// Register addresses
#define ML13_IRQ_Control 0x0B01

//Macros for read and write in ML13 register.
#define REG8(x) *((unsigned char *)(x))

//Macro for write IRQ routin adress in vector table.
#define  SET_IRQ_VECTOR(interrupt_handler, address)    *((unsigned int *) address )= &(interrupt_handler)

//For debugging
#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0)
//
//Declaration of functions in this module
void initIRQ();

//Declaration of functions in ML13_irq_asm_routin.s12
extern void standby(void);
extern void timerSetup(void);
extern void setTimeout(int);

//Variable for knowing the type of the interrupt
//Defined the cases in main
int interruptType;
//The two addresses we're reading and writing to
char* interrupt_address = 0x0B01;
char* base_address = 0x0B00;

void main() {

    puts("Started...");
    initIRQ();
    while(1)    {
        interruptType = NO_IRQ_TYPE;
        standby();
        switch(interruptType)   {
            case SENSOR :
                *base_address = 0x01;
                break;
            case OPENED_DOOR :
                setTimeout(1);
                break;
            case TIME_OUT :
                *base_address = 0x02;
                break;
            default :
            break;
        }
    }

}

__interrupt void  ML13_interrupt(void)  {
    char c = *interrupt_address & 0x3F;
    printf ("Leading text "BYTETOBINARYPATTERN, BYTETOBINARY(c));
    puts("\t-Call from interrupt");

    if(c & 0x08)    {
        interruptType = SENSOR;
    }else if(c & 0x01)  {
        interruptType = OPENED_DOOR;
    }
    //Clears interrupt register
    *interrupt_address = 0x01;
}

void initIRQ(void){
  SET_IRQ_VECTOR(ML13_interrupt, 0x3FF2);
  __asm(" CLI");
  REG8(ML13_IRQ_Control)= 0x01;
  timerSetup();
  puts("IRQ has been initiated");
}
