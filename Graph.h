#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <array>

using uint = unsigned int;

class Graph
{
public:
	virtual ~Graph();

	virtual size_t addVertex() = 0;									// must return vertex id in data structure
	virtual void addEdge(size_t vert1, size_t vert2) = 0;           // edge builds out of vertex id's
	virtual void deleteEdge(size_t vert1, size_t vert2) = 0;
	virtual void deleteNode(size_t vert) = 0;

	virtual std::string toAdjListsString() = 0;
	virtual std::string toAdjMatrixString() = 0;
};

class UndirectedGraph : public Graph
{
private:
	size_t vertexCount;
	std::map < size_t, std::list <size_t> > vertices;
public:
	UndirectedGraph();
	UndirectedGraph(size_t verts);

	// Inherited via Graph
	size_t addVertex() override;
	void addEdge(size_t vert1, size_t vert2) override;
	void deleteEdge(size_t vert1, size_t vert2) override;
	void deleteNode(size_t vert) override;

	// Inherited via Graph
	std::string toAdjListsString() override;
	std::string toAdjMatrixString() override;
};

class DirectedGraph : public Graph
{
private:
	size_t vertexCount;
	std::map < size_t, std::list <size_t> > vertices;
public:
	DirectedGraph();
	DirectedGraph(size_t verts);

	// Inherited via Graph
	size_t addVertex() override;
	void addEdge(size_t vert1, size_t vert2) override;
	void deleteEdge(size_t vert1, size_t vert2) override;
	void deleteNode(size_t vert) override;

	// Inherited via Graph
	std::string toAdjListsString() override;
	std::string toAdjMatrixString() override;
};

#endif
