#include <GL/glut.h>
#include <iostream>
using namespace std;


float X1, Y1, Z1;
float X2, Y2, Z2;
float tranX = 0, tranY = 0, tranZ = 0;
float Tx, Ty, Tz;
float angleX = 0, angleY = 0, angleZ = 0;
float stepX, stepY, stepZ;

void drawCubeFromPoints(float x1, float y1, float z1, float x2, float y2, float z2)
{
    glBegin(GL_QUADS);// total 6 faces

    //write your code here

    glColor3f(1.00, 0.00, 0.00);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);


    glColor3f(0.00, 1.0, 0.00);
    glVertex3f(x1, y1, z1);
    glVertex3f(x1, y2, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y1, z1);


    glColor3f(0.0, 0.00, 1.00);
    glVertex3f(x1, y2, z1);
    glVertex3f(x1, y2, z2);
    glVertex3f(x2, y2, z2);
    glVertex3f(x2, y2, z1);


    glColor3f(1.00, 1.00, 0.00);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2);
    glVertex3f(x1, y1, z2);

    glColor3f(1.0f, 0.00, 1.00);
    glVertex3f(x1, y1, z1);
    glVertex3f(x1, y1, z2);
    glVertex3f(x1, y2, z2);
    glVertex3f(x1, y2, z1);


    glColor3f(0.00, 1.00, 1.00);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x2, y1, z2);

    glEnd();
}


void keyboard(unsigned char key, int, int)
{
    switch (key)
    {
    case 'd': tranX = tranX + Tx;
        break;
    case 'a': tranX = tranX - Tx;
        break;
    case 's': tranY = tranY - Ty;
        break;
    case 'w': tranY = tranY + Ty;
        break;

    case 'f': tranZ = tranZ - Tz;
        break;
    case 'j': tranZ = tranZ + Tz;
        break;

    case 'X': angleX = angleX + stepX;
        break;
    case 'x': angleX = angleX - stepX;
        break;
    case 'Y': angleY = angleY + stepY;
        break;
    case 'y': angleY = angleY - stepY;
        break;
    case 'Z': angleZ = angleZ + stepZ;
        break;
    case 'z': angleZ = angleZ - stepZ;



    }

    glutPostRedisplay();
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(15, 15, 25, //eye/camera position
        0, 0, 0,// camera looking at
        0, 1, 0);// which direction is up
    glTranslatef(tranX, tranY, tranZ);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    glRotatef(angleZ, 0, 0, 1);

    drawCubeFromPoints(X1, Y1, Z1, X2, Y2, Z2);
    glutSwapBuffers();
}






void init()
{
    glEnable(GL_DEPTH_TEST);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 100.0);


    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    cout << "Enter first point (x1 y1 z1): ";
    cin >> X1 >> Y1 >> Z1;


    cout << "Enter second point (x2 y2 z2): ";
    cin >> X2 >> Y2 >> Z2;

    cout << "Enter the value of Tx,Ty,TZ :";
    cin >> Tx >> Ty >> Tz;

    cout << "Enter the value of stepx stepy stepz :";
    cin >> stepX >> stepY >> stepZ;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Object View");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();


    return 0;
}



