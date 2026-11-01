#include <stdio.h>

int main(void)
{
    int a[4][2];
    int i, j;

    printf("Enter 8 elements for a 4 x 2 matrix:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }

    return 0;
}
