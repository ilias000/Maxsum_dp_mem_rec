#include "solve.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf ("\n******************* PROGRAM STARTED *******************\n") ;

	int n ,m ; // n = lines m = columns

	// reading the number of lines and the number of columns
	scanf ("%d", &n) ;
	scanf ("%d", &m) ;

	int ** board ;

	board = malloc (n * sizeof(int *)) ;
	if (board == NULL) // cheking if malloc returned NULL 
	{
	    printf ("Error. Allocation was unsuccessful. \n") ;
	    return 1 ;
	}

	for (int i = 0 ; i < n ; i++)
		board[i] = malloc (m * sizeof(int)) ; 

	// reading the integers for the array
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < m ; j++)
		{
			scanf ("%d", &board[i][j]);
		}
	}

/*	for (int i = 0 ; i < n ; i++) // printing the array
	{
		for (int j = 0 ; j < m ; j++)
		{
			printf("%d ", board[i][j]) ;
		}
	printf("\n");
	}*/

	// calling solve 
	solve (n,m,board) ;	

	free (board) ;	

	printf ("\n******************* PROGRAM ENDED *********************\n") ;
	return 0 ;
}