#include "TextureManager.hpp"
SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren) //здесь описана реализация создания ассета на экране.Texture- адрес файла, SDL_Renderer- визуализатор.
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex; // возвращает текстуру

}