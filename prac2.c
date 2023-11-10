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
	printf("Elements de la matriu MatDD:\n");

	int i;
	int fin;
	fin=from+numel;

	for (i=from; i<fin; i++){
		printf("%f  ", mat[row][i]);
	}
}

void MultEscalar( float vect[N], float vectres[N], float alfa ){
	
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

float Magnitude( float vect[N] ){
        float mult;
        float magnitud;

        mult=Scalar(vect, vect);

        magnitud=sqrt(mult);
        
	return (magnitud);

}

int Ortogonal( float vect1[N], float vect2[N] ){

        float mult;
        int ortogonals;

        mult=Scalar(vect1, vect2);
        if (mult==0){
                ortogonals=1;
	}else{
                ortogonals=0;
	}

        return (ortogonals);

}

void Projection( float vect1[N], float vect2[N], float vectres[N] ){

        float mult, mag;
        float escalar;

        mult=Scalar(vect1, vect2);
	mag=Magnitude(vect2);
        escalar=mult/mag;
        MultEscalar(vect2, vectres, escalar);

}
               
float Infininorm( float M[N][N] ){
        int i;
        int j;
        float max;
        float sumafila;
        max=0;


        for( i=0;i<N; i++){
                sumafila=0;
                for( j=0; j<N; j++){
                        sumafila=sumafila+fabs(M[i][j]);
                        }
                if(sumafila>max){
                        max=sumafila;
                }
        }
        return max;
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
                if (columna>=max){
                        max=columna;
                }
        }
        return max;

}
float NormFrobenius( float M[N][N] ){

        int i, j;
        float suma=0;
        float Frob;

        for (j=0; j<N; j++){
                for (i=0; i<N; i++){
                        suma=suma+(M[j][i]*M[j][i]);
                }
        }

        Frob=sqrt(suma);
	return (Frob);

}

int DiagonalDom( float M[N][N] ){

        int i,j,k;
        int diagonal=0;
        

        for (i=0; i<N; i++){
                float fila=0;
		for (j=0; j<N; j++){
                        fila=fila+fabs(M[i][j]);
                }
                for (k=0; k<N; k++){
                        if (M[k][j]>=fila-fabs(M[k][j])){
                                diagonal=1;
                        }
                }
        }
        printf("És diagonal dominant? (1(Sí)/0(No)): ");
        printf("%d\n", diagonal);
        return (diagonal);
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
	float s=0, V0[N], res[N], res1, res2, res3;
	
	PrintVect(V3, 0, 1);
	printf("\n");

        PrintRow(MatDD, a, b, c);
        printf(" \n");

	MultEscalar(V3, V0, 2);
        printf("Multiplicació de V3 per l'escalar 2:\n");

	printf("Elements resultants (0-9):\n");
	PrintVect(V0, 0, 9);
	printf("\n");

	printf("Elements resultants (256-265):\n");
	PrintVect(V0, 256, 9);
	printf("\n");
        
	res1=Scalar(V1, V2);
	printf("Multiplicació escalar entre V1 i V2: %f\n", res1);
        
	res2=Scalar(V1, V3);
	printf("Multiplicació escalar entre V1 i V3: %f\n", res2);
        
	res3=Scalar(V2,V3);
	printf("Multiplicació escalar entre V2 i V3: %f\n", res3);
	printf("\n");

        printf("Magnituts dels vectors V1, V2 i V3, respectivament:\n");
	printf("%f", Magnitude(V1));
	printf("\n");
	printf("%f", Magnitude(V2));
	printf("\n");
	printf("%f", Magnitude(V3));
        printf("\n\n");
	
	if (Ortogonal(V1, V2)==1){
		printf("Els vectors V1 i V2 són ortogonals\n");
	}else{
		printf("Els vectors V1 i V2 no són ortogonals\n");
	}

	if (Ortogonal(V1, V2)==1){
                printf("Els vectors V1 i V3 són ortogonals\n");
        }else{
                printf("Els vectors V1 i V3 no són ortogonals\n");
        }

	if (Ortogonal(V1, V2)==1){
                printf("Els vectors V2 i V3 són ortogonals\n");
        }else{
                printf("Els vectors V2 i V3 no són ortogonals\n");
        }

        printf("\n");
	
	float VP[N];

	printf("Projecció de V1 sobre V2 (elements 0-9):\n");
	Projection(V1,V2,VP);
	PrintVect(VP, 0, 10);
	printf("\n");

	float VX[N];

	printf("Projecció de V2 sobre V3 (elements 0-9):\n");
        Projection(V2,V3,VX);
        PrintVect(VX, 0, 10);
	printf("\n\n");


	printf("Infininorma de Mat: %f", Infininorm(Mat));
	printf("\n");
	printf("Infininorm de MatDD: %f\n", Infininorm(MatDD));
    
	printf("\n");

	printf("Norma ú de Mat: %f\n", Onenorm(Mat));
	printf("Norma ú de MatDD: %f\n", Onenorm(MatDD));
	
	printf("\n");

	printf("Norma de Frobenius de la matriu Mat: %f\n", NormFrobenius(Mat));
	printf("Norma de Frobenius de la matriu MatDD: %f\n", NormFrobenius(MatDD));
	printf("\n");

	if (DiagonalDom(Mat)==1){
		printf("La matriu Mat és diagonal dominant\n");
	}else{
		printf("La matriu Mat no és diagonal dominant\n");
	}

	if (DiagonalDom(MatDD)==1){
                printf("La matriu MatDD és diagonal dominant\n");
        }else{
                printf("La matriu MatDD no és diagonal dominant\n");
	}




	printf("\n");



}
