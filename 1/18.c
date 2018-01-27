#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main(){
    int len;
    int i, j;
    char line[MAXLINE];
    char longest[MAXLINE];

    for (i = 0; i < MAXLINE; ++i){
        line[i] = 0;
        longest[i] = 0;
    }

    while ((len = get_line(line, MAXLINE)) > 0){
        if (line[len-2] == ' ' || line[len-2] == '\t'){
            j = len-2;
            while (line[j] == ' ' || line[j] == '\t'){
                --j;
            }
            if (line[j] != ' ' || line[j] != '\t'){
                line[j+1] = '\n';
                line[j+2] = '\0';
            }
        }
        copy(longest, line);
    }
    printf("\nLines \n%s\n", longest);
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

void copy(char to[], char from[]){
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}

/*#include <stdio.h>

#define IN      1
#define OUT     0
#define MAXLINE 1000

int get_line(char line[], int maxline);
void trim(char to[], char from[]);

int main() {
  char line[MAXLINE];
  char trimmed[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    trim(trimmed, line);
    printf("%s", trimmed);
  }

  return 0;
}

int get_line(char s[],int lim) {
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void trim(char to[], char from[]) {
  int i;
  char c;
  int l;
  int state;

  i = 0;
  l = MAXLINE;
  state = OUT;

  while ((c = from[i]) != '\0') {
    to[i] = c;
    if (c == '\n' || c == '\t' || c == ' ') {
      if (state == IN) {
        state = OUT;
        l = i;
      }
    } else {
      state = IN;
    }
    ++i;
  }
  to[l]     = '\n';
  to[l + 1] = '\0';
}*/