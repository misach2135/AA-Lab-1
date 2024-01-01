#include "Graph.h"

IGraphOperations::~IGraphOperations()
{
}

ListsGraph::ListsGraph()
{
	vertices.clear();
}

ListsGraph::ListsGraph(size_t verts)
{
	for (size_t i = 0; i < verts; i++)
	{
		addVertex();
	}
}

size_t ListsGraph::addVertex()
{
		vertices.push_back(Vertex());
		return vertices.size() - 1;
}

void ListsGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= vertices.size()) return;
	if (vert2 >= vertices.size()) return;

	vertices[vert1].neighbors.push_back(vert2);
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

void ListsGraph::deleteNode(size_t vert)
{
	if (vert >= vertices.size()) return;

	vertices.erase(vertices.begin() + vert);

		// Remove the deleted vertex from neighbor lists and update indices
	for (auto& v : vertices)
	{
		v.neighbors.remove(vert);

		for (auto& neighbor : v.neighbors)
		{
			if (neighbor > vert)
			{
				neighbor--;
			}
		}
	}
}

DListsGraph::DListsGraph()
{
	vertices.clear();
}

DListsGraph::DListsGraph(size_t verts)
{
	for (size_t i = 0; i < verts; i++)
	{
		addVertex();
	}
}

size_t DListsGraph::addVertex()
{
	vertices.push_back(Vertex());
	return vertices.size() - 1;
}

void DListsGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vert1 >= vertices.size()) return;
	if (vert2 >= vertices.size()) return;

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

void DListsGraph::deleteNode(size_t vert)
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

AdjencyMatrixGraphRepresentation::AdjencyMatrixGraphRepresentation()
{
	matrix = std::vector <std::vector<size_t>>(0);
}

AdjencyMatrixGraphRepresentation::AdjencyMatrixGraphRepresentation(const std::vector<std::list<size_t>>& lists)
{
	// TODO
}

std::string AdjencyMatrixGraphRepresentation::toAdjListsString()
{
	return std::string();
}

std::string AdjencyMatrixGraphRepresentation::toAdjMatrixString()
{
	return std::string();
}

size_t MatrixGraph::addVertex()
{
	return size_t();
}

void MatrixGraph::addEdge(size_t vert1, size_t vert2)
{
}

void MatrixGraph::deleteEdge(size_t vert1, size_t vert2)
{
}

void MatrixGraph::deleteNode(size_t vert)
{
}

size_t DMatrixGraph::addVertex()
{
	return size_t();
}

void DMatrixGraph::addEdge(size_t vert1, size_t vert2)
{
}

void DMatrixGraph::deleteEdge(size_t vert1, size_t vert2)
{
}

void DMatrixGraph::deleteNode(size_t vert)
{
}

AdjencyListsGraphRepresentation::Vertex::Vertex()
{
	neighbors = std::list<size_t>();
}
