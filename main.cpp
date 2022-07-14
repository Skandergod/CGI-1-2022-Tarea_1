
// 1. Bajar freeglut http://www.lighthouse3d.com/tutorials/glut-tutorial/
// 2. Bajar AntTweakBar http://anttweakbar.sourceforge.net/doc/
// 3. Bajar "Open File Dialog", "open"

#define FREEGLUT_STATIC
#include "GL/freeglut.h"
#include <list>
#include <iostream>
#include <memory>
#include "line.h"
#include "glut.h"
#include "AntTweakBar.h"

using namespace std;


int width = 800, height = 600;





list <shared_ptr<CShape>> shapes;

shared_ptr<CShape> current_shape;


void renderScene(void) 
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.5f, 0.25f);
	TwDraw();

	for (auto const& x : shapes) 
		x->render();
	
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

	TwWindowSize(width, height);
}

int main(int argc, char** argv)
{
	// init GLUT and create Window

	TwBar* bar;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(width, height);
	glutCreateWindow("Proyecto 1 - Daniel");

	//Antweakbar

		TwInit(TW_OPENGL, NULL);
		bar = TwNewBar("Figure");

	//Configuracion del Sample
		// Set GLUT event callbacks
		// - Directly redirect GLUT mouse button events to AntTweakBar
		glutMouseFunc((GLUTmousebuttonfun)TwEventMouseButtonGLUT);
		// - Directly redirect GLUT mouse motion events to AntTweakBar
		glutMotionFunc((GLUTmousemotionfun)TwEventMouseMotionGLUT);
		// - Directly redirect GLUT mouse "passive" motion events to AntTweakBar (same as MouseMotion)
		glutPassiveMotionFunc((GLUTmousemotionfun)TwEventMouseMotionGLUT);
		// - Directly redirect GLUT key events to AntTweakBar
		glutKeyboardFunc((GLUTkeyboardfun)TwEventKeyboardGLUT);
		// - Directly redirect GLUT special key events to AntTweakBar
		glutSpecialFunc((GLUTspecialfun)TwEventSpecialGLUT);
		// - Send 'glutGetModifers' function pointer to AntTweakBar;
		//   required because the GLUT key event functions do not report key modifiers states.
		TwGLUTModifiersFunc(glutGetModifiers);
		TwWindowSize(width, height);
		TwDefine("Figure refresh = '0.0001f'");
		TwDefine("Figure resizable = false");
		TwDefine("Figure fontresizable = false");
		TwDefine("Figure movable = false");
		TwDefine("Figure visible = false");
		TwDefine("Figure position = '20 20'");
		TwDefine("Figure size = '220 320' color='96 216 224'");
		TwDefine("Figure visible = true");


	

	cout << "Hello..." << endl;

	glViewport(0, 0, width, height);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);

	shared_ptr<CLine> l1 = make_shared <CLine>(1, 1, 1);
	shared_ptr<CLine> l2 = make_shared <CLine>(1, 0, 0);
	
	l1->set(0, 0, 200, 200);
	l2->set(200, 200, 400, 200);

	shapes.push_back(l1);
	shapes.push_back(l2);

	// register callbacks
	glutDisplayFunc(renderScene);
	
	// Here is our new entry in the main function
	glutReshapeFunc(changeSize);
	glutMainLoop();
	cout << "Chao..." << endl;
	return 0;
}
