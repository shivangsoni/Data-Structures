class MaxPriorityQueue
{
public:
int n;
int priority[1000];
int count;
int p[1000000];
MaxPriorityQueue();
MaxPriorityQueue(int a);
void insert(int k);
int removeMax();
int removeKey(int k);
void change(int k,int newk);
void heapifyup(int k);
void heapifydown(int k);
void heapifydown1(int* p,int n,int k);
void heapsort(int priorityArray[],int n);
};

