#include <GL/glut.h>


void Desenha(void)
{
                   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
  
    glBegin(GL_QUADS);
            glVertex2i(100,150);
            glVertex2i(100,100);

            glVertex2i(150,100);
            glVertex2i(150,150);               
    glEnd();

    glFlush();
}


void resize(GLsizei w, GLsizei h)
{
                   if(h == 0) h = 1;
                           
                   glViewport(0, 0, w, h);

                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   if (w <= h) 
                           gluOrtho2D (0.0f, 180.0f, 0.0f, 180.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 180.0f*w/h, 0.0f, 180.0f);
}

int main(int argc, char** argv)
{
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Exemplo ViewPort");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(resize);
     glutMainLoop();
}
