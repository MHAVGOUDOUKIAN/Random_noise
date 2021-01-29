#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <chrono>

class Grid : public sf::Drawable
{
public :
	
	Grid();
	void update();
	float getNeighboorMid(const int x, const int y) const;

private :
	
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void modif(int, int, int);
	
private :
	
	static constexpr int m_dim = 12;
	int m_table[m_dim][m_dim]{};
};

#endif // GRID_H
