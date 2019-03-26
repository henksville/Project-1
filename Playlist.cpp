//
//  Playlist.cpp
//  Final Project
//
//  Created by Ore Runsewe on 5/6/18.
//  Copyright © 2018 Ore Runsewe. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"

Playlist::Playlist(NODE *listHead, NODE *listTail) {
    this->head = listHead;
    this->tail = listTail;
}

Playlist::~Playlist() {
    NODE *temp = new NODE;
    temp = head;
    while (temp != NULL) {
        delete temp;
        temp = temp->next;
    }
}

void Playlist::Append(string val1, string val2, string val3, string val4, int val5) {
    NODE *temp = new NODE;
    temp->song.title = val1;
    temp->song.genre = val2;
    temp->song.duration = val3;
    temp->song.artist = val4;
    temp->song.likes = val5;
    
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp->next = NULL;
    }
    else {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
}

int Playlist::NumOfSongs() {
    int x = 0;
    NODE *temp = new NODE;
    temp = head;
    while (temp != NULL) {
        temp = temp->next;
        x+=1;
}
    return x;
}

int Playlist::NumOfLikes() {
    int x = 0;
    NODE *temp = new NODE;
    x = temp->song.likes;
    return x;
}
    
void Playlist::Print() {
    int x = 0;
    NODE *temp = new NODE;
    temp = head;
    while (temp != NULL) {
        cout << x+1 << ". \"" << temp->song.title << "\"" << " by " << temp->song.artist << " with a genre of " << temp->song.genre << ", duration of " << temp->song.duration << " and " << temp->song.likes << " likes. " << endl;
        temp = temp->next;
        x+=1;
    }
    
}




