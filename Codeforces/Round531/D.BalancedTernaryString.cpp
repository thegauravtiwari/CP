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
#define repi(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>b;i--)
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

class DBalancedTernaryString {
public:
	void solve(std::istream& cin, std::ostream& cout) {
		int n;
		cin>>n;
		string str;
		cin>>str;
		vector<int> zeroI,oneI,twoI;
		int count0=0,count1=0,count2=0,beg2=0,beg1=0;
		for(int i=0;i<str.length();i++)
        {
		    if(str[i]=='0')
            {
		        zeroI.pb(i);
		        count0++;
            }
		    else if(str[i]=='1')
            {
                oneI.pb(i);
                count1++;
            }
		    else{
		        twoI.pb(i);
		        count2++;
		    }
        }
		if(count2<n/3)
        {
		    int diff=n/3-count2;
		    while(diff>0)
            {
		        if(count1>n/3)
                {
		            int ind=oneI[count1-1];
		            oneI.pop_back();
		            str[ind]='2';
		            count1--;
                }
		        else if(count0>n/3)
                {
                    int ind=zeroI[count0-1];
                    zeroI.pop_back();
                    str[ind]='2';
                    count0--;
                }
		        diff--;
                count2++;
            }
        }

        if(count0<n/3)
        {
            int diff=n/3-count0;
            while(diff>0)
            {
                if(count1>n/3)
                {
                    int ind=oneI[beg1];
                    beg1++;
                    str[ind]='0';
                    count1--;
                }else if(count2>n/3)
                {
                    int ind=twoI[beg2];
                    beg2++;
                    str[ind]='0';
                    count2--;
                }
                diff--;
                count0++;
            }
        }


		if(count1<n/3)
        {
            int diff=n/3-count1;
            while(diff>0)
            {
                if(count0>n/3)
                {
                    int ind=zeroI[count0-1];
                    zeroI.pop_back();
                    str[ind]='1';
                    count0--;
                }else if(count2>n/3)
                {
                    int ind=twoI[beg2];
                    beg2++;
                    str[ind]='1';
                    count2--;
                }
                diff--;
                count1++;
            }

        }

		cout<<str;
	}
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	DBalancedTernaryString solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
