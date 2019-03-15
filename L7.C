//Round Robin Algo
#include<stdio.h>
#include<conio.h>
int jobQueue[20]={0}, isFirst=1;
struct process
{ 	int AT, BT, BT_copy, CT, TA, WT, last_time;
};
int getNextJob(struct process pro[20], int time, int size, int tq)
{   int i, j, k, curr;
	if(isFirst)
	{   jobQueue[0]=1;
		isFirst=0;
	}

	printf("\nAt t=%d: ", time);
	for(j=0 ; j<10 ; j++)
		printf("%d, ", jobQueue[j]);
	getch();

	for(i=0 ; jobQueue[i]==0 && i<19 ; i++);
	curr=jobQueue[i];
	jobQueue[i]=0;

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

	for(k=curr ; jobQueue[k]!=0 ; k++);

	for(j=curr+1 ; j<=size ; j++)
		if(pro[j].AT<=time && pro[j].BT>0 && !contains(jobQueue, j))
			jobQueue[k++]=j;

	if(pro[curr].BT>0)
		jobQueue[k++]=curr;

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

