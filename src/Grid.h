#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>

class Grid : public sf::Drawable
{
public :
	enum Direction
	{
		Horizontal,
		Vertical
	};
	
public :
	
	Grid();
	void update();
	float getNeighboorMid(const int x, const int y) const;

private :
	
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void modif(int, int, int);
	void toggleDirection();
	
private :
	
	static constexpr int m_dim = 12;
	int m_table[m_dim][m_dim]{};
	std::vector<unsigned> m_cursor;
	Direction m_direction;
	unsigned m_level;
};

#endif // GRID_H
