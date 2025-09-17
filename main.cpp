#include <iostream> //fro dispalying to the terminal
#include <fstream> //for writing/reading from files
#include <limits>

void displayMessage(const std::string& msg){
    std::cout <<msg<<std::endl;
}

void displayMenu(){
    displayMessage("\nPassword Manager");
    displayMessage(" 1. Add Password");
    displayMessage(" 2. View Passwords");
    displayMessage(" 3. Exit");
    displayMessage("Enter your choice: ");
}

void SavePassword(const std::string& site, const std::string& password){
    std::ofstream file("password.txt",std::ios::app);
    if (file.is_open()) {
        file << site << " " << password << "\n";
        file.close();
        displayMessage("Password saved successfully!");
    }else {
        std::cerr << "Error: Unable to open file for writing. \n";
    }
}

int main(){
    int choice;
    std::string site, password;

    do{
        displayMenu();

        std:: cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch(choice){
            case 1:
                displayMessage("Enter site name: ");
                std::cin >> site;
                displayMessage("Enter password: ");
                std::cin >> password;
                SavePassword(site, password);
                break
            
            case 2:

                break

            case 3:

                break

            default:

                break
        }

    } while(choice != 3);

    return 0;
}