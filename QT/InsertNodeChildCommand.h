#pragma once
#include "Command.h"
#include "MindMapModel.h"
class InsertNodeChildCommand :
	public Command
{
	friend class InsertNodeChildCommandTest;
	FRIEND_TEST(InsertNodeChildCommandTest, execute);
	FRIEND_TEST(InsertNodeChildCommandTest, unexecute);
public:
	InsertNodeChildCommand(string, int, MindMapModel*);
	void execute();
	void unexecute();
private:
	int NodeID;
	int CreateNodeID;
	MindMapModel *Mindmapmodel;
	string Description;
};

