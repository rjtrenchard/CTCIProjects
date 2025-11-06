//
// Created by RJ on 11/3/2025.
//

#include "graphs.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>




bool Graph::addVertex(int vertex)
{
    if (hasVertex(vertex)) return false;
    m_graph[vertex] = {};
    return true;
}

bool Graph::addEdge(const int src, const int dest)
{
    if (!hasVertex(src) || !hasVertex(dest)) return false;
    m_graph[src].push_back(dest);
    return true;
}

bool Graph::removeVertex(int vertex)
{
    if (!hasVertex(vertex)) return false;

    // remove vertex
    auto it = m_graph.find(vertex);
    m_graph.erase(it);

    // then remove any edge pointing to it
    for (const auto element : m_graph) {
        removeEdge(element.first, vertex);
    }

    return true;
}

bool Graph::removeEdge(int src, int dest)
{
    bool hasEdge = false;
    for (auto it = m_graph[src].begin(); it != m_graph[src].end();) {
        if (*it == dest) {
            m_graph[src].erase(it);
            hasEdge = true;
        }
        ++it;
    }
    return hasEdge;
}

bool Graph::hasVertex(int const vertex) const {
    return m_graph.contains(vertex);
}

void Graph::printGraph() {
    for (const auto&[fst, snd] : m_graph) {
        std::cout << fst << " : ";
        for (const auto list : snd) {
            std::cout << list << ", ";
        }
        std::cout << std::endl;
    }
}

std::vector<int> Graph::bfs(int src, int dest) {

    // no vertex
    if (!hasVertex(src) || !hasVertex(dest)) return {};

    std::set<int> visited {};
    std::queue<int> nodes {};
    nodes.push(src);

    while (!nodes.empty()) {
        // grab next node to check
        auto next = nodes.front();



        // add all next children to queue
        // for (const auto& )
        nodes.pop();
    }

    return {};
}


std::vector<int> Graph::m_dfs(int root, int dest, std::map<int, bool>& visited) {

    // check if we've been here before
    if (visited[root]) return {};
    visited[root] = true;

    // create the base to concatenate, return it if we are at the destination
    std::vector<int> base = {root};
    if (root == dest) return base;

    // search all of this roots children. concat
    for (const auto& children : m_graph[root]) {
        auto search = m_dfs(children, dest, visited);
        if (!search.empty()) {
            base.insert(base.end(), search.begin(), search.end());
            return base;
        }
    }

    return {};
}

std::vector<int> Graph::dfs(int src, int dest) {
    // 1 path
    if (src == dest) return {src};

    // impossible path
    if (m_graph.empty()) return {};
    if (!hasVertex(src) || !hasVertex(dest)) return {};

    std::map<int, bool> visited = {};
    return m_dfs(src, dest, visited);
}





