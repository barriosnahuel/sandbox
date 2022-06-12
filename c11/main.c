#include <stdio.h>

#define descuento 0.3

int variableGlobal;

int mainPseudocodigo() {

    // ejecutar el proceso de venta hasta que me digan lo contrario
    // preguntar si es socio ==> si o no
    // preguntar si quiero vender ==> si o no
    // preguntar sector ==> vip, bajo, o platea
    // informar lugares disponibles
    // calcular cuanta plata ingresa

    // mostrar cantidad ventas totales
    // mostrar cantidad de socios
    // mostrar total recaudado

}

int mainNahu() {
    int venta, opcion = -1, club, socio = 0;
    int vip = 550, bajo = 350, platea = 250;
    int lugaresVip = 1;
    int lugaresBajo = 1;
    int personas = 0, recaudado = 0;

    printf("Desea registrar venta? (1 para registrar, 0 para finalizar): ");
    scanf("%d", &venta);


    // iteración, loop
    // entrada = input, salida = output
    while (venta == 1) {
        printf("\n1-Sector Vip");
        printf("\n2-Sector bajo");
        printf("\n3-Platea");
        printf("\nIngrese opcion deseada: ");
        scanf("%d", &opcion);
        personas++;

        switch (opcion) {
           case 1:

                if (lugaresVip > 0) {
                    printf("El valor del sector vip es de %d pesos\n", vip);
                    printf("\nEs socio de Club Teatro? (1 SI, 0 NO): ");
                    scanf("%d", &club);
                    if (club == 1) {
                        socio++;
                        int beneficio = vip - (vip * descuento);
                        printf("\nTiene un 30 porciento de descuento");
                        printf("\nEl valor de la entrada es de %d pesos\n", beneficio);
                        recaudado = recaudado + beneficio;
                    } else {
                        recaudado = recaudado + vip;
                    }
                    lugaresVip--;
                    printf("Quedan %d lugares vip\n", lugaresVip);
                } else {
                    printf("no te vendo nada, gil");
                }

                break;

            case 2:
                printf("El valor del sector bajo es de %d pesos\n", bajo);
                printf("\nEs socio de Club Teatro? (1 SI, 0 NO): ");
                scanf("%d", &club);
                if (club == 1) {
                    socio++;
                    int beneficio = bajo - (bajo * descuento);
                    printf("\nTiene un 30 porciento de descuento");
                    printf("\nEl valor de la entrada es de %d pesos\n", beneficio);
                    recaudado = recaudado + beneficio;
                } else {
                    recaudado = recaudado + bajo;
                }
                lugaresBajo--;

                break;
            default:

                printf("lugares vip disponibles: %d\n", lugaresVip);

                printf("La opcion ingresada no es valida\n");
        }

        printf("\nDesea registrar venta? (1 para registrar, 0 para finalizar): ");
        scanf("%d", &venta);
    }
    printf("\n Cantidad total de entradas vendidas: %d", personas);
    printf("\n Cantidad total de socios de club teatro: %d", socio);
    printf("\n Monto total recaudado: %d", recaudado);
    return 0;
}

/**
 * Punto A del primer exámen.
 */
int mainA() {
    float demora, metros, sonido = 300;
    int opcion;

    printf("\n Se observo algun rayo? (1 para SI, 0 para Finalizar):");
    scanf("%d", &opcion);

    while (opcion == 1) {
        printf("\n Ingrese cuantos segundos tardo en oir el trueno: ");
        scanf("%f", &demora);

        metros = (demora * sonido);
        printf("\n El rayo cayo aproximadamente a %.2f metros:\n", metros);

        printf("\n Se observo algun rayo? (1 para SI, 0 para Finalizar):");
        scanf("%d", &opcion);
    }

    return 0;
}

// Lesende, Mariel DNI 36884197
#include <stdio.h>

#define descuento 0.3

int main() {
    int venta, opcion, club, socio = 0;
    int vip = 550, bajo = 350, platea = 250;
    int personas = 0, recaudado = 0;
    int lugaresVip = 1, lugaresBajo = 55, lugaresPlatea = 80;                   // lugares de cada sector

    printf("SISTEMA DE REGISTRO DE VENTAS\n\n");
    printf("Desea registrar venta? (1 para registrar, 0 para finalizar): ");
    scanf("%d", &venta);
    while (venta == 1) {
        printf("\n1-Sector Vip");                         //seleccion de sector
        printf("\n2-Sector bajo");
        printf("\n3-Platea");
        printf("\nIngrese opcion deseada: ");
        scanf("%d", &opcion);

        printf("\nEs socio de Club Teatro? (1 SI, 0 NO): ");
        scanf("%d", &club);
        switch (opcion) {
            case 1:
                if (lugaresVip > 0 && club == 1) {
                    int beneficio = vip - (vip * descuento);
                    printf("\nEl valor del sector vip con descuento es de %d pesos\n", beneficio);
                    socio++;                             //contador cantidad de socios
                    recaudado = recaudado + beneficio;
                } else {
                    printf("\nEl valor de la entrada es de %d pesos\n", vip);
                    recaudado = recaudado + vip;
                }
                lugaresVip--;
                if (lugaresVip == 0) {
                    printf("\nNo quedan mas lugares disponibles en este sector");
                }
                break;
            case 2:
                if (lugaresBajo > 0 && club == 1) {
                    int beneficio = bajo - (bajo * descuento);
                    printf("\nEl valor del Sector Bajo con descuento es de %d pesos\n", beneficio);
                    socio++;                             //contador cantidad de socios
                    recaudado = recaudado + beneficio;
                } else {
                    printf("\nEl valor de la entrada es de %d pesos\n", bajo);
                    recaudado = recaudado + bajo;
                }
                lugaresBajo--;
                if (lugaresBajo == 0) {
                    printf("\nNo quedan mas lugares disponibles en este sector");
                }
                break;
            case 3:
                if (lugaresPlatea > 0 && club == 1) {
                    int beneficio = platea - (platea * descuento);
                    printf("\nEl valor del Sector de Plateas con descuento es de %d pesos\n", beneficio);
                    socio++;                             //contador cantidad de socios
                    recaudado = recaudado + beneficio;
                } else {
                    printf("\nEl valor de la entrada es de %d pesos\n", platea);
                    recaudado = recaudado + platea;
                }
                lugaresPlatea--;
                if (lugaresPlatea == 0) {
                    printf("\nNo quedan mas lugares disponibles en este sector");
                }
                break;
            default:
                printf("La opcion ingresada no es valida\n");
        }
        printf("\nDesea registrar otra venta? (1 para registrar, 0 para finalizar): ");
        scanf("%d", &venta);
        personas++;                  // contador personas general
    }

    printf("\n Cantidad total de entradas vendidas: %d", personas);
    printf("\n Cantidad total de socios de club teatro: %d", socio);
    printf("\n Monto total recaudado: %d\n", recaudado);

    return 0;
}

