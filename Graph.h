#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <array>

class MatrixView
{
	// TODO: Adjency matrix view
};

class Graph
{
protected:
	Graph() = default;

	struct Node
	{
		const char* data;
		std::list<unsigned int> vertices;
	};

	std::vector<Node> adjList;
public:
	virtual ~Graph();
	
	virtual int addNode(const char* data) = 0;
	virtual void addEdge(unsigned int nodeA, unsigned int nodeB) = 0;
	virtual const Node* const find(unsigned int node) = 0;
	virtual void removeNode(unsigned int node) = 0;
	virtual void removeEdge(unsigned int nodeA, unsigned int nodeB) = 0;

	std::list<unsigned int> bfs(unsigned int s);

	// TODO: BFS, DFS
};

class DirectedGraph : public Graph
{
public:
	DirectedGraph();
	int addNode(const char* data) override;
	void addEdge(unsigned int nodeA, unsigned int nodeB) override;
	const Node* const find(unsigned int nod) override;
	void removeNode(unsigned int node) override;
	void removeEdge(unsigned int nodeA, unsigned int nodeB) override;
};

class UndirectedGraph : public Graph
{
	UndirectedGraph() = default;
	int addNode(const char* data) override;
	void addEdge(unsigned int nodeA, unsigned int nodeB) override;
	const Node* const find(unsigned int nod) override;
	void removeNode(unsigned int node) override;
	void removeEdge(unsigned int intA, unsigned int intB) override;
};

#endif
