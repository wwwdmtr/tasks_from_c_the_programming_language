
/* couldnt resolve negative numbers */ 



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void print_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("error: to many chars");
	else
		buf[bufp++] = c;
}

int getop(char s[]){
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (c == '-' || c == '+') {
		int next_char = getch();

		if (isdigit(next_char)){
			s[i++] = c;
			c = next_char;
		} else {
			ungetch(next_char);
			return c;
		}
       	}
	if (isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("stack overflow %g cant get in", f);
}

double pop(void)
{
	if (sp > -1)
		return val[--sp];
	else {
		printf("Stack is empty\n");
		return -1.0;
	}
}

void print_top(void){
	if (sp>0)
		printf("Top of the stack: %g\n", val[sp-1]);
	else 
		printf("error: stack is empty\n");
}

void duplicate_top(void){
	if (sp>0){
		double top = val[sp-1];
		push(top);
	} else 
		printf("error: stack is empty\n");
}

void swap_top_two(void){
	if (sp > 1){
		double temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp - 2] = temp;
	} else {
		printf("error: not enough elements to swap\n");
	}
}

void clear_stack(void){
	sp = 0;
}


int main() {
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop (s)) != EOF){
		switch(type){
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
				if(op2 != 0.0)
					push(pop()/op2);
				else 
					printf("cant devide by zero");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0)
					push((int)pop() % (int)op2);
				else
					printf("cant devide by zero");
				break;
			case 'p':  
				print_top();
                		break;
          		  case 'd':  
				duplicate_top();
               			 break;
           		 case 's':  
               			 swap_top_two();
               			 break;
           		 case 'c':  
                		clear_stack();
                		break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("unknown operator %s\n", s);
				break;
		}
	}
	return 0;
}

