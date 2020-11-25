#include <iostream>
#include <map>

class smartPointerInt {
public:
  int * point = nullptr;// nullptr - нулевой указатель
  static std::map<int*, int> counter;//static - вне класса

  smartPointerInt& operator= (smartPointerInt& right) {
    if(point != nullptr) {
      if(counter[point] == 1)
        delete point;
      counter[point] -= 1;
    }

    if (right.point != nullptr) {
      counter[right.point] += 1;
    }
    point = right.point;

    return *this;
  }

  smartPointerInt& operator= (int * val) {
    if(point != nullptr) {
      if(counter[point] == 1)
        delete point;
      counter[point] -= 1;
    }

    if (val != nullptr) {
      counter[val] += 1;
    }
    point = val;

    return *this;
  }

  ~smartPointerInt() {
    if(counter[point] == 1) {
      std::cout << "delete"<<std::endl;
      delete point;
    } else  {
      std::cout << "not delete" << std::endl;
    }
    counter[point] -= 1;
  }
};

std::map<int *, int> smartPointerInt::counter ={}; 

int main() {
  smartPointerInt a, b, c, d, e, f, t; 


  a = new int();
  b = a;
  c = a;
  d = a;

  d = a;
  d = a;
  e = a;
  return 0;
}