#pragma once
#include "p2Point.h"
#include "Icon.h"
#include "j1Textures.h"

class Label : public Icon
{
public:
	Label(ICON_TYPE type, SDL_Texture* texture, iPoint position);
	~Label();

	SDL_Texture* texture;
};
