//
//  main.cpp
//  Final Project
//
//  Created by Ore Runsewe on 5/5/18.
//  Copyright © 2018 Ore Runsewe. All rights reserved.


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

#include "user.h"
#include "Playlist.h"
#include "Sort.h"

/* int *arrayNumOfLikes(int arraySize);

int *arrayNumOfLikes(int arraySize) {
    int *array [arraySize];
    NODE *temp = new NODE;
    int i =0;
    
    while (temp->next != NULL) {
        array[i] = &temp->song.likes;
        temp = temp->next;
    }
    
    return *array;
} */




int main () {
    ifstream inFS, inFS2;
    
    int option = 0;
    string uName;
    string studentName, songTitle, songGenre, songDuration, songArtiste;
    int songLikes;
    User User1;
    Playlist Playlist1, Playlist2;
    // srand(time(0));
    
    
    
    
    cout << "Enter your name: ";
    getline(cin, uName);
    cout << endl;
    User1.SetUserName(uName);
    cout << "User's name is " << User1.GetUserName() << endl << endl;
    
    cout << "Menu: " << endl << "1. Load & name playlist" << endl << "2. Play playlist" << endl << "3. Update user information" << endl << "4. Add Song to playlist" << endl << "5. Quit" << endl << endl;
    

    cout << "Enter a choice number: ";
    cin >> option;
    

    while (option != 5) {
        switch (option) {
            case 1: {
                // cout << "Opening file \"playlist.txt\"" << endl;
                inFS.open("playlist.txt");
                
                while (!inFS.eof()) {
                    
                    getline(inFS, studentName, '\t');
                    getline(inFS, songArtiste, '\t');
                    getline(inFS, songTitle, '\t');
                    getline(inFS, songDuration, '\t');
                    getline(inFS, songGenre, '\n');
                    
                    songLikes = (rand() % 100) + 1;
                    Playlist1.Append(songTitle, songGenre, songDuration, songArtiste, songLikes);
                }
                inFS.close();
                
                int arrSize = Playlist1.NumOfSongs();
                int arr[arrSize];
                int x = 0;
                NODE *temp = Playlist1.head;
                while (temp != NULL) {
                    arr[x] = temp->song.likes;
                    cout << arr[x] << endl;
                    temp = temp->next;
                    x++;
                }
               
                Sort::MergeSort(arr, 0, arrSize-1);
                // Sort::InsertionSort(arr, arrSize);
                // Sort::SelectionSort(arr, arrSize);
                cout << "MERGE SORT: ";
                for(int i = 0; i < arrSize; ++i) {                       //To print sorted int array
                    cout << arr[i] << " ";
                }
                cout << endl;
                
                int p = 0;
                NODE* temp2 = Playlist1.head;
                while (p < arrSize) {
                    while (temp2 != NULL) {
                        if (arr[p] == temp2->song.likes) {
                            Playlist2.Append(temp2->song.title, temp2->song.genre, temp2->song.duration, temp2->song.artist, temp2->song.likes);
                            //temp2->previous->next = temp2->next;
                            //delete temp2;
                        }
                        temp2 = temp2->next;
                    }
                    p += 1;
                }
                
                Playlist1.Print();
                Playlist2.Print();
                break;
            }
                
            case 2: {
                
                // Playlist1.Print();
                Playlist2.Print();
                break;
            }
        
            case 3: {
                cout << "Re-enter your name: ";
                // cin.ignore(256, '\n');
                cin.ignore();                                                       // This line removes the newline character that interfers with the cin buffer
                getline(cin, uName);
                User1.SetUserName(uName);
                break;
            }
            case 4: {
                cout << "Enter the name of the song: ";
                cin >> songTitle;
                cout << "Enter the song genre: ";
                cin >> songGenre;
                cout << "Enter the length of the song: ";
                cin >> songDuration;
                cout << "Enter Artiste's name: ";
                cin >> songArtiste;
                cout << "Enter the number of likes on the song: ";
                cin >> songLikes;
                cout << endl;
                Playlist1.Append(songTitle, songGenre, songDuration, songArtiste, songLikes);
                break;
            }
            case 5: {
                Playlist1.~Playlist();
                break;
            }
            default: {
                cout << "Option number not in menu. Please choose another number." << endl;
                cout << "Choose another number: ";
                cin >> option;
                break;
            }
        }
        
        cout << endl;
        cout << "Menu: " << endl << "1. Load & name playlist" << endl << "2. Play playlist" << endl << "3. Update user information" << endl << "4. Add Song to playlist" << endl << "5. Quit" << endl << endl;
        cout << "Enter a choice number: ";
        cin >> option;
    }
    
    //Playlist1.Print();
    
    cout << User1.GetUserName();
    
    return 0;
    }