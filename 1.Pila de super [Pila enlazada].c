#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[25];

typedef struct {
	int codProd;
	int codRubro;
	int cantidad;
	float precio;
	tString descripcion;
}tElem;

typedef struct nodo{
	tElem elem;
	struct nodo* siguiente;
}tPila;

tElem dato;
tPila* pila;
float totalRecaudado=0.0;
float total=0.0;

void inicializar();
bool pilaVacia(tPila*);
void agregarElemento(tElem);
void quitarElemento(tElem);
void visualizar(tPila*);
void ingresarDatos();
float totalReca();
void menu();

int main(){
	inicializar();
	menu();
	
	return 0;
}

void inicializar(){
	pila=NULL;
	printf("\nPila inicializada, lista para agregar elementos.\n");
	system("pause");
	system("cls");
}

bool pilaVacia(tPila* pPila){
	return pPila==NULL;
}

void agregarElemento(tElem pElem){
	tPila* nuevoNodo;
	
	nuevoNodo=(tPila*)malloc(sizeof(tPila));
	
	nuevoNodo->elem=pElem;
	
	nuevoNodo->siguiente=pila;
	
	pila=nuevoNodo;
	
	printf("\nCliente ingresado!");
	printf("\nProducto [%d] | Rubro [%d] | Cantidad [%d] | Precio [$%.2f] | Descripcion [%s]",pElem.codProd,pElem.codRubro,pElem.cantidad,pElem.precio,pElem.descripcion);
}

void quitarElemento(tElem pElem){
	if(pilaVacia(pila)){
		printf("\nNo hay clientes para quitar");
	} else{
		tPila* nodoSuprimir;
		nodoSuprimir=pila;
		
		pila=pila->siguiente;
		
		printf("\nCliente eliminado!");
		printf("\nProducto [%d] | Rubro [%d] | Cantidad [%d] | Precio [$%.2f] | Descripcion [%s]",nodoSuprimir->elem.codProd,nodoSuprimir->elem.codRubro,nodoSuprimir->elem.cantidad,nodoSuprimir->elem.precio,nodoSuprimir->elem.descripcion);
		
		free(nodoSuprimir);
		
		nodoSuprimir=NULL;	
	}	
}

void visualizar(tPila* pPila){
	tPila* aux;
	aux=pPila;
	int i;
	
	if(pilaVacia(pila)){
		printf("\nNo hay clientes para visualizar");
	} else{
		printf("\n\t***Lista de clientes***");
		while(aux!=NULL){
			i++;
			printf("\nCLIENTE %d",i);
			printf("\nCodigo de producto: %d",aux->elem.codProd);
			printf("\nCodigo de rubro: %d",aux->elem.codRubro);
			printf("\nCantidad: %d",aux->elem.cantidad);
			printf("\nPrecio: $%.2f",aux->elem.precio);
			printf("\nDescripcion: %s",aux->elem.descripcion);
			printf("\n-----------------------------------");
			aux=aux->siguiente;
		}
	}
}

void ingresarDatos(){
	printf("\nIngresar datos: ");
	printf("\n\tCodigo de producto: ");
	scanf("%d",&dato.codProd);
	
	printf("\n\tCodigo de rubro: ");
	scanf("%d",&dato.codRubro);
	
	printf("\n\tCantidad: ");
	scanf("%d",&dato.cantidad);
	
	printf("\n\tPrecio: ");
	scanf("%f",&dato.precio);
	
	printf("\n\tDescripcion: ");
	fflush(stdin);
	scanf("%[^\n]s",&dato.descripcion);
	
	total=dato.precio*dato.cantidad;
}

float totalReca(){
	totalRecaudado+=total;
	
	return totalRecaudado;
}

void menu(){
	int res;
	do{
		printf("\n--------------Menu--------------");
		printf("\n0.Salir\n1.Agregar\n2.Quitar\n3.Visualizar\n4.Total recaudado");
		printf("\n--------------------------------\n");
		printf("\nSeleccionar opcion: ");
		scanf("%d",&res);
		
		switch(res){
			case 0: {
				printf("\nSaliendo de menu...");
				break;
			}	
			
			case 1: {
				ingresarDatos();
				agregarElemento(dato);
				
				break;
			}
			
			case 2: {
				quitarElemento(dato);
				
				break;
			}
			
			case 3: {
				visualizar(pila);
				
				break;
			}
			
			case 4: {
				printf("\nEl total recaudado es de $%.2f",totalReca());
				
				break;
			}
			
			default: {
				printf("\nIngreso una opcion incorrecta, vuelva a ingresar");
				break;
			}
		}
		getch();
		system("cls");
		
	} while(res!=0);
}
















