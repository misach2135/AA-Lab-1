#include "Graph.h"

Graph::~Graph()
{
}

UndirectedGraph::UndirectedGraph()
{
	vertexCount = 0;
}

UndirectedGraph::UndirectedGraph(size_t verts)
{
	for (size_t i = 0; i < verts; i++)
	{
		addVertex();
	}
}

size_t UndirectedGraph::addVertex()
{
	vertices[vertexCount] = std::list<size_t>();
	vertexCount++;
	return vertexCount - 1;
}

void UndirectedGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vertices.find(vert1) == vertices.end()) return;
	if (vertices.find(vert2) == vertices.end()) return;

	vertices[vert1].push_back(vert2);
	vertices[vert2].push_back(vert1);

}

void UndirectedGraph::deleteEdge(size_t vert1, size_t vert2)
{
	if (vertices.find(vert1) == vertices.end()) return;
	if (vertices.find(vert2) == vertices.end()) return;

	for (auto i = vertices[vert1].begin(); i != vertices[vert1].end(); i++)
	{
		if (*i == vert2)
		{
			vertices[vert1].erase(i);
			break;
		}
	}

	for (auto i = vertices[vert2].begin(); i != vertices[vert2].end(); i++)
	{
		if (*i == vert1)
		{
			vertices[vert2].erase(i);
			break;
		}
	}
}

void UndirectedGraph::deleteNode(size_t vert)
{
	if (vertices.find(vert) == vertices.end()) return;
	
	vertices.erase(vert);

	for (auto& kv : vertices)
	{
		for (auto i = kv.second.begin(); i != kv.second.end(); i++)
		{
			if (*i == vert)
			{
				kv.second.erase(i);
				break;
			}
		}
	}
}

std::string UndirectedGraph::toAdjListsString()
{
	std::string res;
	for (const auto& kv : vertices)
	{
		res.append(std::to_string(kv.first) + "-> ");
		for (const auto& v : kv.second)
		{
			res.append(std::to_string(v) + " ");
		}
		res.append("\n");
	}
	return res;
}

std::string UndirectedGraph::toAdjMatrixString()
{
	std::string res;
	for (const auto& kv : vertices)
	{
		for (size_t i = 0; i < this->vertexCount; i++)
		{
			if (std::find(kv.second.begin(), kv.second.end(), i) != kv.second.end())
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

DirectedGraph::DirectedGraph()
{
	vertexCount = 0;
}

DirectedGraph::DirectedGraph(size_t verts)
{
	for (size_t i = 0; i < verts; i++)
	{
		addVertex();
	}
}

size_t DirectedGraph::addVertex()
{
	vertices[vertexCount] = std::list<size_t>();
	vertexCount++;
	return vertexCount - 1;
}

void DirectedGraph::addEdge(size_t vert1, size_t vert2)
{
	if (vertices.find(vert1) == vertices.end()) return;
	if (vertices.find(vert2) == vertices.end()) return;

	vertices[vert1].push_back(vert2);
}

void DirectedGraph::deleteEdge(size_t vert1, size_t vert2)
{
	if (vertices.find(vert1) == vertices.end()) return;
	if (vertices.find(vert2) == vertices.end()) return;

	for (auto i = vertices[vert1].begin(); i != vertices[vert1].end(); i++)
	{
		if (*i == vert2)
		{
			vertices[vert1].erase(i);
			break;
		}
	}

}

void DirectedGraph::deleteNode(size_t vert)
{
	if (vertices.find(vert) == vertices.end()) return;

	vertices.erase(vert);

	for (auto& kv : vertices)
	{
		for (auto i = kv.second.begin(); i != kv.second.end(); i++)
		{
			if (*i == vert)
			{
				kv.second.erase(i);
				break;
			}
		}
	}
}

std::string DirectedGraph::toAdjListsString()
{
	std::string res;
	for (const auto& kv : vertices)
	{
		res.append(std::to_string(kv.first) + "-> ");
		for (const auto& v : kv.second)
		{
			res.append(std::to_string(v) + " ");
		}
		res.append("\n");
	}
	return res;
}

std::string DirectedGraph::toAdjMatrixString()
{
	std::string res;
	for (const auto& kv : vertices)
	{
		for (size_t i = 0; i < this->vertexCount; i++)
		{
			if (std::find(kv.second.begin(), kv.second.end(), i) != kv.second.end())
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


