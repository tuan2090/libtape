#ifndef __TAPESCRIPT_HEADER__
#define __TAPESCRIPT_HEADER__

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Tape struct ---

typedef struct {
  size_t tape_length;
  unsigned char *tape_data;
  size_t head;
  bool is_debug_mode_enable;
  size_t run_step;
} Tape;

// --- Tape implement ---

void init_tape(Tape *tape, size_t size);
void free_tape(Tape *tape);

void halt(Tape *tape);
void move_right(Tape *tape);
void move_left(Tape *tape);
void head_jump(Tape *tape, size_t pos);

void increment_head_value(Tape *tape);
void decrement_head_value(Tape *tape);

void write_at_head(Tape *tape, unsigned char value);
unsigned char read_at_head(Tape *tape);

unsigned char read_tape(Tape *tape, size_t pos);

void show_tape_table(const Tape *tape);

#endif // __TAPESCRIPT_HEADER__
