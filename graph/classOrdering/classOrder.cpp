#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <vector>
#include <ctime>
#include <stack>

using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
void removeEdge(int front, unordered_map<int, int> &prereqs, vector<unordered_set<int>> &graph);
void addEdgeless(unordered_map<int, int> &prereqs, queue<int> &noEdges);
vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites);

int main() {
    vector<pair<int,int>> prerequisites = {make_pair(6,27),make_pair(83,9),make_pair(10,95),make_pair(48,67),make_pair(5,71),make_pair(18,72),make_pair(7,10),make_pair(92,4),make_pair(68,84),make_pair(6,41),make_pair(82,41),make_pair(18,54),make_pair(0,2),make_pair(1,2),make_pair(8,65),make_pair(47,85),make_pair(39,51),make_pair(13,78),make_pair(77,50),make_pair(70,56),make_pair(5,61),make_pair(26,56),make_pair(18,19),make_pair(35,49),make_pair(79,53),make_pair(40,22),make_pair(8,19),make_pair(60,56),make_pair(48,50),make_pair(20,70),make_pair(35,12),make_pair(99,85),make_pair(12,75),make_pair(2,36),make_pair(36,22),make_pair(21,15),make_pair(98,1),make_pair(34,94),make_pair(25,41),make_pair(65,17),make_pair(1,56),make_pair(43,96),make_pair(74,57),make_pair(19,62),make_pair(62,78),make_pair(50,86),make_pair(46,22),make_pair(10,13),make_pair(47,18),make_pair(20,66),make_pair(83,66),make_pair(51,47),make_pair(23,66),make_pair(87,42),make_pair(25,81),make_pair(60,81),make_pair(25,93),make_pair(35,89),make_pair(65,92),make_pair(87,39),make_pair(12,43),make_pair(75,73),make_pair(28,96),make_pair(47,55),make_pair(18,11),make_pair(29,58),make_pair(78,61),make_pair(62,75),make_pair(60,77),make_pair(13,46),make_pair(97,92),make_pair(4,64),make_pair(91,47),make_pair(58,66),make_pair(72,74),make_pair(28,17),make_pair(29,98),make_pair(53,66),make_pair(37,5),make_pair(38,12),make_pair(44,98),make_pair(24,31),make_pair(68,23),make_pair(86,52),make_pair(79,49),make_pair(32,25),make_pair(90,18),make_pair(16,57),make_pair(60,74),make_pair(81,73),make_pair(26,10),make_pair(54,26),make_pair(57,58),make_pair(46,47),make_pair(66,54),make_pair(52,25),make_pair(62,91),make_pair(6,72),make_pair(81,72),make_pair(50,35),make_pair(59,87),make_pair(21,3),make_pair(4,92),make_pair(70,12),make_pair(48,4),make_pair(9,23),make_pair(52,55),make_pair(43,59),make_pair(49,26),make_pair(25,90),make_pair(52,0),make_pair(55,8),make_pair(7,23),make_pair(97,41),make_pair(0,40),make_pair(69,47),make_pair(73,68),make_pair(10,6),make_pair(47,9),make_pair(64,24),make_pair(95,93),make_pair(79,66),make_pair(77,21),make_pair(80,69),make_pair(85,5),make_pair(24,48),make_pair(74,31),make_pair(80,76),make_pair(81,27),make_pair(71,94),make_pair(47,82),make_pair(3,24),make_pair(66,61),make_pair(52,13),make_pair(18,38),make_pair(1,35),make_pair(32,78),make_pair(7,58),make_pair(26,58),make_pair(64,47),make_pair(60,6),make_pair(62,5),make_pair(5,22),make_pair(60,54),make_pair(49,40),make_pair(11,56),make_pair(19,85),make_pair(65,58),make_pair(88,44),make_pair(86,58)};
    prerequisites.push_back(make_pair(1, 2)); 
    int numCourses = 2;
    int start_s = clock(); 
    cout << canFinish(100, prerequisites) << " is the answer" << endl;
    int stop_s = clock(); 
    cout << "Execution Time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

//Uses Kahn's Algorithm to solve - have a queue that holds onto each of the
//node's that have no incoming edges. 
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
    unordered_map<int, int> prereqs; 

    for(int i = 0; i < numCourses; i++) prereqs[i] = 0;
    for(auto neighbors : graph) {
        for(int neigh : neighbors) {
            prereqs[neigh]++; 
        }
    }
    
    queue<int> noEdges; 
    addEdgeless(prereqs, noEdges); 
    
    while(!noEdges.empty()) {
        int front = noEdges.front(); 
        noEdges.pop(); 
        prereqs.erase(front); 
        removeEdge(front, prereqs, graph);
        addEdgeless(prereqs, noEdges); 
    }
   
    return prereqs.empty(); 
}

vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph; 
}

void removeEdge(int front, unordered_map<int, int> &prereqs, vector<unordered_set<int>> &graph) {
    for(auto i : graph[front]) {
        prereqs[i]--;
    }
}

void addEdgeless(unordered_map<int, int> &prereqs, queue<int> &noEdges) {
    stack<int> toErase; 
    for(auto kv : prereqs) {
        if(!kv.second) {
            noEdges.push(kv.first); 
            toErase.push(kv.first); 
        }
    }
    
    while(!toErase.empty()) {
        prereqs.erase(toErase.top());
        toErase.pop(); 
    }
}
