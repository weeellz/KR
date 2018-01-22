#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int get_line(char line[], int maxline);
void copy(char to[], char from[], int p);

main(){
    int len, max;
    int i;
    char line[MAXLINE];
    char longest[MAXLINE];

    for (i = 0; i < MAXLINE; ++i){
        line[i] = 0;
        longest[i] = 0;
    }

    max = 0;

    while ((len = get_line(line, MAXLINE)) > 0){
        if (len > MINLINE){
            copy(longest, line, max);
            max = max + len;
        }
    }
    printf("\nLines longer than %d symbols\n%s\n", MINLINE, longest);
    return 0;
}

int get_line(char s[], int lim){
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[], int tmp){
    int i;

    i = 0;

    while ((to[i+tmp] = from[i]) != '\0'){
        ++i;
    }
}