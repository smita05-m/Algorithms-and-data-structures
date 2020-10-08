/* Merge sort uses Divide and Conquer for sorting an array with average and worst case complexity of O(NlogN). */

#include<bits/stdc++.h>
using namespace std;

/* A utility function for printing the array */
void printArray(vector<long long> &nos){
    for(int i = 0; i < nos.size(); i++)
        cout<<nos[i]<<" ";
    cout<<"\n";
}

/* This function merges 2 sorted arrays into a single sorted array using 2 pointer. */
void mergeArrays(vector<long long> &nos , int l , int r){
	long long mid = (l + r) / 2 , size1 = mid - l + 1 , size2 = r - mid , leftArray[size1] , rightArray[size2];
    
	for(int i = l; i < l + size1; i++)
		leftArray[i - l] = nos[i];
	
	for(int i = mid + 1; i < mid + 1 + size2; i++)
	    rightArray[i - mid - 1] = nos[i];
	
		
	int leftPointer = 0 , rightPointer = 0 , oriPointer = l;
	
// 	for(int i = 0; i < size1; i++)
// 	    cout<<leftArray[i]<<" ";
// 	cout<<"\n";
// 	for(int i = 0; i < size2; i++)
// 	    cout<<rightArray[i]<<" ";
// 	cout<<"\n";
	
	while(oriPointer <= r){
		if(leftPointer < size1 && rightPointer < size2){
			if(leftArray[leftPointer] < rightArray[rightPointer]){
				nos[oriPointer] = leftArray[leftPointer];
				leftPointer++;
			}
			else{
				nos[oriPointer] = rightArray[rightPointer];
				rightPointer++;
			}	
		}
		else if(leftPointer < size1){
			nos[oriPointer] = leftArray[leftPointer];
			leftPointer++;
		}
		else{
			nos[oriPointer] = rightArray[rightPointer];
			rightPointer++;
		}
		oriPointer ++;
	}
// 	printArray(nos);
}

/* This function divides the array into 2 subarrays from the middle element as merge sort is based on Divide and Conquer. */
void mergeSort(vector<long long> &nos , int l , int r){
	if(l < r){
		int mid = (l + r) / 2;
		mergeSort(nos , l , mid);
		mergeSort(nos , mid + 1 , r);
		mergeArrays(nos , l , r);
	}
}

int main(){
	long long n;
	cin>>n;
	
	vector<long long>nos(n);
	for(int i = 0; i < n; i++)
		cin>>nos[i];
		
	mergeSort(nos , 0 , n-1);
	printArray(nos);
	    
	return 0;
}