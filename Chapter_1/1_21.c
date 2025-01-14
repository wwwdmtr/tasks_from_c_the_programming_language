#include <stdio.h>
#define TABSIZE 8

void entab(char line[]);

int main() {
    char line[1000];
    printf("Enter text: ");
    fgets(line, sizeof(line), stdin); 
    entab(line);
    printf("Converted text:\n%s", line);
    return 0;
}

void entab(char line[]) {
    int i, j, space_count, pos;
    char result[1000];
    pos = 0; 
    for (i = 0; line[i] != '\0'; ++i) {
        if (line[i] == ' ') {
            space_count = 0;
            while (line[i] == ' ') {
                ++space_count;
                ++i;
            }
            --i; 
            int tabs = (pos + space_count) / TABSIZE - pos / TABSIZE;
            int spaces = space_count - tabs * TABSIZE;

            while (tabs-- > 0) {
                result[pos++] = '\t';
            }

            while (spaces-- > 0) {
                result[pos++] = ' ';
            }
        } else {
            result[pos++] = line[i];
        }
    }
    result[pos] = '\0';
    for (j = 0; result[j] != '\0'; ++j) {
        line[j] = result[j];
    }
    line[j] = '\0';
}
