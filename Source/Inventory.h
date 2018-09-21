#pragma once
#include "GameObject.h"
#include <vector>
#include<string>
#include<memory>
#include"Item.h"
class Inventory
{
public:
	/*Inventory();
	~Inventory();*/

	void addItem(std::unique_ptr<Item>&&);
	std::string getRenderString();
	

private:
	std::vector<std::unique_ptr<Item>>objects;
};

