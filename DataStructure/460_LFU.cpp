#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
public:
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
    }

    Node(int key, int val, Node* prev, Node* next){
        this->key = key;
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

class LinkedHashMap{
public:
    Node* head = new Node(0, 0);
    Node* tail = new Node(0 ,0);
    unordered_map<int, Node*> nodeMap;

    LinkedHashMap(){
        head->next = tail;
        tail->prev = head;
    }

    void add(int key, int value){
        if (nodeMap.find(key) != nodeMap.end()){
            Node* target = nodeMap.find(key)->second;
            target->val = value;

            remove(target);
            makeFirst(target);

            return;
        }

        Node* newNode = new Node(key, value);
        nodeMap.insert(make_pair(key, newNode));
        makeFirst(newNode);
    }



    int get(int key){
        if (nodeMap.find(key) != nodeMap.end()){
            Node* target = nodeMap.find(key)->second;

            remove(target);
            makeFirst(target);

            return target->val;
        }
        return -1;
    }

    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void makeFirst(Node* node){
        Node* first = head->next;
        head->next = node;
        first->prev = node;
        node->next = first;
        node->prev = head;
    }
};


class LFUCache {
public:
    unordered_map<int, int> kvMap;
    unordered_map<int, int> kfMap;
    unordered_map<int, LinkedHashMap> fkMap;

    int least_freq;
    int capacity;


    LFUCache(int capacity) {
        this->capacity = capacity;
        this->least_freq = 0;
    }
    
    int get(int key) {
        if (kvMap.find(key) == kvMap.end())
            return -1;

        int orig_freq = kfMap.find(key)->second;
        LinkedHashMap orig_link = fkMap.find(orig_freq)->second;
        Node* target = orig_link.nodeMap.find(key)->second;
        orig_link.remove(target);

        LinkedHashMap new_link;
        if (fkMap.find(orig_freq + 1) == fkMap.end())
            fkMap.insert(make_pair(orig_freq+1, new_link));
        new_link = fkMap.find(orig_freq+1)->second;
        new_link.add(key, target)


        kfMap.find(key)->second++;
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */