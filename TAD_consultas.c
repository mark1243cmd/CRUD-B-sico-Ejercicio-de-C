#include "TAD_consultas.h"
#include <stdio.h>
#include <string.h>
/*Creacion Funciones*/
/*Menu*/
/*Prototipos 3 tipos de consulta*/
tColaClientes inicializarCola(){
	tColaClientes cola;
	
	cola.tam = 0;
	
	return cola;
	
}

/*Inicializar Consulta*/
void inicializarConsultorio(tConsultorio *c){
	int i;
	
	for(i = 0; i < 3; i++)
		c->colas[i] = inicializarCola();
}
/*Comprobadores*/
int estaVacia(tColaClientes *cola){
	return cola -> tam == 0;
}
int estaLlena(tColaClientes *cola){
	return cola -> tam == TAMMAX;
}
	
/*Crear Cliente || Agregar datos || Desencolar*/	
tCliente crearCliente(char *nombre, char *motivo){
	tCliente cliente;
		int i;

		for(i = 0; nombre[i] != '\0'; i++)
			cliente.nombre[i] = nombre[i];
		cliente.nombre[i] = '\0';
			
		for(i = 0; motivo[i] != '\0'; i++)
			cliente.motivo[i] = motivo[i];
		cliente.motivo[i] = '\0';
			
		return cliente;
}

void push(tColaClientes *cola, tCliente *cliente){
	if(!estaLlena(cola)){
		cola -> datos[cola->tam] = *cliente;
		cola -> tam = cola -> tam +1;
	}
	else{
		printf("Cola llena.\n");
	}
}

tCliente desencolar(tColaClientes *cola)
{
	tCliente c;
	if(!estaVacia(cola)){
		c = cola->datos[0];
		eliminar(cola, &c);
	} else{
		printf("Esta la cola vacia.\n");
		c.nombre[0] = '\0';
		c.motivo[0] = '\0';
	}
	return c;
}
	/* ? BIEN */
void registrarPaciente(tConsultorio *c, tTipoConsultorSelector tipo, tCliente *cliente) {
	if (!estaLlena(&c->colas[tipo])) {
		push(&c->colas[tipo], cliente);
		printf("Poniendo al paciente %s en su sala correspondiente %s\n", cliente -> nombre, nombreConsulta(tipo));
	}
	else{
		printf("Esta llena.\n");
	}
}

/*Eliminar*/
void eliminar(tColaClientes *cola, tCliente *cliente){
		int i, j = 0;
		for(i = 0; i < cola->tam; i++){
			/*Coincide el elemento a eliminar con el elemento actual*/
			if(strcmp(cliente->nombre, cola->datos[i].nombre) == 0){
				j++;                    /* uno mas eliminado, no lo copiamos */
			} else {
				/*Tenemos un elemento
				coincide 1, pero como no coinciden, entonces
				i = 4 - 1, lis elemento actual pasa a ser el anterior,
				eliminando al posterior*/
				cola->datos[i - j] = cola->datos[i];  /* lo recolocamos j posiciones atras */
			}
		}
		cola->tam = cola->tam - j;
}

int eliminarPrimero(tColaClientes *cola, tCliente *cliente){
	int i;
			
	if (!estaVacia(cola)) {

		*cliente = cola->datos[0];
				
		for (i = 0; i < cola->tam - 1; i++)
				cola->datos[i] = cola->datos[i + 1];
				
			cola->tam--;
				
			return 1;
	}
			
	return 0;
}
			
void Atender(tConsultorio *c, tTipoConsultorSelector tipo){
	tCliente cliente;
	if(eliminarPrimero(&c->colas[tipo], &cliente)){
		printf("Atendiendo a %s...\n", cliente.nombre);
	}
	else{
		printf("Esta vacio.\n");
	}
}

/*Mostrar datos*/
void mostrarClientes(tColaClientes *cola){
	int i;
	if(!estaVacia(cola)){
		for(i=0; i < cola -> tam; i++){
			printf("Cliente %d\n Nombre: %s \n Motivo: %s\n", i, cola->datos[i].nombre, cola->datos[i].motivo);
		}
	}
	else{
		printf("No hay clientes, esta vacia.\n");
	}
}
void mostrarCliente(tColaClientes *cola, char *nombre){
	int i;
	if(!estaVacia(cola)){
		for(i=0; i < cola -> tam && strcmp(nombre, cola->datos[i].nombre) != 0; i++);
		if(i < cola -> tam){
			printf("El cliente %s se encuentra en la posicion %d y el motivo es %s\n",
				   cola->datos[i].nombre, i, cola->datos[i].motivo);
			
		}
		else
		   printf("El cliente no ha sido encontrado.\n");
	}
	else{
		printf("Esta vacia.\n");
	}
	
}
void mostrarCola(tConsultorio *c, tTipoConsultorSelector tipo){
	int i;
	int count = c -> colas[tipo].tam;
	if(!estaVacia(&c -> colas[tipo])){
		for(i=0; i < count; i++){
			printf("El cliente %s y su motivo es %s\n", c->colas[tipo].datos[i].nombre,
				   c->colas[tipo].datos[i].motivo);
		}
	}
	else{
		printf("La lista esta vacia\n");
	}
}
	
const char *nombreConsulta(tTipoConsultorSelector tipo){
	switch(tipo){
		case GENERAL: return "GENERAL";
		case OFTAMOLOGIA: return "OFTAMOLOGIA";
		case TRAUMATOLOGIA: return "TRAUMATOLOGIA";
		default: return "Ese numero no es valido.\n";
	}
}
