/*
DSA Toolkit Project
Language: C++
Concepts Used:
- Arrays
- Sorting Algorithms
- Dynamic Memory Allocation
- Linked List
- Stack
- Queue
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*=================================================
                ARRAY OPERATIONS
=================================================*/

void traverseArray(const vector<int>& arr){
    for(int num : arr) cout<<num<<" ";
    cout<<endl;
}

void insertElement(vector<int>& arr, int value, int pos){
    if(pos < 0 || pos > arr.size()){
        cout<<"Invalid position\n";
        return;
    }
    arr.insert(arr.begin()+pos, value);
}

void deleteElement(vector<int>& arr, int pos){
    if(pos < 0 || pos >= arr.size()){
        cout<<"Invalid position\n";
        return;
    }
    arr.erase(arr.begin()+pos);
}

void updateElement(vector<int>& arr, int pos, int value){
    if(pos < 0 || pos >= arr.size()){
        cout<<"Invalid position\n";
        return;
    }
    arr[pos] = value;
}

void countValues(const vector<int>& arr){
    int pos=0, neg=0, odd=0, even=0;

    for(int num : arr){
        if(num>=0) pos++; else neg++;
        if(num%2==0) even++; else odd++;
    }

    cout<<"Positive:"<<pos<<" Negative:"<<neg
        <<" Even:"<<even<<" Odd:"<<odd<<endl;
}

void reverseArray(vector<int>& arr){
    reverse(arr.begin(), arr.end());
}

void removeDuplicates(vector<int>& arr){
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
}

void rotateArray(vector<int>& arr, int k){
    int n = arr.size();
    if(n==0) return;

    k %= n;

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
}

void findLeaders(const vector<int>& arr){
    if(arr.empty()) return;

    int maxRight = arr.back();
    cout<<"Leaders: "<<maxRight<<" ";

    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i] > maxRight){
            maxRight = arr[i];
            cout<<maxRight<<" ";
        }
    }
    cout<<endl;
}

/*=================================================
                SORTING
=================================================*/

void bubbleSort(vector<int>& arr){
    for(int i=0;i<arr.size()-1;i++){
        bool swapped=false;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

void selectionSort(vector<int>& arr){
    for(int i=0;i<arr.size()-1;i++){
        int minIndex=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minIndex]) minIndex=j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

void insertionSort(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// Merge Sort
void merge(vector<int>& arr,int l,int m,int r){
    vector<int> temp;
    int i=l,j=m+1;

    while(i<=m && j<=r){
        if(arr[i]<=arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while(i<=m) temp.push_back(arr[i++]);
    while(j<=r) temp.push_back(arr[j++]);

    for(int k=0;k<temp.size();k++)
        arr[l+k]=temp[k];
}

void mergeSort(vector<int>& arr,int l,int r){
    if(l>=r) return;

    int m=l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

// Quick Sort
int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

/*=================================================
            DYNAMIC MEMORY
=================================================*/

void heapAllocationDemo(int size){
    int* arr = new int[size];

    for(int i=0;i<size;i++)
        cin>>arr[i];

    cout<<"Heap Elements: ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    delete[] arr;
}

void stackVsHeapDemo(){
    int stackVar = 10;

    int* heapVar = new int;
    *heapVar = 20;

    cout<<"Stack:"<<stackVar<<endl;
    cout<<"Heap:"<<*heapVar<<endl;

    delete heapVar;
}

/*=================================================
            LINKED LIST
=================================================*/

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class SinglyLinkedList{

    Node* head;

public:

    SinglyLinkedList(){
        head=NULL;
    }

    void insertAtEnd(int val){
        Node* newNode=new Node(val);

        if(!head){
            head=newNode;
            return;
        }

        Node* temp=head;
        while(temp->next) temp=temp->next;

        temp->next=newNode;
    }

    void deleteNode(int pos){
        if(!head) return;

        Node* temp=head;

        if(pos==0){
            head=head->next;
            delete temp;
            return;
        }

        for(int i=0;i<pos-1 && temp->next;i++)
            temp=temp->next;

        if(!temp->next) return;

        Node* del=temp->next;
        temp->next=del->next;
        delete del;
    }

    void updateNode(int pos,int val){
        Node* temp=head;

        for(int i=0;i<pos && temp;i++)
            temp=temp->next;

        if(temp) temp->data=val;
    }

    void traverse(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    ~SinglyLinkedList(){
        while(head){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
};

/*=================================================
                    STACK
=================================================*/

class Stack{
    int* arr;
    int top;
    int cap;

public:

    Stack(int size){
        cap=size;
        arr=new int[cap];
        top=-1;
    }

    bool isEmpty(){ return top==-1; }
    bool isFull(){ return top==cap-1; }

    void push(int val){
        if(isFull()){
            cout<<"Overflow\n";
            return;
        }
        arr[++top]=val;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Underflow\n";
            return;
        }
        cout<<"Popped:"<<arr[top--]<<endl;
    }

    void peek(){
        if(!isEmpty())
            cout<<"Top:"<<arr[top]<<endl;
    }

    ~Stack(){
        delete[] arr;
    }
};

/*=================================================
                    QUEUE
=================================================*/

class Queue{
    int* arr;
    int front,rear,size,cap;

public:

    Queue(int c){
        cap=c;
        arr=new int[cap];
        front=0;
        rear=-1;
        size=0;
    }

    bool isEmpty(){ return size==0; }
    bool isFull(){ return size==cap; }

    void enqueue(int val){
        if(isFull()){
            cout<<"Overflow\n";
            return;
        }

        rear=(rear+1)%cap;
        arr[rear]=val;
        size++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Underflow\n";
            return;
        }

        cout<<"Dequeued:"<<arr[front]<<endl;
        front=(front+1)%cap;
        size--;
    }

    void display(){
        for(int i=0;i<size;i++)
            cout<<arr[(front+i)%cap]<<" ";
        cout<<endl;
    }

    ~Queue(){
        delete[] arr;
    }
};

/*=================================================
                    MAIN
=================================================*/

int main(){

    vector<int> arr = {5,2,8,1,3};

    cout<<"Original Array:\n";
    traverseArray(arr);

    bubbleSort(arr);
    cout<<"After Bubble Sort:\n";
    traverseArray(arr);

    reverseArray(arr);
    cout<<"After Reverse:\n";
    traverseArray(arr);

    // Linked List Demo
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout<<"\nLinked List:\n";
    list.traverse();

    // Stack Demo
    Stack st(5);
    st.push(100);
    st.push(200);
    st.peek();
    st.pop();

    // Queue Demo
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<"\nQueue:\n";
    q.display();
    q.dequeue();

    return 0;
}

