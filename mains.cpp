#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream> 
#include <cctype>

using namespace std;

void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}


class admin{
    string id = "S001";
    string password = "A123";

    string ids;
    string pass;

    bool logs;

    public:
    bool login();
    void viewrespondent();
};

bool admin::login(){
    system("clear"); 
    logs = false;
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
          cout<<"Login Successfully";
          logs = true;
      }
  
      else{
          system("clear");
          cout<<"Login Unsuccessfully\n\n";
          logs = false;
      }

    }
    return 1;
}

class questionnaire{
    string userName;
    char answer[10];
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
    };

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
    };

    public:
    void start1(){
      system("clear");
      cout << "Welcome to Green City, Smart Living: A Vision for Sustainable Urban Futures Questionnaire.\n\n";
      cout << "[Enter 'X' to quit]\n";
      cout << "Enter your name: ";
      cin >> userName;
      for (char &c : userName) {
        c = toupper(c);
    }

      if(userName == "X"){
          return;
      }

      for(int i = 0; i < 10; i++){
        system("clear");
        cout << "Welcome to Green City, Smart Living: A Vision for Sustainable Urban Futures.\n";
        cout << i+1 << ". " << Question[i] << endl;
        cout << abc[i] << endl;  
        
        cout<<"\nYour Answer [Enter 'X' to quit]: ";
        cin >> answer[i];
        answer[i] = toupper(answer[i]);


        while(answer[i] != 'A' && answer[i] != 'B' && answer[i] != 'C' && answer[i] != 'D' && answer[i] != 'X') {
            cout << "Invalid input! Please enter A, B, C, or D [Enter 'X' to quit]: ";
            cin >> answer[i];
            answer[i] = toupper(answer[i]);
        }
        
        if(toupper(answer[i]) == 'X'){
          return;
      }
      }

      system("clear");
      cout << "Thanks for your responses!\n";
      ofstream file("user_input.txt", ios::app);  
      file << "User: " << userName << "\n";
      for(int j = 0; j < 10; j++) {
          file << "Q" << (j+1) << ": " << answer[j] << "\n";
      }
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
  cout << "Welcome to Green City, Smart Living: A Vision for Sustainable Urban Futures Questionnaire.\n\n";
  cout<<endl<<"1. Answer the Question"<<endl;
  cout<<"2. Admin Login"<<endl;
  cout<<"3. Quit\n"<<endl;
  cout<<"select the option from above: ";
  cin>>opt;

  if(opt == '1'){
   ques.start1();
  }
  else if(opt == '2'){
    ad = user.login();
    if(ad == true){
        cout<<"hi, welcome back to the system.";
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