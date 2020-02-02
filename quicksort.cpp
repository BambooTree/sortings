#include <iostream>
using namespace std;



void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

    
int partition(int arr[], int low, int up)
{
    int temp, i, j,pivot;
    i = low+1;
    j = up;
    pivot = arr[low];
    while(i<=j)
    {
            while((arr[i] < pivot) && (i<up))
               i++;
           while(arr[j]>pivot)
               j--;
           if(i<j)
           {
            swap(&arr[i],&arr[j]);
              i++;
              j--;
           }
           else
             i++;

    }
    arr[low]= arr[j];
    arr[j] = pivot;
    return j;

}

void quick_sort(int arr[], int low,int up)
{
   int pivot;
   if(low>=up)
            return ;
   pivot = partition(arr, low, up);
   quick_sort(arr, low ,pivot-1);  // Process Left Sublist
   quick_sort(arr, pivot+1,up);    // Process right Sublist

}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    quick_sort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 