/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Gaurav Tiwari
 */



#include <bits/stdc++.h>
#define mod 1000000007ll
#define mod2 100000009ll
#define mod3 998244353
#define pb push_back
#define fastIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define readi(x) scanf("%d",&x)
#define reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define PI 3.141592653589793238462643383
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
#define mp make_pair
#define ll long long
#define sorti(a,b) sort(a,b)
#define sortd(a,b,tp) sort(a,b,greater<tp>())
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;

class ASnowball {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		int w,h;
		cin>>w>>h;
		int u1,d1,u2,d2;
		cin>>u1>>d1>>u2>>d2;
		while(h>0)
        {
		    w+=h;
		    if(d1==h)
            {
		        w-=u1;
		        if(w<0)
		            w=0;
            }else if(d2==h)
            {
                w-=u2;
                if(w<0)
                    w=0;
            }
		    h--;
        }
		cout<<w;
	}
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ASnowball solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
