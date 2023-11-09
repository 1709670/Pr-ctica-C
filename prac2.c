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
	srand(4422543);
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
		printf("%f  ", vect[i]);
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
		printf("%f  ", mat[row][i]);
	}
}

void MultEscalar( float vect[N], float vectres[N], float alfa ){
	
	printf("Escalar pel que multiplicar: ");
	scanf("%f", alfa);
	
	int i;
	for (i=0; i<N; i++){
		vectres[i]=vect[i]*alfa;
	}

	printf("Multiplicació del vector per %f:\n", alfa);
	
	for (i=0; i<N; i++){
		printf("%f  ", vectres[i]);
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

float Magnitude( float vect[N] ){
        float mult;
        float magnitud;

        mult=Scalar(vect, vect);

        magnitud=sqrt(mult);
        printf("La magnitud del vector és: %f\n", magnitud);

}

int Ortogonal( float vect1[N], float vect2[N] ){

        float mult;
        int ortogonals;

        mult=Scalar(vect1, vect2);
        if (mult==0)
                ortogonals=1;
        else
                ortogonals=0;

        return (ortogonals);

}

void Projection( float vect1[N], float vect2[N], float vectres[N] ){

        float mult;
        float escalar;

        mult=Scalar(vect1, vect2);
        escalar=mult/Magnitude(vect2);
        MultEscalar(vect2, vectres, escalar);

}

float Infininorm( float M[N][N] ){

        float max=0;
        int i,j;
        float fila;

        for (j=0; j<N; j++){
                fila=0;
                for (i=0; i<N; i++){
                        fila=fila + M[j][i];
                }
                if (fila>max){
                        max=fila;
                }
        }

        printf("%f", max);
}

float Onenorm( float M[N][N] ){

        float max=0;
        int i,j;
        float columna;

        for (j=0; j<N; j++){
                columna=0;
                for (i=0; i<N; i++){
                        columna=columna + M[i][j];
                }
                if (columna>max){
                        max=columna;
                }
        }

        printf("%f", max);

}

float NormFrobenius( float M[N][N] ){
	
	int i, j;
	float suma=0;
	float Frob;

	for (j=0; j<N; j++){
		for (i=0; i<N; i++){
			suma=suma+pow(M[j][i], 2);
		}
	}
	
	Frob=pow(suma, 1/2);

	printf("La norma de Frobenius és: %f\n", Frob);

}

int DiagonalDom( float M[N][N] ){
	
	int i,j,k;
	int diagonal=1;
	float fila=0;

	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			fila=fila+abs(M[i][j]);
		}
		if (abs(M[i][j]) <= fila){
			diagonal=1;
		}else{
			diagonal=0;
		}
		
	}

	return (diagonal);

	printf("%d", diagonal);
}

int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){
	int i,j,x,k,resultat;
	float suma=0;
	int diagonal;

	diagonal=DiagonalDom(M);
		if (diagonal==1){
		        for (k=0; k<iter; k++) {
			         for (i = 0; i < N; i++) {
				           for (j = 0; j < N; j++) {
					             if (j != i) {
						            suma += M[i][j] * vect[j];
						     }
					    }
				}
				vectres[i] = (vect[i] - suma) / M[i][i];
			}
		resultat=1;
		}else{
		       resultat=0;
		}
	for (x=0; x<N; x++){
                printf("%f  ", vectres[x]);
        }

	return (resultat);
}

int main(){
	InitData();
	int a=0,b=0, c=0;
	float s=0, V0[N];
	
	PrintVect(V1, a, b);
	printf("\n");

        PrintRow(Mat, a, b, c);
        printf(" \n");

        MultEscalar(V1, V0, s);
        printf("\n");

        Scalar(V1, V3);
        printf("\n");

        Magnitude(V1);
        printf("\n");

        printf("Els vectors són ortogonals: %d\n", Ortogonal(V1, V2));
        printf("\n");

        Projection(V1, V2, V0);
        printf("\n");

        printf("Màxima suma dels valors per files: ");
        Infininorm(Mat);
	printf("\n");

	Onenorm(Mat);
	printf("\n");

	NormFrobenius(Mat);
	printf("\n");



}
