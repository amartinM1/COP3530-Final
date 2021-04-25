

//
// Created by alexi on 4/16/2021.
//
#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Plant {

private:
    string nickName = " ";
    string Name = " ";
    string notes = " ";
    string states = " ";
    //int val = 0;
    
public:
    Plant();
    string GetnickName();
    string GetName();
    string Getnotes();
    string Getstates();
   // int GetVal();
    void SetnickName(string nickName);
    void SetName(string Name);
    void Setnotes(string notes);
    void Setstates(string states);
   // void SetVal(string name);

};

Plant::Plant() {
    this->nickName = nickName;
    this->Name = Name;
    this->notes = notes;
    this->states = states;
}

string Plant::GetnickName() {

    return nickName;
}
string Plant::GetName() {
    return Name;
}
string Plant::Getnotes() {
    return notes;
}
string Plant::Getstates() {
    return states;
}

/*int Plant::GetVal() {
   
    if (val == NULL) {

        return 0;
    }
    return val;
}*/
void Plant::SetnickName(string nickName) {
    this->nickName = nickName;
}
void Plant::SetName(string Name) {

    this->Name = Name;
}
void Plant::Setnotes(string notes)
{
    this->notes = notes;
}
void Plant::Setstates(string states) {
    this->states = states;
}

/*void Plant::SetVal(string name) {
   // this->name = name;
    int total = 0;
    for (int i = 0; i < name.length(); i++) {
        total += int(name[i]);
    }
    this->val = total;
}*/
