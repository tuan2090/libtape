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

void init_tape(Tape *tape, size_t size) {
  tape->tape_length = size;

  // Allocate tape data
  tape->tape_data = malloc(sizeof(unsigned char) * size);

  // Check if tape data is not allocate
  if (tape->tape_data == NULL) {
    fprintf(stderr, "ERROR: Couldn't allocate memory for tape\n");
    exit(EXIT_FAILURE);
  }
 
  // Set all tape_data to 0
  memset(tape->tape_data, 0, tape->tape_length);

  tape->head = 0;
  tape->is_debug_mode_enable = false;
  tape->run_step = 0;
}

void free_tape(Tape *tape) {
  // Free tape data
  free(tape->tape_data);

  // Reset all data
  tape->tape_length = 0;
  tape->head = 0;
  tape->is_debug_mode_enable = false;
  tape->run_step = 0;
  tape->tape_data = NULL;
}

void head_halt(Tape *tape) {
  printf("HALTED\n");
  free_tape(tape);
  exit(EXIT_SUCCESS);
}

void move_right(Tape *tape) {
  // Check if tape head is move past tape length
  if (tape->head >= tape->tape_length-1) {
    // Display error messenger
    fprintf(stderr, "ERROR: Head attempted to move past tape length\n");

    // Exit and send exit failure signal
    exit(EXIT_FAILURE);
  }

  tape->head++;

  // If debug mode enable, run it
  if (tape->is_debug_mode_enable) {
    tape->run_step++;
    printf("Step %zu: Move right (head position: %zu)\n", tape->run_step, tape->head);
  }
}

void move_left(Tape *tape) {
  // Check if tape head is move below index 0
  if (tape->head == 0) {
    // Display error messenger
    fprintf(stderr, "ERROR: Head attempted to move below index 0\n");

    // Exit and send exit failure signal
    exit(EXIT_FAILURE);
  }

  tape->head--;

  // If debug mode enable, run it
  if (tape->is_debug_mode_enable) {
    tape->run_step++;
    printf("Step %zu: Move left (head position: %zu)\n", tape->run_step, tape->head);
  }
}

void head_jump(Tape *tape, size_t pos) {
  // Check if tape head is move below index 0 or past tape length
  if (tape->head >= tape->tape_length-1 || tape->head == 0) {
    // Display error messenger
    fprintf(stderr, "ERROR: Head attempted to move below index 0 or move past tape length\n");

    // Exit and send exit failure signal
    exit(EXIT_FAILURE);
  }

  tape->head = pos;
  
  // If debug mode enable, run it
  if (tape->is_debug_mode_enable) {
    tape->run_step++;
    printf("Step %zu: Jump to position %zu (head position: %zu)\n", tape->run_step, pos, tape->head);
  }
}

void write_at_head(Tape *tape, unsigned char value) {
  // If debug mode enable, run it
  if (tape->is_debug_mode_enable) {
    tape->run_step++;
    printf("Step %zu: Write '%c' value at head (head position: %zu)\n", tape->run_step, value, tape->head);
  }

  tape->tape_data[tape->head] = value;
}

const unsigned char read_at_head(Tape *tape) {
  // If debug mode enable, run it
  if (tape->is_debug_mode_enable) {
    tape->run_step++;
    printf("Step %zu: Read %zu(%c) value (head position: %zu)\n", tape->run_step, tape->head, tape->tape_data[tape->head], tape->head);
  }

  return tape->tape_data[tape->head];
}

const unsigned char read_tape(Tape *tape, size_t pos) {
  // Check if tape length is small than content position
  if (pos >= tape->tape_length) {
    // Display error messenger
    fprintf(stderr,
            "ERROR: The tape length should be larger than content position\n");

    // Exit and send exit failure signal
    exit(EXIT_FAILURE);
  }

  // If debug mode enable, run it
  if (tape->is_debug_mode_enable) {
    tape->run_step++;
    printf("Step %zu: Read %zu(%c) value (head position: %zu)\n", tape->run_step, pos, tape->tape_data[pos], tape->head);
  }

  return tape->tape_data[pos];
}

void show_tape_table(const Tape *tape) {
  printf("DEBUG TAPE \n\n");
  printf("Tape index | Hex  |  Dec  | Is Head? | ASCII\n");
  printf("-----------|------|-------|----------|------\n");

  for (size_t i = 0; i < tape->tape_length; i++) {
    // Display tape index, tape data (hexadecimal, decimal)
    printf("%10zu | 0x%02x | %5i | ", i, tape->tape_data[i], tape->tape_data[i]);

    // Check tape head position
    if (i == tape->head) {
      printf("######## | ");
    } else {
      printf("         | ");
    }

    // Check if tape data is printable
    if (isprint(tape->tape_data[i])) {
      // Display tape data (ASCII)
      printf("%c", tape->tape_data[i]);
    } else {
      // Display tape data (Not printable)
      printf(".");
    }

    // New line
    printf("\n");
  }
}
int main(void) {
  printf("Tape 1\n");
  Tape tape1;
  init_tape(&tape1, 8);
  tape1.is_debug_mode_enable = true;

  write_at_head(&tape1, 'H');
  move_right(&tape1);
  write_at_head(&tape1, 'e');
  move_right(&tape1);
  write_at_head(&tape1, 'l');
  move_right(&tape1);
  write_at_head(&tape1, 'l');
  move_right(&tape1);
  write_at_head(&tape1, 'o');
  move_right(&tape1);
  
  show_tape_table(&tape1);

  printf("Tape 2\n");
  Tape tape2;
  init_tape(&tape2, 8);
  tape2.is_debug_mode_enable = true;

  write_at_head(&tape2, 'W');
  move_right(&tape2);
  write_at_head(&tape2, 'o');
  move_right(&tape2);
  write_at_head(&tape2, 'r');
  move_right(&tape2);
  write_at_head(&tape2, 'l');
  move_right(&tape2);
  write_at_head(&tape2, 'd');
  move_right(&tape2);

  show_tape_table(&tape2);

  free_tape(&tape1);
  free_tape(&tape2);
  return 0;
}
