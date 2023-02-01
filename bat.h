#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
struct Bat {
	sf::RectangleShape shape;
	float speedX;
};
void batInit(Bat& bat) {
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
}
void batControl(Bat& bat) {
	bat.speedX = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		bat.speedX = -BAT_SPEEDX;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		bat.speedX = BAT_SPEEDX;
	}
	bat.shape.move(bat.speedX, 0.f);
}
void batUpdate(Bat& bat) {
	batControl(bat);
	if (bat.shape.getPosition().x < 0) {
		bat.shape.setPosition(0.f, BAT_START_POS.y);
	}
	if (bat.shape.getPosition().x > WINDOW_WIDTH - BAT_WIDTH) {
		bat.shape.setPosition(WINDOW_WIDTH - BAT_WIDTH, BAT_START_POS.y);
	}
}
void batDraw(sf::RenderWindow& window, const Bat& bat) {
	window.draw(bat.shape);
}