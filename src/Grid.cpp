#include "Grid.h"

Grid::Grid()
: m_cursor(2, 1)
, m_direction(Horizontal)
, m_level(0)
, m_seed(std::chrono::steady_clock::now().time_since_epoch().count())
{
	srand(m_seed);
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
		m_cursor[0] = 1;
		m_cursor[1] = 1;
	}
	
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	double mean = getNeighboorMean(m_cursor[0], m_cursor[1]);
    std::normal_distribution<double> distN(mean, 25.);
	double new_value = distN(generator);
	new_value = round(new_value);
	if(new_value > 255) {new_value = 255;}
	if(new_value < 10) {new_value = 10;}
	
	modif(m_cursor[0], m_cursor[1], new_value);
}


float Grid::getNeighboorMean(const int x, const int y) const
{
	float res=0;
	int count=0;
	
	if(x == 0 || x == m_dim-1 || y == 0 || y == m_dim-1) { res = 0; }
	else {
		// Voisins des cotés ?
		if( x-1 != 0 && m_table[x-1][y] != 0) { res += m_table[x-1][y]; count++; }
		if( x+1 != m_dim-1 && m_table[x+1][y] != 0) { res += m_table[x+1][y]; count++; }
		if( y-1 != 0 && m_table[x][y-1] != 0) { res += m_table[x][y-1]; count++; }
		if( y+1 != m_dim-1 && m_table[x][y+1] != 0) { res += m_table[x][y+1]; count++; }

		// Voisins des diagonales ? 
		if( x-1 != 0 && y-1 != 0 && m_table[x-1][y-1] != 0) { res += m_table[x-1][y-1]; count++; }
		if( x+1 != m_dim-1 && y+1 != m_dim-1 && m_table[x+1][y+1] != 0) { res += m_table[x+1][y+1]; count++; }
		if( x-1 != 0 && y+1 != m_dim-1 && m_table[x-1][y+1] != 0) { res += m_table[x-1][y+1]; count++; }
		if( x+1 != m_dim-1 && y-1 != 0 && m_table[x+1][y-1] != 0) { res += m_table[x+1][y-1]; count++; }

		res /= count; 
	}

	return res;
}
