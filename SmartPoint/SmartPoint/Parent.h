//
//  Parent.h
//  SmartPoint
//
//  Created by liuqiang on 2018/5/28.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef Parent_h
#define Parent_h

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Child;

class Parent
{
public:
    Parent() { cout << "Parent Constructor..." << endl; }
    ~Parent()
    {
        cout << "Parent Destructor..." << endl;
        std::cout <<" child use_cout:" << child.use_count() << std::endl;
    }
    shared_ptr<Child> child;
};

#endif /* Parent_h */
