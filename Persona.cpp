// Hugo Heredia Sánchez
// u6103255
// Exercici e1
#include "Persona.h"
#include <iostream>

Persona::Persona(int id, int edat, string estudis){
    this->id=id;
    this->edat=edat;
    this->estudis=estudis;
}

void Persona::afegir(const Trajecte&t){
    trajectes.push_back(t);
}

bool Persona::operator==(const Persona& p) const{
    return (this->id==p.id)and(this->edat==p.edat)and(this->estudis==p.estudis);
}

pair<double, int> Persona::TempsPromigTrajectes() const{
    pair<double,int> res{0.0,0};
    vector<Trajecte>::const_iterator it=trajectes.begin();
    while(it!=trajectes.end()){
        res.first+=it->obtenirDurada();
        it++;
    }
    res.second=trajectes.size();
    return res;
}

string Persona::obtenirEstudis() const{
    return this->estudis;
}

int Persona::nombreTrajectes(string tipusTrajecte) const{
    vector<Trajecte>::const_iterator it=trajectes.begin();
    int res=0;
    while(it!=trajectes.end()){
        if(tipusTrajecte==it->obtenirtipusTrajecte()) res++;
        it++;
    }
    return res;
}
