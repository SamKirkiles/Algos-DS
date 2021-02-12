#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Point {
	int x;
	int y; 
};

void printPoint(Point p){
	cout << p.x << " " << p.y<< "\n";
}

void printVector(std::vector<Point> points){
	for (int i=0;i<points.size(); i++){
		printPoint(points[i]);
		cout << ",  ";
	} 	
	cout << '\n';	
}

float distance(Point p1, Point p2){
	return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}


bool x_comp(Point p1, Point p2){return p1.x < p2.x;}
bool y_comp(Point p1, Point p2){return p1.y < p2.y;}

float clasest_rec(vector<Point> Px, vector<Point> Py){

	// This should never happen	
	if (points.size() == 0|| points.size() == 1){
		return 0;
	}	

	if (points.size() == 2){
		return distance(points[0], points[1]);	
	
	int midceil = ceil((float)Px.size()/(float)2);
	int midfloor = floor((float)(Px.size())/(float)2);

	vector<Point> Qx (Px.begin(), Px.begin() + midceil);
	
	int L = Qx[Qx.size()-1].x;


	// Construct Qy
	vector<Point> Qy;
	
	int  i = 0;	
	int  j = 0;
	while (i < Py.size() && j<midfloor){
		if (Py[i].x <= L){
			Qy.push_back(Py[i]);
			j++;
		}
		i++;
	}
	
	vector<Point> Rx (Px.begin() + midfloor, Px.end());

	//Construct Ry
	vector<Point> Ry;
	
	int  i = 0;	
	int  j = 0;
	while (i < Py.size() && j < Rx.size()){
		if (Py[i].x > L){
			Qy.push_back(Py[Py.size()-1-i]);
			j++;
		}
		i++;
	}
	
	float r_1 = closest(Qx, Qy);
	float r_2 = closest(Rx, Ry);

	float delta = min(r_1, r_2);
}

// given a list of points, print the distance of the closest two points
float closest(vector<Point> points){
	
}		
	
	vector<Point> Px (points);
	vector<Point> Py (points);

	// Sort the points by x and y
	sort(Px.begin(), Px.end(), x_comp);
	sort(Py.begin(), Py.end(), x_comp);
	
	return closest_rec(Px, Py);
	

	// Now we know what our delta is
	// Get a subset of Py which is inside the delta region.

	
	// This array is sorted by y values. 	
	vector<Point> insideDelta;
	
	std::for_each(Py.begin(), Py.end(), [&](Point p) {
		if (abs(L-p.x) <= delta || abs(p.x-L)<=delta) {
			insideDelta.push_back(p);		
		} 
	});

	for (int i =0; i < insideDelta.size(); i++){
		int j = i+1; 
		while (i+j<insideDelta.size()-1 && j<15){
			float delta_prime = distance(insideDelta[i], insideDelta[i+j]);
			if (delta_prime<delta){
				delta = delta_prime;
			}
			j++;	
		}
	}
	
	
	return delta;	
}

int main(){

	vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}, {9, 44}}; 
	//vector<Point> points = {{2,3}, {12,30}};

	cout << "The closest distance was: " << closest(points) << '\n';
	
	return 0;
}
