#pragma once
#include <vector>
#include <list>
#include "Vertex.h"
#include "Edge.h"
#include <limits>
#include "Table.h"
#include "TextInput.h"

class Graph
{
private:
	mutable std::vector<Vertex> verticies;
	std::vector<std::vector<int>> adjMatrix;
	std::vector<Vertex> buffer;
	std::vector<Edge> edges;
	int rec = INT_MAX;
	std::list<int> path;

	int numberOfVertecies;
public:
	Graph();
	void addVertex(Vertex vertex);
	void addVertexToBuffer(Vertex vertex);
	Vertex getVertexInCoords(sf::Vector2f);
	bool coordsIsInVerticies(sf::Vector2f);
	void draw(sf::RenderWindow& window, sf::Font& font);
	int getVertexIndex(Vertex vertex);
	std::vector<std::vector<int>> getAdjMatrix();
	bool AllVisited(std::vector<bool>& visitedVerts);
	std::vector<std::string> getVertexArray() const;
	void delVertex(int index);

	std::vector<int> getPath() const;
	int getLenOfPath() const;
	void printAdjMatrix(sf::Font& font);
	void clearPath();



	void eval(const int& start);
	std::vector<int> getNBRS(const int& vert);
	void opop(const int& start, const int& current, std::list<int>& path, std::vector<bool>& visitedVerts);
};
