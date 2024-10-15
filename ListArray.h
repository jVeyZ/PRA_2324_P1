#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
      T* arr;
      int max;
      int n;
      static const int MINSIZE; 

      void resize(int new_size);


    public:
      void insert(int pos, T e) override {

      }
      void append(T e) override{

      }
      void prepend(T e) override{

      }
      

};
