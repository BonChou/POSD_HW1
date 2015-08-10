#pragma once
#include "Command.h"
#include "MindMapModel.h"
class InsertNodeParentCommand :
	public Command
{
	friend class InsertNodeParentCommandTest;
	FRIEND_TEST(InsertNodeParentCommandTest, execute);
	FRIEND_TEST(InsertNodeParentCommandTest, unexecute);
public:
	InsertNodeParentCommand(string, int, MindMapModel*);
	void execute();
	void unexecute();
private:
	int NodeID;
	int CreateNodeID;
	MindMapModel *Mindmapmodel;
	string Description;
};

