// C++ implementation to sort numbers on 
// the basis of factors 
#include <bits/stdc++.h> 

using namespace std; 

// structure of each element having its index 
// in the input array and number of factors 
struct element 
{ 
	int index, no_of_fact; 
}; 

// function to count factors for 
// a given number n 
int countFactors(int n) 
{ 
	int count = 0; 
	int sq = sqrt(n); 
	
	// if the number is a perfect square 
	if (sq * sq == n) 
		count++; 
	
	// count all other factors 
	for (int i=1; i<sqrt(n); i++) 
	{ 
		// if i is a factor then n/i will be 
		// another factor. So increment by 2 
		if (n % i == 0)	 
			count += 2; 
	}		 
	
	return count; 
} 

// comparsion function for the elements 
// of the structure 
bool compare(struct element e1, struct element e2) 
{ 
	// if two elements have the same number 
	// of factors then sort them in increasing 
	// order of their index in the input array 
	if (e1.no_of_fact == e2.no_of_fact) 
		return e1.index < e2.index; 
	
	// sort in decreasing order of number of factors 
	return e1.no_of_fact > e2.no_of_fact;	 
} 

// function to print numbers after sorting them in 
// decreasing order of number of factors 
void printOnBasisOfFactors(int arr[], int n) 
{	 
	struct element num[n]; 
	
	// for each element of input array create a 
	// structure element to store its index and 
	// factors count 
	for (int i=0; i<n; i++) 
	{ 
		num[i].index = i; 
		num[i].no_of_fact = countFactors(arr[i]);		 
	} 
	
	// sort the array of structures as defined 
	sort(num, num+n, compare); 
	
	// access index from the structure element and correponding 
	// to that index access the element from arr 
	for (int i=0; i<n; i++) 
		cout << arr[num[i].index] << " "; 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {5, 11, 10, 20, 9, 16, 23}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printOnBasisOfFactors(arr, n); 
	return 0; 
} 
