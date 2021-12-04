#include <iostream>
#define MAX_ELEMENT 200
using namespace std;

class heapnode
{
    int key;
public:
    heapnode(int k=0):key(k){}
    void setkey(int k){key=k;}
    int getkey(){return key;}
    void display(){printf("%4d", key);}
};
class minheap
{
    heapnode node[MAX_ELEMENT];
    int size;
public:
    minheap():size(0){}
    bool isEmpty() {return size==0;}
    bool isFull() {return size==MAX_ELEMENT-1;}
    heapnode& getParent(int i) {return node[i/2];}
    heapnode& getLeft(int i) {return node[i*2];}
    heapnode& getRight(int i) {return node[i*2+1];}
    void insert(int key)
    {
        if(isFull()) return;
        int i=++size;
        while(i!=1&key<getParent(i).getkey())
        {
            node[i]=getParent(i);
            i/=2;
        }
        node[i].setkey(key);
    }
    heapnode remove()
    {
        if(isEmpty()) return NULL;
        heapnode root=node[1];
        heapnode last=node[size--];
        int parent=1;
        int child=2;
        while(child<=size)
        {
            if(child<size&&getLeft(parent).getkey()>getRight(parent).getkey())
                ++child;
            if(last.getkey()<=node[child].getkey()) break;
            node[parent]=node[child];
            parent=child;
            child*=2;
        }
        node[parent]=last;
        return root;

    }
};

void maketree(int freq[], int n)
{
    minheap heap;
    for(int i=0;i<n;++i)
        heap.insert(freq[i]);
    for(int i=1;i<n;++i)
    {
        heapnode e1=heap.remove();
        heapnode e2=heap.remove();
        heap.insert(e1.getkey()+e2.getkey());
        printf("(%d+%d)\n", e1.getkey(),e2.getkey());
    }
}

int main()
{
    int freq[]={15,12,8,6,4};
    maketree(freq,5);
    return 0;
}
