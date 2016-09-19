/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/* 
 * File:   Grafo.cpp
 * Author: Carlos
 * 
 * Created on 6 de septiembre de 2016, 11:02 PM
 */
 
#include "Grafo.h"
 
Grafo::Grafo(int N, int K, double beta) {
    arrNdoVrt_ptr = new NdoVrt[N];
 
    // #1: se crea la laticia regular anular
    for (int i = 0; i < N; i++) {
        // agrega adyacencias desde i+1 hasta i + K/2
        for (int j = 1; j < K / 2 + 1; j++) {
            arrNdoVrt_ptr[i].lstAdy.agr(i + j);
            arrNdoVrt_ptr[i + j].lstAdy.agr(i); // por ser no dirigida la red
        }
        // agrega adyacencias desde i-1 hasta i - K/2
        for (int j = K / 2; j > 0; j--) {
            if ((i - j) >= 0) {
                arrNdoVrt_ptr[i].lstAdy.agr(i - j);
                arrNdoVrt_ptr[i - j].lstAdy.agr(i); // por ser no dirigida la red
            } else {
                arrNdoVrt_ptr[i].lstAdy.agr(N - j);
                arrNdoVrt_ptr[N - j].lstAdy.agr(i); // por ser no dirigida la red
            }
        }
    }
 
    // Se construye el generador de números al azar basado en una semilla tomada
    // del reloj del sistema:    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    // Se cargan los dados
    std::uniform_real_distribution<double> dados_0_1(0.0, 1.0);
 
 
    //#2: se re-alambran las conexiones usando beta
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            // Genera un número al azar entre 0 y 1
            int numAzar = dados_0_1(generator);
            if ((arrNdoVrt_ptr[i].lstAdy.bus(j)) &&(numAzar <= beta)) { // se re-alambra
                // se borra j de la lstAdy de i
                arrNdoVrt_ptr[i].lstAdy.elm(j);
                arrNdoVrt_ptr[j].lstAdy.elm(i);
 
                int* sonAdyDeI = new int[N];
                int cntNoAdyDeI = 0;
 
                // se cuentan e identifican todos los nodos no adyacentes a i
                for (int k = 0; k < N; k++) {
                    if (!arrNdoVrt_ptr[i].lstAdy.bus(k) && (k != i)) {
                        sonAdyDeI[k] = false;
                        cntNoAdyDeI++;
                    } else sonAdyDeI[k] = true;
                }
 
                // seleccionar entre todas las no-adyacencias una basándose en 
                // la distribución uniforme
                std::uniform_int_distribution<int> dados_0_N(0, cntNoAdyDeI - 1);
                int posNuevaAdy = dados_0_N(generator);
 
                // se busca nueva adyacencia en el vector de no-adyacencias
                int nuevaAdy = 0;
                int cuentaFalse = 0;
                for (int k = 0; k < N; k++) {
                    if (!sonAdyDeI[k]) {
                        if (cuentaFalse == posNuevaAdy)
                            nuevaAdy = k;
                        cuentaFalse++;
                    }
                }
 
                // se re-alambra o sustituye j por k
                arrNdoVrt_ptr[i].lstAdy.agr(nuevaAdy);
                arrNdoVrt_ptr[nuevaAdy].lstAdy.agr(i);
            }
        }
}
 
Grafo::Grafo(const Grafo& orig) {
 
}
 
Grafo::Grafo(string nArch) {
	string hilera; //se inicializa la variable que contendra las hileras del archivo
	int cntVrt; //se guarda en esta variable la cantidad de vertices leidos en la primer linea del archivo
	string aux; //en esta variable se guarda cada caracter de la hilera
	int pos = 0; //contador para posicion del arreglo que contendra los nodos
	ifstream grafo(nArch); //se lee el archivo que contiene el grafo
	
	if (!grafo) { // operador ! sobrecargado
		cerr << "No se pudo abrir el archivo de entrada" << endl;
		exit(1);
	}
	
	getline(grafo, hilera); //se lee la primera linea del archivo
	cntVrt = stoi(hilera); //se convierte la primera linea a entero
	arrNdoVrt_ptr = new NdoVrt[cntVrt]; //se inicializa el arreglo que contendra a los vertices
	while(getline(grafo, hilera)){ //mientras no se acaben las hileras del archivo
		for(int i = 0; i < hilera.size()-1; i++){ //este ciclo lee todos los caracteres de la hilera
			if(hilera[i] != ' '){
				aux = aux + hilera[i]; //se guarda el caracter en aux
			} else{
				arrNdoVrt_ptr[pos].lstAdy.agr(stoi(aux));//se cambia el caracter a entero y se asigna a la lista correspondiente a cada vertice
				//cout << "Elementos de las hileras: " << stoi(aux) << endl;
				//cout << "Posicion del arreglo: " << pos << endl;
				aux = "";
			}
		}
		arrNdoVrt_ptr[pos].lstAdy.agr(stoi(aux));//se cambia el caracter a entero y se asigna a la lista correspondiente a cada vertice
		//cout << "Elementos de las hileras: " << stoi(aux) << endl;
		//cout << "Posicion del arreglo: " << pos << endl;
		aux = "";
		pos = pos + 1; //se aumenta el contador de posiciones para el arreglo de vertices
	}
}
 
Grafo::~Grafo() {
 
}
 
bool Grafo::xstVrt(int vrt) const {
 
}
 
bool Grafo::xstAdy(int vrtO, int vrtD) const {
 
}
 
int* Grafo::obtAdy(int vrt) const {
 
}
 
int Grafo::obtTotVrt() const {
 
}
 
int Grafo::obtTotAdy() const {
	
}
 
int Grafo::obtTotAdy(int vrt) const {
	int totAdy;
	totAdy = arrNdoVrt_ptr[vrt].lstAdy.totAdy();
	return totAdy;
}
 
double Grafo::obtPrmAdy() const {
 
}
 
Grafo::E Grafo::obtEst(int vrt) const {
 
}
 
int Grafo::obtTmpChqVrs(int vrt) const {
 
}
 
int Grafo::obtCntChqVrs(int vrt) const {
 
}
 
double Grafo::promLongCmnsCrts() const {
 
}
 
double Grafo::coeficienteAgrupamiento(int vrt) const {
 
}
 
double Grafo::coeficienteAgrupamiento() const {
     
}
 
void Grafo::modEst(int vrt, E ne) {
 
}
 
void Grafo::modTmpChqVrs(int vrt, int nt) {
 
}
 
void Grafo::actCntChqVrs(int vrt) {
 
}
 
void Grafo::infectar(int ios) {
 
}
 
void Grafo::azarizarTmpChqVrs(int maxTmp) {
 
}