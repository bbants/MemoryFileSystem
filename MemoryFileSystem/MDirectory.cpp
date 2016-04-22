//
//  MDirectory.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "MDirectory.hpp"
#include <ctime>

MDirectory::MDirectory(MDirectory* parent, const string& name): MElement(name) {
    m_parent = parent;
}

MDirectory::~MDirectory() {
    for(auto p: m_container) {
        delete p.second;
    }
}

string MDirectory::getName() {
    return m_name + "/";
}

void MDirectory::mkdir(const string& path) {
    MDirectory* newDir = new MDirectory(this, path);
    m_container[newDir->getName()] = (MElement*)newDir;
}

string MDirectory::ls() {
    string result;
    for(auto p: m_container) {
        result += p.second->getLastUpdateTime()+ "  \t" + to_string(p.second->getSize()) + "  \t" + p.second->getName() + "\n";
    }
    return result;
}

void MDirectory::touch(const string& path) {
    MFile* newFile = new MFile(path);
    m_container[path] = (MElement*)newFile;
}

map<string, MElement*> MDirectory::getContainer() {
    return m_container;
}

void MDirectory::rm(const string& path) {
    delete m_container[path];
    m_container.erase(path);
}


MElement* MDirectory::cd(const string& path) {
    if(path == "") {
        return (MElement*)this;
    }
    int slash;
    for(slash=0; slash<path.length(); slash++) {
        if(path[slash] == '/') {
            break;
        }
    }
    string curPath = path.substr(0, slash+1);
    if(curPath == "../") {
        // go to parent directory
        string remainPath = path.substr(slash+1, path.length()-slash);
        return ((MDirectory*)m_parent)->cd(remainPath);
    } else if(m_container.find(curPath) != m_container.end()) {
        // check if the cur path exists
        if(slash == path.length()) {
            // reach a file
            return m_container[curPath];
        }else {
            // reach a directory
            string remainPath = path.substr(slash+1, path.length()-slash-1);
            return ((MDirectory*)m_container[curPath])->cd(remainPath);
        }
    }
    return NULL;
}

int MDirectory::getSize() {
    int size = 0;
    for(auto p: m_container) {
        size += p.second->getSize();
    }
    return size;
}