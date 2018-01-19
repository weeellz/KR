#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 5

main(){
	int c, i, j, state, nw;
	int ncount[MAXLEN];

	state = OUT;
	nw = 0;

	for (i = 0; i < MAXLEN; ++i)
		ncount[i] = 0;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}
		else if (state == OUT){
			state = IN;
			++nw;
		}
		if (state == IN){
			++ncount[nw - 1];
		}
	}
	printf("%d\n", nw);
	for (i = 0; i < MAXLEN; ++i){
		for (j = 0; j < ncount[i]; ++j){
			printf("-");
		}
		putchar('\n');
	}
}