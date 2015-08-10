#include "CommandManager.h"


CommandManager::CommandManager()
{
}
CommandManager::~CommandManager()
{
	while (!ModelUndoCommands.empty())
	{
		Command* Command = ModelUndoCommands.top();
		ModelUndoCommands.pop();
		delete Command;
	}
	while (!ModelRedoCommands.empty()) 
	{
		Command* Command = ModelRedoCommands.top();
		ModelRedoCommands.pop();
		delete Command;
	}
}
void CommandManager::execute(Command* CommandExecute)
{
	CommandExecute->execute();
	ModelUndoCommands.push(CommandExecute);

	// cleanup and release redoable commands
	while (!ModelRedoCommands.empty()) 
	{
		Command* Command = ModelRedoCommands.top();
		ModelRedoCommands.pop();
		delete Command;
	}
}

bool CommandManager::redo()
{
	if (ModelRedoCommands.size() == 0)
		return false; // or throw exception

	Command* Command = ModelRedoCommands.top();
	ModelRedoCommands.pop();
	Command->execute(); // redo the command
	ModelUndoCommands.push(Command);
	return true;
}

bool CommandManager::undo()
{
	if (ModelUndoCommands.size() == 0)
		return false;

	Command* Command = ModelUndoCommands.top();
	ModelUndoCommands.pop();
	Command->unexecute(); // undo the command
	ModelRedoCommands.push(Command);
	return true;
}

int CommandManager::getModelUndoCommands()
{
	return ModelUndoCommands.size();
}
int CommandManager::getModelRedoCommands()
{
	return ModelRedoCommands.size();
}