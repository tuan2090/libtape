#include "libtape.h"

int main(void) {
  Tape t;
  init_tape(&t, 8);
  t.is_debug_mode_enable = true;

  write_at_head(&t, 'H');
  move_right(&t);
  write_at_head(&t, 'e');
  move_right(&t);
  write_at_head(&t, 'l');
  move_right(&t);
  write_at_head(&t, 'l');
  move_right(&t);
  write_at_head(&t, 'o');
  move_left(&t);
  increment_head_value(&t);
  move_left(&t);
  decrement_head_value(&t);

  show_tape_table(&t);

  free_tape(&t);
  return 0;
}
