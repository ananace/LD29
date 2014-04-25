#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>

#include <cstdint>
#include <functional>
#include <vector>
#include <map>

namespace sf { class Event; }
class MenuState;

class MenuPage
{
public:
	MenuPage(MenuState* state);
	MenuPage(const MenuPage&);
	MenuPage(MenuPage&&);
	virtual ~MenuPage();

	MenuPage& operator=(MenuPage);

	void setHideFactor(float);
	float getHideFactor() const;

	virtual void handleEvent(const sf::Event& ev);
	virtual void update(double dt);
	virtual void draw(sf::RenderTarget& target);

protected:
	std::vector<std::pair<std::string, std::function<void()> > > mEntries;
	MenuState* mMenuState;
	std::string mSelectedEntry;
	int16_t mSelectedIndex;
	sf::Font mMenuFont;
	float mHideFactor;
};