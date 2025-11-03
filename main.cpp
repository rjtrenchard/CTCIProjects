#include <iostream>

#include "graphs.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char** argv) {

    Graph graph;

    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);
    graph.addVertex(5);

    graph.addEdge(2,3);
    graph.addEdge(3,2);
    graph.addEdge(1,3);
    graph.addEdge(5,3);
    graph.addEdge(2,5);
    graph.addEdge(2,4);

    graph.removeVertex(1);

    graph.printGraph();
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}