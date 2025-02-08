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
 /*
TrieNode *search_trie(TrieNode *root, const char *name) { //busca de um nome expecifico
    TrieNode *current = root;
    for (int i = 0; name[i] != '\0'; i++) {
        int index = name[i] - 'a';
        if (!current->children[index]) {
            return NULL; // Palavra não encontrada
        }
        current = current->children[index];
    }
    if(current != NULL && current->end)
        return current;
    return NULL;
}

//varredura e exibição das mensagens, no intervalo A-B, de todos os usuarios cadastrados
void *messages_from_all_users(TrieNode *root, long long int a, long long int b, const char *name, int *Qtd){
    TrieNode *current = root;

    char current_name[ASCII_SIZE] = ""; //criando array de char vazio 
    if(name){
        strcpy(current_name, name); //copiando a palavra
    }

    if(current->end){ //verifica se é um nodo final
        inorder_avl(current->root_avl, a, b, current_name, Qtd);
    }

    int index = 0;  //buscando o fim do array
    while (current_name[index] !='\0'){
        index ++;
    }

    for (int i = 0; i < ASCII_SIZE; i++) { //chama novamente a função para cada filho existente
       if(current->children[i] != NULL){
            current_name[index] =  i + 'a';
            current_name[index + 1] = '\0'; //define uum novo tamanho para a verificação dos filhos        
            messages_from_all_users(current->children[i], a, b, current_name, Qtd);
       }
    }
}

void free_trie(TrieNode *root){
    for (int i = 0; i < ASCII_SIZE; i++){
        if(root->children[i] != NULL){
            free_trie(root->children[i]);
        }
    }
    free_avl(root->root_avl);
    free(root);
}*/