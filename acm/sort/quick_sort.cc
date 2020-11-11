#include <functional>
#include <iostream>
#include <vector>

using sort_function = std::function<void(int * /* array */, int /* left */, int /* right */)>;

int partition(int *array, int left, int right) {
  int middle = array[left];
  int l = left;
  int r = right;

  while (l < r) {
     while (l < r && array[r] >= middle) --r;
     array[l] = array[r];

     while (l < r && array[l] <= middle) ++l;
     array[r] = array[l];
  }
  array[l] = middle;
  return l;
}

// Time cost: O(n log2 n)
// Space cost: O(1) 
void quick_sort(int *array, int left, int right) {
  if (left >= right) return;
  
  int pivot = partition(array, left, right);
  quick_sort(array, left, pivot - 1); 
  quick_sort(array, pivot + 1, right); 
}

void display_array(int *array, int left, int right) {
  std::cout << "[";
  for (int i = left; i < right; ++i) std::cout<< *(array + i) << ", ";
  std::cout << "]" << std::endl;
}

static sort_function sort_int_array = quick_sort;

void run_all_testings() {
  std::vector<int> array_01{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> array_02{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> array_03{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> array_04{9, 8, 9, 7, 5, 6 , 3, 2, 1, 2};
  
  sort_int_array(array_01.data(), 0, array_01.size() - 1);
  sort_int_array(array_02.data(), 0, array_02.size() - 1);
  sort_int_array(array_03.data(), 0, array_03.size() - 1);
  sort_int_array(array_04.data(), 0, array_04.size() - 1);

  display_array(array_01.data(), 0, array_01.size());
  display_array(array_02.data(), 0, array_02.size());
  display_array(array_03.data(), 0, array_03.size());
  display_array(array_04.data(), 0, array_04.size());
}

int main(int argc, char *argv[]) {
   run_all_testings();
   return 0;
}
