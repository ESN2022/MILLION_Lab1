#include <system.h>
#include <unistd.h>
#include <altera_avalon_pio_regs.h>

int main() {
    // PIO_0_BASE defined in system.h
    unsigned char enable, state = 0b1;

    while (1) {
        enable = IORD_ALTERA_AVALON_PIO_DATA(PIO_1_BASE);
	if (enable) {
            IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, state);
	    // might be a bit overkill...
            state = (state << 1) | (state >> (sizeof(state)*8 - 1));
            usleep(250000);
        }
        // check the button every 100 ms
	usleep(100000);
    }
    return 0;
}
