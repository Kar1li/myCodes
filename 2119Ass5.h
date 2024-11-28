#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct control
{
    vector<long long int> arr;

    void print() {
        for (auto i : arr) {
            cout << i << ", ";
        } cout << endl;
    }

    void insert(long long int x) { 
        arr.push_back(x);  
        for (long long int i = arr.size(); --i >= 0; ) {
            if (arr[i] < x ) {
                for (long long int j = arr.size(); --j > i; ) {
                    arr[j] = arr[j - 1];
                } arr[i + 1] = x;
                return;
            }
            if (i == 0) {
                for (long long int j = arr.size(); --j > i; ) {
                    arr[j] = arr[j - 1];
                } arr[0] = x;
                return;               
            }
        }
    }

    void remove(long long int x) {
        for (long long int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                for (long long int j = i; j < arr.size() - 1; j++) {
                    arr[j] = arr[j + 1];
                } arr.pop_back(); return; 
            }
        } 
    }

    long long int findKth(long long int k) { return arr[k - 1]; }

    long long int index(long long int x) {for (long long int i = 0; i < arr.size(); ++i) { if (arr[i] == x) {return i + 1; }}}

    long long int sum(long long k) {
        long long int SUM = 0;
        for (long long int i = 0; i < k; ++i) {
            SUM += arr[i];
        } return SUM;
    }
};

struct treeNode
{
    long long int val;
    long long int size;
    long long int sum;
    long long int height;
    long long int level;
    treeNode * parent;
    treeNode * left;
    treeNode * right;

    void init(long long int n)
    {
        height = 0;
        level = 0;
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
    long long int level;

    void print()
    {
        list<treeNode * > task;
        task.push_back(root);
        long long int currLv = 0, prevLv = 0;
        while (!task.empty())
        {
            treeNode * curr = task.front(); task.pop_front();

            if (curr != NULL)
            {
                prevLv = currLv; currLv = curr->level;
                if (prevLv < currLv)
                {
                    cout << endl;
                }                              
                cout << "(" << curr->val << ", " << curr->size << ", " << curr->height << ", " << curr->level << ", " << curr->sum << "), " << endl; 
                task.push_back(curr->left); task.push_back(curr->right);

            }
            else cout << "NULL, \n";
            
        }
        cout << '\n';
    }

    void rightUp(treeNode * node)
    {
        treeNode * p = node->parent, * c = node, * r = node->right, * rl = node->right->left;
        long long int size_rl, sum_rl, height_rl, height_l, height_rr; 


        if (rl != NULL) 
        {
            size_rl = rl->size;    
            sum_rl = rl->sum;
            height_rl = rl->height;
        } 
        else
        {
            size_rl = 0;
            sum_rl = 0;
            height_rl = -1;
        }    
        c->parent = r; c->right = rl; 
        c->level += 1; c->size = c->size - r->size + size_rl; c->sum = c->sum - r->sum + sum_rl; 
        if (c->left != NULL)
        {
            height_l = c->left->height;
        }
        else
        {
            height_l = -1;
        }
        if (height_l > height_rl)
        {
            c->height = 1 + height_l;
        }
        else
        {
            c->height = 1 + height_rl;
        }


        r->left = c; r->parent = p; 
        r->level -= 1; r->size = r->size - size_rl + c->size; r->sum = r->sum - sum_rl + c->sum;
        if (r->right != NULL)
        {
            height_rr = r->right->height;
        }
        else
        {
            height_rr = -1;
        }
        if (height_rr > c->height)
        {
            r->height = 1 + height_rr;
        }
        else
        {
            r->height = 1 + c->height;
        }

        if (p == NULL)
        {
            root = r;
        }
        else
        {
            if (p->left == c)
            {
                p->left = r;
                if (p->right != NULL)
                {
                    if (p->right->height > p->left->height)
                    {
                        p->height = 1 + p->right->height;
                    }
                    else
                    {
                        p->height = 1 + p->left->height;
                    }
                }
                else
                {
                    p->height = 1 + p->left->height;
                }
            }
            else
            {
                p->right = r;
                if (p->left != NULL)
                {
                    if (p->left->height > p->right->height)
                    {
                        p->height = 1 + p->left->height;
                    }
                    else
                    {
                        p->height = 1 + p->right->height;
                    }
                }
                else
                {
                    p->height = 1 + p->right->height;
                }               
            }           
        }
        if (rl != NULL)
        {
            rl->parent = c;
        }
        
    }

    void leftUp(treeNode * node)
    {
        treeNode * p = node->parent, * c = node, * l = node->left, * lr = node->left->right;
        long long int size_lr, sum_lr, height_lr, height_r, height_ll; 


        if (lr != NULL) 
        {
            size_lr = lr->size;    
            sum_lr = lr->sum;
            height_lr = lr->height;
        } 
        else
        {
            size_lr = 0;
            sum_lr = 0;
            height_lr = -1;
        }    
        c->parent = l; c->left = lr; 
        c->level += 1; c->size = c->size - l->size + size_lr; c->sum = c->sum - l->sum + sum_lr; 
        if (c->right != NULL)
        {
            height_r = c->right->height;
        }
        else
        {
            height_r = -1;
        }
        if (height_r > height_lr)
        {
            c->height = 1 + height_r;
        }
        else
        {
            c->height = 1 + height_lr;
        }


        l->right = c; l->parent = p; 
        l->level -= 1; l->size = l->size - size_lr + c->size; l->sum = l->sum - sum_lr + c->sum;
        if (l->left != NULL)
        {
            height_ll = l->left->height;
        }
        else
        {
            height_ll = -1;
        }
        if (height_ll > c->height)
        {
            l->height = 1 + height_ll;
        }
        else
        {
            l->height = 1 + c->height;
        }

        if (p == NULL)
        {
            root = l;
        }
        else
        {
            if (p->left == c)
            {
                p->left = l;
                if (p->right != NULL)
                {
                    if (p->right->height > p->left->height)
                    {
                        p->height = 1 + p->right->height;
                    }
                    else
                    {
                        p->height = 1 + p->left->height;
                    }
                }
                else
                {
                    p->height = 1 + p->left->height;
                }
            }
            else
            {
                p->right = l;
                if (p->left != NULL)
                {
                    if (p->left->height > p->right->height)
                    {
                        p->height = 1 + p->left->height;
                    }
                    else
                    {
                        p->height = 1 + p->right->height;
                    }
                }
                else
                {
                    p->height = 1 + p->right->height;
                }               
            }           
        }
        if (lr != NULL)
        {
            lr->parent = c;
        }
        
    }   

    void balance(treeNode ** prev)
    {
        long long int 
        h1 = ((*prev)->left == NULL) ? -1 : (*prev)->left->height,
        h2 = ((*prev)->right == NULL) ? -1 : (*prev)->right->height;
        if (h1 > h2 + 1)
        {
            long long int
                h11 = ((*prev)->left->left == NULL) ? -1 : (*prev)->left->left->height,
                h12 = ((*prev)->left->right == NULL) ? -1 : (*prev)->left->right->height;
            if ((*prev)->left->right != NULL) {
                h12 = (*prev)->left->right->height;
            } else h12 = -1;
            if ((*prev)->left->left != NULL) {
                h11 = (*prev)->left->left->height;
            } else h11 = -1;
            long long int H2;
            if (h2 > h12) {
                H2 = h2 + 1;
            } else H2 = h12 + 1;
            if (H2 > h11 + 1)
            {
                rightUp((*prev)->left);
                leftUp((*prev));
            }
            else
            {
                leftUp((*prev));
            }               
            *prev = (*prev)->parent;
        }
        else if ( h2 > h1 + 1)
        {
            long long int 
                h21 = ((*prev)->right->left == NULL) ? -1 : (*prev)->right->left->height,
                h22 = ((*prev)->right->right == NULL) ? -1 : (*prev)->right->right->height;
            if ((*prev)->right->left != NULL) {
                h21 = (*prev)->right->left->height;
            } else h21 = -1;
            if ((*prev)->right->right != NULL) {
                h22 = (*prev)->right->right->height;
            } else h22 = -1;
            long long int H1;
            if (h1 > h21) {
                H1 = h1 + 1;
            } else H1 = h21 + 1;
            if (H1 > h22 + 1)
            {
                leftUp((*prev)->right);
                rightUp((*prev));
            }
            else
            {
                rightUp((*prev));
            }
            *prev = (*prev)->parent;
        }       
    }
    
    void insert(long long int val)
    {
        treeNode * prev = NULL;
        treeNode * curr = root;
        long long int level = 0;
        while (curr != NULL)
        {
            curr->size += 1;
            curr->sum += val;
            prev = curr;
            if (curr->val > val) {
                curr = curr->left;
            } else curr = curr->right;
            ++level;
        }
        treeNode * node = new treeNode; node->init(val); node->level = level;
        if (prev == NULL) {
            root = node;
        } else if (prev->val > val) {
            prev->left = node;
        } else {
            prev->right = node;
        } node->parent = prev;
        while (prev != NULL)
        {
            long long int H, h1, h2, h, h11, h12, h21, h22;
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
                balance(&prev);
                prev = prev->parent;
            } else break;
        }
    }

    bool isAVL(treeNode * node)
    {
        if (node == NULL)
        {
            return true;
        }
        else
        {
            long long int h1, h2;
            if (node->left != NULL) {
                h1 = node->left->height;
            } else h1 = -1;
            if (node->right != NULL) {
                h2 = node->right->height;
            } else h2 = -1;
            if (isAVL(node->left) && isAVL(node->right) && (h1 - h2 <= 1 && h1 - h2 >= -1))
            {
                return true;
            }
            else
            {
                printf("failAt: %lld, %lld\n", node->val, node->height);
                return false;
            }
        }
    }

    void updateHeight(treeNode * prt) {
        long long int 
            h2 = (prt->right == NULL) ? -1 : prt->right->height,
            h1 = (prt->left == NULL) ? -1 : prt->left->height;
        prt->height = 1 + ((h2 > h1) ? h2 : h1);
    }

    void remove(long long int x)
    {
        treeNode * curr = root;
        treeNode * next = NULL, * prt = NULL;
        while (curr != NULL)
        {
            if (curr->val == x)
            {
                prt = curr->parent;
                if (curr->right == NULL)
                {
                    if (curr->left == NULL)
                    {
                        if (prt == NULL) root = NULL;
                        else
                        {
                            if (curr->val < prt->val) {
                                prt->left = NULL;
                            } else prt->right = NULL;
                            do {
                                prt->size -= 1; prt->sum -= curr->sum;
                                updateHeight(prt);
                                balance(&prt);
                                prt = prt->parent;
                            } while (prt != NULL);
                        }
                        delete curr; 
                    }
                    else
                    {
                        curr->val = curr->left->val; curr->size = 1; curr->sum = curr->left->val; curr->height = 0; curr->left = NULL;
                        prt = curr->parent;                        
                        while (prt != NULL)
                        {
                            prt->size -= 1; prt->sum -= x;
                            updateHeight(prt);
                            balance(&prt);
                            prt = prt->parent;
                        } 
                        delete curr->left;
                    }
                }
                else
                {
                    next = curr->right;
                    while (next->left != NULL) {
                        next = next->left;
                    }
                    curr->val = next->val;
                    prt = next->parent;
                    long long int nextVal = next->val;
                    if (next->right != NULL) 
                    {
                        next->val = next->right->val; next->size = 1; next->sum = next->val; next->height = 0;
                        delete next->right;
                        next->right = NULL;
                    } 
                    else
                    {
                        if (prt != curr) prt->left = NULL;
                        else curr->right = NULL;
                        delete next;
                    }
                    while (prt != curr)
                    {
                        prt->size -= 1; prt->sum -= nextVal;
                        updateHeight(prt);
                        balance(&prt);
                        prt = prt->parent;
                    }
                    while (prt != NULL)
                    {
                        prt->size -= 1; prt->sum -= x;
                        updateHeight(prt);
                        balance(&prt);
                        prt = prt->parent;                       
                    }
                }
                return;
            }
            else if (curr->val > x) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }       
    }

    long long int findKth(long long int k)
    {
        treeNode * curr = root;
        long long int a = 0;
        while (curr != NULL) {
            long long int index;
            if (curr->left != NULL) index = a + curr->left->size;
            else index = a;
            if (index == k - 1) {
                return curr->val;
            } else if (index > k - 1) {
                curr = curr->left;
            } else {
                a = index + 1; 
                curr = curr->right;
            }
        }
    }
    
    long long int Index(long long int x)
    {
        treeNode * curr = root;
        long long int a = 0;
        while (curr != NULL) {
            long long int index;
            if (curr->left != NULL) index = a + curr->left->size;
            else index = a;
            if (curr->val == x) {
                return index + 1;
            } else if (curr->val > x) {
                curr = curr->left;
            }  else {
                a = index + 1; 
                curr = curr->right;
            }
        }
    }   

    long long int Sum(long long int k)
    {
        treeNode * curr = root;
        long long int a = 0, Sum;

        if (curr == NULL) return 0;
        else Sum = curr->sum;
         
        while (curr != NULL)
        {
            long long int index;
            if (curr->left != NULL) index = a + curr->left->size;
            else index = a;
            if (index == k - 1)
            {
                if (curr->right != NULL) {
                    Sum -= curr->right->sum;
                } return Sum;
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
