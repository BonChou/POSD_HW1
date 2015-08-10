#include "CutNodeCommandTest.h"


CutNodeCommandTest::CutNodeCommandTest()
{
}


CutNodeCommandTest::~CutNodeCommandTest()
{
}
void CutNodeCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Command = new CutNodeCommand(1, Mindmapmodel);
}
void CutNodeCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Command;
}
TEST_F(CutNodeCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Command->execute();
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n");
}
TEST_F(CutNodeCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Command->execute();
	Command->unexecute();
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n  +-Node1(Node,ID:1)\n");
}