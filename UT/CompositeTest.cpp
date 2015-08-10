#include "CompositeTest.h"


CompositeTest::CompositeTest()
{
}


CompositeTest::~CompositeTest()
{
}
void CompositeTest::SetUp()
{
	Mindmapmodel = new MindMapModel;
	CompositeNode = new Node();
	CompositeRoot = new Root();
}

void CompositeTest::TearDown()
{
	delete Mindmapmodel;
	delete CompositeNode;
	delete CompositeRoot;
}
TEST_F(CompositeTest, addChild)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeChild(2, 3);
	Component* Buffer = new Node();
	Buffer->setID(3);
	CompositeNode->addChild(Buffer);
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 4);
}
TEST_F(CompositeTest, addChildBool)
{
	ASSERT_TRUE(CompositeNode->addChild());
}
