#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void lectura_fichero(FILE *f){
	char amigo[50];
	f=fopen("amigos.txt","r");
	if(f==NULL){
		cout<<"ERROR EN APERTURA DE FICHEROS!!!";
	}
	else{
		cout<<"LISTA DE MEJORES AMIGOS"<<endl;
		fgets(amigo,25,f);
		while(!feof(f)){
			cout<<amigo<<endl;
			fgets(amigo,25,f);//saca u obtiene una cadena del fichero
		}
	}fclose(f);//cierre del fichero
}

void escritura_fichero(FILE *f){
	char amigo[50];
	cout<<"Nombre y celular"<<endl;
	fflush(stdin);
	gets(amigo);
	fflush(stdin);
	f=fopen("amigos.txt","a");//apertura del fichero
	if(f==NULL){
		cout<<"ERROR en la apertura del fichero!!!";
	}
	else{
		fputs(amigo,f);//escritura texto en el fichero
		fputc( '\n',f);
	}
	fclose(f);//cierre del fichero
}

void copia_fichero(FILE *origen,FILE *copia){
	char car;
	origen=fopen("amigos.txt","r");
	copia=fopen("copiaamigos.txt","w");
	if(origen==NULL || copia==NULL){
		cout<<"ERROR DE APERTURA";
	}
	else{
		car=fgetc(origen);
		while(car!=EOF){
			fputc(car,copia);
			car=fgetc(origen);
		}
	}
	fclose(origen);
	fclose(copia);
}

void menu()
{	cout<<"******************"<<endl;
	cout<<"*                 BIENVENIDO A EMI PLUSS                       *"<<endl;
	cout<<"*       =============================            *"<<endl;
	cout<<"*  1. LLENAR EL FICHERO                          *"<<endl;
	cout<<"*  2. MOSTRAR EL FICHERO                         *"<<endl;
	cout<<"*  3. COPIA DEL FICHERO                          *"<<endl;
	cout<<"*  4. SALIR DEL PROGRAMA                         *"<<endl;
	cout<<"******************"<<endl;
}

void ejecutaOpcion(int op){
	FILE *archi; //declaracion de un puntero a un fichero
	FILE *	copia;
	switch (op)
	{	case 1: {
		    char resp;
			do{
		    cout<<"GUARDA AMIGO EN EL FICHERO"<<endl;
		    escritura_fichero(archi);
		    cout<<"MAS AMIGOS"<<endl;
	        cin>>resp;
	        }while (resp!='n');
			break;
			}
			case 2: {
				cout<<"LEE AMIGO DEL FICHERO"<<endl;
	            lectura_fichero(archi);
				break;
			}
			case 3: {
				cout<<"COPIA DEL FICHERO"<<endl;
				copia_fichero(archi,copia);
				lectura_fichero(archi);
				lectura_fichero(copia);
				break;
			}
			case 4:	{	cout<<"CERRANDO PROGRAMA, GRACIAS POR USARLO!";
				}
	}
}

int main(){
	int opcion;
	srand(time(NULL));   // para que se puedan ejecutar otros valores aleatorios diferentes
	do
	{	menu();
		cout<<endl<<"Elige una de las opciones : ";
		cin>>opcion;
		ejecutaOpcion(opcion);
	}while (opcion!=4);
	return 0;
}
