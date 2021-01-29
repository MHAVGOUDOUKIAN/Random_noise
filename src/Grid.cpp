#include "Grid.h"

Grid::Grid()
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	srand(seed);
	
	m_table[1][1] = rand() % 245 + 10;
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

float Grid::getNeighboorMid(const int x, const int y) const
{
	float res=0;
	int count=0;
	
	if(x == 0 || x == m_dim-1 || y == 0 || y == m_dim-1) { res = 0; }
	else {
		// Voisins des cotés ?
		if( x-1 != 0 ) { res += m_table[x-1][y]; count++; }
		if( x+1 != m_dim-1 ) { res += m_table[x+1][y]; count++; }
		if( y-1 != 0 ) { res += m_table[x][y-1]; count++; }
		if( y+1 != m_dim-1 ) { res += m_table[x][y+1]; count++; }

		// Voisins des diagonales ? 
		if( x-1 != 0 && y-1 != 0 ) { res += m_table[x-1][y-1]; count++; }
		if( x+1 != 0 && y+1 != 0 ) { res += m_table[x+1][y+1]; count++; }
		if( x-1 != 0 && y+1 != 0 ) { res += m_table[x-1][y+1]; count++; }
		if( x+1 != 0 && y-1 != 0 ) { res += m_table[x+1][y-1]; count++; }

		res /= count; 
	}

	return res;
}