#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
#include "brick.h"
struct BrickField {
	Brick arr[ROWS][COLUMNS];
};

void brickFieldInit(BrickField& brickField)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			sf::Color color;
			if (i == 0 || i == 1) color = sf::Color::Red;
			else if (i == 2 || i == 3) color = sf::Color{ 255,165,0 };
			else if (i == 4 || i == 5) color = sf::Color::Green;
			else if (i == 6 || i == 7) color = sf::Color::Yellow;
			sf::Vector2f position{ 0.f + j * BRICK_WIDTH, 60.f + i * BRICK_HEIGHT };
			brickInit(brickField.arr[i][j], color, position);
		}
	}
}

void brickFieldUpdate(BrickField& brickField) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			brickUpdate(brickField.arr[i][j]);
		}
	}
}

void brickFieldDraw(sf::RenderWindow& window, const BrickField& brickField) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			brickDraw(window, brickField.arr[i][j]);
		}
	}
}