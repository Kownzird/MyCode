/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retV;
        int len = nums.size();
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                if(target == (nums[i] + nums[j])){
                    retV.push_back(i);
                    retV.push_back(j);
                }
            }
        }
        return retV;
    }
};

int main(int argc, char* argv[]){
    vector<int> v,vTarget;
    Solution solution;

    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    

    vTarget = solution.twoSum(v,8);
    
    for(vector<int>::iterator i=vTarget.begin(); i!=vTarget.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
}