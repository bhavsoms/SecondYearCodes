#include <stdio.h>

int main()
{
    int ar[100],n,i,j,tmp;
    printf("Enter the number of elements in array:\t");
    scanf("%d",&n);
    printf("Enter the array elements:\t");
    for (i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for (i=1;i<n;i++)
    {
        for (j=i;j>0 && ar[j-1]>ar[j];j--)
        {
            tmp=ar[j];
            ar[j]=ar[j-1];
            ar[j-1]=tmp;
        }
    }
    printf("Result is:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",ar[i]);
    }
    printf("\n");
    return 0;
}
