//
//  MFile.hpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#ifndef MFile_hpp
#define MFile_hpp

#include<iostream>
#include "MElement.hpp"
using namespace std;

class MFile:public MElement {
public:
    string cat();
    void write(const string& content);
    
    virtual string getName();
    virtual int getSize();
    
    MFile(const string& path);
    ~MFile();
private:
    string m_content;
};

#endif /* MFile_hpp */
