#include "TextUI.h"
TextUI::TextUI()
{
}
void TextUI::run(Presentation* PresentationModel)
{
	while (MainMenu_choice.compare(EXIT) != 0)
	{
		displayMenu();
		if (MainMenu_choice.compare(CREATE_MAP) == 0)
		{ 
			if (PresentationModel->checkMindMapExist() == true)
				cout << "MindMap was exist\n";
			else
			{
				cout << "Please enter the topic : ";
				getline(cin, Description);
				PresentationModel->createMap(Description);
			}
			cout << PresentationModel->displayMap();
		}
		else if (MainMenu_choice.compare(INSERT_NODE) == 0)
		{
			if (PresentationModel->checkMindMapExist() == false)
				cout << "Please create the MindMap\n";
			else
			{
				cout << PresentationModel->displayMap();
				insertNode(PresentationModel);
				if (ChoiceNode.compare(INSER_NODE_PARENT) == 0)
					PresentationModel->createInsertNodeParentCommand(NodeName, NodeID);
				else if (ChoiceNode.compare(INSER_NODE_CHILD) == 0)
					PresentationModel->createInsertNodeChildCommand(NodeName, NodeID);
				else if (ChoiceNode.compare(INSER_NODE_SIBLING) == 0)
					PresentationModel->createInsertNodeSiblingCommand(NodeName, NodeID);
				cout << PresentationModel->displayMap();
			}
		}
		else if (MainMenu_choice.compare(EDIT_NODE) == 0)
		{
			if (PresentationModel->checkMindMapExist() == false)
				cout << "Please create the MindMap\n";
			else
				editNode(PresentationModel);
		}
		else if (MainMenu_choice.compare(DISPALY_MAP) == 0)
			cout << PresentationModel->displayMap();
		else if (MainMenu_choice.compare(SAVE_MAP) == 0)
		{
			if (PresentationModel->checkMindMapExist() == false)
				cout << "Please create the MindMap\n";
			else
			{
				PresentationModel->initialCommand();
				cout << "The mind map " << PresentationModel->getRootDescription() << " is displayed as follows:\n" << PresentationModel->displayMap();
				cout << PresentationModel->saveMindMap();
			}
		}
		else if (MainMenu_choice.compare(LOAD_MAP) == 0)
			loadMap(PresentationModel);
		else if (MainMenu_choice.compare(REDO) == 0)
		{
			bool Success = PresentationModel->redo();
			if (Success == true)
			{
				cout << "The mind map " << PresentationModel->getRootDescription() << " is displayed as follows:\n" << PresentationModel->displayMap();
				cout << "-----------------------------" << endl;
			}
			else
				cout << "Can’t Redo!\n";
		}
		else if (MainMenu_choice.compare(UNDO) == 0)
		{
			bool Success = PresentationModel->undo();
			if (Success == true)
			{
				cout << "The mind map " << PresentationModel->getRootDescription() << " is displayed as follows:\n" << PresentationModel->displayMap();
				cout << "-----------------------------" << endl;
			}
			else
				cout << "Can’t Undo!\n";
		}
		else if (MainMenu_choice.compare(EXIT) == 0)
			PresentationModel->saveMindMap();
	}
}
void TextUI::editNode(Presentation *PresentationModel)
{
	bool Succes = false;
	while (Succes == false)
	{
		string StringID;
		cout << "The mind map " << PresentationModel->getRootDescription() << " is displayed as follows:\n" << PresentationModel->displayMap();
		cout << "-----------------------------" << endl;
		cout << "Enter the edit node ID:";;
		getline(cin, StringID);
		Succes = PresentationModel->checkNodeExist(StringID);
		NodeID = PresentationModel->stringToInt(StringID);
		if (Succes == false)
			cout << "The node is not exist!!\n";
	}
	Succes = false;
	string CommandChoice;
	while (Succes == false)
	{
		cout << "a.Edit the description of a node" << endl;
		cout << "b.Change the parent of a node" << endl;
		cout << "c.Delete a node" << endl;
		getline(cin, CommandChoice);
		Succes = checkCommandChoice(CommandChoice);
		if (Succes == false)
			cout << "The command is not found!!\n";
	}
	Succes = false;
	Succes = PresentationModel->checkCommandChoice(CommandChoice, NodeID);
	if (Succes == false && CommandChoice.compare(CHANGE_PARENT) == 0)
		cout << "Root can't be changed the parent.\n";
	else if (Succes == false && CommandChoice.compare(DELETE_COMPONENT) == 0)
		cout << "You can’t delete the root.\n";
	else
		executeCommand(PresentationModel, CommandChoice);
	cout << "The mind map " << PresentationModel->getRootDescription() << " is displayed as follows:\n" << PresentationModel->displayMap();
	cout << "-----------------------------" << endl;
}
void TextUI::executeCommand(Presentation *PresentationModel, string CommandChoice)
{
	if (CommandChoice.compare(EDIT_COMPONENT) == 0)
	{
		cout << "Enter the description :";
		getline(cin, Description);
		PresentationModel->createEditCommand(Description, NodeID);
	}
	else if (CommandChoice.compare(CHANGE_PARENT) == 0)
	{
		bool Succes = false;
		int ParentNodeID;
		while (Succes == false)
		{
			string StringID;
			cout << "Enter the parent ID:";;
			getline(cin, StringID);
			Succes = PresentationModel->checkNodeExist(StringID);
			ParentNodeID = PresentationModel->stringToInt(StringID);
			if (Succes == false)
				cout << "The node is not exist!!\n";
			if (ParentNodeID == NodeID)
			{
				cout << "You can’t select itself!!\n";
				Succes = false;
			}
		}
		PresentationModel->createChangeParentCommand(NodeID, ParentNodeID);
	}
	else if (CommandChoice.compare(DELETE_COMPONENT) == 0)
		PresentationModel->createDeleteCommand(NodeID);
}
bool TextUI::checkCommandChoice(string CommandChoice)
{
	if (CommandChoice.compare(EDIT_COMPONENT) == 0)
		return true;
	else if (CommandChoice.compare(CHANGE_PARENT) == 0)
		return true;
	else if (CommandChoice.compare(DELETE_COMPONENT) == 0)
		return true;
	else
		return false;
}
void TextUI::loadMap(Presentation *PresentationModel)
{
	string Path;
	cout << "Please input a file path:";
	getline(cin, Path);
	if (PresentationModel->loadMindMap(Path) == true)
	{
		cout << "The mind map " << PresentationModel->getRootDescription() << " is displayed as follows:\n" << PresentationModel->displayMap();
		cout << "-----------------------------" << endl;
	}
	else
		cout << "File not found!!\n";
}
void TextUI::insertNode(Presentation *PresentationModel)
{
	bool Succes = false;
	while (Succes == false)
	{
		string StringID;
		cout << "Enter the node ID : ";
		getline(cin, StringID);
		Succes = PresentationModel->checkNodeExist(StringID);
		NodeID = PresentationModel->stringToInt(StringID);
	}
	Succes = false;
	while (Succes == false)
	{
		Succes = choiceInsertNode(PresentationModel);
		if (Succes == false)
			cout << "Root can’t insert parent node" << endl;
	}
	cout << "Enter the node name:" << endl;
	getline(cin, NodeName);
}
void TextUI::displayMenu()
{
	cout << "-----------------------------" << endl;
	cout << "1. Create a new mind map" << endl;
	cout << "2. Insert a new node" << endl;
	cout << "3. Edit a node" << endl;
	cout << "4. Display mind map" << endl;
	cout << "5. Save mind map" << endl;
	cout << "6. Load a mind map" << endl;
	cout << "7. Redo" << endl;
	cout << "8. Undo" << endl;
	cout << "9. Exit" << endl;
	cout << "Please enter your choice:";
	getline(cin, MainMenu_choice);
}
bool TextUI::choiceInsertNode(Presentation *PresentationModel)
{
	bool Checkfail=false;
	while (Checkfail == false)
	{
		cout << "-----------------------------" << endl;
		cout << "a.Insert a parent node" << endl;
		cout << "b.Insert a child node" << endl;
		cout << "c.Insert a sibling node" << endl;
		getline(cin, ChoiceNode);
		if (ChoiceNode.compare(INSER_NODE_PARENT) == 0)
			return PresentationModel->checkInsertNode(ChoiceNode, NodeID);
		else if (ChoiceNode.compare(INSER_NODE_CHILD) == 0)
			return PresentationModel->checkInsertNode(ChoiceNode, NodeID);
		else if (ChoiceNode.compare(INSER_NODE_SIBLING) == 0)
			return PresentationModel->checkInsertNode(ChoiceNode, NodeID);
		else
			Checkfail = false;
	}
	return false;
}
