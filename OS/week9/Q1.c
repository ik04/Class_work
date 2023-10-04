#include<stdio.h>
struct process
{
    int WT, AT, BT, TAT, PT;
};

struct process a[10];

int main()
{
    int n, temp[10], t, count = 0, short_p;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time, burst time, and priority of the processes:\n");
    printf("AT  BT  PT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a[i].AT, &a[i].BT, &a[i].PT);

        // Copying the burst time into
        // a temp array for further use
        temp[i] = a[i].BT;
    }

    // We initialize the burst time
    // of a process with a maximum priority
    a[9].PT = 10000;

    printf("\nGantt Chart:\n");
    printf("ID  WT  TAT\n");
    for (t = 0; count != n; t++)
    {
        short_p = 9;
        for (int i = 0; i < n; i++)
        {
            if (a[i].PT < a[short_p].PT && a[i].AT <= t && a[i].BT > 0)
            {
                short_p = i;
            }
        }

        a[short_p].BT = a[short_p].BT - 1;

        // If any process is completed
        if (a[short_p].BT == 0)
        {
            // One process is completed
            // so count increases by 1
            count++;
            a[short_p].WT = t + 1 - a[short_p].AT - temp[short_p];
            a[short_p].TAT = t + 1 - a[short_p].AT;

            // Total calculation
            total_WT = total_WT + a[short_p].WT;
            total_TAT = total_TAT + a[short_p].TAT;

            // Print Gantt Chart for the completed process
            printf("%d   %d   %d\n", short_p + 1, a[short_p].WT, a[short_p].TAT);
        }
    }

    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;

    // Printing the answer
    printf("\nID   WT   TAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d    %d     %d\n", i + 1, a[i].WT, a[i].TAT);
    }

    printf("Avg waiting time of the processes is %f\n", Avg_WT);
    printf("Avg turnaround time of the processes is %f\n", Avg_TAT);

    return 0;
}
