//
//  FollowObject.h
//  SmartPoint
//
//  Created by liuqiang on 2018/9/12.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef FollowObject_h
#define FollowObject_h
#include <iostream>
#include <memory>
#include <vector>

struct Vector3
{
    float x, y, z;
};
class FollowObject
{
public:
    FollowObject()
    {
        printf("FollowObject()\n");
        Vector3 pos{1,0,0};
        m_vPos = pos;
    }
    ~FollowObject()
    {
        printf("~FollowObject()\n");
    }
    Vector3 GetPosition()  {  return m_vPos;}
    
    Vector3 m_vPos;
};

typedef std::shared_ptr<FollowObject>  FollowObjectPtr;
typedef std:: weak_ptr<FollowObject>   FollowObjectWeakPtr;
#endif /* FollowObject_h */
