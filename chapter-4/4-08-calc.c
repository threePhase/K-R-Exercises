#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>     /* for atof() */
#include <string.h>     /* for strcmp() */
#include <math.h>       /* for sin(), exp(), and pow() */

#define MAXOP 100       /* max size of operand or operator */
#define MAXVAL 100      /* maximum depth of val stack */
#define NUMBER '0'      /* signal that a number was found */
#define SIN '1'         /* signal that sine function was found */
#define EXP '2'         /* signal that exponential function was found */
#define POW '3'         /* signal that power function was found */
#define VAR '4'         /* signal that variable was found */

int getop(char input[]);
int getch(void);
void ungetch(int c);
void push(double input);
double pop(void);
double print(void);
double duplicate(void);
double swap(void);
void clear(void);

int sp = 0;             /* next free stack position */
int current_var;        /* current variable */
double val[MAXVAL];     /* value stack */
double vars['z'-'a'];   /* variable collection (a-z) */
int buf = -1;                /* buffer for ungetch */

/* reverse Polish calculator
 *
 * all basic operators provided (+, *, -, /, %, sin, exp, pow) as well as some
 * speciality commands:
 *
 *  ` - clear stack
 *  # - duplicate top value of stack
 *  ? - print top value of stack
 *  ~ - swap top two values on stack
 *
 *  variables (a-z) are also supported with the = operator
 *
 *  the '!' character is a special variable which stores the most recently
 *  printed value
 *
 */
int main() {
  int type;
  double op1, op2, last_printed;
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
    case VAR:
      op2 = vars['z'-current_var];
      push(op2);
      break;
    case '=':
      op2 = pop();
      vars['z'-current_var] = op2;
      break;
    case '!':
      push(last_printed);
      break;
    case '\n':
      last_printed  = pop();
      printf("\t%.8g\n", last_printed);
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}


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

/* getop: get next operator or numeric operand */
int getop(char input[]) {
  int i, c, output;

  output = NUMBER;

  while ((input[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
  input[1] = '\0';

  if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-') {
    return c;           /* not a number or function */
  }
  i = 0;

  if (isalpha(c)) {
    while(isalpha(input[++i] = c = getch())) {
      ;
    }
    if (i > 1) {        /* check for possible function */
      input[i] = '\0';
      if (strcmp(input, "sin") == 0) {
        output = SIN;
      } else if (strcmp(input, "exp") == 0) {
        output = EXP;
      } else if (strcmp(input, "pow") == 0) {
        output = POW;
      }
    } else {
      current_var = input[i-1];
      output = VAR;     /* not a recognized function */
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

int getch(void) {       /* get a (possibly pushed back) character */
  int c;
  if (buf != -1) {
    c = buf;
    buf = -1;
    return c;
  } else {
    return getchar();
  }
}

void ungetch(int c) {   /* push character back on input */
    buf = c;
}
