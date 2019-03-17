//Round Robin Algo
#include<stdio.h>
#include<conio.h>
int jobQueue[30]={0}, front=-1, rear=-1;
struct process
{ 	int AT, BT, BT_copy, CT, TA, WT, last_time;
};
int getNextJob(struct process pro[20], int time, int size, int tq)
{   int i, curr;
	if(front==-1)
	{   jobQueue[0]=1;
		front=rear=0;
	}

	curr=jobQueue[front];
	jobQueue[front++]=0;

	if(curr==0)
		return -1;

	if(pro[curr].BT>=tq)
	{	pro[curr].last_time=tq;
		pro[curr].BT-=tq;
	}
	else
	{   pro[curr].last_time=pro[curr].BT;
		pro[curr].BT=0;
	}
	time+=pro[curr].last_time;

	for(i=curr+1 ; i<=size ; i++)
		if(pro[i].AT<=time && pro[i].BT>0 && !contains(jobQueue, i))
			jobQueue[++rear]=i;

	if(pro[curr].BT>0)
		jobQueue[++rear]=curr;

	return curr;
}

int contains(int a[], int x)
{	int i;
	for(i=0 ; i<20 ; i++)
		if(a[i]==x)
			return 1;
	return 0;
}

void main()
{	int size, i, time, j, tq;
	float avgTA=0, avgWT=0;
	struct process pro[20];
	clrscr();

	printf("Enter no. of processes: ");
	scanf("%d", &size);
	printf("Enter time quantum: ");
	scanf("%d", &tq);

	for(i=1 ; i<=size ; i++)
	{   printf("\nEnter arrival time of P%d: ", i);
		scanf("%d", &pro[i].AT);
		printf("Enter burst time of P%d: ", i);
		scanf("%d", &pro[i].BT);
		pro[i].BT_copy=pro[i].BT;
	}

	time=pro[1].AT;
	while(1)
	{	j=getNextJob(pro, time, size, tq);
		if(j!=-1)
		{   time+=pro[j].last_time;
			pro[j].CT = time;
		}
		else
			break;

	}

	printf("\nProcess\tAT\tBT\tCT\tTA\tWT\n");
	for(i=1 ; i<=size ; i++)
	{   pro[i].TA = pro[i].CT-pro[i].AT;
		pro[i].WT = pro[i].TA-pro[i].BT_copy;
		avgTA+=pro[i].TA;
		avgWT+=pro[i].WT;
		printf("P%d\t%2d\t%d\t%2d\t%2d\t%2d\n"
			, i, pro[i].AT, pro[i].BT_copy, pro[i].CT, pro[i].TA, pro[i].WT);
	}

	avgTA/=size;
	avgWT/=size;

	printf("\nAverage TA = %f", avgTA);
	printf("\nAverage WT = %f", avgWT);

	getch();
}