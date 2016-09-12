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
 
LstAdy::LstAdy():inicio(nullptr){
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
    cout << "Borrando lista" << endl;
}
 
void LstAdy::agr(int nady) {
    bool result = false;
    shared_ptr<NdoLstAdy> p = inicio;
    shared_ptr<NdoLstAdy> ant = nullptr;
    if (inicio == nullptr){
        inicio = shared_ptr<NdoLstAdy> (new NdoLstAdy(nady));
        result = true;
    } else {
        if (inicio->vrtD < nady){
            p = shared_ptr<NdoLstAdy> (new NdoLstAdy(nady));
            p->sgt = inicio;
            inicio = p;
            result = true;
        } else {
            p = inicio;
            while (p != nullptr){
                if(p->vrtD == nady){
                    p = nullptr;
                } else {
                    if(p->vrtD > nady){
                        ant = p;
                        p = p->sgt;
                        if(p == nullptr){
                            p = shared_ptr<NdoLstAdy> (new NdoLstAdy(nady));
                            ant->sgt = p;
                            p = p->sgt;
                        }
                    } else{
                        p = nullptr;
                    }
                }
            }
            if (result){
                p = ant->sgt;
                ant->sgt = shared_ptr<NdoLstAdy> (new NdoLstAdy(nady));
                ant->sgt->sgt = p;
            }
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
