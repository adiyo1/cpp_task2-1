// 318725520
// adi.yohanann@gmail.com


#include <iostream>
#include "Graph.hpp"
#include <stack>

namespace ariel {
    class Algorithms {
        public:

            Algorithms();
            static bool isConnected(Graph g);
            static string shortestPath(Graph g, int x, int y);
            static bool isContainsCycle(Graph g);
            static string isBipartite(Graph g);
            static bool bfs(Graph graph, size_t start);
            static bool negetiveEdge(Graph graph);
            static bool negativeCycle(Graph graph);
            static bool  dfs(Graph graph, size_t node, vector<bool> visited, vector<bool>& inStack, stack<size_t>& cycle_path);
    };  
}