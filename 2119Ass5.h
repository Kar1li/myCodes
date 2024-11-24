#include <iostream>


#include <list>





struct treeNode
{
    long long int val;
    long long int size;
    long long int sum;
    long long int height;
    treeNode * parent;
    treeNode * left;
    treeNode * right;

    void init(long long int n)
    {
        height = 0;
        parent = NULL;
        left = NULL;
        right = NULL;
        val = n;
        size = 1;
        sum = n;
    }
};


struct tree
{
    treeNode * root; 

    void print()
    {
        list<treeNode * > task;
        task.push_back(root);
        while (!task.empty())
        {
            treeNode * curr = task.front(); task.pop_front();
            if (curr != NULL)
            {
                cout << "( " << curr->val << ", " << curr->size << ", " << curr->height << ", " << curr->sum << "), " << endl; 
                task.push_back(curr->left); task.push_back(curr->right);
            }
            else cout << "NULL, \n";
            
        }
        cout << '\n';
    }
    
    void insert(long long int val)
    {
        treeNode * prev = NULL;
        treeNode * curr = root;
        while (curr != NULL)
        {
            curr->size += 1;
            curr->sum += val;
            prev = curr;
            if (curr->val > val)
            {
                curr = curr->left;
            }
            else curr = curr->right;
        }
        treeNode * node = new treeNode; node->init(val);
        if (prev == NULL)
        {
            root = node;
        }
        else if (prev->val > val)
        {
            prev->left = node;
        }
        else prev->right = node;
        node->parent = prev;
        while (prev != NULL)
        {
            long long int H, h1, h2, h;
            H = prev->height;
            if (prev->left != NULL) {
                h1 = prev->left->height;
            } else h1 = -1;
            if (prev->right != NULL) {
                h2 = prev->right->height;
            } else h2 = -1;
            if (h1 > h2) {
                h = h1 + 1;
            } else h = h2 + 1;
            if (h > H) {
                prev->height = h;
                prev = prev->parent;
            } else break;
        }
    }


    long long int findKth(long long int k)
    {
        treeNode * curr = root;
        long long int a = 0, b = root->size - 1;
        while (curr != NULL)
        {
            long long int index;
            if (curr->left != NULL) index = a + curr->left->size;
            else index = a;
            if (index == k - 1)
            {
                return curr->val;
            }
            else if (index > k - 1)
            {
                curr = curr->left;
            }
            else
            {
                a = index + 1; 
                curr = curr->right;
            }
        }
    }
    
    long long int Index(long long int x)
    {
        treeNode * curr = root;
        long long int a = 0;
        while (curr != NULL)
        {
            long long int index;
            if (curr->left != NULL) index = a + curr->left->size;
            else index = a;
            if (curr->val == x)
            {
                return index;
            }
            else if (curr->val > x)
            {
                curr = curr->left;
            }
            else
            {
                a = index + 1; 
                curr = curr->right;
            }
        }
    }   

    long long int Sum(long long int k)
    {
        treeNode * curr = root;
        long long int a = 0, b = root->size - 1, Sum;

        if (curr == NULL) return 0;
        else Sum = curr->sum;
         
        while (curr != NULL)
        {
            long long int index;
            if (curr->left != NULL) index = a + curr->left->size;
            else index = a;
            if (index == k - 1)
            {
                if (curr->right != NULL)
                {
                    Sum -= curr->right->sum;
                }
                return Sum;
            }
            else if (index > k - 1)
            {
                if (curr->right != NULL)
                Sum -= curr->val + curr->right->sum;
                else Sum -= curr->val;
                curr = curr->left;
            }
            else
            {
                a = index + 1; 
                curr = curr->right;
            }
        }
    }
    
};