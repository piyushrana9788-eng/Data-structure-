#include <stdio.h>

int main(void)
{
    int a[10][10], b[10][10], product[10][10];
    int r1, c1, r2, c2, i, j, k;

    printf("Enter rows and columns of first matrix (maximum 10): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix (maximum 10): ");
    scanf("%d %d", &r2, &c2);

    if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10 ||
        r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10)
    {
        printf("Invalid matrix size.\n");
        return 1;
    }

    if (c1 != r2)
    {
        printf("Multiplication is not possible: columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            product[i][j] = 0;
            for (k = 0; k < c1; k++)
                product[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Product of the matrices:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%4d", product[i][j]);
        printf("\n");
    }

    return 0;
}
