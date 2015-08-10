#include "RootTest.h"


RootTest::RootTest()
{
}


RootTest::~RootTest()
{
}

void RootTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Roottest = new Root;
}

void RootTest::TearDown()
{
	delete Mindmapmodel;
	delete Roottest;
}

TEST_F(RootTest, addParent)
{
	ASSERT_FALSE(Roottest->addParent());
}

TEST_F(RootTest, addSibling)
{
	ASSERT_FALSE(Roottest->addSibling());
}

