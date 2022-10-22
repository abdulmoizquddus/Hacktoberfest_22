#include <iostream>
#include <queue>
#include <vector>

int Big(int a, int b) {
    if (a > b) {return a;}
    else if (a < b) {return b;}
    else return a;
}

int Height(BstNode* root) {
    if(root == NULL) {
        return -1;
    }
    else {
        return (Big(Height(root->left),Height(root->right)) + 1);
    }
}

void LevelOrder(BstNode* root) {  // Breadth First //
    if(root == NULL) return;
    std::queue<BstNode*> Q;
    Q.push(root);
    while(!Q.empty()) {
        BstNode* current = Q.front();
        std::cout << current->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}


// Depth First //
void PreOrder(BstNode* root) {
    if (root == NULL) return;
    std::cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BstNode* root) {
    if(root == NULL) return;
    InOrder(root->left);
    std::cout << root->data << " ";
    std::vector<int> arr;
    arr.push_back(root->data);
    InOrder(root->right);
}

void PostOrder(BstNode* root) {
    if(root == NULL) return;
    InOrder(root->left);
    InOrder(root->right);
    std::cout << root->data << " ";
    
}