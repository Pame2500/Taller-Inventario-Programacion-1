#include <stdio.h>

int main() {
    char nombres[10][20] = {{0}}, buscado[20] = {0};
    float precios[10], total, promedio, mayor, menor;
    int cantidad, i, j, opcion, encontrado, iguales;
    int precioMayor = 0;
    int precioMenor = 0;

    printf("SISTEMA DE INVENTARIO\n");

    do {
        printf("Ingrese la cantidad de productos (1 a 10): ");
        scanf("%d", &cantidad);
        if (cantidad < 1 || cantidad > 10) {
            printf("Debe ingresar entre 1 y 10 productos.\n");
        }
    } while (cantidad < 1 || cantidad > 10);

    for (i = 0; i < cantidad; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre (sin espacios): ");
        scanf("%19s", nombres[i]);
        do {
            printf("Precio : $ ");
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("El precio no puede ser negativo.\n");
            }
        } while (precios[i] < 0);
    }

    do {
        printf("\nSeleccione una opcion:\n");
        printf("1. Calcular total del inventario\n");
        printf("2. Encontrar producto mas caro y mas barato\n");
        printf("3. Calcular precio promedio\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Mostrar productos\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                total = 0;
                for (i = 0; i < cantidad; i++) {
                    total = total + precios[i];
                }
                printf("Precio total: $%f\n", total);
                break;

            case 2:
                mayor = precios[0];
                menor = precios[0];
                precioMayor = 0;
                precioMenor = 0;
                for (i = 1; i < cantidad; i++) {
                    if (precios[i] > mayor) {
                        mayor = precios[i];
                        precioMayor = i;
                    }
                    if (precios[i] < menor) {
                        menor = precios[i];
                        precioMenor = i;
                    }
                }
                printf("Mas caro: %s - $%f\n", nombres[precioMayor], mayor);
                printf("Mas barato: %s - $%f\n", nombres[precioMenor], menor);
                break;

            case 3:
                total = 0;
                for (i = 0; i < cantidad; i++) {
                    total = total + precios[i];
                }
                promedio = total / cantidad;
                printf("Precio promedio: $%f\n", promedio);
                break;

            case 4:
                // Antes de cada busqueda, se limpia el arreglo buscado.
                for (j = 0; j < 20; j++) {
                    buscado[j] = 0;
                }
                printf("Ingrese el nombre a buscar (sin espacios): ");
                scanf("%19s", buscado);
                encontrado = 0;

                for (i = 0; i < cantidad; i++) {
                    iguales = 1;
                    // Compara las 20 posiciones de ambos arreglos de letras.
                    for (j = 0; j < 20; j++) {
                        if (nombres[i][j] != buscado[j]) {
                            iguales = 0;
                            break;
                        }
                    }
                    if (iguales == 1) {
                        printf("Producto encontrado: %s - $%f\n", nombres[i], precios[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado == 0) {
                    printf("Producto no encontrado.\n");
                }
                break;

            case 5:
                printf("\nLISTA DE PRODUCTOS\n");
                for (i = 0; i < cantidad; i++) {
                    printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
                }
                break;

            case 6:
                printf("Programa finalizado.\n");
                break;

            default:
                printf("No existe la opcion.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
