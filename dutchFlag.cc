#include <vector>
#include <iostream>

// Sort elements around a pivot such that 
// -------------------------------
//        < pivot
// -------------------------------
//        == pivot
// -------------------------------
//        > pivot
// -------------------------------

using namespace std;

void swap(vector<int> &vec, int i, int j)
{
  int tmp = vec[i];
  vec[i] = vec[j];
  vec[j] = tmp;
}

void print(const vector<int> &vec)
{
  for (auto const v : vec)
    std::cout << v << " ";
  std::cout << std::endl;
}

void DutchFlagPartition(vector<int> &vec, int pivotIndex)
{
  int length = vec.size();
  int pivot  = vec[pivotIndex];

  int tmp = vec[pivotIndex];
  vec[pivotIndex] = vec.back();
  vec[length-1] = tmp;


  int i, j;
  for (i = 0, j = length-2; i <= j;)
  {
    if (vec[i] >= pivot)
    {
      swap(vec, i, j);
      --j;
    }
    else
      ++i;
  }
  swap(vec, i, length-1);

  int k, l;
  for (k=length-1, l =i+1; l < k;)
  {
    if (vec[k] == pivot)
    {
      swap(vec, k, l);
      ++l; 
    }
    else
    {
      --k;
    }
  }
}

void DutchFlagPartition2(vector<int> &vec, int pivotIndex)
{
  int length = vec.size();
  int pivot  = vec[pivotIndex];

  int smaller = 0, larger = length, equal=0;

  while (equal < larger)
  {
    if (vec[equal] < pivot) 
    {
      swap(vec, smaller, equal);
      ++smaller; ++equal;
    }
    if (vec[equal] > pivot)
    {
      --larger;
      swap(vec, equal, larger);
    }
    if (vec[equal] == pivot)
      equal++;
  }
}

int main()
{
  vector<int> v1 = {19, 13, 8, 14, 6, 18, 7, 12, 17, 4, 2, 10, 3, 2, 16, 20, 1, 5, 15, 11, 2, 9};
  vector<int> v2 = {2,2,2,2};
  vector<int> v3 = {19, 13, 8, 14, 6, 18, 7, 12, 17, 4, 10, 3, 16, 20, 1, 5, 15, 11, 2, 9, 3, 3, 4};
  vector<int> v4 = {11, 7, 3, 12, 14, 9, 5, 10, 13, 6};

  DutchFlagPartition2(v1, 10); DutchFlagPartition2(v2,0); DutchFlagPartition2(v3,7);
  DutchFlagPartition2(v4,5);
  print(v1);print(v2); print(v3); print(v4);

  return 0;
}
