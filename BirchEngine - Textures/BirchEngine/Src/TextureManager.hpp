#pragma once
#include "Game.hpp"
class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName ); // функция, определенная в классе, но не имеющая доступ к объектам кроме типа static. Вызывается через класс, а не через объект класса.
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};