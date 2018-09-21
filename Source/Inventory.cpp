#include "Inventory.h"
# include<string>

void Inventory::addItem(std::unique_ptr<Item>&& obj)
{
	objects.push_back(std::move(obj));
}
std::string Inventory::getRenderString()
{
	std::string string="\nyou have";
	
	if (!objects.empty())
	{
		for (const auto& item : objects)
		{
			string += item->getDescription();
			string += "";
			
		}
		return string;
	}
	return std::string("Empty");
}