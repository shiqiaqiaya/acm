# 寒训笔记整理

## 二分（binary search）

```c++
int l=-1,r=n;
while(l+1<r){
    int mid=l+r>>1;
    if(check(mid)){
        l=mid;
    }
    else r=mid;
}
```

1. 以上代码默认从0—n-1序号查找；

2. 左右边界初始化一定要从指向空开始！

3. 假设求 1 3 4 5 5 5 7 9 中：

   + 第一个5出现的位置

    * 最后一个小于5
       + check条件 **x<5**
    * 最后一个5出现的位置
    * 第一个大于5
      + check条件 **x>=5**

​			<u>最后根据实际判断输出 *l or r*</u>

<u>lower_bound()和upper_bound()在一些情况下相当实用捏</u>



## 三分

```c++
db l=L,r=R;
while(r-l>P){
	db mid=(l+r)/2,lmid=(l+mid)/2,rmid=(mid+r)/2;
	if(f(lmid)-f(rmid)<0) l=lmid;
	else r=rmid;
}
```

与二分的思想类似，当我们需要求解**单峰最大/最小值**时，可以用三分来查找。





## string（c++）

~~注意和c语言的string头文件区分开呦~~

+ 头文件<string>（c的头文件<cstring>/<string.h>）

 1. 构造

    ```c++
    string str1="abc";
    string str2=str1;
    string str3("efg");
    string str4(4,'x');//str4="xxxx"
    string str5("abcdefg",2,3);//str5=cde(从第2个字符开始的连续3个字符)
    ```

 2. 其他操作

    + 计算长度与比较

      ```c++
      string str="abc";
      cout<<str.size()<<" "<<str.length();
      ```

      注：c++ string的末尾与c的字符串不同，**没有** ‘\0' 。

      比较时，虽然有比较函数compare()，但还是直接用>、<、=来比较方便。

    + 赋值（assign)

      通常情况下我们直接用 = 就可以直接把一个字符串赋值给另一个。

      ```c++
      string s1="abcdefg";
      string s2;
      s2.assign(s1);//s2=s1
      s2.assign(s1,2,3)//s2=cde
      s2.assgin(4,'k');//s2=kkkk
      ```

    + 连接（append）

      如果只是普通的将整个加到后面，可以直接用 + 来运算。如s1+=s2 便是将s2整个直接加到s1的末尾。

      ```c++
      string s1="abc";
      string s2="1234567";
      s1.append(s2);
      s1.append(s2,2,3);//abc345,从第二个开始连续三个
      s1.append("1234567",2,3);
      ```

    + 查找（find）

      find()  和  rfind()

    + 替换（replace）

      ```c++
      string s1="1234567";
      s1.replace(2,1,"abc");//12abc4567
      s1.replace(2,1,"abcdef",2,3);
      s1.replace(2,1,4,'o');
      ```

    + 删除（erase）

      ```c++
      string s1="abcdefg";
      s1.erase(2,1);
      s1.erase(3);//把第三个及以后的都删除
      ```





## 树的遍历

> 以下内容都是以二叉树为基础

* 基本分类

  前序遍历——根左右

  中序遍历——左根右

  后序遍历——左右根

> 只要知道**中序遍历**和前序或是后序中的任意一个，就可以求出剩下的那一个

我们接下来以知道中序遍历和后序遍历为例来构造一棵树（前序遍历和中序遍历的组合原理相似就不另外给出了捏）

>前序遍历的最前面那个一定是根节点，同理后序遍历的最后面一个也一定是根节点。
>
>对中序遍历而言，根节点的左边所有节点都是它的左子树，右边所有节点都是它的右子树。
>
>从中序遍历得到的左右子树数量在前序遍历中一定以左右为顺序位于根节点后面，在后序遍历中则一定位于根节点的前面，数量相同。

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=40;
int n,zhong[N],hou[N],l[N],r[N];
unordered_map<int,int> pos;//用来存储

//a后序范围        b中序范围 
int build(int al,int ar,int bl,int br){
    //分别传入后序遍历的范围和中序遍历的范围
	int root=hou[ar];//通过后序遍历记录当前范围内的根
	int k=pos[root];//找到当前根在中序遍历中的位置
	if(bl<k) l[root]=build(al,k-1-bl+al,bl,k-1);
    //如果中序遍历中该点左边有点（左子树），向下递归
	if(br>k) r[root]=build(k-bl+al,ar-1,k+1,br);
    //同理，如果右边有点则向下递归
	return root;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>hou[i];
	for(int i=1;i<=n;i++) cin>>zhong[i],pos[zhong[i]]=i;
	int x=build(1,n,1,n);
	bfs(x);
	return 0;
}
```





## 前缀和

+ 一维前缀和

  没啥难点，主要是做题的时候要想到用它。

+ 二维前缀和

  求sum

  ​	$sum[i] [j]=sum[i-1] [j]+sum[i] [j-1]-sum[i-1] [j-1]+a[i] [j]$

  求子阵

  ​	$x1,y1\ \ \ \  x2,y2$

  ​	$s=sum[x2] [y2]-sum[x1-1] [y2]-sum[x2] [y1-1]+sum[x1-1] [y1-1]$

## 差分

一维差分没啥难度，直接记原理用就好了，我们在这里讲讲二维差分。

二维差分是一维差分的一个扩展。假设我们需要在[x1,y1\][x2,y2\]这个矩阵中区间加入某个数c，我们的操作如下：

```c++
void insert(int x1,int y1,int x2,int y2,int c){
	b[x1][y1]+=c;
    b[x1][y2+1]-=c;
    b[x2+1][y1]-=c;
    b[x2+1][y2+1]+=c;
}
```





## dp + 记忆化搜索

从今天开始就要写dp的题目啦！(●'◡'●)

感觉就目前来看，dp更多的是多做题得出的经验，当下次看到类似的题目时可以想到能这样dp。

所以这部分大部分的笔记都在错题那里啦！记得去看捏~(￣▽￣)~*



能用动态规划解决的问题，需要满足三个条件：**最优子结构**，**无后效性**和**子问题重叠**。

+ **最优子结构**

  当前问题的最优解中包含了子问题的最优解。这同样是贪心所具有的特征。但有的时候贪心并不能解决所有问题（如数字三角形）（笔者在这里又想到对于数字三角形不能用贪心的原因可能是我当前的决策会对我后面的决策造成影响，不符合无后效性）

+ **无后效性**

  顾名思义，当前所作的决策不会对后面的决策产生影响，后面决策也不会对前面的决策结果又影响。

+ **子问题重叠**

  如果有大量的重叠子问题，我们可以用空间将这些子问题的解存储下来，避免重复求解相同的子问题，从而提升效率。



*经典记忆化搜索题目就是滑雪啦！*

记忆化搜索是一种通过记录<u>已经遍历过的状态的信息，从而避免对同一状态重复遍历</u>的搜索实现方式。

因为记忆化搜索确保了**每个状态只访问一次**，它也是一种常见的动态规划实现方式。

[P1434 [SHOI2002] 滑雪 ](https://www.luogu.com.cn/problem/P1434)

没啥好说的，直接看代码吧

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define N 110
int n,m,num[N][N],f[N][N],vis[N][N];

int read(){//快读快读快读
	int i=0,j=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') j=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		i=i*10+ch-'0';
		ch=getchar();
	}
	return i*j;
} 

int di[]={0,1,0,-1},dj[]={1,0,-1,0};

int ski(int a,int b){
	if(vis[a][b]) return f[a][b];
	vis[a][b]=1;
	for(int i=0;i<4;i++){//向四个方向走
		int t=a+di[i],p=b+dj[i];
		if(t>0&&t<=n&&p>0&&p<=m&&num[a][b]<num[t][p]){
   //num[a][b]<num[t][p]我们是在倒着推到源头，为满足dp的无后效性
			f[a][b]=max(f[a][b],ski(t,p)+1);
            //向周围比自己高的推过去，直到不能推再一层层返回
		}
	}
	return f[a][b];
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			num[i][j]=read();
			f[i][j]=1;//每个点初始都可以达到它自己记为1
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){//因为不知道从哪个点开始最佳，所以要遍历一遍取max，c<=100 遍历的复杂度在接受范围内
			ans=max(ans,ski(i,j));
		}
	}
	cout<<ans;
	return 0;
}
```



## 线性dp

#### 最长上升子序列 LIS

非常常见的dp题目捏，要好好记模板，可用于相似问题如最长下降子序列或是最长不上升子序列之类的……

+ **lower_bound()、upper_bound()及它们与greater<>()的运用**

  - **lower_bound()**是找到第一个**>=**给定数字的位置

  - **upper_bound()**是找到第一个**>( 没有= )** 给定数的位置

    > 注意，二者使用时数组必须是有序的，且必须要**升序**（与后面greater的运用加以区分）

  - **greater<>()**

    对于lower_bound()，与greater搭配使用后，会变成找第一个**<=**给定数字的位置，同理，对upper_bound，会变成找第一个**<**给定数字的位置，但要注意，数组需要是**降序**的。

让我们来快乐的运用这些函数吧！！（题目在错题集里也有捏）

[P1020 [NOIP1999 普及组] 导弹拦截 ](https://www.luogu.com.cn/problem/P1020)

```c++
int a[N],b[N],n;
int main(){
	while(scanf("%d",&a[n])!=EOF){
		n++;
	}
	int len=0;
	memset(b,0x3f3f3f3f,sizeof(b));
	for(int i=0;i<n;i++){//最长不上升子序列长度
		if(b[len]>=a[i]){
			b[++len]=a[i];
		}
		else{//upper_bound()和greater()的标准用法，记得记得
			*upper_bound(b,b+len,a[i],greater<int>())=a[i];
		}
	}
	cout<<len<<"\n";
	len=0;
	memset(b,0,sizeof(b));
	for(int i=0;i<n;i++){//最长上升子序列长度
		if(b[len]<a[i]){
			b[++len]=a[i];
		}
		else{
			*lower_bound(b,b+len,a[i])=a[i];
		}
	}
	cout<<len<<"\n";
	
	return 0;
}
```

> 一个小总结，可重复用upper，不可重复用lower

#### 最长公共子序列 LCS

将str1与str2逐个比较，若相同就取左上角的数+1，不相同则取上方和左方中较大的数，记为当前的值，二维数组记录，也可用滚动数组。

相对应的，我们还有**最长公共子串问题**，与LCS的区别在于子串一定要连续的，故当不相同时当前格的数据为0 。



## 背包dp

### 01背包

> 最经典的背包问题啦，很多背包问题都可以转变为01背包来解决。
>
> > 有 N 件物品和一个容量为 V 的背包。放入第 i 件物品耗费的费用是 C[i]，得到的 价值是 W[i]。求解将哪些物品装入背包可使价值总和最大。

这题的关键在于每个物品只有一个，可以选择放或者不放。

从dp的分析角度来看看状态转移方程

```
对于每个物品i，它可以放进去，也可以不放，取决于放进去后是否对当前体积j有利，判断有利的条件就是加入物品i后当前体积j的价值是否变大。

因此，我们得到了状态转移方程
     f[i][j]=max{f[i-1][j],f[i-1][j-vol[i]]+val[i]}
     当前状态       不选择i            选择i
对于这个方程，我们首先要枚举i，然后再从0到V枚举j，最后得到答案是f[N][V]

以上是最简单的形式。
进一步的，为了压缩空间复杂度,我们观察可以发现每次状态转移只和i以及i-1有关，很自然的，我们想到了滚动数组，对于这题来说，它还能更进一步地压缩为一维数组：因为每次改变只和j之前的数组有关(j-vol[i])，所以，如果我们从V到vol[i]枚举j，就能保证之前的数据不受影响的同时得到正确答案。
至此就是本题的dp分析思路。
```

来看看代码~~

~~~c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1010
#define M 998244353
int n,val[N],vol[N],m,f[N];


int read(){
	int i=0,j=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') j=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		i=i*10+ch-'0';
		ch=getchar();
	}
	return i*j;
}

int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		vol[i]=read();
		val[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=vol[i];j--){
			f[j]=max(f[j],f[j-vol[i]]+val[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
~~~

> 注意，对于01背包的初始化，如果将**全部初始化为0**，那么最后得到的会是**前所有方案中的最佳答案**，既一般输出答案不用遍历取max，只需要输出最后一格就是答案了；但如果**将（0，0）初始化为0，其余初始化为-INF**，最后得到是**当前能填满**的数据格，找的时候可以知道是否能填满，但输出最优解时需要遍历取max。



### 完全背包

> 与01背包的不同点在于，完全背包中每个物品可以放无数个。
>
> > 有 N 种物品和一个容量为 V 的背包，每种物品都有无限件可用。放入第 i 种物品 的费用是 Ci，价值是 Wi。求解：将哪些物品装入背包，可使这些物品的耗费的费用总 和不超过背包容量，且价值总和最大。

很明显，从01背包推过来的话，我们可以得到一个这样的状态转移公式：

​	`f[i][j] = max(f[i-1][j],f[i-1][j-k * vol[i]] + k * val[i])`

但是，更明显的是，我们要分别枚举i，j，k，它的复杂度是O(n^3)，当数据达到1000以上时很明显会超时，所以我们需要想一个新的方法。

我们想起01背包还有个一维数组的版本，对于01背包是倒序遍历的，如果正序遍历会怎么样呢？

对于正序遍历，每次加的时候会把前面的先改变，再改变后面的，也就是说对于物品i，只要满足背包大小，它会存在一个以其体积为节的数量增加，也就是我们想要的每个物品可以加无限次知道背包满为止。

所以我们最后得出结论，对于完全背包，只需要按照01背包的**一维数组**思路，遍历体积时**从小到大遍历**，就能得到答案。代码就不另外放出来了。



### 多重背包

> 当我们把完全背包的物品个数做出限制时，就得到了多重背包。
>
> > 有 N 种物品和一个容量为 V 的背包。第 i 种物品最多有 Mi 件可用，每件耗费的 空间是 Ci，价值是 Wi。求解将哪些物品装入背包可使这些物品的耗费的空间总和不超 过背包容量，且价值总和最大。

事实上，对于多重背包，我们可以把它看成是特殊的01背包——即物品会重复的01背包。我们最直观的想法就是把一个物品重复多少次就拆成多少个，但是，当物品个数达到一定数量级（1000+）时，这个方法的复杂度就不是我们可接受的范围内了，所以我们要重新想个方法。

我们要考虑如果要用几个数字来表示从0到某个数n之间的所有数（当然接下来的方法并不是我想出来的），我们可以用到二进制表示法，既分别用1、2、4……来减去n，直到不能减为止，得到的数列就可以表示从0到n的所有数字（eg：对于9，我们用1 2 4 2能表示出来，且所用数字个数最少）

由上，我们就得到了如何解决多重背包的方法：用**二进制表示法**将物品拆分成多组，然后根据**01背包的原理**去遍历。 `宇宙的尽头是01背包`

以下只给出了部分代码

```c++
void add(int v,int w,int s){
	for(int p=1;p<=s;p*=2){
		val[cnt]=w*p;
		vol[cnt]=v*p;
		s-=p;
		cnt++;
	}
	if(s){
		val[cnt]=w*s;
		vol[cnt]=v*s;
		cnt++;
	}
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int v=read(),w=read(),s=read();
		add(v,w,s);
	}
	for(int i=0;i<=cnt;i++){
		for(int j=m;j>=vol[i];j--){
			f[j]=max(f[j],f[j-vol[i]]+val[i]);
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
```

> 这里还应该有个单调队列优化的多重背包，但我实在没学懂，所以就先跳过它吧…………………………



### 混合背包

其实就是把前三个背包混合使用，不多赘述的了。



### 二维费用的背包问题

> 对于每件物品，具有两种不同的费用，选择这件物品必 须同时付出这两种费用。对于每种费用都有一个可付出的最大值（背包容量）。问怎样 选择物品可以得到最大的价值。
>
> 设第 i 件物品所需的两种费用分别为 Ci 和 Di。两种费用可付出的最大值（也即两 种背包容量）分别为 V 和 U。物品的价值为 Wi。

尝试迁移一下之前关于背包的知识，这里其实就是用一个二维数组实现的背包，可以直接看代码吧~

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 110
int n,v,m,f[N][N];

int main(){
	cin>>n>>v>>m;
	for(int i=1;i<=n;i++){
		//第一维是体积 第二维是质量 
		int a,b,c;
		cin>>a>>b>>c;// vol mass val
		for(int t=v;t>=a;t--){
			for(int p=m;p>=b;p--){
				f[t][p]=max(f[t][p],f[t-a][p-b]+c);
			}
		} 
	}
	cout<<f[v][m];
	return 0;
} 
```



### 分组的背包问题

> 有 N 件物品和一个容量为 V 的背包。第 i 件物品的费用是 Ci，价值是 Wi。这些 物品被划分为 K 组，每组中的物品互相冲突，最多选一件。求解将哪些物品装入背包 可使这些物品的费用总和不超过背包容量，且价值总和最大。

看着很复杂，其实蛮简单的~会有一些细节需要注意。

我们只需要在求解的时候，把同一组的单独拿出来比较。以下提供了两种思路，一种是固定组内遍历体积，另一种是固定体积遍历组。

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 110
int n,m,f[N],g[N][2];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t=0;
		cin>>t;
        
        //固定体积遍历组
		for(int j=1;j<=t;j++){
			cin>>g[j][0]>>g[j][1];
		}
		for(int p=m;p>=0;p--){
			for(int j=1;j<=t;j++){
				if(p>=g[j][0]){//注意判断
					f[p]=max(f[p],f[p-g[j][0]]+g[j][1]);
				}
			}
		}
        
        //固定组遍历体积（二维数组）
        memcpy(f,g,sizeof(g));
        for(int j=1;j<=t;j++){
			int v,w;
			cin>>v>>w;
			for(int p=m;p>=v;p--){
				g[p]=max(g[p],max(f[p],f[p-v]+w));
                //这里要比较三个，否则会默认存进最后一个
			}
		}
        
	}
	cout<<f[m];
	return 0;
} 
```



### 有依赖的背包问题

> 这种背包问题的物品间存在某种“依赖”的关系。也就是说，物品 i 依赖于物品 j， 表示**若选物品 i，则必须选物品 j**。为了简化起见，我们先设没有某个物品既依赖于别的物品，又被别的物品所依赖；另外，没有某件物品同时依赖多件物品。

思想其实很简单，易知我们物品的依赖关系会构成树，我们可以通过dfs来遍历这棵树，对于每个结点的子节点，其每个体积必然存在一个最佳答案，然后对于当前结点，其最佳答案一定是其与子节点答案的总和，像这样先解决子节点再解决父节点，就可以得到最后的答案。

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 110
int n,m,f[N][N],root,g[N][2];
vector<int> nxt[N];

void dfs(int u){
	for(auto v:nxt[u]){
		dfs(v);//遍历子节点
		for(int i=m-g[u][0];i>=0;i--){
           //从m-g[u][0]开始，为u留出位置
			for(int k=0;k<=i;k++){
           //因为子节点不同体积对应的价值不同，所以要把所有可能的体积遍历
				f[u][i]=max(f[u][i],f[u][i-k]+f[v][k]);
			}
		}
	}
	for(int i=m;i>=g[u][0];i--){//将原来空出的位置补上
		f[u][i]=f[u][i-g[u][0]]+g[u][1];
	}
	for(int i=0;i<g[u][0];i++){
        //体积比g[u][0]小时无法选择u，不满足题目条件
		f[u][i]=0;
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i][0]>>g[i][1];
		int fa;
		cin>>fa;
		if(fa==-1) root=i;//标记根结点
     //因为本题只有一棵树，如果有多棵树还需要多加一个0结点作为所有的根节点
		else nxt[fa].push_back(i);
	}
	dfs(root);
	cout<<f[root][m];
	return 0;
} 
```



### 扩展背包问题

#### 求最优的方案数

基本流程与01背包类似，但为了求出方案数，我们需要多一个数组来存每个体积对应的方案数，以及为了找出哪个才是最优解，我们初识化f数组的时候需要将0以外的点置为-INF（原因见01背包），遍历后找到最优解并将等于最优解对应的方案数加起来就可以了。

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1010
#define M 1000000007
int n,m,f[N],g[N];

int main(){
	memset(f,0x3f3f3f3f,sizeof(f));
	cin>>n>>m;
	g[0]=1;
	for(int i=1;i<=n;i++){
		int v,w;
		cin>>v>>w;
		for(int j=m;j>=v;j--){
			int t=max(f[j],f[j-v]+w);
			int s=0;
            //如果相同就要同时取两边的方案数
			if(t==f[j]) s+=g[j];
			if(t==f[j-v]+w) s+=g[j-v];
			s%=M;
			f[j]=t;
			g[j]=s;
		}
	}
	int ans=0,p=0;//遍历找答案
	for(int i=0;i<=m;i++) p=max(p,f[i]);
	for(int i=0;i<=m;i++){
		if(f[i]==p){
			ans+=g[i];
		}
	}
	cout<<ans;
	return 0;
}
```



#### 输出字典序最小的最优方案

对于此问题，因为我们要按字典序小的输出，为了保证最后的正确性，所以我们遍历的时候要**从n到1遍历**，找答案的时候再从1到n寻找。

具体看代码

```c++
#include<bits/stdc++.h>
using namespace std;
#define N 1010
int n,m,f[N][N],v[N],w[N];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	for(int i=n;i>0;i--){//从n开始遍历
		for(int j=0;j<=m;j++){
		    f[i][j]=f[i+1][j];//从前面继承状态
		    if(j>=v[i]){
		        f[i][j]=max(f[i][j],f[i+1][j-v[i]]+w[i]);
		    }
		}
	}
		
	for(int i=1;i<=n;i++){
		if(m>=v[i]&&f[i][m]==f[i+1][m-v[i]]+w[i]){
        //注意要判断m>=v[i]!!!!
			cout<<i<<" ";
			m-=v[i];
		}
	}
	return 0;
}
```







## 区间dp

区间 DP 有以下特点：

​	**合并**：即将两个或多个部分进行整合，当然也可以反过来；

​	**特征**：能将问题分解为能两两合并的形式；

​	**求解**：对整个问题设最优值，枚举合并点，将问题分解为左右两个部分，最后	合并两个部分的最优值得到原问题的最优值。

以下会列举区间dp的一些常见例题，掌握后基本就都是套路了~~( •̀ ω •́ )

[区间dp总结+题解 ](https://www.luogu.com.cn/blog/BreakPlus/ou-jian-dp-zong-jie-ti-xie)



#### 石子合并类

[P1880 [NOI1995] 石子合并 ](https://www.luogu.com.cn/problem/P1880)

这类最经典，基本都是套路。

如果是环就需要在当前段后面补一段，就可以达到和链同样的效果了，枚举断点即可。

基本思路：枚举断点，枚举处理长度，枚举开头（即枚举区间），枚举区间断点

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 220
int n,sum[N<<1],minn[N<<1][N<<1],maxx[N<<1][N<<1],a[N];

int main(){
	scanf("%d",&n);
	memset(minn,0x3f3f3f3f,sizeof(minn));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		minn[i][i]=0;
		minn[n+i][n+i]=0;
	}
	for(int i=1;i<=n;i++){
		sum[n+i]=sum[n]+sum[i];
	}
	for(int len=1;len<=n;len++){//枚举处理长度
		for(int i=1;i+len<=2*n;i++){
            //会在枚举区间的时候把环断点一起枚举掉
			for(int k=i;k<i+len;k++){//枚举区间断点
				minn[i][i+len]=min(minn[i][i+len],minn[i][k]+minn[k+1][i+len]+sum[i+len]-sum[i-1]);
				maxx[i][i+len]=max(maxx[i][i+len],maxx[i][k]+maxx[k+1][i+len]+sum[i+len]-sum[i-1]);
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		ans=min(ans,minn[i][i+n-1]);
	}
	cout<<ans<<"\n";
	ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,maxx[i][i+n-1]);
	}
	cout<<ans;
	return 0;
}
```



#### 涂色套路

如果左右端点相同，涂 i 的时候可以顺带涂一下 j；涂j的时候可以顺带涂一下i。也就是，一个端点可以忽略。否则，枚举中转点涂。

```c++
#include<bits/stdc++.h>
using namespace std;
#define N 60
int n,dp[N][N];
char s[N];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n;i++){
			int j=i+len-1;
			if(j>n) break;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			if(s[i]==s[j]) dp[i][j]--;
            //这里--是我突发奇想出来的，题解是这样解的:
            //f[i][j]=min(f[i][j-1],f[i+1][j])
            //感觉它更合理一点XD
		}
	}
	cout<<dp[1][n];
	return 0;
} 
```



#### 	取一端/两端问题

[P1005 [NOIP2007 提高组] 矩阵取数游戏](https://www.luogu.com.cn/problem/P1005)

这是**取一端**的问题

__int128万岁！！！~\ (≧▽≦) /~

从小开始遍历，对于当前的区间（i，j），可能是原区间合并左端a[i]，也可能是合并右端a[j]，因为是从内开始向外反着推，所以每次结果×2就能得到对应的计算。

```c++
#include<bits/stdc++.h>
using namespace std;
#define N 100
int n,m;
__int128 a[N],dp[N][N];
//__int128内置了四则运算，我们只需要手写输入输出就可以，比高精度方便
__int128 print(__int128 x){
	__int128 a=x;
	if(a/10) print(a/10);
	putchar('0'+x%10); 
}

void scan(__int128 &x){
	__int128 i=0,j=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') j=-1;
		ch=getchar(); 
	}
	while(isdigit(ch)){
		i=i*10+ch-'0';
		ch=getchar();
	}
	x=i*j;
}

__int128 solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++){
		scan(a[i]);
	}
	for(int len=0;len<=m;len++){
		for(int i=1;i+len<=m;i++){
			dp[i][i+len]=max(dp[i+1][i+len]+a[i],dp[i][i+len-1]+a[i+len])*2;//看合并a[i]还是a[i+len]更大，记得×2
		}
	}
	return dp[1][m];
} 

int main(){
	cin>>n>>m;
	__int128 ans=0;
	for(int i=1;i<=n;i++){//每一组互不干扰，分开计算即可
		ans+=solve();
	}
	print(ans);
	return 0;
} 
```



## 状压dp

状态是一个~~非常玄学~~的东西。多数时候数组存储就可以，但有时状态数量太多，就把一个数组压缩成一个数字，通过位运算进行操作。
当然这种压缩往往只是**选或者不选**两种状态，状态太多了无法使用这种策略。

+ &按位与运算

  同为1则为1，不同为1则为0。

  &一般被看作集合的交集。比如，第k位是1代表这个集合有k这个元素，第k位是0表示这个集合没有k这个元素。则一个整数就是一个集合，两个集合的交就是这两个数字并起来。这点非常有用，一定记住！

  一般用于求第i位是0或1 。

  很容易证明，与运算是**不升**的，也就是说，一个数字不管怎么与，也**不可能大于原数字**。这一点有些题可以用到（对于unsigned）。

+ |按位或运算

  有一个1则为1，没有为0。

  这个运算一般用来给集合**赋值**。其次，或运算经常被用于作为集合的**并集**。

  同时，或运算是**不降**的。也就是说，不管怎么或，也不可能产生的数字比原来数字还小（对于unsigned）。

+ ^按位异或运算

  不进位的加法。

  两个数字对于每一位，相同为0，不同为1。

+ <<左移 / >>右移

+ ~按位取反

  后面两个都比较好理解，按位取反有个结论**~a=-a-1**

由于状压dp其自身的特性，它通常会在待选择物品的**数据范围比较小**（20以内）的时候来求解。一般的状态压缩都是**选择或者不选择**，**放或者不放**，遇见这种东西一般时状压。

<u>八皇后问题</u>也是一个状压的代表。比如<u>TSP，覆盖问题</u>之类的。经常会有这种模型的题出现就可以使用状压。

如果是比较明显的状压dp基本分成两个套路：

 1. 可预先处理出每一行的情况

    这一类的经典代表就是**放置物品**（[ 互不侵犯 ](https://www.luogu.com.cn/problem/P1896)、[ 炮兵阵地](https://www.luogu.com.cn/problem/P2704)）相似的问题，特征大概就是每个位置可选与不选，选后有**作用域**且作用域内位置不可选。遇到这种情况我们就可以预先处理出每一行可能的情况，在dp的时候可大大减少便遍历的方案数。

    上面两题都是非常经典的题目，一个求方案数一个求最大值，都值得多看看

    放个简单的代码

    [327. 玉米田 - AcWing题库](https://www.acwing.com/problem/content/description/329/)

    ```c++
    #include<bits/stdc++.h>
    using namespace std;
    #define N 13
    #define M 100000000
    int n,m,f[N][N*N],pos[N],cnt,state[N*N];
    
    int main(){
    	scanf("%d%d",&n,&m);
    	for(int i=0;i<(1<<m);i++){
    		if(!(i&(i>>1))){//处理出每一行可能的情况
    			state[cnt++]=i;
    		}
    	}
    	for(int i=1;i<=n;i++){
    		int t=0;
    		for(int j=1;j<=m;j++){
    			int p=0;
    			scanf("%d",&p);
    			t+=(p<<j-1);
    		}
    		pos[i]=(~t);
            //按题目要求记录土地情况，注意在检查行时要同时检查土地
    	}
    	f[0][0]=1;
    	for(int i=1;i<=n;i++){//一行行遍历
    		for(int j=0;j<cnt;j++){//对每一行遍历所有方案
    			for(int k=0;k<cnt;k++){//对应遍历上一行的方案数
    				if(!(state[j]&pos[i])&&!(state[j]&state[k])){
                    //检查当前方案与土地是否冲突 检查是否可以从上一行转移
    					f[i][j]+=f[i-1][k];//一个简单的状态转移方程
    					f[i][j]%=M;
    				}
    			}
    		}
    	}
    	int ans=0;
    	for(int i=0;i<cnt;i++){//遍历得到总答案
    		ans+=f[n][i];
    		ans%=M;
    	}
    	cout<<ans;
    	return 0;
    }
    ```

    

 2. 不可预先处理

    一般是**求图路径**（[最短Hamilton路径](https://www.acwing.com/problem/content/description/93/)）或是**求选择方案**（[P3092 No Change G ](https://www.luogu.com.cn/problem/P3092)）之类的，符合上述的状压dp的特征。对于此类问题，我们在dp时要遍历(1<<n)-1种方案数。

    也是一个简单的代码（Hamilton）

    ```c++
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define N 21
    int n, a[N][N], f[1 << N][N];
    
    int main() {
    	scanf("%d", &n);
    	memset(f, 0x3f, sizeof(f));
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			scanf("%d", &a[i][j]);
    		}
    	}
    	f[1][0] = 0;
    	for (int k = 0; k < (1 << n); k++) {//遍历方案
    		for (int i = 0; i < n; i++) {//找可状态转移的点
    			for (int j = 0; j < n; j++) {
    				if ((k & (1 << i)) && (k & (1 << j))) {
                      //  i是否在方案中       j是否在方案中
                      //  都在说明对k方案j可以走到i
    		f[k][i] = min(f[k][i], f[k ^ (1 << i)][j] + a[i][j]);
            //状态转移找到当前点的最短路径  从上一个点转移过来
    				}
    			}
    		}
    	}
    	cout << f[(1<<n)-1][n-1];
    	return 0;
    }
    ```

    

## 期望dp

一种跟数学紧密联系的dp QAQ（俺是数学苦手呜呜呜呜呜呜呜）

简单来说是我们对于一系列可能发生的随机事件进行分析，最终得到可能结果的过程。可以看作**加权平均数**。比如最简单的，对于投一个六面骰，我们的期望得分为（1+2+3+4+5+6）/ 6 = 3.5 。

+ 一些简单的性质

  ```
  设X是随机变量，C是常数，则E(CX)=C×E(X)；
  设X，Y是任意两个随机变量，则有E(X+Y)=E(X)+E(Y)；
  设X，Y是相互独立的随机变量，则有E(XY)=E(X)×E(Y)；
  设C为常数，则E(C)=C。
  ```

  

+ 期望与均值

  均值往往是在实验中简单的对数据进行平均，而期望就好像在上帝视角的人。

  ```
  举个掷骰子的例子：
  	我们的均值怎么算呢？显然要掷上一定多的次数来求平均数。比如，掷了6次，分别为1,5,5,6,3,3，那么均值为3.83333...可是期望呢？我们不用掷骰子就能计算出来为3.5，可以看出，两个值是有明显差别的，而且还时刻不同。在将多个均值求均值后，两者就无限接近了。
  ```

  只有**把随机事件映射到随机变量上**，才能够通过对随机变量进行期望计算，从而估计随机事件的某些性质。





## KMP（字符串查找算法）

> **KMP算法**（全称Knuth-Morris-Pratt字符串查找算法，由三位发明者的姓氏命名）是可以在**文本串s**中快速查找**模式串p**的一种算法。

$O(n+m)$

+ 基本思想

  ​	对于模式串p，在匹配的过程中，若与s失配后直接回退到p的开头，会造成时间以及对之前**已经匹配**的部分的浪费。为了减少这种浪费，我们先对p进行预处理：找出p（在不同地方结束的）**相同前后缀**，记为**PMT**（Partial Match Table，部分匹配表），当我们再次遍历s与p进行匹配时，在失配时只需要**跳到上一个相同前缀的结尾**即可，不用直接跳到开头。

> KMP算法的巧妙之处就在于它的**PMT**，在理解了这一点后，只需要对它进行综合运用就好啦——接下来看看板子。

```c++
//a是主串，b是模式串
for(int i=2,j=0;i<m;i++){//i是后缀指针，j是前缀指针
    //注意i从2开始，否则就不是后缀了（从头开始的后缀就是字符串本身）
	while(j&&b[i]!=b[j+1]) j=nxt[j];//一定是i和j+1！！！
    //已知在此之前i-1后缀与j前缀相同，经过一轮循环i指到下一个，所以要和j+1进行匹配，如果失配j就跳到上一个能i-1和j能匹配的前缀，看是否能匹配上
	if(b[i]==b[j+1]) j++;//此时j还指在上一个能匹配上的前缀末位（或是0，即失配）
	nxt[i]=j;//注意这里存的是j，因为前面已经把+1加上了
}
int ans=0;
for(int i=1,j=0;i<n;i++){
    //和主串匹配的时候过程和上面其实大差不差，注意从子串的1开始
	while(j&&a[i]!=b[j+1]) j=nxt[j];
	if(a[i]==b[j+1]) j++;
	if(j==m-1){//注意是m-1，当然如果你的模式串从1开始存就是m，判断当前对上了
		ans++;
		j=nxt[j]; //这个很重要！当时改了好久呜呜呜……
        //有没有它好像大差不差，但在一些地方很重要
	}
}
```



## Manacher（回文子串）

+ 基本思想

  易知，当我们找到一个回文串时，以这个回文串中心为对称点，其左右两边的回文子串长度一一对应。利用这个性质，我们可以**枚举回文中心**，如果当前中心在上一回文串覆盖下，就可以直接**找当前中心的对称中心**，进行转移。

  为了达到此目的，我们可以记录当前覆盖范围的**中心mid**，以及**最右覆盖r**（左边已经遍历过就不需要再重复处理），对于每个i，我们要注意处理区间，既对称点的覆盖范围是否超过了当前区间的最右，取小的那个。**超过就要更新覆盖区间**。

  注意，为了消除枚举中心点时奇偶回文串之间的差异，我们在读入字符串的时候应对字符串做插空处理，如 abc => $#a#b#c#，以保证得到的回文子串是奇数回文串，才可以枚举中心i。

  这个算法的时间复杂度大约在O(n)。

  ```c++
  int n;
  char s1[N],s[N<<1];
  
  void seet(){
      s[0]='$';
      s[1]='#';
      int k=1;
      for(int i=1;i<=n;i++){
          s[++k]=s[i];
          s[++k]='#';
      }
      n=k;
  }
  
  int d[N<<1];
  void manacher(){
      int mid=0,r=0;
      for(int i=1;i<=n;i++){
          if(i<r) d[i]=min(d[mid*2-i],r-i)//d[mid]+mid-i
          else d[i]=1;
          while(s[i+d[i]]==s[i-d[i]]) d[i]++;
          if(d[i]+i>r){
              mid=i;
              r=d[i]+i;
          }
      }
  }
  
  int main(){
      cin>>s1+1;
      n=strlen(s1+1);
      seet();
      manacher();
      return 0;
  }
  ```

  ***最长回文子串长度 d[i]\*2 - 1***

  ***回文子串个数  d[i] / 2***



## Trie树

**字典树**（**Trie**）是一个比较简单的数据结构，也叫**前缀树**，用来存储和查询字符串。

+ 基本思想

  对于多个长度不一的字符串，储存时若一个一个存储很明显不方便查找的同时占用的空间较大，为解决这问题，诞生的trie树，既按照相同的前缀来储存字符串。例如，`water`，`wish`，`win`，`tie`，`tired`这几个单词可以用以下方式存储：![img](https://pic1.zhimg.com/v2-09eb3d3980f61e573d47daf4fa329d14_r.jpg)

代码如下

~~~c++
int n,nxt[N][30],cnt,ed[N];

void init(char s[]){
    int len=strlen[s];
    int k=0;
    for(int i=0;i<len;i++){
        if(!nxt[k][s[i]-'a']) nxt[k][s[i]-'a']=++cnt;
        k=nxt[k][s[i]-'a'];
    }
    ed[k]=1;
}

bool find(char s[]){
    int len=strlen(s);
    int k=0;
    for(int i=0;i<len;i++){
        if(!nxt[k][s[i]-'a']) return false;
        k=nxt[k][s[i]-'a'];
    }
    if(end[k]) return true;
    else return false;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char s[N];
        cin>>s;
        init(s);
    }
    char s[N];
    cin>>s;
    if(find(s)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
~~~

当我们和两个数异或求最大值之类的问题扯上关系的时候，也可以考虑trie树。

又或者是一串数的异或和，我们可以将其转换为前缀和两个数的异或，就可以得到答案了。





## AC自动机

给出多个模式串和一个文本串，找出有多少个模式串在文本串中出现。

+ 基本思想

  > 以下均默认字符串中只有a~z，如果出现其他情况可以自己调整

  为了方便查询，我们首先想到用**trie树来存模式串**。但随后问题出现了，如果我在某个模式串中匹配失配，若直接跳至0结点重新匹配，若与下一文本串有重叠部分，重叠部分将无法被匹配。为了解决此问题，我们在trie树的基础上，增加了**回跳数组**。同时，为了减少多次回跳浪费，我们还增加了**转移数组**。基本规则如下：

   1. 在存好模式串后用**BFS**遍历，从根节点开始先将根节点的所有子节点入队。

   2. 每次从队列中取节点u，遍历它的26个子节点：

      (1) 如果子节点存在，这**父亲帮儿子**建立**回跳边**，并把**儿子入队**；

      (2)如果不存在，则**父亲自建转移边**。

以下是代码

~~~c++
int n,tr[N][30],cnt,ed[N],nxt[N];
char s[N];

void add(){//经典trie树存图
    int len=strlen(s),k=0;
    for(int i=0;i<len;i++){
        if(!tr[k][s[i]-'a']) tr[k][s[i]-'a']=++cnt;
        k=tr[k][s[i]-'a'];
    }
    ed[k]++;//可能有相同模式串
}

void build(){
    queue<int> q;
    for(int i=0;i<26;i++){//根节点所有存在的子节点入队
        if(tr[0][i]) q.push(tr[0][i]);
    }
    while(q.size()){//BFS
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){//遍历26个子节点
            if(tr[u][i]){//如果存在，则父亲帮儿子建立回跳边，儿子入队
                int v=tr[u][i];
                nxt[v]=tr[nxt[u]][i]
                q.push(v);
            } 
            else{//不存在，父亲自己建立转移边
                tr[u][i]=tr[nxt[u]][i];
            }
        }
    }
}

int query(){
    int lne=strlen(s),k=0,ans=0;
    for(int i=0;i<len;i++){
        k=tr[k][s[i]-'a'];//因为build的时候建立了转移边，相当于把所有点全部连通，故我们不用判断该点是否存在直接跳转
        for(int j=k;j&&~ed[j];j=nxt[j]){
            ans+=ed[j];
            ed[j]=-1;//记录是否已经加入该模式串，~（-1）=0
        }
    }
    return ans;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        add();
    }
    build();
    cin>>s;
    cout<<query();
}
~~~





## 博弈论

[由此整理](https://www.luogu.com.cn/blog/Wolfycz/qian-tan-suan-fa-bo-yi-lun-zong-ling-kai-shi-di-bo-yi-lun-post)

### 引入 Bash Game

> 两位游戏者，一堆n个石子，轮流取每次可取1-k颗石子，问先手的必胜策略。

这是一个很简单的小学奥数题（当然在下是蒟蒻并没有参加过小学奥数比赛自然也不知道这种事情，是从大佬那里听说的），在此只是作为后续内容的一个引入。

对于这个问题，答案就是，如果`n%(k+1)==0`那么先手必败，否则只要先手第一次拿走`n%(k+1)`粒，并且后面始终保持与对方每次共同取走`k+1`粒，就能保证先手必胜。

以上几乎就是一个多次经验的累加和找规律记忆的过程，事实上，对于博弈论而言（至少是在下目前遇到的大多数博弈论），我们要么能似曾相识地在以前找到模板，要么一定能在有限次数的游戏中找出必胜的规律。



引入结束了让我们来讲一些概念吧：

1. **平等组合游戏**

     + 两人游戏。

   - 两人轮流走步。
   - 有一个状态集，而且通常是有限的。
   - 有一个终止状态，到达终止状态后游戏结束。
   - 游戏可以在有限的步数内结束。
   - 规定好了哪些状态转移是合法的。
   - 所有规定对于两人是**一样**的。

   因此Bash Game即为一个平等组合游戏，但是我们生活中常见的棋类游戏，<u>如象棋、围棋等，均不属于平等组合游戏</u>，因为双方可以移动的棋子不同，不满足最后一个条件；而我们后续提到的游戏，以及博弈中的其他游戏，基本属于平等组合游戏。

2. **N-position / P-position**

   N-positon——先手必胜状态

   P-position——先手必败状态

   > 此处的先手是指当前局面下将要行动的一方，而不是初始的先后手。

   那么我们定义两个状态之间的转换：

   - 无法进行任何移动的是P状态
   - **可以移动**到P状态的是**N状态**
   - 所有移动**都导致**N状态的是**P状态**

   > 正如我们之前所说，P是先手必败，而这可悲的状态结束方法却只掌握在对方——既处在N状态的人身上，多么可悲的游戏啊。



### Nim Game

> 是上面Bash Game的扩展，当石子个数增加到了n堆，我们要如何找到先手必胜策略呢？

事实上这个我们只需要记住结论就好了，具体的证明过程我也不知道捏（不知道未来的我知不知道）。

结论就是，我们对于每堆石子求其个数的**异或和**，Nim游戏先手必败当且仅当`x1⊕x2⊕...⊕xn = 0`，否则，设异或和为k，只需要在第一次取走任意一堆石子个数`j-j⊕k`个，按此规律无论对方取走多少个，我们只需要取走`j-j⊕k`个就可以了。



### SG函数与Mex函数

[看这里捏](https://blog.csdn.net/AC__dream/article/details/120617787?ops_request_misc=%7B%22request%5Fid%22%3A%22167404786016800182124764%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=167404786016800182124764&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-120617787-null-null.142^v71^one_line,201^v4^add_ask&utm_term=sg函数&spm=1018.2226.3001.4187)

介绍SG函数前先介绍一下**mex函数**，表示**最小**的**不属于**这个集合的**非负整数**，比如mex{0，1，3，4}=2，mex{1，2，3}=0;

任何一个可以用**SG函数**解决的问题都可以抽象成一个有向图游戏（在此我们可以简单理解为上面所提到的**平等组合游戏**），SG函数是用于为这种有向图游戏提供最优策略的。（SG(x)=0代表x为必败态，SG（x）!=0代表x为必胜态）

通过对当前状态下的SG函数进行设计，我们求f(u) = mex{ f(v) **∣** v∈child[u]}

> 把原问题按照游戏规则的差别分解成多个**独立的子游戏**，并计算每个子游戏下的**SG值**，最后求出所有子游戏的SG值的**异或**。

上面提到的**子游戏**，我们可以简单理解为对**每一堆石子**来求出其SG值。



最后给出常见的SG值的计算方法：

（1）若可选步数为**1~m**的连续整数（巴什博弈），则SG（x）=x%(m+1)

（2）若可选步数为**任意步**，则SG（x）=x

（3）剩余的情况只能具体问题具体分析

一个简单的求SG值的实现

~~~c++
int sg(int x){//计算石头数量为x的sg值，这里每个状态只有一个元素，即石头数量
    if(f[x]!=-1) return f[x];//如果在线计算过，那么直接返回
    unordered_set<int> g;
    for(int i=0;i<m;i++){//计算其子节点的sg值
        if(x>=s[i]) g.insert(sg(x-s[i]));
        //这里的s[i]表示所有接下来可以取走的石子状态的集合
    }
    
    for(int i=0;;i++){//mex函数
        if(!g.count(i)) return f[x]=i;
    }
}
~~~

对于每次只能选取**一堆石子来拿**的Nim游戏及其变形（每次只能取某个集合中的数 / 只能取当前堆石子总数的 1 / 2 /...），SG值都非常适用。



### Nimk Game

> 有n堆石子，石子数目分别为$x_i$，A、B两人每次可以选取最多k堆石子，并从选中的每堆石子堆中取走任意多的石子，问A是否有必胜策略

Nimk存在必胜策略，当且仅当，将所有石子数转成**二进制**后，存在**某位**上，所有二进制数中**1的个数之和% (k + 1) 不为0**。



### Wythoff's Game

> 有两堆石子，个数为x1，x2；A、B轮流取石子，规定要么只取一堆的任意多个，要么在两堆里取同样任意多个，问A先手是否有必胜策略。

菜鸡不会证，直接记结论吧。
$$
a_k = \lceil k \times \frac{\sqrt{5}+1}{2}\rceil
$$

$$
b_k=a_k+k
$$

以及一个简单的代码实现

~~~c++
int main(){
	scanf("%d%d",&a,&b);
	if(a>b) swap(a,b);
	if(a==(int)(((1.0+sqrt(5.0))/2.0)*(b-a))) printf("0");
	else printf("1");
	return 0;
}
~~~



> 往下翻了翻，感觉接下来的东西相当玄学（我不想看证明呜呜），不如先到此为止吧，有缘再见。



## 素数

> 素数，又称质数，是我们从小学到大学都会接触的一个概念，相信大家已经很熟悉了，在这里就不贴出它的定义了，只提醒一句，**0和1不是素数**。我们接下来主要将如何在O(n)的时间内求出1~n以内的全部素数。

### 埃氏筛

最朴素的素数筛。基本思想就是，如果一个数是素数，那么它的倍数一定不是素数，并且每个数都可以分解为质因数的乘积，故我们从2开始向后枚举，**遇到素数就枚举**它小于n的倍数，标记为非素数。

~~~c++
int np[N];
void init(int n){
    np[1]=np[0]=1;
    for(int i=2;i<=n;i++){
        if(!np[i]){
            for(int j=2;j*i<=n;j++) np[j*i]=1;
        }
    }
}
~~~

这个算法的复杂度大概是O(n loglog n)，虽然已经很优秀了，但我们还有可以优化的地方：我们很明显可以发现，对于像6，12，14等有两个或以上质因数的数，我们会对它多次筛去，这个重复显然就是我们可优化的地方。



### 欧拉筛

为了优化上面所说的重复，欧拉筛就派上了用场。

我们可以想到，既然每个数都可以分解为多个质因数的乘积，那我们能否指定一个数一定由它的某个质数消去呢？在这里，我们就指定每个数一定由它的最小的质因数消去。

~~~c++
int np[N],prime[N],cnt;
void init(){
    np[0]=np[1]=1;
    for(int i=2;i<=n;i++){
        if(!np[i]) prime[cnt++]=i;
        for(int j=0;j<cnt&&i*prime[j]<=n;j++){
            np[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
~~~

欧拉筛和埃氏筛的区别主要有两点

 1. 欧拉筛不管当前数**是不是素数**，**都**会将其与质数表相乘消去后面的数。

 2. 欧拉筛有一步`if(i%prime[j]==0) break`，这步很重要，决定了一个数是否只会被它**最小的质数**消去，我们用例子来说明：

    ​	当筛到4的时候，质数表里已经有了2和3，如果没有break，那我们应该用2×4筛去8，用3×4筛去12，但实际上12的最小质因子是2，也就是它其实应该被2×6筛去。当我们加上break，意思就是当前的质数p能将i整除，那么对于i的p之后的质数的倍数，都能被p整除，并且这个p一定比之后的倍数小，所以p才是i最小的质因子。



### 素性测试

感觉没咋用过，这里贴个[OI-WIKI](https://oi-wiki.org/math/number-theory/prime/#%E7%B4%A0%E6%80%A7%E6%B5%8B%E8%AF%95)的链接好了……



### 反素数

> 任何小于n的正数的约数个数都小于n的约数个数，换句话说，在一个集合中，因素最多并且值最小的数，就是反素数。

一个求反素数的模板

~~~c++
#include<stdio.h>
#define ULL unsigned long long
#define INF ~0ULL
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
ULL ans;
int n;
//depth:当前在枚举第几个素数。num:当前因子数。
//temp:当前因子数量为num的时候的数值。up：上一个素数的幂，这次应该小于等于这个幂次嘛
void dfs(int depth,int temp,int num,int up){
    if(num > n||depth >= 16) return;
    if(num == n&&ans > temp){
        ans = temp;
        return;
    }
    for(int i = 1;i <= up;i++){
        if(temp/p[depth] > ans) break;
        dfs(depth+1,temp = temp*p[depth],num*(i+1),i);
    }
}
int main(){
    while(scanf("%d",&n) != EOF){
        ans = INF;
        dfs(0,1,1,64);
        printf("%d\n",ans);
    }
    return 0;
}
~~~



## 数论入门

[大人请看（递）](https://oi-wiki.org/math/number-theory/basic/)

> 在此只摘录一些自己没太见过的。

+ 余数的定义

  设$a,b$为两个给定的整数，$a\neq0$。设$d$是一个给定的整数，那么一定存在唯一的一堆整数$q,r$，满足$b=qa+r,d\leq r <|a|+d$。

  无论$d$取任何值，$r$统称为余数。$a|b$等价于$a|r$。

  一般情况下，$d$取0，此时等式$b=qa+r,d\leq r <|a|$称为带余数除法（带余除法）。这里的余数$r$称为最小非负余数。

  余数还有两种常见的取法：

  1. 绝对值最小余数：$d$取$a$的绝对值的一半的相反数。即$ b=qa+r,-\frac{|a|}{2}\leq r <|a|-\frac{|a|}{2}$。
  1. 最小正余数：$d$取1，即$b=qa+r,1\leq r<|a|+1$。
  
+ 多个素数互素，$gcd(a_1,a_2...a_k)=1$，但他们不一定两两互素，如6、10、15互素，但任意两个都不互素。
+ 所有大于3的素数都可以表示为6n+1 / 6n-1的形式，但不是所有这个形式的数都是素数。
+ 同余的性质
  1. 自反性    $a\equiv a\ (mod\ m)$
  2. 对称性    $a\equiv b\ (mod\ m)\ \leftrightarrow b\equiv a\ (mod\ m)$
  3. 传递性    若$a\equiv b\ (mod\ m),b\equiv c\ (mod\ m)$，则$a\equiv c\ (mod\ m)$
  4. 线性运算    若$a\equiv b\ (mod\ m),c\equiv d\ (mod\ m)$，则$a\pm c\equiv b\pm d\ (mod\ m)$，$a\times c\equiv b\times d\ (mod\ m)$
  5. 若$k$为整数，$a\equiv b\ (mod\ m)$，则$ak\equiv bk\ (mod\ mk)$，若a,b,m能被d整除，则同理。
  6. 若$a\equiv b\ (mod\ m)$成立，有$gcd(a,m)=gcd(b,m)$，若$d$能整除$m$及$a$，$b$中的一个，则$d$必定能整除$a$，$b$中的另一个



## 扩展欧几里得算法

求解$ax+by=gcd(a,b)$

先简单贴个代码模板

~~~c++
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1,y = 0;
        return a;
    }
    ll x1, y1, d;
    d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}
~~~

[关于求通解和特解](https://zhuanlan.zhihu.com/p/100567253)

如果要求**最小正整数解**，只需要输出x对b“模加模”`(x % b + b) % b`的结果就可以了。



## 快速幂

> 记住个板子就好啦~

~~~c++
ll qpow(ll a,ll x){
    ll res=1;
    while(x){
        if(x&1) res=res*a%p;
        a=a*a%p;
        x>>=1;
    }
    return res;
}
~~~

[算法学习笔记(4)：快速幂](https://zhuanlan.zhihu.com/p/95902286)



## 逆元

在数论中，如果$ab\equiv 1\ (mod\ p)$我们就说$a$和$b$在模$p$的意义下互为乘法逆元，记做$a=inv(b)$。

逆元有什么用呢？我们常常遇到一些题目要求结果对一个大质数$p$取模，这是因为答案很大，出题人为了不麻烦大家写高精，就采取这样的方法。**加减法**和**乘法**对取模运算都是**封闭**的，所以你可以**处处取模**来避免溢出。但遇到除法时就会出现麻烦，所以<u>为了解决**除法**下的取模问题，我们引入了**逆元**</u>。

我们可以简单的把$inv(a)$看作在模$p$意义下的$\frac{1}{a}$，那么在模p意义下的$\frac{a}{b}$就可以看成$a\times inv(b)\ (mod\ p)$。

求解逆元的方法我们在此讲以下几种：

> 当求逆元的时候我们是**可以对a取模**的！！！

 + **费马小定理**

   费马小定理是数论里的重要定理，叙述如下：

   > 若$p$是质数，且$gcd(a,p)=1$，则有$a^{p-1}\equiv 1\ (mod\ p)$     

   从逆元的定义推导，可得$a\times inv(a)\equiv1\equiv a^{p-1}\ (mod\ p)$，于是就有$inv(a)\equiv a^{p-2}\ (mod\ p)$，只需要对$a^{p-2}$算一下快速幂就可以了。

   注意这个方法要求**$p$一定是质数**。                                                                                                                                                                                                                                                         

 + **扩展欧几里得**

   注意判断是否有解：**a和p互质**

   ~~~c++
   ll exgcd(ll a, ll b, ll &x, ll &y){
       if(b == 0){
           x = 1,y = 0;
           return a;
       }
       ll x1, y1, d;
       d = exgcd(b, a % b, x1, y1);
       x = y1,y = x1 - a / b * y1;
       return d;
   }
   
   ll inv(ll a, ll p)
   {
       ll x, y;
       if (exgcd(a, p, x, y) != 1) // 无解的情形
           return -1;
       return (x % p + p) % p;
   }
   ~~~

 + **线性递推**

   通常情况下前面两种就可以搞定啦~这个是很特殊的情况才用的。

   要保证$p$是质数。

   初始化inv(0)=0, inv(1)=1。$inv(a)=-\lfloor \frac{p}{a}\rfloor\times inv(p\ mod\ a)\ (mod\ p)$。

   只需要用记忆化搜索就可以得出答案了。

   ~~~c++
   // 多次对不同的p使用需要清空Inv数组
   ll Inv[MAXN] = {0, 1};
   inline ll mod(ll a, ll p)
   {
       return (a % p + p) % p;
   }
   ll inv(ll a, ll p)
   {
       if (Inv[a])
           return Inv[a];
       Inv[a] = mod(-p / a * inv(p % a, p), p);
       return Inv[a];
   }
   ~~~

   



## 线性同余方程

形如$ax\equiv b\ (mod\ n)$的方程称为**线性同余方程**（Congruence Equation），其中$a,b,n$为给定的整数，$x$为未知数，需要从$[0,n-1]$中求解，当解不唯一的时候需要求出全体解。

+ 用**逆元**求解

  简单的情况，当**a与n互质**的时候，可以计算a的**逆元**，并将方程两边同时乘上逆元，就可以得出**唯一解**。
  $$
  x\equiv ba^{-1}(mod\ n)
  $$
  

  <u>当a与n不互质的时候呢？</u>我们可以来分析一下。首先此情况不一定有解，那么有解的条件就是$gcd(a,n)\ |\ b$，其中$a$和$n$都大于1。

  若上述成立，我们再方程两边同时除以$gcd(a,n)$，得到了一个新的方程
  $$
  a^\prime x \equiv b^\prime\ (mod\ n^\prime)
  $$
  很明显$a^\prime$和$n^\prime$已经**互质**，于是我们得到了$x^\prime$作为此方程的解，很明显$x^\prime$也是原方程的解，但不是唯一解。原始方程有如下$g$个解，$g=gcd(a,n)$
  $$
  x_i \equiv (x^\prime+i\times n^\prime)(mod\ n)\ \ \ for\ i=0...g-1
  $$
  总之，线性同余方程**解的数量**等于$gcd(a,n)$或等于$0$。

  

+ 用**扩展欧几里得**求解

  原来的线性同余方程可以改写为以下形式：
  $$
  ax+nk=b
  $$
  其中$x$和$k$是未知数，有整数解的充要条件是$gcd(a,n)\ |\ b$。由此我们可以先用扩展欧几里得求出一组$x_0,k_0$，也就是$ax_0+nk_0=gcd(a,n)$，然后两边同时除以$gcd(a,n)$，再乘上$b$，就得出了一个解。

  对于上面求出来的一组解，方程的通解表示为（假定已经对$x_0,k_0$进行了操作）
  $$
  x=x_0+nt\\
  k=k_0-at
  $$

​		且对任意整数$t$都成立。

​		在做题的时候常常需要我们求出最小正整数解，此时假定$t=\frac{n}{gcd(a,n)}$
$$
x=(x\ mod\ t+t)\ mod\ t
$$


## Euler 欧拉函数

[算法学习笔记(18): 欧拉函数](https://zhuanlan.zhihu.com/p/108422764)

在数论中的一个很重要的函数。定义为小于等于x且与x互质的正整数的数量。特别的，规定phi[1]=1。

对于欧拉函数，主要有以下几个性质：

+ 若$p$是质数，则$phi[p]=p-1,\ phi[p^n]=p^{n-1}\times(p-1)$。

+ 若$a\ |\ x$，则$phi[ax]=a\times phi[x]$。
+ 若$a,b$互质，则$phi[ab]=phi[a]\times phi[b]$

> 可以去上面的链接看看性质的证明。

如果只求一个数的函数值，我们有这一条公式
$$
x=p_1^{k_1}p_2^{k_2}...p_n^{k_n}\\
phi[x]=x\times \frac{p_1-1}{p_1}\times \frac{p_2-1}{p_2}...\times\frac{p_n-1}{p_n}
$$
对$x$进行质因数分解就可以在最坏$O(\sqrt n)$的时间复杂度内求出单个的欧拉函数值。

~~~c++
int phi(int n){
  	int res = n;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0)
            res = res / i * (i - 1); // 先除再乘防止溢出
        while (n % i == 0) n /= i;
       	// 每个质因数只处理一次，可以把已经找到的质因数除干净
    }
    if (n > 1) res = res / n * (n - 1); 
    // 最后剩下的部分也是原来的n的质因数
    return res;
}
~~~

如果要求多个（1~n）的数的欧拉函数，上面的方法复杂度显然不行，那么我们有和**线性筛**结合的解法。

~~~c++
int np[N],prime[N],phi[N];
void init(int n){
    phi[1]=1;
    np[0]=np[1]=1;
    for(int i=2;i<=n;i++){
        if(!np[i]) prime[cnt++]=i,phi[i]=i-1;//性质1
        for(int j=0;j<cnt&&prime[j]*i<=n;j++){
            if(i%prime[j]==0){//上面的性质2
                phi[i*prime[j]]=prime[j]*phi[i];
                break;
            } //与质数不互质的只可能是它的倍数，所以排除是倍数后我们可以认为i与prime[j]互质，就用积性函数的性质（性质3）
            else phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
}
~~~

欧拉函数的一个性质
$$
\sum_{d\ |\ n}phi[d]=n
$$


[欧拉函数|(扩展)欧拉定理|欧拉反演](https://www.cnblogs.com/Morning-Glory/p/11106828.html#_label0)



## 整除分块

简单来理解，能快速计算$\sum_{i=st}^{ed}\lfloor \frac{n}{i} \rfloor$及与其相似的一系列式子的方法，就是整除分块。

我们先来几条式子便于我们后面的化简

 + $\lceil \frac{a}{b}\rceil=\lfloor\frac{a-1}{b}\rfloor+1$
 + $a\ mod\ b=a-\lfloor\frac{a}{b}\rfloor\times b$
 + $\sum_{i=1}^n k=nk$（$k$为常数）
 + $\sum_{i=st}^{ed}i=\frac{(a+b)}{2}\times(b-a+1)$
 + $\sum_{i=1}^n i^2=\frac{(n)(n+1)(2n+1)}{6}$
 + $\sum_{i=1}^n i^3=(\sum_{i=1}^n i)^2$



接下来我们看看要怎么快速计算：

我们可以通过打表发现，上述$\sum_{i=st}^{ed}\lfloor \frac{n}{i} \rfloor$在一定区间内的值是连续不变的，那我们可以想到利用这个不变的区间来加速计算，而不用一个一个乘。这些区间的特征是$\lfloor\frac{n}{l}\rfloor=\lfloor\frac{n}{r}\rfloor$，对于这个特征，左端点$l$就是上一个区间的右端点$r$ +1（初识为1），那么要怎么求右端点呢？

由$\lfloor\frac{n}{l}\rfloor=\lfloor\frac{n}{r}\rfloor\leq\frac{n}{r}$，可得出$r\leq\frac{n}{\lfloor\frac{n}{l}\rfloor}$，所以$r=\lfloor\frac{n}{\lfloor\frac{n}{l}\rfloor}\rfloor$。

放个板子

~~~c++
ll solve(ll st,ll ed,ll num){
	ll res=0;
	ed=min(ed,num);//!!!
	for(ll l=st,r=0;l<=ed;l=r+1){
		r=min(ed,num/(num/l));//!!!
		res+=cal(l,r)*(num/l);
        //   区间个数  区间值
        // 根据式子改变  在一个区间内不变
	}
	return res;
}
~~~

（后续会更新一些题目在这里的）



## 莫比乌斯函数及反演

> 看不懂头发掉掉呜呜

### 莫比乌斯函数

$$
\mu(n)=\begin{cases}1\ \ \ \ \ \ \ \ \ \ \ \ n=1\\0\ \ \ \ \ \ \ \ \ \ \ \ n含相同的质因子\\(-1)^s\ \ \ \ s为n的不同质因子的个数\end{cases}
$$

和欧拉函数同理，我们可以通过线性筛来求莫比乌斯函数，代码如下。

~~~c++
int prime[N],np[N],cnt,mu[N];
void get_mu(int n){
    np[0]=np[1]=mu[1]=1;//初始化捏~(￣▽￣)~*
    for(int i=2;i<=n;i++){
        if(!np[i]){
            prime[cnt++]=i;
            mu[i]=-1;//注意初始化
        }
        for(int j=0;j<cnt&&prime[j]*i<=n;j++){
            np[prime[j]*i]=1;
            if(i%prime[j]==0){//证										明当前有重复的质因子了
                //mu[i*prime[j]]=0;
                //牢记要制为0（好像不用也可以，直接break）
                break;
            }
            else mu[i*prime[j]]=-mu[i];//没有重复质因子就从上一个继承过来
        }
    }
}
~~~



莫比乌斯函数的性质
$$
\sum_{d\ |\ n}\mu(d)=[n=1]
$$
我们再来复习下Euler函数的性质
$$
\sum_{d\ |\ n}phi[d]=n
$$
我们可以得到一条上述两者的关系式
$$
\sum_{d\ |\ n}\mu(d)\frac{n}{d}=phi(n)
$$

### 积性函数

$f[1]=1$，当$gcd(a,b)=1$时，有$f[ab]=f[a]*f[b]$，则称$f[n]$为积性函数。

我们上述的**欧拉函数**和**莫比乌斯函数**都是积性函数



### 狄利克雷卷积

欧拉函数也可以表示为
$$
phi(n)=\sum_{i=1}^n [gcd(i,n)=1]
$$

+ **狄利克雷卷积**

  [554 狄利克雷卷积](https://www.bilibili.com/video/BV1g24y1S73q/?spm_id_from=333.999.0.0&vd_source=ca4c39ed7f47fa69f580bce0c7eea582)

  假设$f(n),g(n)$为积性函数，则$(f*g)(n)=\sum_{d\ |\ n}f(d)g(\frac{n}{d})=\sum_{d\ |\ n}f(\frac{n}{d})g(d)$，如$(f*g)(4)=f(1)g(4)+f(2)g(2)+f(4)g(1)$。

  

  + 狄利克雷卷积满足如下**规律**
     	1. 交换律      $f*g=g*f$
     	2. 结合律      $(f*g)*h=f*(g*h)$
     	3. 分配律      $(f+g)*h=f*h+g*h$

  

  + 以及以下是三个**常用函数**
     	1. 元函数            $\varepsilon(n)=[n=1]$
     	2. 常数函数        $1(n)=1$
     	3. 恒等函数        $id(n)=n$

  

  + **常用卷积关系**（下述$\mu,1,\varepsilon$均代表上述的函数省略未知项后表达）

    1. $\sum_{d\ |\ n}\mu(d)=[n=1]\ \leftrightarrow\ \mu*1=\varepsilon$
    2. $\sum_{d\ |\  n}phi(d)=n\ \leftrightarrow\ phi*1=id$
    3. $\sum_{d\ |\ n}\mu(d)\frac{n}{d}=phi(n)\ \leftrightarrow\ \mu*id=phi$
    4. $f*\varepsilon=f$
    5. $f*1\neq f$

    

### 和式的变换规律

+ 和式的**变换规则**

  1. 分配律
     $$
     \sum_{k\in K}c\ a_k=c\sum_{k\in K}a_k
     $$
     
2. 结合律
     $$
     \sum_{k\in K}(a_k+b_k)=\sum_{k\in K}a_k+\sum_{k\in K}b_k
     $$
     
  3. 交换律（$p(k)$是指标集的任意一个排序）
$$
     \sum_{k\in K}a_k=\sum_{p(k)\in K}a_{p(k)}
$$

> 如$a_1+a_2+a_3=a_3+a_1+a_2$

+ 和式的**变换技术**

  1. 替换条件式
     $$
     \sum_{i=1}^n\sum_{j=1}^m\sum_{d|gcd(i,j)}d=\sum_{i=1}^n\sum_{j=1}^m\sum_{d=1}^n[d\ |\ i][d\ |\ j]d
     $$
     
  2. 替换指标变量
     $$
     \sum_{i=1}^n\sum_{j=1}^m[gcd(i,j)=k]=\sum_{ik=1}^n\sum_{jk=1}^m[gcd(ik,jk)=k]=\sum_{i=1}^{\frac nk}\sum_{j=1}^{\frac mk}[gcd(i,j)=1]
     $$
     
  3. 交换求和次序
     $$
     \sum_{i=1}^n\sum_{j=1}^m A(i)B(j)=\sum_{j=1}^m\sum_{i=1}^n A(i)B(j)
     $$
     
  4. 分离变量
     $$
     \sum_{i=1}^n\sum_{j=1}^mA(i)B(j)=\sum_{i=1}^n A(i)\sum_{j=1}^m B(j)
     $$
  
+ 特殊可带换规律

  1. $[gcd(i,j)=1]=\sum_{d|gcd(i,j)}\mu(d)$

     > 和上面结合可进一步推出
     > $$
     > \sum_{i=1}^n\sum_{j=1}^m[gcd(i,j)=k]=\sum_{i=1}^{\lfloor\frac nk\rfloor}\sum_{j=1}^{\lfloor\frac mk\rfloor}\sum_{d|gcd(i,j)}\mu(d)\\\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ =\sum_{i=1}^{\lfloor\frac nk\rfloor}\sum_{j=1}^{\lfloor\frac mk\rfloor}\sum_{d=1}^{\lfloor\frac nk\rfloor}[d\ |\ i][d\ |\ j]\mu(d)
     > $$
     > 

  2. $\sum_{i=1}^n [k\ |\ i]=\lfloor\frac nk \rfloor$（$k$为常数）

     > 我们可以再接着上面进一步推出
     > $$
     > \sum_{i=1}^{\lfloor\frac nk\rfloor}\sum_{j=1}^{\lfloor\frac mk\rfloor}\sum_{d=1}^{\lfloor\frac nk\rfloor}[d\ |\ i][d\ |\ j]\mu(d)=\sum_{d=1}^{\lfloor\frac nk\rfloor}\mu(d)\sum_{i=1}^{\lfloor\frac nk\rfloor}[d\ |\ i]\sum_{j=1}^{\lfloor\frac mk\rfloor}[d\ |\ j]\\\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ =\sum_{d=1}^{\lfloor\frac nk\rfloor}\mu(d)\lfloor\frac n{kd}\rfloor\lfloor\frac m{kd}\rfloor
     > $$
     > 所以$\sum_{i=1}^n\sum_{j=1}^m[gcd(i,j)=k]$就可以在化简后用两个数的整除分块得出答案



### 莫比乌斯反演

$$
f(n)=\sum_{d\ |\ n}g(d)\ \ \leftrightarrow\ \ g(n)=\sum_{d\ |\ n}\mu(d)f(\frac nd)
$$

$f(n),g(n)$均为积性函数。

$f(n)$称为$g(n)$的**莫比乌斯变换**，$g(n)$称为$f(n)$的**莫比乌斯逆变换**



## 排列组合

[排列组合](https://oi-wiki.org/math/combinatorics/combination/)

高中知识来着，其实没啥难，主要看怎么用而已……

这里摘录一些可能会不记得的东西：

 + **排列数**

   从$n$个不同的元素中，**有顺序**地选出$m$个，所有可能构成了排列数，用$A_n^m$表示
   $$
   A_n^m=n(n-1)(n-2)...(n-m+1)=\frac{n!}{(n-m)!}
   $$
   **全排列**就是$m=n$的情况

 + **组合数**

   从$n$个不同元素中，**无顺序**地选出$m$个，所有可能构成了组合数，用$C_n^m$表示
   $$
   C_n^m=\frac{A_n^m}{m!}=\frac{n!}{m!(n-m)!}
   $$
   组合数也会采用$\left(\begin{matrix}n\\m\end{matrix}\right)$表示，读作“$n$选$m$”。

   当$n<m$时，$C_n^m=0$。

以及一些补充

[抽屉原理](https://oi-wiki.org/math/combinatorics/drawer-principle/)



## lucas定理（组合数）

> 卢卡斯定理是一个与组合数有关的数论定理，用于**求组合数对某质数的模**。

通常情况下，求组合数的时候一般会给一个大质数$p$用于取模，我们只需要求逆元出来计算就可以，即$C_n^m=n!*inv(m!)*inv((n-m)!)(mod\ p)$，似乎没有lucas定理的事……

但如果题目比较狗，给的$p$不够大（比$n$小，可能$n,n-m$是$p$的倍数），我们就不能确定一定存在逆元，我们就要用lucas定理了。

+ **lucas定理**

  > 对于非负整数$n,m$以及质数$p$，$C_n^m=\prod_{i=0}^kC_{n_i}^{m_i}(mod\ p)$,$\ m=m_kp^k+...m_1p+m_0$,$\ n=n_kp^k+...n_1p+n_0$，即是$n$和$m$的$p$进制展开。

  上面很复杂，简单化简后就是：
  $$
  C_n^m=C_{n\ mod\ p}^{m\ mod\ p}\times C_{\lfloor\frac{n}{p}\rfloor}^{\lfloor\frac{m}{p}\rfloor}(mod\ p)
  $$
  来个板子

  ~~~c++
  //虽然有取模也要全部设为ll防止计算时溢出
  ll ksm(ll a,ll x){//快速幂的板子
  	ll ans=1;
  	while(x){
  		if(x&1) ans=ans*a%p;//记得这里是乘
  		a=a*a%p;
  		x>>=1; 
  	}
  	return ans;
  }
  
  ll inv(ll a){//求逆元，用费马小定理（注意题目是否说明p一定是质数）
  	return ksm(fact[a],p-2);
  }
  
  ll c(ll n,ll m){
  	return m>n?0:fact[n]*inv(m)%p*inv(n-m)%p;
      //预处理出1~n的阶乘，可以在线算逆元（有时不知道为什么存逆元会出错）
  }
  
  ll lucas(ll n,ll m){
      //m=0时结束递归，证明上一轮的m<p一定成立
  	return m==0?1:lucas(n/p,m/p)*c(n%p,m%p)%p;
      //  这部分不一定小于p，要向下递归   对p取模后一定小于p，可直接计算
  }
  ~~~

  

## 矩阵加速

当我们要求一个类似斐波那契数列的数时，可以通过矩阵来帮助我们计算。

> 直接算复杂度在$O(n)$，矩阵加速后计算复杂度在$O(\log n)$

举个例子来说明更直观：

>已知$a_n=\begin{cases}1\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ n=1,2\\a_{n-1}+a_{n-2}\ \ \ \ n\neq1,2\end{cases}$
>
>根据我们已学的线代知识，我们可以得到如下关系式：
>$$
>\left(\begin{matrix}a_{n-1}&a_{n-2}\end{matrix}\right)\left(\begin{matrix}1&1\\1&0\end{matrix}\right)=\left(\begin{matrix}a_{n}&a_{n-1}\end{matrix}\right)
>$$
>进而，我们可以推出
>$$
>\left(\begin{matrix}a_2&a_1\end{matrix}\right)\left(\begin{matrix}1&1\\1&0\end{matrix}\right)^{n-2}=\left(\begin{matrix}a_{n}&a_{n-1}\end{matrix}\right)
>$$
>所以我们可通过进行**矩阵乘法**同时用**快速幂**求矩阵的幂来$O(\log n)$求出斐波那契函数

放个板子

~~~c++
ll n, m;
struct mat {
	ll a[3][3];
}base, ans;

mat mul(mat x, mat y) {//矩阵乘法，主要看当时的矩阵大小来决定循环次数
	mat res;
	memset(res.a, 0, sizeof(res.a));
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			for (int k = 1; k <= 2; k++) {
				res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % m) % m;
			}
		}
	}
	return res;
}

void init() {//初始化，视不同的斐波那契数列而不同 
	ans.a[1][1] = ans.a[1][2] = base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
	base.a[2][2] = 0;
}

void qpow(int x) {//矩阵快速幂
	while (x) {
		if (x & 1) ans = mul(ans, base);
		base = mul(base, base);
		x >>= 1;
	}
}

void QAQ() {
	cin >> n >> m;
	init();
	if (n == 1 || n == 2) cout << "1" << endl;
	else {
		qpow(n - 2);
		cout << ans.a[1][1] << endl;
	}
}
~~~







## 高斯消元（矩阵）

> 求解线性方程组。

原理线代讲过了就不打了，放点链接好了。

[算法学习笔记(38): 高斯消元](https://zhuanlan.zhihu.com/p/139891282)

[高斯消元 - OI Wiki ](https://oi-wiki.org/math/linear-algebra/gauss/)

再来个板子

~~~c++
const db eps = 1e-6;
ll n, m;
db ans[110];

struct mat {//构造记录矩阵的结构体
	db a[110][110];
}x;

int QAQ() {
	cin >> n;
	m = n + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x.a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {//有多少个未知数就进行多少次
		int k = i;
		for (int j = i + 1; j <= n; j++) {//找当前列最大的来除减少误差
			if (fabs(x.a[k][i]) < fabs(x.a[j][i])) k = j;
		}
		if (fabs(x.a[k][i]) < eps) {
			cout << "No Solution" << endl;
			return 0;
		}
		if (k != i) swap(x.a[i], x.a[k]);
		db d = x.a[i][i];
		for (int j = i; j <= m; j++) x.a[i][j] /= d;
		for (int t = i + 1; t <= n; t++) {
			d = x.a[t][i];
			for (int p = i; p <= m; p++) {
				x.a[t][p] -= d * x.a[i][p];
			}
		}
	}
	//这里也要注意，如果方程数大于未知数个数要以未知数个数为准
	for (int i = n; i > 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			x.a[i][m] -= x.a[i][j] * x.a[j][m];
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << x.a[i][m] << " ";
	}
	cout << endl;
}

~~~





## 单调队列

> 其实很好理解啦，在上学期的课程中也有提到O(∩_∩)O

简单来讲，当我们要求某一个动态区间内的最值，我们会用到单调队列求解。

我们有一列数，我们要求出这列数中每$m$个数中的最大值（又称为**滑动窗口**）。我们的思想是，每当我们要把一个新的数加入队列时，**先检查队头**是否在当前窗口的范围内（这需要我们记录入队的时间），如果不在就不断弹出队头知道符合或为空为止；然后将当前数与队尾元素进行比较，如果比队尾元素大就弹出队尾直到小于队尾为止（在此我们维护的是一个单调递减的队列），将此元素加入队列。

在大多数情况下我们可以直接调用STL库里面的**deque**来构造单调队列，但在某些卡时间比较严的情况下就可能需要我们手写单调队列。

> 补充一个小知识
>
> 当我们只需要进行数组**头尾**的加入和删去操作，且几乎不需要访问数组中间的元素时，用**deque**
>
> 当我们需要访问数组中间的元素，且不常在数组头部加入元素时，用**vector**
>
> （vector的无头部加入删除操作）

deque的实现很简单，这里只给出需要的操作

~~~c++
#include<deque>
deque<int> q;
q.push_back(x);
q.front();
q.back();
q.pop_front();
q.pop_back();
~~~

接下来是手写单调队列的实现过程

~~~c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,a[N];

//这里采用了struct，我们也可以将编号入队然后每次对应查找
struct type{
	ll num,val;
}f[N];

void maxx(){//找区间最大值
	memset(f,0,sizeof(f));
	int front=1,back=0;//front>back时为空
	for(int i=1;i<=n;i++){
		while(front<=back&&f[front].num+m-1<i) front++;
		while(front<=back&&f[back].val<=a[i]) back--;
		back++;//因为找到的是第一个比当前大的，我们要插在它的后面
		f[back].num=i;
		f[back].val=a[i];
		if(i>=m) printf("%d ",f[front].val);
	}
	printf("\n");
}

int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	maxx();	
	return 0;
}
~~~



## 单调栈

当我们要处理某个数在当前数组内离它最近且比它大的元素时，我们会用单调栈。

顾名思义，这是个用栈来维护的数据结构。我们每次将当前元素与**栈顶元素**进行比较（基于栈的先进后出的性质，栈顶的元素一定离当前元素最近），如果栈顶元素比当前元素小，我们就把栈顶元素出栈，直到找到第一个大于当前元素的，就可以得到**离当前元素最近且比它大的元素的位置**，若栈为空，我们将此位置设置为0或n+1（根据当前是从前往后还是从后往前扫），然后将当前元素入栈。

常见的单调栈有两种不同的思路来维护，下面给出的是我们上面提到的方法。

~~~c++
stack<int> q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //求左边第一个≥当前元素的元素位置
	for(int i=1;i<=n;i++){
		while(q.size()&&a[q.top()]<a[i]) q.pop();
		if(q.size()) maxx[i]=q.top();
		else maxx[i]=0;
		q.push(i);
	}
	while(q.size()) q.pop();
    //求右边第一个≤当前元素的元素位置
	for(int i=n;i>0;i--){//注意这里是反着扫的
		while(q.size()&&a[q.top()]>a[i]) q.pop();
		if(q.size()) minn[i]=q.top();
		else minn[i]=n+1;//因为是反正扫所以置为n+1
		q.push(i);
	}
    return 0;
}
~~~



## 二叉堆

> 堆是我们常见的数据结构，我们在上面提到的单调栈就是用STL里的堆来维护的。

STL里还有另一个数据结构叫做**priority_queue**优先队列，这个数据结构也很常用，它的本质就是一个二叉堆虽然在绝大多数情况下我们直接调用STL库里的就可以解决问题，但dalao云

> 使用手写的二叉堆，会比`STL`提供的`priority_queue`快一些。此外，了解其原理也有助于理解一些更高级的数据结构。

所以我们还是要在这里整理下手写二叉堆的方法。

先放个链接——[算法学习笔记(47): 二叉堆 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/187618450)

> 以下以小根堆为例

 + 基本操作

   1. **上浮（swim）**

      我们取某个节点上浮，即将此节点与它的**父节点(x>>1)**做比较，如果此节点小于父节点，则将此节点与父节点交换，直到不再小于或为根节点为止。

   2. **下沉（sink）**

      将当前节点与它的左右儿子节点中**较小**的那个作比较，如果大于则将当前节点与较小的那个节点交换，直到为根节点或不再大于为止。这里注意除了判断当前节点是否大于size以外还要判断当前节点比较的**左右儿子节点是否大于size**。

 + 具体应用

   1. 建堆 / 插入

      每次加入新的元素时将新加入的元素放在最末尾（当前size+1的位置），令当前**size++**后对新加入的节点进行**swim**操作。

   2. 删除

      出于二叉堆的性质，我们删除的一定是**堆顶的元素**。删除时将堆顶元素与最末尾的元素交换后**size--**，然后对交换到堆顶的元素进行**sink**操作。

   3. 查询

      直接返回根节点元素即可。

~~~c++
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,heap[N<<1],size;

void swim(int x){
	while(x>1&&heap[x]<heap[x>>1]){
		swap(heap[x],heap[x>>1]);
		x>>=1;
	}
}

void sink(int x){
	while(((x<<1)<=size&&heap[x]>heap[x<<1])||((x<<1|1)<=size&&heap[x]>heap[x<<1|1])){
		if((x<<1|1)>size||heap[x<<1]<heap[x<<1|1]){
			swap(heap[x],heap[x<<1]);
			x=(x<<1);
		}
		else{
			swap(heap[x],heap[x<<1|1]);
			x=(x<<1|1); 
		}
	}
}

int main(){
	scanf("%d",&n);
	while(n--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x;
			scanf("%d",&x);
			heap[++size]=x;
			swim(size);
		} 
		else if(op==2){
			printf("%d\n",heap[1]);
		}
		else if(op==3){
			swap(heap[1],heap[size]);
			size--;
			sink(1);
		}
		
	}
	return 0;
} 
~~~



## 并查集

顾名思义，并查集就是我们用来**维护集合信息**的一个数据结构，包括了**合并两个集合**和**询问是否在同一个集合里**的两个操作。

最朴素的并查集操作非常简单，我们在之前的训练中基本已经掌握，在此就不再过多赘述。

出于各种性质，最朴素的并查集在复杂情况下复杂度会直线飙升，这时候我们就需要用到**路径压缩**。

在此简单记录一下路径压缩的方法。

~~~c++
int find(int x){
return fa[x]==x?x:fa[x]=find(fa[x]);
}

void hb(int a,int b){
    fa[find(a)]=fa[find(b)];
}
~~~



种类并查集是一种并查集的特殊思想好像也没有什么好总结的，我们在种类并查集里要维护的信息是类似于**敌人的敌人是朋友**。最经典的题目就是[关押罪犯](https://www.luogu.com.cn/problem/P1525)。在这里就丢个链接好了（……）

[算法学习笔记(7)：种类并查集 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/97813717)



## ST表(RMQ)

[算法学习笔记(12): ST表 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/105439034)

**ST表**（Sparse Table，**稀疏表**）是一种简单的数据结构，主要用来解决**RMQ**（Range Maximum/Minimum Query，**区间最大/最小值查询**）问题。它主要应用**倍增**的思想，可以实现 $O(n\ logn)$预处理、$O(1)$查询。

在此简单地丢个模板

~~~c++
vv #include<bits/stdc++.h>
using namespace std;
#define N 100100
int n,m,st[N][40]; 

void solve(){
	int len=log2(n);
	for(int j=1;j<=len;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
            //注意这里j要取上一层，i和i+(1<<j-1)
		} 
	} 
}

int query(int x,int y){
	int l=log2(y-x+1);//计算最大区间长度以保证能全覆盖
	return max(st[x][l],st[y-(1<<l)+1][l]);
    //询问的时候是找同一层（因为是RMQ所以区间重叠不影响最后结果）
    //然后分别从头和从尾开始查询
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>st[i][0];
	}
	solve();
	while(m--){
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<"\n";
	}
	
	return 0;
}
~~~



## 树状数组

[从0到inf，超详细的树状数组详解](https://www.luogu.com.cn/blog/kingxbz/shu-zhuang-shuo-zu-zong-ru-men-dao-ru-fen)

[算法学习笔记(2) : 树状数组 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/93795692)

最基本的操作，**单点修改**和**区间查询**。

```c++
int lowbit(int x){
	return x&-x;
}
```

当然，这只是树状数组最基本的操作。

树状数组还有个我们常见的操作就是求逆序对。

其他的可以看看第一个链接的内容，我们以后再作补充





## 线段树

> 据说是竞赛很常用的算法，但我还是个菜鸡所以学了再说吧。

线段树在了解原理之后就变得相当简单（当然我在这里说的不包括它的各种各样奇妙的变种）

它的组成如下：

	1. 最基本的struct：记录区间l、r，区间维护的值v，区间懒标记lazy
	1. pushup  将当前节点的子节点的变化传递到当前节点
	1. pushdown(通常与懒标记配合使用)  将当前节点的懒标记向下传递，对下一层的值和懒标记做出改变。

通过对上述提到的操作的综合应用我们就可以建出线段树啦！

修改和查询的思路差不多，我们在这里就一起讲了

> 假设我们现在要进行操作的区间是l，r，我们从1开始向下查找，如果当前查找到的区间**在[l，r]内**，我们就直接进行操作，并return；否则我们找到当前区间的mid，如果**l≤mid**，我们就向下查询它的左儿子，如果**r＞mid**，我们就向下查询它的右儿子。

注意：每次递归回溯后都要pushup，每次向下递归前都要pushdown



在此我们再额外记录一些常见的线段树变形：

 1. 同时对区间进行**加**和**乘**的操作

    ​	我们的基本思想其实还是维护懒标记，但问题在于我们要如何去维护这个懒标记。首先我们很明显可以看出，只维护一个懒标记是肯定不可以的，我们要**分别维护乘法和加法的懒标记**。我们再手写模拟一下就又会发现，加法的懒标记对乘法没有影响，但乘法的懒标记对加法会造成影响，即在加法懒标记存在的情况下，我们后面每一次乘法懒标记都会使加法懒标记同时乘上这个数。

    ​	简单来说，在pushdown的时候，先处理乘法，分别对mul，sum，add都操作，然后在处理加法，对sum和add操作。

    ​	注意在这里加法懒标记初始化为0，乘法懒标记初始化为1 。

 2. 进行区间mod一个数的运算

    ​	由于mod的性质不能积累，当我们要对区间取mod时需要一直查询到底，但很明显这样的方法无法满足我们对于复杂度的要求，我们又可以根据mod的性质，记录区间中最大值max，如果max＜当前要mod的数，那么接下来每一次对它的子区间取mod都不会有任何改变。

 3. 最大子段和

    ​	如果是求最大子段和，我们就记录当前区间的ans，从左开始的lans和从右开始的rans：

    ```c++
    #include<bits/stdc++.h>
    using namespace std;
    #define ls u<<1
    #define rs u<<1|1
    #define N 50010
    int n,m,a[N];
    struct type{
    	int lans,rans,ans,sum;
    }tr[N<<2];
    
    void pushup(int u){
    	type L=tr[ls],R=tr[rs];
    	tr[u].sum=L.sum+R.sum;
    	tr[u].lans=max(L.lans,L.sum+R.lans);
    	tr[u].rans=max(R.rans,R.sum+L.rans);
    	tr[u].ans=max(max(L.ans,R.ans),L.rans+R.lans);
    }
    
    void build(int u,int l,int r){
    	if(l==r){
    		tr[u].ans=tr[u].lans=tr[u].rans=tr[u].sum=a[l];
    		return;
    	}
    	int mid=l+r>>1;
    	build(ls,l,mid);
    	build(rs,mid+1,r);
    	pushup(u);
    }
    
    void add(int x,int u,int l,int r,int y){
    	if(l==r){
    		tr[u].ans=tr[u].lans=tr[u].rans=tr[u].sum=y;
    		return ;
    	}
    	int mid=l+r>>1;
    	if(x<=mid) add(x,ls,l,mid,y);
    	else add(x,rs,mid+1,r,y);
    	pushup(u); 
    }
    
    type query(int x,int y,int u,int l,int r){
    	if(x<=l&&y>=r){
    		return tr[u];
    	}
    	int mid=l+r>>1;
    	if(y<=mid) return query(x,y,ls,l,mid);
    	if(x>mid) return query(x,y,rs,mid+1,r);
    	type p,L=query(x,mid,ls,l,mid),R=query(mid+1,y,rs,mid+1,r);
    	p.sum=L.sum+R.sum;
    	p.lans=max(L.lans,L.sum+R.lans);
    	p.rans=max(R.rans,R.sum+L.rans);
    	p.ans=max(max(R.ans,L.ans),L.rans+R.lans);
    	return p; 
    }
    
    
    int main(){
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++){
    		scanf("%d",&a[i]);
    	}
    	build(1,1,n);
    	scanf("%d",&m);
    	while(m--){
    		int flag=0,x,y;
    		scanf("%d%d%d",&flag,&x,&y);
    		if(flag){
    			printf("%d\n",query(x,y,1,1,n).ans);
    		}
    		else{
    			add(x,1,1,n,y);
    		}
    	}
    	
    	return 0;
    }
    ```




## 最短路算法

![](https://images.cnblogs.com/cnblogs_com/blogs/788608/galleries/2324904/o_230709055353_%E6%9C%80%E7%9F%AD%E8%B7%AF.jpg)

### Dijkstra

​	适用范围：无负权边

```c++
#include<bits/stdc++.h>
using namespace std;
#define N 100100
#define M 200100
#define INFF 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
typedef long long ll;
map<int,int> mp[N];//检查重边
set<pii> edges[M];//存边
ll dis[N];
int n,m,s;
bool state[N];

//边数不多的时候直接用邻接矩阵存图就可以了

void addedge(int u,int v,int w){
	if(!mp[u].count(v)){//查找是否有重边
        //没有就直接加入
		mp[u][v]=w;
		edges[u].insert({v,w});
	}
	else{
		if(mp[u][v]>w){//有重边就比较，选择小的那条边加入
			edges[u].erase({v,mp[u][v]});
			mp[u][v]=w;
			edges[u].insert({v,w});
		} 
	}
}

void init(){
    //初识化距离为无穷
	for(int i=1;i<=n;i++){
		dis[i]=INFF;
		state[i]=false;
	}
}

void dijkstra(int p){
    //用堆优化后的版本
	init();
    //p为起点
	dis[p]=0;
    //小根堆
	priority_queue<pii,vector<pii>,greater<pii>> heap;
	heap.push({0,p});//比较的时候默认以pair前面的数为优先级，我们要找到的是当前到起点距离最短的边，所以要先输入距离
	while(!heap.empty()){
		int d,u,v,w;
		tie(d,u)=heap.top();
        //首元素就是距离最短的点
		heap.pop();
		if(state[u]) continue;
		state[u]=true;
		for(auto it:edges[u]){
            //遍历当前点的所有子节点
			tie(v,w)=it;
			if(dis[v]>d+w){
                //如果距离更小就记录并入堆
				dis[v]=d+w;
				heap.push({d+w,v});
			}
		}		
	}
}

//当非常稠密的时候尽量使用朴素版的Dijkstra
void dijkstra(int p){
	init();
	dis[p]=0;
	for(int i=1;i<=n-1;i++){
		int t=-1;
		for(int j=1;j<=n;j++){
			if(!state[j]&&(t==-1||dis[t]>dis[j])){
				t=j;
			}
		}
		state[t]=true;
		
		for(auto it:edges[t]){
			int v,w;
			tie(v,w)=it;
			dis[v]=min(dis[v],dis[t]+w);
		} 
	}
}

void QAQ(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	dijkstra(s);
	for(int i=1;i<=n;i++){
		if(dis[i]==INFF){
			cout<<(int)pow(2,31)-1<<" ";
			continue;
		}
		cout<<dis[i]<<" ";
	} 
	return ;
} 
```



### Bellman-Ford

> 当对**走过边的个数**有要求或者是求是否存在**负权回路**

最多还是用于有边数限制的最短路问题啦

细节在代码里

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,dis[N],tmp[N];

//因为只需要记录有什么边每次都要遍历全部，所以直接存就可以了
struct type{
	int u,v,w;
}edge[N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
	dis[1]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	while(k--){//这个k的遍历次数相当于走了多少条边
		memcpy(tmp,dis,sizeof(dis));
        //防止本次遍历时的更新影响到后续更新
		for(int i=1;i<=m;i++){
			int u=edge[i].u,v=edge[i].v,w=edge[i].w;
			dis[v]=min(dis[v],tmp[u]+w);//要注意用哪个数组捏
		}
	}
	if(dis[n]>=0x3f3f3f3f/2) printf("impossible");
    //这里不能直接判断相等，是因为存在负权边
	else printf("%d",dis[n]);
	return 0;
} 
```







### SPFA

用queue优化的Bellman-Ford算法，简单来讲就是**只有在之前被更新过的节点才会更新其他节点**，所以我们用queue来记录之前更新的节点。

><u>SLF优化SPFA</u>
>
>每次将**入队结点距离和队首比较**，如果比队首大超过一定值则插入至队尾

```c++
#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define M 500010
#define INF 0x3f3f3f3f
int n,m,s,dis[N],cnt[N];
//cnt数组记录当前路径经过点的个数，当某个点的cnt≥n的时候证明存在负权环
struct type{
	int v,w;
}; 
vector<type> edges[M];

void spfa(int s){
	queue<int> q;
	bool state[N];//记录当前点是否在队列中，防止重复入队增加时间
	memset(dis,INF,sizeof(dis));
	memset(state,false,sizeof(state));
	q.push(s);
	dis[s]=0;
	state[s]=true;
	while(q.size()){
		int u=q.front();
		q.pop();
		state[u]=false;
		for(auto x:edges[u]){
			int v=x.v,w=x.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				cnt[v]=cnt[u]+1;
				if(!state[v]){
					state[v]=true;
					//q.push(v);
                    //SLF优化SPFA，使用deque
                    if(!q.empty() && dis[v] > dis[q.front()]){
						//和队头元素进行比较
						q.push_back(v);
					}
					else q.push_front(v);
				}
			}
		}
		
	}
}

int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges[u].push_back({v,w});
	}
	spfa(s);
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	
	return 0;
}
```

注意，如果用SPFA来判断负环的话，我们可以**不用初始化距离**，增加cnt数组，并在**一开始把所有节点入队**。



### Floyd

> 基于DP的多源最短路算法

```c++
const int inf = 0x3f3f3f3f;
int n, m, q, mp[N][N];

void Floyd() {
	//先枚举断点，再枚举两端
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
			}
		}
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			 //初始化两点间距离为无穷大，到自己的距离为0
			if (i != j) mp[i][j] = inf;
			else mp[i][j] = 0;
		}
	}
}

void QAQ() {
	cin >> n >> m >> q;
	init();
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		mp[u][v] = min(mp[u][v], w);
		//避免重边造成影响
	}
	while (q--) {
		int u, v;
		cin << u << v;
		if (mp[u][v] >= inf / 2) printf("impossible\n");
		//取无穷的一半防止遍历的过程中的误差
		else cout >> mp[u][v] >> endl;
	}
}

```



## 最小生成树MST

### Prim

**稠密图**

暴力$O(n^2 + m)$

```c++
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N = 510;
const int M = 1e5+10;
int n,m,a[N][N],dis[N];//邻接矩阵存图
bool vis[N];

int prim(){
	memset(dis,0x3f,sizeof(dis));
	int res=0;
	for(int i=0;i<n;i++){
		int u=-1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(u==-1||dis[u]>dis[j])) u=j;
		}
		vis[u]=true;
		if(i&&dis[u]==inf) return inf;//有点与其他不连通
		if(i) res+=dis[u];
		for(int j=1;j<=n;j++) dis[j]=min(dis[j],a[u][j]);
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		a[x][y]=a[y][x]=min(w,a[x][y]);
	}
	int t=prim();
	if(t==inf) printf("impossible");
	else printf("%d",t); 
	return 0; 
}
```



### Kruskal

$O(m\ logm)$

稀疏图

> 使用**并查集**维护点与点之间的联通关系，每次选择当前**边权最小**且**暂未联通**的两个点加入集合

```c++
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N = 1e5+10;
const int M = 2e5+10;
int n,m,fa[N];
bool vis[N];

struct type{
	int u,v,w;
}e[M];

bool cmp(type a,type b){
	return a.w<b.w;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	int k=1,cnt=1,res=0;
	while(k<=m){
		int a=e[k].u,b=e[k].v;
		if(find(a)!=find(b)){
			cnt++;
			fa[find(a)]=find(b);
			res+=e[k].w;
		}
		k++;
	}
	if(cnt==n) return res;
	else return inf;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+1+m,cmp);
	int t=kruskal();
	if(t==inf) printf("impossible");
	else printf("%d",t);
	return 0;
}
```



## 最近公共祖先LAC

```c++
#include<bits/stdc++.h>
using namespace std;
#define N 500100
#define M 500100

int n,m,h;
int head[N],dep[N];
struct type{
	int nxt,to;
	void in(int a,int b){
		nxt=a;to=b;
	}
}a[M*2];

int read(){
	int i=0,j=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') j=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		i=i*10+ch-'0';
		ch=getchar();
	}
	return i*j;
}

int depp=-0x3f3f3f3f;
int tree[22][N]; 
void dfs(int x){
	int s=head[x];
	while(s){
		if(tree[0][a[s].to]){
			s=a[s].nxt;
			continue;
		}
		tree[0][a[s].to]=x;
		dep[a[s].to]=dep[x]+1;
		depp=max(depp,dep[a[s].to]);
		father(a[s].to);
		s=a[s].nxt;
	}
}

int LAC(int x,int y){
	if(dep[x]<dep[y]){
		int tmp=x;
		x=y;
		y=tmp; 
	}
	//默认depx>=depy 
	while(dep[x]>dep[y]){
		x=tree[(int)log2(dep[x]-dep[y])][x];
	}
	if(x==y) return x;
	for(int i=log2(dep[x]);i>=0;i--){
		if(tree[i][x]!=tree[i][y]){
			x=tree[i][x];
			y=tree[i][y];
		}
	} 
	return tree[0][x];
}

int main(){
	n=read(),m=read(),h=read();
	for(int i=1;i<=(n-1)*2;i+=2){
		int u=read(),v=read();
		a[i].in(head[u],v);
		head[u]=i;
		a[i+1].in(head[v],u);
		head[v]=i+1;
	}
	tree[0][h]=h;
	dep[h]=1;
	dfs(h);
	int lay=log2(depp);
	for(int i=1;i<=lay;i++){//处理数据 
		for(int j=1;j<=n;j++){
			tree[i][j]=tree[i-1][tree[i-1][j]];
		}
	}
	for(int i=0;i<m;i++){
		int x=read(),y=read(); 
		printf("%d\n",LAC(x,y));
	}
	
	return 0;
}
```

