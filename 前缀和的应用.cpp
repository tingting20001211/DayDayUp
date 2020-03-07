#include <iostream>
typedef long long ll;
using namespace std;
int n,a[200005],s[200005],mins[200005];/**< 前缀和存储第1个到第i个这一段的和 */
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);/**< 为cin cout加速 */
    int i,j,k,maxsum;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++) /**< 递推求前缀和 */
        s[i]=s[i-1]+a[i];
    for(i=1;i<=n;i++) /**< 递推求s[1]到s[i]的最小值，存储在mins[i]中 */
        mins[i]=min(mins[i-1],s[i]);
    maxsum=a[1];
    for(i=1;i<=n;i++)/**< 枚举以i为终点的最大字段和 */
        maxsum=max(maxsum,s[i]-mins[i-1]);
    cout<<maxsum;
    return 0;
}




#include <iostream>
typedef long long ll;
using namespace std;
int n,a,s[200005],mins[200005];/**< 前缀和存储第1个到第i个这一段的和 */
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j,k,maxsum=-99999999;//int 2e9
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        s[i]=s[i-1]+a;
        mins[i]=min(mins[i-1],s[i]);
        maxsum=max(maxsum,s[i]-mins[i-1]);
    }
    cout<<maxsum;
    return 0;
}




ios::sync_with_stdio(0),cin.tie(0);/**< 为cincout加速 */   //关闭cin的同步功能
freopen(".in","r",stdin);
freopen(".out","w",stdin);
