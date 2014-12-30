#include "console.h"
#include <QtDebug>
#include <string>
#include <QString>

Console::Console()
{

}

Console::~Console()
{

}

void  Console::log(std::string text){
    qDebug() << QString::fromStdString(text);
}

void Console::log(QString text){
    qDebug() << text;
}
