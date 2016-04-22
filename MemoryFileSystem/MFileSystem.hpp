//
//  MFileSystem.hpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#ifndef MFileSystem_hpp
#define MFileSystem_hpp

#include <iostream>
#include "MDirectory.hpp"
using namespace std;

class MFileSystem {
public:
    string getCurrentDirectory();
    string ls();                                            // show the files and directories in the current directory
    string cat(const string& path);                         // output the content of a file
    void cd(const string& path);                            // go to a path
    void mkdir(const string& path);                         // create a new directory
    void touch(const string& path);                         // create a new file
    void rm(const string& path);                            // remove a file or a directory
    void write(const string& path, const string& content);  // write something to a file
    
    MFileSystem();
    ~MFileSystem();
    
private:
    MDirectory* m_root_directory;
    MDirectory* m_cur_directory;
};

#endif /* MFileSystem_hpp */
