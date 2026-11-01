#include <stdio.h>

int main(void)
{
    int a[10][10], copy[10][10];
    int rows, cols, i, j;

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

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            copy[i][j] = a[i][j];

    printf("Copied matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%4d", copy[i][j]);
        printf("\n");
    }

    return 0;
}
