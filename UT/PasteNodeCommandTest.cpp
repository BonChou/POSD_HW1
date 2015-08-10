#include "PasteNodeCommandTest.h"

PasteNodeCommandTest::PasteNodeCommandTest()
{
}


PasteNodeCommandTest::~PasteNodeCommandTest()
{
}
void PasteNodeCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Command = new PasteNodeCommand(0, Mindmapmodel);
}
void PasteNodeCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Command;
}
TEST_F(PasteNodeCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->cutComponent(1);
	Command->execute();
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n  +-Node1(Node,ID:1)\n");
}
TEST_F(PasteNodeCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->cutComponent(1);
	Command->execute();
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n  +-Node1(Node,ID:1)\n");
	Command->unexecute();
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n");
}