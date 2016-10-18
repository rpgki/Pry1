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
#include <windows.h>
#include <GL/glut.h>
#include <string>
#include "Grafo.h"
#include "Simulador.h"
#include "Datos.h"

using namespace std;
 
string nArch;
int N;
int K;
double beta;
int valor;
 
Grafo crearGrafo(){
    cout << "Programa de simulacion de un virus en una red. Por favor digite 1 si desea crear una red personalizada o 2 si desea ingresar el archivo" << endl;
    cin >> valor;
    if(valor == 1){
        cout << "Cantidad de vertices: " << endl;
        cin >> N;
        cout << "Grado de vertices promedio: " << endl;
        cin >> K;
        cout << "Probabilidad de adyacencia: " << endl;
        cin >> beta;
        return Grafo(N,K,beta);
    } else if(valor == 2){
        cout << "Nombre del archivo: " << endl;
        cin >> nArch;
        return Grafo(nArch);
    } else{
        cout << "Introduzca una opcion valida" << endl;
        exit(1);
    }
}
 
Grafo g = crearGrafo();
Datos d(g);
Simulador s(g);
 
int tam;
int maxFreq;
double inf;
double recu;
double res;
     
// EFE: Dibuja una línea con dos puntos cuadrados en sus extremos centrados en (xo,yo) y (xd,yd).
void dibujarLinea(float xo, float yo, float xd, float yd, Grafo::E e, Grafo g){
  glPointSize(9.0); //Ajusta el tamaño de los puntos
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
  glColor3f(0.5, 0.5, 0.5); //Color blanco
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
            dibujarLinea(d.obtCrdX(i), d.obtCrdY(i), d.obtCrdX(arrAdya[j]), d.obtCrdY(arrAdya[j]), d.obtEst(i),g);
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
 
void visualizar(int argc, char **argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Ejemplo glut");
    glutKeyboardFunc(keyboard); // declara una función para capturar eventos del teclado
    s.iniciarSim(tam, inf, maxFreq, recu, res);
    glutDisplayFunc(display); // dibuja la primera imagen
    glutMainLoop(); // otorga el control a la ventana, cuando se cierra retorna al main.    
}
 
int main(int argc, char **argv) {
    cout << "Acontinuacion se va a iniciar el programa de simulacion. Por favor ingrese los parametros deseados." << endl;
    cout << "Para propagar el virus presione la tecla espaciadora, una vez se haya abierto la ventana con la red" << endl;
    cout << "El color rojo representa un vertice infectado." << endl;
    cout << "El color verde representa un vertice resistente al virus." << endl;
    cout << "El color azul representa un vertice susceptible al virus." << endl;
    cout << "Por favor ingrese los parametros deseados: " << endl;
    cout << "Nodos infectados: " << endl;
    cin >> tam;
    cout << "Probabilidad de infeccion: " << endl;
    cin >> inf;
    cout << "Maxima frecuencia de chequeo de virus: " << endl;
    cin >> maxFreq;
    cout << "Probabilidad de recuperacion: " << endl;
    cin >> recu;
    cout << "Probabilidad de resistencia: " << endl;
    cin >> res;
    visualizar(argc, argv);
    return 0;
}