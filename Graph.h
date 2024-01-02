#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <type_traits>
#include <random>
#include <array>

using uint = unsigned int;

class IGraphOperations
{
public:
	virtual ~IGraphOperations();

	virtual size_t addVertex() = 0;									// must return vertex id in data structure
	virtual void addEdge(size_t vert1, size_t vert2) = 0;           // edge builds out of vertex id's
	virtual void deleteEdge(size_t vert1, size_t vert2) = 0;
	virtual void deleteNode(size_t vert) = 0;
	virtual std::vector<size_t> dfs(size_t vert) = 0;
};

class IGraphRepresentation
{
public:
	virtual std::string toAdjListsString() = 0;
	virtual std::string toAdjMatrixString() = 0;
};

class AdjencyListsGraphRepresentation : public IGraphRepresentation
{
protected:
	struct Vertex {
		bool selected = false;
		std::list<size_t> neighbors;
		Vertex();
	};

	std::vector <Vertex> vertices;
public:
	AdjencyListsGraphRepresentation();
	AdjencyListsGraphRepresentation(const std::vector <std::vector<size_t> >& matrix);

	// Inherited via GraphRepresentation
	std::string toAdjListsString() override;
	std::string toAdjMatrixString() override;
};

class AdjencyMatrixGraphRepresentation : public IGraphRepresentation
{
protected:
	std::vector <std::vector<bool>> matrix;
public:
	AdjencyMatrixGraphRepresentation();
	AdjencyMatrixGraphRepresentation(const std::vector<std::list <size_t> >& lists);

	// Inherited via GraphRepresentation
	std::string toAdjListsString() override;
	std::string toAdjMatrixString() override;
};

class GeneralAdjencyListsGraph : public IGraphOperations, public AdjencyListsGraphRepresentation
{
protected:
	GeneralAdjencyListsGraph();
	GeneralAdjencyListsGraph(size_t n);
public:
	size_t addVertex() override;
	std::vector<size_t> dfs(size_t vert) override;
	void deleteNode(size_t vert) override;
};


class ListsGraph : public GeneralAdjencyListsGraph
{
public:
	ListsGraph();
	ListsGraph(size_t verts);

	void addEdge(size_t vert1, size_t vert2) override;
	void deleteEdge(size_t vert1, size_t vert2) override;

	// Inherited via IGraphOperations

};

class DListsGraph : public GeneralAdjencyListsGraph
{
private:
	void dfsRecursive(size_t vert);
	void transpose();
public:
	DListsGraph();
	DListsGraph(size_t verts);

	void addEdge(size_t vert1, size_t vert2) override;
	void deleteEdge(size_t vert1, size_t vert2) override;

	std::vector<std::vector<size_t>> getStronglyConnectedComponents();
};

class GeneralMatrixGraph : public IGraphOperations, public AdjencyMatrixGraphRepresentation
{
protected:
	GeneralMatrixGraph();
	GeneralMatrixGraph(size_t n);
public:
	size_t addVertex() override;
	void deleteNode(size_t vert) override;
};

class MatrixGraph : public GeneralMatrixGraph
{
public:
	MatrixGraph();
	MatrixGraph(size_t n);

	// Inherited via IGraphOperations
	void addEdge(size_t vert1, size_t vert2) override;
	void deleteEdge(size_t vert1, size_t vert2) override;
	
};

class DMatrixGraph : public GeneralMatrixGraph
{
public:
	DMatrixGraph();
	DMatrixGraph(size_t n);
	// Inherited via IGraphOperations
	void addEdge(size_t vert1, size_t vert2) override;
	void deleteEdge(size_t vert1, size_t vert2) override;
};

template<typename T>
T generateGraph(size_t n, long double p)
{
	static_assert(std::is_base_of<IGraphOperations, T>::value);

	T g(n);
	if (p <= 0)
	{
		return T(n);
	}
	if (p >= 1)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (i == j) continue;
				g.addEdge(i, j);
			}
		}
		return g;
	}

	std::random_device dev;
	std::mt19937 rng(dev());
	std::bernoulli_distribution distribution(p);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i == j) continue;

			if (distribution(rng))
			{
				g.addEdge(i, j);
			}
		}
	}

	return g;
}

#endif