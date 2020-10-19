#include <functional>
#include <iostream>
#include <vector>

using sort_function = std::function<void(int * /* array */, int /* left */, int /* right */)>;

int get_middle_index(int *array, int left, int right) {
  int middle = array[left];
  int l = left, r = right - 1;
  while (l < r) {
    while (l < r && array[r] > middle) --r; 
    if (l < r) {
      array[l] = array[r];
      ++l;
    }
   
    while (l < r && array[l] < middle) ++l;
    if (l < r) {
      array[r] = array[l];
      --r;
    }
    std::cout<< "middle index, l, r:" << l << "," << r << std::endl;
  }
  array[l] = middle;
  return l;
}

// Time cost: O(n log2 n)
// Space cost: O(n log2 n)
void quick_sort(int *array, int left, int right) {
  if (left > right) return;
  
  int middle_index = get_middle_index(array, left, right);
  quick_sort(array, left, middle_index - 1); 
  quick_sort(array, middle_index + 1, right); 
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
  
  sort_int_array(array_01.data(), 0, array_01.size());
  sort_int_array(array_02.data(), 0, array_02.size());
  sort_int_array(array_03.data(), 0, array_03.size());

  display_array(array_01.data(), 0, array_01.size());
  display_array(array_02.data(), 0, array_02.size());
  display_array(array_03.data(), 0, array_03.size());
}

int main(int argc, char *argv[]) {
   run_all_testings();
   return 0;
}
