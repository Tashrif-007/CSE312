#include<bits/stdc++.h>
using namespace std;

bool found=false;
string path;

void cfg(vector<string>&base, string target, string curr, string currPath)
{
    if(found)
    return;

    if(curr.size()>target.size()+1)
    return;

    if(curr.find('P')==string::npos && curr!=" ")
    {
        if(curr==target)
        {
            found=true;
            path = currPath;
        }
        return;
    }

    for(string x : base)
    {
        if(curr.find('P')!=string::npos)
        {
            string temp = curr.substr(0, curr.find('P'));
            temp+=x;
            temp+=curr.substr(curr.find('P')+1);
            x = temp;
        }
        cfg(base, target, x, currPath+"->"+x);
        if(found)
        return;
    }
}

int main()
{
    vector<string>base={"", "0", "1", "0P0", "1P1"};
    string s;
    cin>>s;
    cfg(base, s, " ", path);

    if(found)
    cout<<"P"<<path<<endl;
    else
    cout<<"Rejected"<<endl;
    return 0;
}
