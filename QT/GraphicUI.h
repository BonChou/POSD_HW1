#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include "QInputDialog.h"
#include "GraphicsView.h"
#include "Observer.h"
#include "GraphicPresentation.h"
class GraphicUI : public QMainWindow, Observer
{
	Q_OBJECT
public:
	GraphicUI(GraphicPresentation*);
	~GraphicUI();
private slots:
	void open();
	void create();
	void insertChild();
	void insertSilbing();
	void insertParent();
	void deleteNode();
	void insertCircle();
	void insertTriangle();
	void insertRectangle();
	void save();
	void edit();
	void about();
	void cut();
	void copy();
	void paste();
	void redo();
	void undo();
	void up();
	void down();
	void expand();
	void collapse();
	void expandOne();
	void collapseOne();
	void clear();

public:
	QVector<GraphicComponent*> GraphicComponentVector;
	QVector<QAction*> GraphicAction;
	GraphicPresentation* Gui_presentation;
	GraphicsView* View;
	void createActions();
	void createMenus();
	void createToolBars();
	void createGraphicsView();
	void loadFile(const QString &fileName);
	void initialAction();
	bool CutOrCopy;
	void update();
	void updateToolBar();
	void paintMap();
	QMenu* FileBar;
	QMenu* EditBar;
	QMenu* AboutBar;

	QToolBar* FileToolBar;
	QToolBar* EditToolBar;
	QToolBar* AboutToolBar;

	QAction* CreateAct;
	QAction* OpenAct;
	QAction* ExitAct;
	QAction* SaveAct;
	QAction* EditAct;
	QAction* DeleteAct;
	QAction* InsertAChildAct;
	QAction* InsertASiblingAct;
	QAction* InsertAParentAct;
	QAction* AboutAct;
	QAction* CutAct;
	QAction* CopyAct;
	QAction* PasteAct;
	QAction* InsertARectangleAct;
	QAction* InsertACircleAct;
	QAction* InsertATriangleAct;
	QAction* RedoAct;
	QAction* UndoAct;
	QAction* UpAct;
	QAction* DownAct;
	QAction* ExpandAct;
	QAction* CollapseAct;
	QAction* ClearAct;

	QAction* ExpandOneAct;
	QAction* CollapseOneAct;

};

