#include <stdio.h>

int main() {
    int n, i;
    int burst[20], waiting[20], turnaround[20];
    int total_wait = 0, total_turn = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Times:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &burst[i]);
    }

    waiting[0] = 0;

    for(i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    for(i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        total_wait += waiting[i];
        total_turn += turnaround[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wait/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_turn/n);

    return 0;
}
