/*Aim of the experiment: Write a program to implement the matrix 
chain multiplication problem using M-table & S-table to find 
optimal parenthesization of a matrix-chain product. Print the 
number of scalar multiplications required for the given input.*/

#include <stdio.h>

void printOptimalParenthesis(int i, int j, int S[][100])
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParenthesis(i, S[i][j], S);
        printf(" ");
        printOptimalParenthesis(S[i][j] + 1, j, S);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n)
{
    int m[100][100];
    int S[100][100];

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int chainLength = 2; chainLength < n; chainLength++)
    {
        for (int i = 1; i < n - chainLength + 1; i++)
        {
            int j = i + chainLength - 1;
            m[i][j] = 999999; 
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    printf("M Table:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i <= j)
            {
                printf("%d ", m[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i < j)
            {
                printf("%d ", S[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    printOptimalParenthesis(1, n - 1, S);
    printf("\n");
    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n - 1]);
}

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[100];
    printf("Enter the dimension sequence (row no): ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n + 1);

    return 0;
}