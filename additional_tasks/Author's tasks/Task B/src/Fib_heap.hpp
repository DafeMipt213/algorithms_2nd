#pragma once
const int kMaxDegree = 30;

template <class T> class Node {
public:
  Node<T> *left;
  Node<T> *right;
  Node<T> *child;
  Node<T> *parent;
  T key;
  int degree;
  bool is_descendant_lost;

  Node(T key);
};

template <class T> class FibonacciHeap {
protected:
  Node<T> *min_;

public:
  FibonacciHeap();

  ~FibonacciHeap();

  Node<T> *Insert(T key);

  void Merge(FibonacciHeap &other);

  bool IsEmpty();

  void RemoveMinimum();

  void DecreaseKey(Node<T> *n, int key);

  Node<T> *Find(int key);

  T GetMinimum();

private:
  Node<T> *Empty();

  Node<T> *Merge(Node<T> *first_heap, Node<T> *second_heap);

  void DeleteAll(Node<T> *heap);

  void AddChild(Node<T> *parent, Node<T> *child);

  void UnMarkMinChild(Node<T> *element);

  Node<T> *RemoveMinimum(Node<T> *heap);

  Node<T> *Cut(Node<T> *heap, Node<T> *n);

  Node<T> *DecreaseKey(Node<T> *heap, Node<T> *element, int key);

  Node<T> *Find(Node<T> *heap, int key);
};