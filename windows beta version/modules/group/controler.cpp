#include "group.hpp"
#include "../libs/screen/screen.hpp"
#include "../libs/sets_types/sets_types.hpp"

using namespace std;
using namespace screen;

unsigned Group::playerTargetContoler(const Group & grp)
{
  for (;;)
  {
    screen::clear();
    grp.show();

    cout<<"\nWybierz cel ataku: ";
    unsigned choice = setNumber<unsigned>()-1;

    if (choice < 0 || choice >= grp.size()) continue;
    else if (grp[choice]->isDead()) continue;

    return choice;
  }
}

void Group::controlOurTeam()
{
    for (;;)
    {
        clear();
        show();

        cout<<"\nWybierz cz�onka dru�yny (q - powr�t): ";
        string option = setString();
        if (option == "q") break;

        unsigned choice = atoi(option.c_str())-1;

        if (choice == 0)
        {
            clear();
            cout<<Color::RED<<"Nie mo�esz wybra� samego siebie!"<<Color::DEFAULT<<"\n\n";
            cout<<Color::YELLOW<<"[OK]"<<Color::DEFAULT;
            paused();
            continue;
        }
        else if (choice >= amount) continue;

        controlMember(choice);
    }
}

void Group::controlMember(const unsigned & choiced)
{
    for (;;)
    {
        clear();
        cout<<"Wybra�e� "<<mate[choiced]->getName()<<endl;
        cout<<"1. Zobacz szczeg��owe statystyki\n";
        cout<<"2. Wyrzu� z dru�yny\n";
        cout<<"3. Powr�t\n\n";
        cout<<"Wybierz dzia�anie: ";

        switch (setNumber<unsigned>())
        {
            case 1:
                clear();
                mate[choiced]->show();
                cout<<endl<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
                paused();
            break;

            case 2:
                pop_back(choiced);
            return;

            case 3:
                return;
        }
    }
}

void Group::addControl(Stats * st)
{
    clear();
    if (st->getLevel() < mate[0]->getLevel())
    {
        for (unsigned i = 1; i < MAXSIZE; ++i)
        {
            if (mate[i]->getInstance() == st->getInstance())
            {
                cout<<"Ju� jeste�cie w dru�ynie!\n\n";
                cout<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
                paused();
                return;
            }
        }

        for (;;)
        {
            showAdd(st);
            cout<<"Wybierz dzialanie: ";

            switch (setNumber<unsigned>())
            {
                case 1: push_back(st);
                return;
                case 2: return;
            }
        }
    }
    else
    {
        cout<<"Masz za niski poziom by doda� t� posta� do dru�yny!\n\n";
        cout<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
        paused();
    }
}