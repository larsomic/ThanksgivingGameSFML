#include "PA8Header.h"
#include <Windows.h>

void mainMenu(sf::RenderWindow& window, sf::Font font)
{
	sf::RectangleShape background(sf::Vector2f(1920, 1080));

	sf::Texture menuBackgroundImage;
	menuBackgroundImage.loadFromFile("menuBackground.png");

	background.setTexture(&menuBackgroundImage);

	int charChoice;

	sf::Text playText, exitText;
	playText.setCharacterSize(130);
	playText.setFillColor(sf::Color::Black);
	playText.setFont(font);
	playText.setPosition(1540, 900);
	playText.setString("Play");

	exitText.setCharacterSize(130);
	exitText.setFont(font);
	exitText.setPosition(130, 900);
	exitText.setString("Exit");

	sf::Event checkTheirChoice;
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	sf::Event eventChosen;

	int whoIsChar;

	while (window.pollEvent(eventChosen))
	{
	}

	if (eventChosen.type == sf::Event::Closed)
	{
		window.close();
	}
	//logic to see if they clicked exit
	if ((mousePos.x >= 130 && mousePos.x <= 363)&& (mousePos.y >= 935 && mousePos.y <= 1036))
	{
		exitText.setFillColor(sf::Color::Color(180, 51, 29));
		if (eventChosen.type == sf::Event::MouseButtonPressed)
		{
			window.close();
			return;
		}
	}
	else
	{
		exitText.setFillColor(sf::Color::Black);
	}
	if ((mousePos.x >= 1538 && mousePos.x <= 1793) && (mousePos.y >= 935 && mousePos.y <= 1036))
	{
		playText.setFillColor(sf::Color::Color(180, 51, 29));
		if (eventChosen.type == sf::Event::MouseButtonPressed)
		{
			getHostOrJoin(window, font);
			charChoice = characterChooser(window);

			// this is if the user decides to click x while choosing a char.
			if (charChoice == 3)
			{
				return;
			}
			else if (charChoice == 1)
			{
				// Nadra
				whoIsChar = 1;
			}
			else
			{
				// andy
				whoIsChar = 2;
			}
			playGame(window, whoIsChar);
		}
	}
	else
	{
		playText.setFillColor(sf::Color::Black);
	}

	window.draw(background);
	window.draw(playText);
	window.draw(exitText);

	window.display();
}

void playGame(sf::RenderWindow& window, int whoIsChar)
{
	int randInt;
	randInt = getRand(13);

	int const numInRow1 = 10, numInRow2 = 10, numInRow3 = 10;

	monster row1[numInRow1], row2[numInRow2], row3[numInRow3];

	makeRow(row1, randInt, numInRow1);
	displayRow(row1, numInRow1, window);

	makeRow(row2, randInt, numInRow2);
	displayRow(row2, numInRow2, window);

	makeRow(row3, randInt, numInRow3);
	displayRow(row3, numInRow3, window);

	int movementSpeed = 10;

	int x = 912, y = 918, score = 0;

	sf::RectangleShape background;
	sf::Texture backgroundPic;

	background.setSize(sf::Vector2f(1920, 1080));
	background.setPosition(0, 0);
	backgroundPic.loadFromFile("backgroundGame.png");
	background.setTexture(&backgroundPic);

	sf::RectangleShape forkR;
	sf::Texture forkImage;

	player player1, player2;

	if (whoIsChar == 2)
	{
		player1.setName("Andy");	
		player2.setName("Nadra");
	}
	else
	{
		player1.setName("Nadra");
		player2.setName("Andy");
	}

	player1.texturePic();
	player2.texturePic();

	player1.changeBoxSize(sf::Vector2f(97, 155));
	player2.changeBoxSize(sf::Vector2f(97, 155));

	player1.drawTexture();
	player2.drawTexture();

	player1.draw2Screen(window);
	player2.draw2Screen(window);

	player1.setYcord(918);
	player2.setYcord(918);
	   
	int p1x = 612, p1y = 918, p1score = 0, p2x = 1212, p2y = 918, p2score = 0, forkY = 1080;
	fork forkObj;

	forkObj.setName("fork");
	forkObj.texturePic();
	forkObj.changeBoxSize(sf::Vector2f(157, 27));
	forkObj.drawTexture();
	forkObj.rotateRect(-90);

	window.display();
	
	sf::Event event1;

	int numArray;

	numArray = sizeof(row1) / sizeof(monster);

	bool atEnd = FALSE, gameOver = FALSE;

	while (gameOver != TRUE)
	{
		window.draw(background);
		
		window.pollEvent(event1);

		//draws background
		window.draw(background);
		if (event1.type == sf::Event::Closed)
		{
			window.close();
			return;
		}

		atEnd = moveRow(row1, numInRow1, window, atEnd);
		gameOver = checkGameOver(row1, numInRow1);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
	 		int tempX = player1.getXcord();

			while (forkObj.checkHit(row1[9]) == false && forkObj.getYcord() > 165)
			{
				atEnd = moveRow(row1, numInRow1, window, atEnd);
				gameOver = checkGameOver(row1, numInRow1);

				player1.openMouth();
				player1.draw2Screen(window);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player1.getXcord() <= 1800)
				{
					player1.setXcord(player1.getXcord()+15);
					tempX + 100;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player1.getXcord() >= 10)
				{
					player1.setXcord(player1.getXcord() - 15);
					tempX - 100;
				}

				forkObj.setYcord(forkObj.getYcord() - 7);
				forkObj.setXcord(tempX+30);

				forkObj.updateCords(forkObj.getXcord(), forkObj.getYcord());

				originalWindow(window, background, player1);
  				forkObj.draw2Screen(window);
				displayRow(row1, numInRow1, window);
				window.display();
				originalWindow(window, background, player1);
				forkObj.draw2Screen(window);
				displayRow(row1, numInRow1, window);
				window.display();
			}
			forkObj.setYcord(1080);
		}
		else
		{
			player1.closeMouth();
			displayRow(row1, numInRow1, window);
			player1.draw2Screen(window);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player1.getXcord() <= 1800)
		{
			player1.setXcord(player1.getXcord() + 13);
			sf::Packet m1packet;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player1.getXcord() >= 10)
		{
			player1.setXcord(player1.getXcord() - 13);
		}

		// displays new screen
		window.display();
	}
}

int characterChooser(sf::RenderWindow& window)
{
	sf::RectangleShape background, nadraHead, andyHead;

	sf::Vector2i windowLocation = window.getPosition();

	background.setSize(sf::Vector2f(1920, 1080));
	nadraHead.setSize(sf::Vector2f(387, 620));
	andyHead.setSize(sf::Vector2f(387, 620));

	sf::Texture backgroundImage, andyImage, nadraImage;

	backgroundImage.loadFromFile("charChooser.png");
	andyImage.loadFromFile("Andy.png");
	nadraImage.loadFromFile("Nadra.png");

	background.setTexture(&backgroundImage);
	andyHead.setTexture(&andyImage);
	nadraHead.setTexture(&nadraImage);

	andyHead.setPosition(1150, 320);
	nadraHead.setPosition(400, 320);

	window.clear();
	window.display();	
	window.clear();
	window.display();

	int charChosen = 0;
	sf::Event event1;
	
	while (charChosen != 1)
	{
		window.pollEvent(event1);

		if (event1.type == sf::Event::Closed)
		{
			window.close();
			return 5;
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition();
		if (mousePos.x >= windowLocation.x + 400 && mousePos.x <= windowLocation.x + 787 && mousePos.y >= windowLocation.y + 320 && mousePos.y <= windowLocation.y + 940)
		{
			nadraHead.setScale(sf::Vector2f(1.25, 1.25));
			if (event1.type == sf::Event::MouseButtonPressed)
			{
				return 1;
			}
		}
		else
		{
			nadraHead.setScale(sf::Vector2f(1, 1));
		}

		if (mousePos.x >= windowLocation.x + 1151 && mousePos.x <= windowLocation.x + 1549 && mousePos.y >= windowLocation.y + 320 && mousePos.y <= windowLocation.y + 940)
		{
			andyHead.setScale(sf::Vector2f(1.25, 1.25));
			if (event1.type == sf::Event::MouseButtonPressed)
			{
				return 2;
			}
		}
		else
		{
			andyHead.setScale(sf::Vector2f(1, 1));
		}
		
		window.draw(background);
		window.draw(andyHead);
		window.draw(nadraHead);
		window.display();
	}
}

void getHostOrJoin(sf::RenderWindow& window, sf::Font font)
{
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture backgroundPic;

	backgroundPic.loadFromFile("menuBackground.png");
	background.setTexture(&backgroundPic);

	window.clear();
	window.display();
	window.clear();

	bool notSelected = TRUE;

	sf::Event event1;

	sf::Text join, host;

	join.setFont(font);
	host.setFont(font);
	join.setCharacterSize(130);
	host.setCharacterSize(130);
	host.setPosition(sf::Vector2f(130,900));
	join.setPosition(sf::Vector2f(1540, 900));
	join.setFillColor(sf::Color::Black);
	host.setFillColor(sf::Color::Black);
	join.setString("Join");
	host.setString("Host");
		
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	while (notSelected == TRUE)
	{
		mousePos = sf::Mouse::getPosition(window);

		window.pollEvent(event1);
		if (event1.type == sf::Event::Closed)
		{
			window.close();
			return;
		}

		if ((mousePos.x >= 130 && mousePos.x <= 363) && (mousePos.y >= 935 && mousePos.y <= 1036))
		{
			host.setFillColor(sf::Color::Color(180, 51, 29));
			if (event1.type == sf::Event::MouseButtonPressed)
			{
				//  Meghna do host stuff
				notSelected = FALSE;
			}
		}
		else
		{
			host.setFillColor(sf::Color::Black);
		}
		if ((mousePos.x >= 1538 && mousePos.x <= 1793) && (mousePos.y >= 935 && mousePos.y <= 1036))
		{
			join.setFillColor(sf::Color::Color(180, 51, 29));
			if (event1.type == sf::Event::MouseButtonPressed)
			{
				//  Meghna do join stuff
				notSelected = FALSE;
			}
		}
		else
		{
			join.setFillColor(sf::Color::Black);
		}

		window.draw(background);
		window.draw(join);
		window.draw(host);
		window.display();
	}
}

void originalWindow(sf::RenderWindow& window, sf::RectangleShape background, moveableObject & inObject)
{
	window.clear();
	window.draw(background);
	inObject.draw2Screen(window);
}

int getRand(int x)
{
	srand(rand() * time(NULL));

	return ((rand() % x) + 1);
}

void makeRow(monster cardA[], int randInt, int num)
{
	int len, height, score;

	sf::Vector2f hw;

	string name, temp;
	temp = to_string(randInt);
	name = "f" + temp;
	
	if (randInt == 1 || randInt == 2)
	{
		score = 1;

		hw.x = 117;
		hw.y = 117;
	}
	else if (randInt == 3 || randInt == 4)
	{
		score = 2;

		hw.x = 60;
		hw.y = 60;
	}
	else if (randInt == 5)
	{
		score = 3;

		hw.x = 132;
		hw.y = 153;
	}
	else if (randInt == 6 || randInt == 7 || randInt == 8)
	{
		score = 4;

		hw.x = 110;
		hw.y = 56;
	}
	else if (randInt == 9)
	{
		score = 5;

		hw.x = 91;
		hw.y = 146;
	}
	else if (randInt == 10)
	{
		score = 6;

		hw.x = 130;
		hw.y = 130;
	}
	else if (randInt == 11 || randInt == 12)
	{
		score =  7;

		hw.x = 98;
		hw.y = 66;
	}
	else
	{
		score = 8;

		hw.x = 125;
		hw.y = 150;
	}

	string temps = to_string(randInt);
	temps = "f" + temps;

	for (int j = 0; j < num; j++)
	{
		cardA[j].setScore(score);
		cardA[j].setName(temps);
		cardA[j].texturePic();
		cardA[j].changeBoxSize(hw);
		cardA[j].drawTexture();
		cardA[j].updateCords(150 * j, 0);
	}
}

void displayRow(monster cardA[], int num, sf::RenderWindow& window)
{
	for (int i = 0; i < num; i++)
	{
		cardA[i].draw2Screen(window);
	}
}

bool moveRow(monster cardA[], int num, sf::RenderWindow & window, bool atEnd)
{
	if (cardA[num-1].getXcord() + cardA[num-1].getBoxSize().x < window.getSize().x && atEnd == FALSE)
	{
		for (int i = 0; i < num; i++)
		{
			cardA[i].updateCords(cardA[i].getXcord() + 2, cardA[i].getYcord());
		}
	}
	else if (cardA[0].getXcord()  >= 0 && atEnd == TRUE)
	{
		for (int i = 0; i < num; i++)
		{
			cardA[i].updateCords(cardA[i].getXcord() - 2, cardA[i].getYcord());
		}
	}
	else if (cardA[0].getXcord() <= 6)
	{
		for (int j = 0; j < num; j++)
		{
			cardA[j].setYcord(cardA[j].getYcord() + 50);
		}
		atEnd = FALSE;
	}
	else
	{
		for (int j = 0; j < num; j++)
		{
			cardA[j].setYcord(cardA[j].getYcord() + 50) ;
		}
		atEnd = TRUE;
	}

	return atEnd;
}

bool checkGameOver(monster cardA[], int num)
{
	if (cardA[1].getYcord() >850)
	{
		return true;
	}

	return false;
}