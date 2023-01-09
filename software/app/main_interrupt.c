#include <system.h>
#include <unistd.h>
#include <sys/alt_irq.h>
#include <io.h>
#include <alt_types.h>
#include "sys/alt_sys_init.h"
#include <altera_avalon_pio_regs.h>

volatile unsigned char speed = 0x00;

int alt_irq_register(alt_u32 id, void* context, void (*isr)(void*, alt_u32));

static void irqhandler(void* context, alt_u32 id)
{
    // Instructions to handle IRQ goes here !
    if (id == PIO_1_IRQ) {
        speed = IORD_ALTERA_AVALON_PIO_DATA(PIO_1_BASE) & 0x0F;
        // deassert the irq signal
        // https://sites.ualberta.ca/~delliott/ece492/appnotes/2014w/G3_PIO_Interrupt/G3_PIO_interrupt.pdf
        IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0b1111);
    }
}

int main() {
    // PIO_0_BASE/PIO_1_BASE defined in system.h
    unsigned char state = 0b1;
    
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0xF);
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0xF);
    alt_irq_register(PIO_1_IRQ, NULL, (void*)irqhandler);

    // call it one time to set the state of speed
    irqhandler(NULL, PIO_1_IRQ);

    while (1) {
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, state);
	// might be a bit overkill...
        state = (state << 1) | (state >> (sizeof(state)*8 - 1));
        usleep(1400000 - (speed*90750));
    }
    return 0;
}
