//Trie houses lower case english alphabets
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct trie
{
	struct trie *child[26];
	int isLeaf;
	char *synonym;
}TRIE;

TRIE* createNode();
void insert(TRIE *cur,char *pattern,char *meaning);
int search(TRIE *cur,char *pattern,char *meaning);


int main()
{
	TRIE *cur=createNode();
	
	insert(cur,"act","pretend");
	
	
	char meaning[100];
	if(search(cur,"act",meaning))
		printf("act present and its meaning %s \n",meaning);
	else
		printf("act not present\n");
	
	if(search(cur,"ac",meaning))
		printf("ac present and its meaning %s \n",meaning);
	else
		printf("ac not present\n");
	/*
	if(search(cur,"antenna"))
		printf("antenna present\n");
	else
		printf("antenna not present\n");
	
	if(search(cur,"ten"))
		printf("ten present\n");
	else
		printf("ten not present\n");
	
	
	
	if(search(cur,"an"))
		printf("an present\n");
	else
		printf("an not present\n");
	 */
	
}


TRIE* createNode()
{
	TRIE *temp=malloc(sizeof(TRIE));
	for(int i=0;i<26;i++)
		temp->child[i]=NULL;
	temp->isLeaf=0;
	
	return temp;
}

void insert(TRIE *root,char *pattern,char *meaning)
{
	TRIE *cur=root;
	while(*pattern)
	{
		
		if(cur->child[*pattern-'a']==NULL)
			cur->child[*pattern-'a']=createNode();
		cur=cur->child[*pattern-'a'];
		pattern++;
	}
	cur->isLeaf=1;
	cur->synonym=malloc(sizeof(strlen(meaning)+1));
	strcpy(cur->synonym,meaning);
}
int search(TRIE *root,char *pattern,char *meaning)
{
	TRIE *cur=root;
	while(*pattern)
	{
		
		if(cur->child[*pattern-'a']==NULL)
			return 0;
		cur=cur->child[*pattern-'a'];
		pattern++;
	}
	if(cur->isLeaf)
	{
		strcpy(meaning,cur->synonym);
		return 1;
	}
	return 0;
}


void display(TRIE *cur,char *str,int level)
{
	if(cur->isLeaf)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	for(int i=0;i<26;i++)
	{
		if(cur->child[i]!=NULL)
		{
			str[level]=i+'a';
			display(cur->child[i],str,level+1);
		}
	}
}
