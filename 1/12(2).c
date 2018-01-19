#include <stdio.h>

main(){
	int c, state;

	while((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t')
			putchar('\n');
		}
	}
}