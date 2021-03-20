#include <stdio.h>
void hviezdy(int n) {
	int i;
	for (i = 1; i <= n; i++) {
		printf("*");
	}
	printf("\n");
}
void medzery(int n) {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" ");
	}
}

void trojuh(int n)
{
	int i;
	for (i = 1; i <= n; i += 2) {
		medzery((n-i)/2);
		hviezdy(i);
	}
}

/*
  *     *     *	    2  5  5
 ***   ***   ***	1  3  3
***** ***** *****	0  1  1 
*/



void n_trojuh(int n) {
	int i;
	for (i = 1; i <= n; i ++) {
		/*for (i = 1; i <= n; i++) {
			medzery((n - i) / 2);
			hviezdy(i);
			*/
		}
}

int main()
{
	n_trojuh(3);
	return 0;
}