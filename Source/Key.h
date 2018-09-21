#pragma once
#include "Item.h"

class Key :public Item
{
public:
virtual std::string getRenderString()const;
virtual  std::string GetDescription()const;
private:
};