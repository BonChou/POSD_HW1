#pragma once
#include "MindMapModel.h"
#include "Command.h"
class EditComponentCommand :
	public Command
{
	friend class EditComponentCommandTest;
	FRIEND_TEST(EditComponentCommandTest, execute);
	FRIEND_TEST(EditComponentCommandTest, unexecute);
public:
	EditComponentCommand(string, int, MindMapModel*);
	void execute();
	void unexecute();
private:
	string NewDescription;
	string OldDescription;
	int EditNodeID;
	MindMapModel *Mindmapmodel;
};