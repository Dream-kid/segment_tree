//http://www.spoj.com/problems/GSS1/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class node
{
private:
    ll max_sum,sum,prefix,suffeix;
public:
    void init(ll value)
    {
        max_sum=value;
        sum =value;
        prefix=value;
        suffeix=value;
    }
    void reset()
    {
        max_sum=-10000000000;
        prefix=-10000000000;
        sum=-10000000000;
        suffeix=-10000000000;
    }
    void merge_child(node a,node b)
    {
        sum=a.sum+b.sum;
        prefix=max(a.prefix,a.sum+b.prefix);
        suffeix=max(b.suffeix,b.sum+a.suffeix);
        max_sum=max(max(a.max_sum,b.max_sum),a.suffeix+b.prefix);
    }
    ll get_max()
    {
        return max_sum;
    }
};
node tree[3000000];
void built(ll node1,ll p,ll q)
{
    if(p==q)
    {
        ll x;
        scanf("%lld",&x);
        tree[node1].init(x);
        return;
    }
    built(node1*2,p,(p+q)/2);
    built(node1*2+1,(p+q)/2+1,q);
    tree[node1].merge_child(tree[node1*2],tree[node1*2+1]);
}
node query(ll node1,ll l,ll r,ll p,ll q)
{
    if(r<p||l>q||p>q)
    {
        node obj;
        obj.reset();
        return obj;
    }
    if(l>=p&&r<=q)
        return tree[node1];
    node a,b,c;
    a=query(node1*2,l,(l+r)/2,p,q);
    b=query(node1*2+1,(l+r)/2+1,r,p,q);
    c.merge_child(a,b);
    return c;
}
int main()
{
    ll a,b;
    scanf("%lld",&a);
    built(1,1,a);
    scanf("%lld",&b);
    while(b--)
    {
        ll s,t;
        scanf("%lld%lld",&s,&t);
        node obj=query(1,1,a,s,t);
        printf("%lld\n",obj.get_max());
    }
}
