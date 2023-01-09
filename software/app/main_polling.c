#include <system.h>
#include <unistd.h>
#include <altera_avalon_pio_regs.h>

int main() {
    // PIO_0_BASE/PIO_1_BASE defined in system.h
    unsigned char state = 0b1;
    unsigned char speed = 0x00;

    while (1) {
        speed = IORD_ALTERA_AVALON_PIO_DATA(PIO_1_BASE) & 0x0F;
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, state);
	// might be a bit overkill...
        state = (state << 1) | (state >> (sizeof(state)*8 - 1));
        usleep(1400000 - (speed*90000));
    }
    return 0;
}
