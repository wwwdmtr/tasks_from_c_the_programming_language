#include <stdio.h>
#define MAXLINE 1000

int any(const char s1[], const char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;              }
        }
    }
    return -1; 
}

int main() {
    char s1[] = "hello";
    char s2[] = "world";

    printf("Первое совпадение на позиции: %d\n", any(s1, s2));
    return 0;
}
