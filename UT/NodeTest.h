#pragma once
#include "../QT/MindMapModel.h"
#include "../QT/Node.h"
#include "gtest/gtest.h"
class NodeTest:
	public::testing::Test
{
public:
	NodeTest();
	~NodeTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	Node* Nodetest;
};

