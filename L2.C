//SJF(NP) Algo
#include<stdio.h>
#include<conio.h>
struct process
{ 	int AT, BT, CT, TA, WT, done;
};
int getShortestJob(struct process pro[20], int time, int size)
{   int i, j=-1, tmp=999;
	for(i=1 ; i<=size ; i++)
	{	if(pro[i].done==0 && pro[i].AT<=time && pro[i].BT<=tmp)
		{   tmp = pro[i].BT;
			j=i;
		}
	}
	if(j!=-1)
		pro[j].done=1;
	return j;
}
void main()
{	int size, i, time, j;
	float avgTA, avgWT;
	struct process pro[20];
	clrscr();

	printf("Enter no. of processes: ");
	scanf("%d", &size);

	for(i=1 ; i<=size ; i++)
	{   printf("\nEnter arrival time of P%d: ", i);
		scanf("%d", &pro[i].AT);
		printf("Enter burst time of P%d: ", i);
		scanf("%d", &pro[i].BT);
		pro[i].done = 0;
	}

	time=pro[1].AT;
	for(i=1 ; i<=size ; i++)
	{	j=getShortestJob(pro, time, size);
		if(j!=-1)
		{   time+=pro[j].BT;
			pro[j].CT = time;
			pro[j].TA = pro[j].CT-pro[j].AT;
			pro[j].WT = pro[j].TA-pro[j].BT;
			avgTA+=pro[j].TA;
			avgWT+=pro[j].WT;
		}
	}
	avgTA/=size;
	avgWT/=size;

	printf("\nProcess\tAT\tBT\tCT\tTA\tWT\n");
	for(i=1 ; i<=size ; i++)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, pro[i].AT, pro[i].BT, pro[i].CT, pro[i].TA, pro[i].WT);

	printf("\nAverage TA = %f", avgTA);
	printf("\nAverage WT = %f", avgWT);

	getch();
}

