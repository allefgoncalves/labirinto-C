#ifndef list_H
#define list_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct ListNode{
    struct ListNode *prox;
    int value;
}ListNode;

ListNode *create_node(int number);//cria um nó
ListNode *insert_List(ListNode *root, int number);  //inserir um nó 
int* DFS(ListNode **root, int start, int target, int size, int *pathSize);
bool search(int *list, int size, int number);
void DFS_AUX(
    ListNode **root, 
    int current, 
    int target, 
    bool *visited, 
    int *path, 
    int *index, 
    bool *found
);
void BFS(ListNode **root, int start, int size, int *parent);// não é uma lista é uma fila!

#endif