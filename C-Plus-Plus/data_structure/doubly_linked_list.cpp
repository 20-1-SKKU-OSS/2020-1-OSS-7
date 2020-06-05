#include <iostream>
#include<cstdio>
#include<cstdlib>

struct node {
  int val;
  node *prev;
  node *next;
}*start;

class double_linked_list {
 public:
  double_linked_list() {
    start = NULL;
  }
  void insert_first(int x);
  void insert_last(int x);
  void insert(int x, int order);
  void remove(int x);
  void search(int x);
  void show();
  void reverseShow();
};

void double_linked_list::insert_last(int x) {
  node *t = start;
  if (start != NULL) {
    while (t->next != NULL) {
      t = t->next;
    }
    node *n = new node;
    t->next = n;
    n->prev = t;
    n->val = x;
    n->next = NULL;
  } else {
    node *n = new node;
    n->val = x;
    n->prev = NULL;
    n->next = NULL;
    start = n;
  }
}

void double_linked_list::insert_first(int x){
  node* t = start;

  if(start != NULL){
    node* n = new node;
    n->next = start;
    n->prev = NULL;
    n->val = x;

    start = n;
  }
  else{
    node* n = new node;
    n->val = x;
    n->prev = NULL;
    n->next = NULL;
    start = n;
  }
}

void double_linked_list::insert(int x, int order){
  node* t = start;

  int len = 0;
  while(t != NULL){
    t = t->next;
    len++;
  }

  t = start;
  
  if(order > len){
    std::cout << "The order is too big\n";
    return;
  }

  if(order == 0)
    double_linked_list::insert_first(x);

  else if(order == len)
    double_linked_list::insert_last(x);

  else{
    for(int i = 0; i < order; i++)
      t = t->next;
    node* n = new node;

    n->val = x;
    n->next = t;
    n->prev = t->prev;

    t->prev->next = n;
    t->prev = n;

  }
}


void double_linked_list::remove(int x) {
  node *t = start;
  while (t != NULL && t->val != x) {
    t = t-> next;
  }
  if (t == NULL) {
    return;
  }
  if (t->prev == NULL) {
    if (t->next == NULL) {
      start = NULL;
    } else {
      start = t->next;
      start->prev = NULL;
    }
  } else if (t->next == NULL) {
    t->prev->next = NULL;
  } else {
    t->prev->next = t->next;
    t->next->prev = t->prev;
  }
}

void double_linked_list::search(int x) {
  node *t = start;
  int found = 0;
  while (t != NULL) {
    if (t->val == x) {
      std::cout << "\nFound";
      found = 1;
      break;
    }
    t = t->next;
  }
  if (found == 0) {
    std::cout << "\nNot Found";
  }
}

void double_linked_list::show() {
  node *t = start;
  while (t != NULL) {
    std::cout << t->val << "\t";
    t = t->next;
  }
}

void double_linked_list::reverseShow() {
  node *t = start;
  while (t != NULL && t->next != NULL) {
    t = t->next;
  }
  while (t != NULL) {
    std::cout << t->val << "\t";
    t = t->prev;
  }
}

int main() {
  int choice, x;
  double_linked_list ob;
  do {
    std::cout << "\n1. Insert";
    std::cout << "\n2. Delete";
    std::cout << "\n3. Search";
    std::cout << "\n4. Forward print";
    std::cout << "\n5. Reverse print";
    std::cout << "\n\nEnter you choice : ";
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::cout << "\nEnter the element to be inserted : ";
        std::cin >> x;
        ob.insert(x);
        break;
      case 2:
        std::cout << "\nEnter the element to be removed : ";
        std::cin >> x;
        ob.remove(x);
        break;
      case 3:
        std::cout << "\nEnter the element to be searched : ";
        std::cin >> x;
        ob.search(x);
        break;
      case 4:
        ob.show();
        break;
      case 5:
        ob.reverseShow();
        break;
    }
  } while (choice != 0);
  return 0;
}
