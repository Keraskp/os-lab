#include <stdio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], prior[20];
    int n = 0;
    float awt = 0, atat = 0;
    printf("Enter no. of processes : ");
    scanf("%d", &n);

    printf("Enter burst time and Priority :\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d] : ", i + 1);
        p[i] = i + 1;
        scanf("%d %d", &bt[i], &prior[i]);
    }

    int pos = 0;
    int temp = 0;
    // sorting process
    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (prior[j] > prior[pos])
                pos = j;
        }

        temp = prior[i];
        prior[i] = prior[pos];
        prior[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        awt += wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        atat += tat[i];
    }

    printf("Process\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    awt = (float)awt / n;
    atat = (float)atat / n;
    printf("\nAvg. waiting time : %.4f  Avg. Turnaround time : %.4f\n", awt, atat);

    return 0;
}