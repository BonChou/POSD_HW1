#pragma once
#include "../QT/MindMapModel.h"
#include "../QT/Subject.h"
#include "gtest/gtest.h"

class MindMapModelTest :
	public::testing::Test
{
public:
	MindMapModelTest();
	~MindMapModelTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
};

