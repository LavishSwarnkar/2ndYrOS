//Banker's Algo
#include<stdio.h>
#include<conio.h>

void main()
{   int i, j, sum, size, res, instances[5], alloc[10][5], max[10][5], avl[10][5], need[10][5];
	int done[10], pending[10], c, d, curr;
	clrscr();

	printf("Enter no. of processes (max. 10): ");
	scanf("%d", &size);
	printf("Enter no. of resources (max. 5): ");
	scanf("%d", &res);

	for(i=0 ; i<res ; i++)
	{	printf("Enter no. of instances of R%d: ", i+1);
		scanf("%d", &instances[i]);
	}

	printf("\nEnter allocation matrix- \n");
	for(i=0 ; i<size ; i++)
	{   for(j=0 ; j<res ; j++)
		{	printf("P%d R%d: ", i+1, j+1);
			scanf("%d", &alloc[i][j]);
		}
	}

	printf("\nEnter max matrix- \n");
	for(i=0 ; i<size ; i++)
	{   for(j=0 ; j<res ; j++)
		{	printf("P%d R%d: ", i+1, j+1);
			scanf("%d", &max[i][j]);
		}
	}

	printf("\nEnter initially available instances- \n");
	for(i=0 ; i<res ; i++)
	{	printf("R%d: ", i+1);
		scanf("%d", &avl[0][i]);
	}

	//Calculation of Need Matrix
	for(i=0 ; i<size ; i++)
		for(j=0 ; j<res ; j++)
			need[i][j] = max[i][j] - allox[i][j];

	c=curr=0;
	while(1)
	{   f=0;
		for(i=0 ; i<res ; i++)
			if(need[c][i] > avl[c][i])
			{	f=1;
				break;
			}

		if(!f)
		{	d++;
			done[c++]=curr;
			for(i=0 ; i<res ; i++)
				avl[curr][i] += alloc[curr][i];
		}
		else
			pending[p++]=curr;

	}

	printf("\nNeed Matrix:\n\t");
	for(i=0 ; i<res ; i++)
		printf("R%d\t", i);
	for(i=0 ; i<size ; i++)
	{   printf("\nP%d\t", i+1);
		for(j=0 ; j<res ; j++)
			printf("5\t", i+1, j+1);
	}

	printf("\n\nAvailable Matrix:\n\t");
	for(i=0 ; i<res ; i++)
		printf("R%d\t", i);
	for(i=0 ; i<size ; i++)
	{   printf("\nP%d\t", i+1);
		for(j=0 ; j<res ; j++)
			printf("5\t", i+1, j+1);
	}



	getch();
}