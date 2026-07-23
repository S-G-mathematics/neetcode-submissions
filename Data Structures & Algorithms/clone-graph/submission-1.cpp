/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> yo;
        return dfs(node,yo);
    }

    Node* dfs(Node* node,map<Node*,Node*>& yo){
        if(node==nullptr)return nullptr;
        if(yo.count(node))return yo[node];
        Node* copy=new Node(node->val);
        yo[node]=copy;
        for(Node* n:node->neighbors){
            copy->neighbors.push_back(dfs(n,yo));
        }
        return copy;
    }
};
