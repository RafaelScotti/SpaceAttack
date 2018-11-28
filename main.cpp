//PARA EXECUTAR
// g++ *.cpp -o d -lglut -lGLU -lGL -lGLEW
// ./d
#include <GL/freeglut.h>
#include "Player.h"
#include "Game.h"

GLfloat angle, fAspect, stepX, stepY, stepZ;;
GLfloat xRotated, yRotated, zRotated;
//Player p1;
Game game;


void Init(void)
{


	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.7,0.7,1.0 };		    // "cor"
	GLfloat luzEspecular[4] = { 0.0, 0.0, 0.0, 1.0 };   // "brilho"
	GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };

	GLfloat mat_emission[] = { 1.0, 0.0, 0.0, 1.0 };    // emisao do material

													    // Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;

	// Especifica que a cor de fundo da janela sera preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorizacao de Gouraud
	glShadeModel(GL_SMOOTH);


	// Define emisao do material
	//glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

	// Define a refletancia do material
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

	// Define a concentracao do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parametros da luz de numero 0 (total de 8 luzes [0..7])
	//glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	//glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definicao da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminacao
	glEnable(GL_LIGHTING);
	// Habilita a luz de numero 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	stepX = stepY = stepZ = 0;
	angle = 45;
}

// Funcao usada para especificar o volume de visualizacao
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projecao
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projecao
	glLoadIdentity();

	// Especifica a projecao perspectiva
	gluPerspective(angle, fAspect, 0.1, 900);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posicao do observador e do alvo
	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
}

void WindowSize(GLsizei w, GLsizei h)
{
	// Para previnir uma divisao por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correcao de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void specialKeys(int key, int x, int y) {

	game.controller(key);

	glutPostRedisplay();
	//glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		game.reset();
		break;
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}


void Draw(void)
{

	if (!game.hasStarted()) {  // se o jogo estiver parado, exibe o menu

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		game.showMenu();
		glutSwapBuffers();

	}else{
		EspecificaParametrosVisualizacao();

			// Limpa a janela e o depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			game.creteGame(); // inicia o jogo
			game.collision(); // detecta colisão (em desenvolvimento!)
			glutSwapBuffers();
	}
}






int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 720);
	glutCreateWindow("Space Attack");
	glutDisplayFunc(Draw);
	glutIdleFunc(Draw);
	glutReshapeFunc(WindowSize);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
	Init();
	glutMainLoop();
}
