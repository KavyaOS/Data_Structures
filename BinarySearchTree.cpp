#include <iostream>
#include <string>
using namespace std;


class node
{
    public:
        int value;
        node *left,*right;
};

class tree
{
    public:
        node *root;

        tree()
        {
            root=NULL;
        }

        node* insertIntoTheTree(int key,node *newNode)
        {
            if(newNode==NULL)
            {
                newNode=new node();
                newNode->value=key;
                newNode->left=newNode->right=NULL;
                //cout<<newNode->value;
            }
            else if(key<=newNode->value)
            {
                newNode->left=insertIntoTheTree(key,newNode->left);
            }
            else
            {
                newNode->right=insertIntoTheTree(key,newNode->right);
            }
            return newNode;
        }

        void insertNode(int key)
        {
            root=insertIntoTheTree(key,root);
        }

        string printTree(node *root)
        {
            string str;
            if(root==NULL)
                return;

            else
            {
                //cout<<root->value<<" ";
                str.append(" ");
                //printTree(root->left);
                str.append(root->left);
                //printTree(root->right);
                str.append(root->right);
            }
            return str;
        }

        void printNodes()
        {
            string str=printTree(root);
            cout<<str;
        }
};
int main()
{
    tree t;
    t.insertNode(14);
    t.insertNode(12);
    t.insertNode(2);
    t.insertNode(13);
    t.insertNode(8);
    t.printNodes();
    return 0;
}
