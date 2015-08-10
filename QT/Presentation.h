#pragma once
#include<string>
#include "CommandManager.h"
#include "MindMapModel.h"
#include "CommandManager.h"
#include "EditComponentCommand.h"
#include "ChangeParentCommand.h"
#include "DeleteComponentCommand.h"
#include "InsertNodeChildCommand.h"
#include "InsertNodeSiblingCommand.h"
#include "InsertNodeParentCommand.h"
#include "NodeVisitor.h"
#include "DisplayNodeVisitor.h"
#include "SaveNodeVisitor.h"
#include "gtest/gtest.h"
using namespace std;
class Presentation 
{
	friend class PresentationTest;
	FRIEND_TEST(PresentationTest, initialCommand);
	FRIEND_TEST(PresentationTest, createMap);
public:
	Presentation(MindMapModel*);
	void createEditCommand(string, int);
	void createDeleteCommand(int);
	void createChangeParentCommand(int, int);
	void createInsertNodeParentCommand(string, int);
	void createInsertNodeChildCommand(string, int);
	void createInsertNodeSiblingCommand(string, int);
	void createMap(string);
	void initialCommand();
	bool checkMindMapExist();
	string displayMap();
	string getRootDescription();
	string saveMindMap();
	bool checkNodeExist(string);
	bool loadMindMap(string);
	int stringToInt(string);
	bool checkCommandChoice(string, int);
	bool checkInsertNode(string, int);
	bool redo();
	bool undo();
private:
	MindMapModel *Mindmapmodel;
	CommandManager Commandmanager;
	NodeVisitor *Visitor;
	int NodeID;
	string ChoiceNode;
	string NodeName;
	string Description;
};