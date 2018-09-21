#pragma once 
#include <string>
class GameObject
{
public:
	virtual ~GameObject() = default;
	virtual std::string GetDescription()const=0;
	virtual std::string getRenderString()const = 0; 
protected:
	GameObject() = default;
};