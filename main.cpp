

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <fstream>
#include <iterator>
#include<unordered_map>
#include "plant.h"
using namespace std;


int main() {
    //ofstream file;
    string line;
    Plant newPlant;
    ifstream file;
    file.open("data.txt");
    unordered_map<string, Plant> data;
    //unordered_map<string, Plant> myGarden;
    vector<string> names;

    if (!file) {
        cout << "help";
    }
    else {
        while (getline(file, line))
        {
            char delimiter = ',';
            size_t pos = 0;
            string token;
            string token_states;
            // while ((pos = line.find(delimiter)) != std::string::npos) {

            pos = line.find(delimiter);
            token = line.substr(0, pos);

            newPlant.SetName(token);
            token_states = line.substr(pos + 1, line.length());

            newPlant.Setstates(token_states);

            data[token] = newPlant;



        }
        file.close();
    }




   unordered_set <Plant*> myGarden;
    

    cout << "Hello! Welcome to GreenThumb" << endl;

    bool end = false;

    while (end == false) {
        cout << endl<<"Menu:" << endl<<"--------------------"<<endl;
        cout << "1. Add a Plant" << endl << "2. View your garden" << endl << "3. View water log" <<endl<< "4. Exit"<<endl;
        cout << "What would you like to do?" << endl;

        int usr;
        cin >> usr;

        switch (usr) {
            case 1: 
            {
                cout << "What plant would you like to add?" << endl;
                string name;
                cin >> name;
                if (data.count(name) != 0) {
                    char ans;

                    Plant accessed = data[name];
                    Plant copy = accessed;
                    Plant* current = new Plant();
                    current = &copy;
                    string nn;

                  
                        cout << "Great! What would you like to name your "<< name<<" ?"<<endl;
                        
                        cin >> nn;
                        current->SetnickName(nn);

                        cout << "Would you like to add notes on your plant (y/n)?" << endl;
                   /*
                        cin >> ans;

                        if (ans == 'y') {
                            cout << "What notes would you like to add?" << endl;
                            string notes;
                            cin >> notes;
                            current.Setnotes(notes);
                        }*/
                    
                    cout << "Are you sure you want to add " << nn << " into your garden (y/n)?" << endl;

                    cin >> ans;
                    if (ans == 'y') {

                       // myGarden[nn] = current;
                      myGarden.insert(current);
                      names.push_back(nn);
                        cout << "Your new plant " << nn << " has been successfully added!" << endl;

                    }
                    

                }
                else {
                    cout << "There is no plant by that name." << endl;
                }
                break;
            }
        
            case 2:
            {
                cout << endl<<endl<<"Your Garden: "<<endl<<"--------------------" << endl<<endl;
                for (int i = 0; i < names.size(); i++) {
                    cout << names.at(i) << endl;
                }

                cout << endl << "What plant would you like to see?" << endl;
                string pname;
                cin >> pname;

                unordered_set<Plant*>::iterator itr;
               // Plant found = myGarden[pname];
                Plant* found = NULL;

               for (itr = myGarden.begin(); itr != myGarden.end(); itr++) {
                    Plant* current = *itr;
                    string currentName = current->GetnickName();

                    if (currentName == pname) {
                        found = current;
                    }
                }

                cout <<endl<< "Name: " << found->GetnickName() << endl << "Scientific Name: " << found->GetName() << endl << "Your plant will grow best in the following states: " << endl;
                cout << found->Getstates() << endl << "Notes: " << found->Getnotes() << endl;


                
                /*cout << "Would you like to add notes on your plant (y/n)?" << endl;
                char ans;
                cin >> ans;

               if (ans == 'y') {
                    cout << "What notes would you like to add?" << endl;
                    string notes;
                    cin >> notes;
                    found.Setnotes(notes);
                } */

                break;
            }

            case 3:
            {
                cout << "Welcome to your watering tracker!" << endl << "Would you like to: " << endl << "1. Track a new watering" << endl << " 2. View your log" << endl;
                int usr;
                cin >> usr;

                if (usr == 1) {
                    string fullString = "";
                    cout << "What day of the week is it?" << endl;
                    string day;
                    cin >> day;
                    fullString += day;
                    fullString += ", ";

                    cout << "What date is it?" << endl;
                    string date;
                    cin >> date;
                    fullString += date;
                    fullString += ", ";

                    cout << "What time is it?" << endl;
                    string time;
                    getline(cin, time);
                    fullString += time;

                    cout << "Would you like to track \" " << fullString << "\" in your watering log (y/n)?" << endl;
                    char input;
                    cin >> input;
                    if (input == 'y') {
                        //add to structure
                        cout << "watering has been tracked!" << endl;
                    }

                }



                break;
            }

            case 4:
            {
                cout << "Goodbye!";
                end = true;
                break;
            }

        }



       




    }

    
}

