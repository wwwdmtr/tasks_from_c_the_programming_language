#include <stdio.h>

int unget_char = EOF;

int getch(void) {
    if (unget_char != EOF) {
        int temp = unget_char;
        unget_char = EOF;
        return temp;
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (unget_char != EOF) {
        printf("error: ungetch buffer is full\n");
    } else {
        unget_char = c;
    }
}

int main() {
    int c;

    printf("Enter a character: ");
    c = getch();
    printf("You entered: %c\n", c);

    ungetch(c);
    printf("Returned character: %c\n", getch());

    return 0;
}
