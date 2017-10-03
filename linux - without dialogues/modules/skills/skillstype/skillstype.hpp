/***
* Author: Stasiek Fortoński
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
      if (skill == LIGHT) return "Światło";
      else if (skill == DARKNESS) return "Ciemność";
      return "Równowaga";
  }

  Type getSkillType() const{return skill;}
  Type & getSkillType(){return skill;}
};
#endif
