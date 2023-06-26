#pragma once
#include "Game.hpp"
class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren); // функция, определенная в классе, но не имеющая доступ к объектам кроме типа static. Вызывается через класс, а не через объект класса.
};