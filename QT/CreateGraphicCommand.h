#pragma once
#include "Command.h"
#include "MindMapModel.h"

class CreateGraphicCommand :
	public Command
{
public:
	CreateGraphicCommand(MindMapModel*, string, int);
	void execute();
	void unexecute();
private:
	int NodeID;
	MindMapModel *Mindmapmodel;
	string Type;
};

