#include <iostream>
#include <cmath>
using namespace std;

int I=0;

int reverse_1(int n) {
    int reversedNumber = 0, remainder;
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    return reversedNumber;
}


struct Node
{
    int val;
    Node *left;
    Node *right;
    Node (int v):val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree
{

    Node *root;

    void add(int x, Node *ptr)
    {
        if (ptr==nullptr)
            root=new Node(x);
        else if (ptr->val<x)
        {
            if (ptr->right==nullptr)
                ptr->right= new Node(x);
            else
                add(x,ptr->right);
        }
        else
        {
            if (ptr->left==nullptr)
                ptr->left=new Node(x);
            else
                add(x,ptr->left);
        }
    }



    void print_right(Node *ptr, int a=1)
    {
        if (ptr!=nullptr)
        {
            I++;
            print_left(ptr->left, a*10+2);
            int b=reverse_1(a);
            for(int j=0; j<I; j++)
            {
                int c=b%10;
                if (c==2)
                cout<<"  | ";
                else
                cout<<"    ";
                if (j+1==I)
                    cout<<"  '->";
                b=b/10;
            }
            cout<<ptr->val<<"\n";
            print_right(ptr->right, a*10+1);
            I=I-1;
        }
        else
        {
            int b=reverse_1(a);
            for(int j=0; j<I+1; j++)
            {
                int c=b%10;
                if (c==2)

                cout<<"  | ";
                if (c==1)
                cout<<"    ";
                if (j==I)
                    cout<<"  '->nullptr\n";
                b=b/10;
            }
        }
    }


    void print_left(Node *ptr, int a=1)
    {
        if (ptr!=nullptr)
        {
            I++;
            print_left(ptr->left, a*10+1);
            int b=reverse_1(a);
            for(int j=0; j<I; j++)
            {
                int c=b%10;
                if (c==2)
                cout<<"  | ";
                else
                cout<<"    ";
                if (j+1==I)
                    cout<<"  ,->";
                b=b/10;
            }
            cout<<ptr->val<<"\n";
            print_right(ptr->right, a*10+2);
            I=I-1;
        }
        else
        {
           int b=reverse_1(a);
            for(int j=0; j<I+1; j++)
            {
                int c=b%10;
                if (c==2)
                cout<<"  | ";
                if (c==1)
                cout<<"    ";
                if (j==I)
                    cout<<"  ,->nullptr\n";
                b=b/10;
            }
        }
    }


    void print(Node *ptr)
    {
        if (ptr!=nullptr)
        {
            print_left(ptr->left);
            cout<<"   ->"<<ptr->val<<"\n";
            print_right(ptr->right);
        }
    }


    int search_tree(int x,Node *ptr)
    {
        if (ptr==nullptr)
            return 0;
        else if (ptr->val==x)
            return 1;
        if (ptr->val<x)
        {
            search_tree(x,ptr->right);
        }
        else
        {
            search_tree(x,ptr->left);
        }
    }

public:
    BinaryTree(): root(nullptr) {}

    void clear_tree(Node *ptr)
    {
        if (ptr != nullptr)
        {
            clear_tree(ptr->left);
            clear_tree(ptr->right);
            delete ptr;
        }
    }

    ~BinaryTree()
    {
        clear_tree(root);
    }

    void add(int x)
    {
        add(x,root);
    }

    void print()
    {
        print(root);
    }
    int search_tree(int x)
    {
        return search_tree(x,root);
    }

};
int main()
{
    BinaryTree x;
    x.add(12);
    x.add(13);
    x.add(11);
    x.add(13);
    x.add(10);
    x.add(11);
    x.print();
    cout<<"\n";

    return 0;
}
