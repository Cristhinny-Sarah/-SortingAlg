// Cristhinny Sarah P. Araujo
// 11/10/2020
// Bubble Sort is a sorting algorithm. The basic ideia is to go through a vector various times and each time move the biggest element to the end of the vector.
// This file has the implementation using loops.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Range of values 0 - 500 that will compose an 1D array
#define MAX 500

/* Function that generates random values to an array 'V' of lenght 'n' using MAX 500 to determine the
 * interval of integer values
 * @param int * V = pointer to an integer array
 * @param int n = lenght of an array V
 * return void
 */
void RandomArray(int * V, int n);

/* Function that shows on screen the content of an array 'V' of lenght 'n'
 * @param int * V = pointer to an integer array
 * @param int n = lenght of an array V
 * return void
 */
void PrintArray(int * V, int n);

/* Function that sort an array 'V' of lenght 'n' using Bubble Sort algorithm
 * @param int * V = pointer to an integer array
 * @param int n = lenght of an array V
 * return void
 */
void BubbleSort(int * V, int n);

int main(){
    // 'n' is the lenght of an array
    int n;

    printf("Choose the lenght of the array you wants to sort: ");
    // let's get from de user the number 'n'
    scanf("%d", &n);
    printf("\nGenerating random values for an array of %d positions...\n", n);
    
    // stating pointer V to an array
    int * V = NULL;
    // alocatting space for an integer array with length 'n'
    V = (int *)malloc(sizeof(int)*n);
    
    // verifying if the alocation worked, if not the program will be finished
    if(V == NULL){
        printf("Wasn't possible to alocate memory for this array. Ending the program\n");
        return 0;
    }

    // generating random values
    RandomArray(V, n);
    printf("\n\nThis is the initial array: ");
    // showing an array on the screen
    PrintArray(V, n);

    // sorting the array 'V'
    BubbleSort(V, n);
    printf("\nThe array sorted using Bubble Sort looks like this: ");
    // showing an array on the screen
    PrintArray(V, n);

    // freeing the memory alocated to the array 'V'
    free(V);
    
    return 0;
}

void RandomArray(int * V, int n){
    // makes pseudorandom number possible
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        // lets use the function rand() to generate values from 0 to 500 (MAX). Was used
        // the modulus operator so that we just take the interval we want
        V[i] = rand() % (MAX + 1);
    }
    
    return;
}

void PrintArray(int * V, int n){
    printf("[ %d", V[0]);
    
    for(int i = 1; i < n; i++){
        printf(", %d", V[i]);
    }
    
    printf(" ]\n\n");

    return;
}

void BubbleSort(int * V, int n){
    // variable to hold the biggest value of each iteration
    int max;
    // suport variable to help swap values between two variables
    int a;

    for(int i = n; i >= 0; i--){
        // let's assume that the first value is bigger than the following up
        max = V[0];
        for(int j = 1; j < i; j++){
            // if the value in 'V[j]' is lesser than the value in 'V[j - 1]' these two values will be exchanged 
            // if not, max receives the value in 'V[j]'
            if(V[j] <= max){
                a = V[j];
                V[j] = max;
                V[j-1] = a;
            }
            else{
                max = V[j];
            }
        }
    }
    return;
}

