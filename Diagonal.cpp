#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>

#include<stdlib.h>


void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    //Draw axis

    glClear(GL_COLOR_BUFFER_BIT);

    //Draw axis
    glBegin(GL_LINES);
        glColor3f(0,1,1);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);

        glColor3f(1,1,0);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0,1,1);

    for(float  x= 0.0; x<=1.0 ;x+=0.01){

        float y=x+0.01;
        glVertex2f(x,y);
    }

    glEnd();


    glFlush();
}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitWindowSize(500,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("POINT");
    glutDisplayFunc(display);

    glutMainLoop();
    return EXIT_SUCCESS;
}
