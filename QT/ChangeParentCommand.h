#pragma once
#include "Command.h"
#include "MindMapModel.h"
#include "Component.h"
class ChangeParentCommand :
	public Command
{
	friend class ChangeParentCommandTest;
	FRIEND_TEST(ChangeParentCommandTest, execute);
	FRIEND_TEST(ChangeParentCommandTest, unexecute);
public:
	ChangeParentCommand(int, int, MindMapModel*);
	void execute();
	void unexecute();
private:
	int NodeID;
	int ParentNodeID;
	bool CheckChangeParentType;
	MindMapModel* Mindmapmodel;
	vector<Component*> OldComponentChild;
};

