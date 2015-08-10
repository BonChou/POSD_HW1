#include<iostream>
#include "TextUI.h"
#include "MindMapModel.h"
#include "Presentation.h"
#include "Constants.h"
#include "GraphicUI.h"
#include "GraphicPresentation.h"
#include "Subject.h"
#include <QtWidgets/QApplication>
using namespace std;

int main(int argc, char *argv[])
{
	MindMapModel Mindmapmodel;
	string ChoiceMode;
	cout << "Select mode: TextUI[1], UImode[2]" << endl << ">";
	getline(cin, ChoiceMode); 
	if (ChoiceMode.compare(TEXTUI_MODE) == ZERO)
	{
		Presentation PresentationModel(&Mindmapmodel);
		TextUI Menu;
		Menu.run(&PresentationModel);
		return ZERO;
	}
	else if (ChoiceMode.compare(GUI_MODE) == ZERO)
	{
		GraphicPresentation GraphicPresentationModel(&Mindmapmodel);
		QApplication App(argc, argv);
		GraphicUI Graphicui( &GraphicPresentationModel);
		Mindmapmodel.attatch((Observer*)&Graphicui);
		Graphicui.show();
		return App.exec();
	}
}
