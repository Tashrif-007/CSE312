#include<stdio.h>
#include<math.h>
int power(int n)
{
    int prod=2;
    for(int i=1; i<n; i++)
        prod*=2;
    return prod;
}
void generate(int n, int size)
{
    int num[size];
    for(int i=size-1; i>=0; i--)
    {
        num[i]=n%2;
        n/=2;
    }
    for(int i=0; i<size; i++)
        printf("%d", num[i]);
}
int length(char *s)
{
    int i=0;
    for(i=0; s[i]; i++);
    return i;
}
void isPalindrome(char *s)
{
    for(int i=0,j=length(s)-1; i<j; i++,j--)
    {
        if(s[i]!=s[j])
        {
            printf("Not palindrome");
            return;
        }
    }
    printf("Is palindrome");
}
int main()
{
    int k;
    char s[100];
    printf("Enter value of k: ");
    scanf("%d", &k);
    if(k==0)
        printf("NULL");
    else
    {
        for(int i=0; i<power(k); i++)
        {
            generate(i,k);
            printf("\n");
        }
    }
    /*printf("Enter string: ");
    scanf("%s", s);
    isPalindrome(s);*/
    return 0;
}
