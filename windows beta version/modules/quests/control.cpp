#include "quests.hpp"
#include "../libs/sets_types/sets_types.hpp"
#include "../libs/screen/screen.hpp"
#include <vector>

using namespace std;
using namespace screen;

int Quests::ChooseMission() const
{
    for (;;)
    {
        clear();
        show();
        cout<<"Wybierz misje (q - powr�t): ";
        string choose = setString();

        if (choose == "q") return -1;

        unsigned n = atoi(choose.c_str());
        if (n > missions.size()) continue;

        return n-1;
    }
}

void Quests::ChooseInteraction(const unsigned & numberOfMission)
{
    for (;;)
    {
        clear();
        cout<<missions[numberOfMission];

        cout<<"1. Sprawad� szczeg��y misji\n";
        cout<<"2. Zrezygnuj z zadania\n";
        cout<<"3. Wr�c\n";
        cout<<"Wybierz dzia�anie: ";

        switch (setNumber<unsigned>())
        {
        case 1:
            clear();
            missions[numberOfMission].showNeeds();
            cout<<endl;
            cout<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
			paused();
            break;

        case 2:
            clear();
            missions.pop_back(numberOfMission);
            cout<<"Zrezygnowa�e� z zadania!\n\n";
            cout<<Color::YELLOW<<"[OK]"<<Color::DEFAULT;
            missions.save();
			paused();
            return;

        case 3:
        return;
        }

    }
}

void Quests::control()
{
    clear();
    if (missions.size() > 0)
    {
        int ch = ChooseMission();
        if (ch < 0) return;
        ChooseInteraction(ch);
    }
    else
    {
        cout<<"Obecnie masz brak zada� do wykonania.\n\n";
        cout<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
        paused();
    }
}

void Quests::endMission(Stats & me, const Stats & you)
{
	vector<unsigned> missionsid;
    for (unsigned i = 0; i < missions.size() ; ++i)
    {
        if (you.getInstance() == missions[i].getWhoGives())
			missionsid.push_back(i);
    }
		
    for (;;)
    {
		clear();
        if (missionsid.size() > 0)
        {
			for (unsigned i = 0; i < missionsid.size(); ++i)
				cout<<i+1<<". "<<missions[missionsid[i]]<<endl;
		
            cout<<"\nWybierz misje kt�r� chcesz zako�czy� (q - powr�t): ";
            string ch = setString();
            if (ch == "q") break;
				
            unsigned choice = atoi(ch.c_str());
            if ((choice > missionsid.size()) || (choice == 0)) continue;

            endMission(me, missionsid[choice-1]);
        }
        else
        {
            cout<<"Brak zada� od tej postaci.\n\n";
            cout<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
            paused();
        }
        return;
    }
}

void Quests::endMission(Stats & st, const unsigned & numberOfMission)
{
    clear();
    if (missions[numberOfMission].isEndOfMission(*inventory))
    {
        missions[numberOfMission].showAwards();
        cout<<endl;
        cout<<Color::YELLOW<<"[Dalej]"<<Color::DEFAULT;
        paused();
        missions[numberOfMission].getAwards(st, *inventory);
        missions.pop_back(numberOfMission);

        cout<<"\nZako�czy�e� zadanie pomy�lnie!\n\n";
        cout<<Color::YELLOW<<"[OK]"<<Color::DEFAULT;
        missions.save();
    }
    else
    {
        cout<<Color::RED<<"Nie mo�esz zako�czy� tej misji poniewa� niespe�niasz jej wymaga�!\n\n"<<Color::DEFAULT;
        cout<<Color::YELLOW<<"[Powr�t]"<<Color::DEFAULT;
    }
    paused();
}