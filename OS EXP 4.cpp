#include <stdio.h>

int main() {
    int n, i, j;
    int burst[20], temp;
    int waiting[20], turnaround[20];
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }

    // Sorting burst times
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(burst[i] > burst[j]) {
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }

    waiting[0] = 0;

    for(i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    for(i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage WT = %.2f", total_wt/n);
    printf("\nAverage TAT = %.2f\n", total_tat/n);

    return 0;
}
