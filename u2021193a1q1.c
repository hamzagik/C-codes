#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc<3 || argc>4)
    {
        printf("Insufficient arguments!");
        exit(-1);
    }

    FILE *mat1;
    FILE *mat2;
    mat1 = fopen(argv[1], "r");
    mat2 = fopen(argv[2], "r");
    if (mat1 == NULL || mat2 == NULL)
    {
        printf("Error: failed to open input file: %s", argv[1]);
        exit(-2);
    }

    int r1, c1, r2, c2;
    fscanf(mat1, "%d %d", &r1, &c1);
    fscanf(mat2, "%d %d", &r2, &c2);

    printf("Matrix 1 dimensions: %d x %d\n", r1, c1);
    printf("Matrix 2 dimensions: %d x %d\n", r2, c2);

    if (c1 != r2)
    {
        printf("Error: Matrix multiplication is not possible\n");
        exit(-4);
    }

    int **matrix1 = (int **)malloc(r1 * sizeof(int *));
    if (matrix1 == NULL)
    {
        printf("Error: failed to allocate memory\n");
        exit(-3);
    }

    for (int i = 0; i < r1; i++)
    {
        matrix1[i] = (int *)malloc(c1 * sizeof(int));
        if (matrix1[i] == NULL)
        {
            printf("Error: failed to allocate memory\n");
            exit(-3);
        }
    }

    int **matrix2 = (int **)malloc(r2 * sizeof(int *));
    if (matrix2 == NULL)
    {
        printf("Error: failed to allocate memory\n");
        exit(-3);
    }

    for (int i = 0; i < r2; i++)
    {
        matrix2[i] = (int *)malloc(c2 * sizeof(int));
        if (matrix2[i] == NULL)
        {
            printf("Error: failed to allocate memory\n");
            exit(-3);
        }
    }

    int **result = (int **)malloc(r1 * sizeof(int *));
    if (result == NULL)
    {
        printf("Error: failed to allocate memory\n");
        exit(-3);
    }

    for (int i = 0; i < r1; i++)
    {
        result[i] = (int *)malloc(c2 * sizeof(int));
        if (result[i] == NULL)
        {
            printf("Error: failed to allocate memory\n");
            exit(-3);
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            fscanf(mat1, "%d", &matrix1[i][j]);
        }
    }

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            fscanf(mat2, "%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    FILE *outputFile = NULL;
    if (argc == 4)
    {
        outputFile = fopen(argv[3], "w");
        if (outputFile == NULL)
        {
            printf("Error: failed to open output file\n");
            exit(-1);
        }

        fprintf(outputFile, "%d %d\n", r1, c2);
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                fprintf(outputFile, "%d ", result[i][j]);
            }
            fprintf(outputFile, "\n");
        }

        fclose(outputFile);
    }

    else
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }

    for(int i=0;i<r1;i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < r2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < r1; i++)
    {
        free(result[i]);
    }
    free(result);

    fclose(mat1);
    fclose(mat2);
}
