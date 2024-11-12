#include "social_network.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initialize_network(SocialNetwork *network, int num_users, char user_names[][50]) {
    network->user_count = num_users;
    for (int i = 0; i < num_users; i++) {
        strcpy(network->users[i].name, user_names[i]);
        network->users[i].friend_count = 0;
    }
}

int find_user_index(SocialNetwork *network, const char *name) {
    for (int i = 0; i < network->user_count; i++) {
        if (strcmp(network->users[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_friendship(SocialNetwork *network, const char *user1, const char *user2) {
    int idx1 = find_user_index(network, user1);
    int idx2 = find_user_index(network, user2);

    if (idx1 == -1 || idx2 == -1) return;

    network->users[idx1].friends[network->users[idx1].friend_count++] = idx2;
    network->users[idx2].friends[network->users[idx2].friend_count++] = idx1;
}

void print_network(SocialNetwork *network) {
    for (int i = 0; i < network->user_count; i++) {
        printf("%s: ", network->users[i].name);
        for (int j = 0; j < network->users[i].friend_count; j++) {
            printf("%s%s", network->users[network->users[i].friends[j]].name,
                   (j == network->users[i].friend_count - 1) ? "" : ", ");
        }
        printf("\n");
    }
}

void list_friends(SocialNetwork *network, const char *user) {
    int idx = find_user_index(network, user);
    if (idx == -1) {
        printf("%s not found.\n", user);
        return;
    }
    printf("Friends of %s:\n", user);
    for (int i = 0; i < network->users[idx].friend_count; i++) {
        printf("- %s\n", network->users[network->users[idx].friends[i]].name);
    }
}

void find_mutual_friends(SocialNetwork *network, const char *user1, const char *user2) {
    int idx1 = find_user_index(network, user1);
    int idx2 = find_user_index(network, user2);

    if (idx1 == -1 || idx2 == -1) {
        printf("One or both users not found.\n");
        return;
    }

    printf("Mutual friends between %s and %s:\n", user1, user2);
    for (int i = 0; i < network->users[idx1].friend_count; i++) {
        for (int j = 0; j < network->users[idx2].friend_count; j++) {
            if (network->users[idx1].friends[i] == network->users[idx2].friends[j]) {
                printf("- %s\n", network->users[network->users[idx1].friends[i]].name);
            }
        }
    }
}

void recommend_friends(SocialNetwork *network, const char *user, int degree) {
    int start_idx = find_user_index(network, user);
    if (start_idx == -1) {
        printf("%s not found.\n", user);
        return;
    }

    int visited[MAX_USERS] = {0};
    int queue[MAX_USERS], front = 0, rear = 0;
    int level[MAX_USERS] = {0};

    visited[start_idx] = 1;
    queue[rear++] = start_idx;

    printf("Friend recommendations for %s within %d levels:\n", user, degree);

    while (front < rear) {
        int current = queue[front++];
        if (level[current] >= degree) continue;

        for (int i = 0; i < network->users[current].friend_count; i++) {
            int friend_idx = network->users[current].friends[i];
            if (!visited[friend_idx]) {
                visited[friend_idx] = 1;
                queue[rear++] = friend_idx;
                level[friend_idx] = level[current] + 1;

                if (level[friend_idx] > 1) {
                    printf("- %s\n", network->users[friend_idx].name);
                }
            }
        }
    }
}

void most_popular(SocialNetwork *network) {
    if (network->user_count == 0) {
        printf("No users in the network.\n");
        return;
    }

    int max_friends = network->users[0].friend_count;
    int max_index = 0;

    for (int i = 1; i < network->user_count; i++) {
        if (network->users[i].friend_count > max_friends) {
            max_friends = network->users[i].friend_count;
            max_index = i;
        }
    }

    printf("Most popular user:\n");
    printf("- %s (%d connections)\n", network->users[max_index].name, max_friends);
}
void shortest_path(SocialNetwork *network, const char *user1, const char *user2) {
    int start_idx = find_user_index(network, user1);
    int end_idx = find_user_index(network, user2);

    if (start_idx == -1 || end_idx == -1) {
        printf("One or both users not found.\n");
        return;
    }

    int visited[MAX_USERS] = {0};
    int queue[MAX_USERS], front = 0, rear = 0;
    int parent[MAX_USERS];
    for (int i = 0; i < MAX_USERS; i++) parent[i] = -1;

    visited[start_idx] = 1;
    queue[rear++] = start_idx;

    while (front < rear) {
        int current = queue[front++];

        if (current == end_idx) break;

        for (int i = 0; i < network->users[current].friend_count; i++) {
            int friend_idx = network->users[current].friends[i];
            if (!visited[friend_idx]) {
                visited[friend_idx] = 1;
                queue[rear++] = friend_idx;
                parent[friend_idx] = current;
            }
        }
    }

    if (!visited[end_idx]) {
        printf("No path exists between %s and %s.\n", user1, user2);
        return;
    }

    printf("Shortest path from %s to %s:\n", user1, user2);
    int path[MAX_USERS], path_len = 0;
    for (int at = end_idx; at != -1; at = parent[at]) {
        path[path_len++] = at;
    }

    for (int i = path_len - 1; i >= 0; i--) {
        printf("%s%s", network->users[path[i]].name, (i == 0) ? "\n" : " -> ");
    }
}
