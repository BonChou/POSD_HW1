#include "ChangeParentCommandTest.h"


ChangeParentCommandTest::ChangeParentCommandTest()
{
}
ChangeParentCommandTest::~ChangeParentCommandTest()
{
}
void ChangeParentCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Changeparentcommand = new ChangeParentCommand(NULL, NULL, Mindmapmodel);
}
void ChangeParentCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Changeparentcommand;
}
TEST_F(ChangeParentCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Changeparentcommand->NodeID = 1;
	Changeparentcommand->ParentNodeID = 3;
	Changeparentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 3);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->ParentNode->getID(), 0);
	TearDown();
	SetUp();
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Changeparentcommand->NodeID = 1;
	Changeparentcommand->ParentNodeID = 2;
	Changeparentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), 0);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 2);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->ParentNode->getID(), 0);
}
TEST_F(ChangeParentCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Changeparentcommand->NodeID = 1;
	Changeparentcommand->ParentNodeID = 3;
	Changeparentcommand->execute();
	Changeparentcommand->unexecute();
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 0);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->ParentNode->getID(), 0);
	TearDown();
	SetUp();
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Changeparentcommand->NodeID = 1;
	Changeparentcommand->ParentNodeID = 2;
	Changeparentcommand->execute();
	Changeparentcommand->unexecute();
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 0);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->ParentNode->getID(), 0);
}