/*******************************************
Task: Write an algorithm quicksort
Finished: Student IU8 - 22 Barashkin E.
********************************************/

//Libraries needed for implementation of the algorithm//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Function quicksort//
void quickSort(int A[], int min, int max) 
{
      int i = min, j = max; // The upper and lower limits of sorting
      int buf; // Buffer for data exchange
      int goal = A[(min + max) / 2]; // The support element sorting
 
	  //Find items for exchange//
      while (i <= j) 
	  {
            while (A[i] < goal)// Search on the left side
			{
                  i++;
			}
            while (A[j] > goal)// Search on the right side
			{
                  j--;
			}

			//Exchange of elements in some places//
            if (i <= j) 
			{
                  buf = A[i];
                  A[i] = A[j];
                  A[j] = buf;
				  //Jumps to the next//
                  i++;
                  j--;
            }
      }
 
      //Recursive call to the other elements//
      if (min < j)
            quickSort(A, min, j); 
      if (i < max)
            quickSort(A, i, max); 
}

//The main function//
int main() 
{
	//Variable declaration//
	int *mas; // Array
	int i = 0; // Index
	int n = 0; // Dimension

	printf("Demonstration of quicksort\n");
	printf("\nEnter the dimensions of the array: ");
	scanf("%d", &n); // Request an array dimension
	mas = (int*)malloc (n * sizeof(int)); // Allocate memory for the array
	srand(time(NULL)); 
	printf("\nThe source array:\n"); 

	//Filling and output array//
	for(i = 0 ; i < n; i++)
	{
		mas[i] = rand()%10; //Filling an array with random numbers from 0 to 9.
		printf("%d ", mas[i]); // How to print an array.
	}

    //Call function to sort the array created//
	quickSort(mas, 0, (n-1));

	printf("\n\nSorted array:\n");
	 
	//Of the sort array//
	for(i = 0 ; i < n; i++)
	{
		printf("%d ", mas[i]);
	}  
	free(mas); // Free memory allocated for the array
} 
