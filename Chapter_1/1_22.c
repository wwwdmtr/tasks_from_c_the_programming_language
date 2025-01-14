#include <stdio.h>
#include <string.h>

#define MAXLINE 1000   
#define N 20          

void fold_line(char line[], int n);

int main() {
    char line[MAXLINE];
    printf("Enter text (Ctrl+D to stop):\n");
    while (fgets(line, sizeof(line), stdin)) {
        fold_line(line, N);
    }
    return 0;
}

void fold_line(char line[], int n) {
    int len = strlen(line);
    int pos = 0; 

    while (pos < len) {
        int end = pos + n; 
        if (end >= len) { 
            printf("%s", &line[pos]);
            break;
        }

        int break_pos = -1;
        for (int i = pos; i < end; ++i) {
            if (line[i] == ' ' || line[i] == '\t') {
                break_pos = i;
            }
        }

        if (break_pos == -1) {
            break_pos = end;
        }

        for (int i = pos; i < break_pos; ++i) {
            putchar(line[i]);
        }
        putchar('\n');

        pos = (line[break_pos] == ' ' || line[break_pos] == '\t') ? break_pos + 1 : break_pos;
    }
}
