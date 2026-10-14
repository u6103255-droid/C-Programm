// Hugo Heredia Sánchez
// u6103255
// Exercici e1

/**
 @mainpage Pràctica 1
 @author Hugo Heredia Sánchez
 @version 1.0
 @date 04/11/2025
 @brief L'Observatori de la Mobilitat de Catalunya (OMC) és un instrument per a
 l'avaluació de les eines de planificació de la mobilitat i per a l'anàlisi dels efectes
 que aquests poden produir quan s'apliquen. L'OMC està inscrit en l'àmbit d'actuació del departament competent en
 matèria de transports i mobilitat i es configura com un instrument de recollida
 i difusió de la informació més rellevant en matèria de mobilitat i del seu grau
 de sostenibilitat. L'Autoritat del Transport Metropolità (ATM) de l¡àrea de
 Barcelona en gestiona el portal web.
 L'OMC realitza diferents enquestes i ofereix el detall dels resultats al seu portal, en format CSV. Aquest fitxer
 conté dades anònimes de cadascuna de les enquestes realitzades, amb informació dels desplaçments que realitza la
 població, incloent comarca d'origen i destí, hora del dia, durada, distància, transports utilitzats, sexe, edat, estudis, entre d'altres.

 S'han documentat les classes utilitzades (explicant per què es fan servir i
 descrivint breument els seus atributs), i s'han posat les pre- i
 postcondicions de les accions i funcions del \c main.cpp i d'alguns mètodes
 de les diferents classes implementades.
 */

#include <iostream>
#include "Mobilitat.h"

using namespace std;

string menu();
/**<
 @brief Es mostra per pantalla el menu amb les diferents opcions a triar i demana a l'usuari l'opció que vol triar.
 @return string
 @pre cert
 @post
 -# Mostra per pantalla el menu amb les diferents opcions a triar
 -# Demana a l'usuari l'opció que vol triar
*/

void llegir_dades(Mobilitat&m);
/**<
 @brief Llegeix les dades del fitxer de les enquestes i omple l'objecte Mobilitat
@return void
@param m és un objecte de tipus Mobilitat
@pre cert
@post
-# Llegeix el fitxer de les enquestes passat per l'usuari i omple l'objecte m amb les dades subministrades
-# Mostra per pantalla el nombre de línies llegides.
*/

void mostrarDistancies(int i);
/**<
 @brief Mostra per pantalla la capçalera corresponent a la distància donada per paràmetre
@return void
@param i és un nombre enter positiu corresponent a una de les distàncies
@pre
-# 0<=i<=6
@post
-# Mostra per pantalla les diferents capçaleres segons la distància que s'ha passat per paràmetre
*/

void nombreTransports(const Mobilitat&m);
/**<
 @brief Mostra per pantalla el nombre de transports que hi ha disponibles per la distància entrada per l'usuari.
@return void
@param m és un objecte de tipus Mobilitat
@pre cert
@post
-# Mostra per pantalla el nombre de transports que hi ha disponibles per la distància entrada per l'usuari
-# Mostra un missatge d'error si la distància no compleix és menor que 1 o major que 7
*/

void nombrePersonesperTransport(const Mobilitat&m);
/**<
 @brief mostra per pantalla el nombre de persones que té cada transport i el seu respectiu nom, segons la distància entrada per l'usuari.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla el nombre de persones que té cada transport i el seu respectiu nom, segons la distància entrada per l'usuari.
 -# Si aquesta és incorrecta, surt un missatge d'error.
*/

void mostrar_distancies_formatcurt(int i);
/**<
 @brief Mostra per pantalla les diferents capçaleres segons la distància que ens han entrat.
 @return void
 @param i és un integer que representa la distància
 @pre
 -# 0<=i<=6
 @post
 -# Mostra per pantalla les diferents capçaleres segons la distància que ens han entrat
*/

void mesRapid(const Mobilitat&m);
/**<
 @brief Mostra per pantalla el transport més ràpid segons cada distància i el seu respectiu temps mitjà.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla el transport més ràpid segons cada distància i el seu respectiu temps mitjà.
*/

void trajecteMesLlarg(const Mobilitat&m);
/**<
 @brief Mostra per pantalla el trajecte de més durada de tots els que hi ha disponibles.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla el trajecte de més durada de tots els que hi ha disponibles.
*/

void nous_trajectes(Mobilitat&m);
/**<
 @brief Mostra per pantalla tots els trajectes nous de la distància x (1-7) que no es trobin a les distàncies inferiors [1...x-1]
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla tots els trajectes nous de la distància x (1-7) que no es trobin a les distàncies inferiors [1...x-1]
*/

void transportMesRapid(const Mobilitat&m);
/**<
 @brief Mostra per pantalla la comarca d'inici i final del transport més ràpid i el temps mitjà que triga en fer el trajecte de km entrat per l'usuari.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla la comarca d'inici i final del transport més ràpid i el temps mitjà que triga en fer el trajecte de km entrat per l'usuari.
 -# Si no n'hi ha, mostra NO TROBAT i com a temps 1.79769e+308.
*/

void tempsPerHores(const Mobilitat&m);
/**<
 @brief
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla el temps que triga en fer-se una distància de km entre la comarca d'inici i final entrada per l'usuari per hores segons el transport més ràpid.
 -# Si no n'hi ha cap, retorna "--" i 0 com a temps promig.
*/

void transportmesrapidperhora(const Mobilitat&m);
/**<
 @brief Mostra per pantalla l'hora en que es fa el trajecte més ràpid entre dues comarques entrades per l'usuari i el temps promig que triga en fer-ho.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla l'hora en que es fa el trajecte més ràpid entre dues comarques entrades per l'usuari i el temps promig que triga en fer-ho.
 -# Si no es troba, mostra "--" i 1.79769e+308 com a temps promig.
*/

void transportOptim(const Mobilitat&m);
/**<
 @brief Mostra el temps més òptim per fer un trajecte de km entrat per l'usuari entre dues comarques i el seu temps promig.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra el temps més òptim per fer un trajecte de km entrat per l'usuari entre dues comarques i el seu temps promig.
 -# Si no n'hi ha cap, retorna "--" com a transport, 0 com a hora i 1.79769e+308 com a temps promig.
*/

void tempsPerEstudi(const Mobilitat&m);
/**<
 @brief Mostra per pantalla el temps promig dels trajectes que fa les persones segons un nivell d'estudi.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla el temps promig dels trajectes que fa les persones segons un nivell d'estudi.
 -# Si no n'hi ha cap, només mostra la capçalera de l'opció.
*/

void nombreTrajectes(const Mobilitat&m);
/**<
 @brief Mostra per pantalla el tipus de trajecte que s'ha comprovat i el nombre de trajectes que s'han fet segons aquest.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla el tipus de trajecte que s'ha comprovat i el nombre de trajectes que s'han fet segons aquest.
 -# Si no s'ha fet cap, retorna 0.
*/

void xinoXano(const Mobilitat&m);
/**<
 @brief Mostra per pantalla els minuts que triga la persona que més camina per anar a treballar.
 @return void
 @param m és un objecte de tipus Mobilitat
 @pre cert
 @post
 -# Mostra per pantalla els minuts que triga la persona que més camina per anar a treballar.
 -#Si no n'hi ha cap, retorna 0.
*/

string menu(){

    cerr<<"Menu:"<<endl;
    cerr<<"0:  Acabar."<<endl;
    cerr<<"01: Llegir dades"<<endl;
    cerr<<"02: Nombre transports"<<endl;
    cerr<<"03: Nombre persones per transport"<<endl;
    cerr<<"04: Mes rapid"<<endl;
    cerr<<"05: Trajecte mes llarg"<<endl;
    cerr<<"06: Nous trajectes"<<endl;
    cerr<<"07: Transport mes rapid"<<endl;
    cerr<<"08: Temps per hores"<<endl;
    cerr<<"09: Transport mes rapid per hora"<<endl;
    cerr<<"10: Transport optim"<<endl;
    cerr<<"11: Temps per estudis"<<endl;
    cerr<<"12: Nombre de trajectes"<<endl;
    cerr<<"13: XinoXano"<<endl;
    cerr<<"Opcio: ";
    string opcio;
    cin>>opcio;
    return opcio;
}

void llegir_dades(Mobilitat&m){

    cout<<"********************"<<endl;
    cout<<"* 01: Llegir dades *"<<endl;
    string path;
    cerr<<"Escriu el path: ";
    cin>>path;
    int i=m.llegirDades(path);
    cout<<"********************"<<endl;
    cout<<"Numero de linies: "<<i<<endl;
}

void mostrarDistancies(int i){

        if(i==1){
            cout<<"Distància Menys de 500 metres";
        }
        else if(i==2){
            cout<<"Distància De 500 a 2.000 metres";
        }
        else if(i==3){
            cout<<"Distància De 2.000 a 5.000 metres";
        }
        else if(i==4){
            cout<<"Distància De 5.000 a 10.000 metres";
        }
        else if(i==5){
            cout<<"Distància De 10.000 a 50.000 metres";
        }
        else if(i==6){
            cout<<"Distància De 50.000 a 100.000 metres";
        }
        else if(i==7){
            cout<<"Distància Més de 100.000 metres";
        }
}

void nombreTransports(const Mobilitat&m){

    cout<<"*************************"<<endl;
    cout<<"* 02: Nombre transports *"<<endl;
    cout<<"*************************"<<endl;
    cerr<<"Escriu la distància: ";
    int dist;
    cin>>dist;
    if(dist>=1 and dist<=7){
        int n=m.nombreTransports(dist-1);
        mostrarDistancies(dist);
        cout<<" ==> "<<n<<endl;
    }
    else cerr<<"Has d'introduir un valor que vagi de l'1 al 7, ambdós inclosos!"<<endl;
}

void nombrePersonesperTransport(const Mobilitat&m){

    cout<<"*************************************"<<endl;
    cout<<"* 03: Nombre persones per transport *"<<endl;
    cout<<"*************************************"<<endl;
    cerr<<"Escriu la distància: ";
    int dist;
    cin>>dist;
    if(dist>=1 and dist<=7){
        NumPersonesTransport llista=m.nombrePersonesPerTransport(dist-1);
        mostrarDistancies(dist);
        cout<<endl;
        int pos=0;
        list<pair<int,string>>::iterator it=llista.begin();
        while(it!=llista.end()){
            cout<<pos<<" : "<<it->second<<" => "<<it->first<<endl;
            pos++;
            it++;
        }
    }
    else cerr<<"Has d'introduir un valor que vagi de l'1 al 7, ambdós inclosos!"<<endl;
}

void mostrar_distancies_formatcurt(int i){

    if(i==1){
        cout<<"Menys de 500 metres";
    }
    else if(i==2){
        cout<<"De 500 a 2.000 metres";
    }
    else if(i==3){
        cout<<"De 2.000 a 5.000 metres";
    }
    else if(i==4){
        cout<<"De 5.000 a 10.000 metres";
    }
    else if(i==5){
        cout<<"De 10.000 a 50.000 metres";
    }
    else if(i==6){
        cout<<"De 50.000 a 100.000 metres";
    }
    else if(i==7){
        cout<<"Més de 100.000 metres";
    }
}

void mesRapid(const Mobilitat&m){

    MesRapids v=m.mesRapid();
    cout<<"*******************"<<endl;
    cout<<"* 04: Més ràpid *"<<endl;
    cout<<"*******************"<<endl;
    for(int i=0; i<7; i++){
        mostrar_distancies_formatcurt(i+1);
        cout<<" : "<<v[i].first<<" => "<<v[i].second<<endl;
    }
}

void trajecteMesLlarg(const Mobilitat&m){

    pair<string, double> TrajectemesLlarg=m.trajecteMesLlarg();
    cout<<"***************************"<<endl;
    cout<<"* 05: Trajecte més llarg *"<<endl;
    cout<<"***************************"<<endl;
    cout<<"Trajecte més llarg : "<<TrajectemesLlarg.first<<" => "<<TrajectemesLlarg.second<<" minuts"<<endl;
}

void nous_trajectes(Mobilitat&m){

    cout<<"**********************"<<endl;
    cout<<"* 06: Trajectes nous *"<<endl;
    cout<<"**********************"<<endl;
    NousTrajectes res=m.trajectesNous();
    static const string dist[7] = {
        "Menys de 500 metres",
        "De 500 a 2.000 metres",
        "De 2.000 a 5.000 metres",
        "De 5.000 a 10.000 metres",
        "De 10.000 a 50.000 metres",
        "De 50.000 a 100.000 metres",
        "Més de 100.000 metres"
    };
    for(int i=0; i<7; i++){
        cout<<dist[i]<<endl;
        set<string>::const_iterator it=res[i].begin();
        while(it!=res[i].end()){
            cout<<"     "<<*it<<endl;
            it++;
        }
    }
}

void transportMesRapid(const Mobilitat&m){

    cout<<"*****************************"<<endl;
    cout<<"* 07: Transport més ràpid *"<<endl;
    cout<<"*****************************"<<endl;
    cerr<<"Kilometres: ";
    int km;
    cin>>km;
    cerr<<"Comarca Inici: ";
    string comarcaIn;
    cin.ignore();
    getline(cin,comarcaIn);
    cerr<<"Comarca Final: ";
    string comarcaFi;
    getline(cin,comarcaFi);
    pair<string, double> mesrapid=m.transportMesRapid(km,comarcaIn,comarcaFi);
    cout<<"Trasport més ràpid entre "<<comarcaIn<<" i "<<comarcaFi<<" => "<<mesrapid.first<<" : "<<mesrapid.second<<" minuts"<<endl;
}

void tempsPerHores(const Mobilitat&m){

    cout<<"*******************"<<endl;
    cout<<"* 08: Temps hores *"<<endl;
    cout<<"*******************"<<endl;
    cerr<<"Kilometres: ";
    int km;
    cin>>km;
    cerr<<"Comarca Inici: ";
    string comarcaIn;
    cin.ignore();
    getline(cin,comarcaIn);
    cerr<<"Comarca Final: ";
    string comarcaFi;
    getline(cin,comarcaFi);
    cerr<<"Transport: ";
    string transport;
    getline(cin,transport);
    vector<double> tempsHores=m.tempsHores(km,comarcaIn,comarcaFi,transport);
    cout<<"km:"<<km<<" "<<comarcaIn<<" - "<<comarcaFi<<" -- "<<transport<<endl;
    for(int i=0; i<24; i++){
        cout<<i<<" : ";
        if(tempsHores[i]==0) cout<<"--"<<endl;
        else cout<<tempsHores[i]<<" minuts"<<endl;
    }
}

void transportmesrapidperhora(const Mobilitat&m){

    cout<<"**********************************"<<endl;
    cout<<"* 09: Transport més ràpid hora *"<<endl;
    cout<<"**********************************"<<endl;
    cerr<<"Kilometres: ";
    int km;
    cin>>km;
    cerr<<"Hora: ";
    int hora;
    cin>>hora;
    cerr<<"Comarca Inici: ";
    string comarcaIn;
    cin.ignore();
    getline(cin,comarcaIn);
    cerr<<"Comarca Final: ";
    string comarcaFi;
    getline(cin,comarcaFi);
    pair<string, double> res=m.transportMesRapidHora(km, hora, comarcaIn, comarcaFi);
    cout<<"Hora més ràpida "<<km<<"km  hora:"<<hora<<" Trajecte: "<<comarcaIn<<" - "<<comarcaFi<<" ==> "<<res.first<<" : "<<res.second<<" minuts"<<endl;
}

void transportOptim(const Mobilitat&m){

    cout<<"************************"<<endl;
    cout<<"* 10: Transport òptim *"<<endl;
    cout<<"************************"<<endl;
    cerr<<"Kilometres: ";
    int km;
    cin>>km;
    cin.ignore();
    cerr<<"Comarca Inici: ";
    string comarcaIn;
    getline(cin,comarcaIn);
    cerr<<"Comarca Final: ";
    string comarcaFi;
    getline(cin,comarcaFi);
    MesOptim res=m.transportOptim(km,comarcaIn,comarcaFi);
    cout<<"Transport òptim: "<<km<<"km  Trajecte: "<<comarcaIn<<" - "<<comarcaFi<<" ==> "<<res.tipusTransport<<"  hora:"<<res.hora<<"  temps:"<<res.tempsPromig<<" minuts"<<endl;
}

void tempsPerEstudi(const Mobilitat&m){

    cout<<"************************"<<endl;
    cout<<"* 11: Temps per estudi *"<<endl;
    cout<<"************************"<<endl;
    TempsPerNivellEstudis res=m.tempsPerEstudi();
    map<string,double>::const_iterator it=res.begin();
    while(it!=res.end()){
        cout<<it->first<<" : "<<it->second<<endl;
        it++;
    }
}

void nombreTrajectes(const Mobilitat&m){

    cerr<<"Tipus de trajecte: ";
    string tipusTrajecte;
    cin>>tipusTrajecte;
    int res=m.nombreTrajectes(tipusTrajecte);
    cout<<"************************"<<endl;
    cout<<"* 12: Nombre trajectes *"<<endl;
    cout<<"************************"<<endl;
    cout<<"Trajecte tipus "<<tipusTrajecte<<" : "<<res<<endl;
}

void xinoXano(const Mobilitat&m){

    cout<<"*****************"<<endl;
    cout<<"* 13: XinoXano *"<<endl;
    cout<<"*****************"<<endl;
    cout<<"Persona que més camina per anar a treballar: "<<m.xinoXano()<<" minuts"<<endl;
}

int main(){
    Mobilitat m;
    string opcio=menu();
    while(opcio!="0"){
        if(opcio=="01") llegir_dades(m);
        else if(opcio=="02") nombreTransports(m);
        else if(opcio=="03") nombrePersonesperTransport(m);
        else if(opcio=="04") mesRapid(m);
        else if(opcio=="05") trajecteMesLlarg(m);
        else if(opcio=="06") nous_trajectes(m);
        else if(opcio=="07") transportMesRapid(m);
        else if(opcio=="08") tempsPerHores(m);
        else if(opcio=="09") transportmesrapidperhora(m);
        else if(opcio=="10") transportOptim(m);
        else if(opcio=="11") tempsPerEstudi(m);
        else if(opcio=="12") nombreTrajectes(m);
        else if(opcio=="13") xinoXano(m);
        else cerr<<"Introdueix una opció entre l'1 i el 13, ambdós inclosos"<<endl;
        opcio=menu();
    }
    return 0;
}
