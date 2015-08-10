#pragma once
#include "Command.h"
#include "MindMapModel.h"

class PasteNodeCommand :
	public Command
{
public:
	PasteNodeCommand(int, MindMapModel*);
	void execute();
	void unexecute();
private:
	Component* PasteNode;
	Component* ParentNode;
	MindMapModel* Mindmapmodel;
	int NodeID;
};

