#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <list>
#include <math.h>

class Ponto {
private:
	int x;
	int y;
public:
	Ponto(int a, int b) {
		x = a;
		y = b;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int a) {
		x = a;
	}
	void setY(int b) {
		y = b;
	}
};

int OrigemCliqueX;
int OrigemCliqueY;
int raio = 80;
float PontoX;
float PontoY;

void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	
	double angulo = 0.01;
	
	for (double i = 0; i < 7000; i++) {
		glVertex2i(OrigemCliqueX + raio * cos(angulo),OrigemCliqueY + raio * sin(angulo));
		angulo += 0.01;
	}
	
	glEnd();
	
	glFlush();
}

void VerificarMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			OrigemCliqueX = x;
			OrigemCliqueY = y;
		}
	}
	
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(120, 150);
	glutCreateWindow("Exemplo - Circunferencia");
	gluOrtho2D(0, 500, 500, 0);
	glutDisplayFunc(Desenha);
	glutMouseFunc(VerificarMouse);
	glutMainLoop();
}

