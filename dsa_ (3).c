/* Wap to search a key k in an array using linear search and also display the number of comparisons made to find the key k and also display the index of the key k that is found  .
using malloc .*/
#include<stdio.h>
#include<stdlib.h>
int main () 
{
    int i , n , k , comp = 0 ;
    printf ("Enter the size of the array : ");
    scanf("%d" , &n ) ;
int *A = malloc ( n * sizeof ( int ) ) ;
    if ( A == NULL ) 
    {
        printf("Memory allocation failed\n");
        return 1; 
    }
    printf("Enter the elements of the array : ");
    for ( i = 0 ; i < n ; i++ ) 
    {
        scanf("%d" , &A[i] ) ;
    }
    printf("Enter the key to be searched : ");
    scanf("%d" , &k ) ;
    for ( i = 0 ; i < n ; i++ ) 
    {
        comp++ ;
        if ( A[i] == k ) 
        {
            printf("Key found at index %d after %d comparisons\n" , i , comp );
            break ;
        }
    }
    if ( i == n ) 
    {
        printf("Key not found after %d comparisons\n" , comp );
    }
    free(A) ;
        return 0 ;
}