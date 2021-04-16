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
    string nickName=" ";
    string Name=" ";
    string notes=" ";
    string states=" ";
public:
    string GetnickName();
    string GetName();
    string Getnotes();
    string Getstates();
    void SetnickName(string nickName);
    void SetName(string Name);
    void Setnotes(string notes);
    void Setstates(string states);

};
string Plant::GetnickName(){

    return nickName;
}
string Plant::GetName(){
    return Name;
}
string Plant::Getnotes(){
    return notes;
}
string Plant::Getstates(){
    return states;
}
void Plant::SetnickName(string nickName){
    this->nickName=nickName;
}
void Plant::SetName(string Name){

    this->Name=Name;
}
void Plant::Setnotes(string notes)
{
    this->notes=notes;
}
void Plant::Setstates(string states){
    this->states=states;
}