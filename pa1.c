/**********************************************************************
 * Copyright (c) 2019
 *  Sang-Hoon Kim <sanghoonkim@ajou.ac.kr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* To avoid security error on Visual Studio */
#define _CRT_SECURE_NO_WARNINGS

#define MAX_NR_TOKENS	32	/* Maximum length of tokens in a command */
#define MAX_TOKEN_LEN	64	/* Maximum length of single token */
#define MAX_ASSEMBLY	256 /* Maximum length of assembly string */

/***********************************************************************
 * translate
 *
 * DESCRIPTION
 *   Translate assembly represented in @tokens[] into a MIPS instruction.
 * This translate should support following 13 assembly commands
 *
 *	- add
 *	- addi
 *	- sub
 *	- and
 *	- andi
 *	- or
 *	- ori
 *	- nor
 *	- lw
 *	- sw
 *	- sll
 *	- srl
 *	- sra
 *
 * RETURN VALUE
 *   Return a 32-bit MIPS instruction
 *
 */
static unsigned int translate(int nr_tokens, char *tokens[])
{
	/* TODO:
	 * This is an example MIPS instruction. You should change it accordingly.
	 */
	return 0x02324020;
}


/***********************************************************************
 * parse_command
 *
 * DESCRIPTION
 *  Parse @assembly, and put each assembly token into @tokens[] and the number of
 *  tokes into @nr_tokens.
 *
 * A assembly token is defined as a string without any whitespace (i.e., *space*
 * and *tab* in this programming assignment). For exmaple,
 *   command = "  add t1   t2 s0 "
 *
 * then, nr_tokens = 4, and tokens is
 *   tokens[0] = "add"
 *   tokens[1] = "t0"
 *   tokens[2] = "t1"
 *   tokens[3] = "s0"
 *
 * You can assume that the input string is all lowercase for testing.
 *
 * RETURN VALUE
 *  Return 0 after filling in @nr_tokens and @tokens[] properly
 *
 */
static int parse_command(char *assembly, int *nr_tokens, char *tokens[])
{
	/* TODO:
	 * Followings are example code. You should delete them and implement
	 * your own code here
	 */
	tokens[0] = "add";
	tokens[1] = "t1";
	tokens[2] = "t2";
	tokens[3] = "s0";
	*nr_tokens = 4;

	return 0;
}


/***********************************************************************
 * release
 *
 * DESCRIPTION
 *  This function is invoked automatically by the framework when the
 *  translation is done for the line of assembly code. This is the best
 *  place to put your free() functions if you malloc'ed() previously.
 *  You may leave this function blank if you don't need.
 *
 */
static void release(int nr_tokens, char *tokens[])
{
}


/***********************************************************************
 * The main function of this program.
 * -------- DO NOT CHANGE ANY LINE BELOW THIS COMMENT ---------
 */
int main(int argc, const char *argv[])
{
	char assembly[MAX_ASSEMBLY] = { '\0' };

	printf("*********************************************************\n");
	printf("*          >> SCE212 MIPS translator  v0.01 <<          *\n");
	printf("*                                                       *\n");
	printf("*                                       .---.           *\n");
	printf("*                           .--------.  |___|           *\n");
	printf("*                           |.------.|  |=. |           *\n");
	printf("*                           || >>_  ||  |-- |           *\n");
	printf("*                           |'------'|  |   |           *\n");
	printf("*                           ')______('~~|___|           *\n");
	printf("*                                                       *\n");
	printf("*                                   Fall 2019           *\n");
	printf("*********************************************************\n\n");
	printf(">> ");

	while (fgets(assembly, sizeof(assembly), stdin)) {
		char *tokens[MAX_NR_TOKENS] = { NULL };
		int nr_tokens = 0;
		unsigned int machine_code;

		for (int i = 0; i < strlen(assembly); i++) {
			assembly[i] = tolower(assembly[i]);
		}

		if (parse_command(assembly, &nr_tokens, tokens) < 0)
			continue;

		machine_code = translate(nr_tokens, tokens);

		fprintf(stderr, "0x%08x\n", machine_code);

		release(nr_tokens, tokens);

		printf(">> ");
	}

	return 0;
}
