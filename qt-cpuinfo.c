/* This is home work
 * code not verified with compiler as I didn't have Qt installed.
 * window size was not verified
 */


int main(int argc, char* argv[]) {
    QApplication myApp(argc, argv);
    QWidget* myWidget = new QWidget();
    myWidget->setGeometry(300, 300, 150, 190);

    QFile input_fd("/proc/cpuinfo");
    if(!input_fd.open(QIODevice::ReadOnly | QIODevice::Text))
	return -1;
    QTextStream in(&input_fd);
    QString cpuInfoDisplay;
    cpuInfoDisplay = in.readAll();
    input_fd.close();

    QLabel *myLabel = new QLabel(cpuInfoDisplay,myWidget); //display it
    myLabel->setGeometry(10, 10, 120, 150);
    QPushButton* myQuitButton = new QPushButton("Quit", myWidget);
    myQuitButton->setGeometry(10, 50, 100, 30);
    QObject::connect(myQuitButton, SIGNAL(clicked()), &myApp, SLOT(quit());
    myapp.setMainWidget( myWidget );
    myWidget->show();
    return myApp.exec(); 
}

