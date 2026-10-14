// Hugo Heredia Sánchez
// u6103255
// Exercici e1
#include "Trajecte.h"

Trajecte::Trajecte(){
    this->comarcaFi=" ";
    this->comarcaIn=" ";
    this->durada=0;
    this->horaIn=0;
    this->ordre=0;
    this->tipusTrajecte=" ";
}

Trajecte::Trajecte(int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi){
    this->comarcaFi=comarcaFi;
    this->comarcaIn=comarcaIn;
    this->durada=durada;
    this->horaIn=horaIn;
    this->ordre=ordre;
    this->tipusTrajecte=tipusTrajecte;
}

string Trajecte::obtenirTrajecte() const{
    return this->comarcaIn+" - "+this->comarcaFi;
}

int Trajecte::obtenirDurada() const{
    return this->durada;
}

string Trajecte::obtenirtipusTrajecte() const{
    return tipusTrajecte;
}
