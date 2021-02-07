#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

// merge two lists together 
int * merge(int a1[], int a2[], int a1_length, int a2_length) {

	int* result = new int[a1_length+a2_length];
	
	int i=0;
	int j=0;

	while(i < a1_length || j < a2_length) {
		if (i < a1_length && j < a2_length) {
			if (a1[i]<a2[j]){
				result[i+j]=a1[i];
				i++;
			}else{
				result[i+j]=a2[j];
				j++;
			}
		} else if(i<a1_length) {
			result[i+j]=a1[i];
			i++;
		} else {
			result[i+j]=a2[j];
			j++;
		}
	}

	return result;
}

int * mergesort(int a1[], int left, int right) {

	if (right-left == 0) {
		int* result = new int[0];
		return result;
	} else if (right-left == 1){
		int* result = new int[0];
		result[0] = a1[left];
		return result;
	} else if (right-left == 2) {
		if (a1[left] < a1[right-1]) {
			int* res = new int[2];
			res[0] = a1[left];
			res[1] = a1[right-1];
			return res; 
		} else {
			int* res = new int[2];
			res[0]= a1[right-1];
			res[1]= a1[left];
			return res;
		}
	}
	
	int middle = (right-left)/2;

	int* lefthalf = mergesort(a1, left, left+middle);
	int* righthalf = mergesort(a1, left+middle, right);
	
	return merge(lefthalf, righthalf, middle, right-middle-left);
}

int main() {
 	int n;
	std::scanf("%i", &n);
	std::cin.ignore(256,'\n');
	
	std::cout << "Number of tests: " << n << "\n" << "\n";

	for (int i=0; i<n; i++){
		std::string input_line;
		std::getline(std::cin, input_line);
		
		// initializes a string stream with input_line
		std::stringstream stream(input_line);
		
		int arr[input_line.length()];
			
		int pos;
		int j=0;
		std::cout << "Original List: ";
		while (stream >> pos){
			std::cout << pos;
			std::cout << " ";

			arr[j]=pos;
			j++;
		}

		std::cout << '\n';
		
		
		int * merged = mergesort(arr, 0, j);
		std::cout << "Sorted List: ";
		for (int z = 0; z<j; z++){
			std::cout << merged[z];
			std::cout << " ";
		}
		
		std:: cout << "\n\n";
		
	}	
	
	return 0;
}
