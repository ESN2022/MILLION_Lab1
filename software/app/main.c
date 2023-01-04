#include <system.h>
#include <unistd.h>
#include <altera_avalon_pio_regs.h>

int main() {
    // PIO_0_BASE defined in system.h
    unsigned char state = 0;
    while (1) {
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, state);
        state = ~state;
        usleep(1000000);
    }
    return 0;
}
