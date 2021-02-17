#include "solve.h"
#include <stdio.h>
void solve (int n ,int m ,int **board)
{
	printf ("\nRunning maxsumdp\n") ;
	/*for (int i = 0 ; i < n ; i++) // printing board
	{
		for (int j = 0 ; j < m ; j++)
		{
			printf ("%d ", board[i][j]) ;
		}
		printf ("\n") ;
	}*/

	int array[n][m] ;
	for (int i = 0 ; i < n ; i++) // initialization of the array with -1
	{
		for (int j = 0 ; j < m ; j++)
		{
			array[i][j] = -1 ; 
			if (i == 0)
				array[i][j] = board[i][j] ;
		}
	}

	/*for (int i = 0 ; i < n ; i++) // printing the array 
	{
		for (int j = 0 ; j < m ; j++)
		{
			printf("array[%d][%d] = %d\n",i,j,array[i][j] );
		}
	}*/

	int max1 = -1 ;
	for (int j = 0 ; j < m ; j++) // finding the max of the first line 
	{
		if (board[0][j] > max1)
			max1 = board[0][j] ;
	}
	int max = -1 ;
	for (int i = 1 ; i < n ; i++)
	{
		for (int j = 0 ; j < m ; j++)
		{
			array[i][j] = board[i][j] + max1 ; 
		}
		for (int j = 0 ; j < m ; j++) // finding the max of the first line 
		{
			if (array[i][j] > max)
				max = array[i][j] ;
		}
		max1 = max ;
	}
	
	/*for (int i = 0 ; i < n ; i++) // printing the array 
	{
		for (int j = 0 ; j < m ; j++)
		{
			printf("array[%d][%d] = %d\n",i,j,array[i][j] );
		}
	}*/

	max = -1 ;
	for (int j = 0 ; j < m ; j++)
	{
		if (array[n-1][j] > max)
				max = array[n-1][j] ;
	}
	printf ("Max sum is %d\n", max) ;
}
