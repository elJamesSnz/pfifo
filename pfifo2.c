#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


#define PROCESS_NUM 3
#define SIZE 20
int matrizA[SIZE][SIZE], matrizB[SIZE][SIZE];int matrizC[SIZE][SIZE];
int val_main = 0;

/* llenar la matriz con 0s y 1s*/
void llenarM(int val){

    //val_main = val;

    for (int i = 0; i < val; i++)
    {
        
        for (int j = 0; j < val; j++)
        {
            matrizA[i][j] = 1;
            matrizB[i][j] = 1;
        }                      
    }

    for (int i = 0; i < SIZE; i++)
    {
        
        for (int j = 0; j < SIZE; j++)
        {
            if(matrizA[i][j] != 1){
                matrizA[i][j] = 0;
            }

            if(matrizB[i][j] != 1){
                matrizB[i][j] = 0;
            }                       
        }
    }

}


int consume(int fd, int cont, int cuad){

    /* arreglo con los dos valores a multiplciar */
    int arr[2];
    int piv1 = 0;
    int piv2 = 0;
    int arrIndex[3];
    int values[2];


    if(read(fd, arrIndex, sizeof(int) * 3) == -1){
        return 3;
    }
    //arrindex = {i,j,k}
    values[0] = matrizA[arrIndex[0]][arrIndex[2]];
    values[1] = matrizA[arrIndex[2]][arrIndex[1]];
    if(write(fd, values, sizeof(int) * 2) == -1){
        return 4;
    }

}




int main(int argc, char* argv[]){
    int id = 0;
    int id2 = 0;
    if (argv[1] == NULL){        
        printf("Modo de ejcucion ./archivo tamanio_Arreglo\nEjemplo ./fifo 6\n");
        return 1; 
    }
    //array de cuanto x cuanto es la matriz
    int VALOR = 1;
    VALOR = atoi(argv[1]);
    //se rellena la matriz
    llenarM(VALOR);
    /* para indicar que puede verse y escribirse por cualquiera*/
    if(mkfifo("1", 0777) == -1){        
        /*fifo existe ya y no se crea*/
        if(errno != EEXIST){
            printf("No se pudo crear archivo");
            return 1;
        }        
    }
    mkfifo("2", 0777);
    mkfifo("3", 0777);
    mkfifo("4", 0777);

    int fd1 = open("1", O_RDWR);
    int fd2 = open("2", O_RDWR);
    int fd3 = open("3", O_RDWR);
    int fd4 = open("4", O_RDWR);
    
    
    id = fork();
    //id toma un valor y toma un 0
    id2 = fork();    

    int sum = 0;
    int val = 0;
    int a=0, b=0, c=0,d=0, cuad = 0;
    if(id == 0){
        if(id2 == 0){                        
            //cuadrante 1
            a = 0; b = VALOR/2; c=VALOR/2; d=VALOR; cuad = 1;
        }
        else{            
            //cuadrante 2   
            a = 0; b = VALOR/2; c=0; d=VALOR/2; cuad = 2;                    
        }
    }
    else{
        if(id2 == 0){
            //Cuadrante 3   
            a = VALOR/2; b = VALOR; c=0; d=VALOR/2; cuad = 3;                
        }        
        else{
             //Cuadrante 4      
             a = VALOR/2; b = VALOR; c=VALOR/2; d=VALOR; cuad = 4;                        
        }
    }

    for (int i = a; i < b; i++){                
        for (int j = c; j < d; j++)
        {
            
            for (int k = 0; k < VALOR; k++){
                val++; 
                int arrIndex [3];
                arrIndex[0] = i;
                arrIndex[1] = j;
                arrIndex[2] = k;

                //sum = sum + matrizA[i][k]*matrizB[k][j];
                //printf("escribo fork\n");
                if(write(fd1, arrIndex, sizeof(int) * 3) == -1){
                    return 2;
                }
                consume(fd1, val, 1);                                          
                
                int values[2];
                if(read(fd1, values, sizeof(int) * 2) == -1){
                    return 2;
                }

                sum = sum + (values[0] * values[1]);                                                
            }
            printf("%d(%d) ", sum, cuad);
            sum = 0;                                                                        
        }
        printf("\n");
    }          



    close(fd1);
    unlink("1");

    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    

    /*

    // retorna el file descriptor
    

    //Si se abre un fifo para escribir con open, se bloquea 
    //hasta que se abra un open en modo leer (otro proceso o hilo)
    //
    //int x = 9;

    // -1 si da error de escritura
    //if(write(fd, &x, sizeof(x) == -1)){
      //  return 2;        
    //}
    close(fd);
    
    */
    return 0;
}

