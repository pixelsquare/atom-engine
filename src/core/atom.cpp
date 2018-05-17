#include "atom.h"
#include <iostream>

// function pointer used in start and update functions
void (*startPtr)(void);
void (*updatePtr)(void);

ATOM_BEGIN

//void atomStartFunc( void(*func)(void) ) 
//{
//	startPtr = func;
//}
//
//void atomUpdateFunc( void(*func)(void) ) 
//{
//	updatePtr = func;
//}
//
//void Scene() 
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//	if(inEditMode) 
//    {
//		glTranslatef(0.0f, 0.0f, -editMode.position.z);
//		glTranslatef(editMode.position.x, editMode.position.y, 0.0f);
//		glRotatef(editMode.rotation.x, 1.0f, 0.0f, 0.0f);
//		glRotatef(editMode.rotation.y, 0.0f, 1.0f, 0.0f);
//	}
//	else 
//    {
//		gluLookAt(atomCamera.position.x, atomCamera.position.y, atomCamera.position.z,
//			atomCamera.lookAt.x, atomCamera.lookAt.y, atomCamera.lookAt.z,
//			atomCamera.up.x, atomCamera.up.y, atomCamera.up.z);
//	}
//
//    if(updatePtr != NULL)
//    {
//        updatePtr();
//    }
//
//	if(keyDown[inputKey]) 
//    {
//		isPressed = true;
//		keyDown[inputKey] = false;
//	}
//
//	if(specialKeyHold[inputSpecialKey]) 
//    {
//		specialPressed= true;
//		specialKeyHold[inputSpecialKey] = false;
//	}
//
//	specialPressed = false;
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//void ResizeatomWindow(int width, int height) 
//{
//    if(height == 0)
//    {
//        height = 1;
//    }
//
//	float aspectRatio = 0.0f;
//	aspectRatio = 1.0 * width / height;
//
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	gluPerspective(45, aspectRatio, 0.1, 1000);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void Timer(int extra) 
//{
//	glutPostRedisplay();
//	glutTimerFunc(10, Timer, extra);
//}
//
//void InitRendering() 
//{
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHTING); //Enable lighting
//	//glEnable(GL_LIGHT0); //Enable light #0
//	//glEnable(GL_LIGHT1); //Enable light #1
//	glEnable(GL_NORMALIZE); //Automatically normalize normals
//	glShadeModel(GL_SMOOTH); //Enable smooth shading
//
//	glClearColor(atomWindow.color.r,
//				atomWindow.color.g,
//				atomWindow.color.b,
//				atomWindow.color.a);
//}
//
//void atomInitialize(int argc, char **argv) 
//{
//	//srand(time(0));
//	asset[0].LoadObject("assets\\Cube.obj");
//	asset[1].LoadObject("assets\\Plane.obj");
//	asset[2].LoadObject("assets\\Sphere.obj");
//	asset[3].LoadObject("assets\\Capsule.obj");
//	asset[4].LoadObject("assets\\Cone.obj");
//	asset[5].LoadObject("assets\\Cylinder.obj");
//	asset[6].LoadObject("assets\\Pyramid.obj");
//	asset[7].LoadObject("assets\\Torus.obj");
//
//    if(startPtr != NULL)
//    {
//        startPtr();
//    }
//
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
//
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(atomWindow.width, atomWindow.height);
//
//	glutTimerFunc(0, Timer, 0);
//
//	atomWindow.windowHandle = glutCreateWindow(atomWindow.name);
//	glutDisplayFunc(&Scene);
//	glutReshapeFunc(&ResizeatomWindow);
//	//glutIdleFunc(&Scene);
//	InitRendering();
//
//	glutKeyboardFunc(&atomOnKeyDown);
//	glutKeyboardUpFunc(&atomOnKeyHold);
//	glutSpecialFunc(&atomOnSpecialKey);
//
//	glutMouseFunc(&atomOnMouseButton);
//	glutMotionFunc(&atomOnMouseMove);
//	glutPassiveMotionFunc(&atomOnPassiveMouse);
//
//	glutMainLoop();
//}
//
//void atomatomWindowWidth(int width) 
//{
//	atomWindow.width = width;
//}
//
//void atomatomWindowHeight(int height) 
//{
//	atomWindow.height = height;
//}
//
//void atomatomWindowName(char *name) 
//{
//	atomWindow.name = name;
//}
//
//void atomatomWindowBGColor(double r, double g, double b, double a) 
//{
//	atomWindow.color.r = r;
//	atomWindow.color.g = g;
//	atomWindow.color.b = b;
//	atomWindow.color.a = a;
//}

ATOM_END