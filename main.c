#include "include/list.h"

int main(){
    int M = 2; //colunas 
    int N = 2; //linhas
    char line[201] = "";
    
    printf("\n");

    scanf("%d %d",&N ,&M); //definindo o tamanho da matriz N x M
    
    char **matrix = (char**)malloc(N *sizeof(char*)); //criando a matriz "labirinto"
    int **matrix_number = (int**)malloc(N *sizeof(int*)); // criando a matriz de numeros  
    for(int i=0; i<N; i++){
        matrix[i] = (char*)malloc(M *sizeof(char));
        matrix_number[i] = (int*)malloc(M *sizeof(int));
    }
    
    getchar();// limpando buffer 

    for(int i=0; i<N; i++){// leitura das linhas
        fgets(line, sizeof(line), stdin);
        char *token = strtok(line, " ");
        for(int z=0; token != NULL && z<M; z++){
            matrix[i][z] = token[0];
            token = strtok(NULL, " ");
        }
    }

    int size = N*M; //quantidade de elementos na matriz
    ListNode **root = (ListNode**)malloc(size *sizeof(ListNode*)); //criando lista de adjacência
    for(int i=0; i<size; i++){
        root[i] = NULL; 
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int aux = i*M + j; //posição do elemento atual no array
            if(matrix[i][j] == '.'){
                if(j+1 < M && matrix[i][j+1] == '.'){ //verificando lado direito do elemento atual
                    root[aux] = insert_List(root[aux], aux+1); 
                }
                if(i+1 < N && matrix[i+1][j] == '.'){//verificando a baixo do elemento atual
                    root[aux] = insert_List(root[aux], aux+M); 
                }
                if(j-1 >= 0 && matrix[i][j-1] == '.'){//verificando lado esquerdo do elemento atual
                    root[aux] = insert_List(root[aux], aux-1); 
                }
                if(i-1 >= 0 && matrix[i-1][j] == '.'){//verificando a cima do elemento atual
                    root[aux] = insert_List(root[aux], aux-M); 
                }
            }
        }
    }

    for(int i=0; i<N; i++){ //enumerando os elementos da matriz
        for(int j=0; j<M; j++){
            matrix_number[i][j] = i*M + j;
        }
    }
    /*
    printf("\n a matriz: \n\n");

    for(int i=0; i<N; i++){ //exibição da matriz
        for(int z=0; z<M; z++){
            printf("%c ", matrix[i][z]);
        }
        printf("\n");
    }
    */

    /*
    printf("a lista: \n\n");

    for(int i=0; i<size; i++) {//exibição da lista de adjacência 
        printf("%d-> ", i);
        ListNode *current = root[i];
        while (current != NULL) {
            printf("%d-> ",current->value);
            current = current->prox;
        }
        printf("NULL \n");
    }
    */

    int pathSize;
    int *path = DFS(root, 0, size - 1, size, &pathSize);

    /*
    if(path != NULL){ // exibição do array com o caminho
        printf("\nDFS Path: ");
        for (int i=0; i<pathSize; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    */
    
    for(int i=0; i<N; i++){ //insere o caminho na matriz
        for(int j=0; j<M; j++){
            if(search(path,size, matrix_number[i][j])){
                matrix[i][j] = 'x';
            }
        }
    }

    for(int i=0; i<N; i++){ //exibição da matriz
        for(int z=0; z<M; z++){
            printf("%c ", matrix[i][z]);
        }
        printf("\n");
    }

    for(int i=0; i<N; i++){ //liberando as matrizes
        free(matrix[i]);
        free(matrix_number[i]);
    }

    for(int i=0; i<size; i++){ //liberando a lista de adjacência
        ListNode *current = root[i];
        while (current != NULL) {
            ListNode *temp = current;
            current = current->prox;
            free(temp);
        }
    }
    free(root);
    free(path);

    return 0;
}