#include <stdio.h>

struct Element 
{
    int row, col, value;
};

int main() 
{
    int rows, cols, total;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter total number of non-zero elements: ");
    scanf("%d", &total);

    struct Element elements[total];

    for (int i = 0; i < total; i++) 
    {
        printf("Enter row, column, value for element %d: ", i + 1);
        scanf("%d%d%d", &elements[i].row, &elements[i].col, &elements[i].value);
    }

    int matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

   
    for (int i = 0; i < total; i++) {
        matrix[elements[i].row][elements[i].col] = elements[i].value;
    }

    printf("\nFull Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
