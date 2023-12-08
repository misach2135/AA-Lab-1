#include "Graph.h"

Graph::~Graph()
{
	for (int i = 0; i < adjList.size(); i++)
	{
		// delete adjList[i].data;
		adjList[i].data = nullptr;
	}
}

std::list<unsigned int> Graph::bfs(unsigned int s)
{
	if (s < adjList.size())
	{
		std::queue<unsigned int> q;
		std::list<unsigned int> searchedNodes;
		std::set<unsigned int> visited;
		q.push(s);
		while (!q.empty())
		{
			searchedNodes.push_back(q.front());
			visited.insert(q.front());
			q.pop();
			for (unsigned int node : adjList[searchedNodes.back()].vertices)
			{
				if (visited.find(node) != visited.end())
				{
					continue;
				}
				q.push(node);
			}
		}

		return searchedNodes;
	}
}

DirectedGraph::DirectedGraph()
{
}

int DirectedGraph::addNode(const char* data)
{
	Node newNode = {
		data,
		std::list<unsigned int>()
	};
	adjList.push_back(newNode);
	return adjList.size() - 1;
}

void DirectedGraph::addEdge(unsigned int nodeA, unsigned int nodeB)
{
	if (nodeA < adjList.size() && nodeB < adjList.size())
	{
		adjList[nodeA].vertices.push_back(nodeB);
	}
}

const Graph::Node* const DirectedGraph::find(unsigned int node)
{
	if (node < adjList.size())
	{
		return &adjList[node];
	}
}

void DirectedGraph::removeNode(unsigned int node)
{
	// TODO
}

void DirectedGraph::removeEdge(unsigned int nodeA, unsigned int nodeB)
{
	if (nodeA < adjList.size() && nodeB < adjList.size())
	{
		adjList[nodeA].vertices.remove(nodeB);
	}
}

int UndirectedGraph::addNode(const char* data)
{
	return 0;
}

void UndirectedGraph::addEdge(unsigned int intA, unsigned int intB)
{
}

const Graph::Node* const UndirectedGraph::find(unsigned int node)
{
	return nullptr;
}

void UndirectedGraph::removeNode(unsigned int node)
{
}

void UndirectedGraph::removeEdge (unsigned int intA, unsigned int intB)
{
}
