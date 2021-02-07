#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct Point {
	int x;
	int y; 
};

void printPoint(Point p){
	std::cout << p.x << " " << p.y<< "\n";
}

void printVector(std::vector<Point> points){
	for (int i=0;i<points.size(); i++){
		printPoint(points[i]);
		std::cout << ",  ";
	} 	
	std::cout << '\n';	
}

float distance(Point p1, Point p2){
	return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}


bool x_comp(Point p1, Point p2){return p1.x < p2.x;}
bool y_comp(Point p1, Point p2){return p1.y < p2.y;}

// given a list of points, print the distance of the closest two points
float closest(std::vector<Point> points){
	
	std::vector<Point> Px (points);
	std::vector<Point> Py (points);

	std::sort(Px.begin(), Px.end(), x_comp);
	
	std::cout << " ";

	return  0;
}

int main(){

	std::vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
		
	std::string bob = "12345";	

	std::cout << "The closest distance was: " << closest(points) << '\n';
	
	return 0;
}
