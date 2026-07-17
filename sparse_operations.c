#include <stdio.h>

struct Sparse
{
    int row;
    int col;
    int value;
};

int main()
{
    int m, n;
    int a[10][10], b[10][10];
    struct Sparse s1[100], s2[100], sum[100], trans[100];
    int i, j, k;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);

    /* First Matrix */
    printf("\nEnter First Matrix:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    /* Second Matrix */
    printf("\nEnter Second Matrix:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    /* Convert First Matrix to Sparse */
    k = 1;
    int count1 = 0;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
            {
                s1[k].row = i;
                s1[k].col = j;
                s1[k].value = a[i][j];
                k++;
                count1++;
            }
        }
    }

    s1[0].row = m;
    s1[0].col = n;
    s1[0].value = count1;

    /* Convert Second Matrix to Sparse */
    k = 1;
    int count2 = 0;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(b[i][j] != 0)
            {
                s2[k].row = i;
                s2[k].col = j;
                s2[k].value = b[i][j];
                k++;
                count2++;
            }
        }
    }

    s2[0].row = m;
    s2[0].col = n;
    s2[0].value = count2;

    /* Display Sparse Matrix 1 */
    printf("\nSparse Matrix 1\n");
    printf("Row\tCol\tValue\n");

    for(i = 0; i <= count1; i++)
    {
        printf("%d\t%d\t%d\n", s1[i].row, s1[i].col, s1[i].value);
    }

    /* Display Sparse Matrix 2 */
    printf("\nSparse Matrix 2\n");
    printf("Row\tCol\tValue\n");

    for(i = 0; i <= count2; i++)
    {
        printf("%d\t%d\t%d\n", s2[i].row, s2[i].col, s2[i].value);
    }

    /* Addition */
    i = j = k = 1;

    while(i <= count1 && j <= count2)
    {
        if(s1[i].row == s2[j].row)
        {
            if(s1[i].col == s2[j].col)
            {
                sum[k].row = s1[i].row;
                sum[k].col = s1[i].col;
                sum[k].value = s1[i].value + s2[j].value;
                i++;
                j++;
                k++;
            }
            else if(s1[i].col < s2[j].col)
            {
                sum[k++] = s1[i++];
            }
            else
            {
                sum[k++] = s2[j++];
            }
        }
        else if(s1[i].row < s2[j].row)
        {
            sum[k++] = s1[i++];
        }
        else
        {
            sum[k++] = s2[j++];
        }
    }

    while(i <= count1)
        sum[k++] = s1[i++];

    while(j <= count2)
        sum[k++] = s2[j++];

    sum[0].row = m;
    sum[0].col = n;
    sum[0].value = k - 1;

    printf("\nAddition of Sparse Matrices\n");
    printf("Row\tCol\tValue\n");

    for(i = 0; i <= sum[0].value; i++)
    {
        printf("%d\t%d\t%d\n", sum[i].row, sum[i].col, sum[i].value);
    }

    /* Transpose of Sum Matrix */
    trans[0].row = sum[0].col;
    trans[0].col = sum[0].row;
    trans[0].value = sum[0].value;

    k = 1;

    for(i = 0; i < sum[0].col; i++)
    {
        for(j = 1; j <= sum[0].value; j++)
        {
            if(sum[j].col == i)
            {
                trans[k].row = sum[j].col;
                trans[k].col = sum[j].row;
                trans[k].value = sum[j].value;
                k++;
            }
        }
    }

    printf("\nTranspose of Resultant Sparse Matrix\n");
    printf("Row\tCol\tValue\n");

    for(i = 0; i <= trans[0].value; i++)
    {
        printf("%d\t%d\t%d\n", trans[i].row, trans[i].col, trans[i].value);
    }

    return 0;







}
