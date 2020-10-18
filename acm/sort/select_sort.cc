#include <functional>
#include <iostream>
#include <vector>

using sort_function = std::function<void(int * /* array */, int /* left */, int /* right */)>;

// Time cost: O(n^2)
// Space cost: O(n)
void select_sort(int *array, int left, int right) {
  // 每次从未排序的中序列中找到最小的元素，追加到已排序序列的末尾。
  for (int i = left; i < right; ++i) {
    int min_index = i;
    for (int j = i; j < right - 1; ++j) {
      if (array[j] > array[j + 1]) {
         min_index = j + 1;
      }
    }
    if (min_index != i) {
      std::swap(array[min_index], array[i]);
    }
  }
}

void display_array(int *array, int left, int right) {
  std::cout << "[";
  for (int i = left; i < right; ++i) std::cout<< *(array + i) << ", ";
  std::cout << "]" << std::endl;
}

static sort_function sort_int_array = select_sort;

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
