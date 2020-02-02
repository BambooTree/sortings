// Merge Sort
#include <iostream>
using namespace std;

#define MAX 100
void copy(int arr[],int temp[], int low, int up)
{

	int i;
	for(i =low;i<=up;i++)
		arr[i]=temp[i];
}

void merge(int arr[], int temp[], int low1, int up1, int low2, int up2)
{

	int i =low1;
	int j= low2;
	int k =low1;
	while((i<= up1) && (j<=up2))
	{
		if(arr[i] <= arr[j])
			temp[k++] =arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=up1)
		temp[k++]= arr[i++];
	while(j<=up2)
		temp[k++] = arr[j++];

}


void merge_sort(int arr[],int low, int up)
{

	int mid , temp[MAX];
	if(low <up)
	{
		mid = ( low+up)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr,mid+1,up);
		merge(arr,temp,low, mid,mid+1,up);
		copy(arr,temp, low, up);
	}
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
  
    merge_sort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 