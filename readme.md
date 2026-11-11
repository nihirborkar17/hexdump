# MyHexdump

A simple `hexdump` utility implemented in C that reads data from standard input and displays its hexadecimal and ASCII representations.

The project is intended as a hands-on exercise in C programming, memory management, byte-level data processing, and standard I/O.

## Features

- Reads input from standard input using `getchar()`.
- Processes data in chunks of 16 bytes.
- Displays memory offsets in hexadecimal.
- Prints each byte in two-digit hexadecimal format.
- Displays a corresponding ASCII representation.
- Replaces non-printable characters with `.`.
- Handles the final incomplete 16-byte block.

## Output Format

Each output row represents up to 16 bytes.

\`\`\`text
00000000 48 65 6c 6c 6f 20 57 6f 72 6c 64 21             | Hello World!....
\`\`\`

The output contains:

- **Offset:** Position of the first byte in the current row.
- **Hexadecimal:** Byte values represented in hexadecimal.
- **ASCII:** Printable characters represented directly; non-printable characters replaced with `.`.

## Compilation

Compile the source code using GCC:

\`\`\`bash
gcc -Wall -Wextra -Wpedantic -std=c17 -g myhexdump.c -o myhexdump
\`\`\`

## Usage

Read input from a text file:

\`\`\`bash
./myhexdump < input.txt
\`\`\`

Read input directly:

\`\`\`bash
echo "Hello World!" | ./myhexdump
\`\`\`

Inspect a binary file:

\`\`\`bash
./myhexdump < file.bin
\`\`\`

## Concepts Practiced

- C standard input and output (\`getchar\`, \`printf\`)
- Byte-level data processing
- Hexadecimal representation
- Character encoding and printable ASCII
- Buffer management
- Array indexing and modulo operations
- Processing fixed-size chunks
- Handling incomplete input blocks

## Future Improvements

- Add command-line file argument support.
- Display accurate offsets for all input bytes.
- Improve handling of empty input and incomplete buffers.
- Support configurable bytes per row.
- Add proper error handling and memory management.

## Project Goal

Build a basic understanding of how data is represented and inspected at the byte level, similar to tools used in systems programming, debugging, and binary file analysis.
