/*Hubertas Vindzigalskis
Programu Sistemos 1 kursas 3 grupe 
Ketvirtas namu darbas 
Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta reikšme nurodytą elementą. Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.*/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct node *head = NULL;

    int errorCode;
    if ((errorCode = insert(1, &head)) == -1)
        insert(1, &head);
    if ((errorCode = insert(2, &head)) == -1)
        insert(2, &head);
    if ((errorCode = insert(3, &head)) == -1)
        insert(3, &head);
    if ((errorCode = insert(4, &head)) == -1)
        insert(4, &head);
    if ((errorCode = insert(5, &head)) == -1)
        insert(5, &head);
    
    if ((errorCode = removeNode(3, &head)) == -1)
        printf("Klaida! Nerastas toks sąrašo narys %d. Error kodas: %d\n", 3, errorCode);
    if ((errorCode = removeNode(1, &head)) == -1)
        printf("Klaida! Nerastas toks sąrašo narys %d. Error kodas: %d\n", 1, errorCode);
    if ((errorCode = removeNode(5, &head)) == -1)
        printf("Klaida! Nerastas toks sąrašo narys %d. Error kodas: %d\n", 5, errorCode);
    if ((errorCode = removeNode(6, &head)) == -1)
        printf("Klaida! Nerastas toks sąrašo narys %d. Error kodas: %d\n", 6, errorCode);

    printList(head);

    if ((errorCode = deleteList(&head)) == -1)
        printf("Nepavyko istrinti saraso\n");
    
    printList(head);

    return 0;
}