/// <summary>
/// CodeSignal bullshittery. Given an array, find the indicies of the largest subarray
///     that contains contiguous numbers, whose absolute distance is not greather than the difference
///     parameter.
/// </summary>
/// <param name="a">: The container. Here, a vector.</param>
/// <param name="diff">: The difference.</param>
/// <returns> A vector containing the indicies of the largest subarray.</returns>
vector<int> diffSubArray(vector<int> a, int diff)
{
    std::map<int, std::pair<int, int>, std::greater<int>> myMap;
    vector<int> toReturn;
    for (int i = 0; i < a.size(); i++)
    {
        int offset = 0;
        int count = 0;
        int j = i + 1;
        while (i + 1 + offset < a.size()
            && abs(a[i + offset] - a[j + offset]) <= diff)
        {
            count++;
            offset++;
        }
        if (myMap.count(count) > 0)
            continue;
        myMap[count] = std::make_pair(i, j + offset -1);
    }
    toReturn.push_back(myMap.begin()->second.first);
    toReturn.push_back(myMap.begin()->second.second);
    return toReturn;
}
//same as above but for posterity's sake.
vector<int> longestDiffSubarray(vector<int> numbers, int diff) {
    //key = longest subarray, value = start,end
    std::map<int, std::pair<int, int>, std::greater<int>> result;
    vector<int> toReturn;
    int largestCount = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int j = i + 1;
        int count = 0;
        int offset = 0;
        cout << "cycle " << i << " at " << numbers[i] << endl;
        while ((j + offset < numbers.size())
            && abs(numbers[i + offset] - numbers[j + offset]) <= diff)
        {
            cout << numbers[i + offset] << " " << numbers[j + offset] << endl;
            count++;
            offset++;
        }
        cout << count << " " << i << " " << j + offset - 1 << endl;
        int temp1 = i, temp2 = j + offset - 1;
        if (result.count(count) > 0)
            continue;
        result[count] = std::make_pair(temp1, temp2);
        cout << result[count].first << " " << result[count].second << endl;
        if (count > largestCount)
            largestCount = count;


    }
    toReturn.push_back(result[largestCount].first);
    toReturn.push_back(result[largestCount].second);
    return toReturn;
}