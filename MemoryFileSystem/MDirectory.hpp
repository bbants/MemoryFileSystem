//
//  MDirectory.hpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#ifndef MDirectory_hpp
#define MDirectory_hpp

#include <iostream>
#include <map>
#include "MFile.hpp"
using namespace std;

class MDirectory {
public:
    MDirectory* cd(const string& path);                     // return the pointer of a directory by a path
    string ls();                                            // show all files and directories in this directory
    void rm(const string& path);                            // remove a file or a directory
    string getDirectoryName();                              // get the name of this directory
    string getTime();                                       // get create time of the directory
    string cat(const string& path);                         // output the content of a file
    void touch(const string& path);                         // create a file in this directory
    void mkdir(const string& path);                         // make a new directory in this directory
    void write(const string& path, const string& content);  // write something to a file
    
    MDirectory(MDirectory* parent, const string& name);
    ~MDirectory();
    
private:
    string m_directory_name;
    string m_create_time;
    MDirectory* m_parent;
    map<string, MDirectory*> m_directory_container;
    map<string, MFile*> m_file_container;
};

#endif /* MDirectory_hpp */
