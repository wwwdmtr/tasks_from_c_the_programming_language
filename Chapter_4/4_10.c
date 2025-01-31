#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int getop(char [], char []);
void push(double);
double pop(void);

int sp = 0;               
double val[MAXVAL];       


void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack overflow %g cannot be pushed\n", f);
    }
}


double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

int getop(char s[], char line[]) {
    static int i = 0; 

    
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }

    
    s[0] = line[i];
    s[1] = '\0';

    if (!isdigit(line[i]) && line[i] != '.' && line[i] != '-' && line[i] != '+') {
        return line[i++]; 
    }

    int j = 0;
    if (line[i] == '-' || line[i] == '+') { 
        char next_char = line[i + 1];
        if (isdigit(next_char) || next_char == '.') {
            s[j++] = line[i++];
        } else {
            return line[i++]; 
        }
    }

    
    while (isdigit(line[i])) {
        s[j++] = line[i++];
    }

    
    if (line[i] == '.') {
        s[j++] = line[i++];
        while (isdigit(line[i])) {
            s[j++] = line[i++];
        }
    }

    s[j] = '\0';
    return NUMBER;
}

int getline_custom(char line[], int maxline) {
    int c, i = 0;

    while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }

    if (c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}

int main() {
    char line[MAXLINE]; 
    char s[MAXOP];      
    int type;
    double op2;

    printf("Enter expressions to evaluate. Press Ctrl+D to exit.\n");

    while (getline_custom(line, MAXLINE) > 0) { 
        int i = 0; 
        while ((type = getop(s, line)) != '\0') { 
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
                        printf("error: division by zero\n");
                    }
                    break;
                case '%':
                    op2 = pop();
                    if (op2 != 0) {
                        push((int)pop() % (int)op2);
                    } else {
                        printf("error: division by zero\n");
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
    }

    return 0;
}
