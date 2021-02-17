#include "solve.h"
#include <stdio.h>

 int maxSum (int n ,int m ,int **board) ; // returns the biggest max sum 
 int Sij (int n ,int m ,int i ,int j ,int **board) ; // finds and returns the max sum

void solve (int n ,int m ,int **board) // prints the biggest max sum 
{
	printf ("\nRunning maxsumrec\n") ;
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
	int i = n-1 ,temp = -1 ,max = -1 ;
	for (int j = 0 ; j < m ; j++) // calls the function Sij for all the data of the last line and keeps the bigest Sij
	{
		temp = Sij (n ,m ,i ,j ,board) ;
		if (temp > max)
		{
			max = temp ;
		}
	}
	return max ;
}

int Sij (int n ,int m ,int i ,int j ,int **board) // finds and returns the max sum
{
	int max = -1, temp = -1 ;
	if (i == 0) // first line
	{
		return board[i][j] ;
	}
	else if (i > 0 && j == 0) // the first column but not the first line
	{
		// to find the sij we call recursively the function Sij for the 3 possible paths and we keep the biggest one
		max = Sij (n ,m ,i-1 ,m-1 ,board) ;
		temp = Sij (n ,m ,i-1 ,0 ,board) ;
		if (temp > max)
		{
			max = temp ;
		}
		temp = Sij (n ,m ,i-1 ,1 ,board) ;
		if (temp > max)
		{
			max = temp ;
		}
		return max + board[i][j] ;
	}
	else if (i > 0 && j > 0 && j < (m-1)) // everything except the first line, the first column and the last column
	{
		// to find the sij we call recursively the function Sij for the 3 possible paths and we keep the biggest one
		max = Sij (n ,m ,i-1 ,j-1 ,board) ;
		temp =Sij (n ,m ,i-1 ,j ,board) ;
		if (temp > max)
		{
			max = temp ;
		}
		temp = Sij (n ,m ,i-1 ,j+1 ,board) ;
		if (temp > max)
		{
			max = temp ;
		}
		return max + board[i][j] ;
	}
	else if (i > 0 && j == (m-1)) // the last column but not the first line
	{
		// to find the sij we call recursively the function Sij for the 3 possible paths and we keep the biggest one
		max = Sij (n ,m ,i-1 ,j-1 ,board) ;
		temp = Sij (n ,m ,i-1 ,m-1 ,board) ;
		if (temp > max)
		{
			max = temp ;
		}
		temp = Sij (n ,m ,i-1 ,0 ,board) ;
		if (temp > max)
		{
			max = temp ;
		}
		return max + board[i][j] ;
	}
}