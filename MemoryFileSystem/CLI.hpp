//
//  CLI.hpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#ifndef CLI_hpp
#define CLI_hpp

#include <iostream>
#include "MFileSystem.hpp"
using namespace std;

class CLI {
public:
    void run();
    CLI();
    ~CLI();
private:
    MFileSystem* m_file_system;
};

#endif /* CLI_hpp */
