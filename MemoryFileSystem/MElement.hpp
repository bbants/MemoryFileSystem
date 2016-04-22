//
//  MElement.hpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/22/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#ifndef MElement_hpp
#define MElement_hpp

#include <iostream>
using namespace std;

class MElement {
public:
    
    void setName(const string& name);
    void setCreateTime(const string& name);
    void setLastUpdateTime(const string& name);
    void setSize(const int& size);
    
    virtual string getName() = 0;
    virtual int getSize() = 0;
    string getCreateTime();
    string getLastUpdateTime();
    
    MElement(const string& name);
    virtual ~MElement();
    
protected:
    MElement* m_parent;
    string m_name;
    string m_create_time;
    string m_last_update_time;
    int m_size;
};


#endif /* MElement_hpp */

