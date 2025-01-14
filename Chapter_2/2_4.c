#include <stdio.h>
#define MAXLINE 1000;

void squeeze(char s1[], char s2[]) {
    int i, j, k = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        int match = 0;  
	for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                match = 1;  
		break;      
	    }
        }
        if (!match) {        
    		s1[k++] = s1[i];  
	}
    }
    s1[k] = '\0'; 
}

int main(){
	char str[] = "hello";
	char delChars[] = "world";
	squeeze(str, delChars);
	printf("%s\n", str);
}
