#include "Alumno.h"
#include <stdio.h>
int main(void){

    static const struct alumno_s jesus = {
        .apellido = "Avila",
        .nombre = "Jesus Gerardo Daniel",
        .documento = 41650372,
     };

char cadena[128];

if (0 <= Serializar(&jesus, cadena, sizeof(cadena)) ){
    printf ("%s\n", cadena);
}else{
    printf("Error al serializar\n");
};


return 0;
}
