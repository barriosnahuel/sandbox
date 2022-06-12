#include <stdio.h>
#define TAM 3
struct dato{
    int legajo;
    int valor;
};

void IniciarVector(struct dato [],int);
void ImprimirVector(struct dato [],int);
void Burbujeo(struct dato[],int);
int Busqueda(struct dato[],int,int);

int main()
{
    struct dato vec[TAM];
    int aux,pos;

    IniciarVector(vec,TAM);
    printf("Vector antes de ordenar\n");
    ImprimirVector(vec,TAM);

    printf("\nIngrese un valor a buscar:");
    scanf("%d",&aux);
    pos=Busqueda(vec,TAM,aux);
    if(pos>=0){
        printf("El valor buscado esta en la pos %d",pos);
    }else{
        printf("El valor buscado no existe");
    }

    Burbujeo(vec,TAM);
    printf("\nVector despues de ordenar\n");
    ImprimirVector(vec,TAM);

    pos=Busqueda(vec,TAM,aux);
    if(pos>=0){
        printf("El valor buscado esta en la pos %d",pos);
    }else{
        printf("El valor buscado no existe");
    }

}

void IniciarVector(struct dato vec[],int tam){
    int legajoAux;
    for(int i=0;i<tam;i++){
        printf("Ingrese legajo:");
        scanf("%d",&legajoAux);

        while(Busqueda(vec,i,legajoAux)>=0){
            printf("\nEl legajo ya existe,ingrese otro:");
            scanf("%d",&legajoAux);
        }

        vec[i].legajo=legajoAux;
        printf("Ingrese valor:");
        scanf("%d",&vec[i].valor);
    }
}

void ImprimirVector(struct dato vec[],int tam){
    for(int i=0;i<tam;i++){
        printf("\nLegajo: %d - Valor: %d",vec[i].legajo,vec[i].valor);
    }
}
void Burbujeo(struct dato vec[],int tam){
    struct dato aux;
    for(int i=0;i<tam-1;i++){
        for(int j=0;j<tam-i-1;j++){
            if(vec[j].legajo>vec[j+1].legajo){
                aux=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }
        }
    }
}

int Busqueda(struct dato vec[],int tam,int val){
    int i=0;
    while(i<tam && vec[i].legajo!=val){
        i++;
    }
    if(i<tam && vec[i].legajo==val){
        return i;
    }else{
        return -1;
    }
}
