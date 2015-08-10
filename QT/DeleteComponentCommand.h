#pragma once
#include "Command.h"
#include "MindMapModel.h"
#include "Component.h"
class DeleteComponentCommand :
	public Command
{
	friend class DeleteComponentCommandTest;
	FRIEND_TEST(DeleteComponentCommandTest, execute);
	FRIEND_TEST(DeleteComponentCommandTest, unexecute);
public:
	DeleteComponentCommand(int, MindMapModel*);
	void execute();
	void unexecute();
private:
	int NodeID;
	MindMapModel *Mindmapmodel;
	Component *BufferComponent;
};

