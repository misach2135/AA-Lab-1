#include <iostream>

#include "Graph.h"

using uint = unsigned int;

int main()
{
    size_t n = 10;
    double c = 1;
    long double p = (c * log(n)) / n;
    ListsGraph g = generateGraph<ListsGraph>(n, p);

    std::cout << g.toAdjListsString() << std::endl;
    std::cout << g.toAdjMatrixString() << std::endl;

    g.deleteNode(8);

    std::cout << "After deleting node 8: " << std::endl;
    std::cout << g.toAdjListsString() << std::endl;
    std::cout << g.toAdjMatrixString() << std::endl;

    g.deleteNode(6);

    std::cout << "After deleting node 6: " << std::endl;
    std::cout << g.toAdjListsString() << std::endl;
    std::cout << g.toAdjMatrixString() << std::endl;

    return 0;
}
