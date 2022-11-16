#include <stdio.h>

int main()
{
    int n, quant;
    int bt[20], rt[20], at[20];
    float atat, awt;
    printf("Enter no. of process : ");
    scanf("%d", &n);

    printf("Enter BT and AT for process : \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d] : ", i+1);
        scanf("%d %d", &bt[i], &at[i]);        
        rt[i] = bt[i];
    }

    printf("Enter time quantum : ");
    scanf("%d", &quant);

    int t = 0, i = 0;
    int y = n, count = 0;
    int wt = 0, tat=0;

    printf("Process\tAT\tBT\tWT\tTAT\n");
    
    while (y!=0)
    {
        if (rt[i] <= quant && rt[i]>0)
        {
            t += rt[i];
            rt[i] = 0;
            count = 1; 
        }
        else if (rt[i] > 0){
            t += quant;
            rt[i] -= quant;
    
        }

        if(rt[t]==0 && count==1){
            y--;
            printf("%d\t%d\t%d\t%d\t%d",i+1, at[i], bt[i], t-at[i],t-at[i]-bt[i]);
            wt = wt + t - at[i] - bt[i];
            tat = tat + t - at[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= t)
        {
            i++;
        }
        else
        {
            i = 0;
        }
        // printf("Done\n");
    }

    float avg_wt = wt * 1.0 / n;
    float avg_tat = tat * 1.0 / n;
    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f", avg_tat);
}