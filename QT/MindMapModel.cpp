#include "MindMapModel.h"
const int WIDTH = 300;
const int LENGH = 200;
MindMapModel::MindMapModel()
{
}
MindMapModel::~MindMapModel()
{
	delete PointNode;
	for (unsigned int IndexDelete = ZERO; IndexDelete < MindMap.size(); IndexDelete++)
		delete MindMap[IndexDelete];
}
void MindMapModel::createMindMap(string Description)
{
	MindMap.push_back(CreatMap.createRoot(Description, ROOT_NODE));
}
vector<Component*> MindMapModel::getMindMap()
{
	return MindMap;
}

int MindMapModel::createNode(string NodeName)
{
	MindMap.push_back(CreatMap.createNode(NodeName, CreateNewNodeID));
	int Temp = CreateNewNodeID;
	CreateNewNodeID++;
	return Temp;
}
void MindMapModel::insertNodeChild(int InsertNodeID, int InsertNewNodeID)
{
	int InsertNodeIndex = getRealNodeID(InsertNodeID);
	int InsertNewNodeIndex = getRealNodeID(InsertNewNodeID);
	Component* InsertNode = MindMap[InsertNodeIndex];
	Component* InsertNewNode = MindMap[InsertNewNodeIndex];
	InsertNewNode->addParent(InsertNode);
	InsertNode->addChild(InsertNewNode);
}
void MindMapModel::insertNodeSibling(int InsertNodeID, int InsertNewNodeID)
{
	int InsertNodeIndex = getRealNodeID(InsertNodeID);
	int InsertNewNodeIndex = getRealNodeID(InsertNewNodeID);
	Component* InsertNode = MindMap[InsertNodeIndex];
	Component* InsertNewNode = MindMap[InsertNewNodeIndex];
	InsertNewNode->addParent(InsertNode->ParentNode);
	InsertNode->ParentNode->addChild(InsertNewNode);
}
void MindMapModel::insertNodeParent(int InsertNodeID, int InsertNewNodeID)
{
	int InsertNodeIndex = getRealNodeID(InsertNodeID);
	int InsertNewNodeIndex = getRealNodeID(InsertNewNodeID);
	Component* InsertNode = MindMap[InsertNodeIndex];
	Component* InsertNewNode = MindMap[InsertNewNodeIndex];
	Component* ParentTemp;
	ParentTemp = InsertNode->ParentNode;
	InsertNewNode->addParent(InsertNode->ParentNode);
	InsertNode->addParent(InsertNewNode);
	InsertNewNode->addChild(InsertNode);
	ParentTemp->addChild(InsertNode);
}
int MindMapModel::stringToInt(string String)
{
	int Number = ZERO;
	stringstream Convert(String);
	Convert >> Number;
	return Number;
}
string MindMapModel::intTostr(int &Index)
{
	string String;
	stringstream Convert(String);
	Convert << Index;
	return Convert.str();
}
string MindMapModel::getRootDescription()
{
	return MindMap[ROOT_NODE]->getDescription();
}
bool MindMapModel::checkNodeExist(string StringID)
{
	string NodeID;
	int IntTostrNode;
	for (unsigned int IndexCheck = ZERO; IndexCheck < MindMap.size(); IndexCheck++)
	{
		IntTostrNode = MindMap[IndexCheck]->getID();
		NodeID = intTostr(IntTostrNode);
		if (NodeID.compare(StringID) == ZERO)
			return true;
	}
	return false;
}
bool MindMapModel::checkMindMapExist()
{
	if (MindMap.size() == ZERO)
		return false;
	else 
		return true;
}
bool MindMapModel::checkInsertNode(string ChoiceInsertNode, int NodeID)
{
	int EditNodeID = getRealNodeID(NodeID);
	if (EditNodeID != NOTEXISTNODE)
	{
		if (ChoiceInsertNode.compare(INSER_NODE_PARENT) == ZERO)
			return MindMap[EditNodeID]->addParent();
		else if (ChoiceInsertNode.compare(INSER_NODE_CHILD) == ZERO)
			return MindMap[EditNodeID]->addChild();
		else if (ChoiceInsertNode.compare(INSER_NODE_SIBLING) == ZERO)
			return MindMap[EditNodeID]->addSibling();
	}
	return false;
}
string MindMapModel::displayMap()
{
	if (MindMap.size() != ZERO)
	{
		Visitor = new DisplayNodeVisitor();
		MindMap[ROOT_NODE]->accept(Visitor);
		CoutString = Visitor->getCoutString();
		vector<Component*> Pointer;
		Pointer = MindMap[ROOT_NODE]->getNodeList();
		displayNodeList(Pointer, FIRST_NODE);
		return CoutString;
	}
	else
		return "MindMap is not exist!!\n";
}
void MindMapModel::displayNodeList(vector<Component*> MindMapPointer, unsigned int NodePoint)
{
	vector<Component*> Pointer;
	Component* ParentPointer;//存父節點位置
	while (NodePoint < MindMapPointer.size())//尋找是否沒平輩
	{
		ParentPointer = MindMapPointer[NodePoint]->ParentNode;
		saveLevelLineList(ParentPointer);
		for (int Index = ZERO; Index <= Level; Index++)
		{
			if (LevelLineList[LevelLineList.size() - 1] == true)
			{
				CoutString += "| ";
				LevelLineList.pop_back();
			}
			else
			{
				CoutString += "  ";
				LevelLineList.pop_back();
			}
		}
		MindMapPointer[NodePoint]->accept(Visitor);
		CoutString += Visitor->getCoutString();

		if (MindMapPointer[NodePoint]->getNodeList().size() != ZERO)//判斷是否有child 有在下去
		{
			Pointer = MindMapPointer[NodePoint]->getNodeList();
			Level++;
			displayNodeList(Pointer, FIRST_NODE);//下去下一層NodePoint變回第一個點 
			Level--;
		}
 		NodePoint++;
	}
}
void MindMapModel::saveLevelLineList(Component* ParentPointer)
{
	bool LevelLine;
	while (ParentPointer != NULL)
	{
		Component* GrandfatherPointer;
		GrandfatherPointer = ParentPointer->ParentNode;//存爺爺節點位置
		if (GrandfatherPointer == NULL)//如果爺爺位置是NULL 直接給false
		{
			LevelLine = false;
			LevelLineList.push_back(LevelLine);
		}
		else if (GrandfatherPointer->getNodeList()[GrandfatherPointer->getNodeList().size() - 1]->getID() == ParentPointer->getID())//如果父節點已經是平輩最後一個
		{
			LevelLine = false;
			LevelLineList.push_back(LevelLine);
		}
		else
		{
			LevelLine = true;
			LevelLineList.push_back(LevelLine);
		}
		ParentPointer = ParentPointer->ParentNode;
	}
}
string MindMapModel::saveMindMap(string PATH)
{
	if (MindMap.size() == ZERO)
		return "No MindMap!\n";
	else
	{
		Visitor = new SaveNodeVisitor();
		for (unsigned int IndexMap = ZERO; IndexMap < MindMap.size(); IndexMap++)
			MindMap[IndexMap]->setID(IndexMap);
		fstream FileInput;
		FileInput.open(PATH, ios::out);
		MindMap[ROOT_NODE]->accept(Visitor);
		FileInput << Visitor->getCoutString();
		for (unsigned int IndexMap = NODE_NODE; IndexMap < MindMap.size(); IndexMap++)
		{
			MindMap[IndexMap]->accept(Visitor);
			//cout << Visitor->getCoutString();
			FileInput << Visitor->getCoutString();
		}
		FileInput.close();
		return "Save success!\n";
	}
}
string MindMapModel::saveMindMap()
{
	if (MindMap.size() == ZERO)
		return "No MindMap!\n";
	else
	{
		for (unsigned int IndexMap = ZERO; IndexMap < MindMap.size(); IndexMap++)
			MindMap[IndexMap]->setID(IndexMap);
		fstream FileInput;
		FileInput.open(PATH, ios::out);
		FileInput << ROOT_NODE << " \"" << MindMap[ROOT_NODE]->getDescription() << "\" ";
		for (unsigned int IndexList = ZERO; IndexList < MindMap[ROOT_NODE]->getNodeList().size(); IndexList++)
			FileInput << MindMap[ROOT_NODE]->getNodeList()[IndexList]->getID() << " ";
		for (unsigned int IndexMap = NODE_NODE; IndexMap < MindMap.size(); IndexMap++)
		{
			FileInput << endl << IndexMap << " \"" << MindMap[IndexMap]->getDescription() << "\" ";
			for (unsigned int IndexList = ZERO; IndexList < MindMap[IndexMap]->getNodeList().size(); IndexList++)
				FileInput << MindMap[IndexMap]->getNodeList()[IndexList]->getID() << " ";
		}
		FileInput.close();
		return "Save success!\n";
	}
}

int MindMapModel::getRealNodeID(int NodeID)
{
	int MindMapID = NOTEXISTNODE;
	for (unsigned int IndexID = ZERO; IndexID < MindMap.size(); IndexID++)
		if (MindMap[IndexID]->getID() == NodeID)
			MindMapID = IndexID;
	return MindMapID;
}
bool MindMapModel::checkCommandChoice(string CommandChoice, int NodeID)
{
	int MindMapID = getRealNodeID(NodeID);
	if (CommandChoice.compare(CHANGE_PARENT) == ZERO && MindMap[MindMapID]->getType().compare(ROOT) == ZERO)
		return false;
	if (CommandChoice.compare(DELETE_COMPONENT) == ZERO && MindMap[MindMapID]->getType().compare(ROOT) == ZERO)
		return false;
	else
		return true;
}
string MindMapModel::editComponent(string NewDescription, int EditNodeID)
{
	string OldDescription;
	int EditNodeIndex = getRealNodeID(EditNodeID);
	OldDescription = MindMap[EditNodeIndex]->getDescription();
	MindMap[EditNodeIndex]->setDescription(NewDescription);
	return OldDescription;
}
bool MindMapModel::changeParent(int NodeID, int ParentNodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	vector<Component*> ChildPointer = MindMap[NodeIndex]->getNodeList();
	bool CheckChangeParentType = sortChangeParent(ChildPointer, FIRST_NODE, ParentNodeID);
	return CheckChangeParentType;
}
bool MindMapModel::sortChangeParent(vector<Component*> MindMapPointer, unsigned int NodePoint, int ParentNodeID)
{
	vector<Component*> Pointer;
	bool CheckChangeParentType = false;
	while (NodePoint < MindMapPointer.size())//尋找是否沒平輩
	{
		if (MindMapPointer[NodePoint]->getID() == ParentNodeID)
			return true;
		if (MindMapPointer[NodePoint]->getNodeList().size() != ZERO)//判斷是否有child 有在下去
		{
			Pointer = MindMapPointer[NodePoint]->getNodeList();
			CheckChangeParentType = sortChangeParent(Pointer, FIRST_NODE, ParentNodeID);//下去下一層NodePoint變回第一個點
		}
		NodePoint++;
	}
	if (CheckChangeParentType == true)
		return true;
	return false;
}
vector<Component*> MindMapModel::changeParentInChild(int NodeID, int ParentNodeID)//本身插到轉換的Parent下面 並兒子往上一輩
{
	int ChangeMindMapID = getRealNodeID(NodeID);;
	int ParentMindMapID = getRealNodeID(ParentNodeID);
	vector<Component*> ChildPointer = MindMap[ChangeMindMapID]->getNodeList();
	OldPointer = MindMap[ChangeMindMapID]->ParentNode;
	Component* ChangedComponent = deleteComponent(ChangeMindMapID);
	MindMap.insert(MindMap.begin() + ChangedComponent->getID(), ChangedComponent);
	ChangedComponent->addParent(MindMap[ParentMindMapID]);
	ChangedComponent->deleteNodeList();//刪除所有兒子
	MindMap[ParentMindMapID]->addChild(ChangedComponent);
	return ChildPointer;
}
int MindMapModel::changeParentInAnother(int NodeID, int ParentNodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	int ParentNodeIndex = getRealNodeID(ParentNodeID);
	Component* ParentPointer = MindMap[NodeIndex]->ParentNode;
	int OldParentNodeID = ParentPointer->getID();
	for (unsigned int IndexChild = ZERO; IndexChild < ParentPointer->getNodeList().size(); IndexChild++)
		if (ParentPointer->getNodeList()[IndexChild]->getID() == MindMap[NodeIndex]->getID())
			ParentPointer->deleteNodeList(IndexChild);//刪除此ID的兒子關係
	MindMap[ParentNodeIndex]->addChild(MindMap[NodeIndex]);
	MindMap[NodeIndex]->addParent(MindMap[ParentNodeIndex]);
	return OldParentNodeID;
}
void MindMapModel::undoChangeParentInChild(int NodeID, int ParentNodeID, vector<Component*> OldComponentChild)
{
	int MindMapID = getRealNodeID(NodeID);
	int ParentNodeIndex = getRealNodeID(ParentNodeID);
	Component* ParentPointer = MindMap[ParentNodeIndex]->ParentNode;
	MindMap[MindMapID]->addParent(OldPointer);
	ParentPointer->addChild(MindMap[MindMapID]);
	for (unsigned int IndexOld = ZERO; IndexOld < OldComponentChild.size(); IndexOld++)
	{
		MindMap[MindMapID]->addChild(OldComponentChild[IndexOld]);
		OldComponentChild[IndexOld]->addParent(MindMap[MindMapID]);
		for (unsigned int IndexChild = ZERO; IndexChild < ParentPointer->getNodeList().size(); IndexChild++)
			if (ParentPointer->getNodeList()[IndexChild]->getID() == OldComponentChild[IndexOld]->getID())
				ParentPointer->deleteNodeList(IndexChild);//刪除此ID的兒子
	}
	for (unsigned int IndexChild = ZERO; IndexChild < MindMap[ParentNodeIndex]->getNodeList().size(); IndexChild++)
		if (MindMap[ParentNodeIndex]->getNodeList()[IndexChild]->getID() == MindMap[MindMapID]->getID())
			MindMap[ParentNodeIndex]->deleteNodeList(IndexChild);//刪除此ID的兒子關係
}



Component* MindMapModel::deleteComponent(int DeleteNodeID)
{
	DeleteNodeIndex = getRealNodeID(DeleteNodeID);
	Component* ParentPointer = MindMap[DeleteNodeIndex]->ParentNode;
	vector<Component*> ChildPointer = MindMap[DeleteNodeIndex]->getNodeList();
	Component* BufferComponent = MindMap[DeleteNodeIndex];
	for (unsigned int IndexChild = ZERO; IndexChild < ChildPointer.size(); IndexChild++)
	{
		ChildPointer[IndexChild]->addParent(ParentPointer);
		ParentPointer->addChild(ChildPointer[IndexChild]);
	}
	for (unsigned int IndexChild = ZERO; IndexChild < ParentPointer->getNodeList().size(); IndexChild++)
		if (ParentPointer->getNodeList()[IndexChild]->getID() == DeleteNodeID)
			ParentPointer->deleteNodeList(IndexChild);

	MindMap.erase(MindMap.begin() + DeleteNodeIndex);
	return BufferComponent;
}
int MindMapModel::createComponent(Component* CreateComponent)
{
	MindMap.insert(MindMap.begin() + DeleteNodeIndex, CreateComponent);
	
	Component* ParentPointer = CreateComponent->ParentNode;
	vector<Component*> ChildPointer = CreateComponent->getNodeList();
	for (unsigned int IndexChild = ZERO; IndexChild < ChildPointer.size(); IndexChild++)
	{
		ChildPointer[IndexChild]->addParent(CreateComponent);
		for (unsigned int IndexOld = ZERO; IndexOld < ParentPointer->getNodeList().size(); IndexOld++)
			if (ParentPointer->getNodeList()[IndexOld]->getID() == ChildPointer[IndexChild]->getID())
				ParentPointer->deleteNodeList(IndexOld);//刪除此ID的兒子
	}
	ParentPointer->addChild(CreateComponent);
	return CreateComponent->getID();
}


bool MindMapModel::loadMindMap(string Path)
{
	fstream File;
	string Token = "";
	string GraphicToken = "";
	vector<string> Name;
	vector<string> ChildID;
	vector<string> GraphicTokenList;
	File.open(Path, ios::in);
	if (!File)
		return false;
	else 
	{
		while (!File.eof())
		{
			getline(File, Token, ' '); // 讀ID
			getline(File, Token, '"'); // 把"讀掉
			getline(File, Token, '"'); // 讀名字
			Name.push_back(Token);
			getline(File, Token, '/'); // 讀擁有的NODE ID(沒有數字的會放入"")
			getline(File, GraphicToken, '\n');
			ChildID.push_back(Token);
			GraphicTokenList.push_back(GraphicToken);
		}

		for (unsigned int IndexDelete = ZERO; IndexDelete < MindMap.size(); IndexDelete++)
			delete MindMap[IndexDelete];
		MindMap.clear();
		CreateNewNodeID = 1;
		buildTree(Name);
		cutIdLine(ChildID);
		cutGraphicLine(GraphicTokenList);
		return true;
	}

}

void MindMapModel::buildTree(vector<string> Node) 
{
	for (unsigned int index = ZERO; index < Node.size(); index++)
	{
		if (index == ROOT_NODE)
			createMindMap(Node[index]);
		else 
			createNode(Node[index]);
	}
}

void MindMapModel::cutIdLine(vector<string> Child)
{
	for (unsigned int Index = ZERO; Index < Child.size(); Index++)
		if (Child[Index] != "")
			bulidChild(Index, Child[Index]);
}
void MindMapModel::cutGraphicLine(vector<string> GraphicTokenList)
{
	for (unsigned int Index = ZERO; Index < GraphicTokenList.size(); Index++)
		if (GraphicTokenList[Index] != "")
			bulidGraphic(Index, GraphicTokenList[Index]);
}

void MindMapModel::bulidGraphic(int NodeID, string GraphicTypeLine)
{
	for (unsigned int Index = 0; Index < GraphicTypeLine.length(); Index++)
	{
		if (GraphicTypeLine[Index] != '/')
		{
			string GraphicType = GraphicTypeLine.substr(Index, 1);
			createGrahic(GraphicType, NodeID);
		}
	}
}

void MindMapModel::bulidChild(int ParentId, string IDLine)
{
	int Length = IDLine.length();
	for (int Index = ONE; Index < Length;)
	{ // 因為第0格是' '
		int Temp = Index, Count = ZERO;
		for (; Temp < Length && IDLine[Temp] != ' '; Temp++)
		{ // 讀到空格或是底了
			Count++; // 判斷要印幾個
		}
		string StrID = IDLine.substr(Index, Count);
		int ID = stringToInt(StrID);
		insertNodeChild(ParentId, ID);
		Index = Temp + ONE;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void MindMapModel::initialPosition()
{
	PosCountY = ZERO;
	NegCountY = ZERO;
	CountX = ZERO;

	for (unsigned int Index = ZERO; Index < MindMap.size(); Index++) //設所有的位置
	{
		MindMap[Index]->setX(ZERO);
		MindMap[Index]->setY(ZERO);
		MindMap[Index]->Select = false;
	}
	setPositionX(MindMap[ROOT_NODE]);
	setPositionY(MindMap[ROOT_NODE]);
	setIsExpandPosition(MindMap[ROOT_NODE]);
	Visitor = new DisplayNodeVisitor();
	//cout << displayMap() << "\n---------------------------------------------\n";
	this->notify();
}
void MindMapModel::setIsExpandPosition(Component* ComponentPoint)
{
	unsigned int Index = ZERO;
	while (Index < ComponentPoint->getNodeList().size())
	{
		if (ComponentPoint->getNodeList()[Index]->IsExpand == false)
		{
			ComponentPoint->getNodeList()[Index]->setX(ComponentPoint->getX());
			ComponentPoint->getNodeList()[Index]->setY(ComponentPoint->getY());
		}
		setIsExpandPosition(ComponentPoint->getNodeList()[Index]);
		Index++;
	}

}

void MindMapModel::setPositionX(Component* ComponentPoint)
{
	if (ComponentPoint->getX() == 0)
		CountX = ComponentPoint->getNodeList().size() - (ComponentPoint->getNodeList().size() / 2);
	unsigned int Index = ZERO;
	while (Index < ComponentPoint->getNodeList().size())
	{
		if (ComponentPoint->getX() == 0)
		{
			if (Index < CountX)
			{
				ComponentPoint->getNodeList()[Index]->setX(ComponentPoint->getX() + WIDTH);
				ComponentPoint->getNodeList()[Index]->setY(PosCountY++);

			}
			else
			{
				ComponentPoint->getNodeList()[Index]->setX(ComponentPoint->getX() - WIDTH);
				ComponentPoint->getNodeList()[Index]->setY(NegCountY++);
			}
		}
		else
		{
			if (ComponentPoint->getX() > 0)
			{
				ComponentPoint->getNodeList()[Index]->setX(ComponentPoint->getX() + WIDTH);
				ComponentPoint->getNodeList()[Index]->setY(PosCountY++);
			}
			else
			{
				ComponentPoint->getNodeList()[Index]->setX(ComponentPoint->getX() - WIDTH);
				ComponentPoint->getNodeList()[Index]->setY(NegCountY++);
			}
		}
		setPositionX(ComponentPoint->getNodeList()[Index]);
		Index++;
	}
}

void MindMapModel::setPositionY(Component* ComponentPoint)
{
	unsigned int Index = ZERO;
	while (Index < ComponentPoint->getNodeList().size())
	{
		int Ycount = ComponentPoint->getNodeList()[Index]->getY();
		ComponentPoint->getNodeList()[Index]->setY(Ycount*LENGH);
		setPositionY(ComponentPoint->getNodeList()[Index]);
		Index++;
	}
	int LastNode = ComponentPoint->getNodeList().size() - ONE;
	if (LastNode >= ZERO)
		ComponentPoint->setY((ComponentPoint->getNodeList()[ZERO]->getY() + ComponentPoint->getNodeList()[LastNode]->getY()) / 2);

}

int MindMapModel::sortChoiceNodeID()
{
	unsigned int ChoiceNodeID = PLUS_ONE;
	for (unsigned int Index = ZERO; Index < MindMap.size(); Index++)
	{
		if (MindMap[Index]->Select == true)
			ChoiceNodeID = MindMap[Index]->getID();
	}
	return ChoiceNodeID;
}

void MindMapModel::cutComponent(int NodeID)
{
	for (unsigned int Index = ZERO; Index < MindMap.size(); Index++)
		MindMap[Index]->Copystate = false;
	ClonFlag = false;
	PasteFlag = true;
	int NodeIndex = getRealNodeID(NodeID);
	PasteNode = MindMap[NodeIndex];
	Component* ParentPointer = MindMap[NodeIndex]->ParentNode;
	for (unsigned int IndexChild = ZERO; IndexChild < ParentPointer->getNodeList().size(); IndexChild++)
		if (ParentPointer->getNodeList()[IndexChild]->getID() == MindMap[NodeIndex]->getID())
			ParentPointer->deleteNodeList(IndexChild);//刪除此ID的兒子關係

}
void MindMapModel::setClonNodeID(Component* ClonNode)
{
	MindMap.push_back(ClonNode);
	ClonNode->setID(CreateNewNodeID);
	CreateNewNodeID++;
}
void MindMapModel::deleteClonNodeID(Component* ClonNode)
{
	int ClonIndex = getRealNodeID(ClonNode->getID());
	MindMap.erase(MindMap.begin() + ClonIndex);
	CreateNewNodeID--;
	for (unsigned int Index = ZERO; Index < ClonNode->getNodeList().size(); Index++)
		deleteClonNodeID(ClonNode->getNodeList()[Index]);
}
void MindMapModel::undoPasteComponent(Component* PasteNode)
{
	for (unsigned int IndexChild = ZERO; IndexChild < PasteNode->ParentNode->getNodeList().size(); IndexChild++)
		if (PasteNode->ParentNode->getNodeList()[IndexChild]->getID() == PasteNode->getID())
			PasteNode->ParentNode->deleteNodeList(IndexChild);//刪除此ID的兒子關係
	if (ClonFlag == true)
		deleteClonNodeID(PasteNode);
}

Component* MindMapModel::pasteComponent(int NodeID)
{
	if (ClonFlag == true)
	{
		PasteNode = PasteNode->clon();
		setClonNodeID(PasteNode);
		for (unsigned int Index = ZERO; Index < PasteNode->getNodeList().size(); Index++)
		{
			setClonNodeID(PasteNode->getNodeList()[Index]);
			sortClonNode(PasteNode->getNodeList()[Index]);
		}
	}
	if (ClonFlag == false)
		PasteFlag = false;

	int NodeIndex = getRealNodeID(NodeID);
	MindMap[NodeIndex]->addChild(PasteNode);
	PasteNode->addParent(MindMap[NodeIndex]);
	return PasteNode;
}
void MindMapModel::sortClonNode(Component* ClonNode)
{
	for (unsigned int Index = ZERO; Index < ClonNode->getNodeList().size(); Index++)
	{
		setClonNodeID(ClonNode->getNodeList()[Index]);
		sortClonNode(ClonNode->getNodeList()[Index]);
	}
}

void MindMapModel::clonComponent(int ChoiceNodeID)
{
	for (unsigned int Index = ZERO; Index < MindMap.size(); Index++)
		MindMap[Index]->Copystate = false;
	//cout << "Copy :" << ChoiceNodeID << " \n";
	ClonFlag = true;
	PasteFlag = true;
	copyGraphicComponent(ChoiceNodeID);
	int ChoiceNodeIndex = getRealNodeID(ChoiceNodeID);
	PasteNode = MindMap[ChoiceNodeIndex];
}


void MindMapModel::copyGraphicComponent(int NodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	MindMap[NodeIndex]->Copystate = true;
	for (unsigned int Index = ZERO; Index < MindMap[NodeIndex]->getNodeList().size(); Index++)
	{
		changeCopyComponentState(MindMap[NodeIndex]->getNodeList()[Index]);
		MindMap[NodeIndex]->getNodeList()[Index]->Copystate = true;
	}
}

void MindMapModel::changeCopyComponentState(Component* BufferComponent)
{
	for (unsigned int Index = ZERO; Index < BufferComponent->getNodeList().size(); Index++)
	{
		changeCopyComponentState(BufferComponent->getNodeList()[Index]);
		BufferComponent->getNodeList()[Index]->Copystate = true;
	}
}

void MindMapModel::createGrahic(string Type, int NodeID)
{
	if (Type.compare(CIRCLE) == 0)
	{
		int NodeIndex = getRealNodeID(NodeID);
		Component* Buffer = CreatMap.createCircle();
		Buffer->setX(MindMap[NodeIndex]->getX());
		Buffer->setY(MindMap[NodeIndex]->getY());
		MindMap[NodeIndex]->GraphicList.push_back(Buffer);
	}
	if (Type.compare(RECTANGLE) == 0)
	{
		int NodeIndex = getRealNodeID(NodeID);
		Component* Buffer = CreatMap.createRectangle();
		Buffer->setX(MindMap[NodeIndex]->getX());
		Buffer->setY(MindMap[NodeIndex]->getY());
		MindMap[NodeIndex]->GraphicList.push_back(Buffer);
	}
	if (Type.compare(TRINAGLE) == 0)
	{
		int NodeIndex = getRealNodeID(NodeID);
		Component* Buffer = CreatMap.createTrinagle();
		Buffer->setX(MindMap[NodeIndex]->getX());
		Buffer->setY(MindMap[NodeIndex]->getY());
		MindMap[NodeIndex]->GraphicList.push_back(Buffer);
	}
}

void MindMapModel::deleteGrahic(int NodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	MindMap[NodeIndex]->GraphicList.pop_back();
}
int MindMapModel::sortNodeList(int NodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	for (unsigned int NodeListIndex = 0; NodeListIndex < MindMap[NodeIndex]->ParentNode->getNodeList().size(); NodeListIndex++)
		if (MindMap[NodeIndex]->ParentNode->getNodeList()[NodeListIndex]->getID() == MindMap[NodeIndex]->getID())
			return NodeListIndex;
	return NULL;
}
void MindMapModel::changeNodeListPosition(int NodeListIndex1, int NodeListIndex2, Component* ParentNode)
{
	ParentNode->ChangeNodeList(NodeListIndex1, NodeListIndex2);
}
void MindMapModel::expandGraphic(int NodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	MindMap[NodeIndex]->isCollapsed = false;
	for (unsigned int Index = ZERO; Index < MindMap[NodeIndex]->getNodeList().size(); Index++)
	{
		changeIsExpandState(MindMap[NodeIndex]->getNodeList()[Index], true);
		MindMap[NodeIndex]->getNodeList()[Index]->IsExpand = true;
	}
}
void MindMapModel::collapseGraphic(int NodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	MindMap[NodeIndex]->isCollapsed = true;
	for (unsigned int Index = ZERO; Index < MindMap[NodeIndex]->getNodeList().size(); Index++)
	{
		changeIsExpandState(MindMap[NodeIndex]->getNodeList()[Index], false);
		MindMap[NodeIndex]->getNodeList()[Index]->IsExpand = false;
	}
}
void MindMapModel::changeIsExpandState(Component* BufferComponent,bool ChangeState)
{
	for (unsigned int Index = ZERO; Index < BufferComponent->getNodeList().size(); Index++)
	{
		changeIsExpandState(BufferComponent->getNodeList()[Index], ChangeState);
		BufferComponent->getNodeList()[Index]->IsExpand = ChangeState;
	}
}

void MindMapModel::expandOneGraphic(int NodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	MindMap[NodeIndex]->isCollapsedOne = false;
	for (unsigned int Index = ZERO; Index < MindMap[NodeIndex]->getNodeList().size(); Index++)
		MindMap[NodeIndex]->getNodeList()[Index]->IsExpand = true;
}
void MindMapModel::collapseOneGraphic(int NodeID)
{
	int NodeIndex = getRealNodeID(NodeID);
	MindMap[NodeIndex]->isCollapsedOne = true;
	for (unsigned int Index = ZERO; Index < MindMap[NodeIndex]->getNodeList().size(); Index++)
		MindMap[NodeIndex]->getNodeList()[Index]->IsExpand = false;
}