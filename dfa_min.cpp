#include <bits/stdc++.h>
using namespace std;

#define mx 100

int main()
{
    freopen("dfa_min.txt", "r", stdin);
    char states[mx], alpha[mx], str[mx], start, end, state, path[mx], paths = 0, p = 0;
    int numState, numAlpha, i, j, k = 0;

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
    cout << "Enter final state: ";
    cin >> end;
    int final_idx;
    for (i = 0; i < numState; i++)
    {
        if (end == states[i])
        {
            final_idx = i;
            break;
        }
    }

    char equiv[numState][numState];

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
        {
            equiv[i][j] = ' ';
        }
    }

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
        {
            if ((i == final_idx || j == final_idx) && i > j)
            {
                equiv[i][j] = 'X';
            }
        }
    }

    for (int f = 0;  f<numState; f++)
    {
        for (i = 0; i < numState; i++)
        {
            for (j = 0; j < numState; j++)
            {
                if (i > j)
                {
                    for (k = 0; k < numAlpha; k++)
                    {
                        int x, y;
                        for (int m = 0; m < numState; m++)
                        {
                            if (states[m] == transit[i][k])
                                x = m;
                            if (states[m] == transit[j][k])
                                y = m;
                        }
                        if (equiv[x][y] == 'X' || equiv[y][x] == 'X')
                        {
                            equiv[i][j] = 'X';
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
        {
            if (equiv[i][j] == ' ')
            {
                equiv[i][j] = '=';
            }
        }
    }

    cout << endl;
    for (i = 0; i < numState; i++)
    {
        for (j = 0; j < numState; j++)
            if (i >= j)
                cout << equiv[i][j] << "  ";
        cout << endl;
    }

    //setting up the new minimized states
    vector<set<char>>newState;
    for(i=0; i<numState; i++)
    {
        for(j=0; j<numState; j++)
        {
            if(equiv[i][j]=='=' && i>j)
            {
                set<char>temp;
                temp.insert(states[i]);
                temp.insert(states[j]);
                newState.push_back(temp);
            }
        }
    }
    // Printing transitions to the new states
cout << "\nTransitions to New States:\n";
for (i = 0; i < numState; i++) {
    for (j = 0; j < numAlpha; j++) {
        for (int k = 0; k < newState.size(); k++) {
            bool found = false;
            for (int m = 0; m < numState; m++) {
                if (newState[k].count(transit[i][j]) > 0) {
                    found = true;
                    cout << "State " << states[i] << " with alphabet " << alpha[j]
                         << " goes to New State " << *newState[k].begin() << endl;
                    break;
                }
            }
            if (found) break;
        }
    }
}
    return 0;
}
