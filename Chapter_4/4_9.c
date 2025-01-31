#include <stdio.h>

int unget_char = EOF;
int unget_flag = 0;

int getch(void) {
    if (unget_flag) {
        unget_flag = 0;
        return unget_char;
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (unget_flag) {
        printf("error: ungetch buffer is full\n");
    } else {
        unget_char = c;
        unget_flag = 1;
    }
}

int main() {
    int c;

    printf("Enter a character: ");
    c = getch(); 
    printf("You entered: %c\n", c);

    ungetch(c); 
    printf("Returned character: %c\n", getch()); 
    ungetch(EOF); 
    printf("Returned EOF: %d\n", getch()); 

    return 0;
}
