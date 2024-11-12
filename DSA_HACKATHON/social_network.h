#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#define MAX_USERS 100

typedef struct {
    char name[50]; 
    int friend_count;
    int friends[MAX_USERS];
} User;

typedef struct {
    User users[MAX_USERS];
    int user_count;
} SocialNetwork;

void initialize_network(SocialNetwork *network, int num_users, char user_names[][50]);
void add_friendship(SocialNetwork *network, const char *user1, const char *user2);
void print_network(SocialNetwork *network);
void list_friends(SocialNetwork *network, const char *user);
void find_mutual_friends(SocialNetwork *network, const char *user1, const char *user2);
void recommend_friends(SocialNetwork *network, const char *user, int degree);
void most_popular(SocialNetwork *network);
void shortest_path(SocialNetwork *network, const char *user1, const char *user2);

#endif
