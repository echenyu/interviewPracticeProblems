#include <vector>
#include <iostream>
#include <unordered_map> 
#include <unordered_set> 
#include <stack>

using namespace std; 
/*Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa" 
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input:  words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b' */

class Graph {
public:
	Graph() {}
	unordered_map<char, unordered_set<char> > graph; 
};

void addEdgeAndNode(Graph &graph, string first, string second) {
	int shorter = (first.size() > second.size()) ? second.size() : first.size(); 
	for(int i = 0; i < shorter; i++) {
		if(first[i] != second[i]) {
			if(graph.graph.find(first[i]) == graph.graph.end()) {
				graph.graph[first[i]] = unordered_set<char>(); 
			}
			graph.graph[first[i]].insert(second[i]); 
			return; 
		}
	}
}

Graph createGraph(vector<string> &sortedWords) {
	Graph graph; 

	for(int i = 0; i < sortedWords.size()-1; i++) {
		for(int j = i+1; j < sortedWords.size(); j++) {
			string first = sortedWords[i];
			string second = sortedWords[j]; 
			addEdgeAndNode(graph, first, second); 
		}
	}

	for(auto kv : graph.graph) {
		cout << kv.first << " has "; 
		for(auto j : kv.second) {
			cout << j << ",";
		}
		cout << endl;
	}
	return graph; 
}

void printTopologicalSort(char curr, Graph graph, unordered_set<char> &visited, stack<char>&topologicalStack) {
	visited.insert(curr); 

	for(auto i : graph.graph[curr]) {
		if(visited.find(i) == visited.end())
			printTopologicalSort(i, graph, visited, topologicalStack); 
	}
	topologicalStack.push(curr); 
}


void printOrder(vector<string> sortedWords) {
	Graph graph = createGraph(sortedWords); 
	unordered_set<char> visited;
	stack<char> topologicalStack;

	for(auto kv : graph.graph) {
		if(visited.find(kv.first) == visited.end())
			printTopologicalSort(kv.first, graph, visited, topologicalStack); 
	}
	
	while(!topologicalStack.empty()) {
		cout << topologicalStack.top() << " ";
		topologicalStack.pop(); 
	}
	cout << endl;
}

int main() {
	vector<string> sortedWords;
	sortedWords.push_back("caa");
	sortedWords.push_back("a*");
	sortedWords.push_back("ad");
	sortedWords.push_back("ca"); 

	printOrder(sortedWords); 
}