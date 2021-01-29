#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable
{
public :
	
	Grid();
	void update();
	
private :
	
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	void modif(int, int, int);
	
private :
	
	static constexpr int m_dim = 50;
	int m_table[m_dim][m_dim]{};
};

#endif // GRID_H
