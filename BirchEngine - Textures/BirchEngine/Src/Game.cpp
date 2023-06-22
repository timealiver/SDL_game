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
		flags = SDL_WINDOW_FULLSCREEN; //если передано в fulscreen true, то в переменную флаг заносим флаг для запуска на полном экране
	};
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised" << std::endl;
		window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);	// создаем окно с флагом (fullscreen) или без
		if (window)
		{
			std::cout << "Window created" << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);             // создаем визуализатор

			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255); // если он создался, то присваиваем ему цвет
				std::cout << "Renderer created" << std::endl;
				isRunning = true;                                     // если визуализатор создан и выполнен, то переменная isRunning ==1
			}
			else
			{
				isRunning = false;    // иначе, если что-то пошло не так, игра заканчивается, сл-но isRunning==false
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
	SDL_Event event; // создаем объект класса "событие"
	SDL_PollEvent(&event); // передает в объект класса "событие" последнее произошедшее действие
	switch (event.type)    // event.type возвращает тип события, и если оно - SDL_QUIT (Закрытие окна любым способом, буть то кнопка или alt-f4), то isRunning==false;
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
	SDL_RenderCopy(renderer, playerTex, NULL, &destRect); //вторые два аргумента нужны для того, чтобы указать какую часть изображения вставлять в какую часть экрана.
	// здесь будут добавляться штуки для рендера
	SDL_RenderPresent(renderer);
};
void Game::clean()
{
	SDL_DestroyWindow(window);      // удаляем созданное окно
	SDL_DestroyRenderer(renderer);  // удаляем визуализатор
	SDL_Quit();						// выходим из подсистемы SDL, зачищаем следы ( вроде )
	std::cout << "Game cleaned" << std::endl;
};



