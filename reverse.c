#include <stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int** nbynImatrix();
int** enterMatrix();
void reverseMat();

int n = 0;
int **Imatarr;
int **inputMatarr;

int main(){
    Imatarr = nbynImatrix();
    printf("%d, %d, %d, %d \n",Imatarr[0][0], Imatarr[0][1], Imatarr[1][0], Imatarr[1][1]); //testing
    inputMatarr = enterMatrix();
    printf("%d, %d, %d, %d \n",inputMatarr[0][0], inputMatarr[0][1], inputMatarr[1][0], inputMatarr[1][1]); //testing
    reverseMat(inputMatarr,Imatarr,n);
    //free arrs_should do because of err.
    free(Imatarr);
    free(inputMatarr);
    return 0;
}

int** nbynImatrix(){ //Function that makes I_matrix
    printf("Reverse Calculator of n by n matrix\n");
    printf("n = ? (1 < n < 5)\n");
    scanf("%d",&n);
    if(n < 2 || n > 4){
        printf("unsuitable number.");
        exit(0);
    }
    int** Imatrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) { 
        Imatrix[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            if(i==j){
                Imatrix[i][j] = 1;
            }
            else{
                Imatrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Imatrix[i][j]);
        }
        printf("\n");
    }
    return Imatrix;
}

int** enterMatrix(){ //Input n*n Matrix & Investigate that det == 0 or not
    int num = 0;
    int det = 0;
    printf("enter %d by %d Matrix\n",n, n);

    int** Inputmatrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) { 
        Inputmatrix[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            printf("enter [%d][%d] ", i + 1, j + 1);
            scanf("%d",&num);
            Inputmatrix[i][j] = num;
        }
    }

    if(n == 2){
        det = Inputmatrix[0][0] * Inputmatrix[1][1] - Inputmatrix[0][1] * Inputmatrix[1][0];
    }
    if(n == 3){
        det = Inputmatrix[0][0] * (Inputmatrix[1][1] * Inputmatrix[2][2] - Inputmatrix[1][2] * Inputmatrix[2][1])
        - Inputmatrix[0][1] * (Inputmatrix[1][0] * Inputmatrix[2][2] - Inputmatrix[1][2] * Inputmatrix[2][0])
        + Inputmatrix[0][2] * (Inputmatrix[1][0] * Inputmatrix[2][1] - Inputmatrix[1][1] * Inputmatrix[2][0]);
    }

    if(det == 0){ // if det == 0, there is no reversed matrix
        printf("Can't be reversed!!");
    }
    
    printf("det = %d\n",det);//testing
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
    return Inputmatrix;
}

void reverseMat(int** Inputmatrix, int** Imatrix, int n){ //아직 안돌아감, 계산이 안됨
    int row = 0;
    int col = 0;

<<<<<<< Updated upstream
    if(Inputmatrix[0][0] != 1){
        for(int i = 0; i < n; i++){  
        Inputmatrix[0][i] = Inputmatrix[0][i] / Inputmatrix[0][0];
        Imatrix[0][i] = Imatrix[0][i] / Inputmatrix[0][0];
        }
    }
=======
        for(int b = 0; b < n; b++){

            if(Inputmatrix[b][b] != 1){

                if(Inputmatrix[b][b] == 0){
                    for(int i = 0; i < n; i++){
                        if(b == 0){
                            float k = Inputmatrix[b+1][i];
                            Inputmatrix[b][i] = Inputmatrix[b][i] + k;
                            Imatrix[b][i] = Imatrix[b][i] + k;
                        }
                        else{
                            float k = Inputmatrix[b-1][i];
                            Inputmatrix[b][i] = Inputmatrix[b][i] + k;
                            Imatrix[b][i] = Imatrix[b][i] + k;
                        }
                    }
                }
                
                float k = Inputmatrix[b][b];

                for(int i = 0; i < n; i++){
                    Inputmatrix[b][i] = Inputmatrix[b][i] / k;
                    Imatrix[b][i] = Imatrix[b][i] / k;
                }
            }
        }
    }
    printf("\nfunc_divi_testing\n");
    for(int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.3f   ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void reverseMat(float** Inputmatrix, float** Imatrix, int n){ //아직 안돌아감, 계산이 안됨
>>>>>>> Stashed changes

    for(int i = 1; i < n; i++){

<<<<<<< Updated upstream
        if(Inputmatrix[i][0] != 0){
        int k = Inputmatrix[i][0];

            for(int j = 0; j < n; j++){
                Inputmatrix[i][j] -= Inputmatrix[i-1][j] * k;
                Imatrix[i][j] -= Imatrix[i-1][j] * k;
=======
    for(int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %.3f   ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }
//top_bottom
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n-1; i++){
            float k = 0;
            k = (1 / Inputmatrix[i+1][j]);
            for(int l = 0; l < n; l++){
                Inputmatrix[i+1][l] = k * Inputmatrix[i+1][l] - Inputmatrix[j][l];
                Imatrix[i+1][l] = k * Imatrix[i+1][l] - Imatrix[j][l];
>>>>>>> Stashed changes
            }
            divi(Inputmatrix,Imatrix);
        }
    }
<<<<<<< Updated upstream
=======
//bottom_top
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            float k = 0;
            k = Inputmatrix[i][j];
            for(int l = 0; l < n; l++){
                Inputmatrix[i][l] = Inputmatrix[i][l] - k * Inputmatrix[j+1][l];
                Imatrix[i][l] = Imatrix[i][l] - k * Imatrix[j+1][l];
            }
        }
    }
>>>>>>> Stashed changes

    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Inputmatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < n; i++) { //testing
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] : %d   ", i+1, j+1, Imatrix[i][j]);
        }
        printf("\n");
    }
}