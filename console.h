#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
#include <QString>
class Console
{
public:
    Console();
    ~Console();
    static void  log(std::string text);
    static void  log(QString text);
};

#endif // CONSOLE_H
