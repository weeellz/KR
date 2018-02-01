#include <stdio.h>
#define MAXLINE 100
#define TAB_STOP 8

int get_line(char line[], int maxline);
void detab(char detabbed[], char original[]);

main(){
    int i, j;
    int len;
    char line[MAXLINE];
    char detabbed[MAXLINE];

    for (i = 0; i < MAXLINE; ++i){
        line[i] = 0;
        detabbed[i] = 0;
    }

    while ((len = get_line(line, MAXLINE)) > 0){
      detab(detabbed, line);
      printf("Detabbed %s\n", detabbed);
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

void detab(char q[], char s[]){
    int i, j, k, kek;

    i = j = 0;

    while (s[i] != '\0'){
        if (s[i] == '\t'){
            q[j] = ' ';
            k = TAB_STOP - (j % TAB_STOP);
            while (k > 1){
                ++j;
                q[j] = ' ';
                --k;
            }            
        }
        else{
            q[j] = s[i];
        }
        ++j;
        ++i;
    }
    q[j] = '\0';
}