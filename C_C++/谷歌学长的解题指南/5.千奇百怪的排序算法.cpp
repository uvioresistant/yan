/* 5.1. 常用排序算法*/
/* 刷题时很少需要自己手写排序算法，但是熟习各种排序算法可以加深自己对算法的基本理解，
以及解出由这些排序算法引申出来的题目 */
// 5.1.1.快排
#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &nums, int l, int r)
{
    if (l + 1 >= r)
    {
        return;
    }
    int first = l, last = r - 1, key = nums[first]; //key为枢轴，设为第一项的值
    while (first < last)                            //first指针在last指针前
    {
        while (first < last && nums[last] >= key) //后一项大于
        {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key)
        {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

// 5.1.2. 归并排序(Merge Sort)
void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp)
{
    if (l + 1 >= r)
    {
        return;
    }
    // divide
    int m = l + (r - 1) / 2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);
    // conquer
    int p = l, q = m, i = l;
    while (p < m || q < r)
    {
        if (q >= r || (p < m && nums[p] <= nums[q]))
        {
            temp[i++] = nums[p++];
        }
        else
        {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i)
    {
        nums[i] = temp[i];
    }
}

// 5.1.3. 插入排序(Insertion Sort)
void insertion_sort(vector<int> &nums, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
        {
            swap(nums[j], nums[j - 1]);
        }
    }
}

// 5.1.4. 冒泡排序(Bubble Sort)
void bubble_sort(vector<int> &nums, int n){
    bool swapped;
    for(int i=1; i<n; ++i){
        swapped=false;
        for(int j=1; j<n-i+1; ++j){
            if(nums[j]<nums[j-1]){
                swap(nums[j], nums[j-1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

// 5.1.5. 选择排序(Selection Sort)
void selection_sort(vector<int> &nums, int n){
    int mid;
    for (int i=0; i<n-1; ++i){
        mid=i;
        for(int j=i+1; j<n; ++j){
            if(nums[j]<nums[mid]){
                mid=j;
            }
        }
        swap(nums[mid], nums[i]);
    }
}

void sort(){
    vector<int> nums={1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    vector<int> temp(nums.size());
    // sort(nums.begin(), nums.end());
    quick_sort(nums, 0, nums.size());
    merge_sort(nums, 0, nums.size(), temp);
    insertion_sort(nums, nums.size());
    bubble_sort(nums, nums.size());
    selection_sort(nums, nums.size());
}

// 5.2. 快速选择
// 在一个未排序的数组中，找到第k大的数字
题型：快速选择一般用于求解k-th Element问题，可在O(n)
