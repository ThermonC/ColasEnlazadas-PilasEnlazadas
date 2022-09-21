#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 25

typedef char tString[MAX];

typedef struct {
	tString dni;
	tString nombre;
	tString email;
	int codCategoria;
	float abonado;
}tElem;

typedef struct nodo{
	tElem elem;
	struct nodo* siguiente;
}tPila;

tPila* pila;
tElem dato;
int cantProfesionales,cantTotal;
float montoEstudiantes,totRecaudado;

void inicializar();
bool pilaVacia(tPila*);
void agregar(tElem);
void quitar();
void visualizar(tPila*);
void ingresarDatos();
void menu();
void porcentajeProfesionales();

int main(){
	inicializar();
	menu();
	
	return 0;
}

void inicializar(){
	pila=NULL;
}

bool pilaVacia(tPila* pPila){
	return pPila==NULL;
}

void agregar(tElem pElem){
	tPila* nuevoNodo;
	
	nuevoNodo=(tPila*)malloc(sizeof(tPila));
	
	nuevoNodo->elem=pElem;
	
	nuevoNodo->siguiente=pila;
	
	pila=nuevoNodo;
	
	printf("\nUsuario registrado - DNI [%s]",pElem.dni);
}

void quitar(){
	if(pilaVacia(pila)){
		printf("\nNo se puede quitar usuario, no se ingreso datos");
	} else{
		tPila* nodoSuprimir;
		nodoSuprimir=pila;
		
		pila=pila->siguiente;
	
		if(nodoSuprimir->elem.codCategoria==2){
			cantProfesionales--;
		}
		cantTotal--;
		
		if(nodoSuprimir->elem.codCategoria==1){
			montoEstudiantes-=nodoSuprimir->elem.abonado;
		}
		
		printf("\nUsuario eliminado - DNI [%s]",nodoSuprimir->elem.dni);
		
		free(nodoSuprimir);
	
		nodoSuprimir=NULL;	
	}
}

void visualizar(tPila* pPila){
	tPila* aux;
	aux=pPila;
	int i;
	
	if(pilaVacia(pila)){
		printf("\nNo se pueden visualizar usuario, no se ingreso datos");
	} else{
		printf("\n\t****LISTA DE USUARIOS****\n");
		printf("\n----------------------------------%c",191);
		while(aux!=NULL){
			i++;
			printf("\n\tUSUARIO %d \t\t  |",i);
			printf("\n----------------------------------%c",217);
			printf("\nDNI: %s",aux->elem.dni);
			printf("\nNOMBRE: %s",aux->elem.nombre);
			printf("\nEMAIL: %s",aux->elem.email);
			printf("\nCATEGORIA: %d",aux->elem.codCategoria);
			printf("\nABONADO: $%.2f",aux->elem.abonado);
			printf("\n----------------------------------%c",191);
			aux=aux->siguiente;
		}
	}
}

void ingresarDatos(){
	printf("\n\tIngresar datos:\n");
	printf("\nDNI: ");
	fflush(stdin);
	gets(dato.dni);
	
	printf("\nNombre y apellido: ");
	fflush(stdin);
	gets(dato.nombre);
	
	printf("\nE-Mail: ");
	fflush(stdin);
	gets(dato.email);
	
	printf("\nCodigo de categoria (01-Estudiantes/02-Profesionales/03-Publico en general): ");
	scanf("%d",&dato.codCategoria);
	
	printf("\nMonto abonado: ");
	scanf("%f",&dato.abonado);
	
	if(dato.codCategoria==2){
		cantProfesionales++;
	}
	
	cantTotal++;
	
	if(dato.codCategoria==1){
		montoEstudiantes+=dato.abonado;
	}
	
	totRecaudado+=dato.abonado;
}

void porcentajeProfesionales(){
	float totPorcentaje;
	
	totPorcentaje=100*cantProfesionales/cantTotal;
	
	printf("\nEl porcentaje de los profesionales sobre los inscriptos: %%%.2f",totPorcentaje);
}

void menu(){
	char respuesta;
	
	do {
		printf("\n-------------------MENU-------------------");
		printf("\n0.Salir\n1.Agregar usuario\n2.Quitar usuario\n3.Visualizar usuarios\n4.Cantidad de profesionales\n5.Porcentaje de profesionales");
		printf("\n6.Monto de estudiantes\n7.Total recaudado");
		printf("\n------------------------------------------\n");
		
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
				visualizar(pila);
				
				break;
			}
			
			case 4: {
				printf("\nLa cantidad de profesionales es de %d",cantProfesionales);
				break;
			}
			
			case 5: {
				if(!pilaVacia(pila)){
					porcentajeProfesionales();
				} else{
					printf("\nNo se puede mostrar el procentaje, no hay datos");
				}
				break;
			}
			
			case 6: {
				printf("\nEl monto recaudado de inscriptos de la categoria Estudiante es de $%.2f",montoEstudiantes);
				break;
			}
			
			case 7: {
				printf("\nEl total recaudado en consepto de inscripciones es de $%.2f",totRecaudado);
				break;
			}
			
			default: {
				printf("\nIngreso una opcion incorrecta, vuelva a ingresar");
				break;
			}
		}
		getch();
		system("cls");
		
	}while(respuesta!=0);
}


















