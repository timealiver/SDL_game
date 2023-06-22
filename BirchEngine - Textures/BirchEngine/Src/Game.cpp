#include "Game.hpp"
SDL_Texture* playerTex;
SDL_Rect srcRect, destRect;
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
		SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
		playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);

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
	destRect.h = 64;
	destRect.w = 64;
	destRect.x = cnt;
	std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &destRect); //������ ��� ��������� ����� ��� ����, ����� ������� ����� ����� ����������� ��������� � ����� ����� ������.
	// ����� ����� ����������� ����� ��� �������
	SDL_RenderPresent(renderer);
};
void Game::clean()
{
	SDL_DestroyWindow(window);      // ������� ��������� ����
	SDL_DestroyRenderer(renderer);  // ������� ������������
	SDL_Quit();						// ������� �� ���������� SDL, �������� ����� ( ����� )
	std::cout << "Game cleaned" << std::endl;
};



