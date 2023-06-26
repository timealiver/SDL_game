#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
GameObject* player;
GameObject* enemy;
Game::Game()
{}

void Game::init(const char* title,int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN; //���� �������� � fulscreen true, �� � ���������� ���� ������� ���� ��� ������� �� ������ ������
	};
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised" << std::endl;
		window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);	// ������� ���� � ������ (fullscreen) ��� ���
		if (window)
		{
			std::cout << "Window created" << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);             // ������� ������������

			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255); // ���� �� ��������, �� ����������� ��� ����
				std::cout << "Renderer created" << std::endl;
				isRunning = true;                                     // ���� ������������ ������ � ��������, �� ���������� isRunning ==1
			}
			else
			{
				isRunning = false;    // �����, ���� ���-�� ����� �� ���, ���� �������������, ��-�� isRunning==false
			}
		}
		player = new GameObject("assets/player.png", renderer,0,0);
		enemy = new GameObject("assets/enemy.png", renderer, 100, 50);

	}
	else
	{
		isRunning = false;
	}

}
void Game::handleEvents()
{
	SDL_Event event; // ������� ������ ������ "�������"
	SDL_PollEvent(&event); // �������� � ������ ������ "�������" ��������� ������������ ��������
	switch (event.type)    // event.type ���������� ��� �������, � ���� ��� - SDL_QUIT (�������� ���� ����� ��������, ���� �� ������ ��� alt-f4), �� isRunning==false;
	{
	case SDL_QUIT:
		isRunning = false;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	player->Update();
	enemy->Update();
	std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
	enemy->Render();
	//SDL_RenderCopy(renderer, playerTex, NULL, &destRect); (��� ���� � gameobject ����� texturemanager) ������ ��� ��������� ����� ��� ����, ����� ������� ����� ����� ����������� ��������� � ����� ����� ������.
	SDL_RenderPresent(renderer);
};
void Game::clean()
{
	SDL_DestroyWindow(window);      // ������� ��������� ����
	SDL_DestroyRenderer(renderer);  // ������� ������������
	SDL_Quit();						// ������� �� ���������� SDL, �������� ����� ( ����� )
	std::cout << "Game cleaned" << std::endl;
};



