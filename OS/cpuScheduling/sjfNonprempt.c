#include<stdio.h>
void main()
{
    int bt[100],at[100],pro[100],ct[100],tat[100],wt[100],n,i,j,temp,temp1,temp2,ttat=0,twt=0,v[100];
    float attat,awt;
    printf("enter number of processes ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter arrival time and bust time of process%d ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        pro[i]=i+1;
        v[i]=0;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp1=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp1;
                temp2=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp2;
            }
        }
    }
    for(i=0;i<=at[n-1]+bt[n-1];i++)
    {
        for(j=0;j<n;j++)
        {
            if(at[j]<=i && v[j]==0)
            {
                ct[j]=i+bt[j];
                v[j]=1;
                i=ct[j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        ttat+=tat[i];
        twt+=wt[i];
    }
    awt=(float)twt/n;
    attat=(float)ttat/n;
    for(i=0;i<n;i++)
    printf("\n\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\nAvg TAT=%f\nAvg WT=%f",attat,awt);
    printf("\nGant Chart \n");
    for(i=0,j=0;i<ct[n-1];)
    {
        if(i<at[j])
        {
            printf("%d|---",i);
            i++;
        }
        else if(i>=at[j])
        {
            printf("|%d|P%d",i,pro[j]);
            i=ct[j];
            j++;
        }
    }
    printf("|%d",ct[n-1]);
}
