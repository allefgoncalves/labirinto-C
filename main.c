#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N = 2;
    int M = 2;
    char line[201] = "";

    scanf("%d %d",&N ,&M); //definindo o tamanho da matriz NxM
    
    char** headquarters = (char**)malloc(N* sizeof(char)); //criando a matriz  
    for(int i=0; i<N; i++){
        headquarters[i] = (char*)malloc(M* sizeof(char));
    }

    for(int i=0; i<N; i++){// leitura das linhas
        getchar();
        fgets(line, sizeof(line), stdin);
        char* token = strtok(line, " ");
        for(int z=0; token != NULL && z<M; z++){
            headquarters[i][z] = token[0];
            token = strtok(NULL, " ");
        }
    }

    for(int i=0; i<N; i++){ //exibição da matriz
        for(int z=0; z<M; z++){
            printf("%s", headquarters[i][z]);
        }
    }
    
    for(int i=0; i<M; i++){ //liberandoa a matriz
        free(headquarters[i]);
    }

    return 0;
}