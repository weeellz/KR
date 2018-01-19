#include <stdio.h>

#define MAXLEN 25

main(){
	int c, i, j, z, count;
	int nchar[MAXLEN];
	int ncount[MAXLEN];

	count = 0;

	for (i = 0; i < MAXLEN; i++){
		nchar[i] = 0;
		ncount[i] = 0;
	}

	while ((c = getchar()) != EOF){
		for (i = 1; i < MAXLEN; ++i){
			nchar[i] = c;
			c = getchar();
		}
	}

	for (i = 1; i < MAXLEN; ++i){
		++ncount[i];
		for (j = i + 1; j < MAXLEN; ++j){
			if (nchar[i] == nchar[j]){
				++ncount[i];
			}
		}
		for (z = i - 1; z > 0; --z){
			if (nchar[i] == nchar[z]){
				ncount[i] = 0;
			}
		}
	}

	for (i = 0; i < MAXLEN; ++i){
		if (nchar[i] == 0)
			printf("cap ");
		else
			printf("%c", nchar[i]);
	}
	putchar('\n');
	for (i = 0; i < MAXLEN; ++i){
		printf("%d ", ncount[i]);
	}	
	putchar('\n');
	for (i = 0; i < MAXLEN; ++i){
		if (ncount[i] > 0){
			printf("%c: %d\n", nchar[i], ncount[i]);
			/*for (j = 0; j < ncount[i]; ++j){
				printf("-");
			}*/
		}
		else
			putchar('\b');
	}
}