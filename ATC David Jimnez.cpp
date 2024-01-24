#include <cstdio>
#include <cstring>

struct datos {
    char nombre[40];
    char pais[25];
};

struct atletas_num {
    int num_medallas;
};

struct ATC {
    struct datos info;
    struct atletas_num medallas;
};

void ingresarDatos(ATC& atleta, int indice) {
    printf("Nombre del atleta %d: ", indice + 1);
    scanf("%s", atleta.info.nombre);

    printf("País del atleta %d: ", indice + 1);
    scanf("%s", atleta.info.pais);

    printf("Número de medallas del atleta %d: ", indice + 1);
    scanf("%d", &atleta.medallas.num_medallas);
}

void mostrarInformacion(const ATC& atleta) {
    printf("\nNombre: %s\n", atleta.info.nombre);
    printf("País: %s\n", atleta.info.pais);
    printf("Número de medallas: %d\n", atleta.medallas.num_medallas);
}

int main() {
    const int num_atletas = 3;
    ATC atletas[num_atletas];
    int opcion;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Ingresar datos de atletas\n");
        printf("2. Mostrar atleta con más medallas\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Opción no válida. Inténtelo de nuevo.\n");
            scanf("%*s");  // Limpiar el buffer si no se ingresa un número
            continue;
        }

        switch (opcion) {
            case 1:
                for (int i = 0; i < num_atletas; ++i) {
                    printf("\nIngresar datos del atleta %d:\n", i + 1);
                    ingresarDatos(atletas[i], i);
                }
                break;
            case 2: {
                int indice_max_medallas = 0;
                for (int i = 1; i < num_atletas; ++i) {
                    if (atletas[i].medallas.num_medallas > atletas[indice_max_medallas].medallas.num_medallas) {
                        indice_max_medallas = i;
                    }
                }
                printf("\nAtleta con más medallas:\n");
                mostrarInformacion(atletas[indice_max_medallas]);
                break;
            }
            case 3:
                printf("Saliendo del programa.\n");
                return 0;  // Terminar el programa
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }
    }

    return 0;
}