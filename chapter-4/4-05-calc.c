#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <string.h>     /* for strcmp() */
#include <math.h>       /* for sin(), exp(), and pow() */

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define SIN '1'         /* signal that sine function was found */
#define EXP '2'         /* signal that exponential function was found */
#define POW '3'         /* signal that power function was found */

int getop(char []);
void push(double);
double pop(void);
double print(void);
double duplicate(void);
double swap(void);
void clear(void);

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
    case SIN:
      push(sin(pop()));
      break;
    case EXP:
      push(exp(pop()));
      break;
    case POW:
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case '`':
      clear();
      break;
    case '#':
      duplicate();
      break;
    case '?':
      print();
      break;
    case '~':
      swap();
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

/* print: print the top element of stack without removing it */
double print(void) {
  double value;
  /* get top value */
  value = pop();
  push(value);
  printf("top stack value: %f\n", value);
  return value;
}
/* duplicate: duplicate the top element of stack */
double duplicate(void) {
  double value;
  value = pop();
  push(value);
  push(value);
  return value;
}
/* swap: swap the top two elements of stack */
double swap(void) {
  double value1, value2;
  value1 = pop();
  value2 = pop();
  push(value1);
  push(value2);
  return value2;
}

/* clear: remove all elements from stack stack */
void clear(void) {
  /* setting the stack pointer back to zero should effectively "clear" the
   * stack. */
  sp = 0;
}


#include <ctype.h>
int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char input[]) {
  int i, c, output;

  output = NUMBER;

  while ((input[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
  input[1] = '\0';

  if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-') {
    return c;          /* not a number or function */
  }
  i = 0;

  if (isalpha(c)) {
    while(isalpha(input[++i] = c = getch())) {
      ;
    }
    if (i > 1) {       /* check for possible function */
      input[i] = '\0';
      if (strcmp(input, "sin") == 0) {
        output = SIN;
      } else if (strcmp(input, "exp") == 0) {
        output = EXP;
      } else if (strcmp(input, "pow") == 0) {
        output = POW;
      }
    } else {
      output = c;           /* not a recognized function */
    }
  }
  if (c == '-') {
    if (isdigit(input[++i] = c = getch())) {
      ;                 /* negative number */
    } else {
      output = '-';
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

  return output;
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
