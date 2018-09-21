#pragma once
#include "Panel.h"
#include <memory>
class Actor;
namespace ASGE
{
	class Renderer;
}

class ViewportPanel: public UIPanel
{

public:
	virtual void render(std::shared_ptr<ASGE::Renderer> renderer) override;
	void ViewportPanel::setObject(Actor* obj);
private:
	Actor* object = nullptr;
};