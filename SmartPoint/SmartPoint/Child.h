//
//  Child.h
//  SmartPoint
//
//  Created by liuqiang on 2018/5/28.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef Child_h
#define Child_h
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
#include "Parent.h"

class Parent;

class Child
{
public:
    Child() { cout << "Child Constructor..." << endl; }
    ~Child()
    {
        cout << "Child Destructor..." << endl;
        std::cout <<" parent use_cout:" << parent.use_count() << std::endl;
        //std::cout <<" child use_cout:" << parent->child.use_count() << std::endl;
    }
    //shared_ptr<Parent> parent; //循环引用 内存泄漏
    weak_ptr<Parent> parent;
};
#endif /* Child_h */
