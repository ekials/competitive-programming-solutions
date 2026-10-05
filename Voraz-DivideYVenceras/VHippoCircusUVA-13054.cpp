#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int c;
    if (cin >> c)
    {
        for (int case_num = 1; case_num <= c; ++case_num)
        {
            int n;
            long long h, ta, td;
            cin >> n >> h >> ta >> td;

            vector<long long> height(n);
            for (int i = 0; i < n; ++i)
            {
                cin >> height[i];
            }

            if (td >= 2 * ta)
            {
                cout << "Case " << case_num << ": " << n * ta << "\n";
                continue;
            }

            sort(height.begin(), height.end());

            int left = 0;
            int right = n - 1;
            long long total_time = 0;

            while (left <= right)
            {
                if (left == right)
                {
                    total_time += ta;
                    break;
                }

                if (height[left] + height[right] < h)
                {
                    total_time += td;
                    left++;
                    right--;
                }
                else
                {
                    total_time += ta;
                    right--;
                }
            }

            cout << "Case " << case_num << ": " << total_time << "\n";
        }
    }

    return 0;
}