//FCFS Algo
#include<stdio.h>
#include<conio.h>
void calcTurnAroundTime(int processes[], int size, int st);
void calcWaitingTime(int processes[], int size, int st);
void main()
{	int processes[20], size, i, rt, st;
	clrscr();

	printf("Enter Start time: ");
	scanf("%d", &st);

	printf("Enter no. of processes: ");
	scanf("%d", &size);

	for(i=1 ; i<=size ; i++)
	{	printf("Enter burst time of P%d: ", i);
		scanf("%d", &processes[i]);
	}

	calcTurnAroundTime(processes, size, st);
	calcWaitingTime(processes, size, st);

	rt = size>=1 ? processes[1] : 0;
	printf("\n\nResponse Time:- %d", rt);
	getch();
}

void calcTurnAroundTime(int processes[], int size, int st)
{	int ta=0, i, a=processes[1], b=st, sum=0;
	float avg;

	printf("\nTurn Around Times:-");
	processes[0]=0;
	for(i=1 ; i<=size ; i++)
	{   ta = a-b;
		sum+=ta;
		b=a;
		a+=processes[i+1];
		printf("\nTA%d = %d", i, ta);
	}
	avg = sum;
	avg = avg/size;
	printf("\nAverage = %d/%d = %f",sum, size, avg);
}

void calcWaitingTime(int processes[], int size, int st)
{   int i, a=st, sum=0;
	float avg;

	printf("\n\nWaiting Times:-");
	for(i=1 ; i<=size ; i++)
	{   sum+=a;
		printf("\nWT%d = %d", i, a);
		a+=processes[i];
	}
	avg=sum;
	avg=avg/size;
	printf("\nAverage = %d/%d = %f",sum, size, avg);
}