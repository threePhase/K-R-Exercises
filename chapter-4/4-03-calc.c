#include <stdio.h>
#include <stdlib.h>     /* for atof() */

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() {
  int type;
  double op1, op2, temp;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      op1 = pop();
      if (op2 != 0.0) {
        push(op1 - (int)(op1/op2) * op2);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100      /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push input onto stack */
void push(double input) {
  if (sp < MAXVAL) {
    val[sp++] = input;
  } else {
    printf("error: stack full, can't push %g\n", input);
  }
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>
int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char input[]) {
  int i, c;

  while ((input[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
  input[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-') {
    return c;           /* not a number */
  }
  i = 0;
  if (c == '-') {
    if (isdigit(input[++i] = c = getch())) {
      ;                 /* negative number */
    } else {
      ungetch(c);       /* not a negative, so backup and return negative */
      return '-';
    }
  }
  if (isdigit(c)) {     /* collect integer part */
    while (isdigit(input[++i] = c = getch())) {
      ;
    }
  }

  if (c == '.') {       /* collect fraction part */
    while (isdigit(input[++i] = c = getch())) {
      ;
    }
  }

  input[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }

  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int  bufp = 0;          /* next free position in buf */

int getch(void) {       /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {   /* push character back on input */
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}
