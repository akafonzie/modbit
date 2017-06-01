/************************************************************************************************

						toolBox.cpp - Author: Tom Weaver - 4871898
							class Implementation of toolBox.h

*************************************************************************************************/
#include "toolBox.h"

/////////////////////////////////////////////////////////////////////////////////
//
//								 toolBox()
//	This is the default constructor for the toolBox class, it creates the window 
//	for the toolBox and sets all the variables relating to it, such as: size, 
//	layout, tooltip etc. It also calls the methods associated with adding the 
//	buttons and the text intput box. 
//
//////////////////////////////////////////////////////////////////////////////////

toolBox::toolBox(QWidget *parent) : QWidget(parent)
{
	//Initialise all components used in the window
	currColR = currColG = currColB = 0;
	theToolBox = new QToolBox(this);
	layout = new QHBoxLayout (this);
	currCol = new QLabel(this);

	//Set window Properties
	theToolBox->setLayout(layout);
	setStyleSheet(" *{ background-color:#F8F4FF}}");
	setMinimumSize(230,120);
	setMaximumSize(250,120);
	setWindowTitle("Colour Toolbox");
	this->setWindowIcon(QIcon("./icons/bm.png"));

	//Initialise Current Colour Label
	QPixmap ccpm (50,50);
	ccpm.fill( QColor(currColR, currColG, currColB) );
	currCol->setPixmap(ccpm);
	currCol->setGeometry(5,5, 50, 50);
	currCol->setToolTip("Current Colour");
	currCol->setStyleSheet("*{border-style:solid;border-width:1px;border-colour:black;}}");
	
	//Call methods to add their instances to the window
	addButtons();
	addTextInput();

	//Enforce the widget to stay on top of the main window
	setWindowFlags(Qt::WindowStaysOnTopHint);
}


/////////////////////////////////////////////////////////////////////////////////
//
//								 addButton()
//	This method adds and links all of the buttons to the Colour Toolbox
//	implicitly. Also sets the signal mapping to ensure the correct string
//	is passed to the setColour() method. 
//
//////////////////////////////////////////////////////////////////////////////////
void toolBox::addButtons()
{
	QToolButton *red = new QToolButton(this);
	red->setGeometry(60,5,20,20);
	red->setIcon(QIcon("icons/toolButtonRed.png"));
	red->setToolTip(tr("Red"));
	
	QToolButton *black = new QToolButton(this);
	black->setGeometry(84,5,20,20);
	black->setIcon(QIcon("icons/toolButtonBlack.png"));
	black->setToolTip(tr("Black"));
	
	QToolButton *white = new QToolButton(this);
	white->setGeometry(108,5,20,20);
	white->setIcon(QIcon("icons/toolButtonWhite.png"));
	white->setToolTip(tr("White"));

	QToolButton *dgrey = new QToolButton(this);
	dgrey->setGeometry(132,5,20,20);
	dgrey->setIcon(QIcon("icons/toolButtonDGrey.png"));
	dgrey->setToolTip(tr("Dark Grey"));
		
	QToolButton *yellow = new QToolButton(this);
	yellow->setGeometry(60,29,20,20);
	yellow->setIcon(QIcon("icons/toolButtonYellow.png"));
	yellow->setToolTip(tr("Yellow"));

	QToolButton *green = new QToolButton(this);
	green->setGeometry(84,29,20,20);
	green->setIcon(QIcon("icons/toolButtonGreen.png"));
	green->setToolTip(tr("Green"));

	QToolButton *orange = new QToolButton(this);
	orange->setGeometry(108,29,20,20);
	orange->setIcon(QIcon("icons/toolButtonOrange.png"));
	orange->setToolTip(tr("Orange"));

	QToolButton *lgrey = new QToolButton(this);
	lgrey->setGeometry(132,29,20,20);
	lgrey->setIcon(QIcon("icons/toolButtonLGrey.png"));
	lgrey->setToolTip(tr("Light Grey"));

	QToolButton *brown = new QToolButton(this);
	brown->setGeometry(156,5,20,20);
	brown->setIcon(QIcon("icons/toolButtonBrown.png"));
	brown->setToolTip(tr("Brown"));

	QToolButton *purple = new QToolButton(this);
	purple->setGeometry(180,5,20,20);
	purple->setIcon(QIcon("icons/toolButtonPurple.png"));
	purple->setToolTip(tr("Purple"));
	
	QToolButton *blue = new QToolButton(this);
	blue->setGeometry(156,29,20,20);
	blue->setIcon(QIcon("icons/toolButtonBlue.png"));
	blue->setToolTip(tr("Blue"));
	
	QToolButton *lblue = new QToolButton(this);
	lblue->setGeometry(180,29,20,20);
	lblue->setIcon(QIcon("icons/toolButtonlBlue.png"));
	lblue->setToolTip(tr("Light Blue"));
	
	QToolButton *gold = new QToolButton(this);
	gold->setGeometry(204,5,20,20);
	gold->setIcon(QIcon("icons/toolButtonGold.png"));
	gold->setToolTip(tr("Gold"));

	QToolButton *indigo = new QToolButton(this);
	indigo->setGeometry(204,29,20,20);
	indigo->setIcon(QIcon("icons/toolButtonIndigo.png"));
	indigo->setToolTip(tr("Indigo"));


	QSignalMapper *signalMapper = new QSignalMapper (this);
	signalMapper->setMapping(red, QString("255-0-0"));
	signalMapper->setMapping(black, QString("0-0-0"));
	signalMapper->setMapping(white, QString("255-255-255"));
	signalMapper->setMapping(dgrey, QString("120-120-120"));
	signalMapper->setMapping(yellow, QString("255-255-0"));
	signalMapper->setMapping(green, QString("0-143-57"));
	signalMapper->setMapping(orange, QString("237-118-14"));
	signalMapper->setMapping(lgrey, QString("165-165-165"));
	signalMapper->setMapping(brown, QString("185-122-87"));
	signalMapper->setMapping(purple, QString("163-73-164"));
	signalMapper->setMapping(blue, QString("0-162-232"));
	signalMapper->setMapping(lblue, QString("153-217-234"));
	signalMapper->setMapping(gold, QString("255-201-14"));
	signalMapper->setMapping(indigo, QString("63-72-204"));
	connect(red, SIGNAL(clicked()), signalMapper,  SLOT(map()) );
	connect(black, SIGNAL(clicked()), signalMapper,  SLOT(map()) );
	connect(white, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(dgrey, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(yellow, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(green, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(orange, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(lgrey, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(brown, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(purple, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(blue, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(lblue, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(gold, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(indigo, SIGNAL(clicked()), signalMapper, SLOT(map()) );
	connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(setColour(QString)));
}




/////////////////////////////////////////////////////////////////////////////////
//
//								 addTextInput()
//	This method adds the text input box to the toolBox which allows the user to 
//	enter their own RGB values for a colour. The toolbox filters such that only 
//	numbers can be input to it, it also creates the relvant mapping Signal and Slot
//  so the method can call the setColourCustom() method to set the input colour. 
//
//////////////////////////////////////////////////////////////////////////////////
void toolBox::addTextInput()
{
	QLabel *ccgLabel = new QLabel (tr("Add RGB values: "));
	ccgLabel->setStyleSheet("*{margin-top:5px;margin-left:-2px;}}");
	ccgLabel->setFixedHeight(15);
	ccgLabel->setFixedWidth(110);
	rgbedit = new QLineEdit;
	rgbedit->setFocus();
	rgbedit->setMaxLength(11);
	rgbedit->setStyleSheet("*{background-color: white;margin-top:7px; margin-right:40px; color:black;}}");
	rgbedit->setToolTip("Format: RRR-GGG-BBB");
	rgbedit->setInputMask("999-999-999");
	rgbedit->setFixedWidth(120);
	rgbedit->setText("RRR-GGG-BBB");
	layout->addWidget(ccgLabel);
	layout->addWidget(rgbedit);
	QSignalMapper *textSignalMapper = new QSignalMapper (this);
	textSignalMapper->setMapping(rgbedit, QString("Custom Colour Chooser"));
	connect(rgbedit, SIGNAL(returnPressed()), textSignalMapper, SLOT(map()) );
	connect(textSignalMapper, SIGNAL(mapped(QString)), this, SLOT(setColourCustom()) );
	QString text=rgbedit->text();
}



/////////////////////////////////////////////////////////////////////////////////
//
//								 setColour()
//	This method is passed a QString from the Signal of a colour selection button 
//	being pressed. The QString is then split using the "-" character, the split
//  Qstring is then cast to an integer which is set to the currColR/G/B values 
// respectively, the displayed Current Colour is also updated to show the change. 
//
//////////////////////////////////////////////////////////////////////////////////
void toolBox::setColour(QString qs)
{
	QStringList banana;
	banana = qs.split("-");
	currColR = banana[0].toInt();
	currColG = banana[1].toInt();
	currColB = banana[2].toInt();
	QPixmap ccpm (50,50);
	ccpm.fill( QColor(currColR, currColG, currColB) );
	currCol->setPixmap(ccpm);
	currCol->setGeometry(5,5, 50, 50);
	currCol->setToolTip("Current Colour");
	currCol->show();	
}


///////////////////////////////////////////////////////////////////////////////////////
//
//								 setColourCustom()
//	This method is passed is called from the Signal emitted by the return key 
//  being pressed when the program focus is on the text entry box of the toolBox.
//  When the method is called it grabs the input QString from the text box and much
//  like the setColour() method the QString is split using the "-" character and the 
//	resulting splits are cast to integers and set as the current colour of the toolBox.
//
/////////////////////////////////////////////////////////////////////////////////////////
void toolBox::setColourCustom()
{
	QStringList temp;
	QString banana = rgbedit->text();
	temp = banana.split("-");
	currColR = temp[0].toInt();
	currColG = temp[1].toInt();
	currColB = temp[2].toInt();
	QPixmap ccpm (50,50);
	ccpm.fill( QColor(currColR, currColG, currColB) );
	currCol->setPixmap(ccpm);
	currCol->setGeometry(5,5, 50, 50);
	currCol->setToolTip("Current Colour");
	currCol->show();
	rgbedit->clear();
}

toolBox::~toolBox()
{
	//don't need to destruct anything if the parent is successfully deestructed, else KABOOOOOOM!!!111!!
}