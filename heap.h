#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

using namespace std; 

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   * 
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  vector<T> heap_list;
  int m;
  PComparator c;

  void upHeap(size_t index);
  void downHeap(size_t index);

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m(m), c(c)
{
  if (m < 2)
  {
    throw invalid_argument("Heap must have at least 2 children!");
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heap_list.push_back(item);
  upHeap(heap_list.size()-1); //sorts the heap
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty())
  {
    throw underflow_error ("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_list.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty())
  {
    throw underflow_error ("Heap is empty");
  }

  swap(heap_list.front(), heap_list.back());
  heap_list.pop_back();
  downHeap(0);
  
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::upHeap(size_t index)
{
  while (index > 0) 
  {
      size_t parent = (index - 1) / m;
      if (!c(heap_list[index], heap_list[parent]))  //checks heap property
      {
          break;  // Heap property is satisfied
      }
      swap(heap_list[index], heap_list[parent]); 
      index = parent;
  }
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::downHeap(size_t index)
{
  while (true) 
  {
    size_t best = index;
    for (size_t i = 1; i <= m; ++i) 
    {
        size_t child = m * index + i; //gets child
        if (child < heap_list.size() && c(heap_list[child], heap_list[best]))  //compares best data and child data
        {
            best = child;
        }
    }
    if (best == index) //checks heap property
    {
        break;  // Heap property restored
    }
    swap(heap_list[index], heap_list[best]); //swaps
    index = best; //gets the new best index
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heap_list.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap_list.size();
}


#endif

