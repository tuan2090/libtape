#include "libtape.h"

int main(void) {
  printf("Tape 1:\n");
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
  move_left(&t1);
  increment_head_value(&t1);
  move_left(&t1);
  decrement_head_value(&t1);

  show_tape_table(&t1);

  printf("Tape 2:\n");
  Tape t2;
  init_tape(&t2, 8);
  t2.is_debug_mode_enable = true;

  unsigned char name[7] = "Johnny";
  
  for (size_t i = 0; i < 7; i++) {
    write_at_head(&t2, name[i]);
    move_right(&t2);
  }

  show_tape_table(&t2);

  free_tape(&t1);
  free_tape(&t2);
  return 0;
}
