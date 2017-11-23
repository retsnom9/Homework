#pragma once
#include "Icon.h"

class Interactive : public Icon
{
public:
	Interactive();
	~Interactive();

	virtual void OnClick();
};

