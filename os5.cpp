#include <stdio.h>

int main() {
    int n, i, j;
    int burst[20], priority[20], temp;
    int waiting[20], turnaround[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) scanf("%d", &burst[i]);

    printf("Enter priorities:\n");
    for(i = 0; i < n; i++) scanf("%d", &priority[i]);

    // Sort by priority (lower number = higher priority)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(priority[i] > priority[j]) {
                temp = priority[i]; priority[i] = priority[j]; priority[j] = temp;
                temp = burst[i]; burst[i] = burst[j]; burst[j] = temp;
            }
        }
    }

    waiting[0] = 0;

    for(i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    for(i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }

    printf("\nProcess Burst Priority Waiting Turnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, burst[i], priority[i], waiting[i], turnaround[i]);
    }

    return 0;
}
