#include <GL/glut.h>
#include <iostream>
#include <list>
#include <math.h>
#include <stdio.h>

class Ponto{

private:
	int x;
	int y;
	
public:
	Ponto(int a, int b){
		x = a;
		y = b;
	}
	
	int getX(){
		return x;
	}
	
	
	int getY(){
		return y;
	}


};


std::list<Ponto> listaPontos;

void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0);
	glColor3f(0,1,0);
	
	std::list<Ponto>::iterator it;
	
	glBegin(GL_POINTS);
	for(it = listaPontos.begin(); it != listaPontos.end(); it++){
		glVertex2i(it->getX(),it->getY());
	}
	
	glEnd();
	
	glFlush();

}

void Mouse(int button, int state, int x, int y){

	if(button == GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN){
			listaPontos.push_back(Ponto(x,y));
		}
	}

	if(button == GLUT_RIGHT_BUTTON){
		if(state == GLUT_DOWN){
			
			std::list<Ponto>::iterator it;
			std::list<Ponto>::iterator itMenorDistancia;
			
			
			int menorDistancia = 9999999;
			
			
			for(it = listaPontos.begin(); it != listaPontos.end(); it++){
				
				int distancia = sqrt(pow(x - it->getX(), 2) + pow(y - it->getY(),2));
				
				if(distancia < menorDistancia){
					menorDistancia = distancia;
					itMenorDistancia = it;
				}
				
			}
			
			listaPontos.erase(itMenorDistancia);
			
			
			
		}
	}

	glutPostRedisplay();	
	
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Exemplo");
	gluOrtho2D(0, 500, 500, 0);
	glutDisplayFunc(Desenha);
	glutMouseFunc(Mouse);
	glutMainLoop();
}

