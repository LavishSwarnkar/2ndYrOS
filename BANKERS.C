#include<stdio.h>
#include<conio.h>
void main()
{	int avail[3], max[5][3], allot[5][3], need[5][3], completed[5];
	int process, resource, i, j, instance, k=0, count1=0, count2=0;
	clrscr();
	printf("Enter no. of processes: ");
	scanf("%d", &process);
	printf("Enter no. of resources: ");
	scanf("%d", &resource);

	for(i=0 ; i<process ; i++)
		completed[i]=0;

	printf("Enter no. of available instances: ");
	for(i=0 ; i<resource ; i++)
	{	scanf("%d", &instance);
		avail[i] = instance;
	}

	printf("Enter max. no. of instances: ");
	for(i=0 ; i<process ; i++)
	{   printf("For P[%d]: ", i);
		for(j=0 ; j<resource ; j++)
		{	scanf("%d", &instance);
			max[i][j] = instance;
		}
	}

	printf("Enter allocation of instances: ");
	for(i=0 ; i<process ; i++)
	{   printf("For P[%d]: ", i);
		for(j=0 ; j<resource ; j++)
		{	scanf("%d", &instance);
			allot[i][j] = instance;
			need[i][j] = max[i][j]-allot[i][j];
		}
	}

	printf("Safe sequence: ");

	while(count1!=process)
	{	count2=count1;
		for(i=0 ; i<process ; i++)
		{	for(j=0 ; j<resource ; j++)
				if(need[i][j]<=avail[j])
					k++;
			if(k==resource && completed[i]==0)
			{	printf("P[%d], ", i);
				completed[i] = 1;
				for(j=0 ; j<resource ; j++)
					avail[j]=avail[j]+allot[i][j];
				count1++;
			}
			k=0;
		}

		if(count1==count2)
		{	printf("\t Stop..After this : Deadlock");
			break;
		}
	}
	getch();
}