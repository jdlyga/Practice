#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    // remember smalles number's so far! (stack)
    // cleanup the stack depending on current value

    // sort of increasing sequence (lowest sequence!)
    // remove everything larger than arr[i].

    std::vector<int> stack;
    int result = 0;

    for (int i = 0; i < N; i++)
    {
        int t;
        std::cin >> t;

        auto it = std::upper_bound(stack.begin(), stack.end(), t);

        // TODO wait not exactly!???!?
        // test against ALL values on stack as well..
        // TEST ONLY AGAINST NEIGHBOURING ENTRIES NO
        // test only against larger entries, one smaller allowed (already tested would not make any sense. from upper_bound + one before
        for (auto jt = it != stack.begin() ? it-1 : it; jt != stack.end(); jt++)
        {
            int &A = *jt;
            int &B = t;
            int r = A ^ B; // ((A & B) ^ (A | B)) & (A ^ B);
            if (r > result)
                result = r;
        }

        // remove everything larger equal arr[i]
        stack.erase(it, stack.end());
        if (stack.empty() || stack.back() != t)
            stack.push_back(t);
    }

    std::cout << result << std::endl;

    return 0;
}
