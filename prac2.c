#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 512
float Mat[N][N];
float MatDD[N][N];
float V1[N];
float V2[N];
float V3[N];
float V4[N];

void InitData(){
	int i,j;
	srand(8824553);
	for( i = 0; i < N; i++ )
		for( j = 0; j < N; j++ ){
			Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
			if ( (abs(i - j) <= 3) && (i != j))
				MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
			else if ( i == j )
				MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
			else MatDD[i][j] = 0.0;
			}
	for( i = 0; i < N; i++ ){
		V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
		V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
	}
}

void PrintVect( float vect[N], int from, int numel ){

	printf("Posició inicial: \n");
	scanf("%d", &from);
	printf("Nombre d'elements: \n");
	scanf("%d", &numel);
	printf("Elements del vector:\n");

	int i;
	int fin;
	fin=from+numel;

	for (i=from; i<fin; i++){
		printf("%f\n", vect[i]);
	}
}

void PrintRow( float mat[N][N], int row, int from, int numel ){
	
	printf("Número de fila:");
	scanf("%d", &row);
	printf("Posició inicial: \n");
        scanf("%d", &from);
        printf("Nombre d'elements: \n");
        scanf("%d", &numel);
	printf("Elements de la matriu:\n");

	int i;
	int fin;
	fin=from+numel;

	for (i=from; i<fin; i++){
		printf("%f\n", mat[row][i]);
	}
}

void MultEscalar( float vect[N], float vectres[N], float alfa ){
	
	printf("Escalar pel que multiplicar: ");
	scanf("%f", alfa);
	
	int i;
	for (i=0; i<N; i++){
		vectres[i]=vect[i]*alfa;
	}
}

float Scalar( float vect1[N], float vect2[N] ){
        int i;
        float res=0;
        for (i=0; i<N; i++){
                res=res+(vect1[i]*vect2[i]);
        }
        return (res);

        printf("Resultat multiplicació escalar: %f\n", res);
}


int main(){
	InitData();
	int a=0,b=0, c=0;
	float s=0, V0[N];
	PrintVect(V1, a, b);
	PrintRow(Mat, a, b, c);
	MultEscalar(V1, V0, s);

}
