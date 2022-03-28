#include <iostream>
#include <conio.h>
#include  <stdlib.h>

using namespace std;  

//creacion de nodo
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
//Prototipos
 Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void menu();
void mostrarArbol(Nodo *,int);
	
Nodo *arbol =NULL;


int main(){
	
	menu();
	
}

//Funcion de menu
void menu(){
	int dato, opcion, contador=0;
	
	do{
		printf("\n Menu:\n");
		printf("\n 1.- Insertar un nuevo nodo");
		printf("\n 2.-Mostrar arbol completo");
		printf("\n 3.-Salir");
		
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				printf("Digite un numero:");
					scanf("%d",&dato);
					insertarNodo(arbol,dato); //Insertamos un nuevo nodo
					printf("\n");
					system("pause");
					break;
			case 2:
			printf("\nMostrar el arbol completo: \n\n");
			mostrarArbol(arbol,contador);
			printf("\n \n");
			system("pause");
			break;
					
		}
		system("cls");
	}while(opcion != 3);
}

//Funcion para crear un nuevo nodo

 Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
		
	nuevo_nodo->dato =n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;	
		
		return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n){
	if(arbol==NULL){ //Si el arbol esta vacio
		struct Nodo *nuevo_nodo = crearNodo(n);
		arbol=nuevo_nodo;
	}
	else{//Si el arbol tiene uno o mas de un nodo
	int valorRaiz = arbol ->dato; //Obtener valor de la raiz
	if(n<valorRaiz){ //Si el elemento es menor a la raiz, insertamos en la izq
		insertarNodo(arbol->izq,n);
	}
	else{ //sI EL ELEMENTO ES MAYOR A LA RAIZ
	insertarNodo(arbol->der,n);
	}
	
	}
}

//Funcion para mostrar arbolcompleto

void mostrarArbol(Nodo *arbol,int contador){
	if(arbol==NULL){
		return;
		
	}
	else{
		mostrarArbol(arbol ->der,contador+1);
		for(int i=0;i<contador;i++){
			printf("   ");
		}
		printf("%d-----\n",arbol->dato);
		mostrarArbol(arbol->izq,contador+1);
	}
}
