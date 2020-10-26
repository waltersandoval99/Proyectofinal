#include <iostream>
#include <fstream>
#include <windows.h>


using namespace std;

int menu(){
	int x;
	system("cls");
	cout<<"========BIENBENIDO======="<<endl<<endl;
	cout<<"1. Agregar Palbra"<<endl;
	cout<<"2. Ver Palbras"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Opcion";
	cin>>x;
	return x;
}

bool verifica (string Ingles){
	ifstream leer("registro.txt", ios::in);
	string Ingles;
	string Esp;
	string des;
	leer>>Ingles;
	while(!leer.eof()){
		leer>>Ingles;
		leer>>Esp;
		if(Ingles == Ingles){
			leer.close();
			return false;
		}
		leer>>Ingles;
	}
	leer.close();
	return 	true;
}
void agregar(ofstream &es) {
	system("cls");
	string Ingles;
	string Esp;
	string des;
	es.open("registro.txt", ios::out| ios::app);
	cout<<"Ingles:  ";
	cin>>Ingles;
	cout<<"Español:  ";
	cin>>Esp;
	cout<<"Descripcion:  ";
	cin>>des;
	if(verifica(Ingles))
		es<<Ingles<<" "<<Esp<<" "<<des<<"\n";
	es.close();
	}


int main(){
	ofstream Esc;
	int op;
	do{
		
		system("cls");
		op = menu();
		switch(op){
			case 1:
				agregar(Esc);
			break;
		}	
	}while(op != 3);
	return 0;
}
