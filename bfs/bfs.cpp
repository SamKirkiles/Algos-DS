#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;

struct edge{
	int start;
	int dest;
};


class Graph	{

	int num_verts;	

	list<int> * adjacency;

	public:
		Graph(int v, vector<edge> edges){

			num_verts=v;
			adjacency = new list<int> [v];	
			// add edges to adjacency list 
			for (edge e:edges) {
				add_edge(e);
			}	
		}
	
		void add_edge(edge e){
			adjacency[e.start].push_back(e.dest);
		}

		void bfs(){
			// Add everything to a queue 
			// For each item on the queue, add if we havent seen it before
			int root = 0;

			queue<int> visit;
			visit.push(root);
			
			unordered_set<int> visited;
				
			while(!visit.empty()){

				int current = visit.front();
				
				// push the adjacency list onto the queue 
				for(int adj : adjacency[current]){

					// if we havent seen this vertex yet
					unordered_set<int>::const_iterator found = visited.find(adj);
					if (found == visited.end()) {
						visit.push(adj);	
					}
				}
	
				visit.pop();
				visited.emplace(current);

				cout << "Visited: " << current << "\n";
			}
			
		}
};


int main(){
		
	vector<edge> edges {edge {0, 1}, edge {1, 7}, edge {7,2}, edge {2,5}, edge {5,6}, edge {2,3}, edge {3,4}, edge {4,8}, edge {8,0}};
	
	Graph g (9, edges);

	g.bfs();
	
	return 0;
}
