#include <stdio.h>
#define TABSIZE 8 
void detab(char s[], char output[], int tabsize);

int main() {
    char line[1000];      
    char result[2000];    
    int c, i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line[i] = '\0';
            detab(line, result, TABSIZE);
            printf("%s\n", result);
            i = 0;
        } else {
            line[i++] = c;
        }
    }
    return 0;
}

void detab(char s[], char output[], int tabsize) {
    int i, j, pos;
    i = j = 0;
    pos = 0; 

    while (s[i] != '\0') {
        if (s[i] == '\t') {
            int spaces = tabsize - (pos % tabsize);
            for (int k = 0; k < spaces; k++) {
                output[j++] = ' ';
                pos++;
            }
        } else {
            output[j++] = s[i];
            pos++;
        }
        i++;
    }
    output[j] = '\0';
}
