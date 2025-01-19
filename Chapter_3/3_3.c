#include <stdio.h>
#include <ctype.h>

void expand(const char s1[], char s2[]) {
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i - 1] != '\0' && s1[i + 1] != '\0') {
            char start = s1[i - 1];
            char end = s1[i + 1];
            
            if (isalnum(start) && isalnum(end) && start <= end) {
                for (char c = start + 1; c <= end; c++) {
                    s2[j++] = c;
                }
                i++;  
            } else {
                s2[j++] = s1[i];
            }
        } else {
            s2[j++] = s1[i];
        }
        i++;  
    }
    s2[j] = '\0'; 
}

int main() {
    char s1[] = "-a-f0-9-";
    char s2[100]; 
    expand(s1, s2);
    printf("Expanded: %s\n", s2); 
    return 0;
}
