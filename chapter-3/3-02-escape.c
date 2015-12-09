#include <stdio.h>

#define MAXLINE 1000

enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
               NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

void escape(char input[], char output[]);
void unescape(char input[], char output[]);
int getline2(char line[], int maxline);

int main() {
  int len;
  char input[MAXLINE], output[MAXLINE], output2[MAXLINE];
  while  ((len = getline2(input, MAXLINE)) > 0) {
    escape(input, output);
    printf("%s\n", output);
    unescape(output, output2);
    printf("%s\n", output2);
  }
  return 0;
}


/* escape: copy input to output replacing non-visible characters as their
 * escape sequences */
void escape(char input[], char output[]) {
  int c, i, j;

  for (i = j = 0; (c = input[i]) != '\0'; i++) {
    switch (c) {
      case BELL:
        output[j] = '\\';
        j++;
        output[j] = 'a';
        break;
      case BACKSPACE:
        output[j] = '\\';
        j++;
        output[j] = 'b';
        break;
      case NEWLINE:
        output[j] = '\\';
        j++;
        output[j] = 'n';
        break;
      case RETURN:
        output[j] = '\\';
        j++;
        output[j] = 'r';
        break;
      case TAB:
        output[j] = '\\';
        j++;
        output[j] = 't';
        break;
      case VTAB:
        output[j] = '\\';
        j++;
        output[j] = 'v';
        break;
      default:
        output[j] = c;
        break;
    }
    j++;
  }
  output[j] = '\0';
}

/* unescape: copy input to output replacing escape sequences with their
 * non-visible characters */
void unescape(char input[], char output[]) {
  int c, escaped, i, j;

  escaped = 0;
  for (i = j = 0; (c = input[i]) != '\0'; i++) {
    if (escaped) {
      switch (c) {
        case 'a':
          output[j] = BELL;
          break;
        case 'b':
          output[j] = BACKSPACE;
          break;
        case 'n':
          output[j] = NEWLINE;
          break;
        case 'r':
          output[j] = RETURN;
          break;
        case 't':
          output[j] = TAB;
          break;
        case 'v':
          output[j] = VTAB;
          break;
        default:
          output[j] = '\\';
          j++;
          output[j] = c;
          break;
      }
      j++;
      escaped = 0;
    } else {
      switch (c) {
        case '\\':
          escaped = ~escaped;
          break;
        default:
          output[j] = c;
          j++;
          break;
      }
    }
  }
  output[j] = '\0';
}

/* getline2: read a line into line, return length */
int getline2(char line[], int maxline) {
  int c, i;

  for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

