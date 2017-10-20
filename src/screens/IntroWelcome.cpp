#include "IntroWelcome.h"

namespace TeaMessenger {

IntroWelcome::IntroWelcome()
: m_layout( new QVBoxLayout ) {
    this->resize(700,60);
    this->setWindowIcon(QIcon(":/Icon-App"));
    this->setMinimumWidth(400);
    this->setMinimumHeight(480);
    this->setWindowTitle(QString("Tea Messenger - Welcome"));
    this->setStyleSheet("background-image: url(:/BG-Intro); background-position: bottom center; background-repeat: no-repeat;");

    m_layout->setMargin(20);
    m_layout->setSpacing(0);

    QFontDatabase::addApplicationFont(":/Lato-Black");
    QFontDatabase::addApplicationFont(":/Lato-Hairline");
    QFontDatabase::addApplicationFont(":/Lato-Light");
    QFont latoBlack("Lato-Black", 20, QFont::Bold);
    QFont latoHairline("Lato-Hairline", 20, QFont::Normal);
    QFont latoLight("Lato-Light", 24, QFont::Normal);

    m_logo = new QLabel;
    QPixmap logoPix(":/Icon-Logo");
    m_logo->setPixmap(logoPix.scaled(120,120,Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_logo->setAlignment(Qt::AlignCenter);
    m_logo->setStyleSheet("background: rgba(0,0,0,0);");

    m_introTitle = new QLabel("Tea Messenger", this);
    m_introTitle->setAlignment(Qt::AlignCenter);
    m_introTitle->setFont(latoLight);
    m_introTitle->setStyleSheet("background: rgba(0,0,0,0);");

    m_introSubTitle = new QLabel("Welcome to the Official Tea Messenger Desktop App.", this);
    m_introSubTitle->setAlignment(Qt::AlignCenter);
    QFont subTitleFont = latoLight;
          subTitleFont.setPixelSize(12);
    m_introSubTitle->setFont(subTitleFont);
    m_introSubTitle->setStyleSheet("background: rgba(0,0,0,0);");

    m_getStartedBtn = new QPushButton("GET STARTED", this);
    m_getStartedBtn->setFont(latoBlack);
    m_getStartedBtn->setStyleSheet("font-size: 18px; padding: 10px; border: 2px solid #478262; background: #478262; color: #ffffff; border-radius: 5px; margin-top: 30px;");

    m_layout->addWidget(m_logo);
    m_layout->addWidget(m_introTitle);
    m_layout->addWidget(m_introSubTitle);
    m_layout->addWidget(m_getStartedBtn);
    m_layout->setAlignment(Qt::AlignCenter);
    m_layout->setContentsMargins(0,50,0,180);
    this->setLayout(m_layout);
};

};
