#include <system.h>
#include <unistd.h>
#include <altera_avalon_pio_regs.h>

int main() {
    // PIO_0_BASE defined in system.h
    unsigned char state = 0b1;
    while (1) {
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, state);
	// might be a bit overkill...
        state = (state << 1) | (state >> (sizeof(state)*8 - 1));
        usleep(250000);
    }
    return 0;
}
