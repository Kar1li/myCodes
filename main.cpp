#include <iostream>
#include <list>
#include <time.h>
#include <random>
#include <set>
#include <unordered_set>
#include "2119Ass5.h"

using namespace std;

#define forever for (;;) 
#define from for (int i = 
#define to ; i < 
#define pp ; ++i)
#define lli long long int


int main()
{
    srand(time(NULL));
    control ctr;
    tree t; t.root = NULL;
    unordered_set<long long int> record;
    //from 0 to 1024 pp
    forever
    {
        int opNum = rand() % 5 + 1;
        switch (opNum)
        {
        case 1: {
            long long int x = rand() % 1000000000000;
            if (!record.count(x))
            {
                record.insert(x);
                ctr.insert(x); t.insert(x);
                //ctr.print();
                if (!t.isAVL(t.root)) {
                    cout << "insertion error after " << x << " inserted" << endl; 
                    t.print();
                    return 1;
                }
            } break; }
        case 2: {
            if (!record.empty())
            {
                long long int x = ctr.arr[rand() % ctr.arr.size()];
                record.erase(x);
                //cout << "before removal: \n";
                //t.print();
                ctr.remove(x); t.remove(x);
                //cout << x << " remove, " << "after removal: \n";
                //t.print();
                if (!t.isAVL(t.root)) {
                    cout << "deletion error after " << x << " deleted" << endl;
                    t.print();
                    return 2;
                }
            } 
            break; }
        case 3: {
            if (!record.empty()) {
                lli k = rand() % record.size() + 1;
                lli trueFound = ctr.findKth(k);
                lli testedFound = t.findKth(k);
                if (trueFound != testedFound) {
                    cout << "finding error after " << k << " found" << endl;
                    cout << "true found: " << trueFound << " v. " << testedFound << endl;
                    t.print();
                    return 3;
                }
            } break; }
        case 4: {
            if (!record.empty()) {
                long long int x = ctr.arr[rand() % ctr.arr.size()];
                lli trueIndex = ctr.index(x);
                lli testedIndex = t.Index(x);
                if (trueIndex != testedIndex) {
                    cout << "indexing error after " << x << " indexed" << endl;
                    cout << "true index: " << trueIndex << " v. " << testedIndex << endl;
                    t.print();
                    ctr.print();
                    return 4;
                }
            } break; }
        case 5: {
            if (!record.empty()) {
                lli k = rand() % record.size() + 1;
                lli trueSum = ctr.sum(k);
                lli testedSum = t.Sum(k);
                if (trueSum != testedSum) {
                    cout << "summing error after " << k << " summed" << endl;
                    cout << "true sum: " << trueSum << " v. " << testedSum << endl;
                    t.print();
                    return 5;
                }
            } break; }

        
        default:
            break;
        }
        printf("_");
    }
    
   
    cout << "no erorr" << endl;


    return 0;
}
