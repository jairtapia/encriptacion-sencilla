#include<iostream>
#include<string>
#include<fstream>
#define t 10000
#define d 1000

using namespace std;


void encriptar(string key){
	string linea1;
	string texto1;
	ifstream archivo1("pruebas.txt");
	while(getline(archivo1,linea1)){
		texto1+=linea1;
	}
	archivo1.close();
	string cadena = texto1;
	string newcadena;
	int asciiv[t],vmod[t],vky[d];
	for(int i =0;i<cadena.length();i++){
		asciiv[i]=0;
		vky[i]=0;
		vmod[i]=0;
	}
	for(int i = 0;i<key.length();i++){
		vky[i]=key[i];
		if(vky[i]>32&&vky[i]<90){
			vky[i]-=32;
		}
		else if(32<vky[i]&&vky[i]<126){
			vky[i]-=35;
		}	
	}
	for(int i = 0;i<cadena.length();i++){
		asciiv[i]=cadena[i];
		if(asciiv[i]>=32&&asciiv[i]<90){
			asciiv[i]-=32;
		}
		else if(32<asciiv[i]&&asciiv[i]<126){
			asciiv[i]-=35;
		}
	}
    for(int i = 0,j=0;i<cadena.length();i++){
        if(j<key.length()){
            vmod[i]+=(asciiv[i]+vky[j])%88;
            j++;
        }
        else{
            j=0;
            vmod[i]+=(asciiv[i]+vky[j])%88;
            j++;
        }
    }
    for(int i = 0;i<cadena.length();i++){
    
    	newcadena+=vmod[i];
	}
	ofstream archivo2("pruebas.txt");
	archivo2<<newcadena;
	archivo2.close();
}


void desencriptar(string key){
	string linea2;
	string texto2;
	ifstream archivo3("pruebas.txt");
	while(getline(archivo3,linea2)){
		texto2+=linea2;
	}
	archivo3.close();
	string cadena = texto2;
	string newcadena;
	int asciiv[t],vmod[t],vky[d];
	for(int i =0;i<cadena.length();i++){
		asciiv[i]=0;
		vky[i]=0;
		vmod[i]=0;
	}
	for(int i = 0;i<key.length();i++){
		vky[i]=key[i];
		if(vky[i]>32&&vky[i]<90){
			vky[i]-=32;
		}
		else if(32<vky[i]&&vky[i]<126){
			vky[i]-=35;
		}	
	}
	for(int i = 0;i<cadena.length();i++){
		asciiv[i]=cadena[i];
	}
    for(int i = 0,j=0;i<cadena.length();i++){
    	if(asciiv[i]-vky[j]<=0){
    		if(j<key.length()){
            	vmod[i]+=((asciiv[i]-vky[j])+88)%88;
           		j++;
       		}
        else{
           		j=0;
            	vmod[i]+=((asciiv[i]-vky[j])+88)%88;
            	j++;
        	}
		}
		else if(asciiv[i]-vky[j]>0){
			if(j<key.length()){
        		vmod[i]+=(asciiv[i]-vky[j])%88;
           		j++;
       		}
       		else{
            	j=0;
            	vmod[i]+=(asciiv[i]-vky[j])%88;
            	j++;
        	}
		}
		if(vmod[i]<0)
        vmod[i]+=88;
    }
    for(int i = 0;i<cadena.length();i++){
    	if(vmod[i]>0&&vmod[i]<58){
    		vmod[i]+=32;
		}
    	if(vmod[i]>58&&vmod[i]<88){
    		vmod[i]+=35;
		}
    	newcadena+=vmod[i];
	}
	ofstream archivo4("pruebas.txt");
	archivo4<<newcadena;
	archivo4.close();
}


int main(){
	string llave;
	string a;
	string palabra;
	int opc,exit,vky[d];
	system("color 04");
	do{
		cout<<"-------------------menu-------------------------"<<endl;
		cout<<"-------------------1.encriptacion---------------"<<endl;
		cout<<"-------------------2.desencriptacion------------"<<endl;
		cout<<"-------------------3.salir----------------------"<<endl;
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"escribe una palabra secreta pero no debes olvidarla"<<endl;
				cin>>llave;
				encriptar(llave);
				system("cls");
				system("pause");
				break;
			case 2:
				system("color 02");
				cout<<"escribe la llave te dije que no olvide la palabra secreta"<<endl;
				cin>>llave;
				desencriptar(llave);
				system("cls");
				system("pause");
				break;
			case 3:
				system("color 05");
				cout<<"saliendo del programa"<<endl;
				system("pause");
				break;
			default:
				cout<<"opcion disponible proximamente"<<endl;
				system("pause");
		}
	}while(opc!=3);
	return 0;	
}
