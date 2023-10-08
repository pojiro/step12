#include "defines.h"
#include "lib.h"
#include "serial.h"

int main(void) {
  serial_init(SERIAL_DEFAULT_DEVICE);

  puts((unsigned char *)"Hello World!\n");

  // clang-format off
  putxval(0x10, 0);   puts((unsigned char *)"\n");
  putxval(0xffff, 0); puts((unsigned char *)"\n");
  // clang-format on

  while (1)
    ;

  return 0;
}
