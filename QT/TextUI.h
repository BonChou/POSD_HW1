#pragma once
#include<string>
using namespace std;
#include "Constants.h"
#include "MindMapModel.h"
#include "Presentation.h"
#include "NodeVisitor.h"
#include "DisplayNodeVisitor.h"
class TextUI
{
public:
	TextUI();
	void run(Presentation*);
	void displayMenu();
	bool choiceInsertNode(Presentation*);
	void displayMap(Presentation*);
	void displayNodeList(Presentation*, unsigned int);
	void saveLevelLineList(Presentation*);
	void insertNode(Presentation*);
	void loadMap(Presentation*);
	void editNode(Presentation*);
	bool checkCommandChoice(string);
	void executeCommand(Presentation*, string);
private:
	int NodeID;
	int Level = 0;
	vector<bool>LevelLineList;
	string Description;
	string ChoiceNode;
	string NodeName;
	string MainMenu_choice;
};