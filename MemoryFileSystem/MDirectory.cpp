//
//  MDirectory.cpp
//  MemoryFileSystem
//
//  Created by Hiukin on 4/21/16.
//  Copyright © 2016 Hiukin. All rights reserved.
//

#include "MDirectory.hpp"

MDirectory::MDirectory(MDirectory* parent, const string& name, const int& permission) {
    m_parent = parent;
    m_directory_name = name;
    m_permission = permission;
}

MDirectory::~MDirectory() {
}

string MDirectory::getDirectoryName() {
    return m_directory_name + "/";
}

void MDirectory::mkdir(const string& path) {
    MDirectory* newDir = new MDirectory(this, path);
    m_directory_container[path] = newDir;
}

string MDirectory::ls() {
    string result;
    for(auto p: m_directory_container) {
        result += p.second->getDirectoryName() + "\n";
    }
    for(auto p: m_file_container) {
        result += p.second->getName() + "\n";
    }
    return result;
}

void MDirectory::touch(const string& path) {
    MFile* newFile = new MFile(path);
    m_file_container[path] = newFile;
}

// output the content of a file
string MDirectory::cat(const string& path) {
    if(m_file_container.find(path) != m_file_container.end()) {
        return m_file_container[path]->cat();
    } else {
        // to do
        // throw an error
        return "";
    }
}

// write some content to a file
void MDirectory::write(const string& path, const string& content) {
    if(m_file_container.find(path) != m_file_container.end()) {
        m_file_container[path]->write(content);
    }
}

MDirectory* MDirectory::cd(const string& path) {
    if(path == "") {
        return this;
    }
    int slash = path.find_first_of('/');
    string curPath = path.substr(0, slash);
    if(curPath == "..") {
        // go to parent directory
        string remainPath = path.substr(slash+1, path.length()-slash-1);
        return m_parent->cd(remainPath);
    } else if(m_directory_container.find(curPath) != m_directory_container.end()) {    // check if the cur path exists
        if(slash == path.length() - 1) {        // reach the last path
            return m_directory_container[curPath];
        }else {
            string remainPath = path.substr(slash+1, path.length()-slash-1);
            return m_directory_container[curPath]->cd(remainPath);
        }
    }
    return NULL;
}