#include <iostream>
#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
      T* arr;
      int max;
      int n;
      static const int MINSIZE = 2; 

      void resize(int new_size){
       T* newArr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        max = new_size;
      };


    public:
      ListArray(){
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
      }

      ~ListArray(){
        delete arr;
      }

      void insert(int pos, T e) {
        try {
          if (pos <= n && pos >= 0) {
            if (n == max) {
              resize(max * 2);
            }
            for (int i = n; i > pos; --i) {
              arr[i] = arr[i - 1];
            }
            arr[pos] = e;
            ++n;
          } else {
            throw std::out_of_range("Position out of range");
          }
        } catch (const std::out_of_range& e) {
          std::cout << e.what() << std::endl;
        }

      }

      void append(T e){
        insert(n, e);
      }

      void prepend(T e)  {
        insert(0, e); 
      }

      T remove(int pos)   {
        int val;
        try {
          if (pos < n && pos >= 0) {
            val = arr[pos];
            for (int i = pos; i < n - 1; ++i) {
              arr[i] = arr[i + 1];
            }
            --n;
          } else {
            throw std::out_of_range("");
          }
        } catch (std::out_of_range&) {
          std::cout << "out_of_range \n";
        }
        return val;
      }

      T get(int pos) {
         try {
          if (pos < n && pos >= 0) {
          return arr[pos];
          } 
          else {
          throw std::out_of_range("");
          }
        }
        catch (std::out_of_range()) {
          std::cout << "out_of_range";
        }

      }

      int search(T e)  {
        for (int i = 0; i < n; ++i) {
          if (arr[i] == e) {
        return i;
          }
        }
        return -1;
      }

      bool empty()   {
        if (size() == 0) {
        return true;
        }
      }

      int size()   {
        return n; 
      }

      T operator[](int pos){
        if (pos >= 0 && pos < n) {
          return arr[pos];
        }
        else {
        throw std::out_of_range("");
        }
      }

      friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
          out << list.arr[i];
          if (i < list.n - 1) {
        out << ", ";
          }
        }
        out << "]";
        return out;
      }


};
