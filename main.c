#include "include/list.h"

int main(){
    int M = 2; //colunas 
    int N = 2; //linhas
    char line[201] = "";
    
    printf("\n");

    scanf("%d %d",&N ,&M); //definindo o tamanho da matriz N x M
    
    char** headquarters = (char**)malloc(N* sizeof(char*)); //criando a matriz  
    for(int i=0; i<N; i++){
        headquarters[i] = (char*)malloc(M* sizeof(char));
    }
    
    getchar();// limpando buffer 

    for(int i=0; i<N; i++){// leitura das linhas
        fgets(line, sizeof(line), stdin);
        char* token = strtok(line, " ");
        for(int z=0; token != NULL && z<M; z++){
            headquarters[i][z] = token[0];
            token = strtok(NULL, " ");
        }
    }

    int size = N*M;
    ListNode **root = (ListNode**)malloc(size *sizeof(ListNode*)); 
    for(int i=0; i<size; i++){
        root[i] = NULL; 
    }

    /*for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int aux = i*M + j; //posição do elemento atual no array
            if(j+1 < M && headquarters[i][j+1] == '.'){ //verificando lado direito do elemento atual
                root[aux] = insert_List(root[aux], aux+1); 
            }

            if(i+1 < N && headquarters[i+1][j] == '.'){//verificando a baixo do elemento atual
                root[aux] = insert_List(root[aux], aux+M); 
            }

            if(j-1 >= 0 && headquarters[i][j-1] == '.'){//verificando lado esquerdo do elemento atual
                root[aux] = insert_List(root[aux], aux-1); 
            }

            if(i+1 >= 0 && headquarters[i-1][j] == '.'){//verificando a cima do elemento atual
                root[aux] = insert_List(root[aux], aux-M); 
            }
        }
    }*/

    printf("\n a matriz: \n\n");

    for(int i=0; i<N; i++){ //exibição da matriz
        for(int z=0; z<M; z++){
            printf("%c ", headquarters[i][z]);
        }
        printf("\n");
    }
    
    for(int i=0; i<N; i++){ //liberando a matriz
        free(headquarters[i]);
    }

    for (int i=0; i<size; i++) {
        ListNode *current = root[i];
        while (current != NULL) {
            ListNode *temp = current;
            current = current->prox;
            free(temp);
        }
    }
    free(root);

    return 0;
}