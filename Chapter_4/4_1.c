#include <stdio.h>

int strindex(char s[], char t[]) {
    int i, j, k;
    int pos = -1; 
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (t[k] == '\0') {
            pos = i; 
        }
    }

    return pos; 
}

int main() {
    char s[] = "hello world, hello!";
    char t[] = "hello";

    int result = strindex(s, t);

    if (result != -1) {
        printf("The most right index '%s' in '%s' is: %d\n", t, s, result);
    } else {
        printf("String '%s' has 0 matches '%s'\n", t, s);
    }

    return 0;
}
