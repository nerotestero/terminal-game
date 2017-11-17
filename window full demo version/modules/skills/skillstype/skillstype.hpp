/***
* Author: Stasiek Forto�ski
* Date: 16.06.2017
* Skill types
* Version: 1
***/

#ifndef SKILLSTYPE_HPP_
#define SKILLSTYPE_HPP_ 1
#include <iostream>

class SkillsType
{
public:
  enum Type{MEDIUM, DARKNESS, LIGHT};

private:
  Type skill;

public:
  SkillsType(const Type & ref = MEDIUM): skill(ref){}

  std::string getCourseName() const
  {
      if (skill == LIGHT) return "�wiat�o";
      else if (skill == DARKNESS) return "Ciemn�o��";
      return "R�wnowaga";
  }

  Type getSkillType() const{return skill;}
  Type & getSkillType(){return skill;}
};
#endif