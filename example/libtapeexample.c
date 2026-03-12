#include "libtape.h"

int main(void) {
  Tape t1;
  init_tape(&t1, 8);
  t1.is_debug_mode_enable = true;

  write_at_head(&t1, 'H');
  move_right(&t1);
  write_at_head(&t1, 'e');
  move_right(&t1);
  write_at_head(&t1, 'l');
  move_right(&t1);
  write_at_head(&t1, 'l');
  move_right(&t1);
  write_at_head(&t1, 'o');
  move_right(&t1);

  show_tape_table(&t1);

  free_tape(&t1);
  return 0;
}
