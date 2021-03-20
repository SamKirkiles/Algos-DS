#include "rbt.h"
#include "viz.h"
#include <iostream>

using namespace std;
int main(){

        RBTNode tree = {26, NULL, NULL, NULL, BLACK}; 
        insert_node(&tree, 27);
        insert_node(&tree, 22);
	insert_node(&tree, 28);
	insert_node(&tree, 27);
	insert_node(&tree, 25);
	insert_node(&tree, 26);
	insert_node(&tree, 23);
	insert_node(&tree, 1);
	insert_node(&tree, 5);
	insert_node(&tree, 75);
	//insert_node(&tree, 73);
	//insert_node(&tree, 70);
	//insert_node(&tree, 44);	
	insert_node(&tree, 80);
	
	//before	
        plot_graph(&tree);
	
	//after
	//leftRotate(&tree, (*(*tree.right).right).right);
	leftRotate(&tree, tree.left);
	plot_graph(&tree);
        cout << "Hello World";

        return 0;
}
