# C++ Primer Plus 习题

## 第2章

### 2.6

1. 函数
2. 包含iostream头文件，将头文件添加到源代码中
3. using是预编译指令，使用std命名空间
4. `cout<<"Hello,world"<<endl;`
5. `int cheeses;`
6. `cheeses=32;`
7. `cin>>chesses;`
8. `cout<<"We have "<<chesses<<" varieties of cheese."<<endl;`
9. + 函数名 froop 返回值int 参数为double
   + 函数名rettle 参数为int 无返回值
   + 函数名prune 无参 返回值为int
10. 无返回值时，即void型
11. 命名空间
    + 全局使用`using spacename std;`
    + 函数内使用`using spacename std`
    + cout更改为`std::cout`

### 2.7

编程练习见github仓库pratice/unit2

## 第3章

### 3.6

1. int、short、long、longlong、char、unsigned、signed有10种类型，主要是根据实际数据运算需要来进行匹配应用
2. + `short a = 80;`
   + `unsigned int b = 42110;`
   + `unsigned int c = 3000000000;`或者`long/long long`类型，却保数据不会溢出
3. C++没有提供自动防止数据溢出的功能，只能由程序员决定，具体每种类型的长度，取决于编译平台
4. 33L是long型数据，33默认是int型
5. 基于ASCII码平台时是一致的：
   + char grade = 65；先存储为int型65，再强转为char型‘A’，
   + char grade = ‘A’；，直接将字符A存储进去
6. + `char a = 88;`
   + `(char)88;`
   + `char(88);`对应cout输出即可
7. 若long型为4字节，不会出现舍入误差，若long long为8字节，会出现舍入误差，double存储的有效位只有52位，存放64bit的long会溢出
8. `74;4;0;4.5;3;	`
9. + `int sum = (int)x1 + (int)x2;`
   + `int sum = (int)(x1 + x2);`
10. + `int`
    + `float`
    + `char`
    + `char32_t`
    + `float`

### 3.7

编程练习见github仓库pratice/unit3

+ 在第2题中，曾出现错误，原因：
  + 变量类型问题：结合实际进行分配，double weight，height等

+ 第3题中，出现错误，原因：
  + 变量未定义
  + 拼写出错
  + 变量类型出错：将double写为int，导致输出强制变为整形
  + 程序运算符出错：/写为*

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221105105650.png)

## 第4章

### 4.12

1. `char actor[30];short betsie[100];float chuck[13];long double dipsea[64];`

2. `array<char,30> actor; array<short,100> betsie;array<float,13> chuck;array<long double,64> dipsea;`

3. `int a[5]={1,3,5,7,9};`

4. `even=a[0]+a[4];`

5. `cout<<ideas[1]<<endl;`

6. `char test[]={"cheeseburger"};`

7. `string str1 = {"Waldorf Salad"};`

8. ```c++
   struct fish_sort
   {
       char name[20];
       int weight;
       double length;
   };
   ```

9. `fish_sort f1={"caoyu",20,23.10};`

10. ```c++
    enum Response
    {
        YES=1,
        NO=0,
        Maybe=2
    };
    ```

11. ```c++
    double ted;double* pted=&ted;cout<<*pted<<endl; 
    ```

12. ```c++
    float treacle[10];
    float* pt=&treacle[0];
    cout<<*pt<<" / "<<*(pt+strlen(treacle)-1)<<endl;
    //strlen计算元素个数，但是角标与个数差1，记得减去
    ```

13. ```c++
    int n;
    cin>>n;
    int *pa = new int [n];
    delete [] pa;
    vector<int> pa(n);
    ```

14. 有效，将打印字符串的首地址

15. ```c++
    //假设8已经定义
    fish_sort* pf1 = new fish_sort;
    cin.getline(pf1->name,20);
    cin>>pf1->weight;
    ```

16. 当输入的值出现空白符时将阶段赋值，剩下的将留在缓冲区，类似于cin.get（）会造成空白行

17. ```c++
    #include<iostream>
    #include<vector>
    #include<array>
    const int COUNT = 10;
    vector<string> str1(COUNT);
    array<string,COUNT>str2;
    ```

### 4.13

见github仓库 ./pratice/unit4

注意第9题，使用new动态分配结构体数组时，与分配数组类似,因为结构体就相当于自定义一个类。

`CandyBar *arr = new CandyBar [3];`

## 第5章

### 5.8

1. 入口是在进入循环时进行判定，而出口则是执行完循环体再判定，for和while属于入口条件循环，do..while属于出口

2. 打印01234换行

3. 打印11内3的倍数，换行打印12

4. 68，程序rv4.cpp，4.1.1比较也有说明，关系运算符优先级比算数低

5. 8，只执行一次

6. 见rv6.cpp

7. 使用{}

8. 有效，int x赋值8进制024，y=1，验证见rv8.cpp

   `std::cout<<std::oct<<x<<'\n';`转换为8进制输出

9. 三者均是读取一个字符，但是cin>>ch会跳过空白符，cin.get（ch）单参数调用返回一个cin对象，可以开火车，而ch=cin.get（）；可以读取一个字符并回送给ch，不能开火车

   另一方面，读到文件尾EOF时，cin.get（ch）返回cin对象，bool类型为false，而ch=cin.get（）将不会得到任何值

### 5.9

编程练习见github仓库pratice/unit5

2. ```c++
   #include<iostream>
   #include<array>
   int main(void)
   {
           using namespace std;
           array<long double,101> fi;
           fi[0]=1,fi[1]=1;
           for(int i = 2;i < 101;i++)
                   fi[i]=i*fi[i-1];
           cout<<fi[3]<<endl;
           return 0;
   }//array与数组的使用完全相同
   ```

仅做了几道练习熟悉语法

## 第6章

### 6.10

1. 对于version1，无论结果如何，ch都将判断两次，而version2在非空格的适合才判断是否为回车，效率更高

2.  

3. H$i$!$ $S$e$n$d$ $

   ct1=9,ct2=9

   曾出错，错误原因，while判断条件写为`ch = cin.get() != '$'`，结果不会输出字符，**算数运算>关系运算符>逻辑运算符>赋值运算，因此ch的值必然为0或1，输出出错**