#pragma once
#include "../QT/Presentation.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class PresentationTest :
	public::testing::Test
{
public:
	PresentationTest();
	~PresentationTest();
	void SetUp();
	void TearDown();
protected:
	Presentation* PresentationCommand;
	MindMapModel* Mindmapmodel;
};

