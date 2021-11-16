#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(640, 480), "Жужа", Style::Fullscreen);

	Clock clock;
	Image heroimage;
    heroimage.loadFromFile("Images/Bob.png");
	//heroimage.createMaskFromColor(Color(255, 255, 255));

	Texture  herotexture;
	herotexture.loadFromImage(heroimage);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 61+1, 61, 61));
	herosprite.setPosition(50, 300);

	float CurrentFrame = 0;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close(); // выход по ESC

		if (Keyboard::isKeyPressed(Keyboard::Left))  {
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame = 0;
			herosprite.setTextureRect(IntRect(61*int(CurrentFrame), 61*3+1, 61, 61));
			herosprite.move(-0.1*time, 0);  
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) { 
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame = 0;
			herosprite.setTextureRect(IntRect(61 * int(CurrentFrame), 61*1+1, 61, 61));
			herosprite.move(0.1 * time, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))    { 
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame = 0;
			herosprite.setTextureRect(IntRect(61 * int(CurrentFrame), 61*2+1, 61, 61));
			herosprite.move(0, -0.1*time);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))  { 
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 4) CurrentFrame = 0;
			herosprite.setTextureRect(IntRect(61 * int(CurrentFrame), 61*0+1, 61, 61));
			herosprite.move(0, 0.1*time);
		}


		if (Mouse::isButtonPressed(Mouse::Left))  { herosprite.setColor(Color::Red); }
		if (Mouse::isButtonPressed(Mouse::Right)) { herosprite.setColor(Color::White); }


		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}




