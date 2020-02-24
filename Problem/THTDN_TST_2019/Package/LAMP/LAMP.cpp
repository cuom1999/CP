#include <bits/stdc++.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{	//freopen("input.txt", "r", stdin);
    int n, q;
    scanf("%d %d", &n, &q);

    map<int, int> work;
    work[-1] = -1;
    work[1] = n;
    work[n + 2] = n + 2;
    int count = n;

    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        scanf("%d %d %d", &k, &l, &r);

        auto fiter = --work.lower_bound(l);
        auto siter = fiter;

        while (siter != work.end())
        {
            if (siter->first > r)
                break;

            if(siter->second >= l)
                count -= min(siter->second, r) - max(siter->first, l) + 1;

            if (siter->first >= l && siter->second <= r)
                siter = work.erase(siter);
            else
                ++siter;
        }

        auto riter = fiter;
        ++riter;

        if (k == 0)
        {
            if (fiter->second > r)
            {
                work[r + 1] = fiter->second;
                fiter->second = l - 1;
            }

            if (fiter->second >= l)
                fiter->second = l - 1;

            if (riter->first <= r)
            {
                auto rr = riter->second;
                work.erase(riter);
                work[r + 1] = rr;
            }
        }
        else
        {
            if (fiter->second < l && riter->first > r)
                work[l] = r;

            if (fiter->second >= l && fiter->second < r)
            {
                if (riter->first <= r)
                {
                    fiter->second = riter->second;
                    work.erase(riter);
                }
                else
                {
                    fiter->second = r;
                }
            }
            else if (riter->first <= r)
            {
                auto rr = riter->second;
                work.erase(riter);
                work[l] = rr;
            }

            count += r - l + 1;
        }

        printf("%d\n", count);
    }

    return 0;
}