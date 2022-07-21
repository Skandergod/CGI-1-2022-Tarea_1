
// 1. Bajar freeglut http://www.lighthouse3d.com/tutorials/glut-tutorial/
// 2. Bajar AntTweakBar http://anttweakbar.sourceforge.net/doc/
// 3. Bajar "Open File Dialog", "open"

#include <cstdlib>
#include "include/GL/freeglut.h"
#include <list>
#include <iostream>
#include <memory>
#include "Figure.h"
#include "Line.h"
#include "AntTweakBar.h"

#define GAP  25

using namespace std;


int width = 800, height = 600;
int button = 0, action = 0, x = 0, y = 0;

list <shared_ptr<CFigure>> shapes;

shared_ptr<CFigure> current_shape;

shared_ptr<CLine> l1;
shared_ptr<CLine> l2;





void subwindow1_display(void);

void subwindow2_display(void);

void main_mouse(int button, int state, int x, int y)
{
	//  Notify that we are clicking on the main window
	printf("Main Window: ");

	switch (button)
	{
		//  Left Button Clicked
	case GLUT_LEFT_BUTTON:

		switch (state)
		{
			//  Pressed 
		case GLUT_DOWN:
			printf("Mouse Left Button Pressed (Down)...\n");
			break;
			//  Released
		case GLUT_UP:
			printf("Mouse Left Button Released (Up)...\n");
			break;
		}

		break;

		//  Middle Button clicked
	case GLUT_MIDDLE_BUTTON:

		switch (state)
		{
			//  Pressed
		case GLUT_DOWN:
			printf("Mouse Middle Button Pressed (Down)...\n");
			break;
			//  Released
		case GLUT_UP:
			printf("Mouse Middle Button Released (Up)...\n");
			break;
		}

		break;

		//  Right Button Clicked
	case GLUT_RIGHT_BUTTON:

		switch (state)
		{
			//  Pressed
		case GLUT_DOWN:
			printf("Mouse Right Button Pressed (Down)...\n");
			break;
			//  Released
		case GLUT_UP:
			printf("Mouse Right Button Released (Up)...\n");
			break;
		}

		break;

	}
}

void main_motion(int x, int y)
{
	//  Notify that we are dragging over the main window
	printf("Main Window: ");

	//  Print the mouse drag position
	printf("Mouse Drag Position: %d, %d.\n", x, y);
}

void main_pmotion(int x, int y)
{
	//  Notify that we are moving the mouse over the main window
	//printf ("Main Window: ");

	//  Print mouse move positopn
	//printf ("Mouse Move Position: %d, %d.\n", x, y);
}


void renderScene(void) 
{

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.5f, 0.25f);

	subwindow1_display();
	subwindow2_display();
	
	glutSwapBuffers();
}

void changeSize(int w, int h) 
{
	if (h == 0)
		return;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	glOrtho(0, w, 0, h, -1, 1);

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	width = w;
	height = h;

	
}

void changeSize2(int w, int h)
{
	glColor3f(1.0f, 0.0f, 0.00f);
	TwWindowSize(width, height);
}

void subwindow1_display(void)
{
	printf("Drawing SubWindow 1 contents.\n");

	//  Set background color to blue
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//  Set drawing color to yellow
	glColor3f(1, 1, 0);

	//  Draw teapot
	//glutWireTeapot(0.5);

	//  Swap front and back buffers
	
	TwDraw();
	glutSwapBuffers();
	
}

void main_keyboard(unsigned char key, int x, int y)
{
	//  Notify that an ASCII key is pressed on the main window
	printf("Main Window: ");

	//  Print what key the user is hitting
	printf("User is hitting the '%c' key.\n", key);
	printf("ASCII code is %d.\n", key);

	switch (key)
	{
		//  User hits A key
	case 'a':

		break;

		//  User hits Shift + A key
	case 'A':

		break;

		//  User hits Enter
	case '\r':
		printf("User is hitting the Return key.\n");
		break;

		//  User hits Space
	case ' ':
		printf("User is hitting the Space key.\n");
		break;

		//  User hits back space
	case 8:
		printf("User is hitting the Back Space key.\n");
		break;

		//  User hits ESC key
	case 27:
		exit(1);
		break;
	}

	glutPostRedisplay();
}

void subwindow2_reshape(int width, int height)
{
	//  Represents a side of the viewport. A viewport is intended to
	//  to take a square shape so that the aspect ratio is reserved
	int viewport_side = 0;

	//  Viewport x and y positions (Center viewport)
	int viewport_x = 0, viewport_y = 0;

	//  Calculate viewport side
	viewport_side = (width > height) ? height : width;

	//  Calculate viewport position
	viewport_x = (width - viewport_side) / 2;
	viewport_y = (height - viewport_side) / 2;

	//  Preserve aspect ratio
	glViewport(viewport_x, viewport_y, viewport_side, viewport_side);

	//  Set subwindow width and height
	
	/*
	subwindow2_w = width;
	subwindow2_h = height;
	*/

	//  Notify that we are reshaping subwindow 1
	printf("Subwindow 2: ");

	//  Print current width and height
	printf("Width: %d, Height: %d, Viewport Side: %d.\n", width, height, viewport_side);
}

void subwindow2_display(void)
{
	//  Notify that we are displaying subwindow 2
	printf("Drawing SubWindow 2 contents.\n");

	//  Set background color to yellow
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//  Set drawing color to blue
	glColor3f(0, 0, 1);

	//  Draw teapot
	glutWireTeapot(0.5);

	//  Swap front and back buffers
	glutSwapBuffers();

}

void subwindow2_mouse(int button, int state, int x, int y)
{
	//  Notify that we are clicking on subwindow 2
	printf("SubWindow 2: ");

	switch (button)
	{
		//  Left Button Clicked
	case GLUT_LEFT_BUTTON:

		switch (state)
		{
			//  Pressed 
		case GLUT_DOWN:
			printf("Mouse Left Button Pressed (Down)...\n");
			break;
			//  Released
		case GLUT_UP:
			printf("Mouse Left Button Released (Up)...\n");
			break;
		}

		break;

		//  Middle Button clicked
	case GLUT_MIDDLE_BUTTON:

		switch (state)
		{
			//  Pressed
		case GLUT_DOWN:
			printf("Mouse Middle Button Pressed (Down)...\n");
			break;
			//  Released
		case GLUT_UP:
			printf("Mouse Middle Button Released (Up)...\n");
			break;
		}

		break;

		//  Right Button Clicked
	case GLUT_RIGHT_BUTTON:

		switch (state)
		{
			//  Pressed
		case GLUT_DOWN:
			printf("Mouse Right Button Pressed (Down)...\n");
			break;
			//  Released
		case GLUT_UP:
			printf("Mouse Right Button Released (Up)...\n");
			break;
		}

		break;

	}
}

void main_special(int key, int x, int y)
{
	//  Notify that we are pressing a non-ASCII key on the main window
	printf("Main Window: ");

	switch (key)
	{
	case GLUT_KEY_F1:
		printf("F1 function key.\n");
		break;
	case GLUT_KEY_F2:
		printf("F2 function key. \n");
		break;
	case GLUT_KEY_F3:
		printf("F3 function key. \n");
		break;
	case GLUT_KEY_F4:
		printf("F4 function key. \n");
		break;
	case GLUT_KEY_F5:
		printf("F5 function key. \n");
		break;
	case GLUT_KEY_F6:
		printf("F6 function key. \n");
		break;
	case GLUT_KEY_F7:
		printf("F7 function key. \n");
		break;
	case GLUT_KEY_F8:
		printf("F8 function key. \n");
		break;
	case GLUT_KEY_F9:
		printf("F9 function key. \n");
		break;
	case GLUT_KEY_F10:
		printf("F10 function key. \n");
		break;
	case GLUT_KEY_F11:
		printf("F11 function key. \n");
		break;
	case GLUT_KEY_F12:
		printf("F12 function key. \n");
		break;
	case GLUT_KEY_LEFT:
		printf("Left directional key. \n");
		break;
	case GLUT_KEY_UP:
		printf("Up directional key. \n");
		break;
	case GLUT_KEY_RIGHT:
		printf("Right directional key. \n");
		break;
	case GLUT_KEY_DOWN:
		printf("Down directional key. \n");
		break;
	case GLUT_KEY_PAGE_UP:
		printf("Page up directional key. \n");
		break;
	case GLUT_KEY_PAGE_DOWN:
		printf("Page down directional key. \n");
		break;
	case GLUT_KEY_HOME:
		printf("Home directional key. \n");
		break;
	case GLUT_KEY_END:
		printf("End directional key. \n");
		break;
	case GLUT_KEY_INSERT:
		printf("Insert directional key. \n");
		break;
	}

	glutPostRedisplay();
}

void subwindow2_motion(int x, int y)
{
	//  Notify that we are dragging over subwindow 2
	printf("SubWindow 2: ");

	//  Print the mouse drag position
	printf("Mouse Drag Position: %d, %d.\n", x, y);
}

void subwindow2_pmotion(int x, int y)
{
	//  Notify that we are moving the mouse over subwindow 2
	//printf ("SubWindow 2: ");

	//  Print mouse move positopn
	//printf ("Mouse Move Position: %d, %d.\n", x, y);
}

void main_entry(int state)
{
	if (state == GLUT_ENTERED)
		printf("Mouse entered main window...\n");
	else if (state == GLUT_LEFT)
		printf("Mouse left main window...\n");
}

void subwindow2_keyboard(unsigned char key, int x, int y)
{
	//  Notify that an ASCII key is pressed on subwindow 2
	printf("SubWindow 2: ");

	//  Print what key the user is hitting
	printf("User is hitting the '%c' key.\n", key);
	printf("ASCII code is %d.\n", key);

	switch (key)
	{
		//  User hits A key
	case 'a':

		break;

		//  User hits Shift + A key
	case 'A':

		break;

		//  User hits Enter
	case '\r':
		printf("User is hitting the Return key.\n");
		break;

		//  User hits Space
	case ' ':
		printf("User is hitting the Space key.\n");
		break;

		//  User hits back space
	case 8:
		printf("User is hitting the Back Space key.\n");
		break;

		//  User hits ESC key
	case 27:
		exit(2);
		break;
	}

	glutPostRedisplay();
}

void subwindow2_special(int key, int x, int y)
{
	//  Notify that we are pressing a non-ASCII key on subwindow 2
	printf("SubWindow 2: ");

	switch (key)
	{
	case GLUT_KEY_F1:
		printf("F1 function key.\n");
		break;
	case GLUT_KEY_F2:
		printf("F2 function key. \n");
		break;
	case GLUT_KEY_F3:
		printf("F3 function key. \n");
		break;
	case GLUT_KEY_F4:
		printf("F4 function key. \n");
		break;
	case GLUT_KEY_F5:
		printf("F5 function key. \n");
		break;
	case GLUT_KEY_F6:
		printf("F6 function key. \n");
		break;
	case GLUT_KEY_F7:
		printf("F7 function key. \n");
		break;
	case GLUT_KEY_F8:
		printf("F8 function key. \n");
		break;
	case GLUT_KEY_F9:
		printf("F9 function key. \n");
		break;
	case GLUT_KEY_F10:
		printf("F10 function key. \n");
		break;
	case GLUT_KEY_F11:
		printf("F11 function key. \n");
		break;
	case GLUT_KEY_F12:
		printf("F12 function key. \n");
		break;
	case GLUT_KEY_LEFT:
		printf("Left directional key. \n");
		break;
	case GLUT_KEY_UP:
		printf("Up directional key. \n");
		break;
	case GLUT_KEY_RIGHT:
		printf("Right directional key. \n");
		break;
	case GLUT_KEY_DOWN:
		printf("Down directional key. \n");
		break;
	case GLUT_KEY_PAGE_UP:
		printf("Page up directional key. \n");
		break;
	case GLUT_KEY_PAGE_DOWN:
		printf("Page down directional key. \n");
		break;
	case GLUT_KEY_HOME:
		printf("Home directional key. \n");
		break;
	case GLUT_KEY_END:
		printf("End directional key. \n");
		break;
	case GLUT_KEY_INSERT:
		printf("Insert directional key. \n");
		break;
	}

	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	// init GLUT and create Window
	int mainWindow = 0;
	TwBar* bar;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	

	mainWindow = glutCreateWindow("Proyecto 1 - Daniel");

	//Ventana principal

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutMouseFunc(main_mouse);
	glutMotionFunc(main_motion);
	glutPassiveMotionFunc(main_pmotion);
	glutKeyboardFunc(main_keyboard);
	glutSpecialFunc(main_special);
	glutEntryFunc(main_entry);

	//Primera Sub-Ventana
	//Antweakbar

		TwInit(TW_OPENGL, NULL);
		bar = TwNewBar("Figure");

		int subwindow_1 = glutCreateSubWindow(mainWindow, 0, 0, 256, 600);

		//Configuracion del Sample
		// Set GLUT event callbacks
		glutDisplayFunc (subwindow1_display);
		// - Directly redirect GLUT mouse button events to AntTweakBar
		glutMouseFunc((GLUTmousebuttonfun)TwEventMouseButtonGLUT);
		// - Directly redirect GLUT mouse motion events to AntTweakBar
		glutMotionFunc((GLUTmousemotionfun)TwEventMouseMotionGLUT);
		// - Directly redirect GLUT mouse "passive" motion events to AntTweakBar (same as MouseMotion)
		glutPassiveMotionFunc((GLUTmousemotionfun)TwEventMouseMotionGLUT);
		// - Directly redirect GLUT key events to AntTweakBar
		glutKeyboardFunc((GLUTkeyboardfun)TwEventKeyboardGLUT);
		// - Directly redirect GLUT mouse events to AntTweakBar
		glutMouseFunc((GLUTmousebuttonfun)TwEventMouseButtonGLUT);
		// - Directly redirect GLUT special key events to AntTweakBar
		glutSpecialFunc((GLUTspecialfun)TwEventSpecialGLUT);
		// - Send 'glutGetModifers' function pointer to AntTweakBar;
		//   required because the GLUT key event functions do not report key modifiers states.
		TwGLUTModifiersFunc(glutGetModifiers);
		TwWindowSize(600,800);
		TwDefine("Figure refresh = '0.0001f'");
		TwDefine("Figure resizable = false");
		TwDefine("Figure fontresizable = false");
		TwDefine("Figure movable = false");
		TwDefine("Figure visible = false");
		TwDefine("Figure position = '20 20'");
		TwDefine("Figure size = '220 320' color='96 216 224'");
		TwDefine("Figure visible = true");

		int subwindow_2 = glutCreateSubWindow(mainWindow, 0, 0, 800, 600);

		glutDisplayFunc(subwindow2_display);
		glutReshapeFunc(changeSize2);
		glutMouseFunc(subwindow2_mouse);
		glutMotionFunc(subwindow2_motion);
		glutPassiveMotionFunc(subwindow2_pmotion);
		glutKeyboardFunc(subwindow2_keyboard);
		glutSpecialFunc(subwindow2_special);

		cout << "Hello..." << endl;

		glViewport(0, 0, width, height);	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, 0, height, -1, 1);
	
	

		shapes.push_back(l1);
		shapes.push_back(l2);

		// register callbacks
	
		// Here is our new entry in the main function
	
		glutMainLoop();
		cout << "Chao..." << endl;
		return 0;
}
