#include <iostream>

#include "Graph.h"

using uint = unsigned int;

int main()
{
    UndirectedGraph g;

    uint node1 = g.addVertex();
    uint node2 = g.addVertex();
    uint node3 = g.addVertex();
    uint node4 = g.addVertex();
    uint node5 = g.addVertex();

    g.addEdge(node1, node2);


    std::cout << g.toAdjListsString() << std::endl;
    std::cout << g.toAdjMatrixString() << std::endl;

    g.deleteNode(node1);

    std::cout << "\n\n";

    std::cout << g.toAdjListsString() << std::endl;
    std::cout << g.toAdjMatrixString() << std::endl;

    g.deleteEdge(node2, node5);

    std::cout << "\n\n";

    std::cout << g.toAdjListsString() << std::endl;
    std::cout << g.toAdjMatrixString() << std::endl;

    return 0;
}
