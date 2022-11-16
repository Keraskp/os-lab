#include <stdio.h>

int main()
{

    int i, n, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], rt[10];
    float avg_wt, avg_tat;
    printf(" Total number of process in the system: ");
    scanf("%d", &n);
    y = n; 

    for (i = 0; i < n; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf(" Arrival time is: \t"); 
        scanf("%d", &at[i]);
        printf(" \nBurst time is: \t"); 
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; 
    }
    
    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &quant);
    
    // Display the process No, burst time, Turn Around Time and the waiting time
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (rt[i] <= quant && rt[i] > 0) // define the conditions
        {
            sum = sum + rt[i];
            rt[i] = 0;
            count = 1;
        }
        else if (rt[i] > 0)
        {
            rt[i] = rt[i] - quant;
            sum = sum + quant;
        }
        if (rt[i] == 0 && count == 1)
        {
            y--; // decrement the process no.
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_wt = wt * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f", avg_tat);

    return 0;
}