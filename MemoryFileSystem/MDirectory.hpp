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
#include "MElement.hpp"
using namespace std;

class MDirectory: public MElement {
public:
    MElement* cd(const string& path);                       // return the pointer of an element by a path
    string ls();                                            // show all files and directories in this directory
    void rm(const string& path);                            // remove a file or a directory
    void touch(const string& path);                         // create a file in this directory
    void mkdir(const string& path);                         // make a new directory in this directory
    map<string, MElement*> getContainer();
    
    virtual string getName();                               // get the name of directory
    virtual int getSize();                                  // get the size of directory
    
    MDirectory(MDirectory* parent, const string& name);
    virtual ~MDirectory();
    
private:
    map<string, MElement*> m_container;
};

#endif /* MDirectory_hpp */
