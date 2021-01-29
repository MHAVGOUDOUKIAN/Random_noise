#include "Grid.h"

Grid::Grid()
: m_cursor(2, 1)
, m_direction(Horizontal)
, m_level(0)
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	srand(seed);
	
	m_table[m_cursor[0]][m_cursor[1]] = rand() % 245 + 10;
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

void Grid::toggleDirection()
{
	m_direction = (m_direction == Horizontal) ? Vertical : Horizontal;
}

void Grid::update()
{
	if(m_direction == Horizontal)
	{
		if(m_cursor[0] == m_dim-2)
		{
			toggleDirection();
			m_cursor[0] = m_level;
			++m_level;
			
		}
		++m_cursor[0];
	}
	
	if(m_direction == Vertical)
	{
		if(m_cursor[1] == m_dim-2)
		{
			toggleDirection();
			m_cursor[1] = m_level;
		}
		++m_cursor[1];
	}
	
	if(m_level == m_dim-2)
	{
		m_level = 0;
	}
	
	modif(m_cursor[0], m_cursor[1], rand() % 245 + 10);
	
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
