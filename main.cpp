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
 /*
 * 
 */
int main(int argc, char** argv)
{
	/*Grafo grf(20, 0.5);
	Simulador sml(grf);
	Visualizador vsl(grf,sml);*/

	LstAdy lista;

	lista.agr(4);
	lista.agr(2);
	lista.agr(7);
	lista.agr(5);

	int* b;
	b = lista.obtAdy();
	int a = lista.totAdy();
	for(int i = 0; i < a; i++){
	     cout << "Prueba arreglo: " << b[i] << endl;
	}

	lista.elm(2);
	lista.elm(7);
	lista.elm(4);
	lista.elm(5);

	string h = lista.aHil();

	cout << "Cantidad de adyacencias: " << a << endl;
	cout << "Adyacencias: " << h << endl;
	
	Grafo graf("redMuyPeq.txt");
	
	int vrt = 9;
	cout << "Total adyacencias en " << vrt << ": " <<graf.obtTotAdy(vrt) << endl;
	
	return 0;
}