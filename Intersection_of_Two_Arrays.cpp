class Solution {
public:
    map<int, int> frequenciesOfNum;
    int count = 0; //size of resultant array
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i< nums1.size(); i++)
        {
            frequenciesOfNum[nums1[i]]++;
        }
        int j=0;
        for(int i=0; i< nums2.size(); i++)
        {
            if((frequenciesOfNum.find(nums2[i]) != frequenciesOfNum.end())&&(frequenciesOfNum.at(nums2[i])>0))
            {
                
                nums1.at(j++)=nums2[i];
                frequenciesOfNum.at(nums2[i])--;
                count++;
            }
        }
            nums1.resize(count);
            return nums1;
    }
};