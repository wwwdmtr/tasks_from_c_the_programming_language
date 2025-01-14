/* Possible poblems are - empty text;  double space, tab or new line; space
 *  after last word; words like up-to-date, ice cream and so on */

#include <stdio.h>

#define IN 1 /* in word */
#define OUT 0 /* out of word */

int main() {
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF )
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == 'n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
