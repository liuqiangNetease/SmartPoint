//
//  MainCharacter.h
//  SmartPoint
//
//  Created by liuqiang on 2018/9/12.
//  Copyright © 2018年 liuqiang. All rights reserved.
//

#ifndef MainCharacter_h
#define MainCharacter_h
#include <iostream>
#include <memory>
#include <vector>
#include "FollowObject.h"
class MainCharacter
{
public:
    MainCharacter()
    {
        printf("MainCharacter()\n");
    }
    ~MainCharacter()
    {
        printf("~MainCharactor() \n");
    }
    void SetFollow(FollowObjectWeakPtr object)  { m_ptrFollow = object;}
    void Update()
    {
        if(m_ptrFollow.expired() == false)
        {
            FollowObjectPtr follow = m_ptrFollow.lock();
            follow->GetPosition();
        }
        else
        {
            printf("weakpoint expired!\n");
        }
        
       
    }
    FollowObjectWeakPtr m_ptrFollow;
    
    
};

typedef std::shared_ptr<MainCharacter> MainCharacterPtr;

#endif /* MainCharacter_h */
