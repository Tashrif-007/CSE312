#include<iostream>
using namespace std;

int main()
{
    FILE *fp = fopen("code.c", "r");

    string str="", temp="";
    char ch;
    int line=1,t;
    bool found=false;

    while((ch=fgetc(fp))!=EOF)
    str+=ch;

    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='/' && str[i+1]=='/' && !found)
        {
            cout<<line<<":";
            for(int j=i+2; str[j]!='\n'; j++)
            cout<<str[j];
            cout<<endl;
        }
        else if(!found && str[i]=='/' && str[i+1]=='*')
        {
            t=line;
            found=true;
        }
        else if(found && str[i]!='*')
        {
            temp+=str[i];
        }
        else if(found && str[i]=='*' && str[i+1]=='/')
        {
            cout<<t<<":"<<temp<<endl;
            temp.clear();
            found=false;
        }

        if(str[i]=='\n')
        line++;
    }
    if(found)
    cout<<t<<": "<<"Wrong commenting"<<endl;
    return 0;
}
