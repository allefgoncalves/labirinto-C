#ifndef list_H
#define list_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
    struct ListNode *prox;
    int value;
}ListNode;

ListNode *create_node(int number);//cria um nó
void insert_list(ListNode *root, const char *name,int key, char *chuiter);  //inserir um nó 
ListNode *search_List(ListNode *root, const char *name); //busca de usuario
void *messages_from_all_users(ListNode *root, long long int a, long long int b, const char *name, int *Qtd); //exibe as mensagens de todos os usuarios em um intervalo A-B
void free_List(ListNode *root);                     //libera o espaço de memoria


#endif