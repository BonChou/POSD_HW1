#pragma once
#include "../QT/MindMapModel.h"
#include "../QT/Presentation.h"
#include "gtest/gtest.h"
class IntegrationTest:
	public::testing::Test
{
public:
	IntegrationTest();
	~IntegrationTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	Presentation* PresentationCommand;
};

