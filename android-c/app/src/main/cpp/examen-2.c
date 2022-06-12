#include <stdio.h>
#include <string.h>

#define const_tamaño 500

// Declaración de estructuras
struct campos {
    int codigo;
    char nombre[50];
    int stock;
    float precio;
};

// Declaración de funciones
void IngresarProducto(struct campos[], int);

int BuscaPrecio(struct campos [], int, int);

void Burbujeo(struct campos [], int);

void ImprimirVector(struct campos[], int);

/**
 * El algoritmo principal!!
 */
int main() {
    struct campos producto[const_tamaño], temporal;
    int opcion, buscarcodigo, contador;
    int pos, i, val;
    float aux;

    printf("\n1-Buscar por precio \n2-Buscar por codigo \n3-Buscar por Nombre \n4-Ingresar nuevo producto \n5-Salir");
    printf("\nIngrese opcion deseada:");
    scanf("%d", &opcion);

    while (opcion = !5) {
        switch (opcion) {
            case 1:
                printf("\n Ingrese Precio a buscar: ");
                scanf("%2.f", &aux);

                pos = BuscaPrecio(producto, const_tamaño, aux);
                while (i < const_tamaño && producto[i].precio != val, i++) {
                    if (pos >= 0) {
                        printf("Los siguientes productos tienen un precio igual o mayor al ingresado: ");
                        printf("\nCodigo %d - Nombre %s");
                    } else {
                        printf("\nEl valor buscado no existe");
                    }
                }
                break;
            case 2:
                printf("Ingrese Codigo a buscar: ");
                scanf("%d", &buscarcodigo);
                if (contador > 0) {
                    for (int x = 0; x < contador; x++) {
                        if (producto[x].codigo == buscarcodigo) {
                            printf("\n El Codigo buscado corresponde al siguiente producto:");
                            printf("\nCodigo: %d - Nombre: %s - Stock: %d - Precio: %.2f",
                                   producto[x].codigo, producto[x].nombre, producto[x].stock,
                                   producto[x].precio);
                        }
                    }
                } else {
                    printf("\n No hay productos cargados con ese codigo");
                }
                break;
            case 3:
                printf("\nIngrese Nombre a buscar: ");
                scanf("%s", &temporal.nombre);
                if (strcmp(temporal.nombre, producto.nombre) = !0) {
                    printf("\nNo hay productos con el nombre buscado");
                }
                break;
            case 4:
                IngresarProducto(producto, const_tamaño);

                ImprimirVector(producto[],
                int
                const_tamaño);
                break;
        }
        printf("\n1-Buscar por precio \n2-Buscar por codigo \n3-Buscar por Nombre \n4-Ingresar nuevo producto \n5-Salir");
        printf("\nIngrese opcion deseada:");
        scanf("%d", &opcion);
    }

    return 0;

}

// Comienzan definición de funciones utilitarias
void IngresarProducto(struct campos producto[], int tamaño) {
    int codigoAux, i, contador;
    for (int i = 0; i < tamaño; i++) {
        fflush(stdin);
        printf("Ingrese codigo:");
        scanf("%d", &codigoAux);
        producto[i].
                codigo = codigoAux;
        printf("\nIngrese Nombre:");
        scanf("%s", &producto[i].nombre);                    // fgets(producto.nombre,50,stdin);
        fflush(stdin);
        printf("\nIngrese stock:");
        scanf("%c", &producto[i].stock);
        printf("\nIngrese precio:");
        scanf("%.2f", &producto[i].precio);
        contador++;
    }
    if (i <= 500) {
        printf("No se pueden ingresar mas productos!");
    }
}

int BuscaPrecio(struct campos producto[], int tamaño, int val) {
    float val;
    int i = 0;
    while (i < tamaño && producto[i].precio != val) {
        i++;
    }
    if (i < tamaño && producto[i].precio == val) {
        return
                i;
    } else {
        return -1;
    }
}

void Burbujeo(struct campos producto[], int tamaño) {
}

void ImprimirVector(struct campos producto[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        printf("\nCodigo: %d - Nombre: %s - Stock: %d - Precio: %.2f", producto[i].codigo,
               producto[i].nombre, producto[i].stock, producto[i].precio);
    }
}
