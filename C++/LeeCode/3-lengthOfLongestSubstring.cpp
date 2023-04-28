/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len,i,left,right,max=0;
        len = s.length();

        left = 0;
        //循环遍历整个字符串字符
        //left指向子串头
        //right指向子串尾
        for(i=0; i<len; i++){
            for(right=left; right<i; right++){
                if(s[right] == s[i]){
                    left = right + 1;
                    break;
                }
            }

            if(right-left+1 > max){
                max = right-left+1;
            }
        }
        return max;
    }
};

int main(int argc, char* argv[]){

    string s = "bbbbbbbb";
    Solution solution;

    cout << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}