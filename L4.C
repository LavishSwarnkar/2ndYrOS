//SJF(Preemptive) Algo
#include<stdio.h>
#include<conio.h>
struct process
{ 	int AT, BT, BT_copy, CT, TA, WT;
};
int getShortestJob(struct process pro[20], int time, int size)
{   int i, j=-1, tmp=999;
	for(i=1 ; i<=size ; i++)
	{	if(pro[i].AT<=time && pro[i].BT<=tmp && pro[i].BT>0)
		{	tmp = pro[i].BT;
			j=i;
		}
	}
	for(i=1 ; i<=size ; i++)
	{	if(pro[i].BT==tmp)
		{	j=i;
			break;
		}
	}
	if(j!=-1)
	{	pro[j].BT--;
	}
	return j;
}
void main()
{	int size, i, time, j;
	float avgTA=0, avgWT=0;
	struct process pro[20];
	clrscr();

	printf("Enter no. of processes: ");
	scanf("%d", &size);

	for(i=1 ; i<=size ; i++)
	{   printf("\nEnter arrival time of P%d: ", i);
		scanf("%d", &pro[i].AT);
		printf("Enter burst time of P%d: ", i);
		scanf("%d", &pro[i].BT);
		pro[i].BT_copy=pro[i].BT;
	}

	time=pro[1].AT;
	while(1)
	{	j=getShortestJob(pro, time, size);
		if(j!=-1)
		{   time++;
			pro[j].CT = time;
		}
		else
		{	break;
		}
	}

	printf("\nProcess\tAT\tBT\tCT\tTA\tWT\n");
	for(i=1 ; i<=size ; i++)
	{   pro[i].TA = pro[i].CT-pro[i].AT;
		pro[i].WT = pro[i].TA-pro[i].BT_copy;
		avgTA+=pro[i].TA;
		avgWT+=pro[i].WT;
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n"
			, i, pro[i].AT, pro[i].BT_copy, pro[i].CT, pro[i].TA, pro[i].WT);
	}

	avgTA/=size;
	avgWT/=size;

	printf("\nAverage TA = %f", avgTA);
	printf("\nAverage WT = %f", avgWT);

	getch();
}

