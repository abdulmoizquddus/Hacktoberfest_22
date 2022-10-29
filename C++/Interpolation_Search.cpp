// The Interpolation search is the upgraded version of binary search. It’s algorithm work on probing a position of the required value. Interpolation search algorithm work when the data is sorted and equally distribution. 
// The procedure will try to locate the exact position using interpolation formula. After finding the estimated location, it can separate the list using that location. As it tries to find exact location every time, so the searching time reduces. 
// This technique can find items easily if the items are uniformly distributed. 
// It is applicable when you know the distribution of your data. The intuition is simple: instead of guessing that the target value is in the middle of your range (as we do in Binary Search), you adjust your guess based on the value. 
// If the value is smaller than average, you aim near the beginning of the array. If the value much larger than average, you guess that the index should be near the end.

// Start
//  Step1: In a loop, calculate the value of “pos” using the probe position formula. 
//  Step2: If it is a match, return the index of the item, and exit. 
//  Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array. 
//  Step4: Repeat until a match is found or the sub-array reduces to zero.
// End


#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int lo, int hi, int value){
	if (lo <= hi && value >= arr[lo] && value <= arr[hi]) {
		int pos;
		// Probing Formula
		pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (value - arr[lo]));
		
		if (arr[pos] == value) 
			return pos;
		// using recusrion if element is not found at probe position
		if(arr[pos] < value )
			return interpolationSearch(arr, pos + 1, hi, value);
		if(arr[pos] > value )
			return interpolationSearch(arr, lo, pos - 1, value);
	}
	return -1;
}

int main(){
	int size, element, index;
	//Array of items on which search will be conducted.
	int arr[] = {2,8,12,14,18,20,25,29,33};
	// size of array
	size = sizeof(arr) / sizeof(arr[0]);
	// element to be searched
	element = 20;
	
	cout<<"Searching Element "<<element<<" in Array\n";
	// the function will return the index at which the element is found
	index = interpolationSearch(arr, 0, size - 1, element); 
	(index!=-1)?
		cout<< "Element found at index "<<index :
		cout<<"Element not Found";
}


// Time Complexity:
// 	>> Best Case : O(1)
//      When the array items have perfectly uniform Distribution and the difference between two positions value is same for all arrays
//      Example: {2, 4, 8, 10, 12, 14}
//  >> Average case : O(log2(log2 n))
//      When the array items have uniform Distribution but not perfectly distributed
//      Example: {1, 3, 4, 6, 9, 10}
//  >> Worst case : O(n)
//      When an array items are distributed exponentially such as the difference between any two position values are very exponential. Example: {1, 5, 6, 20, 26, 35, 60, 77, 89} 
// Space Complexity:
//      O(1)