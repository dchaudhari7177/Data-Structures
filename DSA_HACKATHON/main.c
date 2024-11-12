#include "social_network.h"
#include <stdio.h>
#include <string.h>

int main() {
    SocialNetwork network;
    char user_names[][50] = {"Alice", "Bob", "Charlie", "Dave", "Eve", "Karen", "John"};
    initialize_network(&network, 7, user_names);

    add_friendship(&network, "Alice", "Bob");
    add_friendship(&network, "Alice", "Eve");
    add_friendship(&network, "Alice", "Dave");
    add_friendship(&network, "Alice", "Charlie");
    add_friendship(&network, "Bob", "Charlie");
    add_friendship(&network, "Bob", "John");
    add_friendship(&network, "Karen", "Dave");

    int choice;
    char user1[50], user2[50];
    int degree;

    do {
        printf("\n1. Print Network\n2. List Friends\n3. Find Mutual Friends\n4. Most Popular\n5. Find Shortest Path\n6. Recommend Friends\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_network(&network);
                break;
            case 2:
                printf("Enter user: ");
                scanf("%s", user1);
                list_friends(&network, user1);
                break;
            case 3:
                printf("Enter two users: ");
                scanf("%s %s", user1, user2);
                find_mutual_friends(&network, user1, user2);
                break;
            case 4:
                most_popular(&network);
                break;
            case 5:
                printf("Enter two users to find the shortest path: ");
                scanf("%s %s", user1, user2);
                shortest_path(&network, user1, user2);
                break;
            case 6:
                printf("Enter user: ");
                scanf("%s", user1);
                printf("Enter degree: ");
                scanf("%d", &degree);
                recommend_friends(&network, user1, degree);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
