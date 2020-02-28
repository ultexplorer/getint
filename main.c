#include <stdio.h>
#include <ctype.h>

#define SIZE 100

void ungetch(int c);
int getch(void);
int getint(int *);

int main()
{
    int n;
    int array[SIZE];
    printf("Задай числовой ряд: \n");

    for(n=0; n<SIZE && getint(&array[n])!=EOF; n++);

    for(int i=0; i<n; i++){
        printf("%d\n", array[i]);
    }

    printf("End\n");

    return 0;
}

int bufp=0;
int buf[SIZE];

void ungetch(int c)
{
    if(bufp>SIZE)
        printf("Error, buf is full(too meny characters)\n");
    else
        buf[bufp++]=c;
}

int getch()
{
    return (bufp>0) ? buf[--bufp] : getchar();
}

int getint(int *pn)
{
    int c, sign;
    while (isspace(c=getch()));

    if(!isdigit(c) && c!=EOF && c!='+' && c!='-')
    {
        ungetch(c);
        return 0;
    }

    sign=(c=='-')?-1:1;

    if(c=='+'||c=='-')
    {
        c=getch();
    }

    for(*pn=0; isdigit(c); c=getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *=sign;

    if(c!=EOF){
        ungetch(c);
    }
    return c;
}