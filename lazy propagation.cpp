//http://www.lightoj.com/volume_showproblem.php?problem=1164
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <limits>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <bitset>
#include <numeric>
#include <cassert>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

#define sc scanf
#define pf printf
#define pi 2*acos(0.0)
#define ull unsigned long long
#define all(v) v.begin(),v.end()

#define sii(t) scanf("%d",&t)
#define sll(t) scanf("%lld",&t)
#define ssii(a,b) scanf("%d%d",&a,&b)
#define ssll(a,b) scanf("%lld%lld",&a,&b)
#define Case(no) printf("Case %lld:",++no)
#define nl puts("")
#define p(a) printf("%d\n",a)
#define pll(a) printf("%lld\n",a)
#define P(a) printf("%d ",a)
#define PLL(a) printf("%lld ",a)


#define ff first
#define se second
#define pb push_back
#define ST(v) sort(all(v))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define cover(a,d) memset(a,d,sizeof(a))
#define popcount(i) __builtin_popcount(i)                       //count one
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define un(v) ST(v), (v).earse(unique(all(v)),v.end())
#define common(a,b) ST(a), ST(b), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b) ST(a), ST(b), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
#define flop(m,n,q)             for(ll i=m;i<n;i+=q)
////============ CONSTANT ===============////
#define mx  (100010)
#define inf 1000000000000000000
#define eps 1e-9
#define mod 10007
////=====================================////
typedef long long ll;
struct node1
{
    ll sum,prop;
} tree[100000*3];
void update(ll node,ll l,ll r,ll p,ll q,ll value)
{
    if(l>q||r<p) return;
    if(l>=p&&r<=q)
    {
        tree[node].sum+=value*(r-l+1);
        tree[node].prop+=value;
        return;
    }
    update(node*2,l,(l+r)/2,p,q,value);
    update(node*2+1,(l+r)/2+1,r,p,q,value);
    tree[node].sum=tree[node*2].sum+tree[2*node+1].sum+(r-l+1)*tree[node].prop;
}
ll query(ll node,ll l,ll r,ll p,ll q,ll carry)
{
    if(l>q||r<p) return 0;
    if(l>=p&&r<=q)
        return tree[node].sum+carry*(r-l+1);
    return(query(node*2,l,(l+r)/2,p,q,carry+tree[node].prop)+query(node*2+1,(l+r)/2+1,r,p,q,carry+tree[node].prop));
}
int main()
{
    ll a,b,c,t=0;
    sll(c);
    while(c--)
    {
        bool mark=true;
        ssll(a,b);
        while(b--)
        {
            ll p;
            sll(p);
            if(mark)
            {
                Case(t);
                pf("\n");
            }
            if(p==0)
            {
                ll o,s,n;
                ssll(o,s);
                sll(n);
                update(1,1,a,o+1,s+1,n);
            }
            else
            {
                ll o,s;
                sll(o);
                sll(s);
                pll(query(1,1,a,o+1,s+1,0));
            }
            mark=false;
        }
        cover(tree,0);
    }
}
