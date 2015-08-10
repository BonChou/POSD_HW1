#include "GraphicUI.h"
const QString WINDOWS_TITLE = "103598019_Mind_MAP";
const int LENGTH = 1024;
const int WIDTH = 900;


GraphicUI::GraphicUI(GraphicPresentation* Gui_presentation)
{
	this->Gui_presentation = Gui_presentation;
	createActions();
	createMenus();
	createToolBars();
	createGraphicsView();
	//this->setWindowState(this->windowState() ^ Qt::WindowFullScreen);
	this->resize(LENGTH, WIDTH);
	this->setWindowTitle(WINDOWS_TITLE);
	setUnifiedTitleAndToolBarOnMac(true);
}
GraphicUI::~GraphicUI()
{
	delete FileBar;
	delete EditBar;
	delete AboutBar;
	delete FileToolBar;
	delete EditToolBar;
	delete AboutToolBar;
	delete CreateAct;
	delete OpenAct;
	delete ExitAct;
	delete SaveAct;
	delete EditAct;
	delete DeleteAct;
	delete InsertAChildAct;
	delete InsertASiblingAct;
	delete InsertAParentAct;
	delete AboutAct;

}
void GraphicUI::createGraphicsView()
{
	View = new GraphicsView(new QGraphicsScene(), GraphicAction, Gui_presentation);
	View->setMouseTracking(true);
	setCentralWidget(View);
}

void GraphicUI::createMenus()
{
	FileBar = new QMenu(tr("&File"));
	FileBar->addAction(CreateAct);
	FileBar->addAction(OpenAct);
	FileBar->addAction(SaveAct);
	FileBar->addSeparator();
	FileBar->addAction(ExitAct);
	this->menuBar()->addMenu(FileBar);

	EditBar = new QMenu(tr("&Edit"));
	EditBar->addAction(EditAct);
	EditBar->addAction(DeleteAct);
	EditBar->addAction(InsertAChildAct);
	EditBar->addAction(InsertASiblingAct);
	EditBar->addAction(InsertAParentAct);
	EditBar->addAction(CutAct);
	EditBar->addAction(CopyAct);
	EditBar->addAction(PasteAct);
	EditBar->addAction(RedoAct);
	EditBar->addAction(UndoAct);
	EditBar->addAction(InsertARectangleAct);
	EditBar->addAction(InsertACircleAct);
	EditBar->addAction(InsertATriangleAct);
	EditBar->addAction(ExpandAct);
	EditBar->addAction(CollapseAct);
	EditBar->addAction(ExpandOneAct);
	EditBar->addAction(CollapseOneAct);
	EditBar->addAction(ClearAct);
	this->menuBar()->addMenu(EditBar);

	AboutBar = new QMenu(tr("&About"));
	AboutBar->addAction(AboutAct);
	this->menuBar()->addMenu(AboutBar);

}

void GraphicUI::createActions()
{
	CreateAct = new QAction(QIcon("images/create.png"), tr("&Create a mind map"), this);
	connect(CreateAct, SIGNAL(triggered()), this, SLOT(create()));

	OpenAct = new QAction(QIcon("images/open.png"), tr("&Open a mind map"), this);
	OpenAct->setStatusTip(tr("Open an existing file"));
	connect(OpenAct, SIGNAL(triggered()), this, SLOT(open()));

	SaveAct = new QAction(QIcon("images/save.png"), tr("&Save a mind map"), this);
	connect(SaveAct, SIGNAL(triggered()), this, SLOT(save()));

	ExitAct = new QAction(QIcon("images/exit.png"), tr("&Exit"), this);
	ExitAct->setStatusTip(tr("Exit the application"));
	connect(ExitAct, SIGNAL(triggered()), this, SLOT(close()));

	EditAct = new QAction(QIcon("images/edit.png"), tr("&Edit"), this);
	connect(EditAct, SIGNAL(triggered()), this, SLOT(edit()));

	DeleteAct = new QAction(QIcon("images/delete.png"), tr("&Delete"), this);
	connect(DeleteAct, SIGNAL(triggered()), this, SLOT(deleteNode()));

	InsertAChildAct = new QAction(QIcon("images/child.png"), tr("&Insert a child"), this);
	connect(InsertAChildAct, SIGNAL(triggered()), this, SLOT(insertChild()));

	InsertASiblingAct = new QAction(QIcon("images/silbing.png"), tr("&Insert a silbing"), this);
	connect(InsertASiblingAct, SIGNAL(triggered()), this, SLOT(insertSilbing()));

	InsertAParentAct = new QAction(QIcon("images/parent.png"), tr("&Insert a parent"), this);
	connect(InsertAParentAct, SIGNAL(triggered()), this, SLOT(insertParent()));

	AboutAct = new QAction(QIcon("images/about.png"), tr("&About"), this);
	connect(AboutAct, SIGNAL(triggered()), this, SLOT(about()));

	CutAct = new QAction(QIcon("images/cut.png"), tr("&Cut"), this);
	connect(CutAct, SIGNAL(triggered()), this, SLOT(cut()));
	
	CopyAct = new QAction(QIcon("images/copy.png"), tr("&Copy"), this);
	connect(CopyAct, SIGNAL(triggered()), this, SLOT(copy()));

	PasteAct = new QAction(QIcon("images/paste.png"), tr("&Paste"), this);
	connect(PasteAct, SIGNAL(triggered()), this, SLOT(paste()));

	RedoAct = new QAction(QIcon("images/redo.png"), tr("&Redo"), this);
	connect(RedoAct, SIGNAL(triggered()), this, SLOT(redo()));

	UndoAct = new QAction(QIcon("images/undo.png"), tr("&Undo"), this);
	connect(UndoAct, SIGNAL(triggered()), this, SLOT(undo()));

	InsertARectangleAct = new QAction(QIcon("images/rectangle.png"), tr("&Insert a rectangle"), this);
	connect(InsertARectangleAct, SIGNAL(triggered()), this, SLOT(insertRectangle()));

	InsertACircleAct = new QAction(QIcon("images/circle.png"), tr("&Insert a circle"), this);
	connect(InsertACircleAct, SIGNAL(triggered()), this, SLOT(insertCircle()));

	InsertATriangleAct = new QAction(QIcon("images/triangle.png"), tr("&Insert a triangle"), this);
	connect(InsertATriangleAct, SIGNAL(triggered()), this, SLOT(insertTriangle()));

	UpAct = new QAction(QIcon("images/up.png"), tr("&Up"), this);
	connect(UpAct, SIGNAL(triggered()), this, SLOT(up()));

	DownAct = new QAction(QIcon("images/down.png"), tr("&Down"), this);
	connect(DownAct, SIGNAL(triggered()), this, SLOT(down()));

	ExpandAct = new QAction(QIcon("images/expand.png"), tr("&Expand"), this);
	connect(ExpandAct, SIGNAL(triggered()), this, SLOT(expand()));

	CollapseAct = new QAction(QIcon("images/collapse.png"), tr("&Collapse"), this);
	connect(CollapseAct, SIGNAL(triggered()), this, SLOT(collapse()));

	ExpandOneAct = new QAction(QIcon("images/expand2.png"), tr("&Expand"), this);
	connect(ExpandOneAct, SIGNAL(triggered()), this, SLOT(expandOne()));

	CollapseOneAct = new QAction(QIcon("images/collapse2.png"), tr("&Collapse"), this);
	connect(CollapseOneAct, SIGNAL(triggered()), this, SLOT(collapseOne()));

	ClearAct = new QAction(QIcon("images/clear.png"), tr("&Clear"), this);
	connect(ClearAct, SIGNAL(triggered()), this, SLOT(clear()));

	initialAction();
	GraphicAction.push_back(DeleteAct);
	GraphicAction.push_back(InsertAChildAct);
	GraphicAction.push_back(InsertASiblingAct);
	GraphicAction.push_back(InsertAParentAct);
	GraphicAction.push_back(EditAct);
	GraphicAction.push_back(CutAct);
	GraphicAction.push_back(CopyAct);
	GraphicAction.push_back(PasteAct);
	GraphicAction.push_back(RedoAct);
	GraphicAction.push_back(UndoAct);
	GraphicAction.push_back(InsertARectangleAct);
	GraphicAction.push_back(InsertACircleAct);
	GraphicAction.push_back(InsertATriangleAct);
	GraphicAction.push_back(UpAct);
	GraphicAction.push_back(DownAct);
	GraphicAction.push_back(ExpandAct);
	GraphicAction.push_back(CollapseAct);
	GraphicAction.push_back(ExpandOneAct);
	GraphicAction.push_back(CollapseOneAct);
	GraphicAction.push_back(ClearAct);

	Gui_presentation->setGraphicAction(GraphicAction);
}
void GraphicUI::initialAction()
{
	DeleteAct->setDisabled(true);
	InsertAChildAct->setDisabled(true);
	InsertASiblingAct->setDisabled(true);
	InsertAParentAct->setDisabled(true);
	EditAct->setDisabled(true);
	CutAct->setDisabled(true);
	PasteAct->setDisabled(true);
	CopyAct->setDisabled(true);
	UndoAct->setDisabled(true);
	RedoAct->setDisabled(true);
	InsertARectangleAct->setDisabled(true);
	InsertACircleAct->setDisabled(true);
	InsertATriangleAct->setDisabled(true);
	UpAct->setDisabled(true);
	DownAct->setDisabled(true);
	ExpandAct->setDisabled(true);
	CollapseAct->setDisabled(true);
	ExpandOneAct->setDisabled(true);
	CollapseOneAct->setDisabled(true);
	ClearAct->setDisabled(true);
}
void GraphicUI::createToolBars()
{
	FileToolBar = addToolBar(tr("ToolBar"));
	FileToolBar->addAction(CreateAct);
	FileToolBar->addAction(OpenAct);
	FileToolBar->addAction(SaveAct);
	FileToolBar->addAction(ExitAct);

	EditToolBar = addToolBar(tr("ToolBar"));
	EditToolBar->addAction(EditAct);
	EditToolBar->addAction(DeleteAct);
	EditToolBar->addAction(InsertAChildAct);
	EditToolBar->addAction(InsertASiblingAct);
	EditToolBar->addAction(InsertAParentAct);
	EditToolBar->addAction(CutAct);
	EditToolBar->addAction(CopyAct);
	EditToolBar->addAction(PasteAct);
	EditToolBar->addAction(RedoAct);
	EditToolBar->addAction(UndoAct);
	EditToolBar->addAction(InsertARectangleAct);
	EditToolBar->addAction(InsertACircleAct);
	EditToolBar->addAction(InsertATriangleAct);
	EditToolBar->addAction(UpAct);
	EditToolBar->addAction(DownAct);
	EditToolBar->addAction(ExpandAct);
	EditToolBar->addAction(CollapseAct);
	EditToolBar->addAction(ExpandOneAct);
	EditToolBar->addAction(CollapseOneAct);
	EditToolBar->addAction(ClearAct);

	AboutToolBar = addToolBar(tr("ToolBar"));
	AboutToolBar->addAction(AboutAct);
}


void GraphicUI::open()
{
	Gui_presentation->initialCommand();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Mind Map"), "C:\\", tr("Mind Map files(*.mm)"));
	if (fileName.toStdString().compare(NULL_STRING))
		Gui_presentation->loadMindMap(fileName.toStdString());
}

void GraphicUI::create()
{
	Gui_presentation->initialCommand();
	if (!Gui_presentation->createRoot(NULL_STRING))
		QMessageBox::critical(NULL, "ERROR", "You was already create the Mind Map!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void GraphicUI::insertChild()
{
	Gui_presentation->createChildNode(NULL_STRING);
}

void GraphicUI::insertSilbing()
{
	Gui_presentation->createSilbing(NULL_STRING);
}
void GraphicUI::insertParent()
{
	Gui_presentation->createParent(NULL_STRING);
}

void GraphicUI::updateToolBar()
{
	DeleteAct->setDisabled(true);
	InsertAChildAct->setDisabled(true);
	InsertASiblingAct->setDisabled(true);
	InsertAParentAct->setDisabled(true);
	EditAct->setDisabled(true);
	CutAct->setDisabled(true);
	CopyAct->setDisabled(true);
	PasteAct->setDisabled(true);
	InsertARectangleAct->setDisabled(true);
	InsertACircleAct->setDisabled(true);
	InsertATriangleAct->setDisabled(true);
	UpAct->setDisabled(true);
	DownAct->setDisabled(true);
	ExpandAct->setDisabled(true);
	CollapseAct->setDisabled(true);
	ExpandOneAct->setDisabled(true);
	CollapseOneAct->setDisabled(true);
	ClearAct->setDisabled(true);
	if (Gui_presentation->getModelRedoCommands() != 0)
		GraphicAction[REDO_NUMBER]->setDisabled(false);
	else
		GraphicAction[REDO_NUMBER]->setDisabled(true);

	if (Gui_presentation->getModelUndoCommands() != 0)
		GraphicAction[UNDO_NUMBER]->setDisabled(false);
	else
		GraphicAction[UNDO_NUMBER]->setDisabled(true);
}

void GraphicUI::update()
{
	paintMap();
}

void GraphicUI::paintMap()
{
	GraphicComponentVector = Gui_presentation->getGraphicComponentVector();
	View->drawDiagram(GraphicComponentVector);
	updateToolBar();
}

void GraphicUI::deleteNode()
{
	Gui_presentation->deleteNode();
	updateToolBar();

}
void GraphicUI::save()
{
	Gui_presentation->initialCommand();
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Mind Map"), "C:\\", tr("Mind Map files(*.mm)"));
	if (Gui_presentation->saveMindMap(fileName.toStdString()).compare("No MindMap!\n") == 0)
		QMessageBox::critical(NULL, "ERROR", "You didn't create the Mind Map!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	updateToolBar();

}

void GraphicUI::edit()
{
	bool Isok;
	QWidget* Scenewidget = ZERO;
	QString Description = QInputDialog::getText(Scenewidget, tr("Input Dialog"), tr("Please input your description"), QLineEdit::Normal, "", &Isok);
	if (Isok == true)
		Gui_presentation->editDecription(Description.toStdString());
	updateToolBar();
}

void GraphicUI::about()
{
	QMessageBox::about(this, "About","This Mind_MAP is designed by Boom!!");
}
void GraphicUI::cut()
{
	Gui_presentation->cutComponent();
	updateToolBar();
}

void GraphicUI::paste()
{
	Gui_presentation->Paste();
	updateToolBar();
}

void GraphicUI::copy()
{
	Gui_presentation->clonComponent();
	updateToolBar();
}

void GraphicUI::redo()
{
	Gui_presentation->redoCommand();
	updateToolBar();
}
void GraphicUI::undo()
{
	Gui_presentation->undoCommand();
	updateToolBar();
}

void GraphicUI::insertCircle()
{
	Gui_presentation->createGraphic(CIRCLE);
}
void GraphicUI::insertTriangle()
{
	Gui_presentation->createGraphic(TRINAGLE);
}
void GraphicUI::insertRectangle()
{
	Gui_presentation->createGraphic(RECTANGLE);
}

void GraphicUI::up()
{
	if (!Gui_presentation->upGraphic())
		QMessageBox::critical(NULL, "ERROR", "You didn't up the Node!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}
void GraphicUI::down()
{
	if (!Gui_presentation->downGraphic())
		QMessageBox::critical(NULL, "ERROR", "You didn't down the Node!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}
void GraphicUI::expand()
{
	Gui_presentation->expandGraphic();
}
void GraphicUI::collapse()
{
	Gui_presentation->collapseGraphic();
}
void GraphicUI::expandOne()
{
	Gui_presentation->expandOneGraphic();
}
void GraphicUI::collapseOne()
{
	Gui_presentation->collapseOneGraphic();
}

void GraphicUI::clear()
{
	Gui_presentation->initialCommand();
	Gui_presentation->clearGraphic();
}
