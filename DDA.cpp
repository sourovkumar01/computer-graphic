#include<windows.h>
#include<GL/glut.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>

#include<stdlib.h>

using namespace std;

int x1,y1,x2,y2;
/// 20 30 60 80
/// 20 20 70 60

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    // //Draw axis
    glBegin(GL_LINES);
        glColor3f(0,1,1);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);

        glColor3f(1,1,0);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();

    float m = ((1.0)*(y2-y1)) / ((1.0)*(x2 - x1));

    cout << m << endl;
    if(m < 1 ){
        if(x1 > x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        glBegin(GL_POINTS);
        float  y = y1;
        for(int x = x1; x <= x2; x++){
            y += m;
            float p1 = 0, p2 = 0;
            p1 = (1.0)*x / 100;
            p2 = y / 100;

            cout << p1 << " - "<< p2 << endl;

            glVertex2f(p1,p2);
        }
        glEnd();
    }

    if(m > 1){
        float x = x1;
        if(y1 > y2){
            swap(x1,x2);
            swap(y1,y2);
        }
        glBegin(GL_POINTS);
        for(int y = y1; y <= y2; y++){
            x += (1/m);
            cout << x << endl;
            float p1 = 0, p2 = 0;

            p1 = x / 100;
            p2 = (1.0)*y / 100;

            cout <<p1 << " - "<< p2 << endl;

            glVertex2f(p1,p2);
        }
        glEnd();
    }



    glFlush();
}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitWindowSize(500,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("LINES");

    cin >> x1 >> y1 >> x2 >> y2;

    glutDisplayFunc(display);

    glutMainLoop();
    return EXIT_SUCCESS;
}
