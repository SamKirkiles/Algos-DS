#include <opencv2/opencv.hpp>
#include "rbt.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// use the pointer converted to a string as the name of the node
string unique_node_name(RBTNode *t){

	ostringstream get_the_address; 
	get_the_address << (long int) t;
    	string node_name =  get_the_address.str(); 

	return node_name;
}

string create_nodes(RBTNode * t){

	string result = "";

	if (t != NULL){

		string color_string;

		if ((*t).c == RED){
			color_string = "red";
		}else{
			color_string = "black";
		}

		string node_name = unique_node_name(t);
		result += node_name + " " + "[fillcolor =" + color_string + ", label=" + to_string((*t).value) + "]\n";
	
	
		if ((*t).left != NULL){
			result += create_nodes((*t).left);;
		}
	
		if ((*t).right != NULL){
			result += create_nodes((*t).right);;
		}

	}	
	return result;
}

string create_transitions(RBTNode * t){

	string result = "";

	if (t != NULL){
		string node_name = unique_node_name(t);
	
		if ((*t).left != NULL){
			string left_node_name = unique_node_name((*t).left);
			result += node_name + "->" + left_node_name + "\n";;
			result += create_transitions((*t).left);
		}
	
		if ((*t).right != NULL){
			string right_node_name = unique_node_name((*t).right);
			result += node_name + "->" + right_node_name + "\n";;
			result += create_transitions((*t).right);
		}
	}	
	return result;
}

void plot_graph(RBTNode* t){

        string header = "digraph G {"
        "graph [ratio=.48];"
        "node [style=filled, color=black, shape=circle, width=.6"
        "       fontname=Helvetica, fontweight=bold, fontcolor=white, "
        "       fontsize=24, fixedsize=true];";

	string nodes = create_nodes(t);
	string transitions = create_transitions(t);

        string footer = "}";

        string command = "echo \"" + header + nodes + transitions + footer + "\" | dot -Tpng -o output.png";

        const char* command_const = command.c_str();

        system(command_const);

        cv::Mat img = cv::imread("output.png");
        cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
        cv::imshow("image", img);
	cv::waitKey();

        system("rm output.png");
}

