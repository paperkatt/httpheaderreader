#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 30

struct Node{
    char *key;
    int occurences;
    struct Node *next;
};

struct HashTable{
    struct Node *hashArray[LENGTH];
};

int hashIndex(char *key) {
    int totalValue = 0;
    while(*key != '\0'){
        totalValue += (int)( *key);
	++key;
    }
    return totalValue % LENGTH;

}

void HashTableMemSet(struct HashTable *ht){
    for(int i=0; i<LENGTH; i++){
        ht->hashArray[i] = NULL;
    }
}

struct Node *search(char *key, struct HashTable *ht){
    int index = hashIndex(key);
    struct Node *ptr = ht->hashArray[index];
    while(ptr != NULL){
	//if(ptr->occurences == 0) return NULL;
        if( strcmp(ptr->key, key) == 0){ //i.e the strings are equal
	    ++(ptr->occurences); //we increment occurences (i.e value)
    //to keep track of how many times we searched for the word
	    return ptr;
        }
	ptr = ptr->next;
    }
    return NULL;
}

void insert(char *key, struct HashTable *ht){ //assumes no duplicates
    struct Node *neww = (struct Node*) malloc(sizeof(struct Node));
    neww->key = (char*) malloc(sizeof(key));
    strcpy(neww->key, key);
    neww->occurences = 1; //we are inserting when we first occur a new word
    neww->next = NULL;
    int index = hashIndex(key);  //index we need to insert at

    if(ht->hashArray[index] == NULL){ //i.e no linked list head here
        ht->hashArray[index] = neww;   //then make one
    }
    else{ //else then there is a linked list head so traverse to the end 
	  // and add  the new node there
        struct Node *ptr = ht->hashArray[index];
	while(ptr-> next != NULL){
	    ptr = ptr->next;
	}
	ptr->next = neww;
    }

}
