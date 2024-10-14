#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct chat {
    char name[50];
    char text[50];
    struct chat* next;
    struct chat* prev;
} chat;

void disp(chat* headp, chat* head) {
    chat* p;

    printf("Pinned Chats:\n");
    p = headp;
    if (p == NULL) {
        printf("No pinned chats.\n");
    } else {
        while (p != NULL) {
            printf("%s: %s\n", p->name, p->text);  
            p = p->next;
        }
    }

    printf("\nUnpinned Chats:\n");
    p = head;
    if (p == NULL) {
        printf("No unpinned chats.\n");
    } else {
        while (p != NULL) {
            printf("%s: %s\n", p->name, p->text); 
            p = p->next;
        }
    }
}

chat* addchat(chat* headp, chat* head, char name[], char text[]) {
    chat* newChat = (chat*)malloc(sizeof(chat));
    strcpy(newChat->name, name);
    strcpy(newChat->text, text);
    newChat->next = NULL;
    newChat->prev = NULL;

    if (head == NULL) {
        head = newChat;
    } else {
        chat* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newChat;
        newChat->prev = temp;
    }
    printf("Chat with %s added.\n", name);
    return head;
}

void pinchat(chat** headp, chat** head, chat* chatToPin) {
    if (*head == NULL) return;

    if (chatToPin->prev != NULL) {
        chatToPin->prev->next = chatToPin->next;
    } else {
        *head = chatToPin->next;
    }

    if (chatToPin->next != NULL) {
        chatToPin->next->prev = chatToPin->prev;
    }

    chatToPin->next = *headp;
    chatToPin->prev = NULL;

    if (*headp != NULL) {
        (*headp)->prev = chatToPin;

    }
    *headp = chatToPin;
    printf("Chat with %s pinned.\n", chatToPin->name);
}

void unpin(chat** headp, chat** head, chat* chatToUnpin) {
    if (*headp == NULL) return;

    if (chatToUnpin->prev != NULL) {
        chatToUnpin->prev->next = chatToUnpin->next;
    } else {
        *headp = chatToUnpin->next;
    }

    if (chatToUnpin->next != NULL) {
        chatToUnpin->next->prev = chatToUnpin->prev;
    }

    chatToUnpin->next = *head;
    chatToUnpin->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = chatToUnpin;
    }
    *head = chatToUnpin;
    printf("Chat with %s unpinned.\n", chatToUnpin->name);
}

int main() {
    chat* head = NULL;
    chat* headp = NULL;
    int out = 0;
    printf("***************************************************************\n");
    printf("YOUR CHAT MESSENGER\n");
    printf("***************************************************************\n");

    while (out == 0) {
        printf("\nPick your action:\n");
        printf("To DISPLAY all chats enter 0\n");
        printf("To ADD a chat enter 1\n");
        printf("To PIN a chat enter 2\n");
        printf("To UNPIN a chat enter 3\n");
        int op = 0;
        printf("Enter option: ");
        scanf("%d", &op);

        if (op == 1) {
            char n[50] = "";
            char t[50] = "";
            printf("Enter name: ");
            getchar();
            scanf("%[^\n]s", n);
            getchar();
            printf("Enter text: ");
            scanf("%[^\n]s", t);
            head = addchat(headp, head, n, t);
        } else if (op == 2) {
            printf("Enter name of contact from unpinned chats:\n");
            getchar();
            disp(headp, head);
            char cont[50] = "";
            scanf("%[^\n]s", cont);

            chat* p = head;
            while (p != NULL && strcmp(p->name, cont) != 0) {
                p = p->next;
            }

            if (p != NULL) {
                pinchat(&headp, &head, p);
            } else {
                printf("Chat not found.\n");
            }
        } else if (op == 3) {
            printf("From the pinned chats, enter a chat that you want to unpin:\n");
            disp(headp, head);
            char in[50] = "";
            getchar();
            scanf("%[^\n]s", in);

            chat* point2 = headp;
            while (point2 != NULL && strcmp(point2->name, in) != 0) {
                point2 = point2->next;
            }

            if (point2 != NULL) {
                unpin(&headp, &head, point2);
            } else {
                printf("Chat not found.\n");
            }
        } else if (op == 0) {
            disp(headp, head);
        } else {
            printf("Wrong Input\n");
        }
    }
    return 0;
}
