#include <stdio.h>

int main(){
	int c, newLine, tabChar, spaceChar;
	newLine = 0;
	tabChar = 0;
	spaceChar = 0;
	while ((c = getchar()) != EOF){
		if (c == ' '){
			++spaceChar;
		} else if (c == '\t') {
			++tabChar;
		} else if (c == '\n'){
			++newLine;
		}}

	printf("** Text has ** \n");
	printf("Space chars: %d", spaceChar);	
	printf("\nTab chars: %d", tabChar);	
	printf("\nNew line chars: %d", newLine);	

}
