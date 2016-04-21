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
    MDirectory* cd(string path);            // return the pointer of a directory by a path
    string ls();                            // show all files and directories in this directory
    void rm(string path);                   // remove a file or a directory
    void chmod(int permission);             // change the permission
    string pwd();                           // return the path of this directory
    void touch(string file_name);           // create a file in this directory
    
private:
    string m_directory_name;
    string m_create_time;
    int m_permission;
    MDirectory* m_parent;
    map<string, MDirectory*> m_directory_container;
    map<string, MFile*> m_file_container;
};

#endif /* MDirectory_hpp */
