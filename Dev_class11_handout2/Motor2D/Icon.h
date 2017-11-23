#pragma once
#include "p2Point.h"
#include "j1Gui.h"

enum ICON_TYPE;

class Icon
{
public:
	Icon();
	~Icon();

	iPoint position;
	ICON_TYPE type;

	virtual void Draw();
};

