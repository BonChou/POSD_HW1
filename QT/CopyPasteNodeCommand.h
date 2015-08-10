#pragma once
#include "Command.h"
#include "MindMapModel.h"
class CopyPasteNodeCommand :
	public Command
{
public:
	CopyPasteNodeCommand(int, int, MindMapModel*);
	void execute();
	void unexecute();
private:
	MindMapModel* Mindmapmodel;
	int NodeID;
	int ParentNodeID;
};

