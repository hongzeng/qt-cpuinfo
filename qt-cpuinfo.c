/* This is home work
 * code not verified with compiler as I didn't have Qt installed.
 * buffer allocation size was estimated for simplifying work,
 * suppose it big enough for /proc/cpuinfo.
 * window size was not verified
 */


#define BUFSIZE 256

int main(int argc, char* argv[]) {
    QApplication myApp(argc, argv);
    QWidget* myWidget = new QWidget();
    myWidget->setGeometry(400, 300, 120, 90);

    int input_fd;
    int ret_in;
    input_fd = open(“/proc/cpuinfo”, O_RDONLY);
    if(input_fd == -1) {
        perror (“open”);
        return 2;
    }

    char buffer [BUF_SIZE*128]={0}; //simplified here, just allocate big enough buffer to
                                    //read in all text from /proc/cpuinfo
    char * BufferP = buffer;
    strcpy(buffer, “CPU info:\n”);  //title of info
    BufferP += strlen(buffer);      //increment the size of “CPU info:\n”

    while((ret_in = read(input_fd, &BufferP, BUF_SIZE))>0){//suppose the buffer big enough
        BufferP += BUF_SIZE;
    }

    close (input_fd);
    QString cpuInfoDisplay = new QString(buffer);
    QLabel *myLabel = new QLabel(cpuInfoDisplay,myWidget); //display it
    myLabel->setGeometry(10, 10, 80, 30);
    QPushButton* myQuitButton = new QPushButton("Quit", myWidget);
    myQuitButton->setGeometry(10, 50, 100, 30);
    QObject::connect(myQuitButton, SIGNAL(clicked()), &myApp, SLOT(quit());
    myapp.setMainWidget( myWidget );
    myWidget->show();
    return myApp.exec();
}

