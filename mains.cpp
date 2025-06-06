#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream> 
#include <cctype>
#include <sstream>
#include <map>

using namespace std;

void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
} //when user enter, this function will end

string Question[10] = {
        "Which do you think is the most effective way to reduce energy consumption at home?", 
        "What eco-friendly transport method do you prefer?", 
        "Which of the following sustainable habits do you practice regularly?", 
        "How important are urban green spaces to you?", 
        "Which smart technology do you think is most effective in creating sustainability?", 
        "What would motivate you to adopt smart living solutions at home?", 
        "What do you think is the biggest challenge in transitioning to green cities?", 
        "Which emerging smart technology do you think will have the biggest impact on sustainable urban living in the next decade?", 
        "What initiatives do you think would encourage more public involvement in green city projects?", 
        "Which personal action do you think has the most impact on creating a sustainable city?"
    };  //question

    string abc[10]={
        "A. Bicycle \nB. Hybrid vehicle \nC. Electric vehicle \nD. Electric Public transport",
        "A. Bicycle \nB. Hybrid vehicle \nC. Electric vehicle \nD. Electric Public transport",
        "A. Recycling\nB. Energy conservation \nC. Using public transport \nD. None",
        "A. Very important\nB. Somewhat important \nC. Not important \nD. No opinion",
        "A. Smart grids for renewable energy \nB. Green buildings with energy-efficient design \nC. Electric and autonomous transportation \nD. IoT-based waste management",
        "A. Cost saving \nB. Environmental benefit \nC. Convenience and automation \nD. Government incentives",
        "A. High Cost \nB. Infrastructure limitation \nC. Lack of public participation \nD. Policy restriction",
        "A. AI-driven energy optimization \nB. Smart water management systems \nC. Autonomous electric transport \nD. Circular economy innovations",
        "A. Government-funded awareness campaigns \nB. Incentives for eco-friendly practices \nC. Smart city technology demonstrations \nD. Local sustainability workshops",
        "A. Switching to renewable energy sources \nB. Using eco-friendly transportation options \nC. Reducing household waste and consumption \nD. Advocating for sustainable urban policies"
    }; // choices for each question
    
class admin{
    string id = "S001"; //admin id
    string password = "A123"; //admin pass
    string ids;
    string pass; //to verify admin
    bool logs;

    string texts;
    string abcd;  
    int QNo;
    string name; //used to display responses

    public:
    bool login();
    void analysis();
    void menu();
    void viewresponses();
};

void admin::menu(){
  char option;
  while(true){
  system("clear");
  cout << "Welcome Back Admin.\n\n";
  cout<<"1. View Analyzed Data"<<endl;
  cout<<"2. View Respondent Data"<<endl;
  cout<<"3. Logout\n"<<endl;
  cout<<"select the option from above: ";
  cin>>option; //used to store user select option

  while (option != '1' and option != '2' and option != '3'){
    cout << "Invalid input! Please input again: ";
    cin>>option;
  } //if user input option wasn't 1 2 3, the while loop will keep looping

  if(option == '1'){
    analysis();
  }
  else if(option == '2'){
    viewresponses();
  }
  else if(option == '3'){
    return;
  }
  }
}

void admin::viewresponses(){
  ifstream file("user_input.txt"); //open file

    if (!file) {
        cout << "Error: Unable to open 'user_input.txt'!" << endl;
        return; //if the file does't exist or could not open this message will appear
    }

    string line, name, response;
    int questionIndex = 0;
    while (getline(file, line)) { //this loop will display one responses at a time
        stringstream ss(line);
        getline(ss, name, ',');
        questionIndex = 0;
        system("clear");
        cout << "\nResponses from: " << name << endl;
        cout << "---------------------------------\n";

        while (getline(ss, response, ',')) {
            cout << "Q" << questionIndex + 1 << ": " << Question[questionIndex] << endl;
            cout << "User's Answer: " << response << "\n" << endl;
            questionIndex++;
        }

        cout << "---------------------------------\n";

        cout << "Type 'next' to view the next respondent or 'exit' to quit: ";
        string userInput;
        cin >> userInput; //if user input next, it will show another responses

        if (userInput == "exit") {
            file.close();
            return; 
        }//if user input exit, this function will be exited.
    }

    file.close();
}

bool admin::login(){
    logs = false; //to make sure the while keeps loop before login successful or exit
    system("clear"); 
    while(logs == false){
      cout<<"ADMIN LOGIN\n\n";
      cout << "[Enter 'exit' to quit]\n";
      cout<<"ID      : ";
      cin.ignore();
      cin>>ids;
      if(ids == "exit"){
          return 0;
      }

      cout<<"Password: ";
      cin.ignore();
      cin>>pass;
      if((ids == id) && (pass == password)){
          logs = true; //if authenticate successfully, the logs will be true to exit the while loop
      }
  
      else{
          system("clear");
          cout<<"Login Unsuccessfully\n";
          logs = false; //if authenticate unsuccessfully, it will display unsuccess message and keep looping
      }

    }
    return 1;
}

void admin::analysis(){
  system("clear"); 
  ifstream file("user_input.txt");  //open file
    if (!file) {
        cout << "Error: Unable to open file!" << endl;
        return; //if the file does't exist or could not open this message will appear
    }

    map<int, map<char, int>> responseCount; //used to store response cunts per quest

    while (getline(file, texts)){
        stringstream ss(texts);
        getline(ss, name, ' '); //used to extract the respondent name
        QNo = 1;  

        while (getline(ss, abcd, ',')){ 
            responseCount[QNo][toupper(abcd[0])]++; 
            QNo++;
        }
    }
    file.close();

    //display summary
    cout << "\n Survey Response Summary:\n";
    cout << "--------------------------------------\n";
    cout << "Q#   A   B   C   D\n";
    cout << "--------------------------------------\n";    

    for (int i = 1; i <= 10; i++) {
      if(i<10){
        cout << "Q0" << i << "   "
             << responseCount[i]['A'] << "   "
             << responseCount[i]['B'] << "   "
             << responseCount[i]['C'] << "   "
             << responseCount[i]['D'] << endl;
      }
      else{
        cout << "Q" << i << "   "
             << responseCount[i]['A'] << "   "
             << responseCount[i]['B'] << "   "
             << responseCount[i]['C'] << "   "
             << responseCount[i]['D'] << endl;
      }
    }
    waitForEnter();
    system("clear");
}

class questionnaire{
    string userName; //used to store respondent name
    char answer[10]; //store respondent answer

    public:
    void start1(){ //used to start the questionnaire
      system("clear");
      cout << "Welcome to Green City, Smart Living: A Vision for Sustainable Urban Futures Questionnaire.\n\n";
      cout << "[Enter 'X' to quit]\n";
      cout << "Enter your name: ";
      cin.ignore(); //clear input buffer
      getline(cin, userName);
      for (char &c : userName) {
        c = toupper(c);
    }

      if(userName == "X"){
          return; //quit if user input x
      }

      //display each question and get user answer
      for(int i = 0; i < 10; i++){
        system("clear");
        cout << "Welcome to Green City, Smart Living: A Vision for Sustainable Urban Futures.\n\n";
        cout << i+1 << ". " << Question[i] << endl;
        cout << abc[i] << endl;  
        
        cout<<"\nYour Answer [Enter 'X' to quit]: ";
        cin >> answer[i];
        answer[i] = toupper(answer[i]);

        //validate input
        while(answer[i] != 'A' && answer[i] != 'B' && answer[i] != 'C' && answer[i] != 'D' && answer[i] != 'X') {
            cout << "Invalid input! Please enter A, B, C, or D [Enter 'X' to quit]: ";
            cin >> answer[i];
            answer[i] = toupper(answer[i]);
        }
        
        //quit if user input x
        if(toupper(answer[i]) == 'X'){
          return;
      }
      }

      system("clear");
      cout << "Thanks for your responses!\n";
      ofstream file("user_input.txt", ios::app);  //store into the file
      file <<"\""<< userName <<"\""<< " ";

      for(int j = 0; j < 10; j++) {
          file << answer[j] << ",";
      }
      file<<"\n";
      file.close();
      cout << "Your input has been saved.\n";
      waitForEnter();
    }
};

int main() {
  char opt;
  bool ad = false;
  admin user;
  questionnaire ques;
  while(true){
  system("clear");
  cout << "Welcome to Green City, Smart Living: A Vision for Sustainable Urban Futures.\n\n";
  cout<<"1. Answer the Question"<<endl;
  cout<<"2. Admin Login"<<endl;
  cout<<"3. Quit\n"<<endl;
  cout<<"select the option from above: ";
  cin>>opt;//get user input option

  //handle user choices
  if(opt == '1'){
   ques.start1();
  }
  else if(opt == '2'){
    ad = user.login();
    if(ad == true){
        user.menu();
    }
  }
  else if(opt == '3'){
    exit(0);
  }
  else{
    cout<<"option invalid!";
  }
}
  return 0;
}