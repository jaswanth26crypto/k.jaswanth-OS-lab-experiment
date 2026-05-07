#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int burst[10], remaining[10], priority[10];
    int waiting[10], turnaround[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Burst time for P%d: ", i+1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];

        printf("Priority for P%d: ", i+1);
        scanf("%d", &priority[i]);
    }

    while(completed < n) {
        int highest = -1, index = -1;

        for(i = 0; i < n; i++) {
            if(remaining[i] > 0 && (index == -1 || priority[i] < highest)) {
                highest = priority[i];
                index = i;
            }
        }

        remaining[index]--;
        time++;

        if(remaining[index] == 0) {
            completed++;
            turnaround[index] = time;
            waiting[index] = turnaround[index] - burst[index];
        }
    }

    printf("\nProcess Burst Priority Waiting Turnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, burst[i], priority[i], waiting[i], turnaround[i]);
    }

    return 0;
}
