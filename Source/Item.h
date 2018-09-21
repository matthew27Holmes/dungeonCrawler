#pragma once
#include "GameObject.h"
class Item :public GameObject
{
public:
	virtual std::string getRenderString();
	virtual std::string getDescription();

};

