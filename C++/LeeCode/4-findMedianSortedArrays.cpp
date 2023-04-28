/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyPrint{
public:
    void operator()(int val){
        cout << val << " ";
    }
    
};

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        
        vector<int> nums;
        double ret;

        for(vector<int>::iterator it1 = nums1.begin(); it1!=nums1.end(); it1++) {
            nums.push_back(*it1);
        }

        for(vector<int>::iterator it2 = nums2.begin(); it2!=nums2.end(); it2++) {
            nums.push_back(*it2);
        }

        sort(nums.begin(), nums.end());

        int len = nums.size();
        if(len%2){ //单数
            ret = nums[len/2]/1.0;
        }else{ //双数
            ret = (nums[len/2-1] + nums[len/2])/2.0;
        }
    
        return ret;
    }
};

int main(int argc, char** argv){
    vector<int> v1,v2;
    Solution solution;

    v1.push_back(1);
    v1.push_back(3);

    v2.push_back(2);

    cout << solution.findMedianSortedArrays(v1,v2) << endl;

    return 0;

}