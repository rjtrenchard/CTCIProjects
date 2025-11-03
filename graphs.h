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
    bool addEdge(const int src, const int dest);
    bool removeVertex(int vertex);
    bool removeEdge(int src, int dest);
    bool hasVertex(int const vertex) const;
    void printGraph();
private:
    std::map<int, std::vector<int>> m_graph;
    void m_removeElement(int src, int dest);
};

#endif //CTCIPROJECTS_GRAPHS_H