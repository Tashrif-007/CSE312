#include <iostream>
using namespace std;

#define mx 100

int main()
{
    freopen("dfa_min.txt", "r", stdin);
    char states[mx], alpha[mx], str[mx], start, end, state, path[mx], paths=0,p=0;
    int numState, numAlpha, i, j,k=0;

    printf("Enter number of states: ");
    scanf("%d", &numState);

    printf("Enter states: ");
    for (i = 0; i < numState; i++)
        scanf(" %c", &states[i]);

    printf("Enter number of Alphabet: ");
    scanf("%d", &numAlpha);
    printf("Enter alphabets: ");

    for (i = 0; i < numAlpha; i++)
        scanf(" %c", &alpha[i]);

    char transit[numState][numAlpha];
    printf("Provide transition functions: \n");
    for (i = 0; i < numState; i++)
    {
        printf("Enter transition for state %c: \n", states[i]);
        for (j = 0; j < numAlpha; j++)
        {
            printf("Enter for alphabet %c: ", alpha[j]);
            scanf(" %c", &transit[i][j]);
        }
    }
    cout<<"Enter final state: ";
    cin>>end;
    int final_idx;
    for(i=0; i<numState; i++)
    {
        if(end==states[i])
        {
            final_idx=i;
            break;
        }
    }

    char equiv[numState][numState];

    for(i=0; i<numState; i++)
    {
        for(j=0; j<numState; j++)
        {
            equiv[i][j]=' ';
        }
    }

    for(i=0; i<numState; i++)
    {
        for(j=0; j<numState; j++)
        {
            if((i==final_idx || j==final_idx) && i>j)
            {
                equiv[i][j]='X';
            }
        }
    }

    for(i=0; i<numState; i++)
    {
        for(j=0; j<numState; j++)
        {
            if(i>j)
            {
                for(k=0; k<numAlpha; k++){
                    int x,y;
                    for(int m=0; m<numState; m++)
                    {
                        if(states[m]==transit[i][k])
                        x=m;
                        if(states[m]==transit[j][k])
                        y=m;
                    }
                    if(equiv[x][y]=='X' || equiv[y][x]=='X'){
                    equiv[i][j]='X';
                   }
                }
            }
        }
    }

    for(i=0; i<numState; i++)
    {
        for(j=0; j<numState; j++)
        {
            if(equiv[i][j]==' ')
            {
                equiv[i][j]='=';
            }
        }
    }

    cout<<endl;
    for(i=0; i<numState; i++)
    {
        for(j=0; j<numState; j++)
        if(i>=j)
        cout<<equiv[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}
