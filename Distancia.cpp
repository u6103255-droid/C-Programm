// Hugo Heredia Sánchez
// u6103255
// Exercici e1
#include "Distancia.h"

void Distancia::calcularTempsMig(map<string, pair<double,int>> &res, const map<string, pair<double,int>> &aux){
    map<string, pair<double,int>>::const_iterator it=aux.begin();
    while(it!=aux.end()){ //Cost constant amortitzat perquè és un vector petit
        string estudis=it->first;
        double suma=it->second.first;
        int compt=it->second.second;
        res[estudis].first+=suma;
        res[estudis].second+=compt;
        it++;
    }
}

bool Distancia::compara(const pair<int,string>& a, const pair<int,string>& b){
    if (a.first!=b.first) return a.first > b.first;
    else return a.second <= b.second;
}

Distancia::Distancia(){
}

void Distancia::netejarTrajectesNous(){
    trajectesNous.clear();
}

void Distancia::afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis){
    bool trobat=false;
    vector<Transport>::iterator it=transports.begin();
    while(it!=transports.end() and not trobat){
        if(it->obtenirNom()==mitjaPrincipal) trobat=true;
        else it++;
    }
    if(not trobat){ //si no troba el transport al vector transports, crea un nou objecte transports i el guarda al vector.
        Transport t(mitjaPrincipal);
        t.afegir(id, ordre, tipusTrajecte, horaIn, durada, comarcaIn, comarcaFi, edat, estudis);
        this->transports.push_back(t);
    }
    else it->afegir(id, ordre, tipusTrajecte, horaIn, durada, comarcaIn, comarcaFi, edat, estudis); //si existeix el transport al vector transports, només guardarà el respectiu trajecte
    string trajecte=comarcaIn+" - "+comarcaFi;
    trajectesNous.insert(trajecte);
}

int Distancia::nombreTransports() const{
    return transports.size();
}

NumPersonesTransport Distancia::nombrePersonesPerTransport() const{
    NumPersonesTransport res;
    vector<Transport>::const_iterator it=transports.begin();
    while(it!=transports.end()){
        int num=it->obtenirNombrePersones();
        string tipus=it->obtenirNom();
        pair<int,string> p;
        p.first=num;
        p.second=tipus;
        res.push_back(p);
        it++;
    }
    res.sort(compara);
    return res;
}

pair<string,double> Distancia::mesRapid() const{
    pair<string,double> mesrapid;
    mesrapid.first="--";
    mesrapid.second=1.79769e+308; //valor brossa
    vector<Transport>::const_iterator it=transports.begin();
    while(it!=transports.end()){
        double temps=it->obtenirTempsPromig();
        if(temps<mesrapid.second){ //si temps es menor que el temps guardat com a mínim, aquest es convertirà en el mínim (més ràpid)
            mesrapid.second=temps;
            mesrapid.first=it->obtenirNom();
        }
        it++;
    }
    return mesrapid;
}

set<string> Distancia::obtenirTrajectesNous() const{
    return this->trajectesNous;
}

pair<string, double> Distancia::transportMesRapid(string trajecte) const{
    pair<string, double> transportMesRapid{"NO TROBAT",1.79769e+308};
    vector<Transport>::const_iterator it=transports.begin();
    while(it!=transports.end()){
        map<string,pair<int,int>> tempsComarques=it->obtenirTempsComarques();
        double tempsPromig = double(tempsComarques[trajecte].first) / tempsComarques[trajecte].second;
        if(transportMesRapid.second > tempsPromig){
            transportMesRapid.first = it->obtenirNom();
            transportMesRapid.second = tempsPromig;
        }
        it++;
    }
    return transportMesRapid;
}

vector<double> Distancia::tempsHores(string transport, string trajecte) const{
    vector<double> tempsHores(24,{0.0});
    vector<Transport>::const_iterator it=transports.begin();
    bool trobat=false;
    while(it!=transports.end() and not trobat){
        if(it->obtenirNom()==transport) trobat=true;
        else it++;
    }
    if(trobat){
        map<string, vector<pair<int,int>>> thores=it->obtenirTempsPerHora();
        if(thores.count(trajecte)>0){
            for(int i=0;i<24;i++){
                double tempsPromig;
                if(thores[trajecte][i].second>0){
                    tempsPromig=double(thores[trajecte][i].first)/thores[trajecte][i].second;
                }
                else tempsPromig=0.0;
                tempsHores[i]=tempsPromig;
            }
        }
    }
    return tempsHores;
}

pair<string, double> Distancia::transport_mesrapid_perhora(int hora, string trajecte) const{
    pair<string, double> tempsminim{"--", 1.79769e+308};
    vector<Transport>::const_iterator it=transports.begin();
    while(it!=transports.end()){
        if(it->obtenirTempsPerHora(hora, trajecte)<tempsminim.second){
            tempsminim.first=it->obtenirNom();
            tempsminim.second=it->obtenirTempsPerHora(hora, trajecte);
        }
        it++;
    }
    return tempsminim;
}

MesOptim Distancia::transportOptim(string trajecte) const{
    MesOptim res{"--",0,1.79769e+308};
    vector<Transport>::const_iterator it=transports.begin();
    while(it!=transports.end()){
        for(int i=0; i<24; i++){ //Cost constant amortitzat perquè la mida és petita i sempre la mateixa
            if(it->obtenirTempsPerHora(i, trajecte)<res.tempsPromig){
                res.tipusTransport=it->obtenirNom();
                res.hora=i;
                res.tempsPromig=it->obtenirTempsPerHora(i, trajecte);
            }
        }
        it++;
    }
    return res;
}

map<string, pair<double,int>> Distancia::TempsPromigperEstudis() const{
    map<string, pair<double,int>> res;
    vector<Transport>::const_iterator it=transports.begin();
    while(it!=transports.end()){
        map<string, pair<double,int>> aux=it->TempsPromigperEstudis();
        calcularTempsMig(res,aux);
        it++;
    }
    return res;
}

int Distancia::nombreTrajectes(string tipusTrajecte) const{
    int res=0;
    vector<Transport>::const_iterator it=transports.begin();
    while(it!=transports.end()){
        res+=it->nombreTrajectes(tipusTrajecte);
        it++;
    }
    return res;
}
