#include <iostream>

#include "Graph.h"

using uint = unsigned int;

int main()
{
    size_t n = 50;
    double c = 5;
    long double p = (c * log(n)) / n;
    DirectedGraph g = DirectedGraph::generate(n, p);

    std::cout << g.toAdjMatrixString() << std::endl;

    return 0;
}
