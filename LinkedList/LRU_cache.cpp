#include<iostream>
using namespace std;

// LRU CACHE (LEETCODE 146)
// USING DOUBLY LINKED LIST AND HASHMAP - TC=O(1), SC=O(N)

// Steps:
// 1. Implement a doubly linked list to store the key-value pairs.
// 2. Implement a hashmap to store the key and the corresponding node address.
// 3. The head of the linked list is the most recently used node.
// 4. The tail of the linked list is the least recently used node.
// 5. To get the value of a key, check if the key exists in the hashmap.
// 6. If the key exists, move the node to the head of the linked list and return the value.
// 7. To put a key-value pair, check if the key exists in the hashmap.
// 8. If the key exists, update the value and move the node to the head of the linked list.
// 9. If the key does not exist, check if the capacity is full.
// 10. If the capacity is full, remove the least recently used node from the tail of the linked list and hashmap.
// 11. Add the new key-value pair to the head of the linked list and hashmap.

class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        Node *prev;
        Node *next;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    unordered_map<int, Node *> mp;
    int capacity;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void insertAfterHead(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    void deleteNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        Node *temp = mp[key];
        deleteNode(temp);
        insertAfterHead(temp);
        return temp->val;
    }
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            insertAfterHead(temp);
        }
        else
        {
            if (mp.size() == capacity)
            {
                Node *temp = tail->prev;
                mp.erase(temp->key);
                deleteNode(temp);
            }
            Node *newNode = new Node(key, value);
            mp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};