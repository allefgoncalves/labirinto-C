#include  "../include/list.h"

ListNode *create_node(int number){  //criaçao do nó
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if(node){
        node-> value = number;
        node-> prox = NULL;
        return node;
    }
    return NULL;
} 

ListNode *insert_List(ListNode *root, int number){//inserção na lista
    if(root == NULL){
        return create_node(number);
    }

    ListNode *current = root;
    while (current->prox != NULL){
        current = current->prox;
    }
    current->prox = create_node(number);
    return root;
}

bool search(int *list, int size, int number){
    if(list == NULL || size == 0) {
        return false;
    }

    for(int i=0; i<size; i++){
        if(list[i] == number){
            return true;
        }
    }

    return false;
}

void DFS_AUX(
    ListNode **root, 
    int current, 
    int target, 
    bool *visited, 
    int *path, 
    int *index, 
    bool *found){

    if(*found){
        return;
    } 
        
    visited[current] = true;
    path[(*index)++] = current;

    if(current == target){  
        *found = true;
        return;
    }

    ListNode *neighbor = root[current];
    while(neighbor != NULL && !(*found)){
        if(!visited[neighbor->value]){
            DFS_AUX(root, neighbor->value, target, visited, path, index, found);
        }
        neighbor = neighbor->prox;
    }

    if(!(*found)){
        (*index)--;
    }  
}

int* DFS(ListNode **root, int start, int target, int size, int *pathSize){
    bool *visited = (bool*)calloc(size, sizeof(bool)); 
    int *path = (int*)malloc(size * sizeof(int)); 
    int index = 0;
    bool found = false; 

    DFS_AUX(root, start, target, visited, path, &index, &found);
    free(visited);

    if(!found){
        free(path);
        return NULL;
    }

    *pathSize = index;
    return path;
}

void BFS(ListNode **root, int start, int size, int *parent){
    bool *visited = (bool*)malloc(size *sizeof(bool));
    for(int i=0; i<size; i++){
        visited[i] = false;
        parent[i] = -1;
    }

    visited[start] = true;
    parent[start] = -1;

    int *queue = (int*)malloc(size *sizeof(int));// criando a fila
    int front = 0; 
    int rear = 0;
    queue[rear++] = start;

    while (front<rear){
        int current = queue[front++];
        
        ListNode *currentNode = root[current];
        while (currentNode != NULL){
            int neighbor = currentNode->value;
            if(!visited[neighbor]){
                visited[neighbor] = true;
                parent[neighbor] = current;
                queue[rear++] = neighbor;
            }
            currentNode = currentNode->prox;
        }
    }
    
    free(visited);
    free(queue);
}
