#include "NodeTest.h"


NodeTest::NodeTest()
{
}


NodeTest::~NodeTest()
{
}

void NodeTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Nodetest = new Node;
}

void NodeTest::TearDown()
{
	delete Mindmapmodel;
	delete Nodetest;
}

TEST_F(NodeTest, addParent)
{
	ASSERT_TRUE(Nodetest->addParent());
}

TEST_F(NodeTest, addSibling)
{
	ASSERT_TRUE(Nodetest->addSibling());
}
