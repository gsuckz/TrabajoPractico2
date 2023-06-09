#include "Alumno.h"
#include <stdio.h>
/// @brief 
/// Modulo Alumno con la funcion Serializar
/// @return 

static int SerializarCadena();
/// @brief 
/// Funcion para Imprimir Cadenas
/// @return 

static int SerializarNumero();
/// @brief 
/// Funcion para Imprimir Numeros
/// @return 


static int SerializarCadena(const char * campo,const char * valor, char * cadena, int espacio){
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio){
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

int Serializar(const struct alumno_s * alumno, char cadena[], uint32_t espacio){
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    cadena++;
    disponibles--;
    resultado = SerializarCadena("apellido",&alumno->apellido,cadena,disponibles);

    if (resultado > 0){
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarCadena("nombre",&alumno->nombre,cadena,disponibles);
    }
    if (resultado > 0){
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento",alumno->documento,cadena,disponibles);
    }
    if (resultado > 0){
        cadena += resultado;
        disponibles -= resultado;
        *(cadena-1)= '}';
        resultado = espacio - disponibles;
    }

    return resultado;
}
