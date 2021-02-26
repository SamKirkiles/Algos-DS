#include <iostream>
#include <vector>
#include <algorithm>

struct line{
	int m;
	int b;
};

void print_line(line l){
	cout << "y="<<l.m<<"x+"<<l.b<<"\n";
}

void print_lines(vector<line> lines){
	for (line l :lines){
		print_line(l);
	}
}

// Merge two lists of solved lines 
vector<line> merge(vector<line> lh, vector<line> rh){
	
	vector<line> merged;	
	
	int lh_size = lh.size();
	int rh_size = rh.size();

	int  i=0; int j=0;

	while (i<lh_size && j< rh_size){
		//  use the one with the smaller slope
		if (lh.at(i).m<=rh.at(j).m){
			merged.push_back(lh.at(i));	
			i++;				
		}else { // use the one with the bigger slope
			merged.push_back(rh.at(j));
			j++;
		} 
		
	}	

	if (i < lh_size){
		while(i < lh_size){
			merged.push_back(lh.at(i));    
			i++;
		}
	}

	if (j< rh_size){
		while (j<rh_size){
			merged.push_back(rh.at(j));	
			j++;
		}
	}			
	
	
	// The highest slope line will always be visible.
	// The lowest slope line will always be visible
	// When we add a new line, how many others will  it take out?
	// start from base  if the intersection x doesnt increase, remove the line.  

	vector<lines> visible_lines;
		
	line first = visible_lines.push_back(lines.at(0));
	line second = visible_lines.push_back(lines.at(1));
	
	// clear from lines
	visible_lines.remove(0);
	visible_lines.remove(0);

	for (line l:lines){
		// Add to visible_lines
		visible_lines.push_back(l);
			
		int i =0;	
		

		while (i < visible_lines.size()-1){
			line l_1 = visible_lines.at(i);
			line l_2 = visible_lines.at(i+1);

			float first_intersection = intersection(l_1, l);
			float second_intersection = intersection(l_2, l);										
			
			// if the first intersection is less than the second, then we add l. 
			if (first_intersection > second_intersection){
				
			} else{
			
			}
	
		}		
		
	}
	
	return  visible_lines;
}


vector<line> hidden_surface(vector<line> lines){ 

	// There are no lines (trivial)
	if (lines.size() == 0){
		return output;
	}
	
	// If there is only one line return it
	if (lines.size() == 1){
		line l_1 = lines.at(0);
		output.push_back(l_1);
		return output;
	}

	// if there are two lines return both unless they have the same slope
	if (lines.size() == 2){
		line l_1  = lines.at(0);
		line l_2 = lines.at(1);
		
		// If they have the same slope return the one with the larger b
		if (l_1.m==l_2.m){
			if (l_1.b>l_2.b) {output.push_back(l_1); return output;}
			else {output.push_back(l_2); return output;}
		}

		output.push_back(l_1);
		output.push_back(l_2);
		return output;
	}
	
	int mid = lines.size()/2;
	
	vector<line> left_half (lines.begin(), lines.begin()+mid);
	vector<line> right_half (lines.begin()+mid, lines.end());

	vector<line> lh = hidden_surface(left_half);
	vector<line> rh = hidden_surface(right_half);
	
	vector<line> result = merge(lh, rh);

	// Sort lines
	return result;
}

float intersection(line l_1, line l_2){
	return (l_1.m-l_2.m)/(l_1.b-l_2.b);
}

bool compare_slope(line l_1, line l_2){
	return l_1.m<l_2.m;
}

int main(){
	
	line l_1 = {2, 3};
	line l_2 = {4, 2};
	line l_3 = {-3, -2};
	line l_4 = {3, 1};
	line l_5 = {1, 1};

	
	vector<line> lines {l_1, l_2, l_3, l_4, l_5};
	
	cout << "before sorted\n";
	print_lines(lines);	

	// Sort lines
	sort(lines.begin(), lines.end(), compare_slope);

	cout << "after sorted\n";
	print_lines(lines);
	
	vector<line> visible = hidden_surface(lines);
	
	cout << "result\n";
	print_lines(visible);
	return 0;

}
