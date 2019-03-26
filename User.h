//
//  user.h
//  Final Project
//
//  Created by Ore Runsewe on 5/6/18.
//  Copyright © 2018 Ore Runsewe. All rights reserved.
//

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
