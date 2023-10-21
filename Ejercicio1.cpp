#include <stdio.h>

int menu();
int sumaA(int *arr, int tam);
int llenararregl(int arreglo[], int tam);
void copiarArreglos(int *origen, int *destino, int tam);
void concatenarArreglos(int *arr1, int *arr2, int *resultado, int tam1, int tam2);
int compararArreglos(int *arr1, int *arr2, int tam);
void encontrarMaximo(int *arr, int tam);

int main() 
{
    int check, arreglo[5], arreglo2[5], tam = sizeof(arreglo) / sizeof(arreglo[0]);
    int destino[5], resultado;
    printf("Llena el arreglo con 5 números\n\n");
    llenararregl(arreglo, tam);
    printf("\n\nllena un segundo arreglocon 5 números: \n\n");
    llenararregl(arreglo2, tam);
    printf("\n\n");
    do 
    {
        check = menu();
        if (check == 1) 
        {
            int n;
            printf("Quieres sumar los elementos del arreglo 1 o 2?");
            scanf("%d",&n);
            if (n == 1)
            {
                resultado = sumaA(arreglo, tam);
            
            }
            else 
            {
                resultado = sumaA(arreglo2, tam);
            }
            printf("La suma de elementos en el arreglo es: %d\n", resultado);
        }
        else
        {
            if(check == 2)
            {
                copiarArreglos(arreglo, destino, tam); 
                printf("Arreglo destino copiado desde arreglo origen.\n");
            }    
            else
            {
                if (check == 3)
                {
                    int resultado[tam + 5]; 
                    concatenarArreglos(arreglo, arreglo2, resultado, tam, 5);
                    for (int i = 0; i < tam + 5; i++) 
                    {
                        printf("%d ", resultado[i]);
                    }
                    printf("\n");
                }
                else
                {
                    if (check == 4)
                    {
                        int resultado = compararArreglos(arreglo, arreglo2, tam);
                        if (resultado) 
                        {
                            printf("Los arreglos son iguales.\n");
                        } 
                        else 
                        {
                            printf("Los arreglos no son iguales.\n");
                        }
                    }
                    else
                    {
                        if (check == 5)
                        {
                            int n;
                            printf("Quieres encontrar el maximo del arreglo 1 o 2?");
                            scanf("%d",&n);
                            if (n == 1)
                            {
                                encontrarMaximo(arreglo, tam);
            
                            }
                            else 
                            {
                                if (n == 2)
                                {
                                    encontrarMaximo(arreglo2, tam);
                                }
                            }
                        } 
                    }
                }
            }
        }  
    } while (check != 0);
    printf("\n\nAdios!!!");
    return 0;
}

int menu()
{
    int op;
    printf("\n\n\tMenu\n");
    printf("1. Suma de elementos en un arreglo\n");
    printf("2. Copia de arreglos\n");
    printf("3. Concatenación de arreglos\n");
    printf("4. Comparación de arreglos\n");
    printf("5. Encontrar el elemento máximo\n");
    printf("0. Salir\n");
    scanf("%d",&op);
    return op;
}

int llenararregl(int arreglo[], int tam)
{
    for (int i = 0; i < tam; i++) 
    {
        printf("Dame un valor cualquiera: ");
        scanf("%d", &arreglo[i]);
    }
    return arreglo[5];
}

int sumaA(int *arr, int tam) {
    int suma = 0, *ptr = arr;
    for (int i = 0; i < tam; i++) {
        suma += *ptr;
        ptr++;
    }
    return suma;
}

void copiarArreglos(int *origen, int *destino, int tam) 
{
    for (int i = 0; i < tam; i++) 
    {
        destino[i] = origen[i];
    }
}

void concatenarArreglos(int *arr1, int *arr2, int *resultado, int tam1, int tam2) 
{
    for (int i = 0; i < tam1; i++) 
    {
        resultado[i] = arr1[i];
    }
    
    for (int i = 0; i < tam2; i++) 
    {
        resultado[tam1 + i] = arr2[i];
    }
}

int compararArreglos(int *arr1, int *arr2, int tam) 
{
    for (int i = 0; i < tam; i++) 
    {
        if (arr1[i] != arr2[i]) 
        {
            return 0; 
        }
    }
    return 1; 
}

void encontrarMaximo(int *arr, int tam) 
{
    int maximo = arr[0];
    for (int i = 1; i < tam; i++) 
    {
        if (arr[i] > maximo) 
        {
            maximo = arr[i];
        }
    }
    printf("El elemento máximo en el arreglo es: %d \n", maximo);
}