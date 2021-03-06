#ifndef __BATALLA_H__
#define __BATALLA_H__


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define FILA_INICIO_HOMBRES '9'
#define FILA_INICIO_ORCOS '0'

#define MOVER_NORTE 'N'
#define MOVER_SUR 'S'
#define ATACAR 'A'
#define SELECCIONAR 'C'

#define RANGED 'R'
#define MELE   'M'

#define RANGO_RANGED_MAX 3

#define ENERGIA_DE_INICIO 3

#define COSTO_RANGED 8
#define COSTO_MELE 3

#define ELFO     'E'
#define HUMANO   'H'
#define ORCO     'O'
#define URUK_HAI 'U'
#define AMBOS    'A'

#define TURNO_ROHAN 0
#define TURNO_ISENGARD 1

#define CANTIDAD_LLEGADAS 5

#define CANTIDAD_INICIO_ROHAN 3
#define CANTIDAD_INICIO_ISENGARD 3

#define MAX_TERRENO_FIL     10
#define MAX_TERRENO_COL     10

#define MAX_PERSONAJES      100

#define VIDA_RANGED_MAXIMA  200
#define BASIC_ATTACK_RANGED 10

#define BASIC_ATTACK_MELE   50
#define VIDA_MELE_MAXIMA  100

typedef struct personaje {
	char codigo;
	int vida;
	int ataque;
	int fila;
	int columna;
	int alcance;
	char rango;
	int movilidad;
	int costo;
	int bando;


	// Pueden agregar los campos que deseen
} personaje_t;

typedef struct juego {
	char terreno[MAX_TERRENO_FIL][MAX_TERRENO_COL];
	personaje_t rohan[MAX_PERSONAJES];
	int cantidad_rohan;
	int energia_rohan;
	int llegadas_rohan;
	int plus_rohan;
	personaje_t isengard[MAX_PERSONAJES];
	int cantidad_isengard;
	int energia_isengard;
	int llegadas_isengard;
	int plus_isengard;
	int modo;
	int turno;
	// Pueden agregar los campos que deseen
} juego_t;

typedef struct datos_obtenidos_del_usuario {
int Puntos_x_Mascota;
int Puntos_x_Maldades;
int Bando;
int intensidad_luchador;

}datos_t;
void limpiar_pantalla();

void realizar_turno(juego_t* juego);

void ejecutar_comandos(juego_t* juego);

void crear_humano(juego_t* juego);
void crear_elfo(juego_t* juego);
void crear_orco(juego_t* juego);
void crear_uruk(juego_t* juego);

void seleccionar_personaje(juego_t* juego);

void Buscar_Libre(char letra,int* ncol, int* nrow);

void mover_personaje(juego_t* juego, int i);

int vida_personajes (juego_t* juego, int i);

void definir_plus (datos_t* datos_obtenidos_del_usuario, juego_t* juego);

void definir_modo(juego_t* juego);

int aleatorio(int rango, int minimo);

void juega_hombre(juego_t* juego, int i);
void juega_orco(juego_t* juego, int i);



void imprimir_pantalla(juego_t* juego);
/*
 * imprime la pantalla
 */
void inicializar_juego(juego_t* juego, datos_t* datos_obtenidos_del_usuario);

/*
 * Inicializar?? todos los valores del juego, dej??ndolo en un estado
 * inicial v??lido.
 */
void posicionar_personaje(juego_t* juego, personaje_t personaje);
/*
 * Recibir?? un personaje, con todos sus campos correctamente cargados y
 * lo dar?? de alta en el juego, sum??ndolo al vector correspondiente,
 * posicion??ndolo tambi??n en la matriz.
 */

void jugar(juego_t* juego, char bando, int posicion_personaje);

/*
 * Realizar?? la jugada del personaje del bando recibido que
 * se encuentra en la posici??n posicion_personaje.
 * Se mover?? o atacar?? dependiento lo que corresponda.
 * Actualizar?? el juego seg??n los efectos del movimiento del
 * personaje, matar rivales, actualizar la matriz, restar vida, etc.
 */


#endif /* __BATALLA_H__ */
