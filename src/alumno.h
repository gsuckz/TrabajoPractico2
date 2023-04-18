#ifndef Alumno_H
#define Alumno_H
#endif
#include <stdint.h> 
#include <string.h> 

typedef struct alumno_s{
    char apellido[50];
    char nombre[50];
    uint32_t documento;
} alumno_t;


int Serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio);