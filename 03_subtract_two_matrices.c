#include <stdio.h>

int main(void)
{
    int a[10][10], b[10][10], difference[10][10];
    int rows, cols, i, j;

    printf("Enter number of rows and columns (maximum 10 each): ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10)
    {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            difference[i][j] = a[i][j] - b[i][j];

    printf("Difference (first matrix - second matrix):\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%4d", difference[i][j]);
        printf("\n");
    }

    return 0;
}
