#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i,j,key;
	printf("yes yes yes\n");
	int arr[] = {24,23,25,27,26};
	int n  = sizeof(arr)/sizeof(arr[0]);
	for (i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while (j>=0 && arr[j]>key) 
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1]=key;
	}
	for (i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
