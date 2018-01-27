#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int maxline);
void reverse(char reversed[], char original[], int len);

main(){
    int i, j;
    int len;
    char line[MAXLINE];
    char reversed[MAXLINE];

    for (i = 0; i < MAXLINE; ++i){
        line[i] = 0;
        reversed[i] = 0;
    }

    while ((len = get_line(line, MAXLINE)) > 0){
      reverse(reversed, line, len);
      printf("Reversed %s\n", reversed);
    }
    return 0;
}

int get_line(char s[], int lim){//возвращает индекс последнего элемента массива \0
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

void reverse(char r[], char s[], int l){
    int i, j, z;

    i = 0;

    for (z = 0; z < MAXLINE; ++z){
      r[z] = 0;
    }

    for (j = l-2; j >= 0; --j){
      r[i] = s[j];
      ++i;
    }
}