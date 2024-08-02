#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "Runecrypt.h"

using namespace std;
//Implement your own keys that are four characters in length(Ex: 0x01)
string defaultKeys[95] = {
  "0X01", "0X02", "0X03", "0X04", "0X05", "0X06", "0X07", "0X08", "0X09", "0X10",
  "0X11", "0X12", "0X13", "0X14", "0X15", "0X16", "0X17", "0X18", "0X19", "0X20",
  "0X21", "0X22", "0X23", "0X24", "0X25", "0X26", "0X27", "0X28", "0X29", "0X30",
  "0X31", "0X32", "0X33", "0X34", "0X35", "0X36", "0X37", "0X38", "0X39", "0X40",
  "0X41", "0X42", "0X43", "0X44", "0X45", "0X46", "0X47", "0X48", "0X49", "0X50",
  "0X51", "0X52", "0X53", "0X54", "0X55", "0X56", "0X57", "0X58", "0X59", "0X60",
  "0X61", "0X62", "0X63", "0X64", "0X65", "0X66", "0X67", "0X68", "0X69", "0X70",
  "0X71", "0X72", "0X73", "0X74", "0X75", "0X76", "0X77", "0X78", "0X79", "0X80",
  "0X81", "0X82", "0X83", "0X84", "0X85", "0X86", "0X87", "0X88", "0X89", "0X90",
  "0X91", "0X92", "0X93", "0X94", "0X95"
    };
void lineSpace1() {
  cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~=" << endl;
}

void welcomeRunecrypt() {
  string welcomeInput = "";
  lineSpace1();
  cout << "Welcome To Runecrypt v1" << endl;
  cout << "Created By MS" << endl;
  lineSpace1();
  cout << "\'Help\' For Info | \'Con\' to continue" << endl;
  cout << "User: ";
  cin >> welcomeInput;
  if (welcomeInput == "Help" || welcomeInput == "help") {
    helpScript();
  } else if (welcomeInput == "Con" || welcomeInput == "con") {
    continueScript();
  } else if (welcomeInput == "Quit" || welcomeInput == "quit" || welcomeInput == "Q" || welcomeInput == "q") {
    quitScript();
  } else if (welcomeInput == "Encrypt" || welcomeInput == "encrypt" || welcomeInput == "E" || welcomeInput == "e") {
    encryptScript();
  } else if (welcomeInput == "Decrypt" || welcomeInput == "decrypt" || welcomeInput == "D" || welcomeInput == "d") { 
    decryptScript();
  } else {
    cout << "Invalid Input" << endl;
  }
}

void helpScript() {
  string helpScriptInput = "";
  lineSpace1();
  cout << "Runecrypt is a file encryption/decryption program" << endl;
  cout << "Runecrypt uses a similar algorithm as glyphLock/DragonScramble" << endl;
  cout << "Runecrypt can only encrypt contents of a file once as of now" << endl;
  cout << "To Encrypt/Decrypt Files Determined From User Input" << endl;
  cout << "Runecrypt decryption will only work for Runecrypts encryption" << endl;
  cout << "Your file must be placed within Runecrypts Folder" << endl;
  lineSpace1();
  cout << "Type Con to continue | Type Quit to quit" << endl;
  cout << "User: ";
  cin >> helpScriptInput;
  if (helpScriptInput == "Quit" || helpScriptInput == "quit" || helpScriptInput == "Q" || helpScriptInput == "q") {
    quitScript();
  }
  else if (helpScriptInput == "Con" || helpScriptInput == "con" || helpScriptInput == "C" || helpScriptInput == "c") {
    continueScript();
  } else {
    lineSpace1();
    cout << "Invalid Input" << endl;
    lineSpace1();
  }
}

void quitScript() {
  lineSpace1();
  cout << "Thank You! For using Runecrypt" << endl;
  lineSpace1();
}

void continueScript() {
  string continueScriptInput = "";
  lineSpace1();
  cout << "Type Encrypt for Encryption | Type Decrypt for Decryption" << endl;
  cout << "User: ";
  cin >> continueScriptInput;
  if (continueScriptInput == "Encrypt" || continueScriptInput == "encrypt" || continueScriptInput == "E" || continueScriptInput == "e") {
    encryptScript();
  } else if (continueScriptInput == "Decrypt" || continueScriptInput == "decrypt") {
    decryptScript();
  } else {
    lineSpace1();
    cout << "Invalid Input" << endl;
    lineSpace1();
  }
}

void encryptScript() {
  string fileName = "";
  lineSpace1();
  cout << "Enter The File Name(Ex: example.txt)" << endl;
  cout << "User: ";
  cin >> fileName;
  fstream userFile(fileName);
  if (userFile.is_open()) {
    char c;
    string fileContent;
    string encryptContent = "";
    while (userFile.get(c)) {
      fileContent += c;
    }
    for (size_t i = 0; i < fileContent.size(); ++i) {
        if (fileContent[i] >= 32 && fileContent[i] <= 126) {
          encryptContent += defaultKeys[fileContent[i]-32];
        } else if (fileContent[i] == 10) {
          encryptContent += "NxW!";
        } else {
          encryptContent += fileContent[i];
        }
    }
    ofstream outputfile(fileName);
    outputfile << encryptContent;
    userFile.close();
    lineSpace1();
    cout << "Thank You For Using Runecrypt!" << endl;
} else {
  lineSpace1();
  cout << "Error Code: 107 | File Not Found" << endl;
  lineSpace1();
}
}

void decryptScript() {
  string fileName = "";
  lineSpace1();
  cout << "Enter The File Name(Ex: example.txt)" << endl;
  cout << "User: ";
  cin >> fileName;
  fstream userFile(fileName);
  string encryptContent = "";
  string decryptChunk = "";
  string decryptContent = "";
  char decryptKey;
  if (userFile.is_open()) {
    while (getline(userFile, encryptContent)) {
      for (size_t i = 0; i < encryptContent.length(); i += 4) {
        decryptChunk = encryptContent.substr(i, 4);
        for (int c = 0; c < 95; c++) {
          if (decryptChunk == defaultKeys[c]) {
            decryptKey = static_cast<char>(c + 32);
            decryptContent += decryptKey;
        } if (decryptChunk == "NxW!") {
          decryptContent += "\n";
          break;
        }
      }   
      } 
    }
    ofstream outputfile(fileName);
    outputfile << decryptContent;
    userFile.close();
    quitScript(); 
  } else {
    lineSpace1();
    cout << "Error Code: 107 | File Not Found" << endl;
    lineSpace1();    
  }
}


