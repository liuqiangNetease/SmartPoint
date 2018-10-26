//
//  main.cpp
//  SmartPoint
//
//  Created by liuqiang on 2018/5/28.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#include <iostream>
#include "Child.h"
#include "Parent.h"

#include "MainCharacter.h"
#include "FollowObject.h"

class Test
{
public:
    Test()
    {

    }
    ~Test()
    {
        
    }
    
    shared_ptr<Parent> m_spParent;
    shared_ptr<Child> m_spChild;
};

int main(int argc, const char * argv[])
{
    shared_ptr<Parent> parent = make_shared<Parent>();
    shared_ptr<Child> child = make_shared<Child>();
    {
        parent->child = child;
        std::cout << "parent use_cout:" <<parent.use_count() << " child use_cout:" << child.use_count() << std::endl;
        
        Test test;
        test.m_spParent = parent;
        std::cout << "parent use_cout:" << parent.use_count() << " child use_cout:" << child.use_count() << std::endl;
        test.m_spChild = child;
        std::cout << "parent use_cout:" << parent.use_count() << " child use_cout:" << child.use_count() << std::endl;
    }
    std::cout << "parent use_cout:" << parent.use_count() << " child use_cout:" << child.use_count() << std::endl;
    
    //-------------
    shared_ptr<Parent> sp(new Parent);
    //assert(sp.use_count() == 1);
    weak_ptr<Parent> wp(sp); //从shared_ptr创建weak_ptr  其实weak_ptr 是shared_ptr的观察者， 当sharedptr引用计数为0时，会通知weakPtr把指针赋值为空
    //assert(wp.use_count() == 1);
    if(!wp.expired())//判断weak_ptr观察的对象是否失效
    {
        shared_ptr<Parent> sp2 = wp.lock();//获得一个sharedPtr 计数增加
        //assert(wp.use_count() == 2);
    }
    
    //assert(wp.use_count() == 1);
    
    
    //-------------
    cout<<"test shared_ptr base usage:"<<endl;
    shared_ptr<string> p1 = make_shared<string>("");
    if(p1 && p1->empty())
        *p1 = "hello";
    
    auto p2 = make_shared<string>("world");
    cout<<*p1<<' '<<*p2<<endl;
    
    cout<<"test shared_ptr use_count:"<<endl;
    cout<<"p1 cnt:"<<p1.use_count()<<"\tp2 cnt:"<<p2.use_count()<<endl;
    
    auto p3 = p2;
    cout<<"p1 cnt:"<<p1.use_count()<<"\tp2 cnt:"<<p2.use_count()<<"\tp3 cnt:"<<p3.use_count()<<endl;
    p2 = p1;
    cout<<"p1 cnt:"<<p1.use_count()<<"\tp2 cnt:"<<p2.use_count()<<"\tp3 cnt:"<<p3.use_count()<<endl;

    cout<<"test shared_ptr reset:"<<endl;
    cout<<"p1 cnt:"<<p1.use_count()<<"\tp2 cnt:"<<p2.use_count()<<"\tp3 nt:"<<p3.use_count()<<endl;
    //shared_ptr可以通过reset方法重置指向另一个对象，此时原对象的引用计数减一。
    p1.reset(new string("cpp11"));
    cout<<"p1 cnt:"<<p1.use_count()<<"\tp2 cnt:"<<p2.use_count()<<"\tp3 cnt:"<<p3.use_count()<<endl;
    
    
    ///test game weak pointer
    MainCharacterPtr main = make_shared<MainCharacter>();
    
    {
        FollowObjectPtr follow = make_shared<FollowObject>();
        FollowObjectWeakPtr wpFollow(follow);
        main->SetFollow(wpFollow);
    }
    
    main->Update();
    
    
   
  
    return 0;
}
