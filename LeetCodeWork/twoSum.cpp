//My version
vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i ++)
    {
        int find = target - nums[i];
        vector<int>::iterator second = std::find(nums.begin(), nums.end(), target - nums[i]);
        if (second != nums.end())
        {
            int index = std::distance(nums.begin(), second);
            if (index != i)
            {
                result.push_back(i);
                result.push_back(std::distance(nums.begin(), second));
                break;
            }

        }
    }

    return result;
}

//optimal version
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> imap;
    
    for (int i = 0;; ++i) {
        auto it = imap.find(target - nums[i]);
        
        if (it != imap.end()) 
            return vector<int> {i, it->second};
            
        imap[nums[i]] = i;
    }
}