# libtape

`libtape` is a lightweight C library for working with **tape-style data
streams and sequential storage utilities**.\
It provides a simple API for reading, writing, and managing sequential
data structures that behave similarly to tape devices.

--------------------------------------------

## Features

-   Sequential read/write utilities
-   Simple tape-like buffer abstraction
-   Minimal dependencies
-   Clean C API
-   Designed for embedding in other projects

--------------------------------------------

## Installation

Clone the repository:

``` bash
git clone https://github.com/tuan2090/libtape.git
cd libtape
```

Build using `make`:

``` bash
make
```

Install it!:

``` bash
sudo make install
```

--------------------------------------------

## Usage

Example basic usage:

``` c
#include "libtape.h"

int main() {
  Tape tape;
  init_tape(&tape, 3);

  // Enable debug mode
  t1.is_debug_mode_enable = true;

  write_at_head(&tape, 'A');
  move_right(&tape);
  write_at_head(&tape, 'B');
  move_right(&tape);
  write_at_head(&tape, 'C');

  show_tape_table(&tape);

  // Don't forget to free tape!!!!!
  free_tape(&tape);
  return 0;
}
```

Compile example:

``` bash
gcc example.c -ltape -o example
```

--------------------------------------------

## HOW TO UNINSTALL IT!

Just run this command!

``` bash
sudo make uninstall
```

--------------------------------------------

## Project Structure

    libtape/
    ├── src/        # Library source code
    ├── include/    # Public headers
    ├── examples/   # Example programs
    ├── Makefile
    └── README.md

--------------------------------------------

## Contributing

Contributions are welcome!

1.  Fork the repository
2.  Create a new branch
3.  Commit your changes
4.  Open a Pull Request

Please ensure code follows the existing style and includes tests where
appropriate.

--------------------------------------------

## License

This project is licensed under the **MIT License**.

See the `LICENSE` file for details.

--------------------------------------------

## Author

**Tuan Nguyen**
GitHub: https://github.com/tuan2090
