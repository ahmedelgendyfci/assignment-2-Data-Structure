#include <iostream>
#include <random>
#include <chrono> 
using namespace std;
using namespace std::chrono;

void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.

	int *temp = new int[high - low + 1];
	int i, j, k;
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}

	delete[] temp;
}

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}



//------------------------------------------------------- Quick Sort ---------------------------

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;    
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[10000];
	for (int i = 0; i < 10000; i++)
	{
		int randNum = rand() % 10000 ;
		arr[i] = randNum;
	}
	auto start = high_resolution_clock::now();
	//MergeSort(arr, 0, 10000 - 1);
	quickSort(arr, 0, 10000);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n----------------------------------Sorted Data-------------------------\n";
	for (int i = 0; i < 10000; i++)
	{
		cout << arr[i]<<" , ";
	}
	cout << endl << endl;
	cout << duration.count() << endl;



	system("pause");
	return 0;
}