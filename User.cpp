// Created by Henry Odunze
//  User.cpp
//  Final Project
//  Copyright © 2018 Odunze Henry. All rights reserved.


#include "user.h"

#include <iostream>
#include <string>

using namespace std;

void User::SetUserName(string name) {
    userName = name;
}
string User::GetUserName() {
    return userName;
}
