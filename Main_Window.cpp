/* Main coding resources:

	http://qt-project.org/doc/ - For all QT related resources and implementation queries.

*/

#include "Main_Window.h"

////////////////////////////////////////////////////////////////////////////////
////							MAIN WINDOW
////////////////////////////////////////////////////////////////////////////////
MAIN_WINDOW::MAIN_WINDOW(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle("MODBIT");
	first_run = true;
	draw = true;
	ui.setupUi(this);
	initialise();
}


MAIN_WINDOW::~MAIN_WINDOW()
{
	
}


void MAIN_WINDOW::closeEvent(QCloseEvent *event)
{
	//If the main window is closed, close all sub windows
	theToolBox.close();
}


////////////////////////////////////////////////////////////////////////////////
////					initialise function
////	Initialises the image window when the program is first run
////////////////////////////////////////////////////////////////////////////////

void MAIN_WINDOW::initialise(void)
{
	//Set height and width
	data.setDimensions(640, 480);
	data.fillArray();
	updateCursor();

	change = false;
	just_released = false;
	
	//Initialise tool buttons
	initToolbar();

	//Set the size and location of the window (x, y, width, height)
	this->setGeometry(40, 40, data.width, data.height+60);

	drawImage();

	this->showMaximized();
	this->show();
	this->setWindowTitle("MODBIT | Modular Bitmap Drawing and Image Editing Tool");
	this->setWindowIcon(QIcon("./icons/mb.png"));

	//Show the colour toolbox
	theToolBox.show();
}



////////////////////////////////////////////////////////////////////////////////
////					initToolbar function
////	Initialises the toolbar with icons for each included tool
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::initToolbar(void)
{
	//Initialise the tool array with 100 max possible entries
	tool_Array = new Tool[MAX_TOOLS];
	//Loop through the tool array and set the id of each tool to "N" to signify it is null
	for(int i = 0; i < MAX_TOOLS; i++)
	{
		tool_Array[i].id = "N";
	}
	Tool newTool;

	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////					REGISTER TOOLS HERE						/////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	
	////////////////////BRUSH////////////////////
	newTool.tool = new t_Brush;
	regTool(newTool);

	////////////////////REGBRUSH////////////////////
	newTool.tool = new t_RegBrush;
	regTool(newTool);

	////////////////////PENCIL////////////////////
	newTool.tool = new t_Pencil;
	regTool(newTool);	

	//////////////////////FILL//////////////////////////
	newTool.tool = new t_Fill;
	regTool(newTool);
	
	//////////////////////ERASER//////////////////////////
	newTool.tool = new t_Eraser;
	regTool(newTool);

	//////////////////////DROPPER/////////////////////
	newTool.tool = new t_Dropper;
	regTool(newTool);
	
	////////////////////GREYSCALE////////////////////
	newTool.tool = new t_Greyscale;
	regTool(newTool);

	////////////////////BLUR////////////////////
	newTool.tool = new t_Blur;
	regTool(newTool);

	//////////////////////UNDO/////////////////////
	//newTool.tool = new t_Undo;
	//regTool(newTool);

	//////////////////////REDO/////////////////////
	//newTool.tool = new t_Redo;
	//regTool(newTool);

	//////////////////////ROTATE/////////////////////
	newTool.tool = new t_Rotate;
	regTool(newTool);

	//////////////////////FLIP HORIZONTAL/////////////////////
	newTool.tool = new t_Flip_H;
	regTool(newTool);

	//////////////////////FLIP VERTICAL/////////////////////
	newTool.tool = new t_Flip_V;
	regTool(newTool);

	//////////////////////MIRROR/////////////////////
	newTool.tool = new t_Mirror;
	regTool(newTool);

	//////////////////////RESIZE/////////////////////
	newTool.tool = new t_Resize;
	regTool(newTool);

	//////////////////////STRETCH/////////////////////
	newTool.tool = new t_Stretch;
	regTool(newTool);

	//////////////////////RECTANGLE/////////////////////
	newTool.tool = new t_Rectangle;
	regTool(newTool);

	//////////////////////LINE/////////////////////
	newTool.tool = new t_Line;
	regTool(newTool);
	//////////////////////GRADIENT LINE/////////////////////
	newTool.tool = new t_threeDLine;
	regTool(newTool);


	linkTool("brush");

	addSizeSlider();
}



////////////////////////////////////////////////////////////////////////////////
////					regTool function
////	Registers the tool to the tool_Array for button mapping
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::regTool(Tool newTool)
{
	int i = 0;
	bool set = false;
	int test = sizeof(tool_Array);
	//Loop through the tool array to find the next available space
	while(i < MAX_TOOLS && !set)
	{
		//If there is no tool registered to this slot, save the new tool here
		if(tool_Array[i].id == "N")
		{
			tool_Array[i].id = newTool.tool->id;
			tool_Array[i].tool = newTool.tool;
			addToolButton(tool_Array[i].tool);
			set = true;
		}
		i++;
	}
}



////////////////////////////////////////////////////////////////////////////////
////					linkTool function
////	Searches the tool_Array for the queried tool id. If located,
////	sets the active tool to this type
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::linkTool(QString id)
{
	const char* idQuery;
	idQuery = id.toStdString().c_str();
	int i = 0;
	bool mapped = false;
	//Loop through the tool array to find the next available space
	while(i < MAX_TOOLS && !mapped)
	{
		//If the queried id is found, set the active tool
		if(tool_Array[i].id == id)
		{
			active_tool = tool_Array[i].tool;
			active_tool->onPress(data);
			mapped = true;
			change = true;
		}
		i++;
	}
}


////////////////////////////////////////////////////////////////////////////////
////					addButton function
////	Adds a new button to the toolbar in the main window
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::addToolButton(t_Base* tool)
{
	QToolButton *new_button = new QToolButton(this);
	new_button->setGeometry(0,0,20,20);
	//Set the icon for the button
	new_button->setIcon(QIcon(tool->icon));
	new_button->setToolTip(tr(tool->tooltip));
	new_button->setShortcut(tr(tool->shortcut));
	//Declare the signal mapper to map the new button to a function

	QSignalMapper *signalMapper = new QSignalMapper (this);
	signalMapper->setMapping(new_button, tool->id);
	connect(new_button, SIGNAL(clicked()), signalMapper,  SLOT(map()));
	connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(linkTool(QString)));

	////QSignalMapper *mapper = new QSignalMapper(this);
	//connect(new_button, SIGNAL(clicked()), this, SLOT(tool->onPress()));
	ui.mainToolBar->addWidget(new_button);
}



////////////////////////////////////////////////////////////////////////////////
////					addSizeSlider function
////	Add a slider to main toolbar to control the size of active_tool
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::addSizeSlider()
{
	QToolBar *sTB = new QToolBar (this);
	szSlider = new QSlider (Qt::Horizontal);
	szSlider->setMaximumWidth(100);
	szSlider->setToolTip("Change Selected Tool Size");
	szSlider->setRange(5, 50);
	szSlider->setSingleStep(1);
	szSlider->setTickPosition(QSlider::TicksBelow);
	szSlider->setTickInterval(10);
	sTB->addSeparator();
	sTB->addWidget(szSlider);
	sTB->addSeparator();
	sTB->setFixedWidth(110);
	ui.mainToolBar->addWidget(sTB);
	//QSignalMapper *szmap = new QSignalMapper (this);
	connect( szSlider, SIGNAL(valueChanged(int)), this, SLOT(setToolSize(int)) );

	connect(ui.actionLoad, SIGNAL(triggered()), this, SLOT( getImage() ));
	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT( drawImage() ));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT( save() ));
}



////////////////////////////////////////////////////////////////////////////////
////					drawImage slot
////	makes QImage object, sets QImage to initial Image_Data data 
////	contents, draws to QLabel. Outputs image on screen.
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::drawImage()
{	
	QLabel *label = new QLabel(this);
	
	data.setDimensions(HEIGHT, WIDTH);

	//Create QImage object and set image format
	image = new QImage(data.width, 
		data.height,
		QImage::Format_ARGB4444_Premultiplied);

	//resize pixel array to size of QImage
	data.fillArray(); //fill pixel array

	for(int i=0; i < data.width; i++)
	{
		for(int j=0; j < data.height; j++)
		{
			//define a QRgb colour object as the rgba value of the current cell in the pixel array
			QRgb colour = qRgba(data.data[i][j].r,
								data.data[i][j].g,
								data.data[i][j].b,
								data.data[i][j].a);
			//assign this colour to the current pixel in the QImage
			image->setPixel(i,j,colour);
		}
	}

	update_timer = new QTimer (this);
	update_timer->setInterval(1);
	connect(update_timer, SIGNAL(timeout()), this, SLOT(refresh()));
	update_timer->start();

	label->setFixedSize(image->width(),image->height());
	label->setPixmap(QPixmap::fromImage(*image)); //attach QImage to a QLabel
	label->move(0,50);
	label->show();
	delete image;
	delete label;
	change = true;
}



////////////////////////////////////////////////////////////////////////////////
////					refresh function
////	Performs all operations which must be repeated per frame 
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::refresh(void)
{
	updateCursor();
	QLabel *label = new QLabel(this);
	if(first_run){update(label);first_run=false;}

	//If the mouse is pressed, use the current tool
	if(data.mouse_press)
	{
		active_tool->use(data);
		change = true;
	}
	else if(just_released)
	{
		active_tool->use(data);
		just_released = false;
		change = true;
	}

	if(change)
	{
		//add label to vector to counter memory leaks
		tempvec.push_back(label);
		//if vector is greater than 2 delete any further labels using pop_back
		if (tempvec.size() > 2)
		{
			tempvec.pop_back();
		}
		//call update on the front element of the vector to draw any updates.
		update(tempvec.front());
		change = false;
	}

	//qApp->processEvents();
	//delete label;
}



////////////////////////////////////////////////////////////////////////////////
////					update function
////	Updates the image on the screen with any changes made
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::update(QLabel *label)
{
	//Create QImage object and set image format
	image = new QImage(data.width, 
		data.height,
		QImage::Format_ARGB4444_Premultiplied);
	for(int i=0; i < data.width; i++)
	{
		for(int j=0; j < data.height; j++)
		{
			//define a QRgb colour object as the rgba value of the current cell in the pixel array
			QRgb colour = qRgba(data.data[i][j].r,
								data.data[i][j].g,
								data.data[i][j].b,
								data.data[i][j].a);
			//assign this colour to the current pixel in the QImage
			image->setPixel(i,j,colour);
		}
	}
	label->setFixedSize(image->width(),image->height());
	label->setPixmap(QPixmap::fromImage(*image)); //attach QImage to a QLabel
	label->move(0,60);
	label->show();
	//call this method to continually ensure colour changes are set globally
	setGlobalColour();
	colourPicker();

	delete image;
}




////////////////////////////////////////////////////////////////////////////////
////					getImage slot
////				Loads a BMP from a file
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::getImage(){

	QLabel *label = new QLabel(this);
	Load_Img *li = new Load_Img();

	QString loadimg = QFileDialog::getOpenFileName(this, tr("Open File.."), QString(), tr("JPEG (*.jpg *.jpeg);; BMP (*.bmp);; PNG (*.png);; TIFF (*.tif);;"));
	QByteArray ba = loadimg.toLocal8Bit();
    const char *imagename = ba.data();

	QString suffix;
	QString delimiterPattern(".");
	QStringList parts = loadimg.split(delimiterPattern);
	suffix = parts.last();
	int i=1;
	int j=1;

	if(suffix == "bmp"){
		i = li->loadBMP(imagename); //use my load method
	}
	else{
		QString tmp = suffix;
		tmp = suffix.toUpper(); //make capital letters
		QByteArray ba2 = tmp.toLocal8Bit(); //convert to char array
		const char *newsuffix = ba2.data();
		image = new QImage(imagename, newsuffix); //use QT's load methods
		j=0;
	}

	if(i == 0 || j==0) //if either method succeeded
	{
		if(j==0){
			data.setDimensions(image->width(), image->height()); //only need to fill data as the qimage is already initialized
			data.fillArrayFromQImage(image);
		}
		if(i==0){
			data.setDimensions(li->bmp->w, li->bmp->h);
			data.fillArrayFromImage(li->bmp->pixels);
			image = new QImage(li->bmp->w,li->bmp->h,QImage::Format_ARGB4444_Premultiplied); //create QImage object and set image format
				
			QRgb colour;
			for(int i=0; i< data.width; i++)
			{
				for(int j=0; j<data.height; j++)
				{		
					//define a QRgb colour object as the rgba value of the current cell in the pixel array
					colour = qRgba(data.data[i][j].r,
					data.data[i][j].g,
					data.data[i][j].b,
					data.data[i][j].a);
					//assign this colour to the current pixel in the QImage
					image->setPixel(i,j,colour);				
				}
			}
		} //end if j=0

		update_timer = new QTimer (this);
		update_timer->setInterval(10);
		connect(update_timer, SIGNAL(timeout()), this, SLOT(refresh()));
		update_timer->start();

		label->setFixedSize(image->width(), image->height());
		label->setPixmap(QPixmap::fromImage(*image)); //attach QImage to a QLabel
		label->move(0,50);
		label->show();
		delete image;
		
	} 

	delete li;
	delete label;
	change = true;
	
}



////////////////////////////////////////////////////////////////////////////////
////					mousePressEvent function
////	If the mouse is pressed, sets the data boolean to true 
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::mousePressEvent(QMouseEvent *m)
{
	if(!data.mouse_press)
	{
		data.mouse_press = true;
	}
}



////////////////////////////////////////////////////////////////////////////////
////					mouseReleaseEvent function
////	If the mouse is released, sets the data boolean to false 
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::mouseReleaseEvent(QMouseEvent *m)
{
	if(data.mouse_press)
	{
		data.mouse_press = false;
		just_released = true;

	}
}



////////////////////////////////////////////////////////////////////////////////
////					updateCursor function
////		Updates the position of the cursor stored in the data
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::updateCursor(void)
{
	if (data.prevcursor_x != data.cursor_x || data.prevcursor_y !=data.cursor_y)
	{
		data.prevcursor_x = data.cursor_x;
		data.prevcursor_y = data.cursor_y;
	}
	cursor = QCursor::pos();
	QPoint window = this->pos();
	data.cursor_x = cursor.rx()-window.rx()-9; 
	data.cursor_y = cursor.ry()-window.ry()-88;
	if(data.mouse_press)
	{
		if (!data.mouse_drag)
		{
			int currx = data.prevcursor_x;
			int curry = data.prevcursor_y;
			if ( (data.cursor_x != currx || data.cursor_y != curry) )
			{
				  data.mouse_drag = true;
			} 
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
////					setGlobalColour function
////		Updates the current colour as selected in the colour toolbox
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::setGlobalColour()
{
	data.colour.r = theToolBox.currColR;
	data.colour.g = theToolBox.currColG;
	data.colour.b = theToolBox.currColB;
	data.colour.a = 255;
}

////////////////////////////////////////////////////////////////////////////////
////					colourPicker function
////	Updates the current colour to that selected by the droppper tool
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::colourPicker()
{
	if (data.dropper)
	{
		if(data.cursor_x > -1 && data.cursor_x < data.width
			&& data.cursor_y > -1 && data.cursor_y < data.height)
			{
				Pixel temp;
				int x = data.cursor_x;
				int y = data.cursor_y;
				temp = data.getPixel(x, y);
				QString tamp = QString("%1-%2-%3").arg(temp.r).arg(temp.g).arg(temp.b);
				theToolBox.setColour(tamp);
				data.colour.r = temp.r;
				data.colour.g = temp.g;
				data.colour.b = temp.b;
				data.colour.a = temp.a;
				data.dropper=false;
			}
	}
}

////////////////////////////////////////////////////////////////////////////////
////					setToolSize function
////	Updates the size of the active_tool to the size set in the slider
////		(Only if the tool's size can be set, else it does nothing)
////////////////////////////////////////////////////////////////////////////////

void MAIN_WINDOW::setToolSize(int sz)
{
	int temp = sz;
	active_tool->setToolSize(temp);
}

////////////////////////////////////////////////////////////////////////////////
////					save function
////	
////////////////////////////////////////////////////////////////////////////////
void MAIN_WINDOW::save(){

	Load_Img *load = new Load_Img();
	//write image data to bitmap array format
	uint8_t* BMParray = new uint8_t[data.height*data.width*3];
	BMParray = data.arrayToBMP();

	QString saveimg =  QFileDialog::getSaveFileName(this, tr("Save File.."), QString(), tr("JPEG (*.jpg *.jpeg);; BMP (*.bmp);; PNG (*.png);; TIFF (*.tif);;"));
	QByteArray ba = saveimg.toLocal8Bit();
    const char *imagename = ba.data();

	QString suffix;
	QString delimiterPattern(".");
	QStringList parts = saveimg.split(delimiterPattern);
	//int s = parts.size;
	suffix = parts.last();
	if(suffix == "bmp"){
		load->writeBMP(imagename, BMParray, data.height, data.width); //write bitmap file
	}

	else{
		load->writeOther(imagename, suffix, &data);
	}
}

