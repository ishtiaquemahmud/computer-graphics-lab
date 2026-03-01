#include <GL/glut.h>
#include <iostream>


void Bresenham1(int x1, int y1, int x2, int y2) {

    glBegin(GL_POINTS);
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
            y += yIncrement;
            if (p >= 0) {
                x += xIncrement;
                p = p + 2 * (dx - dy);
            }
            else {
                p = p + 2 * dx;
            }
        }

    }
    glEnd();
}


void plotCirclePoints(int xc, int yc, int x, int y) {
    //write your code here
    glBegin(GL_POINTS);
    glVertex2d(xc + x, yc + y);
    glVertex2d(xc - x, yc + y);
    glVertex2d(xc + x, yc - y);
    glVertex2d(xc - x, yc - y);
    glVertex2d(xc + y, yc + x);
    glVertex2d(xc - y, yc + x);
    glVertex2d(xc + y, yc - x);
    glVertex2d(xc - y, yc - x);
    glEnd();

}



void circleMidPoint(int xCenter, int yCenter, int radius) {
    //write your code here
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    plotCirclePoints(xCenter, yCenter, x, y);

    while (x <= y) {
        x++;
        if (p < 0) {
            p = p + (2 * x) + 1;
        }
        else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        plotCirclePoints(xCenter, yCenter, x, y);
    }

}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    int centerX = 200;
    int centerY = 200;
    int radius = 100;
    circleMidPoint(centerX, centerY, radius);





    glColor3f(0.0, 1.0, 0.0);
    Bresenham1(20, 350, 20, 20);
    Bresenham1(20, 350, 350, 350);
    Bresenham1(20, 20, 350, 20);
    Bresenham1(350, 20, 350, 350);







    glFlush();
}


// OpenGL initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);      // Set projection matrix mode
    glLoadIdentity();                 // Load identity matrix
    gluOrtho2D(0, 400, 0, 400);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




