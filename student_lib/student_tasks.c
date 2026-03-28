#include "student_tasks.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// ============== ПРОСТЫЕ ЗАДАНИЯ (15 заданий, 0.5-1.5 балла) ==============

// Задание 1: Сумма элементов массива (0.5 балла)
int arraySum(const int *arr, int size) {
  int res = 0;
  for (int i = 0; i < size; i++) {
    res = arr[i] + res;
  }
  // TODO: Вычислить сумму всех элементов массива
  return res;
}

// Задание 2: Максимальный элемент массива (0.5 балла)
int arrayMax(const int *arr, int size) {
  int res = -100;
  for (int i = 0; i < size; i++) {
    if (arr[i] > res) {
      res = arr[i];
    }
  }
  // TODO: Найти максимальный элемент массива
  return res;
}

// Задание 3: Минимальный элемент массива (0.5 балла)
int arrayMin(const int *arr, int size) {

  int res = 100;
  for (int i = 0; i < size; i++) {
    if (arr[i] < res) {
      res = arr[i];
    }
  }
  return res;
  // TODO: Найти минимальный элемент массива
  return 0;
}

// Задание 4: Разворот массива на месте (0.5 балла)
void arrayReverse(int *arr, int size) {
  for (int i = 0; i < size / 2; i++) {
    int temp = 0;
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
  // TODO: Развернуть массив (первый элемент меняется с последним и т.д.)
}

// Задание 5: Подсчитать чётные числа (0.5 балла)
int countEven(const int *arr, int size) {
  int res = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      res = res + 1;
    }
  }
  // TODO: Подсчитать количество чётных чисел в массиве
  return res;
}

// Задание 6: Поиск элемента в массиве (0.5 балла)
int arrayFind(const int *arr, int size, int value) {
  for (int i = 0; i < size; i++){
    if (arr[i] == value){
      return i;
    } 
  }
  // TODO: Вернуть индекс первого вхождения value или -1
  return -1;
}

// Задание 7: Копирование массива (0.5 балла)
void arrayCopy(int *dest, const int *src, int size) {
  // TODO: Скопировать size элементов из src в dest
  int res = 0;
  for (int i = 0; i < size; i++) {
    dest[i] = src[i];
  }
}

// Задание 8: Сортировка пузырьком (0.5 балла)
void bubbleSort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = 0;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  // TODO: Отсортировать массив по возрастанию методом пузырька
}

// Задание 9: Циклический сдвиг влево на k позиций (0.5 балла)
void rotateLeft(int *arr, int size, int k) {
  // TODO: Сдвинуть элементы массива влево на k позиций
  // Пример: [1,2,3,4,5], k=2 -> [3,4,5,1,2]
  int temp[10];
  for (int j = 0; j < size; j++) {
    temp[j] = arr[(j + k) % size];
  }
  for (int i = 0; i < size; i++) {
    arr[i] = temp[i];
  }
}

// Задание 10: Слияние двух отсортированных массивов (0.5 балла)
void mergeSorted(const int *a, int sizeA, const int *b, int sizeB,
                 int *result) {
  // TODO: Объединить два отсортированных массива в один отсортированный
  int size = sizeA + sizeB;
  int k = 0;
  for (int i = 0; i < sizeA; i++) {
    result[k] = a[i];
    k++;
  }
  for (int j = 0; j < sizeB; j++) {
    result[k] = b[j];
    k++;
  }
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (result[j] > result[j + 1]) {
        int temp = 0;
        temp = result[j];
        result[j] = result[j + 1];
        result[j + 1] = temp;
      }
    }
  }
}

// Задание 11: Удалить дубликаты из отсортированного массива (0.5 балла)
int removeDuplicates(int *arr, int size) {
  // TODO: Удалить дубликаты из отсортированного массива на месте
  // Вернуть новый размер массива
  int res = 1;
  if (size == 0) {
    return 0;
  }
  for (int i = 1; i < size; i++) {
    if (arr[i] != arr[res - 1]) {
      arr[res] = arr[i];
      res++;
    }
  }
  return res;
}



// Задание 12: Второй по величине элемент (1 балл)
int secondLargest(const int *arr, int size) {
  // TODO: Найти второй по величине элемент
  // Если все элементы одинаковые, вернуть этот элемент
  int temp = 0;
  int max = 0;
  bool flag = 1;

  for (int i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int z = 0; z < size; z++){
    if (arr[z] != max){
      flag = 0;
      break;
    }
  }
  if (flag == 1){
    return max;
  }
  for (int j = 0; j < size; j++) {
    if ((arr[j] > temp) && (arr[j] < max) && (temp < max)) {
      temp = arr[j];
    }
  }

  return temp;
}

// Задание 13: Проверить, отсортирован ли массив по неубыванию = по возрастанию (1 балл)
bool isSorted(const int *arr, int size) {
  // TODO: Вернуть true, если массив отсортирован по неубыванию = по возрастанию
  bool flag = 1;

  if (size <= 1){
    return flag;
  }
  for (int i = 0; i < size; i++){
    if (arr[i] > arr[i + 1]){
      flag = 0;
      break;
    }
  }
  return flag;
}

// Задание 14: Частота самого частого элемента (1 балл)
int maxFrequency(const int *arr, int size) {
  // TODO: Найти, сколько раз встречается самый частый элемент
  if (size == 1) {
    return size;
  }
  int k = 0;
  int z = 0;
  int j = 0;
  while (j < size) {
    int temp = arr[j];
    k = 0;
    for (int i = 0; i < size; i++) {
      if (arr[i] == temp) {
        k++;
      }
    }
    j++;
    if (k > z) {
      z = k;
    }
  }
  return z;
}

// Задание 15: Найти два элемента с заданной суммой (1.5 балла)
int *twoSum(const int *arr, int size, int target) {
  // TODO: Найти два индекса i, j (i < j) таких, что arr[i] + arr[j] == target
  // Вернуть массив из двух элементов, выделенный через malloc
  // Если пара не найдена, вернуть NULL

  int *res = (int*)malloc(2*sizeof(int));

  for(int i = 0; i < size; i++){
    for(int j = 1; j < size; j++){
      if(arr[i] + arr[j] == target){
        res[0] = i;
        res[1] = j;
        return res;
      }
    }
  }
  free(res);
  return NULL;
}

// ============== СЛОЖНЫЕ ЗАДАНИЯ (5 заданий, 3-5 баллов) ==============

// Задание 16: Фильтрация положительных элементов (3 балла)
int *filterPositive(const int *arr, int size, int *resultSize) {
  // TODO: Создать новый массив (malloc) только с положительными элементами
  // Записать размер в *resultSize
  // Если положительных нет, вернуть NULL и *resultSize = 0
  int count = 0;
  for(int i = 0; i < size; i++){
    if (arr[i] > 0){
      count++;
    }
  }
  
  if(count == 0){
    *resultSize = 0;
    return NULL;
  }

  int *res = (int*)malloc(count * sizeof(int));

  int j = 0;
  for(int i = 0; i < size; i++){
    if (arr[i] > 0){
      res[j] = arr[i];
      j++;
    }
  }

  *resultSize = count;
  return res;
}

// Задание 17: Транспонирование матрицы (3 балла)
int *matrixTranspose(const int *matrix, int rows, int cols) {
  // TODO: Создать новую матрицу (malloc) — транспонированную
  // Матрица хранится построчно (row-major)
  // result[j * rows + i] = matrix[i * cols + j]
  int size = rows + cols;
  int *res = (int*)malloc(size * sizeof(int));
  for(int i =0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      res[j * rows + i] = matrix[i * cols + j];
    }
  }
  return res;
}

// Задание 18: Обход матрицы по спирали (4 балла)
int *spiralOrder(const int *matrix, int rows, int cols, int *resultSize) {
  // TODO: Вернуть элементы матрицы в порядке спирального обхода
  // Выделить результат через malloc, записать размер в *resultSize
  *resultSize = 0;
  return NULL;
}

// Задание 19: Разбиение строки по разделителю (5 баллов)
char **stringSplit(const char *str, char delimiter, int *count) {
  // TODO: Разбить строку по разделителю
  // Выделить массив строк и каждую строку через malloc
  // Записать количество частей в *count
  if (str == NULL){
    *count = 0;
    return NULL;
  }

  int c_word = 1;
  for(int i = 0; str[i] != '\0'; i++){
    if (str[i] == delimiter){
      c_word++;
    }
  }

  char **res = (char**)malloc(c_word * sizeof(char*));

  int resIndex = 0;
  int start = 0;



  *count = 0;
  return NULL;
}

// Задание 20: Умножение полиномов (5 баллов)

int *polynomialMultiply(const int *a, int sizeA, const int *b, int sizeB,
                        int *resultSize) {
  int resSize = sizeA + sizeB - 1;

  int *result = (int *)malloc(resSize * sizeof(int));
  if (result == NULL) {
    *resultSize = 0;
    return NULL;
  }

  for (int i = 0; i < resSize; i++) {
    result[i] = 0;
  }

  for (int i = 0; i < sizeA; i++) {
    for (int j = 0; j < sizeB; j++) {
      result[i + j] += a[i] * b[j];
    }
  }

  *resultSize = resSize;
  return result;
}