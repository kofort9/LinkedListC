// list/list.c
// 
// Implementation for linked list.
//
// <Kofi Fort>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t* list_alloc() {
   
    list_t* linked_list = malloc(sizeof(list_t*)); 
    linked_list->head = malloc(sizeof(node_t));
   return linked_list; 
}
void list_free(list_t *l) {
   free(l);
}

void list_print(list_t *l) {
    node_t* currnode;
    currnode = malloc(sizeof(node_t));
    currnode->next = malloc(sizeof(node_t));
    currnode = l->head;
    int count = 1;
    
    while(currnode != NULL){
        printf("%d.  ", count);
        printf("%d \n", currnode->value);
        
        count++;
        currnode = currnode->next;
    }
    
}
int list_length(list_t *l) {
    int count;
    node_t* currnode = l->head;
    while(currnode != NULL){
        count++;
        currnode = currnode->next;
    }
    return count; 
}

void list_add_to_back(list_t *l, elem value) { 
    node_t* currnode = l->head;
    node_t* newnode;
    newnode = malloc(sizeof(node_t));
    newnode->value = value;
    newnode->next = NULL;
    
    while(currnode->next != NULL){
        currnode = currnode->next;
     }
        currnode->next = malloc(sizeof(node_t));
        currnode->next = newnode;
        printf("Added Node with value: %d \n", currnode->next->value);
       
}
void list_add_to_front(list_t *l, elem value) {
    node_t* newnode;
    newnode = malloc(sizeof(node_t));
    newnode->value = value;
    
    if (l->head == NULL){
        l->head = newnode;
    } else {
       node_t* temp = l->head;
        l->head = newnode;
        l->head->next = temp;
    }
    
    printf("Added Node with value to front: %d \n", l->head->value);
    
}
void list_add_at_index(list_t *l, elem value, int index) {
    node_t* newnode;
    newnode = malloc(sizeof(node_t));
    newnode->value = value;
    node_t* temp = l->head;
    int count = 0;
    while(temp->next != NULL){
        if (count+1 == index){
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        count++;
        temp = temp->next;
    } 
}

elem list_remove_from_back(list_t *l) { 
    node_t* currnode = l->head;
    int popvalue = 0;
 
     if (l->head->next == NULL) {
        popvalue = l->head->value;
        free(l->head);
        return popvalue;
    }
 
    while(currnode->next->next != NULL){
        currnode = currnode->next;
    }
    popvalue = currnode->next->value;
    free(currnode->next);
    currnode->next = NULL;
    return popvalue;           
}

elem list_remove_from_front(list_t *l) { 
    node_t* removenode = l->head;
    l->head = l->head->next;
    return removenode->value; 
}

elem list_remove_at_index(list_t *l, int index) {
    node_t* currnode = l->head;
    node_t*  removenode;
    removenode = malloc(sizeof(node_t));
    int count = 0;
    while(currnode->next != NULL){
        if (count == index-1){
            removenode = currnode->next;
            currnode->next = removenode->next;
            return removenode->value;
        }
        count++;
        currnode = currnode->next;
        
    }
    return -1; 
}

bool list_is_in(list_t *l, elem value) { 
    node_t* currnode = l->head;
    while(currnode->next != NULL){
        if (currnode->value == value){
            return true;
        }
        currnode = currnode->next;
    }
    return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
    node_t* currnode = l->head;
    int count = 0;
    while(currnode != NULL){
        if (count == index){
            return currnode->value;
        }
        count++;
        currnode = currnode->next;
    }
    return -1; 
}

int list_get_index_of(list_t *l, elem value) { 
    node_t* currnode = l->head;
    int count = 0;
    while(currnode->next != NULL){
        if (currnode->value == value){
            return count;
        }
        count++;
        currnode = currnode->next;
    }
    return -1; 
}
