#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    int sum = 0;

    printf("Enter matrix elements:\n");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < m && i < n; i++)
    {
        sum = sum + a[i][i];
    }

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}
