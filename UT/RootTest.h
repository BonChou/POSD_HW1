#pragma once
#include "../QT/MindMapModel.h"
#include "../QT/Root.h"
#include "gtest/gtest.h"

class RootTest:
	public::testing::Test
{
public:
	RootTest();
	~RootTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	Root* Roottest;
};

