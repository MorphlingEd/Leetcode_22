#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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

class LRUCache {
public:
    int capacity;
    int size;

    Node* head = new Node(0, 0);
    Node* tail = new Node(0, 0);

    unordered_map<int, Node*> nodeMap;

    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (nodeMap.find(key) != nodeMap.end()){
            Node* targetNode = (nodeMap.find(key))->second;

            targetNode->next->prev = targetNode->prev;
            targetNode->prev->next = targetNode->next;

            makeFirst(targetNode);

            return targetNode->val;
        }
        return -1;
    }

    void put(int key, int value) {
        // The key already exists modify the value
        if (nodeMap.find(key) != nodeMap.end()){
            Node* target = nodeMap.find(key)->second;
            target->val = value;

            target->next->prev = target->prev;
            target->prev->next = target->next;

            makeFirst(target);
            return;
        }

        // The capacity is full -> removes the last node and corresponding key
        if (size == capacity){
            Node* last = tail->prev;

            last->prev->next = tail;
            tail->prev = last->prev;

            nodeMap.erase(last->key);
            size--;
        }

        // Add the new node
        Node* newNode = new Node(key, value);
        nodeMap.insert(make_pair(key, newNode));
        size++;

        makeFirst(newNode);
    }

    void makeFirst(Node* node){
        Node* first = head->next;
        first->prev = node;
        head->next = node;
        node->next = first;
        node->prev = head;
    }
};


int main(){
    LRUCache* cache = new LRUCache(2);
    cache->put(2, 1);
    cache->put(1,1);
    cache->put(2, 3);
    cache->put(4,1);
    cout << cache->get(1) << endl;
    cout << cache->get(2);

    return 0;
}