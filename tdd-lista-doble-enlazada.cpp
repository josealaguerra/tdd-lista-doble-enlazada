#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//Nodo que representara nuestra lista
typedef struct nodo{
	int codigo;
	char nombre[30];
	char identificacion[15];
	char telefono[10];
	char direccion[45];
	struct nodo *ptrSig;
	struct nodo *ptrAnt;
} stcNodo;


stcNodo *ptrInicio, *ptrRecorrido, *ptrNuevo, *ptrAnterior, *ptrFinal;



//Solicita información en pantalla y 
//crea un nodo para que sea agregado a la lista
bool CrearNodo(){
	bool seCreoNodo=false;
	system("cls");
	
	//Se busca un espacio en memoria
	ptrNuevo = (stcNodo *)malloc( sizeof(stcNodo) );
	
	//Si el puntero es nulo, envia error
	if(ptrNuevo == NULL){
		printf("%s","No hay espacio en memoria disponible para crear");
	}else{
		//Paso 1, pedimos avlor a inicializamos punteros
		printf("%s","***** INGRESO DE DATOS *****\n");
		printf("%s","\nIngrese codigo de cliente:\n");
		scanf("%d", &ptrNuevo->codigo);
		printf("%s","\nIngrese nombre:\n");
		scanf("%s", &ptrNuevo->nombre);
		printf("%s","\nIngrese identificacion:\n");
		scanf("%s", &ptrNuevo->identificacion);
		printf("%s","\nIngrese telefono:\n");
		scanf("%s", &ptrNuevo->telefono);
		printf("%s","\nIngrese direccion:\n");
		scanf("%s", &ptrNuevo->direccion);

		ptrNuevo->ptrSig = NULL;
		ptrNuevo->ptrAnt = NULL;
		
		if(ptrInicio == NULL){
			ptrInicio = ptrNuevo;
			ptrFinal = ptrNuevo;
		}else{
			seCreoNodo=true;
		}
	}
	
	return seCreoNodo ;
}



//Agrega al final de la lista al nodo
void CrearNodoFinal(){
		
	if( CrearNodo() ){
		ptrRecorrido = ptrInicio;
		while(ptrRecorrido->ptrSig != NULL){
			ptrRecorrido = ptrRecorrido->ptrSig;			
		}
		
		ptrRecorrido->ptrSig = ptrNuevo;
		ptrFinal = ptrNuevo;
	}

}



//Agrega el nodo al principio de la lista
void CrearNodoInicio(){

	if( CrearNodo() ){
		ptrNuevo->ptrSig = ptrInicio;
		ptrInicio = ptrNuevo;
	}

}



//Agrega el nodo en orden descendente según el código del cliente ingresado.
void CrearNodoEnOrden(){
//	bool encontro=false;

	if( CrearNodo() ){

		ptrAnterior = ptrInicio;
		ptrRecorrido = ptrInicio;
		while(ptrRecorrido->ptrSig != NULL){

			if(ptrNuevo->codigo > ptrRecorrido->codigo){
				break;
			}

			ptrAnterior = ptrRecorrido;
			ptrRecorrido = ptrRecorrido->ptrSig;
		}
		
		if(ptrNuevo->codigo > ptrRecorrido->codigo){
			ptrNuevo->ptrSig = ptrRecorrido ;
			
			if(ptrInicio == ptrRecorrido){
				ptrInicio = ptrNuevo;
				//Punteros
				ptrNuevo->ptrSig = ptrFinal;
				ptrNuevo->ptrAnt = ptrInicio;
			}else{
				ptrAnterior->ptrSig = ptrNuevo;
				//Punteros
				ptrNuevo->ptrSig = ptrRecorrido->ptrSig;
				ptrNuevo->ptrAnt = ptrAnterior;				
			}
			
		}else{
			ptrRecorrido->ptrSig = ptrNuevo;
			ptrFinal = ptrNuevo;
			//Punteros
			ptrFinal->ptrSig = NULL;
			ptrFinal->ptrAnt = ptrAnterior;
		}
	}

}



//Elimina un nodo de la lista
void EliminarNodoEnOrden(){
	bool nodoEncontrado=false;
	int numBusqueda, numEncontrado;
	
	numBusqueda=0;
	numEncontrado=0;

	system("cls");
	printf("%s\n","***** ELIMINAR NODO *****");
	printf("%s","* INGRESE NODO A ELIMINAR: ");
	scanf("%d",&numBusqueda);
	
	ptrAnterior = ptrInicio;
	ptrRecorrido = ptrInicio;
	while(ptrRecorrido != NULL){
		if(ptrRecorrido->codigo == numBusqueda){
			ptrAnterior->ptrSig = ptrRecorrido->ptrSig;

			nodoEncontrado=true;
			printf("%s%d%s\n","* ",numBusqueda, "--> [Eliminado exitosamente !!!]");
			break;
		}
		ptrAnterior = ptrRecorrido;
		ptrRecorrido = ptrRecorrido->ptrSig;
	}
	
	printf("%s\n","*       *");
	printf("%s\n","**************************");
	getch();
}




//Recorre la lista
void Recorrido(){
	system("cls");
	printf("%s\n","***** RECORRIDO DE LISTA DOBLE ENLAZADA *****");
	printf("%s\n","*****");

	ptrRecorrido = ptrInicio;
	while(ptrRecorrido != NULL){
		printf("(%d-%s %s %s %s)-->", 
				ptrRecorrido->codigo,
				ptrRecorrido->nombre, 
				ptrRecorrido->identificacion,
				ptrRecorrido->telefono,
				ptrRecorrido->direccion);
		ptrRecorrido = ptrRecorrido->ptrSig;	
	}
	
	printf("%s\n","NIL");
	printf("%s\n","*            *");
	printf("%s\n","*****");
	getch();
}



//Recorre la lista de manera inversa
void RecorridoInverso(){
	system("cls");
	printf("%s\n","***** RECORRIDO INVERSO DE LISTA DOBLE ENLAZADA *****");
	printf("%s\n","*****");

	ptrRecorrido = ptrFinal;
	while(ptrRecorrido != NULL){
		printf("(%d-%s %s %s %s)-->", 
				ptrRecorrido->codigo,
				ptrRecorrido->nombre, 
				ptrRecorrido->identificacion,
				ptrRecorrido->telefono,
				ptrRecorrido->direccion);
		ptrRecorrido = ptrRecorrido->ptrAnt;
	}
	
	printf("%s\n","NIL");
	printf("%s\n","*            *");
	printf("%s\n","*****");
	getch();
}



//Recorre la lista de manera inversa
void RecorridoEspecial(){
	system("cls");
	printf("%s\n","***** REPORTE DE PERSONAS LISTA DOBLE ENLAZADA *****");
	printf("%s\n","*****");

	ptrRecorrido = ptrInicio;
	printf("\t%s\t\t %s\t\t %s\t\t %s\t\t %s\n", 	
				"codigo",
				"nombre", 
				"identificacion",
				"telefono",
				"direccion");
	while(ptrRecorrido != NULL){
		printf("\t%d\t\t %s\t\t %s\t\t %s\t\t %s\n", 
				ptrRecorrido->codigo,
				ptrRecorrido->nombre, 
				ptrRecorrido->identificacion,
				ptrRecorrido->telefono,
				ptrRecorrido->direccion);
		ptrRecorrido = ptrRecorrido->ptrSig;
	}

	printf("%s\n","*******************");
	printf("%s\n","FIN DE LOS DATOS");
	printf("%s\n","*******************");
	getch();
}


//Recorre la lista de manera inversa
void ReporteCantPersonas(){
	system("cls");
	printf("%s\n","***** RECORRIDO INVERSO DE LISTA DOBLE ENLAZADA *****");
	printf("%s\n","*****");

	ptrRecorrido = ptrFinal;
	while(ptrRecorrido != NULL){
		printf("(%d-%s %s)-->", 
				ptrRecorrido->codigo,
				ptrRecorrido->nombre, 
				ptrRecorrido->identificacion,
				ptrRecorrido->telefono,
				ptrRecorrido->direccion);
		ptrRecorrido = ptrRecorrido->ptrAnt;
	}
	
	printf("%s\n","NIL");
	printf("%s\n","*            *");
	printf("%s\n","*****");
	getch();
}



//Busca un código de cliente
void Busqueda(){
	int numBusqueda, numEncontrado;
	
	numBusqueda=0;
	numEncontrado=0;

	system("cls");
	printf("%s\n","***** BUSQUEDA DE UN VALOR *****");
	printf("%s","*** INGRESE VALOR A BUSCAR: ");
	scanf("%d",&numBusqueda);
	
	ptrRecorrido = ptrInicio;
	while(ptrRecorrido != NULL){
		if(ptrRecorrido->codigo == numBusqueda){
			printf("* (%d-%s %s)--> [Valor encontrado]\n", 
					ptrRecorrido->codigo,
					ptrRecorrido->nombre, 
					ptrRecorrido->identificacion,
					ptrRecorrido->telefono,
					ptrRecorrido->direccion);
			//printf("%s%d%s\n","* ",ptrRecorrido->codigo, "-->");
			numEncontrado++;
		}
		ptrRecorrido = ptrRecorrido->ptrSig;
	}	
	
	if(numEncontrado == 0){
		printf("%s%d%s\n","* ",numBusqueda, "--> [Lo lamento, el valor no fue encontrado !!!]");
	}
	
	printf("%s\n","*       *");
	printf("%s\n","**************************");
	getch();
}


void enlaceInicial(){
	if(ptrInicio != NULL){
		ptrInicio->ptrSig = ptrFinal;
		ptrInicio->ptrAnt = ptrFinal;
	}
	if(ptrFinal != NULL){
		ptrFinal->ptrSig = ptrInicio;
		ptrFinal->ptrAnt = ptrInicio;
	}
}

int main (){
	
	int opcion=0;
	enlaceInicial();

	while(opcion != 8){
		system("cls");
		printf("%s\n","1.Ingresar");
		printf("%s\n","2.Buscar");
		printf("%s\n","3.Eliminar");
		printf("%s\n","4.Listado");
		printf("%s\n","5.Listado inverso");
		printf("%s\n","6.Reporte de personas");
		printf("%s\n","7.Cantidad de personas");
		printf("%s\n","8.Salir");
		printf("%s\n","Seleccione una opcion");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				CrearNodoEnOrden();
				break;
			case 2:
				Busqueda();
				break;
			case 3:
				EliminarNodoEnOrden();
				break;
			case 4:
				Recorrido();
				break;
			case 5:
				RecorridoInverso();
				break;				
			case 6:
				RecorridoEspecial();
				break;								
			case 7:
				ReporteCantPersonas();
				break;												
			case 8:
				break;								

			default:
				printf("%s\n","8.Salir");	
				getch();
				opcion=0;
				break;													
		}
	}
	
	return 0;
}

