#include <SFML/Graphics.hpp>
#include "Header.h"
#include "functions.h"
#include "bat.h"
#include "text.h"
#include "brick.h"
#include "ball.h"
#include "brickfield.h"
using namespace sf;
enum GameState{PLAY,GAME_OVER,YOU_WIN};
int main(){
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setFramerateLimit(60);

	GameState gameState = PLAY;

	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	Textobj scoreText;
	TextobjInit(scoreText, std::to_string(ball.score),TEXT_POS);
	Textobj gameOverText;
	TextobjInit(gameOverText, "GAME OVER", Vector2f{ (WINDOW_WIDTH - 250.f) / 2,(WINDOW_HEIGHT - 50.f) / 2 });
	Textobj youWinText;
	TextobjInit(youWinText, "YOU WIN", Vector2f{ (WINDOW_WIDTH - 250.f) / 2,(WINDOW_HEIGHT - 50.f) / 2 });
	BrickField field;
	brickFieldInit(field);


	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		switch (gameState) {
		case PLAY:
				ballUpdate(ball);
				batUpdate(bat);
				if (ball.shape.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT) {
					gameState = GAME_OVER;
				}
				TextobjUpdate(scoreText, ball.score);
				brickFieldUpdate(field);


				ballCollidedWithBat(ball, bat);
				ballCollidedWithBricks(ball, field);

				if (ball.score == 320) {
					gameState = YOU_WIN;
				}

				window.clear();
				brickFieldDraw(window, field);
				ballDraw(window, ball);
				batDraw(window, bat);
				textDraw(window, scoreText);
				window.display();
				break;
		case GAME_OVER:
			window.clear();
			textDraw(window, gameOverText);
			window.display();
		case YOU_WIN:
			window.clear();
			textDraw(window, youWinText);
			window.display();
		}

		
	}

	return 0;
}