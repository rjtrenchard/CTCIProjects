//
// Created by RJ on 11/3/2025.
//

#ifndef CTCIPROJECTS_GRAPHS_H
#define CTCIPROJECTS_GRAPHS_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Graph
{
public:
    bool addVertex(int vertex);
    bool addEdge(int src, int dest);
    bool removeVertex(int vertex);
    bool removeEdge(int src, int dest);
    [[nodiscard]] bool hasVertex(int vertex) const;
    void printGraph();
    std::vector<int> dfs(int src, int dest);
    std::vector<int> bfs(int src, int dest);
private:
    std::map<int, std::vector<int>> m_graph;
    std::vector<int> m_dfs(int root, int dest, std::map<int, bool>& visited);
};

#endif //CTCIPROJECTS_GRAPHS_H