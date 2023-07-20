#include<stdio.h>
#include<time.h>

void generateString(char *s, int len)
{
    for(int i=0; i<len; i++)
    {
        s[i]=rand()%2 + '0';
    }
    s[len]='\0';
}
int length(char *s)
{
    int i=0;
    for(i=0; s[i]; i++);
    return i;
}
void isBinary(char *s)
{
    for(int i=0; s[i]; i++)
    {
        if(s[i]!='1' && s[i]!='0')
        {
            printf("Not accepted\n");
            return;
        }
    }
    printf("Accepted");
}
void concat(char *x, char *y)
{
    int size = length(x)+length(y),k=0,i;
    char newString[size];
    for(i=0; k<length(x); i++)
    {
        newString[i]=x[k];
        k++;
    }
    for(k=0 ;k<length(y);i++)
    {
        newString[i]=y[k];
        k++;
    }
    newString[i]='\0';
    printf("%s\n", newString);
}
int main()
{
    int len;
    char x[100];
    char y[100];
    srand("NULL");

    printf("Enter string1 : ");
    scanf("%s", x);
    printf("Enter string2: ");
    scanf("%s", y);

    /*for(int i=0; i<5; i++)
    {
        len= rand()%10 +1;
        char string[len];
        generateString(string, len);
        printf("%s\n", string);
        printf("Length: %d\n", length(string));
    }*/

    isBinary(string);
    //concat(x,y);
    return 0;
}
