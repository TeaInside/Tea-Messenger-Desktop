#include "QtWidgets"
#include <QLabel>
#include <QVBoxLayout>

namespace TeaMessenger {

class IntroWelcome : public QWidget {
public:
    IntroWelcome();

private:
    QLabel *m_logo,
	   *m_introTitle,
	   *m_introSubTitle;
    QPushButton *m_getStartedBtn;
    QVBoxLayout *m_layout;
};

};
