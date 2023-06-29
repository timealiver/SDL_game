#include "TextureManager.hpp"
SDL_Texture* TextureManager::LoadTexture(const char* texture) //здесь описана реализация создания ассета на экране.Texture- адрес файла, SDL_Renderer- визуализатор (он был удален, дабы избежать повторения)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex; // возвращает текстуру

}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
