#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 20

//Declaracion de los tipos de datos personalizados

typedef char tString[MAX];

tString tCodigo[2]={"Corrientes","Chaco"};

typedef struct {
	tString nombre;
	tString numero;
	tString dni;
	int procedencia;
}tElem;

typedef struct nodo{
	tElem elem;
	struct nodo* siguiente;
}tNodo;

typedef struct{
	tNodo* principio;
	tNodo* final;
}tCola;

//Declaracion de las variables goblales
tElem dato;
tCola cola;

//Declaracion del prototipo
void inicializar();
bool colaVacia(tCola);
void agregar(tElem);
void quitar();
void visualizar(tCola);
void ingresarDatos();
void llamadasEnEspera();
void llamadasEnLugares();
tNodo *primerElemento(tCola);//Funcion Extra
void visualizarPrimerElemento();//Funcion Extra
void menu();

//Funcion principal
int main(){
	inicializar();
	menu();
	
	return 0;
}

//Implementacion de funciones
void inicializar(){
	cola.final=NULL;
	cola.principio=NULL;
}

bool colaVacia(tCola pCola){
	return pCola.final==NULL&&pCola.principio==NULL;
}

void agregar(tElem pElem){
	tNodo* nuevoNodo;
	
	nuevoNodo=(tNodo*)malloc(sizeof(tNodo));
	
	nuevoNodo->elem=pElem;
	
	nuevoNodo->siguiente=NULL;
	
	if(colaVacia(cola)){
		cola.principio=nuevoNodo;
		cola.final=nuevoNodo;
	} else{
		cola.final->siguiente=nuevoNodo;
		cola.final=nuevoNodo;
	}
	
	printf("\nLlamada ingresada - NUMERO [%s] ",pElem.numero);
}

void quitar(){
	if(colaVacia(cola)){
		printf("\nNo hay llamadas por atender");
	} else{
		tNodo* nodoSuprimir=cola.principio;
		
		if(cola.final==cola.principio){
			inicializar();
		} else{
			cola.principio=nodoSuprimir->siguiente;
		}
		
		printf("\nLlamada atendida - Numero [%s]",nodoSuprimir->elem.numero);
		
		free(nodoSuprimir);
		
		nodoSuprimir=NULL;
	}
}

void visualizar(tCola pCola){
	if(colaVacia(pCola)){
		printf("\nNo hay usuarios ingresados");
	} else{
		tNodo* aux=cola.principio;
		int i;
		
		printf("\n\t***LISTA DE USUARIOS***");
		printf("\n----------------------------------");
		while(aux!=NULL){
			i++;
			printf("\n\tUSUARIO %d",i);
			printf("\n----------------------------------");
			printf("\nNombre y apellido: %s",aux->elem.nombre);
			printf("\nNumero de telefono: %s",aux->elem.numero);
			printf("\nDNI: %s",aux->elem.dni);
			printf("\nProcedencia: %s",tCodigo[aux->elem.procedencia-1]);
			printf("\n----------------------------------");
			aux=aux->siguiente;
		}
	}
}

//Funcion Extra
void visualizarPrimerElemento(){
	tNodo* primero=primerElemento(cola);
	
	if(primero!=NULL){
		printf("\nLa primer llamada es %s - %s",primero->elem.nombre,primero->elem.numero);
	} else{
		printf("\nNo existe primer llamada");
	}
}

void llamadasEnLugares(){
	tNodo* aux=cola.principio;
	int totCtes=0,totChaco=0;
	
	while(aux!=NULL){
		if(aux->elem.procedencia==1){
			totCtes++;
		} else{ 
			totChaco++;
		}
		
		aux=aux->siguiente;
	}
	
	printf("\nCantidad de llamadas provenientes de cada lugar de procedencia: \n");
	printf("\nCORRIENTES [%d]\nCHACO [%d]",totCtes,totChaco);
	
}

void llamadasEnEspera(){
	tNodo* aux=cola.principio;
	int total;
	
	while(aux!=NULL){
		total++;
		aux=aux->siguiente;
	}
	
	printf("\nTotal de llamadas en espera: %d",total);
}

tNodo *primerElemento(tCola pCola){
	return pCola.principio;
}

void ingresarDatos(){
	printf("\nIngresar nombre y apellido: ");
	fflush(stdin);
	scanf("%[^\n]",&dato.nombre);
	
	printf("\nIngresar numero de telefono: ");
	fflush(stdin);
	scanf("%[^\n]",&dato.numero);
	
	printf("\nIngresar DNI: ");
	fflush(stdin);
	scanf("%[^\n]",&dato.dni);
	
	printf("\nIngresar codigo de precedencia [1.Corrientes] [2.Chaco]: ");
	scanf("%d",&dato.procedencia);
}

void menu(){
	int respuesta;
	do {
		printf("\n------------------MENU------------------");
		printf("\n0.Salir\n1.Agregar llamada\n2.Atender llamada\n3.Visualizar llamadas\n4.Total llamadas");
		printf("\n5.Llamadas total de lugares\n6.Primer llamada");
		printf("\n----------------------------------------\n");
		printf("\nIngresar opcion: ");
		scanf("%d",&respuesta);
		
		switch(respuesta){
			case 0: {
				printf("\nSaliendo de menu...");
				break;
			}
			
			case 1: {
				ingresarDatos();
				agregar(dato);
				
				break;
			}
			
			case 2: {
				quitar();
				
				break;
			}
			
			case 3: {
				visualizar(cola);
				
				break;
			}
			
			case 4: {
				llamadasEnEspera();
				
				break;
			}
			
			case 5: {
				llamadasEnLugares();
				
				break;
			}
			
			case 6: {
				//Funcion Extra
				visualizarPrimerElemento();
				
				break;
			}
		}
		getch();
		system("cls");
		
	} while(respuesta!=0);
}

