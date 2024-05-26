n,m,p=map(int,input().split()); ans=0
for i in range(p):  x,y,k=map(int,input().split());    ans+=k*(x*(m-y+1))*(y*(n-x+1))
print(ans%998244353)
