#include <vector>
#include <algorithm>
#include <iostream>

void findCombinations(std::vector<int>& arr, int index, int num, int reducedNum, std::vector<std::vector<int>>& res, std::vector<int>& r)
{
    if (reducedNum < 0)
        return;
    if (reducedNum == 0)
    {
        res.push_back(r);
        return;
    }
    while (index < num && reducedNum - arr[index] >= 0)
    {
        r.push_back(arr[index]);
        findCombinations(arr, index, num, reducedNum - arr[index], res, r);
        index++;
        r.pop_back();
    }
}

int main()
{
    int total = 6;
    std::vector<int> amounts = {3, 2, 4, 3, 1};
    std::sort(amounts.begin(), amounts.end());
    std::vector<std::vector<int>> res;
    std::vector<int> r;
    findCombinations(amounts, 0, amounts.size(), total, res, r);
    for (auto& v : res)
    {
        for (int& i : v)
            std::cout << i << " ";
        std::cout << "\n";
    }
    return 0;
}