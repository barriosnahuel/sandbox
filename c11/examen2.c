#include <stdio.h>
#include <string.h>
#define tam 500

struct campos {
       int codigo;
       char nombre[50];
       int stock;
       float precio;
};
void IngresarProducto(struct campos[],int );
int BuscaPrecio(struct campos [],int ,int );
void Burbujeo (struct campos [],int );
void ImprimirVector (struct campos[],int );

int main() {
   struct campos producto[tam], temporal;
   int opcion, buscarcodigo, contador;
   int pos, i, val;
   float aux;

   printf("\n1-Buscar por precio \n2-Buscar por codigo \n3-Buscar por Nombre \n4-Ingresar nuevo producto \n5-Salir");
   printf("\nIngrese opcion deseada:");
   scanf("%d",&opcion);

   while (opcion=!5){
       switch (opcion){
           case 1:
               printf("\n Ingrese Precio a buscar: ");
               scanf("%2.f", &aux );

               Burbujeo (producto[],int tam );

               pos=BuscaPrecio(producto,tam,aux);
               while(i<tam && producto[i].precio!=val, i++) {
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
               scanf("%d",&buscarcodigo);
               if(contador>0){
                   for(int x=0;x<contador;x++){
                       if(producto[x].codigo==buscarcodigo){
                           printf("\n El Codigo buscado corresponde al siguiente producto:");
                           printf("\nCodigo: %d - Nombre: %s - Stock: %d - Precio: %.2f",producto[x].codigo, producto[x].nombre, producto[x].stock, producto[x].precio);
                       }
                   }
               }else{
                   printf("\n No hay productos cargados con ese codigo");
               }
               break;
           case 3:
               printf("\nIngrese Nombre a buscar: ");
               scanf("%s",&temporal.nombre);
               if (strcmp (temporal.nombre, producto.nombre)=!0){
                   printf("\nNo hay productos con el nombre buscado");}
                   break;
           case 4:
               IngresarProducto (producto, tam);

               ImprimirVector (producto[],int tam);
               break;
       }
       printf("\n1-Buscar por precio \n2-Buscar por codigo \n3-Buscar por Nombre \n4-Ingresar nuevo producto \n5-Salir");
       printf("\nIngrese opcion deseada:");
       scanf("%d",&opcion);
   }

   return 0;

}
void IngresarProducto (struct campos producto[],int tam) {
   int codigoAux, i,contador;
   for(int i=0;i<tam;i++){
       fflush(stdin);
       printf("Ingrese codigo:");
       scanf("%d",&codigoAux);
       producto[i].codigo=codigoAux;
       printf("\nIngrese Nombre:");
       scanf ("%s",&producto[i].nombre);                    // fgets(producto.nombre,50,stdin);
       fflush(stdin);
       printf("\nIngrese stock:");
       scanf("%c",&producto[i].stock);
       printf("\nIngrese precio:");
       scanf("%.2f",&producto[i].precio);
       contador ++; }
   if (i<=500){
       printf("No se pueden ingresar mas productos!");
   }
}

int BuscaPrecio (struct campos producto[],int tam,int val) {
   float val;
   int i = 0;
   while (i<tam && producto[i].precio!=val) {
       i++;
   }
   if (i<tam && producto[i].precio==val) {
       return i;
   } else {
       return -1;
   }
}


void Burbujeo(struct campos producto[],int tam){
   struct campos aux[];

void IngresarProducto(struct campos producto, int) {

}

for(int i=0;i<tam-1;i++){
       for(int j=0;j<tam-i-1;j++){
           if(producto[j].precio>producto[j+1].precio){
               aux=producto[j];
               producto[j]=producto[j+1];
               producto[j+1]=aux;
           }
       }
   }
}

void ImprimirVector (struct campos producto[],int tam){
   for(int i=0;i<tam;i++){
       printf("\nCodigo: %d - Nombre: %s - Stock: %d - Precio: %.2f",producto[i].codigo,producto[i].nombre, producto[i].stock, producto[i].precio);
   }
}
