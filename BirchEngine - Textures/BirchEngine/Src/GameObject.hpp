#pragma once
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char* texturesheet,int x,int y);
	~GameObject();

	void Update(); //вместо обновления всей сцены можно обновлять конкретные элементы определенным образом, как например наш игровой объект.
	void Render();
private:
	int xpos, ypos;   // что мы должны знать об игровом объекте? Его координаты
	SDL_Texture* objTexture; // его текстуру
	SDL_Rect srcRect, destRect; // какую часть изображения брать, и в какую часть фона вставлять


};