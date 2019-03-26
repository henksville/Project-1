//
//  User.cpp
//  Final Project
//
//  Created by Ore Runsewe on 5/6/18.
//  Copyright © 2018 Ore Runsewe. All rights reserved.
//

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
