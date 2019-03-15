//Priority Algo
#include<stdio.h>
#include<conio.h>
struct process
{ 	int P, AT, BT, BT_copy, CT, TA, WT;
};
int getNextJob(struct process pro[20], int time, int size)
{	int i, j=-1, tmp=-1;
	for(i=1 ; i<=size ; i++)
	{	if(pro[i].BT>0 && pro[i].AT<=time && pro[i].P>tmp)
		{	tmp = pro[i].P;
			j=i;
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
		printf("Enter priority of P%d: ", i);
		scanf("%d", &pro[i].P);
	}

	time=pro[1].AT;
	while(1)
	{	j=getNextJob(pro, time, size);
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

