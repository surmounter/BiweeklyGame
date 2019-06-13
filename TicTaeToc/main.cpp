// MyBiweeklyGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 이벤트 관련 페이지 : https://stackoverflow.com/questions/768351/complete-example-using-boostsignals-for-c-eventing
#include "TicTacToeGate.h"
#include <iostream>
/*
void Draw(sf::RenderWindow &window)
{
	sf::Texture markO;
	sf::Sprite markOImage;	
	if (markO.loadFromFile("Resource/markO.png") == false)
		std::cout << "can't find markO image" << std::endl;
	markOImage.setTexture(markO);
	markOImage.setPosition(0.0f, 0.0f);
	window.draw(markOImage);
}
*/
int main()
{
	/*
	sf::Texture background;
	sf::Sprite backgroundImage;
	sf::Texture markO;
	sf::Sprite markOImage;
	if (background.loadFromFile("Resource/board.png") == false)
		std::cout << "can't find background image" << std::endl;
	backgroundImage.setTexture(background);
	if(markO.loadFromFile("Resource/markO.png") == false)
		std::cout << "can't find markO image" << std::endl;
	markOImage.setTexture(markO);
	markOImage.setPosition(200.0f, 0.0f);

	sf::RenderWindow window;
	window.create(sf::VideoMode(600, 600), "TicTacToe", sf::Style::Close);
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
		window.draw(markOImage);
		//markOImage.setPosition(0.0f, 0.0f);
		window.draw(markOImage);
		window.display();
	}
	*/
	
	
	WindowSize windowSize = std::make_pair(600, 600);
	TicTacToeGate gate(windowSize);
	gate.UpdateGameLoop();
	return 0;
	
}
