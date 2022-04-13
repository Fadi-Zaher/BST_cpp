#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int * shuffleArray(int * array, int size);

int main()
{

  //given array
  int array[] = {1, 2, 3, 4};
  int array_size = *(&array + 1) - array;
  cout << "size of the array : " << array_size << endl;

  int * result = shuffleArray(array, array_size);
  for (int i = 0; i < array_size; i++)
    cout << result[i] << " ";

  return 0;
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int * shuffleArray(int * array, int size)
{
  if (sizeof(array) == 2)
  {
    int temp;
    temp = array[0];
    array[0] = array[1];
    array[1] = temp;
  }
  for (int i = 0; i < size ; i++)
  {
    int j = rand() % (i + 1);
    swap(&array[i], &array[j]);
    if (array[i] == array[j])
    {
      j = rand() % (i + 1);
      swap(&array[i], &array[j]);
    }
  }
  return array;
}
