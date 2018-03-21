#include <bits/stdc++.h>
using namespace std;
#include<string.h>

bool flag;

struct trie{
	bool endmark;
	trie *next[10];
	trie(){
		endmark=false;
		for(int i=0;i<10;i++){
			next[i]=NULL;
		}
	}
}*root;

void insert(string s)
{
	trie *curr=root;
	for(int i=0;i<s.size();i++){
		int id=s[i]-'0';
		if(curr->next[id]==NULL){
			curr->next[id]=new trie();
		}
		
		curr=curr->next[id];
	}
	curr->endmark=true;
}


void del(trie *root)
{
	for(int i=0;i<10;i++)
		if(root->next[i]!=NULL)
			del(root->next[i]);
	delete root;
}

bool prefix(trie *curr)
{
	if(curr->endmark){
		trie *ptr=curr;
		for(int i=0;i<10;i++){
			if(ptr->next[i]!=NULL)
				flag=true;
		}
	}

	for(int i=0;i<10;i++){
		if(flag==true) break;
		if(curr->next[i]){
			prefix(curr->next[i]);
		}
	}
	return (flag)? true: false;
}

int main()
{
	int t;
	cin>>t;
	string s;

	for(int i=1;i<=t;i++){
		int n;
		root=new trie();
		flag=false;
		cin>>n;

		cin.ignore();

		for(int j=0;j<n;j++){
			cin>>s;
			insert(s);
		}


		if(prefix(root)){
			cout<<"Case "<<i<<": NO"<<"\n";
		}
		else cout<<"Case "<<i<<": YES"<<"\n";
		
		del(root);
	}
	return 0;
}
