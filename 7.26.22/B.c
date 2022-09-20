#include <stdio.h>
#include <time.h>
#include <windows.h>
struct{
	int carne;
	char nombre[20];
	char apellido[20];
	float nota;
}alumno;
int main(){
	//Asignación
	srand(time((NULL)));
	printf("Ingrese el carne: ");
	scanf("%d",&alumno.carne);
	printf("Ingrese Nombre: ");
	fflush(stdin);gets(alumno.nombre);
	strcpy(alumno.apellido,"Perez");
	alumno.nota=rand()%101;
	//Impresión
	printf("\nCarne: %d", alumno.carne);
	printf("\nEstudiante: %s %s", alumno.nombre, alumno.apellido);
	printf("\nNota: %.2f", alumno.nota);
    return 0;
}