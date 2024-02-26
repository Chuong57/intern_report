#include <iostream>
#include <string>

enum StateType 
{
    PASSWORD_CHECKING,
    MONITOR_RUN,
    CHECKING_PASS
};

class StateMachine 
{
private:
    StateType currentState;

public:
    StateMachine() : currentState(PASSWORD_CHECKING) {}

    void run() 
    {
        while (true) {
            switch (currentState) 
            {
                case PASSWORD_CHECKING:
                    handlePasswordChecking();
                    break;
                case MONITOR_RUN:
                    handleMonitorRun();
                    break;
                case CHECKING_PASS:
                    handleCheckingPass();
                    break;
                default:
                    std::cerr << "Invalid state encountered. Exiting.\n";
                    return;
            }
        }
    }

private:
    void handlePasswordChecking() 
    {
        std::string enteredPassword;
        std::cout << "Enter password: ";
        std::cin >> enteredPassword;

        if (enteredPassword == "12345") 
        {
            std::cout << "Password is correct. Transitioning to Monitor Run State.\n";
            currentState = MONITOR_RUN;
        } 
        else 
        {
            std::cout << "Incorrect password. Please try again.\n";
        }
    }

    void handleMonitorRun() 
    {
        std::cout << "Monitoring system running. Press 'q' to quit monitoring.\n";

        char input;
        std::cin >> input;

        if (input == 'q') 
        {
            std::cout << "Quitting monitoring. Transitioning to Checking Pass State.\n";
            currentState = CHECKING_PASS;
        } 
        else 
        {
            std::cout << "Invalid input. Monitoring continues.\n";
        }
    }

    void handleCheckingPass() 
    {
        std::cout << "Checking password again before exiting. Enter password: ";
        std::string enteredPassword;
        std::cin >> enteredPassword;

        if (enteredPassword == "12345") {
            std::cout << "Password is correct. Exiting program.\n";
            
            currentState = PASSWORD_CHECKING;  // Reset to initial state
        } 
        else 
        {
            std::cout << "Incorrect password. Cannot exit. Please try again.\n";
        }
    }
};

int main() 
{
    StateMachine stateMachine;

    stateMachine.run();

    return 0;
}
