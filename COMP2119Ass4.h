#include "stdio.h"
#define MAX 63

struct priorityQueue
{
    int arr[MAX];
    int size;
    int max;

    void init(int n)
    {
        size = 0;
        max = n;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    void insert(int val)
    {
        arr[size++] = val;
        // t - 2 ) / 2 or t - 1 / 2
        int curr = size - 1;
        int prt = (curr - 1) / 2;
        while (curr > 0)
        {
            int check = arr[prt] < arr[curr] - 1 + max;
            if ((arr[prt] < arr[curr]) - 1 + max)
            {
                int temp = arr[prt]; arr[prt] = arr[curr], arr[curr] = temp;
            }
            else break;
            curr = prt; prt = (curr - 1) / 2;
        }
    }

    int dequeue()
    {
        if (size == 0)
        {
            return NULL;
        }
        int ret = arr[0];
        arr[0] = arr[--size];
        int curr = 0; int left = 2 * curr + 1; int right = left + 1;
        int leftNode, rightNode;
        while (1)
        {
            if (left < size - 1)
            {
                leftNode = arr[left];
                rightNode = arr[right];
                if ((leftNode > rightNode ) - 1 + max )
                {
                    if ((leftNode > arr[curr]) - 1 + max)
                    {
                        arr[left] = arr[curr]; arr[curr] = leftNode;
                        curr = left; 
                    } else break; 
                }
                else
                {
                    if ((rightNode > arr[curr]) - 1 + max)
                    {
                        arr[right] = arr[curr]; arr[curr] = rightNode;
                        curr = right;
                    } else break;
                }
            }
            else if (left == size - 1)
            {
                leftNode = arr[left];
                if ((leftNode > arr[curr]) - 1 + max)
                {
                    arr[left] = arr[curr]; arr[curr] = leftNode;
                    curr = left; 
                } else break; 
            }
            else
            {
                break;
            }
            left = 2 * curr + 1; right = left + 1;
        }


        return ret;
    }
    
};




struct medianFinder
{
    priorityQueue smallerHalf; // this is a max priority queue
    priorityQueue greaterHalf; // this is a min priority queue
    int size1; // size of the smaller half
    int size2; // size of the greater half

    void MedianFinder()
    {
        smallerHalf.init(1);
        greaterHalf.init(0);
        size1 = 0;
        size2 = 0;
    }

    void print()
    {
        smallerHalf.print();
        greaterHalf.print();
        printf("\n");
    }

    double findMedian()
    {
        if (size1 == size2)
        {
            return .5 * ( smallerHalf.arr[0] + greaterHalf.arr[0] ); 
        }
        else if (size1 > size2) 
        {
            return smallerHalf.arr[0];
        }
        else
        {
            return greaterHalf.arr[0];
        }
    }

    void addNum(int num)
    {
        if (size1 == 0 && size2 == 0)
        {
            smallerHalf.insert(num);
            ++size1;
            return;
        }
        if (size2 == 0)
        {
            if (smallerHalf.arr[0] > num)
            {
                smallerHalf.insert(num); int _ = smallerHalf.dequeue(); greaterHalf.insert(_);
            }
            else greaterHalf.insert(num);
            ++size2;
            return;
        }
       
        int left = smallerHalf.arr[0];
        int right = greaterHalf.arr[0];
        if (size1 == size2)
        {
            if (num >= right)
            {
                greaterHalf.insert(num);
                ++size2;
            }
            else
            {
                smallerHalf.insert(num);
                ++size1;
            }
        }
        else if (size1 > size2)
        {
            if (num <= left)
            {
                smallerHalf.insert(num);
                int _ = smallerHalf.dequeue();
                greaterHalf.insert(_);
            }
            else
            {
                greaterHalf.insert(num);
            }
            ++size2;
        }
        else
        {
            if (num >= right)
            {
                greaterHalf.insert(num);
                int _ = greaterHalf.dequeue();
                smallerHalf.insert(_);
            }
            else
            {
                smallerHalf.insert(num);
            }
            ++size1;
        }
    }
    
};

// 1 2 4 8 16 ...
// size = 2^n - 1 + m
// size / 2 = 2 ^ (n - 1) - .5 + m / 2

    // size is odd, m is even, 0 <= m <= 2 ^ n - 2 
    // mid = 2 ^ (n - 1) - 1 + 1 + m / 2 = size / 2 + .5

    // size is even, m is odd
    // mid = size / 2, size / 2 + 1

// 13, 6
    // 1 2 4 6

// 11, 5
    // 1 2 4 4

// odd -> even
