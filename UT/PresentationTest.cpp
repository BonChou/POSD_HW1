#include "PresentationTest.h"


PresentationTest::PresentationTest()
{
}


PresentationTest::~PresentationTest()
{
}

void PresentationTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	PresentationCommand = new Presentation(Mindmapmodel);
}
void PresentationTest::TearDown()
{
	delete Mindmapmodel;
	delete PresentationCommand;
}

TEST_F(PresentationTest, createEditCommand)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getDescription(), "Root");
	PresentationCommand->createEditCommand("RootGX", 0);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getDescription(), "RootGX");
}
TEST_F(PresentationTest, createChangeParentCommand)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 0);
	PresentationCommand->createChangeParentCommand(1, 3);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 3);
}
TEST_F(PresentationTest, createDeleteCommand)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[0]->getID(), 1);
	PresentationCommand->createDeleteCommand(1);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getID(), 2);
}
TEST_F(PresentationTest, createInsertNodeChildCommand)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	PresentationCommand->createInsertNodeChildCommand("Node4", 3);
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getID(), 4);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->getNodeList()[0]->getID(), 4);
}
TEST_F(PresentationTest, createInsertNodeSiblingCommand)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	PresentationCommand->createInsertNodeSiblingCommand("Node4", 3);
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getID(), 4);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[2]->getID(), 4);
}
TEST_F(PresentationTest, createInsertNodeParentCommand)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	PresentationCommand->createInsertNodeParentCommand("Node4", 3);
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getID(), 4);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getID(), 4);
}
TEST_F(PresentationTest, redo)
{
	ASSERT_FALSE(PresentationCommand->redo());
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	ASSERT_FALSE(PresentationCommand->undo());
}
TEST_F(PresentationTest, undo)
{
	ASSERT_FALSE(PresentationCommand->undo());
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	ASSERT_FALSE(PresentationCommand->undo());
}

TEST_F(PresentationTest, initialCommand)
{
	PresentationCommand->initialCommand();
}

TEST_F(PresentationTest, displayMap)
{
	ASSERT_EQ(PresentationCommand->displayMap(), "MindMap is not exist!!\n");
}

TEST_F(PresentationTest, createMap)
{
	PresentationCommand->createMap("a");
	ASSERT_EQ(Mindmapmodel->getMindMap()[0]->getDescription(), "a");
}

TEST_F(PresentationTest, checkMindMapExist)
{
	ASSERT_FALSE(PresentationCommand->checkMindMapExist());
}

TEST_F(PresentationTest, getRootDescription)
{
	PresentationCommand->createMap("a");
	ASSERT_EQ("a", PresentationCommand->getRootDescription());
}

TEST_F(PresentationTest, saveMindMap)
{
	PresentationCommand->saveMindMap();
}

TEST_F(PresentationTest, stringToInt)
{
	ASSERT_EQ(1, PresentationCommand->stringToInt("1"));
}

TEST_F(PresentationTest, checkCommandChoice)
{
	PresentationCommand->createMap("a");
	ASSERT_TRUE(PresentationCommand->checkCommandChoice("CHANGE_PARENT", 0));
}

TEST_F(PresentationTest, loadMindMap)
{
	ASSERT_FALSE(PresentationCommand->loadMindMap("a"));
}

TEST_F(PresentationTest, checkInsertNode)
{
	ASSERT_FALSE(PresentationCommand->checkInsertNode("a", 0));
}
