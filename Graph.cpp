#include "Graph.h"

IGraphOperations::~IGraphOperations()
{
}

ListsGraph::ListsGraph()
{

}

ListsGraph::ListsGraph(size_t verts) : GeneralAdjencyListsGraph(verts)
{
}

GeneralAdjencyListsGraph::GeneralAdjencyListsGraph()
{
	vertices.clear();
}

GeneralAdjencyListsGraph::GeneralAdjencyListsGraph(size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		addVertex();
	}
}

size_t GeneralAdjencyListsGraph::addVertex()
{
		vertices.push_back(Vertex());
		return vertices.size() - 1;
}

void ListsGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= vertices.size()) return;
	if (vert2 >= vertices.size()) return;

	if (std::find(vertices[vert1].neighbors.begin(), vertices[vert1].neighbors.end(), vert1) == vertices[vert1].neighbors.end()) 
		vertices[vert1].neighbors.push_back(vert2);
	if (std::find(vertices[vert2].neighbors.begin(), vertices[vert2].neighbors.end(), vert1) == vertices[vert2].neighbors.end()) 
		vertices[vert2].neighbors.push_back(vert1);
}

void ListsGraph::deleteEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= vertices.size()) return;
	if (vert2 >= vertices.size()) return;

	for (auto i = vertices[vert1].neighbors.begin(); i != vertices[vert1].neighbors.end(); i++)
	{
		if (*i == vert2)
		{
			vertices[vert1].neighbors.erase(i);
			break;
		}
	}

	for (auto i = vertices[vert2].neighbors.begin(); i != vertices[vert2].neighbors.end(); i++)
	{
		if (*i == vert1)
		{
			vertices[vert2].neighbors.erase(i);
			break;
		}
	}
}

void DListsGraph::dfsRecursive(size_t vert)
{
	vertices[vert].selected = true;

	for (auto neighbor : vertices[vert].neighbors)
	{
		if (!vertices[neighbor].selected)
		{
			dfsRecursive(neighbor);
		}
	}
}

void DListsGraph::transpose()
{
	std::vector<Vertex> transposedVertices(vertices.size());

	for (size_t i = 0; i < vertices.size(); ++i)
	{
		for (auto neighbor : vertices[i].neighbors)
		{
			transposedVertices[neighbor].neighbors.push_back(i);
		}
	}

	vertices = transposedVertices;
}

DListsGraph::DListsGraph() : GeneralAdjencyListsGraph()
{
}

DListsGraph::DListsGraph(size_t verts) : GeneralAdjencyListsGraph(verts)
{
}

void DListsGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= vertices.size()) return;
	if (vert2 >= vertices.size()) return;

	if (std::find(vertices[vert1].neighbors.begin(), vertices[vert1].neighbors.end(), vert1) == vertices[vert1].neighbors.end())
		vertices[vert1].neighbors.push_back(vert2);
}

void DListsGraph::deleteEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= vertices.size()) return;
	if (vert2 >= vertices.size()) return;

	for (auto i = vertices[vert1].neighbors.begin(); i != vertices[vert1].neighbors.end(); i++)
	{
		if (*i == vert2)
		{
			vertices[vert1].neighbors.erase(i);
			break;
		}
	}

}

std::vector<std::vector<size_t>> DListsGraph::getStronglyConnectedComponents()
{
	std::vector<std::vector<size_t> > res;
	return res;

}

void GeneralAdjencyListsGraph::deleteNode(size_t vert)
{
	if (vert >= vertices.size()) return;

	vertices.erase(vertices.begin() + vert);

	// ¬идал€ю кожну згадку в списках сум≥жност≥ про вузол vert
	for (size_t i = 0; i < vertices.size(); i++)
	{
		vertices[i].neighbors.remove(vert);

		for (auto& v : vertices[i].neighbors)
		{
			if (v >= vert)
			{
				v--;
			}
		}
	}

}

std::vector<size_t> GeneralAdjencyListsGraph::dfs(size_t vert)
{
	if (vert >= vertices.size()) return std::vector<size_t>();

	for (auto& v : vertices) v.selected = false;

	std::vector<size_t> res;
	std::stack<size_t> visited;
	vertices[vert].selected = true;
	visited.push(vert);
	while (!visited.empty())
	{
		size_t v = visited.top();
		visited.pop();
		res.push_back(v);
		for (auto& neighbor : vertices[v].neighbors)
		{
			if (!vertices[neighbor].selected)
			{
				visited.push(neighbor);
				vertices[neighbor].selected = true;
			}
		}
	}
	return res;
}

AdjencyListsGraphRepresentation::AdjencyListsGraphRepresentation()
{
	vertices = std::vector<Vertex>();
}

AdjencyListsGraphRepresentation::AdjencyListsGraphRepresentation(const std::vector<std::vector<size_t>>& matrix)
{
	// TODO
}

std::string AdjencyListsGraphRepresentation::toAdjListsString()
{
	std::string res;
	for (size_t i = 0; i < vertices.size(); i++)
	{
		res.append(std::to_string(i)+ "-> ");
		for (const auto& n : vertices[i].neighbors)
		{
			res.append(std::to_string(n) + " ");
		}
		res.append("\n");
	}
	return res;
}

std::string AdjencyListsGraphRepresentation::toAdjMatrixString()
{
	std::string res;
	for (const auto& v : vertices)
	{
		for (size_t i = 0; i < vertices.size(); i++)
		{
			if (std::find(v.neighbors.begin(), v.neighbors.end(), i) != v.neighbors.end())
			{
				res += "1 ";
				continue;
			}
			res += "0 ";
		}
		res += '\n';
	}
	return res;
}

AdjencyListsGraphRepresentation::Vertex::Vertex()
{
	neighbors = std::list<size_t>();
	selected = false;
}

AdjencyMatrixGraphRepresentation::AdjencyMatrixGraphRepresentation()
{
	matrix = std::vector <std::vector<bool>		>(0);
}

AdjencyMatrixGraphRepresentation::AdjencyMatrixGraphRepresentation(const std::vector<std::list<size_t>>& lists)
{
	// TODO
}

MatrixGraph::MatrixGraph() : GeneralMatrixGraph()
{
}

MatrixGraph::MatrixGraph(size_t n) : GeneralMatrixGraph(n)
{
}

std::string AdjencyMatrixGraphRepresentation::toAdjListsString()
{
	return std::string();
}

std::string AdjencyMatrixGraphRepresentation::toAdjMatrixString()
{
	return std::string();
}

void MatrixGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= matrix.size() && vert2 >= matrix.size())  return;

	matrix[vert1][vert2] = 1;
	matrix[vert2][vert1] = 1;
}

void MatrixGraph::deleteEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= matrix.size() && vert2 >= matrix.size())  return;

	matrix[vert1][vert2] = 0;
	matrix[vert2][vert1] = 0;
}


DMatrixGraph::DMatrixGraph() : GeneralMatrixGraph()
{
}

DMatrixGraph::DMatrixGraph(size_t n) : GeneralMatrixGraph(n)
{
}

void DMatrixGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= matrix.size() && vert2 >= matrix.size())  return;

	matrix[vert1][vert2] = 1;
}

void DMatrixGraph::deleteEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= matrix.size() && vert2 >= matrix.size())  return;

	matrix[vert1][vert2] = 0;
}

GeneralMatrixGraph::GeneralMatrixGraph()
{
	matrix = std::vector<std::vector<bool> >();
}

GeneralMatrixGraph::GeneralMatrixGraph(size_t n)
{
	matrix = std::vector<std::vector<bool> >(n, std::vector<bool>(n, false));
}

size_t GeneralMatrixGraph::addVertex()
{
	matrix.push_back(std::vector<bool>());

	for (auto& e : matrix)
	{
		e.push_back(0);
	}

	return matrix.size() - 1;
}

void GeneralMatrixGraph::deleteNode(size_t vert)
{
	if (vert >= matrix.size()) return;

	matrix.erase(matrix.begin() + vert);
	for (auto& row : matrix)
	{
		row.erase(row.begin() + vert);
	}
}