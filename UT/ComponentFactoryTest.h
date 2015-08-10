#pragma once
#include "../QT/ComponentFactory.h"
#include "../QT/MindMapModel.h"

#include "gtest/gtest.h"
class ComponentFactoryTest:
	public::testing::Test
{
public:
	ComponentFactoryTest();
	~ComponentFactoryTest();
	void SetUp();
	void TearDown();
protected:
	ComponentFactory* Componentfactorytest;
};

