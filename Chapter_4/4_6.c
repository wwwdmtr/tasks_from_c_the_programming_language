#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h> 

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
double variables[26]; 
double last_printed = 0.0; 

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("error: too many characters\n");
    else
        buf[bufp++] = c;
}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (islower(c)) 
        return c;
    if (!isdigit(c) && c != '.' && c != '-' && c != '+')
        return c;
    i = 0;
    if (c == '-' || c == '+') {
        int next_char = getch();
        if (isdigit(next_char)) {
            s[i++] = c;
            c = next_char;
        } else {
            ungetch(next_char);
            return c;
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack overflow\n");
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

int main() {
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: division by zero\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: division by zero\n");
                break;
            case 's': 
                push(sin(pop()));
                break;
            case 'e': 
                push(exp(pop()));
                break;
            case 'p': 
                op2 = pop();
                op1 = pop();
                push(pow(op1, op2));
                break;
            case '=': { 
                op2 = pop();
                if (islower(s[0])) {
                    variables[s[0] - 'a'] = op2;
                    push(op2);
                } else {
                    printf("error: invalid variable name\n");
                }
                break;
            }
            case '\n':
                last_printed = pop();
                printf("\t%.8g\n", last_printed);
                break;
            default:
                if (islower(type)) { 
                    push(variables[type - 'a']);
                } else {
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
    }
    return 0;
}
