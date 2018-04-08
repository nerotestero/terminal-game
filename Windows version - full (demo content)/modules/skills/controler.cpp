#include "skills.hpp"
#include "../libs/sets_types/sets_types.hpp"
#include "../libs/screen/screen.hpp"

using namespace std;
using namespace screen;

void Skills::contolerTreeChoser()
{
  for (;;)
  {
      clear();
      cout<<"Wybierz swoj� drog� umiej�tno�ci!\n\n";

      cout<<"1. Droga Cienia\n2. Droga �wiat�a\n3. Droga Zr�wnowa�ona\nWybierz dzia�nie: ";

      switch (setNumber<unsigned>())
      {
          case 1: getSkillType() = DARKNESS; set(); return;
          case 2: getSkillType() = LIGHT; set(); return;
          case 3: getSkillType() = MEDIUM; set(); return;
          default: continue;
      }
  }
}

void Skills::contolerUpgradeSkill()
{
  for (;;)
  {
    if (learnPoints > 0)
    {
      clear();
      showLearnPoints();
      cout<<endl;
      showTreeName();
      show();
      cout<<"5. Wr��\n";

      cout<<"Wybierz dzia�anie: ";
      unsigned choice = setNumber<unsigned>();

      if (choice == 5) break;
      else if ((choice < 0) || (choice > AMOUNT_SKILLS)) continue;

      if (!upgrade(choice-1))
      {
          clear();
          cout<<Color::RED<<"Jeste� ju� mistrzem w tej sztuce!\n\n"<<Color::DEFAULT;
          cout<<Color::YELLOW<<"[OK]"<<Color::DEFAULT;
          paused();
      }
    }
    else
    {
        clear();
        cout<<Color::RED<<"Brak ci si� by opanowa� nowe sztuki walki!\n\n"<<Color::DEFAULT;
        cout<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
        paused();
        break;
    }
  }
}