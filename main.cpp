#include <GL/glut.h>
#include<iostream>
#include<cmath>

using namespace std;

//int x1,y1,x2,y2;

void Bresenham1(int x1, int y1, int x2, int y2) {
    int p;
    int x = x1, y = y1;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int xIncrement, yIncrement;

    if (x2 >= x1)
    {
        xIncrement = 1;
    }
    else {
        xIncrement = -1;
    }
    if (y2 >= y1) {
        yIncrement = 1;
    }
    else {
        yIncrement = -1;
    }

    if (dy <= dx) {
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            glVertex2f(x, y);
            x += xIncrement;
            p = p + 2 * dy;
        }
    }
    else {
        p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            glVertex2f(x, y);
            if (p >= 0) {
                y += yIncrement;
                p = p + 2 * (dx - dy);
            }
            else {
                p = p + 2 * dx;
            }
        }

    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glPointSize(3);
    glBegin(GL_POINTS);


    Bresenham1(1, 1, 90, 1);
    


    glEnd();
    glFlush();
}
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -100, 100); // Set up a 2D orthographic projection
}

int main(int argc, char** argv) {

    cout << "enter the values of x,y,x2,y2" << endl;

    /*cin>>x1;
    cin>>y1;
    cin>>x2;
    cin>>y2;*/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Line Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}

