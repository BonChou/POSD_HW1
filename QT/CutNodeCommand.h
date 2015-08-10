#pragma once
#include "Command.h"
#include "MindMapModel.h"

class CutNodeCommand :
	public Command
{
public:
	CutNodeCommand(int, MindMapModel*);
	void execute();
	void unexecute();
private:
	MindMapModel* Mindmapmodel;
	Component* PasteNode;
	Component* ParentNode;

	int ParenteID;
	int NodeID;
};
