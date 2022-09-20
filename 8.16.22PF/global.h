#ifndef GLOBAL_H_
#define GLOBAL_H_
#define KU 72
#define KD 80
#define KL 75
#define KR 77

int grid[3][3], dif, points;
typedef struct{
    int d, m, y;
} fecha;

typedef struct{
    char nombre[20];
    int Id, puntos, partidas[4];
    fecha Ingreso;
} jugador;

jugador list[2];

#endif