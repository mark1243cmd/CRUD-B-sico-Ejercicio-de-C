#include "TAD_consultas.h"
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>

int main (void) {
	int i, N=0, opcion= -1, tipoConsulta=-1;
	tCliente cliente;
	char nombre[50], motivo[TAMMAX];
	tColaClientes cola;
	tConsultorio c;
	cola = inicializarCola();
	inicializarConsultorio(&c);
	
	while(opcion!=0){
		
		printf("\n------------------------------------\n");
		printf("1. Crear Cliente\n");
		printf("2. Mostrar Clientes\n");
		printf("3. Buscar Cliente\n");
		printf("4. Registrar paciente\n");
		printf("5. Mostrar Consultorio.\n");
		printf("6. Atender\n");
		printf("7. Limpiar pantalla\n");
		printf("0. Salida");
		printf("\n------------------------------------\n");
		
		printf("Elige una opcion:\n "); scanf("%d",&opcion);
		LIMPIAR_BUFFER();
		switch(opcion){
			/*Salir*/
			case 0:
				printf("Saliendo del bucle...\n");
				opcion = 0;
				break;
			/*Crear Cliente*/
			case 1:
				printf("Cuantos clientes quieres agregar:\n "); scanf("%d", &N);
				LIMPIAR_BUFFER();
				for(i=0; i<N; i++){
					printf("Dame el nombre: \n"); scanf("%49s", nombre);
					printf("Dame el motivo: \n");scanf("%99s", motivo);
					LIMPIAR_BUFFER();
					cliente = crearCliente(nombre, motivo);
					push(&cola, &cliente);
					system("cls");
					
				}
				break;
			/*Mosrar clientes*/
			case 2:
				mostrarClientes(&cola);
				break;
			/*Buscar cliente*/
			case 3:
				printf("Dime el nombre: \n");
				scanf("%49s", nombre);
				LIMPIAR_BUFFER();
				
				mostrarCliente(&cola, nombre);
				break;
			/*Registrar paciente*/
			case 4:
				
				printf("Añadir cola a (1. GENERAL, 2. OFTAMOLOGIA, 3. TRAUMATOLOGIA): \n"); scanf("%d", &tipoConsulta);
				LIMPIAR_BUFFER();
				if(tipoConsulta >= 1 && tipoConsulta <=3){
					tipoConsulta--;
					cliente = desencolar(&cola); 
					registrarPaciente(&c,tipoConsulta, &cliente);
					break;
				}
				else{
					printf("Es incorrecto el valor dado, recuerda (1. GENERAL, 2. OFTAMOLOGIA, 3. TRAUMATOLOGIA)\n");
					Sleep(5000);
					system("cls");
					break;
				}
			case 5:
				   printf("Elegir cola a (1. GENERAL, 2. OFTAMOLOGIA, 3. TRAUMATOLOGIA): \n"); scanf("%d", &tipoConsulta);
				   LIMPIAR_BUFFER();
				   if(tipoConsulta >= 1 && tipoConsulta <=3){
					   tipoConsulta--; 
					   mostrarCola(&c, tipoConsulta);
					   break;
				   }
				   else{
					   printf("Es incorrecto el valor dado, recuerda (1. GENERAL, 2. OFTAMOLOGIA, 3. TRAUMATOLOGIA)\n");
					   Sleep(5000);
					   system("cls");
					   break;
				   }
			case 6:
					printf("Elegir cola a (1. GENERAL, 2. OFTAMOLOGIA, 3. TRAUMATOLOGIA): \n"); scanf("%d", &tipoConsulta);
					LIMPIAR_BUFFER();
					if(tipoConsulta >= 1 && tipoConsulta <=3){
						tipoConsulta--; 
						Atender(&c, tipoConsulta);
						break;
					}
					else{
						printf("Es incorrecto el valor dado, recuerda (1. GENERAL, 2. OFTAMOLOGIA, 3. TRAUMATOLOGIA)\n");
						Sleep(5000);
						system("cls");
						break;
					}
			case 7:
					system("cls");
					break;
			default:
				printf("Opcion no valida.\n");
				break;
				
		}
	}
	return 0;
}

