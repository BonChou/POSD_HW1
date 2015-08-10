#include "ComponentFactoryTest.h"


ComponentFactoryTest::ComponentFactoryTest()
{
}


ComponentFactoryTest::~ComponentFactoryTest()
{
}
void ComponentFactoryTest::SetUp()
{
	Componentfactorytest = new ComponentFactory();
}

void ComponentFactoryTest::TearDown()
{
	delete Componentfactorytest;
}
TEST_F(ComponentFactoryTest, createNode)
{
	Component* Buffer = Componentfactorytest->createNode("Node", 1);
	ASSERT_EQ(Buffer->getDescription(), "Node");
	ASSERT_EQ(Buffer->getID(), 1);
}
TEST_F(ComponentFactoryTest, createRoot)
{
	Component* Buffer = Componentfactorytest->createRoot("Node", 0);
	ASSERT_EQ(Buffer->getDescription(), "Node");
	ASSERT_EQ(Buffer->getID(), 0);
}