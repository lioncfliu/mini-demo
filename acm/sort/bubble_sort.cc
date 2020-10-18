#include <functional>
#include <iostream>
#include <vector>

using sort_function = std::function<void(int * /* array */, int /* left */, int /* right */)>;

// Time cost: O(n^2)
// Space cost: O(n)
void bubble_sort(int *array, int left, int right) {
  // N个元素排序共需要进行N-1轮冒泡调整，每轮调整后将一个元素的位置排好，下一轮冒泡的次数逐次减少1次。
  for (int i = left + 1; i < right; ++i) {
    for (int j = left; j < right - i; ++j) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
      }
    }
  }
}

void display_array(int *array, int left, int right) {
  std::cout << "[";
  for (int i = left; i < right; ++i) std::cout<< *(array + i) << ", ";
  std::cout << "]" << std::endl;
}

static sort_function sort_int_array = bubble_sort;

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
