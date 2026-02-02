/* Insert an Element in an Array 
Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)
Output:
- Print the updated array (n+1 integers) in a single line, space-separated
Example:
Input:
5
1 2 4 5 6
3
3
Output:
1 2 3 4 5 6
Explanation: Insert 3 at position 3, elements [4,5,6] shift right */
#include<stdio.h>
int main () 
{
    int i , n ;
    printf("Enter the size of the array :");
    scanf("%d" , &n );
    int *A = (int *)malloc((n + 1) * sizeof(int));
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
int pos , value ;
printf("Enter the position at which the elemment needs to be inserted :");
scanf("%d" , & pos );
if ( pos < 1 || pos > n + 1 ) 
{
    printf("Invalid position! Please enter position between 1 and %d\n" , n + 1 );
    return 1 ;
}
printf("Enter the value that needs to be entered in the position :");
scanf("%d" , & value );
for ( i = n ; i>=pos ; i--)
    {
    A[i]=A[i-1] ; 
    }
A[pos-1]= value ;
n = n + 1 ;
printf("The updated array is : ");
for ( i = 0 ; i < n ; i++ ) 
{
    printf("%d " , A[i] );
}
return 0 ;
}