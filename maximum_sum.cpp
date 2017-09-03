//http://www.spoj.com/problems/KGSS/
#include<bits/stdc++.h>
typedef long long  ll;
using namespace std;
struct node
{
    ll maxi,position;
} tree[400000],zero;
void update(ll node1,ll l,ll r,ll p,ll q)
{
    if(r<p||l>p||l>r) return;
    if(l==r)
    {
        tree[node1].maxi=q;
        tree[node1].position=p;
        return;
    }
    update(node1*2,l,(l+r)/2,p,q);
    update(node1*2+1,(l+r)/2+1,r,p,q);
    if(tree[2*node1].maxi>tree[2*node1+1].maxi)
    {
        tree[node1].maxi=tree[2*node1].maxi;
        tree[node1].position=tree[2*node1].position;
    }
    else
    {
        tree[node1].maxi=tree[2*node1+1].maxi;
        tree[node1].position=tree[2*node1+1].position;
    }
}
node query(ll node1,ll l,ll r,ll p,ll q)
{
    if(r<p||l>q||l>r) return zero;
    if(l>=p&&r<=q)
        return tree[node1];
    node s,t;
    s= query(node1*2,l,(l+r)/2,p,q);
    t=query(node1*2+1,(l+r)/2+1,r,p,q);
    if(s.maxi>t.maxi) return s;
    else return t;
}
int main()
{
    ll a;
    scanf("%lld",&a);
    for(ll i=1; i<=a; i++)
    {
        ll p,q;
        scanf("%lld",&p);
        update(1,1,a,i,p);
    }
    ll p1;
    scanf("%lld",&p1);
    while(p1--)
    {
        ll t,y;
        char s;
        cin>>s;
        if(s=='Q')
        {
            scanf("%lld%lld",&t,&y);
            node rest= query(1,1,a,t,y);
            ll m1=rest.maxi;
            ll pos=rest.position;
            update(1,1,a,pos,0);
            rest= query(1,1,a,t,y);
            ll m2=rest.maxi;
            printf("%lld\n",m1+m2);
            update(1,1,a,pos,m1);
        }
        else
        {
            ll p,q;
            scanf("%lld%lld",&p,&q);
            update(1,1,a,p,q);
        }
    }
}
