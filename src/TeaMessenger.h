#include <QApplication>
#include <QtWidgets>

namespace TeaMessenger {

class Messenger final : public QApplication {
public:
    Messenger( int &argc, char *argv[] );

    QWidget* m_window;

    bool isLoggedIn();
    void showChatWindow();
    void showIntroScreen();
};

};
