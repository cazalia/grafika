#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/glut.h>
#include <cmath>

void drawCircle(GLfloat centerX, GLfloat centerY, GLfloat radius, int numSegments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= numSegments; i++)
    {
        float angle = 2.0f * 3.1415926f * (float)i / (float)numSegments;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}

void init(void)
{
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-2.0f, 0.0f, 1.5f, 30);
    drawCircle(0.0f, 0.0f, 2.0f, 30);
    drawCircle(2.0f, 0.0f, 1.5f, 30);
    drawCircle(0.0f, 1.0f, 1.5f, 30);
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Gambar Awan Sederhana");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
