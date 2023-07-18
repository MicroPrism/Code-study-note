#ifndef STOCK00_H_
#define STOCK00_H_

#include<string>

class Stock
{
private://私有定义变量
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){total_val = shares * share_val;};
public://公有定义操作，函数实现
    void acquire(const std::string & co,long n,double pr);
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show();
};

#endif
