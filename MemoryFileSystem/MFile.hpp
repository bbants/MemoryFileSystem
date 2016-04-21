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
using namespace std;

class MFile {
public:
    string getName();
    string cat();
    void write(const string& content);
    
    MFile(const string& path);
    ~MFile();
private:
    string m_name;
    string m_crtime;
    string m_content;
};

#endif /* MFile_hpp */
