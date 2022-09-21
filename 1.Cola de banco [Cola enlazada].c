#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

//Declaracion de tipos de datos personalizados

typedef char tString[MAX];

tString tMotivo[2]={"Transaccion","Consulta"};

typedef struct{
	int turno;
	tString nombre;
	int motivo;	
}tDato;

typedef struct nodo{
	tDato dato;
	struct nodo* siguiente;
}tNodo;

typedef struct {
	tNodo* principio;
	tNodo* final;
}tCola;

//Declaracion de prototipos
void inicializar();
bool colaVacia(tCola);
void agregar(tDato);
void quitar();
void visualizar(tCola);
tNodo *primerElemento(tCola);
void ingresarDatos();
int contTransaccion();
int contConsulta();
void menu();

//Declaracion de variables
tDato elem;
tCola cola;

//Funcion principal
int main(){
	inicializar();
	menu();
	
	return 0;
}

//Implementacion de funciones
void inicializar(){
	cola.principio=NULL;
	cola.final=NULL;
	printf("\nCola inicializada, lista para agregar elementos\n");
	system("pause");
	system("cls");
}

bool colaVacia(tCola pCola){
	return (pCola.final==NULL&&pCola.principio==NULL);
}

void agregar(tDato tDato){
	tNodo* nuevoNodo;
	
	nuevoNodo=(tNodo*)malloc(sizeof(tNodo));
	
	nuevoNodo->dato=tDato;
	
	nuevoNodo->siguiente=NULL;
	
	if(colaVacia(cola)){
		cola.principio=nuevoNodo;
		cola.final=nuevoNodo;
	} else{
		cola.final->siguiente=nuevoNodo;
		cola.final=nuevoNodo;
	}
	
	printf("\nUsuario ingresado - Turno [%d] Nombre [%s] Motivo [%s]",tDato.turno,tDato.nombre,tMotivo[tDato.motivo-1]);
}

void quitar(){
	if(colaVacia(cola)){
		printf("\nNo hay usuarios para quitar");
	} else{
		tNodo* nodoSuprimir;
		
		nodoSuprimir=cola.principio;
		
		if(cola.final==cola.principio){
			cola.principio=NULL;
			cola.final=NULL;
		} else{
			cola.principio=nodoSuprimir->siguiente;
		}
		
		printf("\nUsuario ieliminado - Turno [%d] Nombre [%s] Motivo [%s]",nodoSuprimir->dato.turno,nodoSuprimir->dato.nombre,tMotivo[nodoSuprimir->dato.motivo-1]);
		
		free(nodoSuprimir);
		
		nodoSuprimir=NULL;
	}
}

void visualizar(tCola pCola){
	if(colaVacia(pCola)){
		printf("\nNo se pueden visualizar usuarios");
	} else{
		tNodo* aux=pCola.principio;
		int i;
		
		printf("\n\t***VISUALIZAR USUARIOS***\n");
		printf("\n---------------------------------------");
		
		while(aux!=NULL){
			i++;
			printf("\n\tUSUARIO %d",i);
			printf("\nTurno: %d",aux->dato.turno);
			printf("\nNombre: %s",aux->dato.nombre);
			printf("\nMotivo: %s",tMotivo[aux->dato.motivo-1]);
			printf("\n---------------------------------------");
			aux=aux->siguiente;
		}
	}
}

tNodo *primerElemento(tCola pCola){
	return pCola.principio;
}

void ingresarDatos(){
	printf("\nIngresar datos: \n");
	
	printf("\n\tNumero de turno: ");
	scanf("%d",&elem.turno);
	
	printf("\n\tNombre de cliente: ");
	fflush(stdin);
	scanf("%[^\n]s",&elem.nombre);
	
	printf("\n\tMotivo [1-Transaccion]-[2-Consulta]: ");
	scanf("%d",&elem.motivo);
}

int contTransaccion(){
	tNodo  *aux;
	aux=cola.principio;
	int total=0;
	
	while(aux!=NULL){
		if(aux->dato.motivo==1){
				total++;
		}
		aux=aux->siguiente;
	}
	
	return total;
}

int contConsulta(){
	tNodo  *aux;
	aux=cola.principio;
	int total=0;
	
	while(aux!=NULL){
		if(aux->dato.motivo==2){
				total++;
		}
		aux=aux->siguiente;
	}
	
	return total;
}

void menu(){
	int res;
	
	do {
		printf("\n------------------MENU------------------");
		printf("\n0.Salir\n1.Agregar\n2.Visualizar\n3.Quitar\n4.Personas esperando [Transaccion]\n5.Personas esperando [Consulta]");
		printf("\n----------------------------------------\n");
		
		printf("\nIngresar opcion: ");
		scanf("%d",&res);
		
		switch(res){
			case 0: {
				printf("\nSaliendo de menu...");
				break;
			}
			
			case 1: {
				ingresarDatos();
				agregar(elem);
				
				break;
			}
			
			case 2: {
				visualizar(cola);
				
				break;
			}
			
			case 3: {
				quitar();
				
				break;
			}
			
			case 4: {
				printf("\n%d",contTransaccion());
				break;
			}
			
			case 5: {
				printf("\n%d",contConsulta());
				break;
			}
			
			default: {
				printf("\nSe ingreso una opcion incorrecta, vuelva a ingresar");
				break;
			}
		}
		getch();
		system("cls");
		
	}while(res!=0);
}




















