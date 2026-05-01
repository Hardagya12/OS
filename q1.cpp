#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remain;
    int bt[10], rt[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    // Input burst time
    for(i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tCompletion Time\n");

    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    rt[i] = 0;
                    remain--;
                    printf("P%d\t%d\n", i+1, time);
                }
                else {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    return 0;
}