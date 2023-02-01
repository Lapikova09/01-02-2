#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
struct Textobj {
	sf::Text text;
	sf::Font font;
};
void TextobjInit(Textobj& textobj, std::string str,sf::Vector2f position) {
	textobj.font.loadFromFile("DS-DIGIB.ttf");
	textobj.text.setFont(textobj.font);
	textobj.text.setString(str);
	textobj.text.setCharacterSize(FONT_SIZE);
	textobj.text.setPosition(position);
}
void TextobjUpdate(Textobj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}
void textDraw(sf::RenderWindow& window, const Textobj& textobj) {
	window.draw(textobj.text);
}