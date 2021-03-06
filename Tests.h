//
// Created by @KasperBaun on 30-04-2021.
//

#ifndef MASKPROG_P2_TESTS_H
#define MASKPROG_P2_TESTS_H

#endif //MASKPROG_P2_TESTS_H
struct node* createTestDeck(){
    Node* head = createNewNode();
    Card temp_card;
    Node* temp;
    temp_card.visibility=1;
    // A setup of for-loops creates the 13 cards from each of the 4 suits
    for(int index=1; index<=4; index++){
        if(index==1) temp_card.suit = 'C';
        if(index==2) temp_card.suit = 'D';
        if(index==3) temp_card.suit = 'H';
        if(index==4) temp_card.suit = 'S';

        for(int i=0; i<=13; i++){

            // For assigning the aces card in the respective suit
            if(i==0 && index==1){
                temp_card.rank ='A';
                head->card = temp_card;
            } else if(index>=1&&i==0){
                temp_card.rank = 'A';
                temp = createNewNode();
                temp->card = temp_card;
                insertNew(head,temp);
            }
            // For cards 2 through K in the specific suit
            if(i>0){
                switch(i) {
                    case 1:
                        break;

                    case 2:
                        temp_card.rank = '2';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 3:
                        temp_card.rank = '3';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 4:
                        temp_card.rank = '4';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 5:
                        temp_card.rank = '5';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 6:
                        temp_card.rank = '6';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 7:
                        temp_card.rank = '7';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 8:
                        temp_card.rank = '8';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 9:
                        temp_card.rank = '9';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 10:
                        temp_card.rank = 'T';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 11:
                        temp_card.rank = 'J';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 12:
                        temp_card.rank = 'Q';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    case 13:
                        temp_card.rank = 'K';
                        temp = createNewNode();
                        temp->card = temp_card;
                        insertNew(head,temp);
                        break;

                    default:
                        printf("Switch case ran default option - something went wrong \n");
                }
            }
        }
    } return head;
}
void printDeck(Node* head){
    printf("\t");
    while(head!=NULL){
        printf("%c%c\t",head->card.rank,head->card.suit);
        head=head->next;
    }
}
void testDeck(){
    Node* head;
    head = createTestDeck();
    printf("------------------ createTestDeck() complete ------------------\n");
    printf("### Traversing linked list ### \n");
    traverseList(head);
}
// Todo: make test-case for card in the middle and tail
void testSearchAndDelete(){
    Node* head;
    Node* deleteTest;
    Card card,card2,card3;
    card.rank = 'A';
    card.suit = 'C';
    head = createTestDeck();
    deleteTest = getNodeFromCard(head, card);
    printf("------------- Test # 1: createTestDeck() and search for card AC -------------\n");
    printf("HA's ptr*: %d\n",deleteTest);
    traverseList(head);
    printf("------------- Test #1 concluded - AC's ptr* should be in the traversal list -------------\n");

    printf("------------- Test # 2: delete card AC -------------\n");
    head = deleteNode(head,deleteTest);
    traverseList(head);
    printf("------------- Test # 2: card AC should no longer be in set -------------\n");
}
void testGetTail(){
    Node* head = createTestDeck();
    printf("Printing deck:\n");
    printDeck(head);
    printf("\nPrinting tail:\n");
    printNode(getTail(head));
}
void testInsertLinkedListAtEnd(){
    Node* head = createTestDeck();
    printf("Printing deck:\n");
    printDeck(head);
    printf("\nInserting node as new tail:\n");
    Node* newNode = createNewNode();
    setCard(newNode,'7','D',0);
    printNode(newNode);
    insertLinkedListAtEnd(head,newNode);
    printf("\n New node should now be attached to the old tail:\n");
    printDeck(head);
    printf("\n Printing node again - pointers should be updated here:\n");
    printNode(newNode);
}
void testGetFromIndex(){
    Node* head = createTestDeck();
    printf("Printing deck with index:\n");
    traverseList(head);
    printf("Printing getFromIndex(head, 34): \n");
    printNode(getFromIndex(head,34));

}