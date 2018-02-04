/*
 * C++ Program to Implement Binary Heap
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;
/*
 * Class Declaration
 */
class BinaryHeap
{
  private:
    vector <int> heap;
    int left(int parent);
    int right(int parent);
    int parent(int child);
    void heapifyup(int index);
    void heapifydown(int index);
  public:
    BinaryHeap() {}
    void Insert(int element);
    void DeleteMin();
    int ExtractMin();
    void DisplayHeap();
    int Size();
};
/*
 * Return Heap Size
 */
int BinaryHeap::Size()
{
  return heap.size();
}
 
/*
 * Insert Element into a Heap
 */
void BinaryHeap::Insert(int element)
{
  heap.push_back(element);
  heapifyup(heap.size() -1);
}
/*
 * Delete Minimum Element
 */
void BinaryHeap::DeleteMin()
{
  if (heap.size() == 0)
  {
    cout<<"Heap is Empty"<<endl;
    return;
  }
  heap[0] = heap.at(heap.size() - 1);
  heap.pop_back();
  heapifydown(0);
  cout<<"Element Deleted"<<endl;
}
 
/*
 * Extract Minimum Element
 */
int BinaryHeap::ExtractMin()
{
  if (heap.size() == 0)
    return -1;
  else
    return heap.front();
}
 
/*
 * Display Heap
 */
void BinaryHeap::DisplayHeap()
{
  vector <int>::iterator pos = heap.begin();
  cout<<"Heap -->  ";
  while (pos != heap.end())
  {
    cout<<*pos<<" ";
    pos++;
  }
  cout<<endl;
}
 
/*
 * Return Left Child
 */
int BinaryHeap::left(int parent)
{
  int l = 2 * parent + 1;
  if (l < heap.size())
    return l;
  else
    return -1;
}
 
/*
 * Return Right Child
 */
int BinaryHeap::right(int parent)
{
  int r = 2 * parent + 2;
  if (r < heap.size())
    return r;
  else
    return -1;
}
 
/*
 * Return Parent
 */
int BinaryHeap::parent(int child)
{
  int p = (child - 1)/2;
  if (child == 0)
    return -1;
  else
    return p;
}
 
/*
 * Heapify- Maintain Heap Structure bottom up
 */
void BinaryHeap::heapifyup(int in)
{
  if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
  {
    int temp = heap[in];
    heap[in] = heap[parent(in)];
    heap[parent(in)] = temp;
    heapifyup(parent(in));
  }
}
 
/*
 * Heapify- Maintain Heap Structure top down
 */
void BinaryHeap::heapifydown(int in)
{
 
  int child = left(in);
  int child1 = right(in);
  if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
   child = child1;
  if (child > 0 && heap[in] > heap[child])
  {
    int temp = heap[in];
    heap[in] = heap[child];
    heap[child] = temp;
    heapifydown(child);
  }
}
 
/*
 * Main Contains Menu
 */
int main()
{
  BinaryHeap h;     
  h.Insert(9);
  h.Insert(12);
  h.Insert(8);
  h.Insert(5);
  h.Insert(10);
  h.Insert(3);
  h.DeleteMin();
  cout<< "Minimum Element: ";
  if (h.ExtractMin() == -1)
    cout<<"Heap is Empty"<<endl;
  else
    cout<<"Minimum Element:  "<< h.ExtractMin() <<endl;

  cout<<"Displaying elements of Heap:  ";
  //h.DisplayHeap();
  
  return 0;
}