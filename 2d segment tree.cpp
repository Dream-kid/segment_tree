//http://lightoj.com/volume_showproblem.php?problem=1081

////=====================================////
///-----SOURAV CHAKRABORTY-----///
///-----KUET CSE 2K16-----///
////=====================================////
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define inf 1000000010000
#define mod1 1000000007
ll tree[502*4][502*4];
void merge(ll node,ll xaxis)
{
    tree[xaxis][node]=max(tree[xaxis][2*node],tree[xaxis][2*node+1]);
}
ll query1(ll node,ll l,ll r,ll p,ll q,ll xaxis)
{
    if(r<p||q<l)
        return 0;
    if(l>=p&&r<=q)
        return  tree[xaxis][node];
    return max(query1(2*node,l,(l+r)/2,p,q,xaxis),
               query1(2*node+1,(l+r)/2+1,r,p,q,xaxis));
}
void update1(ll node,ll l,ll r,ll p,ll q,ll xaxis,ll val)
{
    if(r<p||q<l)
        return;
    if(l>=p&&r<=q)
    {
        tree[xaxis][node]=val;
        return;
    }
    update1(2*node,l,(l+r)/2,p,q,xaxis,val);
    update1(2*node+1,(l+r)/2+1,r,p,q,xaxis,val);
    merge(node,xaxis);
}
ll total=1001;
void merge1(ll node,ll L,ll R)
{
    ll temp= max(query1(1,1,total,L,R,2*node),query1(1,1,total,L,R,2*node+1));
    update1(1,1,total,L,R,node,temp);
}
void update(ll node,ll l,ll r,ll p,ll q,ll L,ll R,ll val)
{
    if(r<p||q<l)
        return;
    if(l>=p&&r<=q)
    {
        update1(1,1,total,L,R,node,val);
        return;
    }
    update(2*node,l,(l+r)/2,p,q,L,R,val);
    update(2*node+1,(l+r)/2+1,r,p,q,L,R,val);
    merge1(node,L,R);
}
ll query(ll node,ll l,ll r,ll p,ll q,ll L,ll R)
{
    if(r<p||q<l)
        return 0;
    if(l>=p&&r<=q)
        return query1(1,1,total,L,R,node);
    return max(query(2*node,l,(l+r)/2,p,q,L,R),
               query(2*node+1,(l+r)/2+1,r,p,q,L,R));
}
int main()
{
    ll ts;
    scanf("%d",&ts);
    for(ll t=1; t<=ts; t++)
    {
        printf("Case %d:\n",t);
        ll cnt,total;
        scanf("%d %d",&total,&cnt);
        for(ll i=1; i<=total; i++)
        {
            for(ll j=1; j<=total; j++)
            {
                ll val;
                scanf("%d",&val);
                update(1,1,total,i,i,j,j,val);
            }
        }
        for(ll i=1; i<=cnt; i++)
        {
            ll I,J,S;
            scanf("%d %d %d",&I,&J,&S);
            ll l1=I,r1=J,l2=I+S-1,r2=J+S-1;
            printf("%d\n",query(1,1,total,l1,l2,r1,r2));
        }
        memset(tree,0,sizeof tree);
    }
}
