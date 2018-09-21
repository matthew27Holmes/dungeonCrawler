//#include"Bat.h"
//#include "ViewportPanel.h"
//#include <Engine/Renderer.h>
//#include <string>
//#include <sstream>
//
//
//std::string Bat::getRenderString() const
//{
//	std::string bat_string =R"(
//	ENEMY: BAT
//
//  =,    (\_/)    ,=
//   /`-'--(")--'-'\
//  /     (___)     \
// /.-.-./ " " \.-.-.\
//
//		"I am a Creature from
//		the darkest depths of 
//		your mind!!!"
//
//					Health : (100%) ########
//	)";
//	return bat_string;
//}
//
//std::string Bat::GetDescription()const
//{
//	return std::string("a friendly bat");
//}
//std::string Bat::getHealthAsString() const
//{
//	std::stringstream ss;
//	for (int i = 0; i < health; i += 5)
//	{
//		ss << '#';
//	}
//	return ss.str().c_str();
//}