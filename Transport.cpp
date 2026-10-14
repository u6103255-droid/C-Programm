// Hugo Heredia Sánchez
// u6103255
// Exercici e1
#include "Transport.h"

Transport::Transport(string nom){
    this->nom = nom;
    tempsTotal = 0;
    nTrajectes = 0;
}

void Transport::afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, int edat, string estudis){
    Persona p(id,edat,estudis);
    Trajecte t(ordre, tipusTrajecte, horaIn, durada, comarcaIn, comarcaFi);
    bool trobat=false;
    vector<Persona>::iterator it=persones.begin();
    while(it!=persones.end() and not trobat){
        if(*it==p) trobat=true; //comprova si el trajecte ja existeix al vector trajectes
        else it++;
    }
    if(not trobat){
        p.afegir(t);
        persones.push_back(p); //només guarda el trajecte si aquest no existeix al vector trajectes
    }
    else it->afegir(t);

    //Guardo el temps i el nombre de trajectes del transport

    this->tempsTotal+=durada;
    this->nTrajectes++;

    //Afegeixo al map tempsComarques

    string trajecte = comarcaIn + " - " + comarcaFi;
    if(tempsComarques.count(trajecte)>0){
        tempsComarques[trajecte].first += durada;
        tempsComarques[trajecte].second++;
    }
    else tempsComarques.insert({trajecte, {durada, 1}});


    //Actualitzo el vector tempsPromigPerHores
    if (tempsPerHora.find(trajecte) == tempsPerHora.end()) {
        tempsPerHora[trajecte] = vector<pair<int,int>>(24, {0,0});
    }
    tempsPerHora[trajecte][horaIn].first += durada;
    tempsPerHora[trajecte][horaIn].second++;
}

string Transport::obtenirNom() const{
    return this->nom;
}

int Transport::obtenirNombrePersones() const{
    return persones.size();
}

double Transport::obtenirTempsPromig() const{
    double res=0.0;
    if(nTrajectes>0) res=(double)tempsTotal/nTrajectes;
    return res; //retorna la mitjana de temps dels trajectes
}

bool Transport::operator==(const Transport& m) const{
    return this->nom==m.nom;
}

map<string,pair<int,int>> Transport::obtenirTempsComarques() const{
    return tempsComarques;
}

map<string, vector<pair<int,int>>> Transport::obtenirTempsPerHora() const{
    return tempsPerHora;
}

double Transport::obtenirTempsPerHora(int hora, string trajecte) const{
    double res=1.79769e+308;
    pair<int, int> mitjana{0,0};
    map<string, vector<pair<int,int>>>::const_iterator it=tempsPerHora.find(trajecte);
    if(it!=tempsPerHora.end()){
        mitjana=it->second[hora];
        if(mitjana.second>0) res=double(mitjana.first)/mitjana.second;
    }
    return res;
}

map<string, pair<double,int>> Transport::TempsPromigperEstudis() const{
    map<string, pair<double,int>> res;
    vector<Persona>::const_iterator it=persones.begin();
    while(it!=persones.end()){
        string estudis=it->obtenirEstudis();
        pair<double, int> aux=it->TempsPromigTrajectes();
        double durada=aux.first;
        int compt=aux.second;
        res[estudis].first+=durada;
        res[estudis].second+=compt;
        it++;
    }
    return res;
}

int Transport::nombreTrajectes(string tipusTrajecte) const{
    vector<Persona>::const_iterator it=persones.begin();
    int res=0;
    while(it!=persones.end()){
        res+=it->nombreTrajectes(tipusTrajecte);
        it++;
    }
    return res;
}
