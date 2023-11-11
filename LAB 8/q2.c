/*Aim of the experiment: Given two strings
· Find out all possible Longest Common Subsequences. · 
Calculate length of the LCS.*/

#include <stdio.h>
#include <string.h>

void printAllLCS(char *X, char *Y, int m, int n, char *lcs, int lcsLen, int L[][100])
{
    if (m == 0 || n == 0)
    {
        printf("%s\n", lcs);
        return;
    }

    if (X[m - 1] == Y[n - 1])
    {
        lcs[lcsLen - 1] = X[m - 1];
        printAllLCS(X, Y, m - 1, n - 1, lcs, lcsLen - 1, L);
    }
    else
    {
        if (L[m - 1][n] >= L[m][n - 1])
        {
            printAllLCS(X, Y, m - 1, n, lcs, lcsLen, L);
        }
        if (L[m][n - 1] >= L[m - 1][n])
        {
            printAllLCS(X, Y, m, n - 1, lcs, lcsLen, L);
        }
    }
}

int main()
{
    char X[100];
    char Y[100];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int L[m + 1][100];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            L[i][j] = 0;
        }
    }

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int lcs_length = L[m][n];
    char lcs[lcs_length + 1];
    lcs[lcs_length] = '\0';
    printf("\nLCS:\n");
    printAllLCS(X, Y, m, n, lcs, lcs_length, L);
    printf("\nLCS Length: %d\n", lcs_length);

    return 0;
}