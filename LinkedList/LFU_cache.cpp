#include<iostream>
using namespace std;

// LFU CACHE (LEETCODE 460)
// USING DOUBLY LINKED LIST AND HASHMAP - TC=O(1), SC=O(N)

// Steps:
// 1. Implement a doubly linked list to store the key-value pairs.
// 2. Implement a hashmap to store the key and the corresponding node address.
// 3. Implement a hashmap to store the frequency and the list of nodes with that frequency.
// 4. Implement a hashmap to store the key and the iterator of the node in the list.
// 5. The head of the linked list is the most recently used node.
// 6. The tail of the linked list is the least recently used node.
// 7. To get the value of a key, check if the key exists in the hashmap.
// 8. If the key exists, increment the frequency of the node and move the node to the head of the linked list.
// 9. To put a key-value pair, check if the key exists in the hashmap.
// 10. If the key exists, update the value and increment the frequency of the node.
// 11. If the key does not exist, check if the capacity is full.
// 12. If the capacity is full, remove the least frequently used node from the tail of the linked list and hashmap.
// 13. Add the new key-value pair to the head of the linked list and hashmap.
// 14. Update the minimum frequency if the node is removed from the list.

class LFUCache
{
public:
    class Node
    {
    public:
        int key, val, freq;
        Node *prev;
        Node *next;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            this->freq = 1;
        }
    };
    unordered_map<int, Node *> mp;
    unordered_map<int, list<Node *>> freqList;
    unordered_map<int, list<Node *>::iterator> nodeIter;
    int capacity;
    int minFreq;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
        minFreq = 0;
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
        Node *node = mp[key];
        freqList[node->freq].erase(nodeIter[key]);
        if (freqList[node->freq].empty())
        {
            freqList.erase(node->freq);
            if (minFreq == node->freq)
            {
                minFreq++;
            }
        }
        node->freq++;
        freqList[node->freq].push_front(node);
        nodeIter[key] = freqList[node->freq].begin();
        return node->val;
    }
    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->val = value;
            freqList[node->freq].erase(nodeIter[key]);
            if (freqList[node->freq].empty())
            {
                freqList.erase(node->freq);
                if (minFreq == node->freq)
                {
                    minFreq++;
                }
            }
            node->freq++;
            freqList[node->freq].push_front(node);
            nodeIter[key] = freqList[node->freq].begin();
        }
        else
        {
            if (mp.size() == capacity)
            {
                Node *leastFreqNode = freqList[minFreq].back();
                freqList[minFreq].pop_back();
                if (freqList[minFreq].empty())
                {
                    freqList.erase(minFreq);
                }
                mp.erase(leastFreqNode->key);
                nodeIter.erase(leastFreqNode->key);
                delete leastFreqNode;
            }
            Node *node = new Node(key, value);
            mp[key] = node;
            freqList[1].push_front(node);
            nodeIter[key] = freqList[1].begin();
            minFreq = 1;
        }
    }
};
