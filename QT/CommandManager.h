#pragma once
#include "Command.h"
#include <stack>
using namespace std;
class CommandManager
{
public:
	CommandManager();
	~CommandManager();
	void execute(Command*);
	bool redo();
	bool undo();
	int getModelUndoCommands();
	int getModelRedoCommands();
private:
	stack<Command*> ModelUndoCommands;
	stack<Command*> ModelRedoCommands;
};

