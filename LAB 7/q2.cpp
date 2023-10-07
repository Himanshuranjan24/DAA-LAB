#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct CHAR
{
    char symbol;
    int frequency;
};
struct Node
{
    CHAR character;
    Node *left;
    Node *right;
};
struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->character.frequency > b->character.frequency;
    }
};
Node *buildHuffmanTree(vector<CHAR> &characters)
{
    priority_queue<Node *, vector<Node *>, CompareNodes> minHeap;

    for (const CHAR &c : characters)
    {
        Node *newNode = new Node();
        newNode->character = c;
        newNode->left = nullptr;
        newNode->right = nullptr;
        minHeap.push(newNode);
    }

    while (minHeap.size() > 1)
    {
        
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        
        Node *internalNode = new Node();
        internalNode->character.symbol = '$'; 
        internalNode->character.frequency = left->character.frequency + right->character.frequency;
        internalNode->left = left;
        internalNode->right = right;
        minHeap.push(internalNode);
    }
    return minHeap.top();
}
void inOrderTraversal(Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        if (root->character.symbol != '$')
        {
            cout << root->character.symbol << " ";
        }
        inOrderTraversal(root->right);
    }
}

int main()
{
    int n;
    cout << "Enter the number of distinct characters: ";
    cin >> n;

    vector<CHAR> characters(n);

    cout << "Enter the characters: ";
    for (int i = 0; i < n; i++)
    {
        cin >> characters[i].symbol;
    }

    cout << "Enter their frequencies: ";
    for (int i = 0; i < n; i++)
    {
        cin >> characters[i].frequency;
    }
    Node *root = buildHuffmanTree(characters);

    cout << "In-order traversal of the tree (Huffman): ";
    inOrderTraversal(root);

    return 0;
}