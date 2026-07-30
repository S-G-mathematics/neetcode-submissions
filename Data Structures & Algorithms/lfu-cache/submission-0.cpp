class Node {
public:
    int key, val, freq;
    Node *prev, *next;

    Node(int k,int v){
        key=k;
        val=v;
        freq=1;
        prev=next=nullptr;
    }
};

class List{
public:
    Node *head,*tail;
    int size;

    List(){
        head=new Node(0,0);
        tail=new Node(0,0);

        head->next=tail;
        tail->prev=head;

        size=0;
    }

    void addFront(Node* node){

        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;

        size++;
    }

    void remove(Node* node){

        node->prev->next=node->next;
        node->next->prev=node->prev;

        size--;
    }
};

class LFUCache {

    int capacity;
    int minFreq;

    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqList;

public:

    LFUCache(int capacity) {

        this->capacity=capacity;
        minFreq=0;
    }

    void update(Node* node){

        int freq=node->freq;

        freqList[freq]->remove(node);

        if(freq==minFreq && freqList[freq]->size==0)
            minFreq++;

        node->freq++;

        if(freqList.find(node->freq)==freqList.end())
            freqList[node->freq]=new List();

        freqList[node->freq]->addFront(node);
    }

    int get(int key) {

        if(keyNode.find(key)==keyNode.end())
            return -1;

        Node* node=keyNode[key];

        update(node);

        return node->val;
    }

    void put(int key,int value) {

        if(capacity==0)
            return;

        if(keyNode.find(key)!=keyNode.end()){

            Node* node=keyNode[key];

            node->val=value;

            update(node);

            return;
        }

        if(keyNode.size()==capacity){

            List* list=freqList[minFreq];

            Node* node=list->tail->prev;

            list->remove(node);

            keyNode.erase(node->key);

            delete node;
        }

        Node* node=new Node(key,value);

        minFreq=1;

        if(freqList.find(1)==freqList.end())
            freqList[1]=new List();

        freqList[1]->addFront(node);

        keyNode[key]=node;
    }
};