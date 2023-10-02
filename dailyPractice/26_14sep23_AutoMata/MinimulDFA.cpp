#include <stdio.h>

#define max 20

int main()
{
    freopen("input.txt", "r", stdin);
    int state, alphabet;
    printf("Enter number of states:\n");
    scanf("%d", &state);
    printf("Enter number of alpahbet: \n");
    scanf("%d", &alphabet);
    int mat[state][alphabet];

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < alphabet; j++)
        {
            printf("----");
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n\n\n");

    int final[state] = {0, 0, 0, 1, 0, 0, 0, 0};

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < alphabet; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }

    int min[state][state];

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < state; j++)
        {
            min[i][j] = 0;
        }
    }

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" %d ", min[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < state; j++)
        {
            if (final[i] || final[j])
            {
                min[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" %d ", min[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((min[mat[i][0]][mat[j][0]]) || (min[mat[i][1]][mat[j][1]]))
            {
                min[i][j] = 1;
            }
        }
        printf("\n");
    }

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" %d ", min[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
}