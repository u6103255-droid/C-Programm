// Hugo Heredia Sánchez
// u6103255
// Exercici e1
#include "Mobilitat.h"

Mobilitat::Mobilitat(){
    distancies=vector<Distancia>(7,Distancia()); //inicialitza el vector distancies a 7 (nombre de distàncies)
    nous_trajectes=vector<set<string>>(7);
    xinoxano=0;
}

void Mobilitat::guardarDades(int id, int ordre, int distancia, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis){
    distancies[distancia].afegir(id,ordre,tipusTrajecte,horaIn,durada,comarcaIn,comarcaFi,mitjaPrincipal,edat,estudis);
    if(trajecteLlarg.second<durada){
        trajecteLlarg.first=comarcaIn+" - "+comarcaFi;
        trajecteLlarg.second=durada;
    }
    if(tipusTrajecte=="Anar a treballar" and mitjaPrincipal=="Peu >5 minuts" and durada>xinoxano) xinoxano=durada;
}

int Mobilitat::obtenirDistancia(int km) const{
    int dist=0;
    if(km*1000>=500 and km*1000<2000) dist=1;
    else if(km*1000>=2000 and km*1000<5000) dist=2;
    else if(km*1000>=5000 and km*1000<10000) dist=3;
    else if(km*1000>=10000 and km*1000<50000) dist=4;
    else if(km*1000>=50000 and km*1000<100000) dist=5;
    else if(km*1000>100000) dist=6;
    return dist;
}

int Mobilitat::llegirDades(const string& path){
    distancies.clear();
    distancies = vector<Distancia>(7, Distancia());
    nous_trajectes.clear();
    nous_trajectes = vector<set<string>>(7);
    trajecteLlarg = make_pair("", 0);
    xinoxano = 0;
    for(int i=0; i<distancies.size(); i++){
        distancies[i].netejarTrajectesNous();
    }

    ifstream f;
    string linia;
    f.open(path);
    int compt=0;
    vector<string> items;
    if(!f.fail()){
        getline(f,linia);
        getline(f,linia);
        while(!f.eof()){
            items=tokens(linia, ',', true);
            int id=stoi(items[0]);
            int ordre=stoi(items[2]);
            string tipusTrajecte=items[3];
            int horaIn=stoi(items[4])%24;
            int durada=stoi(items[6]);
            int distancia=stoi(items[7]);
            string comarcaIn=items[8];
            string comarcaFi=items[9];
            int edat=0; //dona un rang, no es pot representar com un int
            string estudis=items[22];
            string mitjaPrincipal=items[14];
            guardarDades(id,ordre,distancia-1,tipusTrajecte,horaIn,durada,comarcaIn,comarcaFi,mitjaPrincipal,edat,estudis);
            compt++;
            getline(f,linia);
        }
    }
    else cerr<<"No s'ha pogut obrir l'arxiu. Torna a intentar-ho!"<<endl;
    return compt;
}

int Mobilitat::nombreTransports(int distancia) const{
    return distancies[distancia].nombreTransports();
}

NumPersonesTransport Mobilitat::nombrePersonesPerTransport(int distancia) const{
    return distancies[distancia].nombrePersonesPerTransport();
}

MesRapids Mobilitat::mesRapid() const{
    MesRapids res;
    for(int i=0; i<7; i++){
        res.push_back(distancies[i].mesRapid());
    }
    return res;
}

pair<string,double> Mobilitat::trajecteMesLlarg() const{
    return trajecteLlarg;
}

NousTrajectes Mobilitat::trajectesNous(){
    for(int i=0; i<7; i++){ //Cost constant amortitzat
        set<string> nous=distancies[i].obtenirTrajectesNous();
        set<string>::const_iterator it=nous.begin();
        while(it!=nous.end()){ //Més eficient que anar mirant tots els trajectes de totes les persones de tots els transports de cada distància.
            bool trobat=false;
            int j=0;
            while(j<i and not trobat){ //Cost constant amortitzat
            if(nous_trajectes[j].count(*it)>0) trobat=true;
            else j++;
            }
            if(not trobat) nous_trajectes[i].insert(*it);
            it++;
        }

    }
    return nous_trajectes;
}

pair<string, double> Mobilitat::transportMesRapid(int km, string comarcaIn, string comarcaFi) const{
    int dist=obtenirDistancia(km);
    string trajecte=comarcaIn+" - "+comarcaFi;
    pair<string, double> mesRapid=distancies[dist].transportMesRapid(trajecte);
    return mesRapid;
}

vector<double> Mobilitat::tempsHores(int km, string comarcaIn, string comarcaFi, string transport) const{
    int dist=obtenirDistancia(km);
    string trajecte=comarcaIn+" - "+comarcaFi;
    vector<double> tempsHores=distancies[dist].tempsHores(transport,trajecte);
    return tempsHores;
}

pair<string, double> Mobilitat::transportMesRapidHora(int km, int hora, string comarcaIn, string comarcaFi) const{
    int dist=obtenirDistancia(km);
    string trajecte=comarcaIn+" - "+comarcaFi;
    pair<string, double> res=distancies[dist].transport_mesrapid_perhora(hora,trajecte);
    return res;
}

MesOptim Mobilitat::transportOptim(int km, string comarcaIn, string comarcaFi) const{
    int dist=obtenirDistancia(km);
    string trajecte=comarcaIn+" - "+comarcaFi;
    MesOptim res=distancies[dist].transportOptim(trajecte);
    return res;
}

TempsPerNivellEstudis Mobilitat::tempsPerEstudi() const{
    TempsPerNivellEstudis res;
    map<string, pair<double,int>> aux2;
    for(int i=0; i<7; i++){
        map<string, pair<double,int>> aux=distancies[i].TempsPromigperEstudis();
        map<string, pair<double,int>>::const_iterator it=aux.begin();
        while(it!=aux.end()){
            string estudis=it->first;
            double suma=it->second.first;
            int compt=it->second.second;
            aux2[estudis].first+=suma;
            aux2[estudis].second+=compt;
            it++;
        }
    }
    map<string, pair<double,int>>::const_iterator it=aux2.begin();
    while(it!=aux2.end()){
        string estudis=it->first;
        double suma;
        if(it->second.second>0) suma=it->second.first/it->second.second;
        res.insert({estudis,suma});
        it++;
    }
    return res;
}

int Mobilitat::nombreTrajectes(string tipusTrajecte) const{
    int res=0;
    for(int i=0; i<7; i++){
        res+=distancies[i].nombreTrajectes(tipusTrajecte);
    }
    return res;
}

int Mobilitat::xinoXano() const{
    return xinoxano;
}
