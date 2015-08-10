#pragma once
#include "Command.h"
#include "MindMapModel.h"
class InsertNodeSiblingCommand :
	public Command
{
	friend class InsertNodeSiblingCommandTest;
	FRIEND_TEST(InsertNodeSiblingCommandTest, execute);
	FRIEND_TEST(InsertNodeSiblingCommandTest, unexecute);
public:
	InsertNodeSiblingCommand(string, int, MindMapModel*);
	void execute();
	void unexecute();
private:
	int NodeID;
	int DeleteNodeID;
	MindMapModel *Mindmapmodel;
	string Description;
};

