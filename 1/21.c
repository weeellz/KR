#include <stdio.h>
#define MAXLINE 100
#define TAB_STOP 8

int get_line(char line[], int maxline);
void entab(char detabbed[], char original[]);

main(){
    int i, j;
    int len;
    char line[MAXLINE];
    char entabbed[MAXLINE];

    for (i = 0; i < MAXLINE; ++i){
        line[i] = 0;
        entabbed[i] = 0;
    }

    while ((len = get_line(line, MAXLINE)) > 0){
      entab(entabbed, line);
      printf("%s\n", entabbed);
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

void entab(char q[], char s[]){
    int i, j, k, kek, kok, z;

    i = j = 0;
    k = z = 0;
    kek = kok = 0;

    while (s[i] != '\0'){
        if (s[i] == ' '){
            ++k;
        }
        else if ((kok = k % TAB_STOP) == 0){
            kek = k / TAB_STOP;
            for (z = 0; z < kek; ++z){
                q[j] = '\t';
                ++j;
            }
        }
        else{
            kek = k / TAB_STOP;
            kok = k % TAB_STOP;
            for (z = 0; z < kek; ++z){
                q[j] = '\t';
                ++j;
            }
            for (z = 0; z < kok; ++z){
                q[j] = ' ';
                ++j;
            }
        }
        ++i;
    }
    q[j] = '\0';
}