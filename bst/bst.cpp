#include <iostream>
#include <vector>

using namespace std;

class BSTNode {

	public:
		int data;
		BSTNode *left;
		BSTNode *right;

		BSTNode (int root) {
			data = root;
			left = NULL;
			right = NULL;
		}

	

		void insert(int item) {
			
			if (item >= data) {

				if (right == NULL){
					right = new BSTNode(item);
				}else{
					(*right).insert(item);
				}

			} else { 

				if (left == NULL){
					left = new BSTNode(item);
				}else{
					(*left).insert(item);
				}

			}
		}
		
		vector<int> walkInOrder(){

			vector<int> output;

			if (left !=  NULL) {
				vector<int> l = (*left).walkInOrder();	
				output.insert(output.end(), l.begin(), l.end());
			}
	
			output.push_back(data);

			if (right !=  NULL) {
				vector<int> r = (*right).walkInOrder();	
				output.insert(output.end(), r.begin(), r.end());
			}
			
			return output;
	
		}
};

int main(){	
	BSTNode bst (2);
	bst.insert(1);
	bst.insert(3);
	bst.insert(2);
	bst.insert(5);

	vector<int> out = bst.walkInOrder();
	
	cout << "hello world";
}
