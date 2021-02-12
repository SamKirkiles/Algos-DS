#include <iostream>
#include <vector> 

using namespace std;

void print_matrix(vector<vector<int>> mat){
	int rows = mat.size();
	int cols = mat[0].size(); 
	
	for (int i=0; i<rows; i++) {
		cout << "| ";	
		for (int j=0; j<cols; j++) {
			cout << mat[i][j] << " " ;
		}	
		cout << "|\n";
	}
}

/**
 * Brute force   
 */
vector<vector<int>> brute_force_multiply(vector<vector<int>> v1, vector<vector<int>> v2) {
	
	int v1_rows = v1.size();
	int v1_columns = v1[0].size();	
		
	int v2_rows = v1.size();
	int v2_columns = v2[0].size();

	vector<vector<int>> result;
	
	// iterate over rows of v1 
	for (int i=0; i<v1_rows; i++) {
		vector<int> output_row;
		//iterate over columns of v2
		for (int j=0; j< v2_columns;  j++) {

			int pos_sum = 0; 
			// iterate over rows of v2
			for (int k=0; k<v1_columns; k++) {
				pos_sum += v1[i][k]*v2[k][j];
			}
			output_row.push_back(pos_sum);
		}
		result.push_back(output_row);
	}	
	
	return result;
}

vector<vector<int>> mat_add (vector<vector<int>> v1, vector<vector<int>> v2){
	
	int size = v1.size();

	vector<vector<int>> result;	
	for (int i=0; i<v1.size(); i++){
		vector<int> row;
		for (int j=0; j<v1[0].size(); j++){
			row.push_back(v1[i][j]+v2[i][j]);
		}	
		result.push_back(row);	
	}
	return result;
}

/**
* Divide and Conquer matrix multiply
*
*/
vector<vector<int>> square_mat_mul_rec(vector<vector<int>> v1, vector<vector<int>> v2,
				       int start_x_1, int start_y_1, int start_x_2, int start_y_2, int size) {

	if (size == 1) {
		vector<vector<int>> result = {{v1[start_x_1][start_y_1]*v2[start_x_2][start_y_2]}};
		return result;
	}

	int half = size/2;

	// A_11*B_11+A_12*B_21	
	vector<vector<int>> c_11 = mat_add(square_mat_mul_rec(v1, v2, start_x_1, start_y_1, start_x_2, start_y_2,  half), 
					   square_mat_mul_rec(v1 ,v2, start_x_1, start_y_1+half, start_x_2+half, start_y_2, half));

	// A_11*B12+A_12*B_22
	vector<vector<int>> c_12 = mat_add(square_mat_mul_rec(v1, v2, start_x_1, start_y_1, start_x_2, start_y_2+half, half),
					   square_mat_mul_rec(v1, v2, start_x_1, start_y_1+half, start_x_2+half, start_y_2+half, half));

	// A_21*B11+A_22*B_21
	vector<vector<int>> c_21 = mat_add(square_mat_mul_rec(v1, v2, start_x_1+half, start_y_1, start_x_2, start_y_2, half),
					   square_mat_mul_rec(v1, v2, start_x_1+half, start_y_1+half, start_x_2+half, start_y_2, half)); 

	// A_21*B12+A_22*B_22
	vector<vector<int>> c_22 = mat_add(square_mat_mul_rec(v1, v2, start_x_1+half, start_y_1, start_x_2, start_y_2+half, half),
					   square_mat_mul_rec(v1, v2, start_x_1+half, start_y_1+half, start_x_2+half, start_y_2+half, half)); 
	

	vector<vector<int>> result;

	// Concat final answer	

	for (int i=0; i<half; i++) {
		vector<int> row;

		row.insert(row.begin(), c_11[i].begin(), c_11[i].end());
		row.insert(row.begin()+half, c_12[i].begin(), c_12[i].end());
		
		result.push_back(row);
	} 

	for (int i=0;i<half; i++){
		vector<int> row; 

		row.insert(row.begin(), c_21[i].begin(), c_21[i].end());
		row.insert(row.begin()+half, c_22[i].begin(), c_22[i].end());
		
		result.push_back(row);
	}
	
	return result;
	
}

/*
 * Strassen's method for matrix multiplication
 */
vector<vector<int>> strassn_multiply(vector<vector<int>> v1, vector<vector<int>> v2){
		
	return vector<vector<int>>();
}


int main(){

	vector<vector<int>> vect_1
    	{
        	{1,2,3,4},
        	{5,6,7,8},
       		{9,10,11,12},
		{13,14,15,16}
    	};
	
	vector<vector<int>> vect_2
	{
		{16,15,14,13},
		{12,11,10,9},
		{8,7,6,5},
		{4,3,2,1}
	};

	cout << "Computing the product of the following two matrices: \n";
	
	print_matrix(vect_1);

	cout << "\n";

	print_matrix(vect_2);		
	
	vector<vector<int>> result = brute_force_multiply(vect_1, vect_2);
	
	cout << "Brute Force Result: \n";
	
	print_matrix(result);

	cout << "Divide and Conquer Result: \n";
	
	int size= vect_1.size();
	vector<vector<int>> rec_result = square_mat_mul_rec(vect_1, vect_2, 0, 0, 0, 0, size);

	print_matrix(rec_result);


}
