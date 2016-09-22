/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LstAdy.cpp
 * Author: Carlos
 * 
 * Created on 6 de septiembre de 2016, 11:05 PM
 */

#include "LstAdy.h"

LstAdy::LstAdy():cntAdy(0), inicio(nullptr){
}

LstAdy::LstAdy(const LstAdy& orig){
    shared_ptr<NdoLstAdy> p = orig.inicio;
    if (p == nullptr){
        inicio = nullptr;
    } else {
        inicio = shared_ptr<NdoLstAdy> ( new NdoLstAdy (orig.inicio->vrtD));
        p = p->sgt;;
        shared_ptr<NdoLstAdy> ultimo = inicio;
        while (p != nullptr){
            ultimo->sgt = shared_ptr<NdoLstAdy> (new NdoLstAdy(p->vrtD));
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
}

LstAdy::~LstAdy() {
    delete[] arrp; //se borra el vector que contiene las adyacencias en *this
    cout << "Borrando lista" << endl;
}

void LstAdy::agr(int nady) {
    bool rsl = false;
    shared_ptr<NdoLstAdy> p = inicio;
    shared_ptr<NdoLstAdy> ant = nullptr;
    if(inicio == nullptr){ //se agrega el primer elemento a *this
        inicio = shared_ptr<NdoLstAdy>(new NdoLstAdy(nady));
        rsl = true;
    }else if (inicio -> vrtD < nady){ // insercion antes del inicio
        p = shared_ptr<NdoLstAdy>(new NdoLstAdy(nady)); // se crea el nuevo nodo
        p -> sgt = inicio; // se liga con el anterior inicio
        inicio = p; // se cambia inicio
        rsl = true;
    } else {
        p = inicio;
        while (p != nullptr) {
            if (p -> vrtD == nady) { // ya se encontro x en *this.
                p = nullptr;
            } else { // todavia no se encuentra pero puede estar mas adelante.
                if (p -> vrtD > nady){
                    ant = p;
                    p = p -> sgt;
                    if (p == nullptr)
                        rsl = true;
                }else{ // se concluye que x no esta en *this
                    p = nullptr;
                    rsl = true; // hay que agregarlo
                }
            }
        }
        if (rsl) { // sirve para agregar en medio y al final
            p = ant -> sgt; // p podria ser null o cer
            ant -> sgt = shared_ptr<NdoLstAdy>(new NdoLstAdy(nady));
            ant -> sgt -> sgt = p;
        }
    }
}

bool LstAdy::bus(int ady) {
    bool rsl = false;//rsl = resultado.
    shared_ptr<NdoLstAdy> p = inicio;
    while(p != nullptr){
        if(p -> vrtD == ady){ // ya se encontro x en *this.
            rsl = true;
            p = nullptr;
        } else{ // todavia no se encuentra pero puede estar mas adelante.
            if(p -> vrtD > ady)
                p = p -> sgt;
            else // se concluye que x no esta en *this
                p = nullptr;
        }
    }
    return rsl;
}

void LstAdy::elm(int ady)
{
    bool rsl = false;
    shared_ptr<NdoLstAdy> p = inicio;
    shared_ptr<NdoLstAdy> ant = nullptr;
    if(inicio != nullptr && inicio -> vrtD >= ady)
        if(inicio -> vrtD == ady){
            p = inicio -> sgt;
            inicio = p;
        } else {
            while(p != nullptr){ // hay que buscar a x
                if(p -> vrtD == ady){
                    rsl = true;
                    p = nullptr;
                } else { // hay que seguir buscando
                    if(p -> vrtD > ady){
                        ant = p;
                        p = p -> sgt;
                    } else p = nullptr; // no esta y no hay nada que eliminar
                }
            }
            if(rsl){ // si hay que eliminar en medio o al final
                p = ant -> sgt -> sgt;
                ant -> sgt = p;
            }
        }
}

string LstAdy::aHil() {
    stringstream fs; // construye una instancia de flujo de salida.
    shared_ptr<NdoLstAdy> p = inicio;
    fs << '{';
		while(p != nullptr){ 
			fs << p -> vrtD;
			p = p -> sgt;
			if(p != nullptr)
				fs << ',';
		}
    fs << '}';
    return fs.str();
}

int LstAdy::totAdy()
{
	shared_ptr<NdoLstAdy> p = inicio; //Se crea una copia de inicio
	cntAdy = 1; //Se inicializa el contador de adyacencias en 1
	if(p == nullptr)
		cntAdy = 0; //Si la lista esta vacia entonces el contador es igual a 0
	else{
		while(p != nullptr){ //Mientras se lean los elementos de la lista
			p = p->sgt; //Acceder a los elementos de la lista
			if(p != nullptr) //Acceder al contador solo si el nodo existe
				cntAdy = cntAdy + 1; //Se aumenta en uno el contador de adyacencias cuando se encuentra un nodo no nulo
		}
	}
	return cntAdy;
}

int* LstAdy::obtAdy(){
    int totAdy = LstAdy::totAdy(); //Se usa el metodo obtener adyacencias para tener el total de adyacencias
    arrp = new int[totAdy]; //Se inicializa el arreglo de tamaño equivalente a la cantidad de adyacencias
    int pos = 0; //Se inicializa el contador de posiciones en 0
    shared_ptr<NdoLstAdy> p = inicio; //Se crea un puntero inteligente igual a inicio
    while(p != nullptr){ //Mientras no termine la lista
        arrp[pos] = p->vrtD; //Se asigna el dato del nodo siguiente al nodo apuntado a la posicion pos del arreglo
        pos = pos + 1; //Se aumenta en uno la posicion
        p = p->sgt; //Se asigna el nodo siguiente a p
    }
    return arrp;
}