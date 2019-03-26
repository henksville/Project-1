// Created by Henry Odunze
//  User.h
//  Final Project
//  Copyright © 2018 Odunze Henry. All rights reserved.


#ifndef user_h
#define user_h

#include <iostream>
#include <string>

using namespace std;

class User {
    public:
    void SetUserName(string name);
        string GetUserName();
    private:
        string userName;
};

#endif /* user_h */
