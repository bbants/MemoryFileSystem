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
    string ls();
    string cat(const string& path);
    void cd(const string& path);
    void mkdir(const string& path);
    void touch(const string& path);
    void rm(const string& path);
    void write(const string& path, const string& content);
    
    MFileSystem();
    ~MFileSystem();
    
private:
    MDirectory* m_root_directory;
    MDirectory* m_cur_directory;
};

#endif /* MFileSystem_hpp */
