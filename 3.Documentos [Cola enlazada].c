#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 25

//Declaracion de tipos de datos personalizados
typedef char tString[MAX]; 

tString tTipo[5]={"docx","pdf","jpg","png","xlsx"};

typedef struct {
	tString ip;
	tString docNombre;
	int tipo;
	float tamano;
}tElem;

typedef struct nodo{
	tElem elem;
	struct nodo* siguiente;
}tNodo;

typedef struct {
	tNodo* principio;
	tNodo* final;
}tCola;

//Declaracion de variables globales
tCola cola;
tElem dato;

//Declaracion de funciones
void inicializar();
bool colaVacia(tCola);
void agregar(tElem);
void quitar();
void visualizar(tCola);
void ingresarDatos();
void documentosImgEnCola();
void tamanoTotalDoc();
tNodo *primerElemento(tCola);
void visualizarPrimerElemento();
void menu();

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
	printf("\nCola inicializada!\n");
	system("pause");
	system("cls");
}

bool colaVacia(tCola pCola){
	return pCola.principio==NULL&&pCola.final==NULL;
}

void agregar(tElem pElem){
	tNodo* nuevoNodo;
	
	nuevoNodo=(tNodo*)malloc(sizeof(tNodo));
	
	nuevoNodo->elem=pElem;
	
	nuevoNodo->siguiente=NULL;
	
	if(colaVacia(cola)){
		cola.final=nuevoNodo;
		cola.principio=nuevoNodo;
	} else{
		cola.final->siguiente=nuevoNodo;
		cola.final=nuevoNodo;
	}
	
	printf("\nDocumento agregado [%s.%s]",pElem.docNombre,tTipo[pElem.tipo-1]);
}

void quitar(){
	if(colaVacia(cola)){
		printf("\nNo hay documentos para imprimir, ingrese otra opcion");
	} else{
		tNodo* nodoSuprimir=cola.principio;
	
		if(cola.principio==cola.final){
			cola.principio=NULL;
			cola.final=NULL;
		} else{
			cola.principio=nodoSuprimir->siguiente;
		}
	
		printf("\nDocumento impreso [%s.%s]",nodoSuprimir->elem.docNombre,tTipo[nodoSuprimir->elem.tipo-1]);
	
		free(nodoSuprimir);
	
		nodoSuprimir=NULL;
	}
}

void visualizar(tCola pCola){
	tNodo* aux=pCola.principio;
	int i;
	
	if(colaVacia(cola)){
		printf("\nNo hay documentos para visualizar, ingrese otra opcion");
	} else{
		printf("\n***DOCUMENTO PARA IMPRIMIR***");
		printf("\n----------------------------------------");
		while(aux!=NULL){
			i++;
			printf("\n\t\tDOCUMENTO %d",i);
			printf("\n----------------------------------------");
			printf("\nDireccion IP de pc: |%s|",aux->elem.ip);
			printf("\nNombre del documento: %s",aux->elem.docNombre);
			printf("\nTipo documento: .%s",tTipo[aux->elem.tipo]);
			printf("\nTama%co: %.1f bytes",164,aux->elem.tamano);
			printf("\n----------------------------------------");
			aux=aux->siguiente;
		}
	}
}

void tamanoTotalDoc(){
	tNodo* aux=cola.principio;
	float total;
	
	while(aux!=NULL){
		total+=aux->elem.tamano;
		aux=aux->siguiente;
	}
	
	printf("\nEl tama%co total de todos los documentos [%.2f] ",164,total);
}

tNodo *primerElemento(tCola pCola){
	return pCola.principio;
}

void visualizarPrimerElemento(){
	tNodo* primero=primerElemento(cola);
	
	if(primero!=NULL){
		printf("\nProximo documento a ser impreso - [%s.%s]",primero->elem.docNombre,tTipo[primero->elem.tipo]);
	} else{
		printf("\nNo hay documentos en cola de impresion");
	}
}

void documentosImgEnCola(){
	tNodo* aux=cola.principio;
	int total=0;
	
	while(aux!=NULL){
  		if(aux->elem.tipo==2||aux->elem.tipo==3||aux->elem.tipo==4){
			total++;
		}
		aux=aux->siguiente;
	}
	
	printf("\nCantidad de documentos de formato de imagen en impresion [%d]",total);
}

void ingresarDatos(){
	printf("\nIngresar direccion IP: ");
	fflush(stdin);
	scanf("%[^\n]s",&dato.ip);
	
	printf("\nIngresar nombre del documento: ");
	fflush(stdin);
	scanf("%[^\n]s",&dato.docNombre);
	
	printf("\nIngresar tipo de documento (01. docx - 02.pdf - 03.jpg - 04.png - 05.xlsx): ");
	scanf("%d",&dato.tipo);
	
	printf("\nIngresar tama%co en bytes: ",164);
	scanf("%f",&dato.tamano);
}

void menu(){
	int res;
	
	do{
		printf("\n---------------------MENU---------------------");
		printf("\n0.Salir\n1.Agregar impresion\n2.Imprimir documentos\n3.Visualizar documentos");
		printf("\n4.Documentos de formato imagen\n5.Tama%co total de documentos\n6.Proximo documento a ser impreso",164);
		printf("\n----------------------------------------------\n");
		printf("\nIngresar opcion: ");
		scanf("%d",&res);
		
		switch(res){
			case 0: {
				printf("\nGracias por ingresar, vuelva pronto!");
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
				documentosImgEnCola();
				
				break;
			}
			
			case 5: {
				tamanoTotalDoc();
				
				break;
			}
			
			case 6: {
				visualizarPrimerElemento();
				
				break;
			}
			
			default: {
				printf("\nIngreso una opcion incorrecta, vuelva a ingresar");
				
				break;
			}
		}
		getch();
		system("cls");
		
	}while(res!=0);
}















