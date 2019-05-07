#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>


#include "hash.h"


using namespace std;

void populateHashTable(const string &checkFiles, int index, vector<string> &files, Hash_312 &h, int numChunks);

int getdir (string dir, vector<string> &files);


int main() {                                    //int argc, char* argv[]

    string dir = string("sm_doc_set");          //argv[1]
    int numChunks = 6;                          //argv[2]
    int minCheating = 200;                      //argv[3]
    vector<string> files = vector<string>();

    getdir(dir, files);

    Hash_312 h;

    for (unsigned int i = 2; i < files.size(); i++) {
       // cout << i << " " << files[i] << endl;
            populateHashTable(files[i], i, files, h, numChunks);

    }

    h.countSimilarItems(files.size(), files, minCheating);

    return 0;

}

int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

//function populateHashTable
//populates the hashtable by hashing the key of chunk of words of file
//counts the similar files and prints them out
//input parameter - file, index of the file, files size, and vetor of files.
//output - none
void populateHashTable(const string &checkFiles,  int index, vector<string> &files, Hash_312 &h, int numChunks) {

    fstream file;
    string word;
    vector<char> std_word;
    string filename;
    string temp;
    string word1;
    queue<string> chunk_word;
    queue<string> temp_queue;

    filename = checkFiles;
    file.open(filename.c_str());
    int num = 0;

    while (file >> word) {

        for (int i = 0; i < word.size(); i++) {
            if (isalnum(word[i])) {
                std_word.push_back(word[i]);
            }
        }
        for (vector<char>::iterator it = std_word.begin(); it != std_word.end(); it++) {   //change word to lowercase
            *it = tolower(*it);
        }
        if (num < 6) {                                //start by making chunk of first six words
            chunk_word.push(string(std_word.begin(), std_word.end()));
            temp = temp + string(std_word.begin(), std_word.end());

            std_word.clear();
            num++;

            if (num == numChunks) {                          //first chunk of six words
                h.insertItem(temp, index);
            }
        } else {
            temp = "";
            chunk_word.pop();                       //using queue to add and remove words
            chunk_word.push(string(std_word.begin(), std_word.end()));
            std_word.clear();
            temp_queue = chunk_word;

            while (!chunk_word.empty()) {
                temp = temp + chunk_word.front();
                chunk_word.pop();
            }


            h.insertItem(temp, index);

            chunk_word = temp_queue;

        }
    }

}




