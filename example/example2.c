#include "libtape.h"

int main(void) {
  Tape t;
  init_tape(&t, 8);
  t.is_debug_mode_enable = true;

  unsigned char name[7] = "Johnny";

  for (size_t i = 0; i < 7; i++) {
    write_at_head(&t, name[i]);
    move_right(&t);
  }

  show_tape_table(&t);

  free_tape(&t);

  return 0;
}
