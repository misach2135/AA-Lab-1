#include <iostream>

#include "Graph.h"

using uint = unsigned int;

int main()
{
    size_t n = 10;
    double c = 1;
    long double p = (c * log(n)) / n;
    DListsGraph g = generateGraph<DListsGraph>(n, p);

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

    auto vec = g.dfs(0);

    for (auto& e : vec)
    {
        std::cout << e << ", ";
    }
    std::cout << "\n\n";

    auto vec2 = g.getStronglyConnectedComponents();

    for (size_t i = 0; i < vec2.size(); i++)
    {
        std::cout << std::to_string(i) << ":  ";
        for (auto& j : vec2[i])
        {
            std::cout << std::to_string(j) << ", ";
        }
        std::cout << "\n";
    }

    return 0;
}
