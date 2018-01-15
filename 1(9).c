#include <stdio.h>

main(){
	int c;
	int count = 0;

	while((c = getchar()) != EOF){
		if(c == ' '){
			if (count == 0){
				++count;
				putchar(c);
			}
		}
		if(c != ' '){
			putchar(c);
			count = 0;
		}
	}
}