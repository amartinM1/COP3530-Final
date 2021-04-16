#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <fstream>
#include<unordered_map>
#include "plant.h"
using namespace std;


int main(){

//ofstream file;
cout<<"hello!";
    string line;
    Plant newPlant;
    ifstream file;
    file.open("C:\\Users\\alexi\\CLionProjects\\FinalProject\\data.txt");
    unordered_map<string, Plant> data;

    if(!file){
        cout<<"help";
    }
    else{
        while ( getline (file,line) )
        {
            char delimiter=',';
            size_t pos = 0;
            string token;
            string token_states;
           // while ((pos = line.find(delimiter)) != std::string::npos) {

                pos = line.find(delimiter);
                token = line.substr(0, pos);

                newPlant.SetName(token);
                token_states = line.substr(pos+1, line.length());

                newPlant.Setstates(token_states);

                data[token]=newPlant;



        }
        file.close();
    }

   Plant check=data["abelia"];
    cout<<check.Getstates();
    cout<<data.size()<<endl;
    //cout<<newPlant.GetName();
   // cout<<newPlant.Getstates();
}
