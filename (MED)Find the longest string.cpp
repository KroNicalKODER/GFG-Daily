//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class TrieNode{
    public:
        char dat;
        vector<TrieNode*> child;
        bool isTerminal;
};
TrieNode* newNode(char val){
    TrieNode* temp = new TrieNode;
    temp->dat = val;
    temp->isTerminal = false;
    return temp;
}

class Solution
{
public:
    TrieNode* isAvailable(vector<TrieNode*>& vec,char ch){
        for(int i=0;i<vec.size();i++){
            if(vec[i]->dat==ch) 
                return vec[i];
        }
        return NULL; 
    }
    TrieNode* insert(string word,TrieNode* roott){
        TrieNode* root = roott;
        int n = word.length();
        for(int i=0;i<n;i++){
            TrieNode* chh = isAvailable(root->child,word[i]);
            if(chh!=NULL){
                root = chh;
                if(i==n-1) root->isTerminal = true;
                continue;
            }
            else{
                TrieNode* temp = newNode(word[i]);
                if(i==n-1) temp->isTerminal = true;
                root->child.push_back(temp);
                root = temp;
            }
        }
        return roott;
    }
    TrieNode* insertAll(vector<string>& words,TrieNode* root){
        for(auto word:words){
            root = insert(word,root);
        }
        return root;
    }

    void returnLongest(TrieNode* root,string curr,int currSize,map<int,set<string>>& ans) {
        bool proceed = true;
        if(root->child.empty() || root->isTerminal==true){
            if(root->dat!='1') curr+=root->dat;
            ans[curr.length()].insert(curr);
            if(root->child.empty()) return;
        }
        
            int n = root->child.size();
            for(auto itr:root->child){
                if(itr->isTerminal == true){
                    returnLongest(itr,curr,currSize+1,ans);
                }
            }
        
    }

    string longestString(vector<string> &words) {
        TrieNode* root = newNode('1');
        root->isTerminal = true;
        map<int,set<string>> ans;
        root = insertAll(words,root);
        returnLongest(root,"",0,ans);
        auto seet = *(prev(ans.end()));
        string strans = (*seet.second.begin());
        int st=0;
        for(int i=0;i<strans.length();i++) if(strans[i]=='1') st++;
        return strans.substr(st,strans.length()-st+1);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends
