

#include <QtCore>
#include <QtGui>

class myProcess: public QProcess
{
  Q_OBJECT
  public:
  myProcess(): QProcess()
  {
    edit = new QTextEdit();
    edit->resize(500,500);
    edit->setWindowTitle("Standard Output Redirection");
    edit->show();
    connect(this,SIGNAL(readyReadStandardOutput()),this,SLOT(readStdOutput()));
    connect(this,SIGNAL(error(QProcess::ProcessError)),this,SLOT(readError()));
  };

  ~myProcess()
  {};

private slots:
  void readStdOutput()
  {
    edit->append(readAllStandardOutput());
  };

  void readError()
  {
    edit->append("An Error Occured! Error Code is: "+QString::number(error()));
  };

private:
  QTextEdit* edit;
};

