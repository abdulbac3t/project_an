#include<iostream>
#include<cassert>
using namespace std;
class Vector {
    private:
       int *arr = nullptr;
       int size { 0 };
       int capacity { };
    public:
       Vector(int size):
         size(size) {
            if(size < 0)
              size = 1;
            capacity = size + 10;
            arr = new int[capacity] {};
         }
         ~Vector() {
            delete[] arr;
            arr = nullptr;
         }
        int get(int idx) {
            assert(0 <= idx && idx < size);
            return arr[idx];
        }
        void set(int idx, int val) {
            assert(0 <= idx && idx < size);
            arr[idx] = val;
        }
        void print() {
            for(int i = 0; i < size; ++i)
              cout << arr[i] << " ";
            cout << "\n";
        }
        int find(int value) {
            for (int i = 0; i < size; ++i)
              if(arr[i] == value)
                 return i;
            return -1;
        }
        void push_back(int value) {
            // when the limit of the size is reached
            if(size == capacity)
               expand_capacity();
            arr[size++] = value;
        }
        void expand_capacity() {
            capacity *= 2;
            cout << " Expand capacity to " << capacity << endl;
            int *arr2 = new int[capacity] {};
            for (int i = 0; i < size; ++i) {
                arr2[i] = arr[i];
            }
            swap(arr, arr2);
            delete[] arr2;
        }
        void insert(int value, int idx) {

            if(size == capacity)
            expand_capacity();
            for(int i = size - 1; i >= idx; i--) {
                 arr[i+1] = arr[i];
            }
           

            arr[idx] = value;
            ++size;
        }
        int find_transposition(int value) {
            int i = 0;
            for(; i < size; i++){
                if(arr[i]==value)
                break;
            }
            arr[i] = arr[i-1];
            arr[i-1] = value;
            return i-1;
        }
};
int main() {
   Vector vec(5);
   vec.set(2,5);
   vec.push_back(15);
   vec.print();
   vec.insert(23,4);
   vec.print();
   //cout << vec.find(15) << endl;
   cout << vec.find_transposition(15) << endl;
   vec.print();
    return 0;
}   