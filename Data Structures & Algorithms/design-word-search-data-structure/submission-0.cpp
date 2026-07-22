class TrieNode{
    public:
    TrieNode* children[26];
    bool isend;
    TrieNode(){
        isend=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};




class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(char c:word){
            int idx=c-'a';
            if(curr->children[idx]==nullptr)curr->children[idx]=new TrieNode();
            curr=curr->children[idx];
        }
        curr->isend=true;
    }
    
    bool dfs(TrieNode* node,int idx,string &word){
        if(idx==word.size()){
            return node->isend;
        }
        char c=word[idx];
        if(c!='.'){
            int child=c-'a';
            if(node->children[child]==nullptr)return false;
            return dfs(node->children[child],idx+1,word);
        }else{
            for(int i=0;i<26;i++){
                if(node->children[i]!=nullptr){
                if(dfs(node->children[i],idx+1,word)) return true;
            }}
            return false;
        }
        
    }

    bool search(string word) {
        return (dfs(root,0,word));
    }
};
