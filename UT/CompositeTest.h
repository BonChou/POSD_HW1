#pragma once
#include "../QT/Composite.h"
#include "../QT/MindMapModel.h"
#include "../QT/Root.h"
#include "../QT/Node.h"

#include "gtest/gtest.h"
class CompositeTest
	:public::testing::Test
{
public:
	CompositeTest();
	~CompositeTest();
	void SetUp();
	void TearDown();
protected:
	Composite* CompositeNode;
	Composite* CompositeRoot;
	MindMapModel* Mindmapmodel;
};

