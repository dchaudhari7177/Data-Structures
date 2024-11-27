//Trie houses lower case english alphabets
#include<stdio.h>
#include<stdlib.h>

typedef struct trie
{
	struct trie *child[26];
	int isLeaf;
}TRIE;

TRIE* createNode();
void insert(TRIE *cur,char *pattern);
int search(TRIE *cur,char *pattern);
void display(TRIE *root,char *str,int level);
void displayofLen(TRIE *root,char *str,int level,int length);
TRIE* delete(TRIE *root,char *str,int level,int length);
TRIE* destroy(TRIE *root);

int main()
{
	TRIE *root=createNode();
	
	insert(root,"ant");
	insert(root,"antenna");
	
	
	if(search(root,"ant"))
		printf("ant present\n");
	else
		printf("ant not present\n");
	
	if(search(root,"antenna"))
		printf("antenna present\n");
	else
		printf("antenna not present\n");
	
	if(search(root,"ten"))
		printf("ten present\n");
	else
		printf("ten not present\n");
	
	
	
	if(search(root,"an"))
		printf("an present\n");
	else
		printf("an not present\n");
	
	char str[100];
	printf("patterns present in TRIE\n");
	display(root,str,0);
	
	printf("patterns of length 3 in  TRIE\n");
	displayofLen(root,str,0,3);
	
	delete(root,"ant",0,3);
	display(root,str,0);
	
	destroy(root);
	
	
}


TRIE* createNode()
{
	TRIE *temp=malloc(sizeof(TRIE));
	for(int i=0;i<26;i++)
		temp->child[i]=NULL;
	temp->isLeaf=0;
	
	return temp;
}

void insert(TRIE *root,char *pattern)
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
}
int search(TRIE *root,char *pattern)
{
	TRIE *cur=root;
	while(*pattern)
	{
		
		if(cur->child[*pattern-'a']==NULL)
			return 0;
		cur=cur->child[*pattern-'a'];
		pattern++;
	}
	return cur->isLeaf;
}

int isEmpty(TRIE *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
			return 0;
	}
	return 1;
}

TRIE* delete(TRIE *root,char *str,int level,int length)
{
	if(root==NULL)
		return root;
	if(length==level)
	{
		if(root->isLeaf==1)
			root->isLeaf=0;
		if(isEmpty(root))
		{
			free(root);
			root=NULL;
		}
		return root;
	}
	
	int index=str[level]-'a';
	root->child[index]=delete(root->child[index],str,level+1,length);
	
	/* This is not required 
       if(root->isLeaf==0 &&isEmpty(root))
	{
		free(root);
		root=NULL;
	}
	return root; */
}
void display(TRIE *root,char *str,int level)
{
	if(root->isLeaf)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			str[level]=i+'a';
			display(root->child[i],str,level+1);
		}
	}
}

void displayofLen(TRIE *root,char *str,int level,int length)
{
	if(root->isLeaf && level==length)
	{
		str[level]='\0';
		printf("%s\n",str);
	}
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			str[level]=i+'a';
			displayofLen(root->child[i],str,level+1,length);
		}
	}
}
TRIE* destroy(TRIE *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			root->child[i]=destroy(root->child[i]);
			//printf("%c freed\n",i+'a');
			free(root->child[i]);
			root->child[i]=NULL;
		}
		
	}
	return root;
}
