//
// Created by prajwal on 5/4/19.
//
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <math.h>


#include "hash.h"

//default constructor
//fill the hash table with NULL pointers
Hash_312:: Hash_312(){
//hashTable = new fileIndex* [TABLESIZE];

for (int i = 0; i< TABLESIZE; i++){
    hashTable[i] = NULL;
}
}

//function hash
//input parameter - string key
//output parameter - int index
int Hash_312:: hash(const string &key){
    unsigned int sum = 0;
    int index;

for (int i = 0; i < key.length()-1; i++){
    sum = sum + (int)key[key.length()-i-1]* pow(37,i);
}

return sum % TABLESIZE;
}


//funtion insertItem
//input parameter - string key and file index number
//output - none
void Hash_312:: insertItem(const string &key, int fileNum){
   // cout << key<< endl;

    int index = hash(key);

   // cout << index<< endl;

    if (hashTable[index] ==  NULL){

        fileIndex* newfileIndex = new fileIndex;
        newfileIndex -> fileNum = fileNum;
        newfileIndex -> next = NULL;
        hashTable[index] = newfileIndex;

    }else{

        fileIndex* newfileIndex = new fileIndex;
        newfileIndex -> fileNum = fileNum;
        newfileIndex->next = NULL;

        fileIndex* ptr = hashTable[index];
        while (ptr->next != NULL){
          //  cout << fileNum << ptr->fileNum<< endl;
            countTable[fileNum][ptr->fileNum]++;
            ptr = ptr->next;
        }
        countTable[fileNum][ptr->fileNum]++;

        ptr->next = newfileIndex;
    }

}

//function countSimilarItems
//counts the files which are similar in some contents
//input parameters - file size and vector of files
//prints the files with similar contents
//output - none
void Hash_312::countSimilarItems(int fileSize, vector<string> &files){
    cout << fileSize<< endl;
    for (int i = 2; i < fileSize; i++){
        for (int j = 2; j < fileSize; j++){
          //  cout << countTable[i][j];
        }
        cout<<endl;
    }

    for (int i = 2; i < fileSize; i++){
    for (int j = 2; j < fileSize; j++){
        if ((countTable[i][j]) > 200 && (i != j)){
            cout << countTable[i][j] << " " << files[i] << " "<< files[j]<< endl;
        }
    }
    cout<<endl;
}

};

//Destructor
//deletes all the linked list from each row of the hash table
Hash_312:: ~Hash_312(){

    for (int i = 0; i < TABLESIZE; i ++){
        fileIndex *prevptr = NULL;
        fileIndex *ptr = hashTable[i];
        while(ptr != NULL){
            prevptr = ptr;
            ptr = ptr->next;
            delete prevptr;
        }

    }


}













