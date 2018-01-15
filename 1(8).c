#include <stdio.h>

main(){
	int c, nl, space, tab;

    nl = 0;
    space = 0;
    tab = 0;
	while((c = getchar()) != EOF){
		if(c == '\n')
			++nl;
		if(c == ' ')
			++space;
		if(c == '\t')
			++tab;
	}
	printf("new line: %d\n", nl);
	printf("space: %d\n", space);
	printf("tab: %d\n", tab);
}