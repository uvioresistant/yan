#include <stdio.h>
int main()
{
    printf("He");
    return 0;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0, r = numbers.size() - 1, sum;
    while (l < r)
    {
        sum = numbers[1] + numbers[r];
        if (sum == target)
            break;
        if (sum < target)
            ++l;
        else
            --r;
    }
    return vector<int>{l + 1, r + 1};
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0, r = numbers.size() - 1, sum;
    while (l < r)
    {
        sum = numbers[1] + numbers[r];
        if (sum == target)
            break;
        if (sum < target)
            ++l;
        else
            --r;
    }
    return vector<int>{l + 1, r + 1};
}

void merge(vector<int> &numbs1, int m, vector<int> &nums2, int n)
{
    int pos = m-- + n-- - 1;
    while (m >= 0 && n >= 0)
    {
        nums[pos--] = nums1[m] > num2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0)
    {
        nums1[pos--] = nums[n--];
    }
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    //判断是否存在环路
    do
    {
        if (!fast || !fast->next)
            return nullptr;
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);
    // 如果存在，查找环路节点
    fast = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

string minWindow(string S, string T)
{
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    //先统计T中的字符情况
    for (int i = 0; i < T.size(); ++i)
    {
        flag[T[i]] = true;
        ++chars[T[i]];
    }
    // 移动滑动窗口，不断更改统计数据
    int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
    for (int r = 0; r < S.size(); ++r)
    {
        if (flag[S[r]])
        {
            if (--chars[S[r]] >= 0)
            {
                ++cnt;
            }
            while (cnt == T.size())
            {
                if (r - l + 1 < min_size)
                {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[S[l]] && ++chars[S[l]] > 0)
                {
                    --cnt;
                }
                ++l;
            }
        }
    }
    return min_size > S.size() ? "" : S.substr(min_l, min_size);
}