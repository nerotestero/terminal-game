/***
*   Author: Stasiek Fortoński
*   Date: 2016 - 10.08.17
*   Basic Dialog Interpreter System
*   Version: 2
***/

#ifndef BASICDIALOGUEINTERPRETER_HPP
#define BASICDIALOGUEINTERPRETER_HPP 1
#include <iostream>
#include <vector>
#include "../../../interpreter/basic_interpreter.hpp"
#include "../../../libs/sets_types/sets_types.hpp"
#include "../../../libs/filetostring/filetostring.hpp"

using namespace std;

class BasicDialogueInterpreter
{
protected:
	FileToString file;

private:
	bool check(const string & command, const unsigned & numberLine, const unsigned & numberOfState);

public:
	BasicDialogueInterpreter(){}
	explicit BasicDialogueInterpreter(const std::string & fn): file(fn){}

	bool isNpcIssue(const unsigned & numberLine, const unsigned & numberOfState);
	bool isPlayerIssue(const unsigned & numberLine, const unsigned & numberOfState);
	bool isWorldAction(const unsigned & numberLine);
	bool isStartState(const unsigned & numberLine, const unsigned & numberOfState);
	bool isGetState(const unsigned & numberLine);
	bool isTrade(const unsigned & numberLine);
	bool isGiveItems(const unsigned & numberLine);
	bool isMission(const unsigned & numberLine);
	bool isGrouping(const unsigned & numberLine);
	bool isFight(const unsigned & numberLine);
	bool isEnd(const unsigned & numberLine);
	bool isExit(const unsigned & numberLine);
	unsigned getStateNumber(const unsigned & numberLine);
	std::string getInstance(const unsigned & numberLine);
	std::vector<std::string> getInstances(const unsigned & numberLine);
};
#endif