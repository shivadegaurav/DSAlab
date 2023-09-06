//Assignment No.4: BST
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

class BST
{
    node *root;

public:
    BST()
    {
        root = new node;
        root = NULL;
    }
    void insert();
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void minimum();
    void maximum();
    void mirror(node *);
    void swap();
    void search();
    void display();
};

void BST ::insert()
{
    int key;
    cout << "\nEnter the number which you want to insert : ";
    cin >> key;
    node *curr = new node;
    curr->data = key;
    curr->left = curr->right = NULL;
    node *temp;
    if (root == NULL)
    {
        root = curr;
    }
    else
    {
        temp = root;

        while (1)
        {
            if (temp->data < curr->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = curr;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else if (temp->data > curr->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                cout << "\nDuplicate entry found ";
                break;
            }
        }
    }
}
void BST::inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << "  ";
        inorder(temp->right);
    }
}

void BST::preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << "  ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BST::postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << "  ";
    }
}

void BST ::search()
{
    int key;
    int flag = 0;
    int cnt = 0;
    node *temp;
    cout << "\nEnter the number which you want to search : ";
    cin >> key;
    temp = root;
    if (temp != NULL)
    {
        while (1)
        {
            if (temp->data == key)
            {
                cnt = cnt + 1;
                flag = 1;
                break;
            }
            else if (temp->data < key)
            {
                if (temp->right == NULL)
                {
                    cnt = cnt + 1;
                    flag = 0;
                    break;
                }
                else
                {
                    cnt = cnt + 1;
                    temp = temp->right;
                }
            }
            else
            {
                if (temp->left == NULL)
                {
                    cnt = cnt + 1;
                    flag = 0;
                    break;
                }
                else
                {
                    cnt = cnt + 1;
                    temp = temp->left;
                }
            }
        }
        if (flag == 1)
        {
            cout << "\nNumber found ";
        }
        else
        {
            cout << "\nNumber not found";
        }

        cout << "\nComparision required are  : " << cnt;
    }
    else
    {
        cout << "\nRoot is not present ";
    }
}
void BST::minimum()
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    cout << "Minimum element : " << temp->data << endl;
}
void BST::maximum()
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    cout << "Maximum element : " << temp->data << endl;
}
void BST::mirror(node *temp)
{
    if (temp != NULL)
    {
        node *x;
        mirror(temp->left);
        mirror(temp->right);
        x = temp->left;
        temp->left = temp->right;
        temp->right = x;
    }
}

void BST ::display()
{
    cout << "\nInorder traversal : " << endl;
    inorder(root);
    cout << "\nPreorder traversal : " << endl;
    preorder(root);
    cout << "\nPostorder traversal : " << endl;
    postorder(root);
}
void BST ::swap()
{
    mirror(root);
}
int main()
{
    // int n;
    // cout << "\nEnter the root element : ";
    // cin >> n;
    BST obj;
    int ch = 0;
    while (ch < 7)
    {
        cout << "\n***************BINARY SEARCH TREE************************";
        cout << "\n1.Insert \n2.Display \n3.Search \n4.Minimum element \n5.Maximum element \n6.Change the tree \n7.Exit";
        cout << "\n*********************************************************";
        cout << "\nEnter the choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.search();
            break;
        case 4:
            obj.minimum();
            break;
        case 5:
            obj.maximum();
            break;
        case 6:
            obj.swap();
            break;
        default:
            cout << "\nExiting the program......";
        }
    }
}