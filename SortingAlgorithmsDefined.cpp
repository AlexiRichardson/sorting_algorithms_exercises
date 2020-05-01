// SortingAlgorithmsDefined.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cctype>
#include<math.h>
#include<ctime>

using namespace std;
//function prototypes
template <typename ItemType>
int findIndexOfLargest(const ItemType theArray[], int size);
template<typename ItemType>
void selectionSort(ItemType theArray[], int n);
template<typename ItemType>
void insertionSort(ItemType theArray[], int n);
template<typename ItemType>
void bubbleSort(ItemType theArray[], int);
//^^^^^algorithms for sorting small arrays or sorting a large array once 
//algorithms below are for extremely large arrays, for pluralistic updating and sorting 
//divide-and-conquer faster sorting algorithms  - recursive formulations 
//merge sort functions 
template<typename ItemType>
void merge(ItemType theArray[], int first, int mid, int last);
template<typename ItemType>
void mergeSort(ItemType theArray[], int first, int last);
template<typename ItemType>
//quick sort functions
void sortFirstMiddleLast(ItemType theArray[], int firt, int mid, int last);
template<typename ItemType>
int partition(ItemType theArray[], int first, int last);
template<typename ItemType>
void quickSort(ItemType theArray[], int first, int last);
template<typename ItemType>
void randNumPop(ItemType theArray[]);
//template<typename ItemType>
//void treeSort();
//template<typename ItemType>
//void heapSort();
//template<typename ItemType>
//void shellSort()
template<typename ItemType>
void radixSort(ItemType theArray[], int n);



const int t_SIZE = 12;
const int SIZE = 11;//for testing sort algos
const int MAX_SIZE = 20;//for merge sort
const int RAND_NUMSIZE = 50; // for quick sort array size (random number gen 1-50)
const int MIN_SIZE = 4;//specify size of smallest subarray to use quick sort on


int main()
{
	int array_test[t_SIZE] = { 9, 3, 5, 4, 7, 6, 8, 1, 10, 12, 11, 2};
	int array[SIZE] = { 7, 4, 9, 3, 5, 1, 10, 6, 2, 8};
	int array2[SIZE] = { 25, 4, 89, 45, 3, 76, 18, 12, 7, 77};
	int array3[SIZE] = { 113, 76, 55, 4, 768, 445, 56, 99, 100, 73 };
	int array4[MAX_SIZE] = { 38, 16, 27, 39, 12, 27, 18, 15, 4, 2, 7, 11, 45, 23, 67, 55, 35, 99, 3, 9};
	int array5[RAND_NUMSIZE];

	char decision;//string literal for menu execution 
	cout << "Welcome to the sort algorithm menu.....\n";

	do {
		cout << "\nB. BubbleSort\n";
		cout << "I. InsertionSort\n";
		cout << "S. SelectionSort\n";
		cout << "M. MergeSort\n";
		cout << "Q. QuickSort\n";
		cout << "T. TreeSort\n";
		cout << "H. HeapSort\n";
		cout << "R. RadixSort\n";
		cout << "L. ShellSort\n";
		cout << "E. Exit\n";
		cout << "\nEnter in letter of menu selection: ";
		cin >> decision;

		switch (toupper(decision)) {

		case 'B': {	
						std::cout << "\n-------------------------------------------------------------" << endl;
						std::cout << "This is the unsorted array: " << std::endl;
						for (int i = 0; i < SIZE; i++)
						{
							std::cout << array[i] << ' ';
						}
						cout << endl;
						std::cout << "\nThis is the sorted array after bubble sort: \n";
						bubbleSort(array, SIZE);
						for (int i = 0; i < SIZE; i++)
						{
							std::cout << array[i] << ' ';
						}
						std::cout << "\n-------------------------------------------------------------" << endl;
						cout << endl;
				}
				  break;

		case 'I': {
						std::cout << "\n-------------------------------------------------------------" << endl;
						std::cout << "This is the unsorted array3: " << std::endl;
						for (int i = 0; i < SIZE; i++)
						{
							std::cout << array3[i] << ' ';
						}
						cout << endl;
						std::cout << "\nThis is the sorted array after the insertion sort: \n";
						insertionSort(array3, SIZE);
						for (int i = 0; i < SIZE; ++i) {
							std::cout << array3[i] << ' ';
						}
						std::cout << "\n-------------------------------------------------------------" << endl;
						cout << endl;
				}
				  break;

		case 'S': {

						std::cout << "\n-------------------------------------------------------------" << endl;
						std::cout << "This is the unsorted array2: " << std::endl;
						for (int i = 0; i < SIZE; i++)
						{
							std::cout << array2[i] << ' ';
						}
						cout << endl;
						std::cout << "\nThis is the sorted array after the selection sort: \n";
						selectionSort(array2, SIZE);
						for (int i = 0; i < SIZE; ++i) {
							std::cout << array2[i] << ' ';
						}
						std::cout << "\n-------------------------------------------------------------" << endl;
						
				}
				  break;

		case 'Q': {
						std::cout << "\n-------------------------------------------------------------" << endl;
						auto n2 = sizeof(array5) / sizeof(array5[0]);
						std::cout << "\nNumber of elements in random number generated array: " << n2 << endl;

						randNumPop(array5);//insert random numbers into quick sort array, size is 50
						std::cout << "The quick sort array after populating with numbers: \n";
						for (int i = 0; i < RAND_NUMSIZE; i++) {
							std::cout << array5[i] << ' ';
						}
						cout << endl;
						//call quick sort
						quickSort(array5, 0, RAND_NUMSIZE - 1);
						std::cout << "\nThe quick sort array after sorting: \n";
						for (int i = 0; i < RAND_NUMSIZE; i++) {
							std::cout << array5[i] << ' ';
						}
						std::cout << "\n-------------------------------------------------------------" << endl;
				}
				  break;

		case 'M': {
						std::cout << "\n-------------------------------------------------------------" << endl;

						std::cout << "The array before merge sort: " << endl;
						for (int i = 0; i < MAX_SIZE; i++) {
							std::cout << array4[i] << ' ';

						}
						cout << endl; 
						std::cout << "\nThe array after merge sort: " << endl;
						mergeSort(array4, 0, MAX_SIZE - 1);
						for (int i = 0; i < MAX_SIZE; i++) {
							std::cout << array4[i] << ' ';
						}
						std::cout << "\n-------------------------------------------------------------" << endl;
				}
				  break;

		case 'R': {
						std::cout << "\n-------------------------------------------------------------" << endl;
						auto n2 = sizeof(array5) / sizeof(array5[0]);
						std::cout << "\nNumber of elements in random number generated array: " << n2 << endl;

						randNumPop(array5);//insert random numbers into radix sort array, size is 50
						std::cout << "The radix sort array after populating with numbers: \n";
						for (int i = 0; i < RAND_NUMSIZE; i++) {
							std::cout << array5[i] << ' ';
						}
						cout << endl;
						//call radix sort
						radixSort(array5, RAND_NUMSIZE);
						std::cout << "\nThe radix sort array after sorting: \n";
						for (int i = 0; i < RAND_NUMSIZE; i++) {
							std::cout << array5[i] << ' ';
						}
						std::cout << "\n-------------------------------------------------------------" << endl;

				}
				  break;
		//case 'L': {


		//}
		default: cout << "\nExiting...";

		}



	} while (toupper(decision) != 'E');


}
template<typename ItemType>
void bubbleSort(ItemType array[], int n)//compare adjacent items and exchanges them if out of order
{//@param n The size of the array
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < n))
	{
		sorted = true; //Assume sorted
		//At this point, the array[n+1 - pass..n - 1] is sorted and all of its entries are > the entries in the array[0..n-pass]
		for (int index = 0; index < n - pass; index++)
		{
			//At this point, all entries in the array[0..index-1] are <= the array[index]
			int nextIndex = index + 1;
			if (array[index] > array[nextIndex])
			{
				//Exchange entries
				swap(array[index], array[nextIndex]);
					sorted = false; //signal exchange 
			}
		}
		//Assertion: the array[0..n-pass-1] < the array[n-pass]
		pass++;//increment number of passes through array elements
	}//end while
}//end bubble sort

template<typename ItemType>
void selectionSort(ItemType theArray[], int size)
{//Ascending Order
	//last = index of the last item in the subarray of items yet to be sorted 
	//largest = index of the largest item found
	for (int last = size - 1; last >= 1; last--)//decrement last index to ignore actual last 
	{//At this point, theArray[last+1..n-1] is sorted, and its entries are greater than those in theArray[0..last]
		//Select the largest entry in theArray[0..last]

		int largest = findIndexOfLargest(theArray, last + 1);

		//Swap the largest entry, theArray[largest], with theArray[last]
		std::swap(theArray[largest], theArray[last]);
	}
	
}

template<typename ItemType>
void insertionSort(ItemType theArray[], int n)
{
	//unsorted = first index of the unsorted region.
	//loc = index of insertion in the sorted region
	//nextItem = next item in the unsorted region
	//Initially, sorted region is theArray[0], unsorted region is theArray[1..n-1]
	//In general, sorted region is theArray[0..unsorted - 1], unsorted region theArray[unsorted..n-1]
	for (int unsorted = 1; unsorted < n; unsorted++) {
		//At this point,theArray[0..unsorted-1] is sorted
		//Find the right position(loc) in theArray[0..unsorted]
		//for theArray[unsorted], which is the first entry in the unsorted region; shift, if necessary, to make room
		ItemType nextItem = theArray[unsorted];
		int loc = unsorted;
		while((loc > 0) && (theArray[loc - 1] > nextItem)) {
			//Shift theArray[loc - 1] to the right
			theArray[loc] = theArray[loc - 1];
			loc--;
		}

		//At this point , theArray[loc] is where the nextItem belongs
		theArray[loc] = nextItem;
	}
}

template<typename ItemType>
int findIndexOfLargest(const ItemType theArray[], int size)
{
	int indexSoFar = 0;
	for (int currentIndex = 1; currentIndex < size; currentIndex++)
	{
		//At this point , theArray[indexSoFar] >= all entries in theArray[0..currentIndex -1]
		if (theArray[currentIndex] > theArray[indexSoFar])
		{   
			indexSoFar = currentIndex;
		}
	}
	return indexSoFar;
}
//@note This function merges the two subarrays into a temporary array and copies the result into the original array theArray.
template<typename ItemType>
void merge(ItemType theArray[], int first, int mid, int last) {//merge function requires use of auxiliary array - more memory storage and copying of data operations
	
	ItemType tempArray[MAX_SIZE]; //temporary array

	//Initialize the local indices to indicate the sub-arrays
	int first1 = first; //beginning of first sub-array
	int last1 = mid;    //end of first sub-array
	int first2 = mid + 1; //beginning of second sub-array
	int last2 = last; //end of second sub-array
	
	//while both subarrays are not empty, copy the smaller item into the temp array

	int index = first1;//next available location in temp array

	while ((first1 <= last1) && (first2 <= last2)) {
		//at this point, tempArray[first..index-1] is in order
		if (theArray[first1] <= theArray[first2]) {
			tempArray[index] = theArray[first1];
			first1++;
		}
		else {
			tempArray[index] = theArray[first2];
			first2++;
		}
		index++;

	}
	//Finish off the first subarray if necessary
	while (first1 <= last1) {

		//at this point tempArray[first..index-1] is in order
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	}
	//finish off the second subarray if necessary
	while (first2 <= last2) {

		//at this point tempArray[first..index-1] is in order
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	}

	//copy the result back into the original array
	for (index = first; index <= last; index++) {
		theArray[index] = tempArray[index];

	}

}
//Sorts the items in an array into ascending order
template<typename ItemType>
void mergeSort(ItemType theArray[], int first, int last) {

	if (first < last) {
		//sort each half
		int mid = first + (last - first) / 2; //index of midpoint

		//sort the left half theArray[first..mid]
		mergeSort(theArray, first, mid);

		//sort the right half theArray[mid+1..last]
		mergeSort(theArray, mid + 1, last);

		//merge the two halves
		merge(theArray, first, mid, last);

	}
}

template<typename ItemType>
void randNumPop(ItemType theArray[]) {

	srand(time(NULL));

	for (int i = 0; i < RAND_NUMSIZE; i++) {

		theArray[i] = (rand() % 100) + 1;

	}

}
//median of three pivot selection function
template<typename ItemType>
void sortFirstMiddleLast(ItemType theArray[], int first, int middle, int last) {

	ItemType temp, temp2, temp3;


		if (theArray[first] > theArray[middle]) {

			temp = theArray[first];
			theArray[first] = theArray[middle];
			theArray[middle] = temp;

		}
		if (theArray[middle] > theArray[last]) {

			temp2 = theArray[last];
			theArray[last] = theArray[middle];
			theArray[middle] = temp2;
		}
		if (theArray[first] > theArray[middle]) {

			temp3 = theArray[first];
			theArray[first] = theArray[middle];
			theArray[middle] = temp3;

		}
}

template<typename ItemType>
int partition(ItemType theArray[], int first, int last)
{
	ItemType temp;

	//Choose pivot and reposition it
	int mid = first + (last - first) / 2;
	sortFirstMiddleLast(theArray, first, mid, last);

	//Interchange
	temp = theArray[last - 1];
	theArray[last - 1] = theArray[mid];
	theArray[mid] = temp;

	int pivotIndex = last - 1;
	ItemType pivot = theArray[pivotIndex];

	//Determine the regions S sub 1 and S sub 2
	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	bool done = false;

	while (!done) {

		//locate first entry on left that is >= pivot
		while (theArray[indexFromLeft] < pivot)
			indexFromLeft = indexFromLeft + 1;
		//locate first entry on right that is <= pivot 
		while (theArray[indexFromRight] > pivot)
			indexFromRight = indexFromRight - 1;
		//now indexFromLeft has a new index subscript and indexFromRight has a new index subscript
		//compare the two indexes 
		if (indexFromLeft < indexFromRight) {

			ItemType temp2 = theArray[indexFromRight];
			theArray[indexFromRight] = theArray[indexFromLeft];
			theArray[indexFromLeft] = temp2;
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;

		}
		else
			done = true;
	}
	//Place pivot in proper position between Ssub1 and Ssub2 and mark its new location
	theArray[pivotIndex] = theArray[indexFromLeft];
	theArray[indexFromLeft] = pivot;
	pivotIndex = indexFromLeft;

	return pivotIndex;
	
}
template<typename ItemType>
void quickSort(ItemType theArray[], int first, int last) {
	//relegate out small arrays 
	
	int n = last - first + 1;//index range of elements to consider

	int middle = first + (last - first) / 2;
	//base case
	if ( n < MIN_SIZE){//array is of size < 4 so no partition or quick sort

		sortFirstMiddleLast(theArray, first, middle, last);

	}
	else {
		//Make the partition : S1 | Pivot | S2
		int pivotIndex = partition(theArray, first, last);

		//Sort subarrays S1 and S2
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);

	}
	

}
template<typename ItemType>
void radixSort(ItemType theArray[], int n) {//to sort numeric data the radix sort treats a number as a character string
	//Sorts n d-digit integers in the array theArray
	//digitPos <- maximum place value of digits in the largest element (units, 10, 100, 1000) 
	int max = getMax(theArray, n);

	for (int digitPos = 1; max / digitPos > 0; digitPos *= 10) {

		countingSort(theArray, n, digitPos);
	}
		
		
}
//Function to get largest element from an array - in terms of radices values 
template<typename ItemType>
int getMax(ItemType theArray[], int n) {
	int maxVal = theArray[0];
	for (int i = 1; i < n; i++) {
		if (theArray[i] > maxVal)
			maxVal = theArray[i];
	}
	return maxVal;
}

template<typename ItemType>
void countingSort(ItemType theArray, int n, int d) {
	
	const int baseMax = 10;
	//Initialize 10 groups to empty
	ItemType groupsArray[10] = { 0 };//radix or base of decimal number system is 10
	ItemType outputArray[n];
	
	for (int i = 0; i < baseMax; i++)
		groupsArray[i] = 0;//initialize a counter for each group to 0
	//digit places index counter 
	for (int i = 0; i < n; i++) {
		groupsArray[(theArray[i] / d ) % 10]++;
	}
	//cumulative counter dictates index of element in output array 
	for (int i = 1; i < baseMax; i++) {
		groupsArray[i] += groupsArray[i - 1];
	}
	//put sorted elements into output array from input array
	for (int i = n - 1; i >= 0; i--) {
		outputArray[groupsArray[(theArray[i] / d) % 10] - 1] = theArray[i];
		groupsArray[(theArray[i] / d) % 10]--;//decrement count of occurences within accessed index in array 
	}

	for (int i = 0; i < n; i++) {
		theArray[i] = outputArray[i];
	}
	
}

template<typename ItemType>
void printArray(ItemType theArray[], int size) {
	for (int i = 0; i < size; i++)
		cout << theArray[i] << " ";
	cout << endl; 
}

