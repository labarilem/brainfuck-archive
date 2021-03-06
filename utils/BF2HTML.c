/*
 * BF2HTML
 * Copyright (C) 2003 Thomas Cort
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/*
 * Program Name:  BF2HTML
 * Version:       1.0
 * Date:          2003-03-18
 * Description:   Converts Brainfuck source to HTML
 * License:       GPL
 * Web page:      http://www.brainfuck.ca
 * Download:      http://www.brainfuck.ca/BF2HTML.c
 * Source Info:   http://www.brainfuck.ca/downloads.html
 * Latest Ver:    http://www.brainfuck.ca/downloads.html
 * Documentation: None
 * Help:          tom@brainfuck.ca
 * Developement:  tom@brainfuck.ca
 * Bugs:          tom@brainfuck.ca
 * Maintainer:    Thomas Cort <tom@brainfuck.ca>
 * Developer:     Thomas Cort <tom@brainfuck.ca>
 * Interfaces:    Command Line
 * Source Lang:   C
 * Build Prereq:  None
 * Related Progs: BF2Texinfo
 * Category:      Software Development > Programming language conversion
 */

#include<stdio.h>

int main(int argc, char **argv) {

  int args,        /* index of current argument  */
      pc,          /* program counter            */
      prog_len;    /* length of program          */
  int p[32768];    /* storage space for the prog */

  FILE *stream, *fopen();

  /* For every arguement do some interpreting */
  /* Each arguement should be a filename      */
  for (args = 1; args < argc; args++) {

    /* Open da file */
    stream = fopen(argv[args], "r");

    prog_len = 0;
    
    /* read the file and store it in p[] */
    for (pc = 0; pc < 32768 && (p[pc] = getc(stream)) != EOF; pc++)
      prog_len++;

    /* reset the program counter */
    pc = 0;

    fclose(stream);

    /* print the HTML header information */
    printf("<HTML><HEAD><TITLE>%s</TITLE></HEAD><BODY>", argv[args]);

    /* visit every element that has part of the bf program in it */
    for(pc = 0; pc < prog_len; pc++) {

      /* '+' */
      if      (p[pc] == 43) printf("+");

      /* '-' */
      else if (p[pc] == 45) printf("-");

      /* '.' */
      else if (p[pc] == 46) printf(".");

      /* ',' */
      else if (p[pc] == 44) printf(",");

      /* '>' */
      else if (p[pc] == 62) printf("&gt;");

      /* '<' */
      else if (p[pc] == 60) printf("&lt;");

      /* '[' */
      else if (p[pc] == 91) printf("[");

      /* ']' */
      else if (p[pc] == 93) printf("]");

    }  
    printf("</BODY></HTML>\n");  
  }

  return 0;
}
