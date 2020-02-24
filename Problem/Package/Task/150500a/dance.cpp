#include <bits/stdc++.h>

using namespace std;

#define REP(i, a) for(int i = 0; i < (a); i++)
#define FORU(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)

const int MN = 2e6 + 1e5 + 1e4;

int my_round(double x) {
    if (x < 0) return -my_round(-x);
    return (int) (x + 1e-3);
}

const double PI = acos((double) -1.0);

typedef complex<double> cplex;
int rev[MN];
cplex wlen_pw[MN], fa[MN], fb[MN];

void fft(cplex a[], int n, bool invert) {
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap (a[i], a[rev[i]]);

    for (int len = 2; len <= n; len <<= 1) {
        double alpha = 2 * PI / len * (invert ? -1 : +1);
        int len2 = len >> 1;

        wlen_pw[0] = cplex(1, 0);
        cplex wlen(cos(alpha), sin(alpha));
        for (int i = 1; i < len2; ++i) wlen_pw[i] = wlen_pw[i-1] * wlen;

        for (int i = 0; i < n; i += len) {
            cplex t, *pu = a+i, *pv = a + i + len2,
                    *pu_end = a + i + len2, *pw = wlen_pw;
            for (; pu != pu_end; ++pu, ++pv, ++pw) {
                t = *pv * *pw;
                *pv = *pu - t;
                *pu += t;
            }
        }
    }

    if (invert) REP(i, n) a[i] /= n;
}

void calcRev(int n, int logn) {
    REP(i, n) {
        rev[i] = 0;
        REP(j, logn) if (i & (1 << j)) rev[i] |= 1 << (logn - 1 - j);
    }
}

void mulpoly(int a[], int b[], int c[], int na, int nb, int &n) {
    int l = max(na, nb), logn = 0;
    for (n = 1; n < l; n <<= 1) ++logn;
    n <<= 1; ++logn;
    calcRev(n, logn);

    REP(i,n) fa[i] = fb[i] = cplex(0);
    REP(i,na) fa[i] = cplex(a[i]);
    REP(i,nb) fb[i] = cplex(b[i]);

    fft(fa, n, false);
    fft(fb, n, false);

    REP(i,n) fa[i] *= fb[i];
    fft(fa, n, true);

    REP(i,n) c[i] = (int)(fa[i].real() + 0.5);
}

const int M = 13;
const int N = 7e4 + 4;

int a[N];
int b[N];
int r[N*4];
int t[M][N];
int p[M][N];

// long long res[N];
int res[N];

main(){
	#define TASK "dance"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
	int n, l, m;
	// long long W;
	scanf("%d%d%d", &n, &l, &m);
	// scanf("%lld", &W);
    int W;
    scanf("%d", &W);
	FORU(i, 1, m)
		FORU(j, 1, n) scanf("%d", &t[i][j]);
	FORU(i, 1, m)
		FORU(j, 1, l) scanf("%d", &p[i][j]);
	FORU(i, 1, m){
		REP(j, n) a[j] = t[i][j+1];
		REP(j, l) b[j] = p[i][l-j];
		int x;
		mulpoly(a, b, r, n, l, x);
		FORU(j, 1, n-l+1) res[j] += r[(l-1)+(j-1)];
	}
	int cnt = 0;
	FORU(j, 1, n-l+1){
        cnt += (res[j] > W);
    }
	printf("%d", cnt);
}