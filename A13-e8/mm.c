#include <stdio.h>

int main()
{
    int osm, tm, tif = 0, i, n, b, nb;
    printf("\nEnter total available Memory:");
    scanf("%d", &tm);
    printf("\nEnter amount of memory occupied by the OS: ");
    scanf("%d", &osm);
    tm -= osm;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter size of each block: ");
    scanf("%d", &b);
    nb = tm / b;

    int p[n], inf[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter required memory for process %d: ", i);
        scanf("%d", &p[i]);
        if (p[i] > b) {
            printf("Process %d cannot be allocated. Sorry.\n", i);
            return 1;
        }
        inf[i] = b - p[i];
        printf("process %d: \nmemory required:%d \nremaining memory:%d \ninternal fragmentation:%d\n", i, p[i], tm, inf[i]);
        tif += inf[i];
        tm -= p[i];
    }

    printf("\nTotal internal fragmentation is:%d\n", tif);
    return 0;
}
