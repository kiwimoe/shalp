#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int t_out(char *fmt, ...) {
	char prt_buf[1024];
	va_list args;
	va_start(args, fmt);
	vsprintf(prt_buf, fmt, args);
	va_end(args);
	vfprintf(stdout, prt_buf, args);
}

int w_out(FILE *file, char *fmt) {
	return fprintf(file, fmt);
}

void read_code(char *file) {
	FILE *fp = fopen(file, "r");
	if (fp == NULL) {
		t_out("error: file not found\n");
		return;
	}
	char c;
	while (!feof(fp)) {
		c = fgetc(fp);

		switch (c) {
			case 'q': t_out("a"); break;
			case '?': t_out("b"); break;
			case '#': t_out("c"); break;
			case 'h': t_out("d"); break;
			case '_': t_out("e"); break;
			case 'l': t_out("f"); break;
			case '-': t_out("g"); break;
			case '$': t_out("h"); break; 
			case 'x': t_out("i"); break; 
			case 'b': t_out("j"); break; 
			case '&': t_out("k"); break;
			case 'w': t_out("l"); break;
			case '!': t_out("m"); break;
			case 's': t_out("n"); break;
			case 'n': t_out("o"); break;
			case 'a': t_out("p"); break;
			case '+': t_out("q"); break;
			case '~': t_out("r"); break;
			case '[': t_out("s"); break;
			case '"': t_out("t"); break;
			case '>': t_out("u"); break;
			case ';': t_out("v"); break;
			case '|': t_out("w"); break;
			case '<': t_out("x"); break;
			case ',': t_out("y"); break;
			case '.': t_out("z"); break;
			case '=': t_out(" "); break;
			case '\\': t_out("\n"); break;
			case '(': t_out(","); break;
			case '@': t_out("."); break;
			case '0': t_out("!"); break;
			default: break;
		}
	}
}


// Just the same code, with oppoiste conversation and write stdout to file xd
void make_small_hand(char *file1, char *file2) {
	FILE *infile = fopen(file1, "r");
	if (infile == NULL) {
		t_out("error: file not found\n");
		return;
	}
	FILE *outfile = fopen(file2, "w");
	char c;
	while (!feof(infile)) {
		c = fgetc(infile);

		switch (c) {
			case 'a': w_out(outfile, "q"); break;
			case 'b': w_out(outfile, "?"); break;
			case 'c': w_out(outfile, "#"); break;
			case 'd': w_out(outfile, "h"); break;
			case 'e': w_out(outfile, "_"); break;
			case 'f': w_out(outfile, "l"); break;
			case 'g': w_out(outfile, "-"); break;
			case 'h': w_out(outfile, "$"); break; 
			case 'i': w_out(outfile, "x"); break; 
			case 'j': w_out(outfile, "b"); break; 
			case 'k': w_out(outfile, "&"); break;
			case 'l': w_out(outfile, "w"); break;
			case 'm': w_out(outfile, "!"); break;
			case 'n': w_out(outfile, "s"); break;
			case 'o': w_out(outfile, "n"); break;
			case 'p': w_out(outfile, "a"); break;
			case 'q': w_out(outfile, "+"); break;
			case 'r': w_out(outfile, "~"); break;
			case 's': w_out(outfile, "["); break;
			case 't': w_out(outfile, "\""); break;
			case 'u': w_out(outfile, ">"); break;
			case 'v': w_out(outfile, ";"); break;
			case 'w': w_out(outfile, "|"); break;
			case 'x': w_out(outfile, "<"); break;
			case 'y': w_out(outfile, ","); break;
			case 'z': w_out(outfile, "."); break;
			case ' ': w_out(outfile, "="); break;
			case '\n': w_out(outfile, "\\"); break;
			case ',': w_out(outfile, "("); break;
			case '.': w_out(outfile, "@"); break;
			case '!': w_out(outfile, "0"); break;
			default: break;
		}
	}
}

int main(int argc, char **argv) {
	if (argv[1] == NULL) {
		t_out("error: expected a command [r]un or [m]ake\n");
		return 1;
	}
	if (strcmp(argv[1], "m") == 0) {
		if (argv[2] == NULL) {
			t_out("error: expected input file\n");
			return 1;
		}
		if (argv[3] == NULL) {
			t_out("error: expected output file\n");
			return 1;
		}
		make_small_hand(argv[2], argv[3]);
	}
	if (strcmp(argv[1], "r") == 0) { 
		if (argv[2] == NULL) {
			t_out("error: expected input file\n");
			return 1;
		}
		read_code(argv[2]);
	}
}
