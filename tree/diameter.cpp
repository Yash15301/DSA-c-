/* Input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1 */
#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){

    int d;
    cin >> d;

    if(d==-1){
        return NULL;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;

};

void levelOrderPrint(Node *root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        if(temp==NULL){
            cout << endl;
            q.pop();
            //insert new null for next level
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout << temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

Node* LevelOrderBuild(){
    int d;
    cin >> d;
    Node* root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *current = q.front();
        q.pop();

        int c1,c2;
        cin >> c1 >> c2;

        if(c1!=-1){
            current->left = new Node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right = new Node(c2);
            q.push(current->right);
        }
    }

    return root;
}

//helper function to find height
int height(Node*root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    return (1+max(h1,h2));
}

int diameter(Node*root){
    if(root==NULL){
        return 0;
    }

    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2,D3));
}

int main(){
    Node *root = LevelOrderBuild();

    levelOrderPrint(root);

    int D = diameter(root);
    cout << "Diameter is " << D;
    return 0;
}