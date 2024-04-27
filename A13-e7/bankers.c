#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j,n,r,max[i][j],pr[i][j],need[i][j],avail[i][j];
	printf("Enter no of processes:");
	scanf("%d",&n);
	printf("Enter no of resources:");
	scanf("%d",&r);
	printf("Enter Resources:\n");
	for (i=0;i<=n;i++) {
		for (j=0;j<=r-1;j++) {
			scanf("%d",&pr[i][j]);
		}
	}
	printf("Enter Max :\n");
	for (i=0;i<=n;i++) {
		for (j=0;j<=r-1;j++) {
			scanf("%d",&max[i][j]);
		}
	}
	printf("Calculating need...\n");
	for (i=0;i<=n;i++) {
		for (j=0;j<=r-1;j++) {
			need[i][j] = max[i][j]-pr[i][j];
		}
	}
	sleep(4);
	printf("Need is:\n");
	for (i=0;i<=n;i++) {
		for (j=0;j<=r-1;j++) {
			printf("\n%3d\n",need[i][j]);
		}
	}
	printf("Avail is:\n");
	for (i=0;i<=0;i++) {
		for (j=0;j<=r-1;j++) {
			scanf("%d",&avail[i][j]);
		}
	}
	printf("Checking if it's possible to allocate :\n");
	for (i=0;i<=n;i++) {
		for (j=0;j<=r-1;j++) {
			if (need[i][j]<avail[i][j]) {
				printf("\nYes\n");
			}
			else {
				printf("\nNo\n");
			}
		}
	}
	return 0;
}
