#include <stdio.h>

int main(void)
{
    int a[10][10], result[10][10];
    int rows, cols, scalar, i, j;

    printf("Enter number of rows and columns (maximum 10 each): ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10)
    {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    printf("Enter scalar value: ");
    scanf("%d", &scalar);

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[i][j] = a[i][j] * scalar;

    printf("Matrix after scalar multiplication:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%4d", result[i][j]);
        printf("\n");
    }

    return 0;
}
