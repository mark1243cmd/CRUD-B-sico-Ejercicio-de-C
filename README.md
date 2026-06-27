# Consultorio — CRUD de Consola en C

CRUD básico por consola implementado en C como ejercicio práctico para afianzar el manejo de **colas** y **estructuras de datos (TADs)**.

El programa simula la gestión de pacientes en un consultorio médico con tres especialidades, usando una cola de espera general y colas independientes por consulta.

---

## Estructura del proyecto

```
Consultorio/
├── main.c              # Menú principal y lógica de interacción
├── TAD_consultas.h     # Definición de tipos y prototipos
└── TAD_consultas.c     # Implementación de las funciones
```

---

## Estructuras de datos

```c
tCliente          // Nodo: nombre + motivo de consulta
tColaClientes     // Cola de clientes (array + tamaño)
tConsultorio      // Agrupación de 3 colas por especialidad
tTipoConsultorSelector  // Enum: GENERAL | OFTAMOLOGIA | TRAUMATOLOGIA
```

La capacidad máxima de cada cola es `TAMMAX = 100` pacientes.

---

## Funcionalidades (menú)

| Opción | Acción |
|--------|--------|
| `1` | Crear uno o varios clientes y añadirlos a la **cola general** |
| `2` | Mostrar todos los clientes de la cola general |
| `3` | Buscar un cliente por nombre en la cola general |
| `4` | Registrar (desencolar de general → encolar en especialidad) |
| `5` | Mostrar la cola de una especialidad |
| `6` | Atender al primer paciente de una especialidad (desencolar) |
| `7` | Limpiar pantalla |
| `0` | Salir |

---

## Flujo de uso

```
1. Crear clientes  →  cola general (push)
        ↓
4. Registrar       →  desencola de general, encola en especialidad
        ↓
6. Atender         →  elimina al primero de la especialidad (FIFO)
```

---

## Compilación

Compilado con **ZinjaI** en Windows. Para compilar manualmente con GCC en Windows:

```bash
gcc main.c TAD_consultas.c -o Consultorio.exe
```

> El proyecto usa `<windows.h>` para `Sleep()` y `system("cls")`, por lo que está pensado para entornos Windows.

---

## Funciones implementadas

### `TAD_consultas.c`

| Función | Descripción |
|---------|-------------|
| `inicializarCola()` | Devuelve una cola vacía (tam = 0) |
| `inicializarConsultorio()` | Inicializa las 3 colas de especialidad |
| `crearCliente()` | Crea un `tCliente` a partir de nombre y motivo |
| `push()` | Encola un cliente (si no está llena) |
| `desencolar()` | Extrae el primero de la cola general (FIFO) |
| `registrarPaciente()` | Desencola de general y encola en especialidad |
| `eliminar()` | Elimina un cliente concreto por nombre |
| `eliminarPrimero()` | Extrae el primer elemento y reordena el array |
| `Atender()` | Llama a `eliminarPrimero()` e imprime el nombre atendido |
| `mostrarClientes()` | Lista todos los clientes de una cola |
| `mostrarCliente()` | Busca y muestra un cliente por nombre |
| `mostrarCola()` | Lista la cola de una especialidad del consultorio |
| `nombreConsulta()` | Devuelve el nombre en texto del tipo de consulta |

---

## Notas

- La eliminación en `eliminar()` usa desplazamiento del array para mantener el orden FIFO.
- El buffer de entrada se limpia con la macro `LIMPIAR_BUFFER()` tras cada `scanf`.
