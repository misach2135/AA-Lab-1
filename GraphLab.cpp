#include <iostream>
#include "Graph.h"

using uint = unsigned int;

int main()
{
    DirectedGraph g;

    uint node1 = g.addNode("Abc");
    uint node2 = g.addNode("def");
    uint node3 = g.addNode("ghk");
    uint node4 = g.addNode("lmn");
    uint node5 = g.addNode("opq");

    g.addEdge(node1, node3);
    g.addEdge(node1, node5);
    g.addEdge(node2, node5);
    g.addEdge(node3, node2);
    g.addEdge(node4, node3);
    g.addEdge(node5, node2);
    g.addEdge(node5, node3);

    std::list<unsigned int> arr = g.bfs(node2);

    for (auto el : arr)
    {
        std::cout << el << "->";
    }

    std::cout << std::endl;

    return 0;
}
