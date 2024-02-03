#include <iostream>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// #include <GL/glut.h>

GLfloat vertices_octahedron[][3] = {
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {-1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, -1.0}
};

static GLfloat theta_octahedron[3] = {0.0, 0.0, 0.0};

void polygon_octahedron(int a, int b, int c) {
    glBegin(GL_TRIANGLES);
    glVertex3fv(vertices_octahedron[a]);
    glVertex3fv(vertices_octahedron[b]);
    glVertex3fv(vertices_octahedron[c]);
    glEnd();
}

void drawOctahedron() {
    glColor3f(1.0, 0.0, 0.0);
    polygon_octahedron(0, 1, 2);
    glColor3f(0.0, 1.0, 0.0);
    polygon_octahedron(0, 2, 3);
    glColor3f(0.0, 0.0, 1.0);
    polygon_octahedron(0, 3, 4);
    glColor3f(1.0, 1.0, 0.0);
    polygon_octahedron(0, 4, 1);
    glColor3f(1.0, 0.0, 1.0);
    polygon_octahedron(5, 2, 1);
    glColor3f(0.0, 1.0, 1.0);
    polygon_octahedron(5, 3, 2);
    glColor3f(1.0, 1.0, 1.0);
    polygon_octahedron(5, 4, 3);
    glColor3f(0.5, 0.5, 0.5);
    polygon_octahedron(5, 1, 4);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(theta_octahedron[0], 1.0, 0.0, 0.0);
    glRotatef(theta_octahedron[1], 0.0, 1.0, 0.0);
    glRotatef(theta_octahedron[2], 0.0, 0.0, 1.0);

    drawOctahedron();

    glFlush();
    glutSwapBuffers();
}

void spinOctahedron() {
    theta_octahedron[0] += 1.0;
    if (theta_octahedron[0] > 360.0) theta_octahedron[0] -= 360.0;
    
    theta_octahedron[1] += 1.0;
    if (theta_octahedron[1] > 360.0) theta_octahedron[1] -= 360.0;

    theta_octahedron[2] += 1.0;
    if (theta_octahedron[2] > 360.0) theta_octahedron[2] -= 360.0;

    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Rotating Octahedron");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(spinOctahedron);
    glutMainLoop();
    return 0;
}
