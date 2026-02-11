#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
 {
    return (*(int*)a - *(int*)b);
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
     scanf("%d", &arr[i]);

    qsort(arr,n,sizeof(int),cmp);

    int left=0,right = n-1;
    int bestSum=1000000000;
    int ans1 = arr[left], ans2 = arr[right];

    while(left < right)
     {
        int sum = arr[left] + arr[right];
        if(abs(sum)<abs(bestSum))
         {
            bestSum = sum;
            ans1 = arr[left];
            ans2 = arr[right];
        }
        if(sum<0)
        left++;
        else right--;
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}