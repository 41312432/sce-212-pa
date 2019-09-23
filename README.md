## Project #1: Assembly to Machine Code Translator

### ***Due on 11:59:59pm, October 4 (Friday)***

### Goal

Translate MIPS assembly code into corresponding MIPS machine code.

### Problem Specification

- You will implement a MIPS assembly translator that translate MIPS assembly into MIPS machine code one line at a time. To this end, you will extend the string parser submitted for PA0, implement a function that translate tokens into bits, and merge the bits into one 32-bit value.

- The framework will get a line of input from CLI, make it to lowercase and call `parse_command()`. After getting the number of tokens and `tokens[]` as of PA0, the framework will call `translate()` function with them. You should translate the tokens and return a 32-bit MIPS machine code.

- Your translator should support following MIPS assembly.

  | Name   | Opcode / opcode + funct |
  | ------ | ----------------------- |
  | `add`  | 0 + 0x20                |
  | `addi` | 0x08                    |
  | `sub`  | 0 + 0x22                |
  | `and`  | 0 + 0x21                |
  | `andi` | 0x0c                    |
  | `or`   | 0 + 0x25                |
  | `ori`  | 0x0d                    |
	| `nor`  | 0 + 0x27                |
  | `sll`  | 0 + 0x00                |
  | `srl`  | 0 + 0x02                |
  | `sra`  | 0 + 0x03                |
  | `lw`   | 0x23                    |
  | `sw`   | 0x2b                    |


- R-format instructions are inputted as follow:

- ```
  add s0 t1 gp    /* s0 <- t1 + gp */
  sub s4 s1 zero  /* s4 <- s1 + zero */
  sll s0 s2 3     /* s0 <- s2 << 3 */
  sra s1 t0 -5    /* s1 <- t0 >> -5 w/ sign extension */
  ```

- I-format instructions are the similar

- ```
  addi s1 s2 0x16 /* s1 <- s2 + 0x16 */
  lw t0 s1 32     /* Load t0 with a word at s1 + 32 */
  ```

- The registers are named as follow;

  | Name   | Number |
  | ------ | ------ |
  | zero   | 0      |
  | at     | 1      |
  | v0, v1 | 2-3    |
  | a0-a3  | 4-7    |
  | t0-t7  | 8-15   |
  | s0-s7  | 16-23  |
  | t8-t9  | 24-25  |
  | k1-k2  | 26-27  |
  | gp     | 28     |
  | sp     | 29     |
  | fp     | 30     |
  | ra     | 31     |

- `shamt` and immediate values are inputted as either (1) decimal numbers without any prefix or (2) hexadecimal numbers with `0x` as its prefix. Followings are the examples

- ```
  10    /* 10 */
  -22   /* -22 */
  0x1d  /* 29 */
  -0x42 /* -66 */
  ```

- Unspecified register and `shamt` parts should be 0. For example, `shamt` part should be 0b00000 for `add` instruction. Likewise, `rs` part should be 0b00000 for `sll` instruction.

### Submission / Grading

- Use [PAsubmit](https://sslab.ajou.ac.kr/pasubmit)  for submission
  - Will be tested using test inputs in testcase files `testcase-r-format`, `testcase-shifts`, and `testcase-i-format`.
- Source: pa1.c (160 pts)
- Git repository URL at git.ajou.ac.kr (10 pts)
	- Refer to https://www.youtube.com/channel/UC-Un-7jmeP-1OaHkS7awO0Q for using gitlab at Ajou University.
- Document: one PDF document (10 pts) including;
	- How do you translate the instructions
		- R-format / I-format
	- How do you translate the register names to corresponding register numbers
	- How do you convert shamt/immediate values from strings to corresponding numbers
	- Lesson learned
	- NO MORE THAN ***TWO*** PAGES
	- DO NOT INCLUDE COVER PAGE
		- No need to specify your name nor student ID on the document
  - DO NOT COMPRESS
	- OTHERWISE YOU WILL GET 0 pts for the report

### Hints/Tips

- You may reuse your `parse_command()` from PA0, or reimplement as we need. Now you can use any standard C library functions (Do NOT USE Windows-specific functions though otherwise it will make a compile error on the server).
- Following functions might help your implementation
  - `strcmp/strncmp`: For matching commands and register names
  - `strotol/strtoimax`: Coverting decimal/hexadecimal numbers (regardless of sign) in string to corresponding long/int numbers
- You can use `0b` prefix to specify a binary numberi directly
- You may use a mask to include `shamt` part in R-format and constant part in I-format into the machine code properly.
