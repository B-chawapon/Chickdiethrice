#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "PauseMenu.h"
#include "Textbox.h"
#include"Button.h"
#include<stdio.h>
#include<iostream>
#include<time.h>
#include <string>
#include <sstream>
#include <math.h>
#include<algorithm>
#include<vector>
#include<utility>
//MAP  WEIGHT =1080   HEIGHT=5000;
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int j = 0;
int i = 1;
int m = 0;
int s = 0;
int stackwtfpausemenu = 0;
int a = 0;//blue

float speed = 1;
float slowtime = 1;
bool checkslowtime = 0;

int stackshoes = 0;

int scorecoins = 0;
int frame = 0;
int framewater = 0;
int frametp = 0;
int framechicken = 0;
int checksideplayer = 0;
int redchicken = 0;
int redchcikeny = 0;
int greenchick = 0;
int greenchicy = 0;

bool collinreturn;
bool restart;
bool texttyping = 0;
bool clickinsername = 0;
bool openfile = 0;
float realposcary;
static const float screenheight = 720.0f;
static const float sizecary = 65.0f;
static const float sizecarx = 120.0f;

int side = 1;
int tempdistance;
int highDistance;
int allowDraw = 0;

int checkcollintime = 0;
int hpbar = 0;
int countcollin = 0;
int die = 0;
int countchecksign = 0;
int answer;
int firstopemfile = 0;
int state = 1;
int flipwalk = 1;
int checkSoundAlert = 0;
struct checksidexi
{
	int checkside;
}whitex[6], redx[7], yellowx[6], bluex[6], greenx[4];
int checksidexci;

int repeat = -1;
int scoreLead[6];
string scoreTextLead[6];

void ResizeView(const sf::RenderWindow& window, sf::View& view);
float findPosCarY(sf::RectangleShape colorcar, float poscary);
bool Collision(sf::Vector2f posobject, sf::RectangleShape sizeobject, sf::RectangleShape posplayerfunc, sf::RectangleShape playersizefunc);
bool changeVolumeSign(float playery, float trainy, float limitupper, float limitlower, float trainsizey);

sf::Vector2f positionview;
int main()
{
	struct checksidexi;
	srand(time(NULL));

	sf::Vector2i screen(1080, 720);
	sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "GAME!", sf::Style::Close | sf::Style::Resize);

	sf::Texture bgtexture;
	bgtexture.loadFromFile("bgmenu.png");
	sf::Sprite bgmenubox;
	bgmenubox.setTexture(bgtexture);

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen.x, screen.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	sf::Vector2f positionview(0, 0);

	sf::RectangleShape player(sf::Vector2f(35.f, 35.f));//35
	player.setFillColor(sf::Color::Green);

	sf::Texture chicktexture;
	chicktexture.loadFromFile("chic.png");
	sf::Sprite chicksp;
	chicksp.setTexture(chicktexture);
	chicksp.setTextureRect(sf::IntRect(0.0f, 0.0f, 48.f, 48.f));
	chicksp.setScale(1.371428571428571f, 1.371428571428571f);

	int framecrash = 0;
	int checkcrasheffect = 0;
	int totalcrash = 0;
	sf::Texture crashtexture;
	crashtexture.loadFromFile("crash.png");
	sf::Sprite crashsp[100];
	for ( totalcrash = 0; totalcrash < 100; totalcrash++)
	{
		crashsp[totalcrash].setTexture(crashtexture);
		crashsp[totalcrash].setTextureRect(sf::IntRect(0.0f, 0.0f, 50.f, 50.f));
		crashsp[totalcrash].setScale(0.96f, 0.96f);
		crashsp[totalcrash].setPosition(-99,-99);
	}

	sf::Texture bloodsctexture;
	bloodsctexture.loadFromFile("dieeffect.png");
	sf::Sprite bloodsc;
	bloodsc.setTexture(bloodsctexture);
	bloodsc.setPosition(-1080, -720);
	
	sf::Vector2f spawnPoint = { 1080 / 2,145.f };
	sf::Vector2f halfPoint = { 1080 / 2,2400.f };
	sf::Vector2f bottomPoint = { 1080 / 2,3896.f };
	player.setPosition(spawnPoint);

	sf::RectangleShape white(sf::Vector2f(sizecarx, sizecary));
	white.setFillColor(sf::Color::Transparent);

	sf::RectangleShape green(sf::Vector2f(sizecarx, sizecary));
	green.setFillColor(sf::Color::Transparent);

	sf::RectangleShape red(sf::Vector2f(200.f, sizecary));
	red.setFillColor(sf::Color::Transparent);

	sf::RectangleShape yellow(sf::Vector2f(90, sizecary));
	yellow.setFillColor(sf::Color::Transparent);

	sf::RectangleShape blue(sf::Vector2f(sizecarx, sizecary));
	blue.setFillColor(sf::Color::Transparent);

	sf::RectangleShape purple(sf::Vector2f(100.f, 50.f));
	purple.setFillColor(sf::Color::Magenta);
	sf::Vector2f pospurple[6];
	for (i = 0; i <= 5; i++)
	{
		if (i == 0)
		{
			pospurple[0].x = 500.0f;
			pospurple[i].y = 755.0f;
			continue;
		}
		if (i >= 1 && i <= 2)
		{
			pospurple[1].x = 200.0f;
			pospurple[2].x = 800.0f;
			pospurple[i].y = 1845.0f;
			continue;
		}
		if (i >= 3 && i <= 5)
		{
			pospurple[3].x = 180.0f;
			pospurple[4].x = 490.0f;
			pospurple[5].x = 800.0f;
			pospurple[i].y = 3335.0f;
		}
	}

	sf::RectangleShape river(sf::Vector2f(1080.f, 250.f));//250
	river.setFillColor(sf::Color::Cyan);
	sf::Vector2f posriver[3];
	for (i = 0; i <= 2; i++)
	{
		posriver[i].x = 0;
		if (i == 0)
		{
			posriver[i].y = 1010;//1000+10
		}
		if (i == 1)
		{
			posriver[i].y = 2500;
		}
		if (i == 2)
		{
			posriver[i].y = 4030;//4000+30
		}
		//1000 2500 4000
	}

	sf::Sprite water;
	sf::Texture texturewater;
	texturewater.loadFromFile("water.png");
	texturewater.setSmooth(true);
	water.setTexture(texturewater);
	water.setTextureRect(sf::IntRect(0, 0, 1080.0f, 250.f));

	sf::RectangleShape staminabar(sf::Vector2f(27.0f, 241.0f));
	staminabar.setFillColor(sf::Color::Green);
	staminabar.setScale(0.65f, 0.645f);
	staminabar.setRotation(180.0f);

	sf::Sprite staminaSprite;
	sf::Texture texturestamina;
	texturestamina.loadFromFile("staminabar.png");
	texturestamina.setSmooth(true);
	staminaSprite.setTexture(texturestamina);
	staminaSprite.setTextureRect(sf::IntRect(0.0f, 0.0f, 50.f, 300.f));
	staminaSprite.setScale(sf::Vector2f(0.65f, 0.65f));

	sf::RectangleShape boat1(sf::Vector2f(200.0f, 62.5f));//200
	boat1.setFillColor(sf::Color::Transparent);//Red
	sf::Vector2f posboat[9];
	for (i = 0; i <= 8; i++)
	{
		if (i >= 0 && i <= 2)
		{
			posboat[i].y = 1010;//360
		}
		if (i >= 3 && i <= 5)
		{
			posboat[i].y = 2625.0f;//360
		}
		if (i >= 6 && i <= 8)
		{
			posboat[i].y = 4092.5f;//360
		}
	}
	posboat[0].x = -200; posboat[1].x = -600; posboat[2].x = -1000;
	posboat[3].x = -200; posboat[4].x = -600; posboat[5].x = -1000;
	posboat[6].x = -200; posboat[7].x = -600; posboat[8].x = -1000;
	sf::RectangleShape boat2(sf::Vector2f(120.0f, 62.5f));//120
	boat2.setFillColor(sf::Color::Transparent);//Blue
	sf::Vector2f posboat2[9];
	for (i = 0; i <= 8; i++)
	{
		if (i >= 0 && i <= 2)
		{
			posboat2[i].y = 1072.5f;//360
		}
		if (i >= 3 && i <= 5)
		{
			posboat2[i].y = 2562.5f;//360
		}
		if (i >= 6 && i <= 8)
		{
			posboat2[i].y = 4217.5f;//360
		}
	}
	posboat2[0].x = 1080; posboat2[1].x = 1500; posboat2[2].x = 1820;
	posboat2[3].x = 1080; posboat2[4].x = 1500; posboat2[5].x = 1820;
	posboat2[6].x = 1080; posboat2[7].x = 1500; posboat2[8].x = 1820;

	sf::RectangleShape boat3(sf::Vector2f(300.0f, 62.5f));//300
	boat3.setFillColor(sf::Color::Transparent);//Black
	boat3.setPosition(1150, 485.0f);//485.0
	sf::Vector2f posboat3[6];
	for (i = 0; i <= 5; i++)
	{
		if (i >= 0 && i <= 1)
		{
			posboat3[i].y = 1135.0f;//485.0f
		}
		if (i >= 2 && i <= 3)
		{
			posboat3[i].y = 2500.0f;//485.0f
		}
		if (i >= 4 && i <= 5)
		{
			posboat3[i].y = 4155.0f;//485.0f
		}
	}
	posboat3[0].x = -300; posboat3[1].x = -900;
	posboat3[2].x = -300; posboat3[3].x = -900;
	posboat3[4].x = -300; posboat3[5].x = -900;
	sf::RectangleShape boat4(sf::Vector2f(240.0f, 62.5f));//225.f
	boat4.setFillColor(sf::Color::Transparent);//White Transparent
	sf::Vector2f posboat4[6];
	for (i = 0; i <= 5; i++)
	{
		if (i >= 0 && i <= 1)
		{
			posboat4[i].y = 1197.5f;//547.5
		}
		if (i >= 2 && i <= 3)
		{
			posboat4[i].y = 2687.5f;//547.5
		}
		if (i >= 4 && i <= 5)
		{
			posboat4[i].y = 4030;//547.5
		}
	}
	posboat4[0].x = 1200; posboat4[1].x = 2200;
	posboat4[2].x = 1200; posboat4[3].x = 2200;
	posboat4[4].x = 1200; posboat4[5].x = 2200;

	sf::Sprite sushiyelloworangered;
	sf::Texture texturesushiyelloworangered;
	texturesushiyelloworangered.loadFromFile("sushiyelloworangered.png");
	texturesushiyelloworangered.setSmooth(true);
	sushiyelloworangered.setTexture(texturesushiyelloworangered);
	sushiyelloworangered.setTextureRect(sf::IntRect(0.0f, 0.0f, 200.f, 63.f));
	sushiyelloworangered.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite duosushi;
	sf::Texture textureduosushi;
	textureduosushi.loadFromFile("duosushi.png");
	textureduosushi.setSmooth(true);
	duosushi.setTexture(textureduosushi);
	duosushi.setTextureRect(sf::IntRect(0.0f, 0.0f, 120.f, 63.f));
	duosushi.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite mixsuhi;
	sf::Texture texturemixsushi;
	texturemixsushi.loadFromFile("mixsushi.png");
	texturemixsushi.setSmooth(true);
	mixsuhi.setTexture(texturemixsushi);
	mixsuhi.setTextureRect(sf::IntRect(0.0f, 0.0f, 300.f, 63.f));
	mixsuhi.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite uniship;
	sf::Texture textureuni;
	textureuni.loadFromFile("uni.png");
	textureuni.setSmooth(true);
	uniship.setTexture(textureuni);
	uniship.setTextureRect(sf::IntRect(0.0f, 0.0f, 242.f, 63.f));
	uniship.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite sushiboat;
	sf::Texture textureusushiboat;
	textureusushiboat.loadFromFile("sushiboat.png");
	textureusushiboat.setSmooth(true);
	sushiboat.setTexture(textureusushiboat);
	sushiboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 120.f, 63.f));
	sushiboat.setScale(sf::Vector2f(1.1f, 1.2f));

	sf::Sprite woodpae;
	sf::Texture textureuwoodpae;
	textureuwoodpae.loadFromFile("boat.png");
	textureuwoodpae.setSmooth(true);
	woodpae.setTexture(textureuwoodpae);
	woodpae.setTextureRect(sf::IntRect(0.0f, 0.0f, 212.f, 63.f));
	woodpae.setScale(sf::Vector2f(1.415094339622642f, 1.0f));

	sf::Sprite zeldaboat;
	sf::Texture texturezeldaboat;
	texturezeldaboat.loadFromFile("zeldaboat.png");
	texturezeldaboat.setSmooth(true);
	zeldaboat.setTexture(texturezeldaboat);
	zeldaboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 200.f, 63.f));
	zeldaboat.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite fishboat;
	sf::Texture texturefishboat;
	texturefishboat.loadFromFile("dog3jellygreen.png");
	texturefishboat.setSmooth(true);
	fishboat.setTexture(texturefishboat);
	fishboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 240.f, 63.f));
	fishboat.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite crocodileboat;
	sf::Texture texturecrocodile;
	texturecrocodile.loadFromFile("dogbubble.png");
	texturecrocodile.setSmooth(true);
	crocodileboat.setTexture(texturecrocodile);
	crocodileboat.setTextureRect(sf::IntRect(0.0f, 0.0f, 300.f, 63.f));
	crocodileboat.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::Sprite woodlogboat2;
	sf::Texture texturewoodlogboat2;
	texturewoodlogboat2.loadFromFile("woodlog2.png");
	texturewoodlogboat2.setSmooth(true);
	woodlogboat2.setTexture(texturewoodlogboat2);
	woodlogboat2.setTextureRect(sf::IntRect(0.0f, 0.0f, 240.f, 63.f));
	woodlogboat2.setScale(sf::Vector2f(1.00f, 1.0f));

	sf::Sprite dogpizza;
	sf::Texture texturedogpizza;
	texturedogpizza.loadFromFile("dogpizza.png");
	texturedogpizza.setSmooth(true);
	dogpizza.setTexture(texturedogpizza);
	dogpizza.setTextureRect(sf::IntRect(0.0f, 0.0f, 240.f, 63.f));
	dogpizza.setScale(sf::Vector2f(0.8333333333333333f, 1.0f));

	sf::Sprite dogham;
	sf::Texture texturedogham;
	texturedogham.loadFromFile("submarine.png");
	texturedogham.setSmooth(true);
	dogham.setTexture(texturedogham);
	dogham.setTextureRect(sf::IntRect(0.0f, 0.0f, 120.f, 63.f));
	dogham.setScale(sf::Vector2f(1.12f, 1.0f));

	sf::RectangleShape itemclock(sf::Vector2f(40.f, 40.f));
	sf::Texture textureclock;
	textureclock.loadFromFile("clock.png");
	itemclock.setTexture(&textureclock);
	textureclock.setSmooth(true);
	itemclock.setPosition(rand() % 1050, rand() % 700);
	itemclock.setScale(sf::Vector2f(1.0f, 1.0f));
	sf::Vector2f posclock[3];
	for (i = 0; i <= 2; i++)
	{
		posclock[i].x = rand() % 1000;
		while (true)
		{
			posclock[i].y = rand() % 4900;
			if (posclock[i].y > 100.0f)
			{
				break;
			}
		}

	}
	
	sf::RectangleShape itemboots(sf::Vector2f(40.f, 40.f));
	sf::Texture textureboots;
	textureboots.loadFromFile("boots.png");
	itemboots.setTexture(&textureboots);
	textureboots.setSmooth(true);
	sf::Vector2f posboots[3];
	for (i = 0; i <= 1; i++)
	{
		posboots[i].x = rand() % 1000;
		while (true)
		{
			posboots[i].y = rand() % 4900;
			if (posboots[i].y > 100.0f)
			{
				break;
			}
		}
	}
	itemboots.setScale(sf::Vector2f(1.1f, 1.1f));

	bool flip = 0;
	int framebeer = 0;
	int totalbeer=0;
	sf::Texture texturebeer;
	texturebeer.loadFromFile("beer2.png");
	sf::Sprite beersp[20];
	sf::Vector2f posbeer;
	for (totalbeer = 0; totalbeer < 20; totalbeer++)
	{
		beersp[totalbeer].setTexture(texturebeer);
		beersp[totalbeer].setTextureRect(sf::IntRect(0.0f, 0.0f, 200.f, 200.f));
		beersp[totalbeer].setScale(0.2f, 0.2f);
		for (i = 0; i <20; i++)
		{
			posbeer.x = rand() % 1000;
			while (true)
			{
				posbeer.y = rand() % 4900;
				if (posbeer.y > 100.0f)
				{
					beersp[i].setPosition(posbeer.x, posbeer.y);
					break;
				}
			}
		}
	}


	sf::Sprite itemcoins;
	sf::Texture texturecoins;
	texturecoins.loadFromFile("coinscut.png");
	texturecoins.setSmooth(true);
	itemcoins.setTexture(texturecoins);
	itemcoins.setTextureRect(sf::IntRect(0, 0, 128.f, 129));
	itemcoins.setScale(sf::Vector2f(0.275f, 0.295f));
	sf::Vector2f poscoins[26];
	for (i = 0; i <= 24; i++)
	{
		poscoins[i].x = rand() % 1000;
		while (true)
		{
			poscoins[i].y = rand() % 4900;
			if (poscoins[i].y > 100.0f)
			{
				break;
			}
		}
	}

	//texture car
	sf::Sprite carwhitesp;
	sf::Sprite cargreensp;
	sf::Sprite carredsp;
	sf::Sprite caryellowsp;
	sf::Sprite carbluesp;
	sf::Texture texturecar;
	texturecar.loadFromFile("carsptext.png");
	//texturecar.setSmooth(true);
	carredsp.setTexture(texturecar);
	caryellowsp.setTexture(texturecar);
	carbluesp.setTexture(texturecar);
	carwhitesp.setTexture(texturecar);
	cargreensp.setTexture(texturecar);
	//carsp.setTextureRect(sf::IntRect(0, 0, 120.f, 65.0f));
	carwhitesp.setTextureRect(sf::IntRect(492, 18, 82.f, 58.0f));
	carredsp.setTextureRect(sf::IntRect(20, 203, 139.f, 74.0f));
	caryellowsp.setTextureRect(sf::IntRect(20, 25, 63.f, 52.0f));
	carbluesp.setTextureRect(sf::IntRect(353, 101, 87.f, 65.0f));
	cargreensp.setTextureRect(sf::IntRect(584, 101, 92.f, 65.0f));
	//carsp.setScale(sf::Vector2f(1.0f, 1.0f));

	sf::RectangleShape platmid(sf::Vector2f(1080.0f, 50.0f));//200
	platmid.setFillColor(sf::Color::Cyan);
	sf::Vector2f posplatmid[4];
	for (i = 0; i <= 3; i++)
	{
		if (i == 0)
		{
			posplatmid[i].y = 390.0f;//360
		}
		if (i == 1)
		{
			posplatmid[i].y = 755.0f;//360
		}
		if (i == 2)
		{
			posplatmid[i].y = 1845.0f;//360
		}
		if (i == 3)
		{
			posplatmid[i].y = 3335.0f;//360
		}
	}

	sf::RectangleShape endPointbox(sf::Vector2f(60, 60));
	endPointbox.setFillColor(sf::Color::Green);
	endPointbox.setPosition(520, 4850);

	sf::RectangleShape tpbox(sf::Vector2f(90, 90));
	tpbox.setFillColor(sf::Color::Blue);
	tpbox.setPosition(505, 4820);
	sf::Texture tpeff;
	tpeff.loadFromFile("tptx.png");
	sf::Sprite tpsp;
	tpsp.setTexture(tpeff);
	tpsp.setScale(1.3f, 1.3f);
	tpsp.setPosition(493, 4805);


	sf::RectangleShape hitboxTrain(sf::Vector2f(4320, 350));
	hitboxTrain.setFillColor(sf::Color::White);
	hitboxTrain.setPosition(-4520, findPosCarY(hitboxTrain, hitboxTrain.getPosition().y));//-4320
	sf::Texture texturetrain;
	texturetrain.loadFromFile("traintext.png");
	hitboxTrain.setTexture(&texturetrain);

	sf::RectangleShape signTrain(sf::Vector2f(100.0f, 100.0f));
	signTrain.setFillColor(sf::Color::Green);
	sf::Vector2f possign[3];
	sf::Texture texturesign;
	texturesign.loadFromFile("danger2.jpg");
	signTrain.setTexture(&texturesign);
	//signTrain.setScale(0.0769230769230769f, 0.0769230769230769f);


	sf::Font fontscore;
	fontscore.loadFromFile("fonttext/GOTHICB.ttf");

	sf::Font bit8;
	bit8.loadFromFile("fonttext/8-BIT WONDER.ttf");

	sf::Text highscoretext;
	highscoretext.setFont(bit8);
	highscoretext.setCharacterSize(20);
	highscoretext.setString("Highscore 0");
	highscoretext.setOutlineColor(sf::Color::Black);
	highscoretext.setOutlineThickness(2);

	sf::Text scoretext;
	scoretext.setFont(bit8);
	scoretext.setCharacterSize(20);
	scoretext.setString("Score 0");
	scoretext.setOutlineColor(sf::Color::Black);
	scoretext.setOutlineThickness(2);

	sf::Text shoetext;
	shoetext.setFont(bit8);
	shoetext.setCharacterSize(20);
	shoetext.setString("Shoes 0");
	shoetext.setOutlineColor(sf::Color::Black);
	shoetext.setOutlineThickness(2);
	sf::Text cointext;
	cointext.setFont(bit8);
	cointext.setCharacterSize(20);
	cointext.setString("Shoes 0");
	cointext.setOutlineColor(sf::Color::Black);
	cointext.setOutlineThickness(2);

	sf::Text nameplayerDisplay;
	nameplayerDisplay.setFont(bit8);
	nameplayerDisplay.setCharacterSize(20);
	nameplayerDisplay.setOutlineColor(sf::Color::Black);
	nameplayerDisplay.setOutlineThickness(2);

	int distance;

	window.setFramerateLimit(60);
	//white
	sf::Vector2f poswhite[6][4];
	for (a = 0; a <= 5; a++)
	{
		whitex[a].checkside = rand() % 2;
		if (whitex[a].checkside == 0)
		{
			whitex[a].checkside = 1;
			for (i = 0; i <= 3; i++)
			{
				if (a == 0)
				{
					poswhite[a][i].x = -120 - (540 * i);
					poswhite[a][i].y = 295;
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
				if (a == 1)
				{
					poswhite[a][i].x = -120 - (540 * i);
					poswhite[a][i].y = 1370;
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
				if (a == 2)
				{
					poswhite[a][0].x = -120; poswhite[a][1].x = -320; poswhite[a][2].x = -530; poswhite[a][3].x = -750;
					poswhite[a][i].y = 2305;//2115
				}
				if (a == 3)
				{
					poswhite[a][0].x = -120; poswhite[a][1].x = -320; poswhite[a][2].x = -530; poswhite[a][3].x = -750;
					poswhite[a][i].y = 3050;//3050
				}
				if (a == 4)
				{
					poswhite[a][i].x = -120 - (540 * i);
					poswhite[a][i].y = 3605;
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
				if (a == 5)
				{
					poswhite[a][i].x = -120 - (540 * i);
					poswhite[a][i].y = 4400;
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
			}
		}
		else
		{
			whitex[a].checkside = -1;
			for (i = 0; i <= 3; i++)
			{
				if (a == 0)
				{
					poswhite[a][i].x = 1080 + (540 * i);
					poswhite[a][i].y = 295;
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
				if (a == 1)
				{
					poswhite[a][i].x = 1080 + (540 * i);
					poswhite[a][i].y = 1370;//470
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
				if (a == 2)
				{
					poswhite[a][0].x = 1080; poswhite[a][1].x = 1280; poswhite[a][2].x = 1490; poswhite[a][3].x = 1710;
					poswhite[a][i].y = 2305;//2115
				}
				if (a == 3)
				{
					poswhite[a][0].x = 1080; poswhite[a][1].x = 1280; poswhite[a][2].x = 1490; poswhite[a][3].x = 1710;
					poswhite[a][i].y = 3050;//3050
				}
				if (a == 4)
				{
					poswhite[a][i].x = 1080 + (540 * i);
					poswhite[a][i].y = 3605;
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
				if (a == 5)
				{
					poswhite[a][i].x = 1080 + (540 * i);
					poswhite[a][i].y = 4400;
					if (i == 3)
					{
						poswhite[a][i].y = -99;
					}
				}
			}
		}
	}

	//green
	sf::Vector2f posgreen[4][3];
	for (a = 0; a <= 3; a++)
	{
		greenx[a].checkside = rand() % 2;
		if (greenx[a].checkside == 0)
		{
			greenx[a].checkside = 1;
			for (i = 0; i <= 2; i++)
			{
				posgreen[a][0].x = -120;
				posgreen[a][1].x = -350;
				posgreen[a][2].x = -900;
				if (a == 0)
				{
					posgreen[a][i].y = 1560;//1370
				}
				if (a == 1)
				{
					posgreen[a][i].y = 2210;//1465
				}
				if (a == 2)
				{
					posgreen[a][i].y = 2955;
				}
				if (a == 3)
				{
					posgreen[a][i].y = 3415;
				}
			}
		}
		else
		{
			greenx[a].checkside = -1;
			for (i = 0; i <= 2; i++)
			{
				posgreen[a][0].x = 1200;
				posgreen[a][1].x = 1430;
				posgreen[a][2].x = 1980;
				if (a == 0)
				{
					posgreen[a][i].y = 1560;//1370
				}
				if (a == 1)
				{
					posgreen[a][i].y = 2210;//1465
				}
				if (a == 2)
				{
					posgreen[a][i].y = 2955;
				}
				if (a == 3)
				{
					posgreen[a][i].y = 3415;
				}
			}
		}
	}

	//red
	sf::Vector2f posred[7][3];
	for (a = 0; a <= 6; a++)
	{
		redx[a].checkside = rand() % 2;
		if (redx[a].checkside == 0)
		{
			redx[a].checkside = 1;
			for (i = 0; i <= 2; i++)
			{
				posred[a][i].x = -200 - (540 * i);
				if (a == 0)
				{
					posred[a][i].y = 660;
				}
				if (a == 1)
				{
					posred[a][i].y = 835;
				}
				if (a == 2)
				{
					posred[a][i].y = 1925;
				}
				if (a == 3)
				{
					posred[a][i].y = 2020;
				}
				if (a == 4)
				{
					posred[a][i].y = 3145;
				}
				if (a == 5)
				{
					posred[a][i].y = 3795;
				}
				if (a == 6)
				{
					posred[a][i].y = 4590;
				}
			}
		}
		else
		{
			redx[a].checkside = -1;
			for (i = 0; i <= 2; i++)
			{
				posred[a][i].x = 1080 + (540 * i);
				if (a == 0)
				{
					posred[a][i].y = 660;
				}
				if (a == 1)
				{
					posred[a][i].y = 835;
				}
				if (a == 2)
				{
					posred[a][i].y = 1925;
				}
				if (a == 3)
				{
					posred[a][i].y = 2020;
				}
				if (a == 4)
				{
					posred[a][i].y = 3145;
				}
				if (a == 5)
				{
					posred[a][i].y = 3795;
				}
				if (a == 6)
				{
					posred[a][i].y = 4590;
				}
			}
		}
	}

	//yellow
	sf::Vector2f posyellow[6][4];
	for (a = 0; a <= 5; a++)
	{
		yellowx[a].checkside = rand() % 2;
		if (yellowx[a].checkside == 0)
		{
			yellowx[a].checkside = 1;
			for (i = 0; i <= 3; i++)
			{
				if (a == 0)
				{
					posyellow[a][i].x = -190 - (800 * i);
					posyellow[a][i].y = 470;//1370
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 1)
				{
					posyellow[a][i].x = -190 - (800 * i);
					posyellow[a][i].y = 1465;//1465
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 2)
				{
					posyellow[a][i].x = -190 - (800 * i);
					posyellow[a][i].y = 1655;
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 3)
				{
					posyellow[a][i].x = -190 - (800 * i);
					posyellow[a][i].y = 2115;//2305
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 4)
				{
					posyellow[a][i].x = -190 - (800 * i);
					posyellow[a][i].y = 3240;//2305
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 5)
				{
					posyellow[a][0].x = -120; posyellow[a][1].x = -400; posyellow[a][2].x = -610; posyellow[a][3].x = -830;
					posyellow[a][i].y = 3700;
				}
			}
		}
		else
		{
			yellowx[a].checkside = -1;
			for (i = 0; i <= 3; i++)
			{
				if (a == 0)
				{
					posyellow[a][i].x = 1180 + (540 * i);
					posyellow[a][i].y = 470;//1370
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 1)
				{
					posyellow[a][i].x = 1180 + (540 * i);
					posyellow[a][i].y = 1465;//1465
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 2)
				{
					posyellow[a][i].x = 1180 + (540 * i);
					posyellow[a][i].y = 1655;
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 3)
				{
					posyellow[a][i].x = 1180 + (540 * i);
					posyellow[a][i].y = 2115;//2305
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 4)
				{
					posyellow[a][i].x = 1180 + (540 * i);
					posyellow[a][i].y = 3240;//2305
					if (i >= 3)
					{
						posyellow[a][i].y = -99;
					}
				}
				if (a == 5)
				{
					posyellow[a][0].x = 1080; posyellow[a][1].x = 1360; posyellow[a][2].x = 1570; posyellow[a][3].x = 1790;
					posyellow[a][i].y = 3700;
				}
			}
		}
	}

	//blue
	sf::Vector2f posblue[6][3];
	for (a = 0; a <= 5; a++)
	{
		bluex[a].checkside = rand() % 2;
		if (bluex[a].checkside == 0)
		{
			bluex[a].checkside = 1;
			for (i = 0; i <= 2; i++)
			{
				posblue[a][i].x = -120 - (540 * i);
				if (a == 0)
				{
					posblue[a][i].y = 200;
				}
				if (a == 1)
				{
					posblue[a][i].y = 565;
				}
				if (a == 2)
				{
					posblue[a][i].y = 1750;
				}
				if (a == 3)
				{
					posblue[a][i].y = 2860;
				}
				if (a == 4)
				{
					posblue[a][i].y = 3510;
				}
				if (a == 5)
				{
					posblue[a][i].y = 4495;
				}
			}
		}
		else
		{
			bluex[a].checkside = -1;
			for (i = 0; i <= 2; i++)
			{
				posblue[a][i].x = 1080 + (540 * i);
				if (a == 0)
				{
					posblue[a][i].y = 200;
				}
				if (a == 1)
				{
					posblue[a][i].y = 565;
				}
				if (a == 2)
				{
					posblue[a][i].y = 1750;
				}
				if (a == 3)
				{
					posblue[a][i].y = 2860;
				}
				if (a == 4)
				{
					posblue[a][i].y = 3510;
				}
				if (a == 5)
				{
					posblue[a][i].y = 4495;
				}
			}
		}
	}
	sf::Clock clock;
	sf::Time durationslow;
	sf::Time coin;
	sf::Clock animationcoin;
	sf::Time waterTime;
	sf::Clock animationwater;
	sf::Time immue;
	sf::Clock immueclock;
	sf::Time signTime;
	sf::Clock signclock;
	sf::Clock animationplayer;
	sf::Time playerchange;
	sf::Clock clockstandTp;
	sf::Time standTp;
	sf::Clock animationtp;
	sf::Time tptime;
	int signNotification = 0;
	int trainrunning = 0;
	bool realspawn = 0;
	sf::Time spawnTrain;
	sf::Clock trainclock;
	sf::Clock dieclock;
	sf::Time dieTime;
	sf::Clock beerclockframe;
	sf::Time beerTimeframe;
	sf::Clock beerclcok;
	sf::Time beerTime;

	

	sf::SoundBuffer effectcarcrash;
	effectcarcrash.loadFromFile("carcrash1.wav");
	sf::Sound carcrash1;
	carcrash1.setBuffer(effectcarcrash);
	carcrash1.setVolume(50);

	sf::SoundBuffer effectcarcrash2;
	effectcarcrash2.loadFromFile("carcrash2.wav");
	sf::Sound carcrash2;
	carcrash2.setBuffer(effectcarcrash2);
	carcrash2.setVolume(50);

	sf::SoundBuffer effectcarcrash3;
	effectcarcrash3.loadFromFile("carcrash3.wav");
	sf::Sound carcrash3;
	carcrash3.setBuffer(effectcarcrash3);
	carcrash3.setVolume(50);

	sf::SoundBuffer effectcarcrash4;
	effectcarcrash4.loadFromFile("carcrash4.wav");
	sf::Sound carcrash4;
	carcrash4.setBuffer(effectcarcrash4);
	carcrash4.setVolume(50);

	sf::SoundBuffer effectcarcrash5;
	effectcarcrash5.loadFromFile("carcrash5.wav");
	sf::Sound carcrash5;
	carcrash5.setBuffer(effectcarcrash5);
	carcrash5.setVolume(50);

	sf::SoundBuffer effectalert;
	effectalert.loadFromFile("alertcross2.wav");
	sf::Sound alert;
	alert.setBuffer(effectalert);
	alert.setVolume(50);

	sf::SoundBuffer effectrain;
	effectrain.loadFromFile("traineff2.wav");
	sf::Sound trainSound;
	trainSound.setBuffer(effectrain);
	trainSound.setVolume(100);

	sf::SoundBuffer effecoin;
	effecoin.loadFromFile("coineff2.wav");
	sf::Sound coinSound;
	coinSound.setBuffer(effecoin);
	coinSound.setVolume(100);

	sf::SoundBuffer effeboots;
	effeboots.loadFromFile("bootseff2.wav");
	sf::Sound bootsSound;
	bootsSound.setBuffer(effeboots);
	bootsSound.setVolume(100);

	sf::SoundBuffer effeclock;
	effeclock.loadFromFile("clockeff2.wav");
	sf::Sound clockSound;
	clockSound.setBuffer(effeclock);
	clockSound.setVolume(100);

	int effectSoundCrash = 9;

	sf::Music music;
	if (!music.openFromFile("soundsonicbg2.wav"))
		return -1; // error
	music.setVolume(100);//60
	music.setLoop(true);


	sf::SoundBuffer effecfootstep;
	effecfootstep.loadFromFile("footsteps111.wav");
	sf::Sound footSound;
	footSound.setBuffer(effecfootstep);
	footSound.setVolume(20);
	footSound.setLoop(true);

	sf::RectangleShape mapbox(sf::Vector2f(1080.f, 4955.f));
	sf::Texture texturemap;
	texturemap.loadFromFile("map.png");
	mapbox.setTexture(&texturemap);
	//texturemap.setSmooth(true);

	Pausemenu pausemenu(window.getSize().x, window.getSize().y, positionview.x, positionview.y);
	Menu endMenu(window.getSize().x, window.getSize().y, positionview.x, positionview.y);


	sf::Font gOTHICB;
	gOTHICB.loadFromFile("fonttext/GOTHICB.ttf");


	Textbox textbox1(40, sf::Color::White, false, sf::Color::Black, 3);
	textbox1.setFont(bit8);
	textbox1.setPosition({ 700,270 });
	textbox1.setLimit(true, 5);

	Textbox leaderText(120, sf::Color::White, true, sf::Color::Black, 3);
	leaderText.setFont(bit8);
	leaderText.setPosition({ 230,50 });
	leaderText.setLimit(true, 5);
	Textbox scoreLeaderText(110, sf::Color::White, true, sf::Color::Black, 3);
	scoreLeaderText.setFont(bit8);
	scoreLeaderText.setPosition({ 500,200 });
	scoreLeaderText.setLimit(true, 5);

	Textbox no2Text(40, sf::Color::White, true, sf::Color::Black, 3);
	no2Text.setFont(bit8);
	no2Text.setPosition({ 530,380 });
	no2Text.setLimit(true, 5);
	Textbox scoreno2Text(40, sf::Color::White, true, sf::Color::Black, 3);
	scoreno2Text.setFont(bit8);
	scoreno2Text.setPosition({ 800,380 });
	scoreno2Text.setLimit(true, 5);

	Textbox no3Text(40, sf::Color::White, true, sf::Color::Black, 3);
	no3Text.setFont(bit8);
	no3Text.setPosition({ 530,470 });
	no3Text.setLimit(true, 5);
	Textbox scoreno3Text(40, sf::Color::White, true, sf::Color::Black, 3);
	scoreno3Text.setFont(bit8);
	scoreno3Text.setPosition({ 800,470 });
	scoreno3Text.setLimit(true, 5);

	Textbox no4Text(40, sf::Color::White, true, sf::Color::Black, 3);
	no4Text.setFont(bit8);
	no4Text.setPosition({ 530,560 });
	no4Text.setLimit(true, 5);
	Textbox scoreno4Text(40, sf::Color::White, true, sf::Color::Black, 3);
	scoreno4Text.setFont(bit8);
	scoreno4Text.setPosition({ 800,560 });
	scoreno4Text.setLimit(true, 5);

	Textbox no5Text(40, sf::Color::White, true, sf::Color::Black, 3);
	no5Text.setFont(bit8);
	no5Text.setPosition({ 530,650 });
	no5Text.setLimit(true, 5);
	Textbox scoreno5Text(40, sf::Color::White, true, sf::Color::Black, 3);
	scoreno5Text.setFont(bit8);
	scoreno5Text.setPosition({ 800,650 });
	scoreno5Text.setLimit(true, 5);


	Buttuon playButton("Play", { 160,40 }, 40, sf::Color::Transparent, sf::Color::White, sf::Color::Black, 3);
	playButton.setPosition({ 800,210 });
	playButton.setFont(bit8);
	playButton.setPositiontext({ 800,208 });


	Buttuon insertNameButton("Name", { 180,42 }, 40, sf::Color::Transparent, sf::Color::White, sf::Color::Black, 3);
	insertNameButton.setPosition({ 802,292 });
	insertNameButton.setFont(bit8);
	insertNameButton.setPositiontext({ 805,290 });

	Buttuon leaderboardButton("Leaderboard", { 385,40 }, 35, sf::Color::Transparent, sf::Color::White, sf::Color::Black, 3);
	leaderboardButton.setPosition({ 805,390 });
	leaderboardButton.setFont(bit8);
	leaderboardButton.setPositiontext({ 805,390 });

	Buttuon exitbutton("Exit", { 130,40 }, 40, sf::Color::Transparent, sf::Color::White, sf::Color::Black, 3);
	exitbutton.setPosition({ 798,472 });
	exitbutton.setFont(bit8);
	exitbutton.setPositiontext({ 798,470 });

	Buttuon backButtonlead("Back", { 130,30 }, 30, sf::Color::Green, sf::Color::White, sf::Color::Black, 3);
	backButtonlead.setPosition({ 95,672 });
	backButtonlead.setFont(bit8);
	backButtonlead.setPositiontext({ 100,670 });

	sf::Texture ledTexture;
	ledTexture.loadFromFile("leaderbg.png");
	sf::Sprite bgleader;
	bgleader.setTexture(ledTexture);

	char name[255];
	string userName[100];
	int userNum[100];
	vector<pair<int, string>> userScore;
	FILE* fptr;
	int index = 0;
	int lenstr;

	fptr = fopen("./bobo.txt", "r");
	if (fptr == NULL)
	{
		cout << "read";
	}
	for (index = 0; index < 5; index++)
	{
		
			fscanf(fptr, "%s", &name);
			userName[index] = name;
			fscanf(fptr, "%d", &userNum[index]);
			scoreLead[index] = userNum[index];
			scoreTextLead[index] = userName[index];
			userScore.push_back(make_pair(userNum[index], userName[index]));
		
	}
	fclose(fptr);
	
	while (window.isOpen())
	{

		//printf("%f\n", player.getPosition().y);
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			case ::sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::W && state == 0)
				{
					if (footSound.getStatus() != 2)
					{
						footSound.play();
					}
				}
				if (event.key.code == sf::Keyboard::S && state == 0)
				{
					if (footSound.getStatus() != 2)
					{
						footSound.play();
					}
				}
				if (event.key.code == sf::Keyboard::A && state == 0)
				{
					if (footSound.getStatus() != 2)
					{
						footSound.play();
					}
				}
				if (event.key.code == sf::Keyboard::D && state == 0)
				{
					if (footSound.getStatus() != 2)
					{
						footSound.play();
					}
				}
				if (event.key.code == sf::Keyboard::R && state == 0)
				{
					//slowtime = 0.1;//0.1
					if (allowDraw == 0)
					{
						allowDraw = 1;
						speed = 10;//2
					}
					else
					{
						allowDraw = 0;
						slowtime = 0.1;
						speed = 10;
						/*boat1.setFillColor(sf::Color::Transparent);//White Transparent
						boat2.setFillColor(sf::Color::Transparent);//White Transparent
						boat3.setFillColor(sf::Color::Transparent);//White Transparent
						boat4.setFillColor(sf::Color::Transparent);//White Transparent*/
					}

					hpbar = -30;
					checkcollintime = 0;
				}
				if (event.key.code == sf::Keyboard::W && (state == 2 || state == 3))
				{
					if (state == 2)
					{
						pausemenu.MoveUp();
						pausemenu.GetPressedItem();
					}
					if (state == 3)
					{

						endMenu.MoveUp();
						endMenu.GetPressedItem();
					}
				}
				if (event.key.code == sf::Keyboard::S && (state == 2 || state == 3))
				{
					if (state == 2)
					{
						pausemenu.MoveDown();
						pausemenu.GetPressedItem();
					}
					if (state == 3)
					{

						endMenu.MoveDown();
						endMenu.GetPressedItem();
					}
				}
				if (event.key.code == sf::Keyboard::Up && (state == 2 || state == 3))
				{
					if (state == 2)
					{
						pausemenu.MoveUp();
						pausemenu.GetPressedItem();
					}
					if (state == 3)
					{

						endMenu.MoveUp();
						endMenu.GetPressedItem();
					}
				}
				if (event.key.code == sf::Keyboard::Down && (state == 2 || state == 3))
				{
					if (state == 2)
					{
						pausemenu.MoveDown();
						pausemenu.GetPressedItem();
					}
					if (state == 3)
					{

						endMenu.MoveDown();
						endMenu.GetPressedItem();
					}
				}
				if (event.key.code == sf::Keyboard::Left && state == 3)
				{
					endMenu.MoveUp();
					endMenu.GetPressedItem();
				}
				if (event.key.code == sf::Keyboard::Right && state == 3)
				{
					endMenu.MoveDown();
					endMenu.GetPressedItem();
				}
				if (event.key.code == sf::Keyboard::Enter && state == 2 && pausemenu.GetPressedItem() == 0)
				{
					state = 0;
				}
				if (event.key.code == sf::Keyboard::Enter && state == 2 && pausemenu.GetPressedItem() == 1)
				{
					state = 1;
					repeat--;
				}
				if (event.key.code == sf::Keyboard::Enter && state == 3 && endMenu.GetPressedItem() == 0)
				{
					state = 0;
					restart = 1;
					openfile = 0;
				}
				if (event.key.code == sf::Keyboard::Enter && state == 3 && endMenu.GetPressedItem() == 1)
				{
					state = 1;
					openfile = 0;
				}
				break;
			case ::sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::W && state == 0)
				{
					footSound.pause();
				}
				if (event.key.code == sf::Keyboard::S && state == 0)
				{
					footSound.pause();
				}
				if (event.key.code == sf::Keyboard::A && state == 0)
				{
					footSound.pause();
				}
				if (event.key.code == sf::Keyboard::D && state == 0)
				{
					footSound.pause();
				}
				break;
			case::sf::Event::TextEntered:
				textbox1.typeOn(event);
				break;
			case::sf::Event::MouseMoved:
				playButton.isMouseOver(window);
				insertNameButton.isMouseOver(window);
				leaderboardButton.isMouseOver(window);
				exitbutton.isMouseOver(window);
				backButtonlead.isMouseOver(window);
				break;
			case sf::Event::MouseButtonPressed:
				if (state == 1)
				{
					if (playButton.isMouseOver(window))
					{
						if (state == 1 && (textbox1.getText() != "" && textbox1.getText() != " "))
						{
							restart = 1;
							state = 0;

						}
						else
						{
							insertNameButton.setTextColor(sf::Color(255, 30, 75, 255));
							state = 1;
						}
					}
					if (insertNameButton.isMouseOver(window))
					{
						if (clickinsername == 0)
						{
							textbox1.setSelected(true);
							clickinsername = 1;
							texttyping = 1;
						}
						else
						{
							textbox1.setColor(sf::Color(255,100, 5, 255));
							textbox1.setSelected(false);
							clickinsername = 0;
							//cout << userName[5];
							if (textbox1.getText() == "" || textbox1.getText() == " ")
							{
								textbox1.setColor(sf::Color::White);
								insertNameButton.setTextColor(sf::Color(255, 30, 75, 255));
								playButton.setTextColor(sf::Color::White);
								texttyping = 0;
							}
							else
							{
								playButton.setTextColor(sf::Color::Green);

							}

						}
					}
					if (leaderboardButton.isMouseOver(window))
					{
						if (state == 1)
						{
							insertNameButton.setTextColor(sf::Color::White);
							state = 4;
						}
					}
					if (exitbutton.isMouseOver(window))
					{
						window.close();
					}
				}
				if (state == 4)
				{
					if (backButtonlead.isMouseOver(window))
					{
						state = 1;
						openfile = 0;
					}
				}
				break;
			}
		}

		//cout << userName[5]<<'\n';
		if (state == 0)//playing
		{
			window.setMouseCursorVisible(false);
			if (restart == 1)
			{
				redchicken = 0;
				redchcikeny = 0;
				staminabar.setSize(sf::Vector2f(27.f, 241.0f ));
				die = 0;
				bloodsc.setPosition(-1080,-720);
				for (totalcrash = 0; totalcrash < 100; totalcrash++)
				{
					crashsp[totalcrash].setPosition(-99, -99);
				}
				checkcrasheffect=0;
				repeat++;
				cout <<'\n'<< "REPEAT " << repeat<<'\n';
				userName[5+repeat] = textbox1.getText();
				window.clear();
				highscoretext.setFillColor(sf::Color::White);
				highscoretext.setCharacterSize(20);
				chicksp.setPosition(player.getPosition().x - 18, player.getPosition().y - 20);
				chicksp.setScale(1.371428571428571f, 1.371428571428571f);
				speed = 1;
				slowtime = 1;
				checkslowtime = 0;
				stackshoes = 0; scorecoins = 0; restart = 0; tempdistance = 0; highDistance = 0; hpbar = 0; countcollin = 0; die = 0; countchecksign = 0;
				answer = 0;
				
				clock.restart();
				durationslow = sf::seconds(0.00f);
				coin = sf::seconds(0.00f);
				animationcoin.restart();
				waterTime = sf::seconds(0.00f);
				animationwater.restart();
				immue = sf::seconds(0.00f);
				immueclock.restart();
				signTime = sf::seconds(0.00f);
				signclock.restart();
				signNotification = 0;
				trainrunning = 0;
				realspawn = 0;
				spawnTrain = sf::seconds(0.00f);
				trainclock.restart();
				trainrunning = 0;
				animationplayer.restart();
				standTp = sf::seconds(0.00f);
				clockstandTp.restart();
				playerchange = sf::seconds(0.00f);
				animationtp.restart();
				dieclock.restart();
				dieTime = sf::seconds(0.00f);
				tptime = sf::seconds(0.00f);
				flip = 0;
				flipwalk = 1;
				beerclcok.restart();
				beerTime = sf::seconds(0.00f);
				player.setFillColor(sf::Color::Green);
				player.setPosition(spawnPoint);
				//reset purple
				for (i = 0; i <= 5; i++)
				{
					if (i == 0)
					{
						pospurple[0].x = 500.0f;
						pospurple[i].y = 755.0f;
						continue;
					}
					if (i >= 1 && i <= 2)
					{
						pospurple[1].x = 200.0f;
						pospurple[2].x = 800.0f;
						pospurple[i].y = 1845.0f;
						continue;
					}
					if (i >= 3 && i <= 5)
					{
						pospurple[3].x = 180.0f;
						pospurple[4].x = 490.0f;
						pospurple[5].x = 800.0f;
						pospurple[i].y = 3335.0f;
					}
				}

				//reset river
				for (i = 0; i <= 2; i++)
				{
					posriver[i].x = 0;
					if (i == 0)
					{
						posriver[i].y = 1010;//1000+10
					}
					if (i == 1)
					{
						posriver[i].y = 2500;
					}
					if (i == 2)
					{
						posriver[i].y = 4030;//4000+30
					}
					//1000 2500 4000
				}
				//reset boat
				for (i = 0; i <= 8; i++)
				{
					if (i >= 0 && i <= 2)
					{
						posboat[i].y = 1010;//360
					}
					if (i >= 3 && i <= 5)
					{
						posboat[i].y = 2625.0f;//360
					}
					if (i >= 6 && i <= 8)
					{
						posboat[i].y = 4092.5f;//360
					}
				}
				posboat[0].x = -200; posboat[1].x = -600; posboat[2].x = -1000;
				posboat[3].x = -200; posboat[4].x = -600; posboat[5].x = -1000;
				posboat[6].x = -200; posboat[7].x = -600; posboat[8].x = -1000;
				//reset boat2
				for (i = 0; i <= 8; i++)
				{
					if (i >= 0 && i <= 2)
					{
						posboat2[i].y = 1072.5f;//360
					}
					if (i >= 3 && i <= 5)
					{
						posboat2[i].y = 2562.5f;//360
					}
					if (i >= 6 && i <= 8)
					{
						posboat2[i].y = 4217.5f;//360
					}
				}
				posboat2[0].x = 1080; posboat2[1].x = 1500; posboat2[2].x = 1820;
				posboat2[3].x = 1080; posboat2[4].x = 1500; posboat2[5].x = 1820;
				posboat2[6].x = 1080; posboat2[7].x = 1500; posboat2[8].x = 1820;
				//reset boat3
				for (i = 0; i <= 5; i++)
				{
					if (i >= 0 && i <= 1)
					{
						posboat3[i].y = 1135.0f;//485.0f
					}
					if (i >= 2 && i <= 3)
					{
						posboat3[i].y = 2500.0f;//485.0f
					}
					if (i >= 4 && i <= 5)
					{
						posboat3[i].y = 4155.0f;//485.0f
					}
				}
				posboat3[0].x = -300; posboat3[1].x = -900;
				posboat3[2].x = -300; posboat3[3].x = -900;
				posboat3[4].x = -300; posboat3[5].x = -900;
				//reset boat4
				for (i = 0; i <= 5; i++)
				{
					if (i >= 0 && i <= 1)
					{
						posboat4[i].y = 1197.5f;//547.5
					}
					if (i >= 2 && i <= 3)
					{
						posboat4[i].y = 2687.5f;//547.5
					}
					if (i >= 4 && i <= 5)
					{
						posboat4[i].y = 4030;//547.5
					}
				}
				posboat4[0].x = 1200; posboat4[1].x = 2200;
				posboat4[2].x = 1200; posboat4[3].x = 2200;
				posboat4[4].x = 1200; posboat4[5].x = 2200;
				//reset clock
				for (i = 0; i <= 2; i++)
				{
					posclock[i].x = rand() % 1000;
					while (true)
					{
						posclock[i].y = rand() % 4900;
						if (posclock[i].y > 100.0f)
						{
							break;
						}
					}

				}
				//reset boots
				for (i = 0; i <= 1; i++)
				{
					posboots[i].x = rand() % 1000;
					while (true)
					{
						posboots[i].y = rand() % 4900;
						if (posboots[i].y > 100.0f)
						{
							break;
						}
					}
				}
				//reset coin
				for (i = 0; i <= 24; i++)
				{
					poscoins[i].x = rand() % 1000;
					while (true)
					{
						poscoins[i].y = rand() % 4900;
						if (poscoins[i].y > 100.0f)
						{
							break;
						}
					}
				}
				//rest plat mid
				for (i = 0; i <= 3; i++)
				{
					if (i == 0)
					{
						posplatmid[i].y = 390.0f;//360
					}
					if (i == 1)
					{
						posplatmid[i].y = 755.0f;//360
					}
					if (i == 2)
					{
						posplatmid[i].y = 1845.0f;//360
					}
					if (i == 3)
					{
						posplatmid[i].y = 3335.0f;//360
					}
				}
				//reset poswhite
				for (a = 0; a <= 5; a++)
				{
					whitex[a].checkside = rand() % 2;
					if (whitex[a].checkside == 0)
					{
						whitex[a].checkside = 1;
						for (i = 0; i <= 3; i++)
						{
							if (a == 0)
							{
								poswhite[a][i].x = -120 - (540 * i);
								poswhite[a][i].y = 295;
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
							if (a == 1)
							{
								poswhite[a][i].x = -120 - (540 * i);
								poswhite[a][i].y = 1370;
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
							if (a == 2)
							{
								poswhite[a][0].x = -120; poswhite[a][1].x = -320; poswhite[a][2].x = -530; poswhite[a][3].x = -750;
								poswhite[a][i].y = 2305;//2115
							}
							if (a == 3)
							{
								poswhite[a][0].x = -120; poswhite[a][1].x = -320; poswhite[a][2].x = -530; poswhite[a][3].x = -750;
								poswhite[a][i].y = 3050;//3050
							}
							if (a == 4)
							{
								poswhite[a][i].x = -120 - (540 * i);
								poswhite[a][i].y = 3605;
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
							if (a == 5)
							{
								poswhite[a][i].x = -120 - (540 * i);
								poswhite[a][i].y = 4400;
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
						}
					}
					else
					{
						whitex[a].checkside = -1;
						for (i = 0; i <= 3; i++)
						{
							if (a == 0)
							{
								poswhite[a][i].x = 1080 + (540 * i);
								poswhite[a][i].y = 295;
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
							if (a == 1)
							{
								poswhite[a][i].x = 1080 + (540 * i);
								poswhite[a][i].y = 1370;//470
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
							if (a == 2)
							{
								poswhite[a][0].x = 1080; poswhite[a][1].x = 1280; poswhite[a][2].x = 1490; poswhite[a][3].x = 1710;
								poswhite[a][i].y = 2305;//2115
							}
							if (a == 3)
							{
								poswhite[a][0].x = 1080; poswhite[a][1].x = 1280; poswhite[a][2].x = 1490; poswhite[a][3].x = 1710;
								poswhite[a][i].y = 3050;//3050
							}
							if (a == 4)
							{
								poswhite[a][i].x = 1080 + (540 * i);
								poswhite[a][i].y = 3605;
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
							if (a == 5)
							{
								poswhite[a][i].x = 1080 + (540 * i);
								poswhite[a][i].y = 4400;
								if (i == 3)
								{
									poswhite[a][i].y = -99;
								}
							}
						}
					}
				}

				//reset green
				for (a = 0; a <= 3; a++)
				{
					greenx[a].checkside = rand() % 2;
					if (greenx[a].checkside == 0)
					{
						greenx[a].checkside = 1;
						for (i = 0; i <= 2; i++)
						{
							posgreen[a][0].x = -120;
							posgreen[a][1].x = -350;
							posgreen[a][2].x = -900;
							if (a == 0)
							{
								posgreen[a][i].y = 1560;//1370
							}
							if (a == 1)
							{
								posgreen[a][i].y = 2210;//1465
							}
							if (a == 2)
							{
								posgreen[a][i].y = 2955;
							}
							if (a == 3)
							{
								posgreen[a][i].y = 3415;
							}
						}
					}
					else
					{
						greenx[a].checkside = -1;
						for (i = 0; i <= 2; i++)
						{
							posgreen[a][0].x = 1200;
							posgreen[a][1].x = 1430;
							posgreen[a][2].x = 1980;
							if (a == 0)
							{
								posgreen[a][i].y = 1560;//1370
							}
							if (a == 1)
							{
								posgreen[a][i].y = 2210;//1465
							}
							if (a == 2)
							{
								posgreen[a][i].y = 2955;
							}
							if (a == 3)
							{
								posgreen[a][i].y = 3415;
							}
						}
					}
				}

				//reset red
				for (a = 0; a <= 6; a++)
				{
					redx[a].checkside = rand() % 2;
					if (redx[a].checkside == 0)
					{
						redx[a].checkside = 1;
						for (i = 0; i <= 2; i++)
						{
							posred[a][i].x = -200 - (540 * i);
							if (a == 0)
							{
								posred[a][i].y = 660;
							}
							if (a == 1)
							{
								posred[a][i].y = 835;
							}
							if (a == 2)
							{
								posred[a][i].y = 1925;
							}
							if (a == 3)
							{
								posred[a][i].y = 2020;
							}
							if (a == 4)
							{
								posred[a][i].y = 3145;
							}
							if (a == 5)
							{
								posred[a][i].y = 3795;
							}
							if (a == 6)
							{
								posred[a][i].y = 4590;
							}
						}
					}
					else
					{
						redx[a].checkside = -1;
						for (i = 0; i <= 2; i++)
						{
							posred[a][i].x = 1080 + (540 * i);
							if (a == 0)
							{
								posred[a][i].y = 660;
							}
							if (a == 1)
							{
								posred[a][i].y = 835;
							}
							if (a == 2)
							{
								posred[a][i].y = 1925;
							}
							if (a == 3)
							{
								posred[a][i].y = 2020;
							}
							if (a == 4)
							{
								posred[a][i].y = 3145;
							}
							if (a == 5)
							{
								posred[a][i].y = 3795;
							}
							if (a == 6)
							{
								posred[a][i].y = 4590;
							}
						}
					}
				}

				//reset yellow
				for (a = 0; a <= 5; a++)
				{
					yellowx[a].checkside = rand() % 2;
					if (yellowx[a].checkside == 0)
					{
						yellowx[a].checkside = 1;
						for (i = 0; i <= 3; i++)
						{
							if (a == 0)
							{
								posyellow[a][i].x = -190 - (800 * i);
								posyellow[a][i].y = 470;//1370
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 1)
							{
								posyellow[a][i].x = -190 - (800 * i);
								posyellow[a][i].y = 1465;//1465
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 2)
							{
								posyellow[a][i].x = -190 - (800 * i);
								posyellow[a][i].y = 1655;
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 3)
							{
								posyellow[a][i].x = -190 - (800 * i);
								posyellow[a][i].y = 2115;//2305
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 4)
							{
								posyellow[a][i].x = -190 - (800 * i);
								posyellow[a][i].y = 3240;//2305
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 5)
							{
								posyellow[a][0].x = -120; posyellow[a][1].x = -400; posyellow[a][2].x = -610; posyellow[a][3].x = -830;
								posyellow[a][i].y = 3700;
							}
						}
					}
					else
					{
						yellowx[a].checkside = -1;
						for (i = 0; i <= 3; i++)
						{
							if (a == 0)
							{
								posyellow[a][i].x = 1180 + (540 * i);
								posyellow[a][i].y = 470;//1370
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 1)
							{
								posyellow[a][i].x = 1180 + (540 * i);
								posyellow[a][i].y = 1465;//1465
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 2)
							{
								posyellow[a][i].x = 1180 + (540 * i);
								posyellow[a][i].y = 1655;
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 3)
							{
								posyellow[a][i].x = 1180 + (540 * i);
								posyellow[a][i].y = 2115;//2305
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 4)
							{
								posyellow[a][i].x = 1180 + (540 * i);
								posyellow[a][i].y = 3240;//2305
								if (i >= 3)
								{
									posyellow[a][i].y = -99;
								}
							}
							if (a == 5)
							{
								posyellow[a][0].x = 1080; posyellow[a][1].x = 1360; posyellow[a][2].x = 1570; posyellow[a][3].x = 1790;
								posyellow[a][i].y = 3700;
							}
						}
					}
				}

				//reset blue
				for (a = 0; a <= 5; a++)
				{
					bluex[a].checkside = rand() % 2;
					if (bluex[a].checkside == 0)
					{
						bluex[a].checkside = 1;
						for (i = 0; i <= 2; i++)
						{
							posblue[a][i].x = -120 - (540 * i);
							if (a == 0)
							{
								posblue[a][i].y = 200;
							}
							if (a == 1)
							{
								posblue[a][i].y = 565;
							}
							if (a == 2)
							{
								posblue[a][i].y = 1750;
							}
							if (a == 3)
							{
								posblue[a][i].y = 2860;
							}
							if (a == 4)
							{
								posblue[a][i].y = 3510;
							}
							if (a == 5)
							{
								posblue[a][i].y = 4495;
							}
						}
					}
					else
					{
						bluex[a].checkside = -1;
						for (i = 0; i <= 2; i++)
						{
							posblue[a][i].x = 1080 + (540 * i);
							if (a == 0)
							{
								posblue[a][i].y = 200;
							}
							if (a == 1)
							{
								posblue[a][i].y = 565;
							}
							if (a == 2)
							{
								posblue[a][i].y = 1750;
							}
							if (a == 3)
							{
								posblue[a][i].y = 2860;
							}
							if (a == 4)
							{
								posblue[a][i].y = 3510;
							}
							if (a == 5)
							{
								posblue[a][i].y = 4495;
							}
						}
					}
				}

				//reset train
				hitboxTrain.setPosition(-4520, findPosCarY(hitboxTrain, hitboxTrain.getPosition().y)/*2534*/);
				restart = 0;
			}
			if (music.getStatus() != 2)
			{
				music.play();
			}
			//player move  //+ Collinsions *************************************************************
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))//2.5
			{
				player.move(0.f, -2.5f * speed*flipwalk);
				checksideplayer = 3;
				greenchicy = 0;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				player.move(0.f, 2.5f * speed*flipwalk);
				checksideplayer = 0;
				greenchicy = 3;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				player.move(-2.5f * speed*flipwalk, 0.0f);
				checksideplayer = 1;
				greenchicy = 2;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				player.move(2.5f * speed*flipwalk, 0.f);
				checksideplayer = 2;
				greenchicy = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				speed = 1;
				slowtime = 1;
				stackshoes = 0;
				/*boat1.setFillColor(sf::Color::Red);//White Transparent
				boat2.setFillColor(sf::Color::Blue);//White Transparent
				boat3.setFillColor(sf::Color::Black);//White Transparent
				boat4.setFillColor(sf::Color::White);//White Transparent*/
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				state = 2;
				continue;
			}
			//animation player
			playerchange = animationplayer.getElapsedTime();
			if (playerchange.asSeconds() > 0.15f)
			{
				if (framechicken <= 2)
				{
					chicksp.setTextureRect(sf::IntRect(((framechicken + redchicken) * 48.f) + 0.0f, ((checksideplayer + redchcikeny) * 48.f) + 0.0f, 48.f, 48.f));
					framechicken++;
					if (framechicken == 3)
					{
						framechicken = 0;
					}
				}
				animationplayer.restart();
			}
			//animation beer
			beerTimeframe = beerclockframe.getElapsedTime();
			if (beerTimeframe.asSeconds() > 0.25f)
			{
				if (framebeer <= 3)
				{
					for (i = 0; i < 20; i++)
					{
						beersp[i].setTextureRect(sf::IntRect(framebeer * 200.f, 0, 200.f, 200.f));
					}
					framebeer++;
					if (framebeer == 4)
					{
						framebeer = 0;
					}
				}
				beerclockframe.restart();
			}

			//animation coins
			coin = animationcoin.getElapsedTime();
			if (coin.asSeconds() > 0.15f)
			{
				if (frame <= 5)
				{
					itemcoins.setTextureRect(sf::IntRect(frame * 128.f, 0, 128.f, 129));
					frame++;
					if (frame == 6)
					{
						frame = 0;
					}
				}
				animationcoin.restart();
			}
			//animation water
			waterTime = animationwater.getElapsedTime();
			if (waterTime.asSeconds() > 0.0f)
			{
				if (framewater <= 6)
				{
					water.setTextureRect(sf::IntRect(frame * 1080.0f, 0, 1080.f, 250.0f));
					framewater++;
					if (framewater == 7)
					{
						framewater = 0;
					}
				}
				animationwater.restart();
			}
			//animation tp
			tptime = animationtp.getElapsedTime();
			if (tptime.asSeconds() > 0.05f)
			{
				if (frametp <= 12)
				{
					tpsp.setTextureRect(sf::IntRect((frametp * 90.f) + 0.0f, 0.0f, 90.f, 90.f));
					frametp++;
					if (frametp == 13)
					{
						frametp = 0;
					}
				}
				animationtp.restart();
			}
			positionview.y = player.getPosition().y + 10 - (screen.y / 2);
			positionview.x = 0;
			if (positionview.y < 0)
			{
				positionview.y = 0;
			}
			else if (player.getPosition().y >= 4585)
			{
				positionview.y = 4235;
			}
			view.reset(sf::FloatRect(positionview.x, positionview.y, screen.x, screen.y));

			//white
			for (a = 0; a <= 5; a++)
			{
				for (i = 0; i <= 3; i++)
				{
					if (whitex[a].checkside == 1)
					{
						if (poswhite[a][i].x > 1620)
						{
							poswhite[a][i].x = -120;
						}
						if (a == 0)//295
						{
							poswhite[a][i].x += (1.5f * slowtime * whitex[a].checkside);//1
						}
						if (a == 1)//1370
						{
							poswhite[a][i].x += (2.5f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 2)//2115
						{
							poswhite[a][i].x += (2.5f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 3)//3050
						{
							poswhite[a][i].x += (6.5f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 4)//3605
						{
							poswhite[a][i].x += (6.0f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 5)//4400
						{
							poswhite[a][i].x += (10.0f * slowtime * whitex[a].checkside);//-1
						}
					}
					else if (whitex[a].checkside == -1)
					{
						if (poswhite[a][i].x < -590)
						{
							poswhite[a][i].x = 1080;
						}
						if (a == 0)//295
						{
							poswhite[a][i].x += (1.5f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 1)//1370
						{
							poswhite[a][i].x += (2.5f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 2)//2115
						{
							poswhite[a][i].x += (2.5f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 3)//3050
						{
							poswhite[a][i].x += (6.5f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 4)//3605
						{
							poswhite[a][i].x += (6.0f * slowtime * whitex[a].checkside);//-1
						}
						if (a == 5)//4400
						{
							poswhite[a][i].x += (10.0f * slowtime * whitex[a].checkside);//-1
						}
					}
				}
			}
			//green
			for (a = 0; a <= 3; a++)
			{
				for (i = 0; i <= 2; i++)
				{
					if (greenx[a].checkside == 1)
					{
						if (posgreen[a][i].x > 1200)
						{
							posgreen[a][i].x = -120;
						}
						if (a == 0)//1560
						{
							posgreen[a][i].x += (2.5f * slowtime * greenx[a].checkside);//1
						}
						if (a == 1)//2210
						{
							posgreen[a][i].x += (2.8f * slowtime * greenx[a].checkside);//1
						}
						if (a == 2)//3000
						{
							posgreen[a][i].x += (7.8f * slowtime * greenx[a].checkside);//-1
						}
						if (a == 3)//3500
						{
							posgreen[a][i].x += (3.0f * slowtime * greenx[a].checkside);//-1
						}
					}
					else if (greenx[a].checkside == -1)
					{
						if (posgreen[a][i].x < -120)
						{
							posgreen[a][i].x = 1080;
						}
						if (a == 0)//1560
						{
							posgreen[a][i].x += (2.5f * slowtime * greenx[a].checkside);//-1
						}
						if (a == 1)//2210
						{
							posgreen[a][i].x += (2.8f * slowtime * greenx[a].checkside);//1
						}
						if (a == 2)//3000
						{
							posgreen[a][i].x += (7.8f * slowtime * greenx[a].checkside);//-1
						}
						if (a == 3)//3500
						{
							posgreen[a][i].x += (3.0f * slowtime * greenx[a].checkside);//-1
						}
					}
				}
			}
			//red
			for (a = 0; a <= 6; a++)
			{
				for (i = 0; i <= 2; i++)
				{
					if (redx[a].checkside == 1)
					{
						if (posred[a][i].x > 1620)
						{
							posred[a][i].x = -200;
						}
						if (a == 0)//660
						{
							posred[a][i].x += (2.0f * slowtime * redx[a].checkside);//1
						}
						if (a == 1)//835
						{
							posred[a][i].x += (5.0f * slowtime * redx[a].checkside);//-1
						}
						if (a == 2)//1925
						{
							posred[a][i].x += (6.27f * slowtime * redx[a].checkside);//-1
						}
						if (a == 3)//2020
						{
							posred[a][i].x += (6.5f * slowtime * redx[a].checkside);//-1
						}
						if (a == 4)//3145
						{
							posred[a][i].x += (7.5f * slowtime * redx[a].checkside);//-1
						}
						if (a == 5)//3795
						{
							posred[a][i].x += (8.0f * slowtime * redx[a].checkside);//-1
						}
						if (a == 6)//3795
						{
							posred[a][i].x += (17.0f * slowtime * redx[a].checkside);//-1
						}
					}
					else if (redx[a].checkside == -1)
					{
						if (posred[a][i].x < -590)
						{
							posred[a][i].x = 1080;
						}
						if (a == 0)//660
						{
							posred[a][i].x += (2.0f * slowtime * redx[a].checkside);//-1
						}
						if (a == 1)//835
						{
							posred[a][i].x += (5.0f * slowtime * redx[a].checkside);//-1
						}
						if (a == 2)//1925
						{
							posred[a][i].x += (6.5f * slowtime * redx[a].checkside);//-1
						}
						if (a == 3)//2020
						{
							posred[a][i].x += (6.15f * slowtime * redx[a].checkside);//-1
						}
						if (a == 4)//3145
						{
							posred[a][i].x += (7.5f * slowtime * redx[a].checkside);//-1
						}
						if (a == 5)//3795
						{
							posred[a][i].x += (8.0f * slowtime * redx[a].checkside);//-1
						}
						if (a == 6)//3795
						{
							posred[a][i].x += (17.0f * slowtime * redx[a].checkside);//-1
						}
					}
				}
			}
			//yellow
			for (a = 0; a <= 5; a++)
			{
				for (i = 0; i <= 3; i++)
				{
					if (yellowx[a].checkside == 1)
					{
						if (posyellow[a][i].x > 1080)
						{
							posyellow[a][i].x = -120;
						}
						if (a == 0)//470
						{
							posyellow[a][i].x += (1.2f * slowtime * yellowx[a].checkside);//1
						}
						if (a == 1)//1465
						{
							posyellow[a][i].x += (2.7f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 2)//1655
						{
							posyellow[a][i].x += (3.0f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 3)//2305
						{
							posyellow[a][i].x += (3.2f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 4)//3145
						{
							posyellow[a][i].x += (5.2f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 5)//3145
						{
							posyellow[a][i].x += (6.2f * slowtime * yellowx[a].checkside);//-1
						}
					}
					else if (yellowx[a].checkside == -1)
					{
						if (posyellow[a][i].x < -120)
						{
							posyellow[a][i].x = 1080;
						}
						if (a == 0)//470
						{
							posyellow[a][i].x += (1.2f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 1)//1465
						{
							posyellow[a][i].x += (2.7f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 2)//1655
						{
							posyellow[a][i].x += (3.0f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 3)//2305
						{
							posyellow[a][i].x += (3.2f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 4)//3145
						{
							posyellow[a][i].x += (5.2f * slowtime * yellowx[a].checkside);//-1
						}
						if (a == 5)//3145
						{
							posyellow[a][i].x += (6.2f * slowtime * yellowx[a].checkside);//-1
						}
					}
				}
			}

			//blue
			for (a = 0; a <= 5; a++)
			{
				for (i = 0; i <= 2; i++)
				{
					if (bluex[a].checkside == 1)
					{
						if (posblue[a][i].x > 1620)
						{
							posblue[a][i].x = -120;
						}
						if (a == 0)//200
						{
							posblue[a][i].x += (2.0f * slowtime * bluex[a].checkside);//1
						}
						if (a == 1)//565
						{
							posblue[a][i].x += (3.25f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 2)//1750
						{
							posblue[a][i].x += (2.0f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 3)//2860
						{
							posblue[a][i].x += (10.5f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 4)//3510
						{
							posblue[a][i].x += (10.5f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 5)//3510
						{
							posblue[a][i].x += (12.5f * slowtime * bluex[a].checkside);//-1
						}
					}
					else if (bluex[a].checkside == -1)
					{
						if (posblue[a][i].x < -590)
						{
							posblue[a][i].x = 1080;
						}
						if (a == 0)//200
						{
							posblue[a][i].x += (2.0f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 1)//565
						{
							posblue[a][i].x += (3.25f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 2)//1750
						{
							posblue[a][i].x += (2.0f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 3)//2860
						{
							posblue[a][i].x += (10.5f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 4)//3510
						{
							posblue[a][i].x += (10.5f * slowtime * bluex[a].checkside);//-1
						}
						if (a == 5)//3510
						{
							posblue[a][i].x += (12.5f * slowtime * bluex[a].checkside);//-1
						}
					}
				}
			}

			//Train+effect
			if (trainrunning == 1)
			{
				//Train

				for (i = 1; i <= 5; i++)
				{
					if (abs(player.getPosition().y - hitboxTrain.getPosition().y) < 100 || (abs(player.getPosition().y - (hitboxTrain.getPosition().y + hitboxTrain.getSize().y)) < 100))
					{
						trainSound.pause();
						trainSound.setVolume(100);
						if (trainSound.getStatus() != 2)
						{
							trainSound.play();
						}
						break;
					}
					if (changeVolumeSign(player.getPosition().y, hitboxTrain.getPosition().y, 100 + (i * 50), 50 + (i * 50), hitboxTrain.getSize().y))
					{
						trainSound.pause();
						trainSound.setVolume(100 - (10 * i));
						if (trainSound.getStatus() != 2)
						{
							trainSound.play();
						}
						break;
					}
				}
				if (hitboxTrain.getPosition().x > 1080)
				{
					trainSound.stop();
					spawnTrain = trainclock.getElapsedTime();
					if (spawnTrain.asSeconds() > 10.0f)//10.00f
					{
						hitboxTrain.setPosition(-4520, findPosCarY(hitboxTrain, hitboxTrain.getPosition().y)/*2534*/);//-4320
						trainrunning = 0;
						signNotification = 0;
						trainSound.stop();
						trainclock.restart();
					}
				}
				hitboxTrain.move(50.0f, 0.0f);
			}
			//Collinsion Train
			if (player.getGlobalBounds().intersects(hitboxTrain.getGlobalBounds()))
			{

				trainSound.stop();
				staminabar.setSize(sf::Vector2f(27.f, -1));
	

			}

			//signtrain
			if (trainrunning == 0)
			{
				for (i = 0; i <= 2; i++)
				{
					possign[i].x = 10;
					possign[i].y = hitboxTrain.getPosition().y + 10 + (116.67f * i);
				}
				for (i = 1; i <= 5; i++)
				{
					if (abs(player.getPosition().y - hitboxTrain.getPosition().y) < 100 || (abs(player.getPosition().y - (hitboxTrain.getPosition().y + hitboxTrain.getSize().y)) < 100))
					{
						alert.pause();
						alert.setVolume(50);
						if (alert.getStatus() != 2)
						{
							alert.play();
						}
						break;
					}
					if (changeVolumeSign(player.getPosition().y, hitboxTrain.getPosition().y, 100 + (i * 50), 50 + (i * 50), hitboxTrain.getSize().y))
					{
						alert.pause();
						alert.setVolume(50 - (10 * i));
						if (alert.getStatus() != 2)
						{
							alert.play();
						}
						break;
					}
				}
				signTime = signclock.getElapsedTime();
				if (signTime.asSeconds() > 0.8f)
				{
					signTrain.setFillColor(sf::Color::Transparent);
					if (signTime.asSeconds() > 1.6f)
					{
						signTrain.setFillColor(sf::Color::Red);
						signNotification += 1;
						if (signNotification == 5)
						{
							trainrunning = 1;//1
							alert.stop();
							trainclock.restart();
						}

						signclock.restart();
					}
				}
			}

			//hitboxTrain.setPosition(-4210, 50);//-4320
			//hitboxTrain.move(50.0f, 0.0f);

			//Collinsion car
			if (checkcollintime == 0)
			{
				
				for (a = 0; a <= 6; a++)
				{
					for (i = 0; i <= 5; i++)
					{
						if (Collision(posblue[a][i], blue, player, player))
						{
							//player.setPosition(spawnPoint);
							//speed -= 0.005;
							checkcollintime = 1;
							effectSoundCrash = 1;
							break;
						}
						if (Collision(poswhite[a][i], white, player, player))
						{
							//player.setPosition(spawnPoint);
							//speed -= 0.005;
							checkcollintime = 1;
							effectSoundCrash = 2;
							break;
						}
						if (Collision(posred[a][i], red, player, player))
						{
							//player.setPosition(spawnPoint);
							//speed -= 0.005;
							checkcollintime = 1;
							effectSoundCrash = 3;
							break;
						}
						if (Collision(posyellow[a][i], yellow, player, player))
						{
							//player.setPosition(spawnPoint);
							//speed -= 0.005;
							checkcollintime = 1;
							effectSoundCrash = 4;
							break;
						}
						if (Collision(posgreen[a][i], green, player, player))
						{
							//player.setPosition(spawnPoint);
							//speed -= 0.005;
							checkcollintime = 1;
							effectSoundCrash = 5;
							break;
						}
					}
					if (checkcollintime == 1)
					{
						hpbar += 1;
						countcollin += 1;
						redchicken = 9;
						redchcikeny = 4;
						speed -= 0.05;
						immue = immueclock.restart();
						
						if (effectSoundCrash == 1 && carcrash1.getStatus() != 2)
						{
							carcrash1.play();
						}
						if (effectSoundCrash == 2 && carcrash2.getStatus() != 2)
						{
							carcrash2.play();
						}
						if (effectSoundCrash == 3 && carcrash3.getStatus() != 2)
						{
							carcrash3.play();
						}
						if (effectSoundCrash == 4 && carcrash4.getStatus() != 2)
						{
							carcrash4.play();
						}
						if (effectSoundCrash == 5 && carcrash5.getStatus() != 2)
						{
							carcrash5.play();
						}
						checkcrasheffect++;
						//crashdraw[checkcrasheffect] = true;
						crashsp[checkcrasheffect].setPosition(player.getPosition().x, player.getPosition().y);
						if (framecrash == 4)
						{
							framecrash = 0;
						}
						crashsp[checkcrasheffect].setTextureRect(sf::IntRect((50 * framecrash), 0.0f, 50.f, 50.f));
						framecrash=rand()%4;
						
						
						
						break;
					}

				}
			}
			//count collinsion + delay immue
			if (checkcollintime == 1)
			{
				
				player.setFillColor(sf::Color::Red);
				immue = immueclock.getElapsedTime();
				if (immue.asSeconds() > 1.0f)
				{
					
					
					player.setFillColor(sf::Color::Green);
					checkcollintime = 0;
					redchicken = 0;
					redchcikeny = 0;
				}
			}

			//stamina bar+ HP+ DEATH
			if (staminabar.getSize().y > 0)
			{
				dieTime = dieclock.getElapsedTime();
				if (die == 0)
				{
					staminabar.setSize(sf::Vector2f(27.f, 241.0f - (hpbar * 16.067f)));
				}
				if (die == 1)
				{
					staminabar.setSize(sf::Vector2f(27.f, 160.6666666666667f - (hpbar * 16.067f)));
					//crashsp[checkcrasheffect].setTextureRect(sf::IntRect((50 * 4), 0.0f, 50.f, 50.f));
					if (dieTime.asSeconds() < 1.0f )
					{
						
						bloodsc.setPosition(positionview.x, positionview.y);
					}
					else {
						bloodsc.setPosition(-1080, -720);
					}
				}
				if (die == 2)
				{
					staminabar.setSize(sf::Vector2f(27.f, 80.33333333333333f - (hpbar * 16.067f)));
					//crashsp[checkcrasheffect].setTextureRect(sf::IntRect((50 * 4), 0.0f, 50.f, 50.f));
					if (dieTime.asSeconds() < 1.0f)
					{
						
						bloodsc.setPosition(positionview.x, positionview.y);
					}
					else {
						bloodsc.setPosition(-1080, -720);
					}
				}
			}
			else {
				dieclock.restart();
				
				hpbar = 0;
				die += 1;
				if (die == 1)
				{
					staminabar.setSize(sf::Vector2f(27.f, 160.6666666666667f));
					crashsp[checkcrasheffect].setTextureRect(sf::IntRect((50 * 4), 0.0f, 50.f, 50.f));
					player.setPosition(spawnPoint);
				}
				if (die == 2)
				{
					staminabar.setSize(sf::Vector2f(27.f, 80.33333333333333f));
					crashsp[checkcrasheffect].setTextureRect(sf::IntRect((50 * 4), 0.0f, 50.f, 50.f));
					player.setPosition(spawnPoint);
				}
				if (die == 3)
				{
					crashsp[checkcrasheffect].setTextureRect(sf::IntRect((50 * 4), 0.0f, 50.f, 50.f));
					state = 3;
				}
			}

			//COllinsion block purple
			/*for (i = 0; i <= 5; i++)
			{
				if (Collision(pospurple[i], purple, player, player))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))//2.5
					{
						player.move(0.f, -5.5f * speed * -1);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
					{
						player.move(0.f, 5.5f * speed * -1);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
					{
						player.move(-5.5f * speed * -1, 0.0f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
					{
						player.move(5.5f * speed * -1, 0.f);
					}
				}
			}*/
			//Water DAMMMM******************
			bool checkCol = 0;
			/*if (Collision(posriver[0], river, player, player))
			{
				player.move(0.0f, 0.0f);
				for (i = 0; i <= 2; i++)
				{
					if (Collision(posboat[i], boat1, player, player))
					{
						checkCol = 1;
						player.move(2.200f * slowtime, 0.0f);
						break;
					}
					if (Collision(posboat2[i], boat2, player, player))
					{
						checkCol = 1;
						player.move(-4.5f * slowtime, 0.0f);
						break;
					}
				}
				for (i = 0; i <= 1; i++)
				{
					if (Collision(posboat3[i], boat3, player, player))
					{
						checkCol = 1;
						player.move(3.5f * slowtime, 0.0f);
						break;
					}
					if (Collision(posboat4[i], boat4, player, player))
					{
						checkCol = 1;
						player.move(-4.5f * slowtime, 0.0f);
						break;
					}
				}
				if (checkCol != 1)
				{
					distance = 0;
					tempdistance = 0;
					player.setPosition(spawnPoint);
				}
			}
			if (Collision(posriver[1], river, player, player))
			{
				player.move(0.0f, 0.0f);
				for (i = 3; i <= 5; i++)
				{
					if (Collision(posboat[i], boat1, player, player))
					{
						checkCol = 1;
						player.move(4.200f * slowtime, 0.0f);
						break;
					}
					if (Collision(posboat2[i], boat2, player, player))
					{
						checkCol = 1;
						player.move(-5.0f * slowtime, 0.0f);
						break;
					}
				}
				for (i = 2; i <= 3; i++)
				{
					if (Collision(posboat3[i], boat3, player, player))
					{
						checkCol = 1;
						player.move(4.5f * slowtime, 0.0f);
						break;
					}
					if (Collision(posboat4[i], boat4, player, player))
					{
						checkCol = 1;
						player.move(-6.5f * slowtime, 0.0f);
						break;
					}
				}
				if (checkCol != 1)
				{
					distance = 0;
					tempdistance = 0;
					player.setPosition(spawnPoint);
				}
			}
			if (Collision(posriver[2], river, player, player))
			{
				player.move(0.0f, 0.0f);
				for (i = 6; i <= 8; i++)
				{
					if (Collision(posboat[i], boat1, player, player))
					{
						checkCol = 1;
						player.move(7.200f * slowtime, 0.0f);
						break;
					}
					if (Collision(posboat2[i], boat2, player, player))
					{
						checkCol = 1;
						player.move(-7.0f * slowtime, 0.0f);
						break;
					}
				}
				for (i = 4; i <= 5; i++)
				{
					if (Collision(posboat3[i], boat3, player, player))
					{
						checkCol = 1;
						player.move(4.5f * slowtime, 0.0f);
						break;
					}
					if (Collision(posboat4[i], boat4, player, player))
					{
						checkCol = 1;
						player.move(-8.5f * slowtime, 0.0f);
						break;
					}
				}
				if (checkCol != 1)
				{
					distance = 0;
					tempdistance = 0;
					player.setPosition(spawnPoint);
				}
			}*/

			//boat1
			for (i = 0; i <= 8; i++)
			{
				if (i >= 0 && i <= 2)
				{
					if (posboat[i].x >= 1080)
					{
						posboat[i].x = -200;
					}
					else {
						posboat[i].x += 2.2f * slowtime;
					}
				}
				if (i >= 3 && i <= 5)
				{
					if (posboat[i].x >= 1080)
					{
						posboat[i].x = -200;
					}
					else {
						posboat[i].x += 4.2f * slowtime;
					}
				}
				if (i >= 6 && i <= 8)
				{
					if (posboat[i].x >= 1080)
					{
						posboat[i].x = -200;
					}
					else {
						posboat[i].x += 7.2f * slowtime;
					}
				}
			}
			//boat2
			for (i = 0; i <= 8; i++)
			{
				if (i >= 0 && i <= 2)
				{
					if (posboat2[i].x <= -220)
					{
						posboat2[i].x = 1080;
					}
					else {
						posboat2[i].x -= 4.5f * slowtime;
					}
				}
				if (i >= 3 && i <= 5)
				{
					if (posboat2[i].x <= -220)
					{
						posboat2[i].x = 1080;
					}
					else {
						posboat2[i].x -= 5.0f * slowtime;
					}
				}
				if (i >= 6 && i <= 8)
				{
					if (posboat2[i].x <= -220)
					{
						posboat2[i].x = 1080;
					}
					else {
						posboat2[i].x -= 7.0f * slowtime;
					}
				}
			}
			//boat3
			for (i = 0; i <= 5; i++)
			{
				if (i >= 0 && i <= 1)
				{
					if (posboat3[i].x >= 1080)
					{
						posboat3[i].x = -300;
					}
					else {
						posboat3[i].x += 3.5f * slowtime;
					}
				}
				if (i >= 2 && i <= 3)
				{
					if (posboat3[i].x >= 1080)
					{
						posboat3[i].x = -300;
					}
					else {
						posboat3[i].x += 4.5f * slowtime;
					}
				}
				if (i >= 4 && i <= 5)
				{
					if (posboat3[i].x >= 1080)
					{
						posboat3[i].x = -300;
					}
					else {
						posboat3[i].x += 4.5f * slowtime;
					}
				}
			}
			//boat4
			for (i = 0; i <= 5; i++)
			{
				if (i >= 0 && i <= 1)
				{
					if (posboat4[i].x <= -230)
					{
						posboat4[i].x = 1700;
					}
					else {
						posboat4[i].x -= 4.5f * slowtime;
					}
				}
				if (i >= 2 && i <= 3)
				{
					if (posboat4[i].x <= -230)
					{
						posboat4[i].x = 1700;
					}
					else {
						posboat4[i].x -= 6.5f * slowtime;
					}
				}
				if (i >= 4 && i <= 5)
				{
					if (posboat4[i].x <= -230)
					{
						posboat4[i].x = 1700;
					}
					else {
						posboat4[i].x -= 8.5f * slowtime;
					}
				}
			}

			//check in window
			if (player.getPosition().x < 0) {
				player.setPosition(0, player.getPosition().y);
			}
			if (player.getPosition().x > 1045) {
				player.setPosition(1045, player.getPosition().y);
			}
			if (player.getPosition().y < 100) {
				player.setPosition(player.getPosition().x, 100);
			}
			if (player.getPosition().y > 4920) {
				player.setPosition(player.getPosition().x, 4920);
			}

			//itemclock
			for (i = 0; i <= 2; i++)
			{
				if ((player.getPosition().x + player.getSize().x > posclock[i].x) && (player.getPosition().x < posclock[i].x + itemclock.getSize().x)        // player's horizontal range can touch the platform
					&& (player.getPosition().y + player.getSize().y > posclock[i].y) && (player.getPosition().y < posclock[i].y + itemclock.getSize().y))// player's vertical   range can touch the platform
				{
					slowtime = 0.3;
					checkslowtime = 1;
					clock.restart();
					posclock[i].x = rand() % 1000;
					while (true)
					{
						posclock[i].y = rand() % 4900;
						if (posclock[i].y > 100.0f)
						{
							break;
						}
					}
					clockSound.play();
				}
			}
			if (checkslowtime == 1)
			{
				durationslow = clock.getElapsedTime();
				//printf("%f\n", durationslow.asSeconds());
				if (durationslow.asSeconds() > 0.9f)
				{
					clockSound.stop();
					slowtime = 1;
					checkslowtime = 0;
				}
			}
			//itembeer
			for (i = 0; i < 20; i++)
			{
				if (Collision(beersp[i].getPosition(), itemboots, player, player))
				{
					coinSound.play();
					scorecoins += 1;
					beersp[i].setPosition(-100, -100);
					flipwalk = -1;
					flip = 1;
					beerclcok.restart();
				}
			}
			if (flip == 1)
			{
				chicksp.setTextureRect(sf::IntRect(((framechicken + greenchicy) * 48.f) + 0.0f, ((checksideplayer + 3) * 48.f) + 0.0f, 48.f, 48.f));
				beerTime = beerclcok.getElapsedTime();
				if (beerTime.asSeconds() > 2.0f)
				{
					flip = 0;
					flipwalk = 1;
				}
			}

			//itemboots
			for (i = 0; i <= 1; i++)
			{
				if ((player.getPosition().x + player.getSize().x > posboots[i].x) && (player.getPosition().x < posboots[i].x + itemboots.getSize().x)        // player's horizontal range can touch the platform
					&& (player.getPosition().y + player.getSize().y > posboots[i].y) && (player.getPosition().y < posboots[i].y + itemboots.getSize().y))// player's vertical   range can touch the platform
				{
					bootsSound.play();
					if (stackshoes >= 6)//6
					{
						speed += 0;
					}
					else
					{
						stackshoes += 1;
						speed += 0.075;
					}
					posboots[i].x = rand() % 1000;
					while (true)
					{
						posboots[i].y = rand() % 4900;
						if (posboots[i].y > 100.0f)
						{
							break;
						}
					}
				}
				posboots[2].x = -99;
				posboots[2].y = -99;
			}

			//itemcoins
			for (i = 0; i <= 24; i++)
			{
				if ((player.getPosition().x + player.getSize().x > poscoins[i].x) && (player.getPosition().x < poscoins[i].x + 30)
					&& (player.getPosition().y + player.getSize().y > poscoins[i].y) && (player.getPosition().y < poscoins[i].y + 30))
				{
					coinSound.play();
					scorecoins += 1;
					poscoins[i].x = -100;
					poscoins[i].y = -100;
				}
				poscoins[25].x = -99;
				poscoins[25].y = -99;
			}
		

			stringstream hs, sc, shoec, coinc, nameplayerValue;
			//printf("%d", s);
			distance = ((player.getPosition().y + player.getSize().y) - 120);

			if (distance - tempdistance > 0)
			{
				tempdistance = distance;
				sc << "Score " << distance;
				scoretext.setString(sc.str());
			}
			else if (distance - tempdistance < 0)
			{
				sc << "Score " << tempdistance;
				scoretext.setString(sc.str());
			}
			if (tempdistance - highDistance > 0)
			{
				highDistance = tempdistance;
				hs << "HighScore " << highDistance;
			}
			else
			{
				hs << "HighScore " << highDistance;
			}
			textbox1.setSelected(false);
			nameplayerValue << textbox1.getText() << '\n';
			nameplayerDisplay.setString(nameplayerValue.str());
			nameplayerDisplay.setPosition(positionview.x, positionview.y);

			coinc << "x " << scorecoins;
			cointext.setPosition(positionview.x + 350, positionview.y);
			cointext.setString(coinc.str());

			shoec << "x " << stackshoes;
			shoetext.setPosition(positionview.x + 500, positionview.y);
			shoetext.setString(shoec.str());

			scoretext.setPosition(positionview.x + 875, positionview.y);
			highscoretext.setString(hs.str());
			highscoretext.setPosition(positionview.x + 590, positionview.y);

			staminabar.setPosition(33.3f, positionview.y + 710.5f);
			staminaSprite.setPosition(8, positionview.y + 520);
			for (i = 0; i <= 3; i++)
			{
				platmid.setPosition(posplatmid[i].x, posplatmid[i].y);
			}
			chicksp.setPosition(player.getPosition().x - 18, player.getPosition().y - 20);


			if (player.getGlobalBounds().intersects(endPointbox.getGlobalBounds()))
			{
				standTp = clockstandTp.getElapsedTime();
				if (standTp.asSeconds() > 0.5f)//2.5
				{
					state = 3;
					clockstandTp.restart();
				}
			}
			else {
				clockstandTp.restart();
			}

			window.setView(view);
			window.display();
		}
		if (state == 1)//main menu
		{
			window.setMouseCursorVisible(true);
			window.clear();
			music.stop();
			alert.stop();
			trainSound.stop();
			clockSound.stop();
			coinSound.stop();
			bootsSound.stop();
			footSound.stop();
			view.reset(sf::FloatRect(0, 0, screen.x, screen.y));
			window.setView(view);

			window.draw(bgmenubox);
			textbox1.drawTo(window);

			exitbutton.drawTO(window);
			leaderboardButton.drawTO(window);
			if (texttyping == 0)
			{
				insertNameButton.drawTO(window);
			}

			playButton.drawTO(window);
			window.display();
		}
		if (state == 2)//pasuemenu
		{
			window.setMouseCursorVisible(false);
			music.pause();
			alert.pause();
			trainSound.pause();
			clockSound.pause();
			coinSound.pause();
			bootsSound.pause();
			footSound.pause();
			//view.reset(sf::FloatRect(positionview.x, positionview.y, screen.x, screen.y));
			//window.setView(view);

			pausemenu.SetPOS(positionview.x, positionview.y);
			pausemenu.draw(window);
			window.display();

		}
		if (state == 3)//endgame
		{
			//cout << userName[5] << '\n';
			window.setMouseCursorVisible(false);
			alert.pause();
			trainSound.pause();
			clockSound.pause();
			coinSound.pause();
			bootsSound.pause();
			footSound.pause();

			stringstream hsend;
			hsend << "HighScore" << '\n' << '\n' << "    " << highDistance + (scorecoins * 10);
			userNum[5+repeat] = highDistance + (scorecoins * 10);
			highscoretext.setString(hsend.str());
			highscoretext.setCharacterSize(100);
			highscoretext.setPosition(positionview.x + 145, positionview.y + 95);
			highscoretext.setFillColor(sf::Color::Green);
			player.move(0.0f, -5.0f);
			chicksp.setScale(5.f, 5.f);
			chicksp.setPosition(player.getPosition().x - 90, player.getPosition().y - 90);
			endMenu.SetPOS(positionview.x, positionview.y);
			endMenu.draw(window);
			window.draw(highscoretext);
			if (openfile == 0)
			{
				userScore.push_back(make_pair(userNum[5+repeat], userName[5+repeat]));
				cout << '\n';
				for (index = 5+repeat; index >= 0; index--)
				{
					cout << userScore[index].first << " " << userScore[index].second << "     "<<index <<'\n';
				}
				sort(userScore.begin(), userScore.end());
				cout << '\n';
				fptr = fopen("./bobo.txt", "w");
				if (fptr == NULL)
				{
					cout << "write";
				}
				for (index = 5+repeat, i = 0; i <= 4 && index >= 1+repeat; index--, i++)//index>=1************
				{
					cout << userScore[index].first << " " << userScore[index].second << "     " << index << '\n';
					strcpy(name, userScore[index].second.c_str());
					fprintf(fptr, "%s %d \n", name, userScore[index].first);
					/*scoreLead[i] = userScore[index].first;
					scoreTextLead[i] = userScore[index].second;*/


				}
				fclose(fptr);
				
				openfile = 1;
			}

			window.display();
		}
		if (state == 4)//leaderboard
		{
			window.clear();
			window.setMouseCursorVisible(true);

			if (openfile == 0)
			{
				fptr = fopen("./bobo.txt", "r");
				if (fptr == NULL)
				{
					cout << "read";
				}
				for (index = 0; index < 5; index++)
				{
					
						fscanf(fptr, "%s", &name);
						userName[index] = name;
						fscanf(fptr, "%d", &userNum[index]);
						scoreLead[index] = userNum[index];
						scoreTextLead[index] = userName[index];
					
				}
				fclose(fptr);

				leaderText.setStr(scoreTextLead[0]);
				no2Text.setStr(scoreTextLead[1]);
				no3Text.setStr(scoreTextLead[2]);
				no4Text.setStr(scoreTextLead[3]);
				no5Text.setStr(scoreTextLead[4]);
				scoreLeaderText.setInt(scoreLead[0]);
				scoreno2Text.setInt(scoreLead[1]);
				scoreno3Text.setInt(scoreLead[2]);
				scoreno4Text.setInt(scoreLead[3]);
				scoreno5Text.setInt(scoreLead[4]);
				for (i = 0; i <= 4; i++)
				{


					cout << scoreLead[i] << " " << scoreTextLead[i] << "     " << i << '\n';

				}
				openfile = 1;
			}

			window.draw(bgleader);
			backButtonlead.drawTO(window);
			scoreno5Text.drawTo(window);
			scoreno4Text.drawTo(window);
			scoreno3Text.drawTo(window);
			no5Text.drawTo(window);
			no4Text.drawTo(window);
			no3Text.drawTo(window);
			no2Text.drawTo(window);
			scoreno2Text.drawTo(window);
			leaderText.drawTo(window);
			scoreLeaderText.drawTo(window);
			view.reset(sf::FloatRect(0, 0, screen.x, screen.y));
			window.setView(view);
			window.display();
		}
		//cout << state << '\n' <<textbox1.getText();
		window.draw(platmid);
		window.draw(mapbox);
		for(int a =0; a <= checkcrasheffect ; a++)
		{ 
			window.draw(crashsp[a]);
		}
		
		//draw white
		for (a = 0; a <= 5; a++)
		{
			for (i = 0; i <= 3; i++)
			{
				if (whitex[a].checkside == 1)
				{

					carwhitesp.setScale(1.463414634146341f, 1.120689655172414f);
					carwhitesp.setPosition(poswhite[a][i].x, poswhite[a][i].y);
				}
				else
				{

					carwhitesp.setScale(sf::Vector2f(-1.463414634146341f, 1.120689655172414f));
					carwhitesp.setPosition(poswhite[a][i].x + white.getSize().x, poswhite[a][i].y);
				}
				white.setPosition(poswhite[a][i].x, poswhite[a][i].y);
				window.draw(white);
				window.draw(carwhitesp);
			}
		}
		//draw blue
		for (a = 0; a <= 5; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (bluex[a].checkside == 1)
				{

					carbluesp.setScale(1.379310344827586f, 1.0f);
					carbluesp.setPosition(posblue[a][i].x, posblue[a][i].y);
				}
				else
				{

					carbluesp.setScale(sf::Vector2f(-1.379310344827586f, 1.0f));
					carbluesp.setPosition(posblue[a][i].x + blue.getSize().x, posblue[a][i].y);
				}
				blue.setPosition(posblue[a][i].x, posblue[a][i].y);
				window.draw(blue);
				window.draw(carbluesp);
			}
		}
		//draw green
		for (a = 0; a <= 3; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (greenx[a].checkside == 1)
				{

					cargreensp.setScale(1.304347826086957f, 1.0f);
					cargreensp.setPosition(posgreen[a][i].x, posgreen[a][i].y);
				}
				else
				{

					cargreensp.setScale(sf::Vector2f(-1.304347826086957f, 1.0f));
					cargreensp.setPosition(posgreen[a][i].x + green.getSize().x, posgreen[a][i].y);
				}
				green.setPosition(posgreen[a][i].x, posgreen[a][i].y);
				window.draw(green);
				window.draw(cargreensp);
			}
		}
		//draw red
		for (a = 0; a <= 6; a++)
		{
			for (i = 0; i <= 2; i++)
			{
				if (redx[a].checkside == 1)
				{

					carredsp.setScale(1.438848920863309f, 0.8783783783783784f);
					carredsp.setPosition(posred[a][i].x, posred[a][i].y);
				}
				else
				{

					carredsp.setScale(sf::Vector2f(-1.438848920863309f, 0.8783783783783784f));
					carredsp.setPosition(posred[a][i].x + red.getSize().x, posred[a][i].y);
				}
				red.setPosition(posred[a][i].x, posred[a][i].y);
				window.draw(red);
				window.draw(carredsp);
			}
		}
		//draw yellow
		for (a = 0; a <= 5; a++)
		{
			for (i = 0; i <= 3; i++)
			{
				if (yellowx[a].checkside == 1)
				{

					caryellowsp.setScale(1.428571428571429f, 1.250f);
					caryellowsp.setPosition(posyellow[a][i].x, posyellow[a][i].y);
				}
				else
				{

					caryellowsp.setScale(sf::Vector2f(-1.428571428571429f, 1.250f));
					caryellowsp.setPosition(posyellow[a][i].x + yellow.getSize().x, posyellow[a][i].y);
				}
				yellow.setPosition(posyellow[a][i].x, posyellow[a][i].y);
				window.draw(yellow);
				window.draw(caryellowsp);
			}
		}
		//draw river
		for (i = 0; i <= 2; i++)
		{
			river.setPosition(posriver[i].x, posriver[i].y);
			water.setPosition(posriver[i].x, posriver[i].y);
			window.draw(river);
			window.draw(water);
		}
		//draw boat1
		for (i = 0; i <= 8; i++)
		{
			if (i >= 0 && i <= 2)
			{
				sushiyelloworangered.setPosition(posboat[i].x - 0.0f, posboat[i].y - 0.0f);
			}
			if (i >= 3 && i <= 5)
			{
				zeldaboat.setPosition(posboat[i].x - 0.0f, posboat[i].y - 1.5f);
			}
			if (i >= 6 && i <= 8)
			{
				dogpizza.setPosition(posboat[i].x - 0.0f, posboat[i].y - 0.0f);
			}
			boat1.setPosition(posboat[i].x, posboat[i].y);
			window.draw(boat1);
			window.draw(sushiyelloworangered);
			window.draw(zeldaboat);
			window.draw(dogpizza);
		}
		//draw boat3
		for (i = 0; i <= 5; i++)
		{
			if (i >= 0 && i <= 1)
			{
				mixsuhi.setPosition(posboat3[i].x, posboat3[i].y);
			}
			if (i >= 2 && i <= 3)
			{
				woodpae.setPosition(posboat3[i].x, posboat3[i].y);
			}
			if (i >= 4 && i <= 5)
			{
				crocodileboat.setPosition(posboat3[i].x + .0f, posboat3[i].y);
			}
			boat3.setPosition(posboat3[i].x, posboat3[i].y);
			window.draw(boat3);
			window.draw(mixsuhi);
			window.draw(woodpae);
			window.draw(crocodileboat);
		}
		//draw boat2
		for (i = 0; i <= 8; i++)
		{
			if (i >= 0 && i <= 2)
			{
				duosushi.setPosition(posboat2[i].x - 0.0f, posboat2[i].y - 0.0f);
			}
			if (i >= 3 && i <= 5)
			{
				sushiboat.setPosition(posboat2[i].x - 10.0f, posboat2[i].y - 15.0f);// -10 -15
			}
			if (i >= 6 && i <= 8)
			{
				dogham.setPosition(posboat2[i].x - 10.0f, posboat2[i].y - 0.0f);
			}
			boat2.setPosition(posboat2[i].x, posboat2[i].y);
			window.draw(boat2);
			window.draw(duosushi);
			window.draw(sushiboat);
			window.draw(dogham);
		}
		//draw boat4
		for (i = 0; i <= 5; i++)
		{
			if (i >= 0 && i <= 1)
			{
				uniship.setPosition(posboat4[i].x, posboat4[i].y);
			}
			if (i >= 2 && i <= 3)
			{
				woodlogboat2.setPosition(posboat4[i].x - 0.0f, posboat4[i].y);
			}
			if (i >= 4 && i <= 5)
			{
				fishboat.setPosition(posboat4[i].x - 0.0f, posboat4[i].y);
			}
			boat4.setPosition(posboat4[i].x, posboat4[i].y);
			window.draw(boat4);
			window.draw(uniship);
			window.draw(fishboat);
			window.draw(woodlogboat2);
		}
		//box purple
		/*for (i = 0; i <= 5; i++)
		{
			purple.setPosition(pospurple[i].x, pospurple[i].y);
			window.draw(purple);
		}*/
		//window.draw(tpbox);
		//window.draw(endPointbox);
		window.draw(tpsp);
		//window.draw(player);
		
		//draw clock
		for (i = 0; i <= 2; i++)
		{
			itemclock.setPosition(posclock[i].x, posclock[i].y);
			window.draw(itemclock);
		}
		//draw boots
		for (i = 0; i <= 2; i++)
		{
			if (allowDraw == 1)//1
			{
				posboots[2].x = positionview.x + 450;
				posboots[2].y = positionview.y;
			}
			itemboots.setPosition(posboots[i].x, posboots[i].y);
			window.draw(itemboots);
		}
		//draw beer
		for (i = 0; i <20; i++)
		{
			window.draw(beersp[i]);
		}
		//draw coin
		for (i = 0; i <= 25; i++)
		{
			if (allowDraw == 1)//1
			{
				poscoins[25].x = positionview.x + 310;
				poscoins[25].y = positionview.y;
			}
			itemcoins.setPosition(poscoins[i].x, poscoins[i].y);
			window.draw(itemcoins);
		}
		//sign
		for (i = 0; i <= 2; i++)
		{
			signTrain.setPosition(possign[i].x, possign[i].y);
			if (trainrunning == 0)
			{
				window.draw(signTrain);
			}
		}
		window.draw(chicksp);
		window.draw(hitboxTrain);
		window.draw(nameplayerDisplay);
		window.draw(staminaSprite);
		window.draw(staminabar);
		if (allowDraw == 1)//1
		{
			window.draw(cointext);
			window.draw(shoetext);
			window.draw(scoretext);
			window.draw(highscoretext);
		}
		window.draw(bloodsc);

	}
	return 0;
}
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(screenheight * aspectRatio, screenheight);
}
float findPosCarY(sf::RectangleShape colorcar, float poscary)
{
	poscary = rand() % 4536;

	for (j = 0; j != i; )
	{
		if ((poscary > 1900.0f && poscary < 4535.0f) && !(poscary + colorcar.getSize().y > 2500 && poscary < 2750) && !(poscary + colorcar.getSize().y > 4030 && poscary < 4280))
		{
			realposcary = poscary;
			return realposcary;
			break;
		}
		else
		{
			poscary = rand() % 4536;
		}
	}
}

bool Collision(sf::Vector2f posobject, sf::RectangleShape sizeobject, sf::RectangleShape posplayerfunc, sf::RectangleShape playersizefunc)
{
	if (((posplayerfunc.getPosition().x + playersizefunc.getSize().x > posobject.x) && (posplayerfunc.getPosition().x < posobject.x + sizeobject.getSize().x)
		&& (posplayerfunc.getPosition().y + playersizefunc.getSize().y > posobject.y) && (posplayerfunc.getPosition().y < posobject.y + sizeobject.getSize().y)))
	{
		collinreturn = 1;
		return collinreturn;
	}
	else
	{
		collinreturn = 0;
		return collinreturn;
	}
}

bool changeVolumeSign(float playery, float trainy, float limitupper, float limitlower, float trainsizey)
{
	if ((abs(playery - trainy) < limitupper && abs(playery - trainy) >= limitlower) || (abs(playery - (trainy + trainsizey)) < limitupper && abs(playery - (trainy + trainsizey)) >= limitlower))
	{
		return true;
	}
	else
	{
		return false;
	}
}

