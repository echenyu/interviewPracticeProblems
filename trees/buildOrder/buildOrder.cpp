#include <iostream>
#include <unordered_map> 

using namespace std;

// a, b, c, d, e, f
// (d, a), (b, f), (d, b), (a, f), (c, d)

// Create a map of projects to their depencies (vector of other projects)
// 	Iterate over all of the projects, and find one that has no depencies
// 	If no depencies
		// Place into vector & remove from all other project's depencies
		//
//  If there are no projects with no depencies
		//Return error
// Return the vector of build order
struct Dependency {
	string project;
	string dependency; 
};

int main() {

}

// a b c 
// a -> b, b -> a
// a -> b, b -> c, c -> a. 

vector<string> createBuildOrder(vector<string> projects, vector<Dependency> dependencies) {
	vector<string> buildOrder; 
	std::unordered_map<string, vector<string> > dependencyMapping; 
	queue<string> projectQueue; 

	for(int i = 0; i < projects.size(); i++) {
		dependencyMapping[projects[i]] = vector<string>(); 
		projectQueue.push(projects[i]); 
	}

	for(int i = 0; i < dependencies.size(); i++) {
		string project = dependencies[i].project; 
		string dependency = dependencies[i].dependency; 
		dependencyMapping[project].push_back(Dependency); 
	}

	//a b c 
	//All projects depend on other projects in the queue
	//
	while(!projectQueue.empty()) {
		string currentProject = projectQueue.pop(); 
		if(checkIfNoDepencies()) { 
			removeFromOtherProjects(); 
			buildOrder.push_back(currentProject); 
		} else {
			if(checkCircular()) {
				assert circularError; 
			}
			projectQueue.push(currentProject); 
		}
	}
}

bool checkCircular(string project, unordered_map<string, vector<string> > dependencyMapping) {
	vector<string> dependencies = dependencyMapping[project]; 
	for(int i = 0; i < dependencies.size(); i++) {

	}
}