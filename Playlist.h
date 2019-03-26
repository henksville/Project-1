// Created by Henry Odunze
//  Playlist.h
//  Final Project
//  Copyright © 2018 Odunze Henry. All rights reserved.


#ifndef Playlist_h
#define Playlist_h

#include <iostream>
#include <string>

#include "Sort.h"

using namespace std;

struct SONG {
    string title;
    string genre;
    string duration;
    string artist;
    int likes;
};

struct NODE {
    SONG song;
    NODE *next;
    NODE *previous;
};

class Playlist {
public:
    Playlist(NODE *listHead = NULL, NODE *listTail = NULL);
    ~Playlist();
    void Append(string val1, string val2, string val3, string val4, int val5);
    void Print();
    int NumOfSongs();
    int NumOfLikes();
    NODE *head;
    NODE *tail;
private:
    int size;
};


#endif /* Playlist_h */
