// MyBiweeklyGame.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

// �̺�Ʈ ���� ������ : https://stackoverflow.com/questions/768351/complete-example-using-boostsignals-for-c-eventing
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
