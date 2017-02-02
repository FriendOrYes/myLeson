#include <SFML/Graphics.hpp>
#include "map.h"
#include <iostream>
#include <Windows.h>
#include <memory>
#include <map>
#include <random>
#include <vector>

using namespace sf;
using namespace std;



class Object 
{
public:
	Object() 
	{

	}
	Object(const string& name)
		:m_name(name)
	{
		m_image.loadFromFile(m_name);

		m_texture.loadFromImage(m_image);

		m_sprite.setTexture(m_texture);
	}

	void DrawObject(RenderWindow& window)
	{
		window.draw(m_sprite);
	}

	void SetObjectPosition(const Vector2f& pos) 
	{
		m_posObj = pos;
		m_sprite.setPosition(pos);
	}

	Sprite& GetSprite() 
	{
		return m_sprite;
	}
private:
	String m_name;
	Image m_image;
	Texture m_texture;
	Sprite	m_sprite;

	Vector2f m_posObj;
};


class Button
{

public:
	Button()
	{
		cout << __FUNCTION__ << "()" << endl;
	}

	Button(const int& radius, string name = "image/button.png")
		: m_name(name)
		, m_button(radius)
		, m_buttonPosition(Vector2f(0, 0))
	{
		cout << __FUNCTION__ << "(const int& radius, string name = image / button.png)" << endl;
		m_buttonImage.loadFromFile(m_name);
		m_buttonImage.createMaskFromColor(Color::White);

		m_buttonTexture.loadFromImage(m_buttonImage);

		m_buttonSprite.setTexture(m_buttonTexture);
		m_buttonSprite.setTextureRect(IntRect(0, 0, radius * 2, radius * 2));  //приведение типов, размеры картинки исходные
	}

	Button(const Button& obj)
		: m_name(obj.m_name)
		, m_button(obj.m_button)
		, m_buttonImage(obj.m_buttonImage)
		, m_buttonTexture(obj.m_buttonTexture)
		, m_buttonSprite(obj.m_buttonSprite)
	{
		cout << __FUNCTION__ << "(copy)" << endl;
	}

	Sprite& GetButtonSprite()
	{
		return m_buttonSprite;
	}

	CircleShape& GetCircleOfButton()
	{
		return m_button;
	}

	void CreatButton(const Vector2f& vector)
	{
		m_button.setPosition(vector);
		m_buttonSprite.setPosition(vector);
		m_buttonPosition = vector;
	}

	void ShowButton(RenderWindow& window)
	{
		window.draw(m_button);
		m_buttonSprite.setTexture(m_buttonTexture);
		window.draw(m_buttonSprite);
	}

	const Button& operator = (const Button& obj)
	{
		cout << __FUNCTION__ << endl;
		m_name = obj.m_name;
		m_button = obj.m_button;
		m_buttonImage = obj.m_buttonImage;
		m_buttonTexture = obj.m_buttonTexture;
		m_buttonSprite = obj.m_buttonSprite;
		return *this;
	}

	const Vector2f& GetPositionOfButton()
	{
		return m_buttonPosition;
	}
private:
	string m_name;
	CircleShape m_button;

	Image m_buttonImage;
	Texture m_buttonTexture;
	Sprite m_buttonSprite;

	Vector2f m_buttonPosition;
};

//----------------------------------------------------------------
class ButtonPanel
{
public:
	ButtonPanel()
	{

	}

	ButtonPanel(const string& name, const int& numberOfButton = 20)
		: m_name(name)
		, m_numberOfButton(numberOfButton)
	{
		m_panelImage.loadFromFile(m_name);
		//		m_PanelImage.createMaskFromColor(Color(0, 0, 0));

		m_panelTexture.loadFromImage(m_panelImage);

		s_panel.setTexture(m_panelTexture);
		s_panel.setTextureRect(IntRect(0, 0, 200, 800));  //приведение типов, размеры картинки исходные

		s_panel.setPosition(220, 0);

		CreatButtons(numberOfButton);
	}

	void ShowPanel(RenderWindow& window)
	{
		window.draw(s_panel);
		SetAllButtonOnPanel(window);
	}

	void ShowPanelWhisOneButton(RenderWindow& window, const int& numberOfButton)
	{
		window.draw(s_panel);
		SetButtonOnCenterOfPanel(numberOfButton, window);
	}

	Sprite& GetPanel()
	{
		return s_panel;
	}

	void SetAllButtonOnPanel(RenderWindow& window)
	{
		for (int i = 1; i <= buttonMap.size(); ++i)
		{
			SetButtons(i);
			buttonMap[i].ShowButton(window);
		}
	}

	void SetButtons(const int& numberOfButton)
	{
		if (numberOfButton == 1)
		{
			buttonMap[numberOfButton].CreatButton(Vector2f(s_panel.getPosition().x + 50, s_panel.getPosition().y + numberOfButton * 70));
		}
		else if (numberOfButton % 2)
			buttonMap[numberOfButton].CreatButton(Vector2f(buttonMap[numberOfButton - 2].GetButtonSprite().getPosition().x, buttonMap[numberOfButton - 1].GetButtonSprite().getPosition().y + 51));
		else
			buttonMap[numberOfButton].CreatButton(Vector2f(buttonMap[numberOfButton - 1].GetButtonSprite().getPosition().x + 65, buttonMap[numberOfButton - 1].GetButtonSprite().getPosition().y));

		buttonMap[numberOfButton].GetCircleOfButton().setFillColor(Color::Black);
	}

	void SetButtonOnCenterOfPanel(const int& numberOfButton, RenderWindow& window)
	{
		buttonMap[numberOfButton].CreatButton(Vector2f(s_panel.getPosition().x + 80, s_panel.getPosition().y + 380));
		buttonMap[numberOfButton].ShowButton(window);
	}

	void SetPanel(const Vector2f& vector)
	{
		if (vector.y <= 220) m_vectorPanel = Vector2f(vector.x + 220, 0);
		else if(vector.y >= 1650)  m_vectorPanel = Vector2f(vector.x + 220, 1250);
		else m_vectorPanel = Vector2f(vector.x + 220, vector.y - 200);
		s_panel.setPosition(m_vectorPanel);
	}

	void CreatButtons(const int& countOfButton = 20)
	{
		for (int i = 1; i <= countOfButton; ++i)
		{
			buttonMap[i] = Button(20);
		}
	}

	const map<int, Button>&  GetButtonMap()
	{
		return buttonMap;
	}
	const int& GetNumberOfButton()
	{
		return m_numberOfButton;
	}

private:
	string m_name;
	int m_numberOfButton;
	Image m_panelImage;
	Vector2f m_vectorPanel;
	map<int, Button> buttonMap;

	Texture m_panelTexture;

	Sprite s_panel;
};
//------------------------------------------------------------
class Man
{
public:
	Man()
	{
	}

	Man(const string& path)
		: m_path(path)
		, m_x(120)
		, m_y(40)
		, m_dx(0)
		, m_dy(0)
	{
		m_image.loadFromFile(m_path);
		m_image.createMaskFromColor(Color::White);
		m_texture.loadFromImage(m_image);//заряжаем текстуру картинкой

		m_sprite.setTexture(m_texture);//заливаем текстуру спрайтом

		m_sprite.setTextureRect(IntRect(0, 0, 26, 74));
		m_sprite.setPosition(120, 40);
	}

	void CorrectDir(const int& dir)
	{
		m_dir = static_cast<DirMove>(dir);
	}

	void Update()
	{
		Clock clock;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		///////////////////////////<---
		//m_sprite.setTextureRect(IntRect(0, 0, 26, 74));//0
		//m_sprite.setTextureRect(IntRect(32, 0, 24, 74));//1
		//m_sprite.setTextureRect(IntRect(66, 0, 24, 74));//2
		//m_sprite.setTextureRect(IntRect(96, 0, 28, 74));//3	
		switch (m_dir)
		{
		case ENTER:
		{
			CurrentFrame += 0.05 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			m_sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 26, 74));
		}break;

		case GO_OUT:
		{
			CurrentFrame += 0.05 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			m_sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 75, 26, 74));
		}break;
		}

		m_sprite.move(m_speed * time * m_dir, 0);
		///////////////////////////--->
		//m_sprite.setTextureRect(IntRect(0, 75, 27, 74));//0
		//m_sprite.setTextureRect(IntRect(35, 75, 25, 74));//1
		//m_sprite.setTextureRect(IntRect(64, 75, 24, 74));//2
		//m_sprite.setTextureRect(IntRect(97, 75, 28, 74));//3
	}
	void SetToFloor(const int& floar)
	{
		m_currentFloar = floar;
	}

	Sprite& GetSprite()
	{
		return m_sprite;
	}

	const int& GetFloar()
	{
		return m_currentFloar;
	}

private:
	string m_path;
	Sprite m_sprite;
	Texture m_texture;
	Image m_image;
	int m_currentFloar;
	float m_speed = 0.02f;
	float CurrentFrame = 0;
	float m_x;
	float m_y;
	float m_dx;
	float m_dy;

	enum DirMove
	{
		ENTER = -1,
		STOP = 0,
		GO_OUT = 1

	}m_dir;
};

//------------------------------------------------------------------------------
class Map
{
public:
	Map()
	{
	}
	Map(const string& path)
		: m_path(path)
		, m_sizeOfObject(0)
	{

		m_image.loadFromFile(m_path);

		m_texture.loadFromImage(m_image);//заряжаем текстуру картинкой

		s_map.setTexture(m_texture);//заливаем текстуру спрайтом


		m_font.loadFromFile("font/Arm.ttf");
		m_textVector.resize(HEIGHT_MAP);

		for_each(m_textVector.begin(), m_textVector.end(),
			[&](Text& text) 
		{
			text.setFont(m_font);
			text.setCharacterSize(25);

			text.setOutlineColor(Color::Black);
			text.setOutlineThickness(1);
		});
}

	Map(const Map& obj) = delete;

	const Map& operator = (const Map& obj) = delete;

	void AddMan(shared_ptr<Man> man)
	{
		m_man = man;
	}

	void AddPanel(shared_ptr<ButtonPanel> panel)
	{
		m_panel = panel;
	}

	void SetManInFloor(const int& floor, const int& x = 85)
	{
		m_man->GetSprite().setPosition(x, 100 * (20 - floor) + 20);
		m_man->SetToFloor(floor);
	}

	void DrawMap(RenderWindow& window)
	{
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (m_map[i][j] == 'c')  s_map.setTextureRect(IntRect(0, 0, 80, 100));
				if (m_map[i][j] == 'f') 
				{
					s_map.setTextureRect(IntRect(80, 0, 140, 100));
					m_textVector[i].setString(to_string(20 - i));
					m_textVector[i].setPosition(j * 80 + 20, i * 100 + 15);
				}
				if (m_map[i][j] == ' ')  continue;
				s_map.setPosition(j * 80, i * 100);
				window.draw(s_map);
			}
		}
		DrawObject(window);
	}

	void AddObject(Object& obj) 
	{
		m_sizeOfObject++;

		m_objectVector.push_back(obj);
	}

	void DrawObject(RenderWindow &window)
	{
		for (auto it = m_objectVector.begin(); it != m_objectVector.end(); ++it)
		{
			it->DrawObject(window);
		}
	}
	void DrawTextInFloor(RenderWindow &window)
	{
		for (auto it = m_textVector.begin(); it != m_textVector.end(); ++it)
		{
			window.draw(*it);
		}
	}

	ButtonPanel& GetPanel() const
	{
		return *m_panel;
	}

	Man& GetMan() const
	{
		return *m_man;
	}
private:
	const int HEIGHT_MAP = 20;
	const int WIDTH_MAP = 10;
	const string m_map[20] =
	{
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
		"cf        ",
	};
	string m_path;
	Sprite s_map;
	Texture m_texture;
	Image m_image;
	vector<Text> m_textVector;
	Font m_font;

	vector<Object> m_objectVector;
	size_t m_sizeOfObject;

	shared_ptr<Man> m_man;
	shared_ptr<ButtonPanel> m_panel;
	
};

//---------------------------------------------------------------------------------------
class Lift
{
public:
	Lift()
	{
	}
	Lift(const string& path, int setFloor, shared_ptr<Map> map, const string& panelSrc = "image/panel.png")
		: m_path(path)
		, m_currentFloor(setFloor)
		, m_loadMan(false)
		, m_dir(STOP)
		, m_map(map)
		, m_panelLift(make_shared<ButtonPanel>(panelSrc, 22))
	{

		m_image.loadFromFile(m_path);

		m_texture.loadFromImage(m_image);//заряжаем текстуру картинкой

		m_lift.setTexture(m_texture);//заливаем текстуру спрайтом

		m_lift.setTextureRect(IntRect(0, 0, 80, 100));

		m_lift.setPosition(0, 100 * (20 - m_currentFloor));

		m_view.setSize(400, 800);
	}

	void StartLift(const int& floorCall, RenderWindow& window)
	{
		m_floorCall = floorCall;
		GetFloorCall();
		MoveLift2(window);

		m_dir = STOP;
		m_loadMan = true;
		DoorOpen(window);
		InterectionMen(m_floorCall, -1, window);
		DoorClose(window);
		//----------------------------------------	
		bool flag = false;
		while (flag != true)
		{

			Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
			Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)

			Event event;

			window.pollEvent(event);

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{

					for (int i = 1; i <= m_panelLift->GetNumberOfButton(); ++i)
					{
						map<int, Button> tmp = m_panelLift->GetButtonMap();
						if (tmp[i].GetButtonSprite().getGlobalBounds().contains(pos.x, pos.y))
						{
							i % 2 == 0 ? m_floorCall = 22 - i : m_floorCall = 20 - i;
							cout << "Floor - " << m_floorCall << "vector = " << tmp[i].GetPositionOfButton().y << endl;
							flag = true;
						}
					}
				}
			}
		}
		//----------------------------------------------
		GetFloorCall();

		MoveLift2(window, false);
		DoorOpen(window);
		InterectionMen(m_floorCall, 1, window);
		DoorClose(window);
		m_loadMan = false;
		m_dir = STOP;
	}

	void InterectionMen(const int& floorCall, const int& dir, RenderWindow& window)
	{
		if (dir > 0)
		{
			m_map->SetManInFloor(m_floorCall, 30);
		}
		else
		{
			m_map->SetManInFloor(m_floorCall);
		}
		m_map->GetMan().CorrectDir(dir);
		int difference;

		if (dir > 0)
		{
			difference = 100;

			while (m_map->GetMan().GetSprite().getPosition().x - m_lift.getPosition().x < difference)
			{
				MovePers(window);
			}
		}
		else
		{
			difference = 30;

			while (m_map->GetMan().GetSprite().getPosition().x - m_lift.getPosition().x > difference)
			{
				MovePers(window);
			}
		}
	}

	void MovePers(RenderWindow& window)
	{
		m_map->GetMan().Update();
		DrawWindow(window);
		cout << "men x :" << m_map->GetMan().GetSprite().getPosition().x << "Lift x: " << m_lift.getPosition().x << endl;
	}

	void MoveLift1(const float& time)
	{
		m_lift.move(0, m_speed * time * m_dir);
	}

	void MoveLift2(RenderWindow& window, const bool& DisplayPers = true)
	{
		std::cout << __FUNCTION__ << endl;
		Clock clock;
		float time = clock.getElapsedTime().asMicroseconds();
		while (m_floorCall != m_currentFloor)
		{
			time = clock.getElapsedTime().asMicroseconds();
			clock.restart();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			MoveLift1(time);
			GetCurrentFloor();
			DrawWindow(window, DisplayPers);
		}
	}

	void DrawWindow(RenderWindow& window, const bool& DisplayPers = true)
	{
		GetLiftCoordinateForView(m_lift.getPosition());
		window.setView(m_view);
		window.clear();
		m_map->DrawMap(window);
		window.draw(m_lift);
		m_map->DrawTextInFloor(window);
		if (m_loadMan == true)
		{
			m_panelLift->SetPanel(m_lift.getPosition());
			m_panelLift->ShowPanel(window);
		}
		else
		{
			m_map->GetPanel().SetPanel(m_lift.getPosition());
			m_map->GetPanel().ShowPanelWhisOneButton(window, 1);
		}
		if (DisplayPers)
		{
			window.draw(m_map->GetMan().GetSprite());
		}

		window.display();
	}


	void GetLiftCoordinateForView(Vector2f vect)
	{ //функция для считывания координат игрока
		
		if (m_lift.getPosition().y <= 200) 
			m_view.setCenter( 210, 400);
		else if (m_lift.getPosition().y >= 1650)
			m_view.setCenter(210, 1650);
		else 
			m_view.setCenter(vect.x + 210, vect.y + 200);
		
	}

	void GetCurrentFloor()
	{
		if (m_dir == UP)
		{
			m_currentFloor = abs((m_lift.getPosition().y / 100) - 20);
		}
		else
		{
			m_currentFloor = abs((m_lift.getPosition().y / 100) - 20) + 1;
		}
	}

	void GetFloorCall()
	{
		DetermineDirection();
	}


	void DoorOpen(RenderWindow& window)
	{
		m_lift.setTextureRect(IntRect(80, 0, 80, 100));

		DrawWindow(window);
	}

	void DoorClose(RenderWindow& window)
	{
		m_lift.setTextureRect(IntRect(0, 0, 80, 100));
	}

	void DetermineDirection()
	{
		if (m_currentFloor > m_floorCall)
		{
			m_dir = DOWN;
		}
		else if (m_currentFloor < m_floorCall)
		{
			m_dir = UP;
		}
		else
		{
			m_dir = STOP;
		}
	}

	const Sprite& GetSprite() const
	{
		return m_lift;
	}

	View& GetView()
	{
		return m_view;
	}

	ButtonPanel& GetPanel() const
	{
		return *m_panelLift;
	}
private:
	string m_path;
	Sprite m_lift;
	Texture m_texture;
	Image m_image;
	int m_currentFloor;
	int m_floorCall;
	const float m_speed = 0.0001f;
	View m_view;
	bool m_loadMan;

	enum Dir
	{
		UP = -1,
		STOP = 0,
		DOWN = 1,
	}m_dir = STOP;


	shared_ptr<Map> m_map;
	shared_ptr<ButtonPanel> m_panelLift;
};


//-----------------------------------------------------------------------------------------------------
int main()
{
	srand(time(0));

	
	RenderWindow window(sf::VideoMode(420, 800), "Lesson 1. kychka-pc.ru");

	Button button(20);

	shared_ptr<ButtonPanel> panel = make_shared<ButtonPanel>("image/fonLift.png", 1);

	shared_ptr<Map> mapObj = make_shared<Map>("image/cafe.png");

	Lift lift("image/lift.png", rand() % 20 + 1, mapObj, "image/panel.png");

	lift.GetView().reset(FloatRect(0, 0, 420, 800));

	shared_ptr<Man> man = make_shared<Man>("image/men.png");

	mapObj->AddMan(man);
	mapObj->AddPanel(panel);

	
	//	mapObj->SetManInFloor(rand()%20 + 1););

	Clock clock;
	
	bool startLift = true;
	
	while (window.isOpen())
	{
		if(startLift)
		{
			mapObj->SetManInFloor(rand() % 20 + 1);
			startLift = false;
		}
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;

		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{

					for (int i = 1; i <= mapObj -> GetPanel().GetNumberOfButton(); ++i)
					{
						map<int, Button> tmp = mapObj->GetPanel().GetButtonMap();
						if (tmp[i].GetButtonSprite().getGlobalBounds().contains(pos.x, pos.y))
						{
							lift.StartLift(mapObj->GetMan().GetFloar(), window);
							startLift = true;
						}
					}
				}
			}
		}

		window.clear();
		lift.DrawWindow(window);
		
	//	window.display();
	}
	return 0;
}

