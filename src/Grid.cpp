#include "Grid.h"

Grid::Grid()
{
	m_table[0][0] = rand() % 245 + 10;
	
	for(int i = 1; i < m_dim-1; ++i)
	{
		m_table[i][1] = rand() % 245 + 10;
	}
	for(int i = 1; i < m_dim-2; ++i)
	{
		m_table[1][i+1] = rand() % 245 + 10;
	}
	for(int i = 2; i < m_dim-1; ++i)
	{
		m_table[i][2] = rand() % 245 + 10;
	}
	for(int i = 1; i < m_dim-3; ++i)
	{
		m_table[2][i+2] = rand() % 245 + 10;
	}
	for(int i = 3; i < m_dim-1; ++i)
	{
		m_table[i][3] = rand() % 245 + 10;
	}
	for(int i = 1; i < m_dim-4; ++i)
	{
		m_table[3][i+3] = rand() % 245 + 10;
	}
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle;
	
	for(int i = 1; i < m_dim-1; i++)
	{
		for(int j = 1; j < m_dim-1; j++)
		{
			rectangle.setSize(sf::Vector2f(600/m_dim, 600/m_dim));
			rectangle.setPosition(i*600/m_dim, j*600/m_dim);
			rectangle.setOutlineColor(sf::Color::Black);
			rectangle.setOutlineThickness(1);

			int a;
			a = m_table[i][j];
			sf::Color gray(a, a, a);
			rectangle.setFillColor(gray);
			
			target.draw(rectangle, states);
		}
	}
}

void Grid::modif(int numRow, int numCol, int new_value)
{
	m_table[numRow][numCol] = new_value;
}

void Grid::update()
{	
	/*
	bool newArray[m_dim][m_dim]{};
	
	for(int i = 0; i < m_dim; i++)
	{
		for(int j = 0; j < m_dim; j++)
		{
			if(verif(i, j))
				newArray[i][j] = verif(i, j);
		}
	}
	
	for(int i = 0; i < m_dim; i++)
	{
		for(int j = 0; j < m_dim; j++)
		{
			if(newArray[i][j] != m_table[i][j])
				modif(i,j);
		}
	}
	*/
}