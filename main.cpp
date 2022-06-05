#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
	RenderWindow window(VideoMode(900, 500), "Tutorial", Style::Default);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				break;
			case Event::TextEntered:
				break;
			case Event::KeyPressed:
				break;
			case Event::MouseMoved:
				break;
			case Event::MouseButtonPressed:
				break;
			default:
				break;

		}

		//update new


	
		//Clear
		window.clear();

		//display to monitor
		window.display();
	}
	return 0;
}