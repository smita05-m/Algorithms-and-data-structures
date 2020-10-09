/* Heap sort uses Heap Data Structure for sorting an array. Heapify creates Min-heap in O(N) time and the whole algorithm
works in O(NlogN) time complexity.  */

#include<bits/stdc++.h>
using namespace std;

/* This function is used to convert the array to a min-heap. */
void heapify(long long *nos , int n , int i){
	int lar = i , l = 2 * i, r = 2 * i + 1;
	if(l <= n)
		if(nos[l] > nos[lar])
			lar = l;
			
	if(r <= n)
		if(nos[r] > nos[lar])
			lar = r;
			
	if(lar != i){
		swap(nos[lar] , nos[i]);
		heapify(nos , n , lar);
	}
}

int main(){
	long long n;
	cin>>n;
	long long nos[n + 1];
	for(int i = 1; i <= n; i++)
		cin>>nos[i];
	
    /* This loop starts from n/2 as the nodes from n/2 + 1 to n would be leaves and there is no use of calling heapify for leaves. */
	for(int i = n / 2; i > 0; i--)
		heapify(nos , n , i);
	
    /* The root of the heap contains the minimum element. So, we swap the last element and first element to store the minimum element
    at the last and call heapify for the root node to maintain the min-heap property. */
	for(int i = n; i > 0; i--){
		swap(nos[i] , nos[1]);
		heapify(nos , i - 1 , 1);
	}
	for(int i = 1; i <= n; i++)
	    cout<<nos[i]<<" ";
	cout<<"\n";
}