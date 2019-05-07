//
// Created by prajwal on 5/4/19.
//

#ifndef CHEATERS_HASH_H
#define CHEATERS_HASH_H
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Hash_312{
private:
    static const int TABLESIZE = 100005;
    static const int FILESIZE = 100;

    struct fileIndex{     //Linked list will get stored inside the hashtable which contains index no. of file and next pointer
        int fileNum;
        fileIndex* next;
    };

    fileIndex* hashTable[TABLESIZE];
    int countTable[FILESIZE][FILESIZE];

public:
    //default constructor to make hashtable
    //fill hashTable with null pointers
    Hash_312();


// funtion Hash
//  takes string as input
//  returns index of the Hash table

    int hash(const string &key);

// funtion insertItem
//  takes string as input
//  output - none
    void insertItem(const string &key, int fileNum);


//function countSimilarItems
//counts the files which are similar in some contents
//input parameters - file size and vector of files
//prints the files with similar contents
//output - none
    void countSimilarItems(int fileSize, vector<string> &files, int minCheating);

//Destructor
//deletes all the linked list from each row of the hash table
    ~Hash_312();

};


#endif //CHEATERS_HASH_H
