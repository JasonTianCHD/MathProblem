/*背景： 在一个娱乐节目上，主持人提供三扇门（假设A,B,C），只有一扇门后面有一辆汽车，另外两扇门都是纪念奖。
主持人知道哪扇门后面有汽车。首先，当你选择一扇门之后，主持人会把剩下的两扇门中的一扇没有汽车的门打开，现
在你有一次重新选择门的机会，你应该选择换还是不换？不换得到汽车的概率是多少？ 换得到汽车的概率是多少？

解答：
方法1：直观理解
你选择一扇门，选中汽车的概率是1/3，没有选中的概率是2/3. 也就是说汽车在剩下两扇门的概率是2/3，主持人打开
了一个没有汽车的门，这个时候2/3的概率都转移到没有打开的那扇门了，所以应该选择换。
 
方法2：计算中奖概率
不换中奖的概率：1/3*1（第一次就选对）+2/3*0（第一次没选对）=1/3
换中奖的概率：1/3*0(第一次就选对，换)+2/3*1(第一次没选对，换)=2/3
2/3>1/3 所以选择换。

code：   */
#include<iostream>

using namespace std;

void main(){
	int n = 3, count = 0, total = 100000, Lefted;
	bool change = true;//选择换

	for (int i = 0; i < total; i++){
		int Car = 1 + rand() % 3;//产生1-3的随机数
		int MyChoose = 1 + rand() % 3;
		if (MyChoose == Car)
			Lefted = 1+(Car + 1) % 3;//因为第一次选对了，剩下两个都没车，所以随便留一个
		else
			Lefted = Car;//如果第一次没选对，则去掉一个非中奖，只剩下车所在的门了
		if (change){
			MyChoose = Lefted;
			count = (MyChoose == Car) ? count + 1 : count;
		}
	}
	cout << "选择换，选中汽车的概率是" << (double)count/total << endl;
	system("pause"); 
}
//实验100000次迭代，最后选择换，选中汽车的概率是：0.6666=2/3 
