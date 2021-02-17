#include "solve.h"
#include <stdio.h>
#include <stdlib.h>

int maxSum (int n ,int m ,int **board) ; // returns the biggest max sum 
int Sij (int n ,int m ,int i ,int j ,int **board ,int **sij) ; // finds and returns the max sum

void solve (int n ,int m ,int **board)
{
	printf ("\nRunning maxsummem\n") ;
	/*for (int i = 0 ; i < n ; i++) // printing board
	{
		for (int j = 0 ; j < m ; j++)
		{
			printf ("%d ", board[i][j]) ;
		}
		printf ("\n") ;
	}*/
	int max = maxSum (n ,m ,board) ;
	printf ("Max sum is %d\n", max) ;
}

int maxSum (int n ,int m ,int **board) // returns the biggest max sum 
{
	// creating the 2nd array that we are going to save all the sij
	int ** sij ;

	sij = malloc(n * sizeof(int *)) ;
	if (sij == NULL) // cheking if malloc returned NULL 
	{
	    printf("Error. Allocation was unsuccessful. \n") ;
	    return 1;
	}
	for (int i = 0 ; i < n ; i++)
		sij[i] = malloc (m * sizeof(int)) ; 
	for (int i = 0 ; i < n ; i++) // initialization of the table sij with -1
	{
		for (int j = 0 ; j < m ; j++)
		{
			sij[i][j] = -1 ;
		}
	}
	/*for (int i = 0 ; i < n ; i++) // prints the table sij before we start putting the sijs in
	{
		for (int j = 0 ; j < m ; j++)
		{
			printf("%d ", sij[i][j]) ;
		}
		printf("\n") ;
	}*/
	int i = n-1 ,temp = -1 ,max = -1 ;
	for (int j = 0 ; j < m ; j++) // calls the function Sij for all the data of the last line and keeps the bigest Sij
	{
		temp = Sij (n ,m ,i ,j ,board ,sij) ;
		if (temp > max)
		{
			max = temp ;
		}
	}
	/*for (int i = 0 ; i < n ; i++) // prints the table sij after we insert all the sijs so we can see that it has the right values
	{
		for (int j = 0 ; j < m ; j++)
		{
			printf("%d ", sij[i][j]) ;
		}
		printf("\n") ;
	}*/
	free (sij) ;
	return max ;
}

int Sij (int n ,int m ,int i ,int j ,int **board ,int **sij) // finds and returns the max sum
{ 
	int max = -1, temp = -1 ;
	if (i == 0) // first line
	{
		sij[i][j] = board[i][j] ;
		return board[i][j] ;
	}
	else if (i > 0 && j == 0) // the first column but not the first line
	{
		if (sij[i][j] != -1) // if we alredy have find the sij take it from the array else find it and insert it in the array
			return sij[i][j] ;
		// to find the sij we call recursively the function Sij for the 3 possible paths and we keep the biggest one
		max = Sij (n ,m ,i-1 ,m-1 ,board ,sij) ;
		temp = Sij (n ,m ,i-1 ,0 ,board ,sij) ;
		if (temp > max)
		{
			max = temp ;
		}
		temp = Sij (n ,m ,i-1 ,1 ,board ,sij) ;
		if (temp > max)
		{
			max = temp ;
		}
		sij[i][j] = max + board[i][j] ;
		return max + board[i][j] ;
	}
	else if (i > 0 && j > 0 && j < (m-1)) // everything except the first line, the first column and the last column
	{
		if (sij[i][j] != -1) // if we alredy have find the sij take it from the array else find it and insert it in the array
			return sij[i][j] ;
		// to find the sij we call recursively the function Sij for the 3 possible paths and we keep the biggest one
		max = Sij (n ,m ,i-1 ,j-1 ,board ,sij) ;
		temp =Sij (n ,m ,i-1 ,j ,board ,sij) ;
		if (temp > max)
		{
			max = temp ;
		}
		temp = Sij (n ,m ,i-1 ,j+1 ,board ,sij) ;
		if (temp > max)
		{
			max = temp ;
		}
		sij[i][j] = max + board[i][j] ;
		return max + board[i][j] ;
	}
	else if (i > 0 && j == (m-1)) // the last column but not the first line
	{
		if (sij[i][j] != -1) // if we alredy have find the sij take it from the array else find it and insert it in the array
			return sij[i][j] ;
		// to find the sij we call recursively the function Sij for the 3 possible paths and we keep the biggest one
		max = Sij (n ,m ,i-1 ,j-1 ,board ,sij) ;
		temp = Sij (n ,m ,i-1 ,m-1 ,board ,sij) ;
		if (temp > max)
		{
			max = temp ;
		}
		temp = Sij (n ,m ,i-1 ,0 ,board ,sij) ;
		if (temp > max)
		{
			max = temp ;
		}
		sij[i][j] = max + board[i][j] ;
		return max + board[i][j] ;
	}
}