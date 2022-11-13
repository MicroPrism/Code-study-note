#  C++ study note

## 0.参考教材

C++ Primer Plus(第6版中文版)

## 1.基础内容

### 1.1 C++创建

命令：`nano name.cpp`，创建/打开name为名称的cpp文件，ctrl+x，退出保存

命令：`g++ name.cpp`，编译文件，生成a.out文件

命令：`./a.out`，执行当前文件夹下的a.out文件

```c++
//一段标准c++框架
int main(void)//括号内void建议加
{
        return 0;//省略时默认return 0
}
//main（）被启动代码调用，启动代码是由编译器加入到main中的，比如a.out文件里就包括启动代码与代码
//对于PC动态链接库与STM32单片机程序，没有main也可以
```

### 1.2 一些说明

+ 注释：//：C++风格   /* */，C风格可以块注释

+ iostream：使用cout与cin进行输入输出
+ 头文件名：C++头文件不含.h，旧的C包含.h

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221102115801.png)

+ 名称空间：不同厂商开发的类库可能有同名函数，而命名空间可以作为限定词进行区分。

  `std::cout<<...`即命名空间std中的cout，开始时`using namespace std`，相当于std命名空间函数都可以使用。

  `using std ::cout;`,声明std命名空间单个命令。

+ 重载：一个字符具有多个不同意义，具体意义需要结合上下文，例如`&、*`,均与多个含义，`<<、>>`在c++中也有移位与流入的意义。

### 1.3 输出

`cout<<"...";`将字符串(..)插入(<<)到输出流(cout)当中.

`cout<<"c++ study.";`输出如下，没有换行。

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221102121523.png)

改进：`cout<<"c++ study."<<endl;`

控制符：endl，当前语句结束后另起一行，功能类似于C中的'\n'换行符，并且'\n'也可以在c++中使用，但是还是建议使用endl。

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221102122100.png)

### 1.4 C++变量

创建变量类似与c，不过略有一点区别，C++只需要在首次使用前定义，而C需要在函数最开始，不变的是必须要定义。

```c++
#include <iostream>
int main(void)
{
        using namespace std;
        int carrots;
        carrots=25;
        cout<<"i have "<<carrots<<endl;
        return 0;//end of program
}
//在内存存放时，存放的为25，但是打印时会转换为字符2与字符5打印
```

相对于C语言的printf函数，显然cout不需要再说明其格式`%s、%d...`，更加准确。

### 1.5 输入 cin

` cin>>carrots;`，此语句便将键盘输入的命令发送至变量carrots。

```C++
#include <iostream>
int main(void)
{
        using namespace std;
        int carrots;
        cout<<"how many carrots do you have. "<<endl;
        cin>>carrots;
        carrots=carrots - 1;
        cout<<"Now carrots = "<<carrots<<" ."<<endl;
        return 0;//end of program
}
//此段代码即实现对象赋值及cout拼接
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221102162502.png)

### 1.6 类简介

类是用户自定义的类型，用户可以自定义自己的类库。

类是一些抽象特性的集合，而基于这些特性，就形成了对象，即实体。而类又指定了对象可对类执行的所有操作。

### 1.7 函数

函数包括有/无返回值的，其与C语言完全相同。

C++程序应为程序中使用的每个函数提供原型，即返回值，形参都应已知。

`double sqrt(double);`就声明了一个sqrt函数。

**函数头**：定义一段函数的开始，后面加{}，不加；

```C
int main()//函数头
{
    ...
}
double sqrt();//声明
x=sqrt(y);//原型
```

**函数原型/声明**：尾接分号；，告诉编译器是什么函数。

提供原型的方法：

1. 源代码中输入函数模型
2. 包含头文件，其中定义了函数原型

```c++
//调用库函数sqrt
#include <iostream>
#include <cmath>
int main(void)
{
        using namespace std;
        double area;
        cout<<"how many area  do you room. "<<endl;
        cin>>area;
        double size = sqrt(area);
        cout<<"the equal size is "<<size<<" ."<<endl;
        return 0;//end of program
}
```

```c++
//自定义函数Simon
#include <iostream>
void Simon(int);//原型声明
int main()
{
        using namespace std;
        cout<<"plz a number"<<endl;
        int count;
        cin>>count;
        Simon(count);//函数调用
        return 0;
}
void Simon(int n)//函数头
{
        using namespace std;
        cout<<"Touch your toes "<< n <<endl;
}
```

一般来说，return 0表示函数运行成功，而-1等其他值表示运行失败。

对于自定义函数，是否命名空间语句方法很多，无论是定义成全局形式，还是在函数内部，甚至说直接使用`std::cout`，都是可以的，只要搞清楚作用范围即可。

## 2.处理数据

### 2.1 变量

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221102204239.png)

同C，sizeof是操作符而非函数，有如下一段程序。

```c++
#include<iostream>
#include<climits>

int main(void)
{
        using namespace std;
        int n_int=INT_MAX;
        short n_short=SHRT_MAX;
        long n_long=LONG_MAX;
        long long n_llong=LLONG_MAX;

        cout<<"int is "<<sizeof(int)<<"bytes"<<endl;
        cout<<"short is "<<sizeof n_short<<"bytes"<<endl;
        cout<<"long is "<<sizeof n_long <<"bytes"<<endl;
        cout<<"long long is "<<sizeof n_llong<<"bytes"<<endl;
        cout<<"MAXimum values "<<endl;
        cout<<"int:"<<n_int<<endl;
        cout<<"short:"<<n_short<<endl;
        cout<<"long:"<<n_long<<endl;

        cout<<"int is "<<sizeof(int)<<"bytes"<<endl;
        cout<<"short is "<<sizeof n_short<<"bytes"<<endl;
        cout<<"long is "<<sizeof n_long <<"bytes"<<endl;
        cout<<"long long is "<<sizeof n_llong<<"bytes"<<endl;
        cout<<"MAXimum values "<<endl;
        cout<<"int:"<<n_int<<endl;
        cout<<"short:"<<n_short<<endl;
        cout<<"long:"<<n_long<<endl;
        cout<<"long long:"<<n_llong<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221102212337.png)

C++变量几种赋值方式：

1. 等号赋值：`int a=10；`
2. 括号赋值：`int a(10);`，面向对象赋值
3. 花括号赋值：`int a={10};`或者省略等号`int a{10};`，大括号内部无值时，将被初始化为0

2、3两种赋值方式并不常见，但是确实是合理的。

### 2.2  无符号变量

`unsigned`修饰，完全同c。例如unsigned short最大为65535.使用时需要确保会不会导致溢出

<img src="https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221103111140.png" style="zoom: 80%;" />

```C++
#include<iostream>
#include<climits>
int main(void)
{
        using namespace std;
        short sam=SHRT_MAX;
        unsigned short sue=sam;
        cout<<"sam is "<<sam<<" sue is "<<sue<<endl;
        sam+=1;
        sue+=1;
        cout<<"sam is "<<sam<<" sue is "<<sue<<endl;
        sam=0;
        sue=0;
        sam-=1;
        sue-=1;
        cout<<sam<<"/"<<sue<<endl;
        return 0;
}
//sam is 32767 sue is 32767
//sam is -32768 sue is 32768
//-1/65535
```

对于数据的选择，对计算机来说，int是最优的，而据实际数据的正负可以选择是否需要无符号型。变量可能出现的数如果大于16位，需要使用long，防止程序在从32位（32位int）移植到16位（16位int）系统时截断导致出现问题。

C++变量的输出：

C++中，无论变量定义时如何，其输出都将默认以10进制进行输出，除非是使用控制字`dec、hex、oct`进行修改。

```C++
#include<iostream>
int main(void)
{
        using namespace std;
        int a=42;
        int b=042;
        int c=0x42;
        cout<<a<<" / "<<b<<" / "<<c<<" / "<<endl;
        cout<<dec<<a<<" / ";
        cout<<oct<<b<<" / ";
        cout<<hex<<c<<endl;
        return 0;
}
//42 / 34 / 66 / 
//42 / 42 / 42
```

控制符`dec、hex、oct`也位于std中，因此不能使用其作为变量名，其本质相当于一条转变形式的消息。

### 2.3 常量存储与后缀

如果在定义变量时声明了变量类型，会按声明的类型存储，如果没有声明，那么会默认按照相应的大小分配变量，例如65535可以是int，而65536会默认为long，**如果想要指定存储格式，可以添加后缀**。

+ U：unsigned
+ L：long
+ LL：long long

对于以上三种后缀可以相互组合，例如6553ul、4399LL分别以无符号长整形储存6553、longlong型存储4399，原则上，后缀的大小顺序不影响结果，但是，l和1太过相似，建议大写。

**存储**：

对于数据的存储，数字非常容易理解，就是二进制（bin）而已，而对于字符，则需要列写字符表，1byte=8bit足以包括大部分字符，因此char应运而生。

对于一些大型项目，也许是EBCDIC编码，也许是Unicode编码。

```c++
#include <iostream>
int main(void)
{
        using namespace std;
        char ch;
        cout<<"plz input a number : "<<endl;
        cin>>ch;
        cout<<ch<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221103193957.png)

对于上方的一段code，输入字符M，也将显示M，输入0~ 9，也将显示0~ 9，不过出现了一个特殊结果输入20将显示2，意味着其只接受了输入的第一个字符。

将程序稍作修改

```c++
char ch1,ch2;
cout<<"plz input a number : "<<endl;
cin>>ch1>>ch2;
cout<<ch1<<" / "<<ch2<<endl;
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221103194329.png)

显然想法是对的。而对于另一段程序

```c++
using namespace std;
char ch;
int a;
cout<<"plz input a number : "<<endl;
cin>>a;
ch=a;
cout<<a<<endl;
cout<<ch<<endl;
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221103194949.png)

M错误的赋值给了int 型变量a，而95可以得到正确结果。

```c++
cout.put(ch);
cout.put(a);
//输入97时，均输出a，这与cout.put()函数定义有关
//put()函数在cout类中
```

需要注意C++中，cin>>a，对变量a赋值时，怎么接收数据取决于a的类型，char a，则接收一个字符并将字符转化为ASCII码存储，而若为int a，则存储为对应的数字。

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221103200504.png)

一般在打印较长的字符串时，常用`\n`，`cout<<"...\n...\n";`，以实现分段。而在打印变量时，常用`endl`，如`cout<<a<<endl;`.

### 2.4 其他字符

1. 通用字符，例如Unicode字符集，包含了各种符号，U-222B表示Unicode字符集十六进制编号222的符号，一般在专门的场景使用
2. unsigned char与signed char：int默认为有符号型，而char则取决于编译器，根据需要来决定其是不是有符号型。
3. wchar_t:用于显示中文日文等，显然char 是不够的，因此提供了一种类似的操作，wchar_t类型，并提供了对应函数`wcout>>...;`
4. char16_t与char32_t:C++新增类型，前缀u表示前者，为16位。大写U表示后者，32位无符号

### 2.5 bool型

bool型仅为true和false，对于一些赋值语句非零会默认为true，而0是false。

true则会默认为1，false依然是0；

### 2.6 const常变量

类似于`#define`定义符号常量，const可以实现同样的功能，例如

`const int Months=12;`定义了月份常变量，为便于区分，建议首字母大写。

**并且注意，定义常变量时必须初始化，且初始化后不可更改**。

### 2.7 浮点数

浮点数无非就是float与double、long double型，表示方式也包括直接表示与科学计数法。

```C++
12.34;
0.02;
8.0;
2.5e+8;//小数点右移8位
8E-4;//8.0小数点左移4
-13.0E5;//默认为+ 右移5，可带+or-符号
7.2 E6;//不可加空格
```

float有效位**至少32位**，double至少48且不少于float，long double至少与double一样多，通常float32位，double64位，long double 80、96、128.

```C++
#include <iostream>
int main(void)
{
        using namespace std;
        cout.setf(ios_base::fixed,ios_base::floatfield);
        float tub = 10.0 / 3.0;
        double mint = 10.0 / 3.0;
        const float million = 1.0e6;
        cout<<"tub = "<<tub;
        cout<<" , a million tub = "<<million*tub<<endl;
        cout<<"mint = "<<mint;
        cout<<" ,million mint = "<<million*mint<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221103212848.png)

**float有效位为6**，而double有效位为15，显然double型的精度更高，float的结果出错而double依然正确。

但是仍然浮点数会存在一个问题，其虽然可以显示到小数点后几位，但是同样会对运算精度产生影响。

```C++
float a=2.34E+22f;
float b=a+1.0f;
cout<<b-a<<endl;
```

该程序段的结果会是0.000000，原因是float**只有6位有效位**，只能正常显示前6/7位字符，甚至说从第8位开始就不会参与运算。

`float a=2.34E+7f;`结果为0.000000，而`float a=2.34E+6f;`结果为1.000000

**浮点数在内存中的存储**：

float计32位，以二进制科学计数法方式存放在内存中。

例如8.25=8.25e0，二进制表示为1000.01，二进制科学计数法为1.00001*2^3，二进制小数点每移一位乘2。

| 符号位 | 指数位 | 小数位 |
| ------ | ------ | ------ |
| 1bit   | 8bit   | 23bit  |

而指数位上又包括正负，所以在0-127计负次，即首位为0；128-255为正，因此表示+3的值为127+3=130(而-1是127-1=126，并非是简单的0...01)，因此8.25的内存存储形式为

0 10000001 00001000000...（补0），共有32个有效位，而实际能表示的10进制数字为6/7位(lg2^32^=6.92),**即6-7位有效位实际是能表示的10进制位，而32位是指二进制有效位。**

**double也类似，指数表示正负也是看首位，也就是所谓 的+1023**，比如表示+1，其实就是10000000001，首位为1而已。不过因为double占字节更长，**小数位更多，所以精度更高64bit，换算为10进制约为15位（lg2^52^=15.65）。**

| 符号位 | 指数位 | 小数位 |
| ------ | ------ | ------ |
| 1bit   | 11bit  | 52bit  |

### 2.8 C++运算符

无论是运算符还是数据类型，其与C语言的规则绝大多数都类似.

```C++
#include <iostream>
int main(void)
{
        using namespace std;
        float hats,heads;
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<"Enter a number :";
        cin>> hats;
        cout<<"Enter another number :";
        cin>>heads;
        cout<<hats+heads<<endl;
        cout<<hats-heads<<endl;
        cout<<hats*heads<<endl;
        cout<<hats/heads<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221104144034.png)

由于float型数据只是近似存储，0.17很难在23位小数位表示出来，所以如果`cout.setf(ios_base::fixed,ios_base::floatfield);`要求显示6位，结果出现偏差，注释掉之后结果正确。将float改为double精度也会更高。

计算机默认浮点常量为double型，取模操作同C。

### 2.9 类型转换

也同C，即低精度向更高精度转化，若将大范围赋值给小范围，恭喜你，要出现截断现象，精度丢失。

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221104185835.png)

```C++
#include <iostream>
int main(void)
{
        using namespace std;
        int a = 3.4;
        float b = 4,c = 5.5,*pc=&c;
        int d =*(int *)pc;
        cout<<a<<" / "<<d<<endl;
        return 0;
}
//结果：3 / 1085276160
```

上面的程序在c语言中就说明过，将3.4赋值给int只会保留整数，但是（int*）pc直接强制改变了指针类型，也就意味着要将按float型存储的二进制码1+8+23按照整形方式解析，自然会出问题

另外一种转换形式是`类型 (变量名)`.表达式中对不同类型的数据进行转换，以最高精度的为准，**而有无符号取决于无符号值能否被有符号值表示，比如无符号24可以用有符号型表示，会转换为有符号，否则反之。**

另外注意，**先强转再运算与先运算再强转结果可能不同**

```c++
#include <iostream>
int main(void)
{
        using namespace std;
        int a = 11.99 + 1.99;
        int b = (int)11.99 + (int)1.99;
        cout<<"a = "<<a<<"; b = "<<b<<endl;
        return 0;
}
//a=13; b=12
```

注意,`{}`**进行赋值时，需要注意数值范围，不允许溢出类型范围**，比如`char a = 256;`,超出了0-255范围，编译不会通过。

对于auto型，由计算机分配类型，但是可能导致错误。

## 3.复合类型

### 3.1 数组

数组内容同C，需要表明元素的类型、数组名、元素个数。

编译器不会检测下标的有效性，下标出错可能导致错误的赋值。

比如完全初始化,部分初始化，都是完全相同的，也禁止缩窄赋值。

```C++
int a[3];
a[0]=1;a[1]=2;a[2]=3;
int b[3]={1,2,3};
```

省略数组元素个数时，将会由编译器默认设置，如果少写入一个数据，将会导致出错，`int num=sizeof namearray/sizeof typearray;`可以实现计数。

在c++中，对数组初始化有一种新的形式，即省略=，如下

`int a[]{1,2,3};`也是合理的。

### 3.2字符串

```c++
char dog[8]={'a','b','b','c','d','e','f'};
char cat[8]={'a','b','b','c','d','e','\0'};
```

字符串本质还是字符数组，只不过说是末尾为`'\0'`的特殊形式，dog是字符数组，而cat才是字符串，`""`可以直接使用**字符串常量**对数组整体进行赋值。

字符串常量实际上是内存地址，而不是表面上的字符。

**对于字符串拼接，cout将对两个连续的字符串常量进行拼接，无论中间有没有空白符，后者 的第一个字符将取代前着的结束符。**

而对于字符串赋值，也有一部分需要注意，cin遇到空白符就结束，多余的数据将存放在缓存区，这和C语言scanf简直一模一样。

```c++
//1.cpp
#include <iostream>
int main(void)
{
        using namespace std;
        const int SIZE = 20;
        char name[SIZE],dessert[SIZE];
        cout<<"what's your name :";
        cin>>name;
        cout<<"what's your favorite dessert :";
        cin>>dessert;
        cout<<"ok,i have some "<<dessert<<" for you,"<<name<<"."<<endl;
        return 0;
}
```

对于上方的程序，如果输入是姓名有空格，那么将会把前者赋给name，而后者赋给dessert，错误发生。

C++也提供了类似于gets的解决方案，比如`getline()`以及 `get()`,直至遇到换行符才截止，不过前者舍弃换行，而后者保留。

+ 使用`getline(name,size)`,至多读取`size-1`个字符存放在name中

  ```c++
  //2.cpp
  cout<<"what's your name :";
  cin.getline(name,SIZE);
  cout<<"what's your favorite dessert :";
  cin.getline(dessert,SIZE);
  cout<<"ok,i have some "<<dessert<<" for you,"<<name<<"."<<endl;
  ```

  将程序cin改为cin.getline()后可以显示正确结果。

  ![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221105163850.png)

  `cin.getline()`还有一个特殊之处，最后的换行将被替换为`\0`结束符。

+ 使用`cin.get()`函数

  ```c++
  //3.cpp
  cout<<"what's your name :";
  cin.getline(name,SIZE);
  cout<<"what's your favorite dessert :";
  cin.getline(dessert,SIZE);
  cout<<"ok,i have some "<<dessert<<" for you,"<<name<<"."<<endl;
  ```

  ![image-20221106114053950](../AppData/Roaming/Typora/typora-user-images/image-20221106114053950.png)

  get函数会保留换行符，因此输入到缓冲区后是保留换行符的，会导致下一次get读取时第一个就遇到换行符，导致出错。

  + **应该使用`cin.get();`来读取下一个字符，思路类似于C的getchar，把空格或者换行读走。**

  + `cin.get(name,SIZE).get();`拼接形式，将换行读出

    cin.get()的返回值是cin对象，可以继续使用cin函数

    而一个函数可以使用不同参数的形式，就称为重载，BMP388中遇到的定义`bmp.begin();`

getline相对于get截止条件不明确，不知道是换行还是读满，而get可以通过`cin.get();`读取下一个字符是不是回车确定是否是字符串太长没有完全读完，此情况在后面再说。

而cin还有一个弊端，即在输入完数字去输入字符串时也会保留回车，导致赋空行。

```c++
#include <iostream>

int main(void)
{
        using namespace std;
        const int SIZE = 80;
        int year;
        char built[SIZE];
        cout<<"what's your house built :";
        cin>>year;
        cout<<"what's your favorite address";
        cin.getline(built,80);
        cout<<"Year built : "<<year<<endl;
        cout<<"Address : "<<built<<"."<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221106201943.png)

显然需要将回车处理掉，比如在`cin>>year;`后加上`cin.get();`处理回车，或者也使用拼接的方式`(cin>>year).get();`,一般建议使用前者，前者更明了。

### 3.2 string类——数组升级版

```c++
#include <iostream>
int main(void)
{
        using namespace std;
        char ch1[20],ch2[20]="jajuar";
        string str1,str2 = "panther";
        cout<<"Enter a kind of feline :";
        cin>>ch1;
        cout<<"Another feline :";
        cin>>str1;
        cout<<"here some feline:\n "<<ch1<<" "<<ch2<<" "
                <<str1<<" "<<str2<<endl;
        cout<<"The third in :"<<ch2<<" is "<<ch2[2]<<endl;
        cout<<"The third in :"<<str2<<" is "<<str2[2]<<endl;
        return 0;
}
```

这段程序写了数组和string形式，显然，**数组即使不想初始化，也需要表明大小，但是string不需要，会将string声明为简单变量，可以用cin输入，输入多少字符自动调整str1的长度**，而且可以同数组一样调用其元素。

同样的，也可以使用花括号赋值,甚至有更多骚操作：

```c++
string str1 = {"the bread bowl"};//正常赋值
string str2 = str1;//串间赋值，如果char a2=a1;是非法的
string str3 = str2 + str1;
string str4;
str4 + = str3;//字符串相加减也是合理的，把str3连接在str4后
```

```c++
include <iostream>
int main(void)
{
        using namespace std;
        char ch1[20],ch2[20]="jajuar";
        string str1,str2 = "panther";
        cout<<"Enter a kind of feline :";
        cin>>ch1;
        cout<<"Another feline :";
        cin>>str1;
        cout<<"here some feline:\n "<<ch1<<" "<<ch2<<" "
                <<str1<<" "<<str2<<endl;
        cout<<"The third in :"<<ch2<<" is "<<ch2[2]<<endl;
        cout<<"The third in :"<<str2<<" is "<<str2[2]<<endl;

        cout<<endl;
        string str3;
        str3 = "plz";
        cout<<"str3 = :"<<str3<<endl;
        str3 += "give me a cup";
        cout<<"str3 + = \"give me a cup\",str3 = : "<<str3<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221106210230.png)

数组方式连接函数`strcpy()、strcat()`:

```c++
#include <iostream>
#include <string>//c++ string
#include <cstring>//c strlen
int main(void)
{
        using namespace std;
        char ch1[20],ch2[20]="jajuar";
        string str1,str2 = "panther";
        strcpy(ch1,ch2);
        str1 = str2;
        cout<<"ch :  "<<ch1<<" "<<ch2<<" "
                <<str1<<" "<<str2<<endl;
        str1 += " past";
        strcat(ch1,"juice");
        int len1 = str1.size();//c++计算长度，str1为string类变量，可以调用string方法
        int len2 = strlen(ch1);//c计算长度
        cout<<"str1 : "<<str1<<" / "<<len1<<endl;
        cout<<"str2 : "<<ch1<<" / "<<len2<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221106212417.png)

完全能实现相同的功能，不过可能更复杂，而且由于数组需要指定大小，总会存在大小不够用的情况，~~就像钱包一样~~，虽然c函数有`strncp()、strncat()`函数可以限定字符长度，但是太麻烦。

#### 3.2.1 string类IO

```c++
#include <iostream>
#include <string>
#include <cstring>
int main(void)
{
        using namespace std;
        char ch1[20];
        string str1;
        cout<<"Enter a string : "<<endl;
        cin.getline(ch1,20);
        cout<<"Enter another string : "<<endl;
        getline(cin,str1);
        cout<<ch1<<" / size= "<<strlen(ch1)<<endl;
        cout<<str1<<" / size = "<<str1.size()<<endl;
}
```

显然，即使是使用cin对string类进行整行输入，还是无法避免空白符截断的情况，在此使用另外一种语句`getline(cin,str1);`将输入行赋值给str1。

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221107170537.png)

### 3.3 其他字符类型

```c++
#include<iostream>
int main(void)
{
        using namespace std;
        wchar_t title[] = L"Chief aaa";
        char16_t name[] = u"felonia";
        char32_t car[] = U"Humber super";
        cout<<R"(jam "king" "\n ".)"<<"\n";
        cout<<R"+*("(wow)",its good)+*"<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221107172644.png)

wchar_t先不多说，对于R即**原始类型raw型，所有的元素将原样输出**，同时可以自定义界定符，比如`R"()"`或者`R"+*()+*"`,界定符不同，可以防止有特殊字符影响输出，非常多变。

### 3.4 struct 结构体

同c，struct结构体有多个变量，它本身也是一个类型或者对象。

```c++
include<iostream>

struct inflatable
{
        char name[20];
        float volume;
        double price;
};

int main(void)
{
        using namespace std;
        inflatable guest =
        {
                "Glorious gloria",
                1.88,
                29.99
        };
        inflatable pal =
        {
               "Audacious arthur",
                3.12,
                32.99
        };
        cout<<"guest list with "<<guest.name;
        cout<<" and "<<pal.name<<endl;
        cout<<"You need to pay $"<<guest.price+pal.price<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221107173500.png)

在使用结构体时有几点不同：

+ 声明时可以省略struct
+ 初始化时可以省略=，`inflatable clock {};`也是合理的，不过是赋值为0
+ 调用其内部函数只需要使用pal.xx，相当于是内部变量在pal中的新名字，但是内容是不变的
+ 结构体内也可以是string，甚至比数组都好用`char name[20];`完全可以更改为`string name;`，当然，使用string前记得声明`using namespace std`；

还有**几点略微风骚的操作：**

+ `choice = budget; `其中choice与budget均是一种结构体，可以实现完全赋值，甚至**结构体内的数组也可以以此赋值**，但是结构体外的数组是不行的

+ ```c++
  struct 
  {
      char ...;
  }particular;
  ```

  完全可以定义一个专属的结构体，连**结构体类型名都能省略，~~但是并不好用~~**

+ 如果**表述多个相同特性的对象，结构体变量也可以使用数组**

  ```c++
  struct university student[33] ={{...,...},{...,...}}
  ```

  student是一个数组，元素类型是university结构体类型，如果相调用数组内的元素，需要指明角标，比如`student[2].name;`,这样才是合理的



位字段用法：

```c++
struct torgle
{
    unsigned int SN : 4;//指定sn字段使用4位
    unsigned int : 4;//没有名称的字段，用于存放间距
    bool goodln :1;
}//用于匹配寄存器，常见于低级编程，了解即可
```

### 3.5 union结构体

union与C相似，**所有变量共用一块内存空间，就像抽屉，可以放书，也可以放零食，但是只能放一种。而结构体，直接要装几种东西给你几个抽屉，甚至直接给你一个衣柜。**共用体的长度为最大成员的长度，因此非常节省内存。

```c++
#include <iostream>

using namespace std;

union pal
{
        int age;
        char init;
};

int main(void)
{
        pal yang;
        cout<<"input a number : "<<endl;
        cin>>yang.age;
        cout<<"the yang initial name is : "<<yang.init<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221107200658.png)

显然，yang.age与yang.init使用的同一个首地址。

其还有一种更好的用法，即在结构体中定义一个无名的结构体，可以选择使用何种分量。

```c++
#include <iostream>
using namespace std;
struct pal
{
        int type;
        char brand[20];
        union
        {
        long id_num;
        char id_char[20];
        };
};
int main(void)
{
        pal yang;
        cout<<"input a number : "<<endl;
        cin>>yang.type;
        if(yang.type==1)
                cin>>yang.id_num;
        else
                cin>>yang.id_char;
        return 0;
}
```

**结构体中定义了一个联合体，虽然没有变量名，但是完全可以正常使用，可以直接通过结构体名调用，而后续通过type的值来选择使用何种形式赋值**

### 3.6 enum枚举

枚举的格式与结构体完全类似，**只不过其值只能为整形**，而且默认从0开始，它也是另外一种定义符号常量的方式，类似于const，还有#define。

`enum spectrum {red,orange,yellow...};`定义一个spectrum类型的枚举量，后续可以使用`specturm color;color=blue;`类型的语句进行赋值调用。

**但是在调用还有点要注意：**

+ 枚举变量赋值时，只能赋枚举内部的值，比如red，orange，其他的就是非法

+ 枚举算数运算非法，整形提升不算`int a=red+orange;`可以

+ 枚举可以整形提升，`int a = red;`，但是不能把数字给枚举，比如`spectrum band = 3;`，3是整形，但不是spectrum型，类型不匹配的亲

+ 为解决第3点，可以使用强转，`band=(spectrum)3;`，这与`band = green;`效果完全相同，**强转可以随心所欲赋值，但问题是，它在超出范围时不会报错**`band=(spectrum)9999999;`，**也很容易出问题**。

  但是，在枚举取值范围内对整形强转是没有问题的，上限为最靠近最大值的2的次幂并-1，比如65-128，上限为128-1=127，下限为0或者靠近最小值的（2的次幂-1）的相反数，如果最小为-6，下限为-（8-1）=-7

+ 如果只需要符号常量，同struct、union一样，甚至不需要定义枚举名称`enum {red,blue,...};`

枚举初始化也与C的相同，不过把int限定修改为long甚至longlong。

格式：`enum {zero,null=0,one,numer_uno=1};//0，0，1，1`

### 3.7 指针与自由存储

不清楚为什么起这个标题，但本质就是指针与存储方式，同C`&`为取址符，cout输出地址默认按照十六进制，至于变量也就是几个连续的几个字节而已，而**具体变量与变量之间是否存储在相邻内存单元取决于编译器**。

```c++
#include<iostream>
int main(void)
{
        using namespace std;
        int donuts = 6;
        double cups =4.5;
        cout<<"donuts value = "<<donuts<<endl;
        cout<<"and donuts address is : "<<&donuts<<endl;
        cout<<"cups valus = :"<<cups<<endl;
        cout<<"this address is : "<<&cups<<endl;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221108194827.png)

地址为64位形式，这与安装时虚拟机ubuntu-amd64一致，前后者的差值为90-8c=4byte，也就是int大小，在linux环境下，变量内存单元是相邻的。

**面向对象编程策略：**

**面向过程编程是在程序运行过程中决策，对于不同的情况可以选择不同的做法，比如可以选择创建20大小或者200大小的数组，而传统的面向过程编程是在编译阶段决策，确定究竟选择哪个操作，不可更改。**

对于指针，和C相同，不再多说，**最重要的还是要在使用函数之前指定一个确定的地址**。

+ 对于指针和数字，可以使用强转赋值，但可能像枚举超限赋值一样导致运行出错，更扯的是这种情况不会编译报错

#### 3.7.1  new

``` c++
int *pn = new int;
//typename *pointname = new typename;
```

该语句意味着**从内存空间找到一个空闲(未被其他变量命名)的int长度的空间，将其地址给pn指针，后续可以通过pn来修改其值，只是这个空间没有变量名**，不同于下方语句操作a

```c++
int a = 1;
int *pa = &a;
```

new的几点注意：

+ new可以声明很多不同的类型，只要指针名不同就不影响`int *pa=new int;double *pb=new double;`是合理的，且* pa、*pb具有不同的长度，~~毕竟是int和double~~；
+ new分配的内存块于常规变量分配的内存块不同，变量通常被存储在栈区，new数据对象被分配在堆（heap）或自由区（free store） 

+ 内存耗尽时new将返回一个空指针`NULL/0`,通常这种情况表示运行出错

#### 3.7.2   delete

需要内存时使用new来申请，对应需要delete来释放，delete也只是释放内存，而不是删除指针。通常上，new与delete需要一一对应，且不能多次释放。

```c++
int *ps=new int ,a = 3,*pa = &a,*pc=NULL;
delete ps;//释放内存,ok
delete ps;//多次释放，报错
delete pa;//错误，不能以此释放已有变量的内存
delete pc;//ok
```

+ 不要用两个指针指向一块内存，因为delete释放内存时两个指针可能都要完蛋

使用new创建动态数组、字符串、结构体，这种叫动态联编（dynamic binding），相对于静态联编（static binding）直接创建固定大小的数组更省内存。

#### 3.7.3 动态数组

```c++
int *ps = new int [10];//创建动态数组
delete [] ps;//释放动态数组
```

动态数组内存返回值为首地址，但是不能直接delete ps，你要干什么，只释放首地址？那剩下的不能用也不能释放，浪费了，因此需要注意括号对应。

```c++
#include<iostream>
using namespace std;
int main(void)
{
        double *p3 = new double [3];
        p3[0] = 0.2;
        p3[1] = 0.5;
        p3[2] = 0.8;
        cout<<"P3[0] is : "<<p3[0]<<endl;
        p3 = p3+1;
        cout<<"p3 = p3 +1,P3[0] is : "<<p3[0]<<endl;
        p3 = p3 -1;
        delete [] p3;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221108212131.png)

还有有趣的一点，利用new分配动态内存数组之后，**确实可以将指针的指向当成数组来处理，指针的加减=前后移动元素的个数，但是记得使用完让指针回到初始位置后再去释放内存**，否则可能会出错

### 3.8 指针运算

指针运算似乎也没什么好说的：

+ `int *ps = &a; ps =  ps+1;`，指针跨越一个类型
+ `char a[10];`,a[0]=*(a+0);

指针大多数情况下与数组用法相同，除了sizeof，sizeof是计算变量的长度，指针操作再多，归根结低也只是一个变量而已。

还要注意，**对数组取地址时，是整个数组的地址，数组也不过是一个长度比较大的组变量而已，而直接使用数组名时，则是数组的首元素地址，即a完全可以理解为**`*(a+0)`。

```c++
short tell[10];
short (*pas)[10] = &tell;
//数组地址也可以赋给指向数组的指针，即数组指针，此时ps指向有20个元素的数组，意味着*pas=tell数组变量，(*pas)[1]=tell[1]等价
```

对于指向同一个元素的指针，利用指针相减确定间隔元素个数，+1才能确定数组长度。

```c++
#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
        char animal[20] = "bear";
        const char *bird = "wren";//指向字符串常量首地址，可用不可改，有些编译器使用字面值的副本保存常量，至于多少副本可能取决于编译器
        char *ps;
        cout<<animal<<" and "<<bird<<"\n";
        cout<<"Enter a kind of animal "<<endl;
        cin.getline(animal,20);
        ps = animal;
        cout<<ps<<"!\n";
        cout<<"Before using strcpy() : \n";
        cout<<animal<<" at "<<(int *)animal<<endl;
        cout<<ps<<" at "<<(int *)ps<<endl;

        ps = new char[strlen(animal)+1];//申请恰当的动态内存存放animal的副本
        strcpy(ps,animal);
        cout<<"after copy : \n";
        cout<<animal<<" at "<<(int*)animal<<endl;
        cout<<ps<<" at "<<(int *)ps<<endl;
        delete [] ps;
        return 0;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221109113751.png)

对于cout而言，使用strcpy之前，animal与ps输出相同，因为指向同一个地址，而如果想把地址输出，需要把char* 强转为int*，否则将会输出串值。

### 3.9 动态类

动态类类似于动态数组，都是new创建

```c++
struct student 
{
    char name[20];
    int id[15];
}
student *pyang = new student;
cin.getline((*pang).id,15);//.运算
cin.getline(pyang->name,20);//->运算
```

同样节省内存

```c++
#include <iostream>
#include <cstring>
using namespace std;
char* getname(void);
int main(void)
{
        char* name;
        name = getname();
        cout<<name<<" at "<<(int*)name<<endl;
        delete [] name;
        name = getname();
        cout<<name<<" at "<<(int*)name<<endl;
        delete [] name;
        return 0;
}
char* getname(void)
{
        char temp[80];
        cout<<"Enter a string : "<<endl;
        cin.getline(temp,80);
        char *pn = new char[strlen(temp)+1];
        strcpy(pn,temp);
        return pn;
}
```

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221109163339.png)

+ 来回赋值主要使用的是指针，而不是固定的数组，在getname中申请内存并将临时数组的数据存放在其中，一定要在main中及时释放
+ 两次调用地址可能一致，也可能不一致 

既然以及谈到了动态存储，也提一下C++中的存储方式，包括自动存储（局部变量）、静态存储（static）、动态存储（new、delete），动态存储常在栈中（或叫自由存储空间）。

### 3.10 复合类型

结构体，数组可以随意组合

```c++
struct student
{
    int age;
    int gender;
}
student s01,s02,s03;
const student *arp[3] = {&s01,&s02,&s03};
const student **ppa = arp;
//auto p = arp;上方二级指针可以以此替代
cout<<(*ppa)->age<<endl;//*ppa为指针，也是数组arp的首元素
```

### 3.11 数组替代品

1. vector类

   vector类本身只是使用new和delete封装好的动态分配内存，在头文件vector中，声明std命名空间，可以确定名称和个数

   ```c++
   int n = 10;
   vector<int> vi(n);//创建n个int元素的名为vi的vector对象
   ```

2. array类

   array类似于数组，长度固定，分配在内存中的栈区，在头文件array中，同样类似于vector类

   ```c++
   array<int,10> vi;//个数在<>内部声明，元素个数也只能是常量，固定
   ```

3. 数组、vector、array区分

   三者都可以当数组利用下标来使用，甚至特性都类似，不过可以将array对象之间相互赋值，这类似于string和struct，

   且三者在超限调用或者赋值时都不会报错，~~隐藏的炸弹~~

   另外要注意，**数组和array可以在定义时不完全初始化，但是vector不行**~~就你特殊~~。

   ![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221109175956.png)

## 4.循环与关系表达式

### 4.1 for

循环无非就是`for、while、do..while`，复合运算符、代码块、局部变量全局变量，格式与c完全相同，不再过多赘述，仅仅对一些c++特殊点进行说明

+ for循环与括号间常有空格，~~只是为了看着舒服~~

+ 允许连续赋值，比如`a = ( b = 4 ) + 3;x = y = z = 0;`,与赋值符右结合性有关，但是并不建议~~也不好用~~

+ cout输出表达式时需要加括号`cout<<(x = 100);`,<<优先级较高，**但在输出语句用赋值表达式或者改变其值可能会影响正确性**

+ **要输出bool结果需要设定，否则会强转为int**，`cout<<ios_base::boolalpha;`

+ 表达式无分号，加分号变为语句，但是不一定有用；语句去掉分号如果不能参加算数运算，就不能称之为表达式，比如`int a ;int c=int a * 10;`是错误的，甚至是四不像，强转还是算数运算？什么都不是。

+ c++允许在for循环初始化创建新变量，`for (int i = 0;i<5;i++);`是合理的，i会视为局部变量，循环结束后释放

+ ```c++
  //unit4/1.cpp
  #include<iostream>
  #include<cstring>
  #include<string>
  int main(void)
  {
          using std::cout;
          using std::cin;
          using std::string,std::endl;
          string str;
          cout<<"Enter a word : ";
          cin>>str;
          for (int i =str.size() - 1 ; i >= 0; i--)
          {
                  cout<<str[i];
          }
          cout<<endl;
          return 0;
  }
  //倒序打印实现
  ```

+ 自增自减也同c，不要多个自增自减同时出现，比如说`int b=2;int a = b++ +b++ +b++;`，**C++没有规定是在子表达式后自增还是在整个式子结束之后自增**，这种不明了的语句vs结果是2+3+4=9，g++是4+4+4=12，也不便于移植。

+ **顺序点**：顺序点概念在C里貌似没有出现过，不过也很好理解，就是一个表达式的结算表示，必须在此标志前完成，**说人话，其实就是分号**；

+ 一般前缀是直接+1再返回，而后缀先复制一个副本，副本+1再返回，前缀版本会速度更快

+ ```c++
  x = *pt++;
  //pt先调用，然后指向下一个地址
  //前缀自增自减、解引用优先级相同，从右至左，后缀自增自减高于前缀，从左至右
  ```

+ 变量声明的位置可以在for()括号内初始化，即使初始化多个也与在外部初始化相同，~~不过看起来会有亿点点乱~~，当循环多次时，在循环体内部创建将消耗更多时间，~~不过没有时间限制的话一般也看不出来~~

#### 4.1.1 比较

**关系运算符，大于小于等于等等，优先级小于算数运算**，甚至不需要加括号，~~不过为了更直观还是建议加上~~

**关系运算符同样不适用于字符串比较**，但是可以用于string，而字符串只能用strcmp（cstring），而且存在弊端，因为是**按照ASCII码比较的可能出现Zoo<axxx的情况**,下方是一段使用strcmp比较字符串的情况

```c++
int main(void)
{
    using namespace std;
    char name[5]="?ate";
    //string word = "?ate"; 
    for(ch = 'a';strcmp(ch,"mate");ch++)
        name[0]=ch;
    //for(ch = 'a';word != "mate";ch++)
        name[0]=ch;
	return 0;
}
```

注释掉的两行是使用string类进行比较的，这貌似是直接在类内部重载了关系运算符的，具体原因要看类设计，for常用于计数，不计数更多用while，**for内的判定语句省略时，视为true**

### 4.2 while

while同c，以下是标准延时函数

```c++
//unit5/2.cpp                                        
#include<iostream>
#include<ctime>
int main(void)
{
        using namespace std;
        cout<<"Enter the delay,in seconds : ";
        float secs;
        cin>>secs;
/**/        clock_t delay = secs*CLOCKS_PER_SEC;
/**/        clock_t start = clock();
/**/        while(clock()-start<delay);
/**/        cout<<"ok!"<<endl;
        return 0;
}
```

**ctime库中定义了clock_t类型与CLOCKS_PER_SEC宏，只需要将秒转化为时钟周期再判断可以节省很多时间，时间也更精确**

类型别名：

+ #define宏替换
+ typedef直接取别名，但是不创建新类型

### 4.3 do while

同c，此循环更适用于需要先取值再判定的情况，3种方式各有优劣，以便于观察为准

### 4.4 范围for

三种形式,但是感觉本质只有一种，已知的一个数组，同类型字符x固定，从始至终

+ ```c++
  double p[5]={1,2,3,5,6};
  for(double x : p)//x为p的首元素
      cout<<x<<std::endl;
  ```

+ ```c++
  for(double &x :p)
      x=x*0.8;//&引用改值
  ```

+ ```c++
  for(int x :{1,2,3,4,5})
      cout<<x<<"";
  cout<<endl;
  ```

### 4.5 循环文本输入

#### 4.5.1 cin

```c++
//3.cpp                  
#include<iostream>
int main(void)
{
        using namespace std;
        char ch;
        int count = 0;
        cout<<"enter a char : ";
        cin>>ch;
    	//cin.get(ch);
        while(ch != '#')
        //1.while(cin.fail() == false)
        //2.while(!cin.fail())
        //3.while(cin),最后一次读取成功时cin转换结果为ture
        {
                cout<<ch;
            	//cin.get(ch);
                ++count;
                cin>>ch;
        }
        cout<<count<<" characterize"<<endl;
        return 0;
}
```

这一段程序非常基础，也绝对看的懂，不过需要再次注意缓冲区的概念，

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221110200630.png)

**cin读数与scanf相同都是从缓冲区读数，因此可以在输入时输入一串，然后cin逐个从缓冲区读**

#### 4.5.2 cin.get()

具体的使用在3.2字符串已经说明，此处主要使用cin.get()读取单个字符，~~主要是难搞的空格~~

核心句：`cin.get(ch);`，将缓冲区字符读入ch

这个用法类似`cin.get(name,20)`，将串读入数组的操作，不过此处向ch读，貌似与cin.get()函数定义参数引用有关，**这是一个重载函数定义**

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221110203437.png)

#### 4.5.3 EOF标志

EOF主要还是标识符，比如识别到#还是什么符号认为结束，但是每个字符都可能有用，可以使用特定的字符EOF

+ **win：ctrl +z** 回车模拟EOF，曾在学c时使用

+ **linux： 程序名 < 文件名**，通过重定向可以直接从文件读取

  ```c++
  //linux终端命令
  nano 4.txt
  ...//输入文本
  ./a.out < 4.txt
  //4.cpp,添加cin.get()读取空格的语句
  ```

  ![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221110211045.png)

  ```c++
  //linux终端另一个操作
  touch 4.txt
  echo 语句 >> 4.txt//将输出到终端的语句添加到文件
  cat 4.txt//显示文件内容
  ./a.out < 4.txt
  ```

  两种方式结果完全相同，只不过下方是用linux终端命令而言

  最终优化结果如下：

  ```c++
  #include<iostream>
  int main(void)
  {
          using namespace std;
          char ch;
          int count = 0;
          cout<<"enter a char : ";
          while(cin.get(ch))
          {
                  cout<<ch;
                  ++count;
          }
          cout<<endl<<count<<" characterize"<<endl;
          return 0;
  }
  ```

  只需要在判断时使用`while(cin.get())`，进入循环时第一次读取，**且将读取结果`cin`类型转换为bool型，判断是否读到文件尾，这种方式只适用于文件流输入**

#### 4.5.4 另一个cin.get()

可以使用cin.get()给字符赋值，`ch = cin.get();`，此时cin.get()返回一个int编码赋值给ch，是合理的，到达EOF时，ch值为EOF(int码为-1)。

甚至为了适配更多环境，有符号的无符号的，int的char的，可以定义`int ch ; ch = cin.get();cout.put(char(ch));`,就是在输出时需要一步强转。

**再次说明，关系运算符的优先级高于赋值，要使用多个赋值时建议带括号**

不过对于cin.get(),一个参数的返回值为cin对象，而没有参数的返回一个ch字符，虽然可以赋值，但是也仅仅如此了，~~有一个参数的甚至可以开火车~~`cin.get(ch1).get(ch2).get(ch3)...`

### 4.6 二维数组

二维数组可以理解成一维数组，只不过每个元素又是一个数组而已。初始化、循环调用不再赘述。

```c++
#include <iostream>
int main(void)
{
        using namespace std;
        const int cities = 5;
        const int year = 4;
        const string pst[cities]={"Beijing","shanghai","Guangzhou","shenzhen","chengdu"};
        int temp[year][cities]=
        {
                {33,34,36,66},{22,33,33,45},{24,24,22},{}
        };
        int test[5]={1,0,2,3};
        for(int i = 0;i<cities;i++)
        {
                cout<<pst[i]<<" :\t";
                for(int j = 0;j<year;j++)
                        cout<<temp[j][i]<<'\t';
                cout<<'\n';
        }
        return 0;
}
```

此段程序足以演示二维数组的使用，实践时出现两个要注意的地方：

+ 数组不完全初始化问题，`int test[5] = {1,2,3,4};`属于不完全初始化，最后一个没有赋值，但是`int test = {1,,2};`是错的，默认补0只是在后面可以补0，如过想实现前面某个值为0，只能直接赋值，比如`int test = {1,0,2};`
+ string类数组，有另外两个选择`const char *pst[5]={...};`指针数组形式 ，以及`const char st[5][25]={...};`形式，但是如果考虑内存和修改，则使用string是最优的结果。

```c++
        char ss[4][6] = {{"abac"},{"hah"},{"yeah"},{"hai"}};
        char (*pss)[6] = ss;
//左端为指向6个char组变量的指针，右端为首元素地址，即第一行，也是指向6个char组变量
```

## 6.分支与逻辑表达式

实际上没有什么好说的，无非是if与switch很多与C相同...

### 6.1 if

if、if else、else if、就近匹配、判断时，常量放在左侧等技巧...

### 6.2 &&、||、！

只需要记住一点**逻辑||、&&优先级<关系运算符<算术运算符，但是逻辑！是三者最高的，取反之前需要括号括起**，~~食物链了属于是~~

书中有一个例子，是判定是否是整形范围的

```c++
#include<climits>
long long a;
bool is_int(long long x)
{
    if(x<INT_MAX&&x>INT_MIN) return true;
    else return false;
}
```

思路是使用更大范围数来存储输入值，再与int范围比较，如果合理，则返回true，如果输入的值超过int范围而强行存储在int中，数据可能会丢失

+ and、or、not与与或非的功能是相同的，属于保留字，在c中需要包含(iso646.h)

**常规意义上进行字符判定，往往是判断是否在a-z之间（或者类似这种形式），但是c++提供了字符库函数，包含在cctype头文件中，其中的各个函数可以直接作为判定条件，建议使用。**

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C++/20221111193003.png)

### 6.3  三目？：符

三目运算符？：与C用法相同，一个完整的？：表达式也可以做令一个？：的一个分支

### 6.4 switch

switch case，用法同c

switch后接的表达式必须是**结果为整数的表达式**，而**case后的必须是整数常量表达式（int、char、enum也可以，枚举强被强转为int）**，前者只强调结果为整形，**后者则必须是给定的值**

switch主要用于处理分支，而ifelse可以处理范围

### 6.5 break、continue、goto

break用于跳出switch或者当前循环，而continue用于跳过此次循环。

goto语句可以跳转到任意地方，但是不利于模块化

### 6.6 读取数字循环

读取数字循环与读取字符非常相似，但是如果在此输入字符...程序依旧会出错：

+ n值不变
+ 不匹配的值继续留在输入队列
+ cin对象错误标记被设置
+ 对cin方法的调用返回false

```c++
#include<iostream>
int main(void)
{
        using namespace std;
        const int MAX = 5;
        double fish[MAX],sum;
        int i = 0;
        cout<<"fish #1 : ";
        while(i<MAX&&cin>>fish[i])
        {
                if(++i<MAX)
                cout<<"\nfish #"<<i+1<<" : ";
        }
        for(int j = 0;j<MAX;j++)
        {
                sum+=fish[j];
        }
        cout<<"sum = "<<sum<<"\n"<<"average = "<<(sum/i)<<endl;
        return 0;
}
```

本身并不难，但是出了很多错误，，比如说循环内没有++i，比如说有效数据个数，输入时退出时数据是i，且第i个没有输入数据，由于i从0计数，所以最终有效个数是i

**在进行优化时再次出现错误,希望在读取/输入错误时跳过当前输入流，即在cin返回false时，清除当前输入流**

```c++
while(!(cin>>fish[i]))
{
    cin.clear();
	while(cin.get()!='\n')
    {
		continue;
    }
}
```

感觉这个题目提供一个非常好的思路，而自己敲时错误的原因是在外层while后加了；导致错误输入时死循环，而内层循环contiue如果没有要求似乎可以取消？待验证

### 6.7 文件输入输出

对文件进行操作，读写文件

对于cin输入流，对变量进行赋值时，不同类型有不同的处理方式，但是感觉大差不差

+ char：读单个字符，存储其字符编码
+ int：读取到非数字字符，存储二进制读取结果
+ double：读取到不属于浮点数的字符，存储浮点二进制码
+ char 数组：`cin>>word;`读取至空白符或者上限，而另一种`cin.getline(word,50);`读取至回车或上限，类似的

#### 6.7.1 输出

对于输出，将把对应的编码显示为字符、数字，比如00001010在显示时显示字符1和0

上方是输入赋值时的原理，在对文件进行输入输出也类似

+ **fstream头文件**
+ 声明ofstream变量，自定义命名
+ 声明名称空间std--ofstream也在名称空间std中
+ 使用ofstream对象与文件关联，即.open（）,~~感觉和arduino的类似~~
+ 结合使用ofstream对象与运算符<<输出数据

实际上，使用ofstream创建新的类之后，当作cout使用就可以

```c++
cout<<fixed;//fixed,类似于之前的dec，oct，hex这种操作符，这个是令浮点型以小数显示
cout.precision(2);//设定小数点后的个数
cout.setf(ios_base::showpoint);//强制显示小数点后的0
ofstream outFile;//定义新的类型
outFile.open("output.txt");
outFile.fixed;
outFile.precision(4);
...;
outFile.close();
```

#### 6.7.2 输入

输入需要使用ifstream创建新的类，然后用法同cin类似，可以用.is_open()检测文件是否正常打开

```c++
#include<iostream>
#include<fstream>
#include<cstdlib>

int main(void)
{
        using namespace std;
        string name;
        ifstream inFile;
        cout<<"Enter filename: ";
        getline(cin,name);
        inFile.open(name);
        if(!inFile.is_open())
        {
                cout<<"Could not open the file "<<name<<endl;
                cout<<"Program terminating.\n";
                exit(EXIT_FAILURE);
        }
        double value;
        double sum = 0.0;
        int count = 0;
        inFile>>value;
		while(inFile.good())
        {
                ++count;
                sum+= value;
                inFile>>value;
        }
        if(inFile.eof())
                cout<<"Enter of file reached.\n";
        else if(inFile.fail())
                cout<<"input terminated by daya mismatch.\n";
        else
                cout<<"input terminated for unknown reason.\n";
        if(count == 0)
                cout<<"No data processed.\n";
        else
        {
                cout<<"items read: "<<count<<endl;
                cout<<"Sum: "<<sum<<endl;
                cout<<"Average: "<<sum/count<<endl;
        }
        inFile.close();
        return 0;
}
```

对文件进行输入与输出也非常类似，不过是相应的ofsteam换为ifstream，同样可以直接把name换为给定字符串,至于用char数组还是使用string本身也无所谓，但是在以文件作为输入时，需要检测文件是否存在，如果文件本身不存在，emmm...

```c++
if(!inFile.is_open())//文件没有正常打开时将退出程序
{
    exit(EXIT_FAILURE);
}
```

甚至可以检测具体的错误原因

```c++
while(inFile.good())//没有错误时执行程序块
{
    ...;
}
if(inFile.eof())//上方程序块退出时具体判断是到文件尾？
    ;
else if(inFile.fail())//或者读到其他字符？
    ;
else//还是未知错误？
    ;
```

在使用`inFile.good()`进行判断时，可以换为`inFile>>value`赋值表达式，其返回值也为`inFile.good()`,成功为true，失败为false。

**而此处的文件操作与之前的输入重定向`./a.out << xx.txt`还有些许区别，前者可以从某些文件读取一些数据，也可以通过软件设定从键盘输入，而重定向则所有的输入都来自文件。**

