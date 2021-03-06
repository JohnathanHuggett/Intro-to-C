#include <stdio.h>
#include "lib.h"

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).

    JS QUICK SORT

function quickSort(nums) {
    if (nums.length <= 1) return nums;
    else {
        let pivot = Math.floor(nums.length / 2); //nums[0]; first attempt 
        let leftSide = [];
        let rightSide = [];

    for (let i = 0; i < nums.length; i++) {
      if (nums[i] <= pivot) {
        leftSide.push(nums[i]);
        leftSide.sort();
      }
      else {
        rightSide.push(nums[i]);
        rightSide.sort();
      }
    }  
    return leftSide.concat(rightSide);
    }
}

*/
void quicksort(int arr[], int low, int high)
{   
    
    int pivot; 
    int i; 
    int j;
    int temp;

    // int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    // 79, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 100
    if (low < high) {
        pivot = low;
        i=low;
        j=high;

        while (i < j) {
            while (arr[i] <= arr[pivot] && i < high) {
                i++;
            }
            while (arr[j] > arr[pivot]) {
                j--;
            }
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
    // printf("arr: %d\n", low);
}

#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    quicksort(arr1, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}
#endif
