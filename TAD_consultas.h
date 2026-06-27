#ifndef TAD_CONSULTAS_H
#define TAD_CONSULTAS_H
#define TAMMAX 100
#define NUM_CONSULTAS 3
#define LIMPIAR_BUFFER() { int c; while ((c = getchar()) != '\n' && c != EOF); }

/*Seleccion con enum del consultorio*/
typedef enum{
	GENERAL,
	OFTAMOLOGIA,
	TRAUMATOLOGIA
}tTipoConsultorSelector;

/*Cola cliente*/
typedef struct{
	char nombre[50];
	char motivo[TAMMAX];
}tCliente;

/*Colas Cliente*/
typedef struct {
	tCliente datos[TAMMAX];
	int tam;
} tColaClientes;

/*Seleccionar*/
typedef struct {
	tColaClientes colas[NUM_CONSULTAS];   /* [0]=Trauma [1]=Oftalmo [2]=General */
} tConsultorio;

/*Menu*/
/*Prototipos 3 tipos de consulta*/
tColaClientes inicializarCola();
void inicializarConsultorio(tConsultorio *c);

/*Agregar datos*/
tCliente crearCliente(char *nombre, char *motivo);
void push(tColaClientes *cola, tCliente *cliente);
void registrarPaciente(tConsultorio *c, tTipoConsultorSelector tipo, tCliente *cliente);

/*Eliminar*/
void Atender(tConsultorio *c, tTipoConsultorSelector tipo);
tCliente desencolar(tColaClientes *cola);
void eliminar(tColaClientes *cola, tCliente *cliente);

/*Mostrar datos*/
void mostrarClientes(tColaClientes *cola);
void mostrarCliente(tColaClientes *cola, char *nombre);
void mostrarCola(tConsultorio *c, tTipoConsultorSelector tipo);
const char *nombreConsulta(tTipoConsultorSelector tipo);

#endif
