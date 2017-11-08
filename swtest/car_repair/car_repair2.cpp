#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int CN, PN, K, A, B;
int a[11], b[11], tk[1111];

void input()
{
    scanf("%d %d %d %d %d", &CN, &PN, &K, &A, &B);
    for (int i = 1; i <= CN; i++) scanf("%d", &a[i]);
    for (int j = 1; j <= PN; j++) scanf("%d", &b[j]);
    for (int k = 1; k <= K; k++) scanf("%d", &tk[k]);

}

int solve()
{
    queue<int> cq, pq;
    vector<int> ct(11, 0), cn(11, 0), pt(11,0), pn(11,0);
    vector<int> solc(K + 10), solp(K + 10);

    int t = 0, tt = 0;

    while (tt != K)
    {
        for (int c = 1; c <= K; c++)
            if (tk[c] == t) cq.push(c);

        for (int i = 1; i <= CN; i++)
        {
            if (ct[i] == 0)
            {
                if (cn[i] != 0)
                {
                    pq.push(cn[i]);
                    cn[i] = 0; // cn[i] == 0 이면 이용중인 사용자가 없음을 의미
                }

                if (!cq.empty())
                {
                    int c = cq.front(); cq.pop();
                    cn[i] = c;
                    ct[i] = a[i];
                    solc[c] = i;
                }
            }
        } // cn for

        for (int i = 1; i <= PN; i++)
        {
            if (pt[i] == 0)
            {
                if (pn[i] != 0)
                {
                    ++tt;
                    pn[i] = 0;
                }

                if (!pq.empty())
                {
                    int c = pq.front(); pq.pop();
                    pn[i] = c;
                    pt[i] = b[i];
                    solp[c] = i;
                }
            }
        } // pn for

        for (int i = 1; i <= CN; i++)
        {
            if (cn[i] != 0) ct[i]--;
        }

        for (int i = 1; i <= PN; i++)
        {
            if (pn[i] != 0) pt[i]--;
        }

        ++t;
    }// while

    int ret = 0;
    for (int c = 1; c <= K; c++)
    {
        if (solc[c] == A && solp[c] == B) ret += c;
    }

    if (ret == 0) ret = -1;

    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        input();
        printf("#%d %d\n", tc, solve());
    }

    return 0;
}
