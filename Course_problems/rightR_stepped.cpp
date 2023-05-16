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
        void right_rotate() {
            if(size == capacity)
            expand_capacity();
            for(int i = size -1; i >=0; i--){
                arr[i+1] = arr[i];
            }
            arr[0] = arr[size];
            arr[size] = '\0';
        }
        void right_rotate(int n) {
            
            int rot_cnt = n % size;
            /* We could just do rotate right n times
            after removing useless no. of rotations 
            by above modulus
            */
           while(rot_cnt--) {
            right_rotate();
           }
           /*int new_ist = size - rot_cnt ;
            int *arr2 = new int[capacity]{};
            int j = 0;
            for(int i = new_ist; i < size; i++) {
                arr2[j++] = arr[i];
            }
            for(int i = 0; i < new_ist; i++) {
                arr2[j++] = arr[i];
            }
            
            swap(arr, arr2);
            delete[] arr2;*/ 
        }
};
int main() {
   Vector vec(5);
   vec.set(2,5);
   vec.set(0,3);
   vec.set(1,8);
   vec.set(3,5);
   vec.push_back(15);
   vec.print();
   vec.right_rotate(3);
   vec.print();
   cout << vec.find(23 ) << endl;
    return 0;
}