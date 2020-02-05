 #include <iostream>
 using namespace std;

 void swap(int arr[], int i, int j)
  {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
void shellSort(int arr[] , int n) 
{
		for(int gap = n/2; gap >= 1; gap/=2)
		{
			for(int j=gap ; j < n ; j++)
			{
				for(int i = j - gap; i>=0 ; i-=gap)
				{
					if(arr[i+gap] < arr[i])
						swap(arr, i+gap , i);
					else 
						break;
				}
			}
		}
	}
	// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

/* Driver code */
int main() 
{ 
	int arr[] = { 12, 11, 13, 5, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<" Before sorting Array "<<endl;
printArray(arr, n); 
	shellSort(arr, n); 
     cout<<" After Sorting Array"<<endl;	
		printArray(arr, n); 

	return 0; 
} 