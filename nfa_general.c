#include <stdio.h>
#define mx 100

int transit[mx][mx][mx];
int maxS, isAccepted = 0;

void exploreStates(char current_state, char end_state, char alpha[], char str[], int numAlpha, int transitionIdx, int strIdx) {
    if (transitionIdx >= maxS || isAccepted) {
        return;
    }

    char next_state = transit[current_state - 'a'][alpha[strIdx]][transitionIdx]; 

    if (str[strIdx] == '\0') {
        if (next_state == end_state) {
            isAccepted = 1; 
            return;
        }
    } else if (next_state != 'q') {
        exploreStates(next_state, end_state, alpha, str, numAlpha, 0, strIdx + 1);
        exploreStates(current_state, end_state, alpha, str, numAlpha, transitionIdx + 1, strIdx);
    }
}

int main() {
    char states[mx], start, end, str[mx];
    int numState, numAlpha,alpha[mx];

    printf("Enter number of states: ");
    scanf("%d", &numState);

    printf("Enter states: ");
    for (int i = 0; i < numState; i++)
        scanf(" %c", &states[i]);

    printf("Enter number of alphabets: ");
    scanf("%d", &numAlpha);

    printf("Enter alphabets: ");
    for (int i = 0; i < numAlpha; i++)
        scanf(" %c", &alpha[i]);
    printf("Enter maximum number of transitions from a state: ");
    scanf("%d", &maxS);

    for (int i = 0; i < numState; i++) {
        printf("Enter transitions for state %c:\n", states[i]);
        for (int j = 0; j < numAlpha; j++) {
            printf("Enter transitions for alphabet %c:\n", alpha[j]);
            for (int k = 0; k < maxS; k++) {
                scanf(" %c", &transit[states[i] - 'a'][alpha[j]][k]);
            }
        }
    }

    printf("Enter start state: ");
    scanf(" %c", &start);

    printf("Enter end state: ");
    scanf(" %c", &end);

    printf("Enter string: ");
    scanf("%s", str);

    exploreStates(start, end, alpha, str, numAlpha, 0, 0);

    if (isAccepted) {
        printf("Accepted\n");
    } else {
        printf("Not accepted\n");
    }

    return 0;
}
