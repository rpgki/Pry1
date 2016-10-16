/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/* 
 * File:   main.cpp
 * Author: Carlos
 *
 * Created on 6 de septiembre de 2016, 11:02 PM
 */
 
/*Prueba 365
 65465464+otra prueba*/
 
#include <iostream>
#include <memory>
#include <iostream>
using namespace std;
 
#include "Grafo.h"
#include "Simulador.h"
#include "Visualizador.h"
#include "LstAdy.h"
#include <windows.h>
#include <GL/glut.h>
#include "Datos.h"
 
 
Grafo g("redMuyPeq.txt");
Datos d(g);
Simulador s(g);
     
// EFE: Dibuja una línea con dos puntos cuadrados en sus extremos centrados en (xo,yo) y (xd,yd).
void dibujarLinea(float xo, float yo, float xd, float yd, Grafo::E e){
  glPointSize(5.8); //Ajusta el tamaño de los puntos
  if(e == Grafo::S){
  glColor3f(0.0, 0.0, 1.0); //Color blanc
  glBegin(GL_POINTS); // dibuja los puntos
    glVertex2f(xo, yo);
  } else{ if(e == Grafo::I){
  glColor3f(1.0, 0.0, 0.0); //Color blanc
  glBegin(GL_POINTS); // dibuja los puntos
    glVertex2f(xo, yo);
  }else{ 
      glColor3f(0.0, 1.0, 0.0); //Color blanc
  glBegin(GL_POINTS); // dibuja los puntos
    glVertex2f(xo, yo);
  }
  }
  glEnd();
  glLineWidth(1.6); //Ajusta el ancho de las lineas
  glColor3f(0.2, 1.0, 1.0); //Color blanco
  glBegin(GL_LINES); // dibuja una sola linea
    glVertex2f(xo, yo);
    glVertex2f(xd, yd);
  glEnd();    
}
 
void display(void) // no puede tener parámetros, por eso se usan variables globales
{
    Datos d(g);
    int* arrAdya;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (int i = 0; i < g.obtTotVrt(); i++) {
        arrAdya = g.obtAdy(i);
        for (int j = 0; j < g.obtTotAdy(i); j++) {
            dibujarLinea(d.obtCrdX(i), d.obtCrdY(i), d.obtCrdX(arrAdya[j]), d.obtCrdY(arrAdya[j]), d.obtEst(i));
        }
    }
    glFlush();
}
 
// EFE: captura un evento del teclado mientras el control esté en la ventana.
void keyboard(unsigned char key, int x, int y)
{
     
  switch (key)
  {
    case 32: // para capturar el evento blanco-tecleado
        s.simular();
        glutPostRedisplay(); // redibuja
        break;
  }
}
 
void visualizar(int argc, char **argv){
  glutInit(&argc, argv);
  glutCreateWindow("Ejemplo glut");
  glutKeyboardFunc(keyboard); // declara una función para capturar eventos del teclado
  s.iniciarSim(3, 0.5, 5, 0.5, 0.5);
  // se inicializan variables globales: xo = -0.4; yo = -0.7; xd = 0.6; yd = 0.7; delta = 0.05;
  /*for(float i = 0.0; i <= 1.80; i += 0.2){
    d.inicializarDatos(0.825*cos(i*3.1415)+0.1, 0.825*sin(i*3.1415), 0.825*cos(0.0*3.1415)+0.1, 0.825*sin(0.0*3.1415), 0.05);
     
  }*/
   
  glutDisplayFunc(display); // dibuja la primera imagen
  glutMainLoop(); // otorga el control a la ventana, cuando se cierra retorna al main.    
}
 
int main(int argc, char **argv)
{
  visualizar(argc, argv);
  return 0;
}