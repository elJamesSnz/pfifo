
/*
    switch(cuad){

         se verifica desde qué cuadrante se pide
        case 1:
            //sum = sum + matrizA[i][k]*matrizB[k][j];
            //printf("leo consume\n");
            if(read(fd, arrIndex, sizeof(int) * 3) == -1){
                return 3;
            }
            //arrindex = {i,j,k}
            values[0] = matrizA[arrIndex[0]][arrIndex[2]];
            values[1] = matrizA[arrIndex[2]][arrIndex[1]];
            if(write(fd, values, sizeof(int) * 2) == -1){
                return 4;
            }
        break;
        case 2:

        break;

        case 3:

        break;

        case 4:

        break;
        
    }

    /*
        int alocate(int fd, int cont, int cuad){

    int res = 0;

    switch(cuad){

        /* se verifica desde qué cuadrante se pide
        case 1:
            
        break;
        case 2:

        break;

        case 3:

        break;

        case 4:

        break;

    }

}
*/
        


                    /*
                    int arrIndex [3];
                    arrIndex[0] = i;
                    arrIndex[1] = j;
                    arrIndex[2] = sum;

                    if(write(fd1, arrIndex, sizeof(int) * 3) == -1){
                        return 5;
                    }
                    alocate(fd1, val, 1);                        
                    */





/*
if(id == 0){
        if(id2 == 0){

            
            
            //Cuadrante 1
            for (int i = 0; i < VALOR/2; i++)
            {
                printf("c1");
                //handler();
                for (int j = VALOR/2; j < VALOR; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                        
                    }                    
                   // printf("\t%d", sum);
                    sum = 0;                                                                        
                }
                //printf("\n"); 
            }    
        }
        else{
            handler();
            //Cuadrante 2
            for (int i = 0; i < VALOR/2; i++)
            {
                for (int j = 0; j < VALOR/2; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                    }                    
                    //printf("\t%d", sum);
                    sum = 0;       
                                 
                }
                //printf("\n");
            }            
        }
    }
    else{
        handler();
        if(id2 == 0){
            //Cuadrante 3
            for (int i = VALOR/2; i < VALOR; i++)
            {
                for (int j = 0; j < VALOR/2; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                    }                    
                   // printf("\t%d", sum);
                    sum = 0;       

                }
               // printf("\n");
            }                       
        }        
        else{
            handler();
             //Cuadrante 4
            for (int i = VALOR/2; i < VALOR; i++)
            {
                for (int j = VALOR/2; j < VALOR; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                    }                    
                 //   printf("\t%d", sum);
                    sum = 0;                     
                }
                //printf("\n");
            }
        }
    }

*/


/*
void handler(int fd, int cuad, int cont, int sol){

    //valor: valor del arreglo puesto por usuario
    //cont: cuántos números le han pasado ya por calcular
    //fd: archivo para pasarle el índice a calcular
    //cuad: cuadrante solicitante
    //sol: 1 si es resultado, 0 si es pedir valores

    /* está pidiendo valores 
    if(sol == 0){
        consume(fd, cont, cuad);
    }
    /* está mandando resultado
    else if(sol == 1){
        alocate(fd, cont, cuad);        
    }    
}

*/