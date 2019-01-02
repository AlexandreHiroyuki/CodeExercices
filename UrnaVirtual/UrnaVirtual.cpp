/*************************************/
/* Urna Virtual                      */
/* Created by Alexandre Hiroyuki     */
/*************************************/
#include<iostream>
#include<fstream>
#include<map>
using namespace std;

struct cdt {
    string name;
    int votes = 0;
};

map<int,cdt> cdtList;

void help() {
    cout << "Todos os comandos:" << endl << endl;
    cout << "'ajuda' - Mostra todos os comandos." << endl;
    cout << "'votar %NUM%' - Inicia a votacao - %NUM% = Numero total de votacoes" << endl;
    cout << endl;
}

void voting(int loops){
    for(int i=0; i<loops; i++){
        int cNum;
        cout << endl << "Lembre-se, que se digitar um candidato inexistente o voto sera nulo!";
        cout << endl << "Digite o numero do candidato: ";
        cin >> cNum;

        cdtList[cNum].votes++;
    }

    ofstream out("votos.txt", ios::app);
    int null = 0;
    for(map<int,cdt>::iterator it=cdtList.begin(); it!=cdtList.end(); it++){
        if(it->second.name.size()>0){
            out << it->first << " " << it->second.name << " " << it->second.votes << endl;
        }
        else null++;
    }
    out << "Nulo " << null;
}

bool menu(){
    string in;
    int iin = 0;
    cin >> in;

    if(in == "ajuda"){help(); return true;}
    else if(in == "votar"){cin>>iin; voting(iin); return true;}
    else if(in == "sair"){return false;}
    else{cout<<"Comando invalido"<<endl; return true;}
}

int main() {
    ifstream in("candidatos.txt",ios::in);
    while(!in.eof()){
        string sin;
        int iin;
        in >> iin >> sin;
        cdtList[iin].name = sin;
    }

    bool flag = true;
    while(flag){
        flag = menu();
        cout << endl;
    }

    return 0;
}

