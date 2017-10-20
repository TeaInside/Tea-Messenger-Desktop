#include "TeaMessenger.h"
#include "screens/IntroWelcome.h"
#include <iostream>

namespace TeaMessenger {

Messenger::Messenger( int &argc, char *argv[] )
: QApplication( argc, argv ) {
};


bool Messenger::isLoggedIn() {
    return false;
};


void Messenger::showChatWindow() {
};


void Messenger::showIntroScreen() {
    m_window = new IntroWelcome;
    m_window->show();
};


};


// Entry Point
int main( int argc, char *argv[] ) {
    std::cout <<  "Tea Messenger starting..."     << std::endl
              <<  "Client Version: V 0.0.1-Alpha" << std::endl
              <<  "Qt Version : "  << qVersion()  << std::endl;


    TeaMessenger::Messenger teaMessenger(argc,argv);
    if( teaMessenger.isLoggedIn() ) {
        teaMessenger.showChatWindow();
    } else {
    }
        teaMessenger.showIntroScreen();

    return teaMessenger.exec();
};
