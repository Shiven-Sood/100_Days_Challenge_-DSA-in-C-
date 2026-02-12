/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/
#include<stdio.h>
int main () 
{
    int i , n ;
    printf("Enter the size of the array :");
    scanf("%d" , &n);
    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter the array elements : ");
    for ( i = 0 ; i < n ; i++ ) 
    {
        scanf("%d" , &A[i] );
    }
int pos ;
printf("Enter the position of the element that needs to be deleted :");
scanf("%d" , & pos );
if ( pos < 1 || pos > n ) 
{
    printf("Invalid position! Please enter position between 1 and %d\n" , n );
    return 1 ;

}
for ( i = pos - 1 ; i < n - 1 ; i++)
    {
    A[i]=A[i+1] ; 
    }
printf("Updated array is : ");
for ( i = 0 ; i < n - 1 ; i++ )
{
    printf("%d " , A[i]);
}
return 0 ;
}