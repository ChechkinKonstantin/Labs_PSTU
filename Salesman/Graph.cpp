#include "Graph.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <vector>


// Misha code's start


void Graph::delVertex(int index)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < this->edges.size(); i++)
		{
			if (this->edges[i].getVerticiesNames()[0] == this->verticies[index].getText() || this->edges[i].getVerticiesNames()[1] == this->verticies[index].getText())
			{
				this->edges.erase(this->edges.begin() + i);
				flag = true;
				break;
			}
		}

	}
	this->verticies.erase(this->verticies.begin() + index);

	for (int i = 0; i < this->adjMatrix.size(); i++)
	{
		this->adjMatrix[i].erase(this->adjMatrix[i].begin() + index);
	}
	this->adjMatrix.erase(this->adjMatrix.begin() + index);
	this->numberOfVertecies--;
}

void Graph::eval(const int& start)
{
	std::list<int> path;
	path.push_back(start);
	std::vector<bool> vis(this->verticies.size(), false);
	vis[start] = true;
	this->opop(start, start, path, vis);
}

void Graph::clearPath()
{
	this->path.clear();
	this->rec = INT_MAX;
}


std::vector<int> Graph::getNBRS(const int& vert)
{
	std::list<int> res;

	for (int j = 0; j < this->verticies.size(); ++j)
	{
		if (this->adjMatrix[vert][j])
		{
			res.push_back(j);
		}
	}



	return std::vector<int>(res.begin(), res.end());
}

bool Graph::AllVisited(std::vector<bool>& visitedVerts)
{
	bool flag = true;
	for (int i = 0; i < this->verticies.size(); i++)
		if (visitedVerts[i] != true)
			flag = false;
	return flag;
};

void Graph::opop(const int& start, const int& current, std::list<int>& path, std::vector<bool>& visitedVerts)
{
	if (this->AllVisited(visitedVerts))
	{
		int min = 0;
		if (!this->adjMatrix[current][start])
		{
			return;
		}


		std::vector<int> p(path.begin(), path.end());
		for (int i = 0; i < p.size() - 1; ++i)
		{
			min += this->adjMatrix[p[i]][p[i + 1]];
			/*std::cout << this->vertexList[p[i]] << ' ';*/
		}
		min += this->adjMatrix[current][start];
		std::cout << std::endl;
		if (rec > min)
		{
			rec = min;
			this->path = path;
		}

		std::cout << std::endl;
	}

	std::vector<int> nbrs = this->getNBRS(current);

	for (int& i : nbrs)
	{
		if (!visitedVerts[i])
		{
			std::vector<bool> cpy_vis(visitedVerts.begin(), visitedVerts.end());
			std::list<int> path_cpy(path.begin(), path.end());
			cpy_vis[i] = true;
			path_cpy.push_back(i);
			opop(start, i, path_cpy, cpy_vis);
		}
	};

}
std::vector<std::string> Graph::getVertexArray() const
{
	std::vector<std::string> res(this->verticies.size());
	int c = 0;
	for (Vertex& i : this->verticies) 
	{
		res[c++] = i.getText();
	}
	return res;
}
std::vector<int> Graph::getPath() const
{
	return std::vector<int>(this->path.begin(),this->path.end());
}
int Graph::getLenOfPath() const
{
	return this->rec;
}
;

//Misha code's end


std::vector<std::vector<int>> Graph::getAdjMatrix()
{
	return this->adjMatrix;
}

bool Graph::coordsIsInVerticies(sf::Vector2f coords)
{
	for (auto& o : this->verticies)
	{
		//return o.circle.getGlobalBounds().contains(coords);
		
		if (pow(coords.x - o.getPosition().x , 2) + pow(coords.y - o.getPosition().y , 2) <= pow(o.getRadius(), 2))
		{
			return true;
		}
		
	}
	return false;
}

Vertex Graph::getVertexInCoords(sf::Vector2f coords)
{
	for (auto&& o : this->verticies)
	{
		if (pow(coords.x - o.getPosition().x, 2) + pow(coords.y - o.getPosition().y , 2) <= pow(o.getRadius(), 2))
		{
			return o;
		}
	}
}

int Graph::getVertexIndex(Vertex vertex)
{
	int result = -1;
	for (int i = 0; i < this->verticies.size(); i++)
	{
		if (this->verticies[i] == vertex)
		{
			result = i;
		}
	}
	return result;
}

void Graph::draw(sf::RenderWindow& window, sf::Font& font)
{
	if (this->buffer.size() == 2)
	{
		TextInput input(30, sf::Color::White, true);
		input.setPosition({ 50, 50 });
		input.setFont(font);

		int weight = std::stoi(input.getInput(font));

		this->edges.push_back(Edge(weight, this->buffer[0], this->buffer[1], font));

		if (this->getVertexIndex(this->buffer[0]) != -1 && this->getVertexIndex(this->buffer[1]) != -1)
		{
			this->adjMatrix[this->getVertexIndex(this->buffer[0])][this->getVertexIndex(this->buffer[1])] = weight;
		}
		buffer.clear();
	}
	for (auto&& o : this->edges)
	{
		o.draw(window);
	}
	for (auto&& o : this->verticies)
	{
		o.draw(window);
	}
}

// how to bild your pc
// 17 febr text намофобия
//
//
//


void Graph::printAdjMatrix(sf::Font& font)
{
	sf::RenderWindow window(sf::VideoMode(100 * (this->adjMatrix.size() + 1), 80 * (this->adjMatrix.size() + 1)), "Adjective Matrix", sf::Style::Close);
	Table table(sf::Vector2f(0, 0), sf::Vector2i(this->adjMatrix.size(), this->adjMatrix.size()), this->getVertexArray(), font);

	table = this->adjMatrix;
	
	sf::Event event;

	sf::Color bgColor;
	bgColor.r = 20;
	bgColor.g = 21;
	bgColor.b = 38;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear(bgColor);

		table.draw(window);

		window.display();
	}
}

void Graph::addVertexToBuffer(Vertex vertex)
{
	this->buffer.push_back(vertex);
}

Graph::Graph()
{
	this->numberOfVertecies = 0; // new for drawing
}

void Graph::addVertex(Vertex vertex)
{
	this->verticies.push_back(vertex);
	std::vector<std::vector<int>> tmp(this->adjMatrix.size() + 1, std::vector<int>(this->adjMatrix.size() + 1, 0));
	for (int i = 0; i < this->adjMatrix.size(); i++)
	{
		for (int j = 0; j < this->adjMatrix.size(); j++)
		{
			tmp[i][j] = this->adjMatrix[i][j];
		}
	}
	this->adjMatrix = tmp;

}



