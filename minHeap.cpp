#include <iostream>

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
        
        int findDepth(node *tempNode)
        {
            if(tempNode==NULL)
                return 0;
            else
            {
                int leftLength=findDepth(tempNode->left);
                int rightLength=findDepth(tempNode->right);

                return max(leftLength,rightLength)+1;
            }
        }

        node* insertIntoMinHeap(int key,node* newNode)
        {
            if(newNode==NULL)
            {
                newNode=new node();
                newNode->value=key;
                newNode->left=newNode->right=NULL;
            }
            else if(key<newNode->value)
            {
                int temp=newNode->value;
                newNode->value=key;
                if(findDepth(newNode->left)>findDepth(newNode->right))
                    newNode->right=insertIntoMinHeap(temp,newNode->right);
                else
                    newNode->left=insertIntoMinHeap(temp,newNode->left);
            }
            else
            {
                if(findDepth(newNode->left)>findDepth(newNode->right))
                    newNode->right=insertIntoMinHeap(key,newNode->right);
                else
                    newNode->left=insertIntoMinHeap(key,newNode->left);
            }
            return newNode;
        }

        void insertToHeap(int key)
        {
            root=insertIntoMinHeap(key,root);
        }

        void printPostOrderNodes(node *root)
        {
            if(root==NULL)
                return;

            else
            {
                printPostOrderNodes(root->left);

                printPostOrderNodes(root->right);

                cout<<root->value<<" ";
            }
        }

        void printNodes()
        {
            cout<<"Post Ordered value of Heap nodes:"<<"\n";
            printPostOrderNodes(root);
        }

        void printOddNodesInPreOrder(node *root)
        {
            if(root==NULL)
                return;

            else
            {
                if((root->value%2)!=0)
                    cout<<root->value<<" ";

                printOddNodesInPreOrder(root->left);
                printOddNodesInPreOrder(root->right);
            }
        }

        void find_Odd_Numbers_Of_the_Heap()
        {
            cout<<"\n\nPre Ordered value of Odd Numbered nodes:"<<"\n";
            printOddNodesInPreOrder(root);
        }
};

int main()
{
    tree t;
    t.insertToHeap(14);
    t.insertToHeap(12);
    t.insertToHeap(3);
    t.insertToHeap(17);
    t.insertToHeap(8);
    t.insertToHeap(15);
    t.printNodes();
    t.find_Odd_Numbers_Of_the_Heap();
    return 0;
}
