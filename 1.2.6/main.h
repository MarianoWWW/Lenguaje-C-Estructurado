/*

Realizar el juego del ahorcado. Primero se debe ingresar la palabra a adivinar de hasta 10 caracteres.
Luego se muestra por cada letra un guion bajo para que el jugador sepa la cantidad de letras a adivinar.
Se irá ingresando una a una las letras y si estas se encuentran en la palabra las deberá ir mostrando en
el lugar correspondiente. Por cada letra que no se encuentre en la palabra perderá una vida. El jugador
dispondrá de 5 vidas para intentar ganar el juego.
Complemento:
• Ir completando el dibujo del muñeco del ahorcado cada vez que se comete un error.

*/


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define PALO() printf("\n\t\t\t|           ")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 13

#include "ingresa.h"
#include "adivina.h"
#include "dibujo.h"
#include "duplicada.h"

#endif // MAIN_H_INCLUDED
