// MyBiweeklyGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 이벤트 관련 페이지 : https://stackoverflow.com/questions/768351/complete-example-using-boostsignals-for-c-eventing
#include "TicTacToeGate.h"
int main()
{
	/*
	std::cout << MessageBoxA(NULL, "text", "Title!!", MB_OKCANCEL | MB_ICONEXCLAMATION);
	sf::Texture background;
	sf::Sprite backgroundImage;
	if (background.loadFromFile("board.png") == false)
		std::cout << "can't find background image" << std::endl;
	backgroundImage.setTexture(background);

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "TicTacToe", sf::Style::Close);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(backgroundImage);
		window.display();
	}
	*/
	WindowSize windowSize = std::make_pair(800, 600);
	TicTacToeGate gate(windowSize);
	gate.UpdateGameLoop();

	return 0;
}
