#include "libtape.h"
#include <stdio.h>

int main(void) {
  Tape t;
  init_tape(&t, 8);

  // Writing data to tape
  unsigned char name[7] = "Alice";
  for (size_t i = 0; i < 7; i++) {
    write_at_head(&t, name[i]);
    move_right(&t);
  };

  // Reading data from tape
  for (size_t i = 0; i < 7; i++) {
    unsigned char content = read_tape(&t, i);
    printf("%c", content);
  }
  printf("\n");
 

  free_tape(&t);

  return 0;
}
