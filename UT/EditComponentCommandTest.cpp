#include "EditComponentCommandTest.h"


EditComponentCommandTest::EditComponentCommandTest()
{
}


EditComponentCommandTest::~EditComponentCommandTest()
{
}
void EditComponentCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Editcomponentcommand = new EditComponentCommand("", NULL, Mindmapmodel);
}
void EditComponentCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Editcomponentcommand;
}
TEST_F(EditComponentCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Editcomponentcommand->EditNodeID = 1;
	Editcomponentcommand->NewDescription = "NodeGX";
	Editcomponentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getDescription(), "NodeGX");
}
TEST_F(EditComponentCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Editcomponentcommand->EditNodeID = 1;
	Editcomponentcommand->NewDescription = "NodeGX";
	Editcomponentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getDescription(), "NodeGX");
	Editcomponentcommand->unexecute();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getDescription(), "Node1");
}