//http://www.spoj.com/problems/PSEGTREE/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    node *left,*right;
    ll val;
    node(ll a=0,node *s=NULL,node *t=NULL)
    {
        val=a;
        left=s;
        right=t;
    }
    void build(ll l,ll r)
    {
        if(l==r)
        {
            return;
        }
        left=new node();
        right=new node();
        left->build(l,(l+r)/2);
        right->build((l+r)/2+1,r);
    }
    node *update(ll l,ll r,ll idx,ll x)
    {
        if(l>idx or idx>r)
            return this;
        if(l==r)
        {
            node *temp=new node(val,left,right);
            temp->val+=x;
            return temp;
        }
        node *temp=new node();
        temp->left=left->update(l,(l+r)/2,idx,x);
        temp->right=right->update((l+r)/2+1,r,idx,x);
        temp->val=temp->left->val+temp->right->val;
        return temp;
    }
    ll query(ll l,ll r,ll p,ll q)
    {
        if(l>q or p>r)
            return 0;
        if(l>=p and q>=r)
        {
            return val;
        }
        return left->query(l,(l+r)/2,p,q)+right->query((l+r)/2+1,r,p,q);
    }
}*tree[4*100000];
int main()
{
    ll total,cnt,l,r,idx,pos,val;
    scanf("%lld",&total);
    tree[0]=new node();
    tree[0]->build(1,total);
    for(ll i=1; i<=total; i++)
    {
        scanf("%lld",&val);
        tree[0]=tree[0]->update(1,total,i,val);
    }
    scanf("%lld",&cnt);
    ll k=1;
    while(cnt--)
    {
        ll type;
        scanf("%lld",&type);
        if(type==2)
        {
            scanf("%lld %lld %lld",&pos,&l,&r);
            ll ans=tree[pos]->query(1,total,l,r);
            printf("%lld\n",ans);
        }
        else
        {
            tree[k]=new node();
            scanf("%lld %lld %lld",&pos,&idx,&val);
            tree[k++]=tree[pos]->update(1,total,idx,val);
        }
    }
}
