


#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include "plant.h"
//#include "unordered_set.cpp"
using namespace std;


class BST {
    struct node {
        Plant plant;
        node* left;
        node* right;
    };

    node* root;


    node* insert(Plant plant, node* root) {
        if (root == NULL) {
            root = new node;
            root->plant = plant;
            root->left = NULL;
            root->right = NULL;

            return root;
        }

        string Rstring = root->plant.GetName();
        int totalR = 0;
        for (int i = 0; i < Rstring.length(); i++) {
            totalR += int(Rstring[i]);
        }

        string Pstring = plant.GetName();
        int totalP = 0;
        for (int i = 0; i < Pstring.length(); i++) {
            totalP += int(Pstring[i]);
        }
        if (totalP < totalR) {
            root->left = insert(plant, root->left);
        }
        else {
            root->right = insert(plant, root->right);
        }

        return root;
    }

    node* search(node* root, string name) {
        int total = 0;
        for (int i = 0; i < name.length(); i++) {
            total += int(name[i]);
        }

        if (root == NULL) {
            return NULL;
        }

        string Rstring = root->plant.GetName();
        int totalR = 0;
        for (int i = 0; i < Rstring.length(); i++) {
            totalR += int(Rstring[i]);
        }

        if (total < totalR) {
            return search(root->left, name);
        }
        else if (total > totalR) {
            return search(root->right, name);
        }
        else {
            return root;
        }


    }


public:
    BST() {
        root = NULL;
       
        
    }

    void insert(Plant plant) {
        root = insert(plant, root);
    }

    Plant search(string name) {
        root = search(root, name);
        Plant val = root->plant;
        return val;
    }
};


class unorderedSet {
private:
    //
public:
    //int buckets=10177;
    int buckets;
    int Size;
    // int *table[];
    list<Plant>* table;

    unorderedSet() {
        //a TA suggested we should make th ebucket size a larger prime number
        this->buckets = 30001;
        table = new list<Plant>[buckets];
        this->Size = 0;
        //unorderedSet *table= new table[10177];
    }

    int hashFunction(string name) {
        //string name = val.GetnickName();
        int total = 0;
        for (int i = 0; i < name.length(); i++) {
            total += int(name[i]);
        }
        int hash = total % buckets;
        return hash;
    }

    bool has(string Value) {
        int index = hashFunction(Value);
        for (auto itr = table[index].begin(); itr != table[index].end(); ++itr)
        {
            if (itr->GetnickName() == Value) {
                return true;
            }
        }
        return false;
    }

    Plant find(string Value) {
        //user is trying to access a plant from the garden by using a nickname              
        //string name = val.GetnickName(); 

        int index = hashFunction(Value);
        Plant empty;
        empty.SetnickName("empty");
        //determine which container is holding all of the plants in the garden

        std::list<Plant>::iterator it;

        for (it = table[index].begin(); it != table[index].end(); ++it)
        {
            string name = it->GetnickName();
            if (name == Value) {
                return *it;

            }
            //return empty;
        }
        return empty;
    }

    void insert(Plant Value) {
        string name = Value.GetnickName();
        if (!has(name)) {
            int index = hashFunction(name);
            table[index].push_back(Value);
            Size++;
        }
        // int index=hashFunction(val);
         // table[index].push_back(val);
              //you need to handle duplicate insertions and track size

    }

    ////I used this site to resolve my remove function errors: https://www.geeksforgeeks.org/c-program-hashing-chaining/
    //void rem(int val) {
    //    int index = hashFunction(val);
    //    auto itr = table[index].begin();
    //    for (; itr != table[index].end(); ++itr)
    //    {
    //        if (*itr == val) {
    //            // table[index].erase(itr);
    //                // table[index].erase(itr);
    //            break;

    //        }
    //    }
    //    if (itr != table[index].end()) {
    //        table[index].erase(itr);
    //        Size--;
    //    }
    //}

    int size() {

        return Size;
    }
};





int main() {
    //ofstream file;
    string line;
    Plant newPlant;
    ifstream file;
    file.open("data.txt");
    BST data;
    
    //unordered_map<string, Plant> data;
   //unordered_map<string, Plant> myGarden;
    vector<string> names;
    vector<string> waterLog;

    int counter = 0;
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

            int total = 0;
            for (int i = 0; i < token.length(); i++) {
                total += int(token[i]);
            }

            data.insert(newPlant);
           


        }
        file.close();
    }




   unorderedSet myGarden;
    

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

                int total = 0;
                for (int i = 0; i < name.length(); i++) {
                    total += int(name[i]);
                }

                char ans;
                    Plant current = data.search(name);
   
                    string nn;

                  
                        cout << "Great! What would you like to name your "<< name<<" ?"<<endl;
                        
                        cin >> nn;
                        current.SetnickName(nn);

                        /*cout << "Would you like to add notes on your plant (y/n)?" << endl;
                   
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

               // unordered_set<Plant*>::iterator itr;
               //// Plant found = myGarden[pname];
               // Plant* found = NULL;

               //for (itr = myGarden.begin(); itr != myGarden.end(); itr++) {
               //     Plant* current = *itr;
               //     string currentName = current->GetnickName();

               //     if (currentName == pname) {
               //         found = current;
               //     }
               // }

                Plant found = myGarden.find(pname);

                cout <<endl<< "Name: " << found.GetnickName() << endl << "Scientific Name: " << found.GetName() << endl << "Your plant will grow best in the following states: " << endl;
                cout << found.Getstates() << endl;


                
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
                cout << "Welcome to your watering tracker!" << endl << "Would you like to: " << endl << "1. Track a new watering" << endl << "2. View your log" << endl;
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
                    cin>>time;
                    fullString += time;
                    fullString += ", ";

                    cout << "What plants are you watering?" << endl;
                    string plants;
                    cin>>plants;
                    fullString += plants;

                    cout << "Would you like to track \" " << fullString << "\" in your watering log (y/n)?" << endl;
                    char input;
                    cin >> input;
                    if (input == 'y') {
                        waterLog.push_back(fullString);
                        cout << "watering has been tracked!" << endl;
                    }

                }

                if (usr == 2) {
                    cout << "Watering Log"<<endl<<"----------------"<<endl;
                    for (int i = 0; i < waterLog.size(); i++) {
                        cout << waterLog[i] << endl;
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


