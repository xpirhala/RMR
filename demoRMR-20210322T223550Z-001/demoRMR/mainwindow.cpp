#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <math.h>
#include "odometry.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <map.h>

int numberOfCoordinates;
int cnt=0;
float phiFeedback, distanceFeedback, destinationPhi;
coordinates *coor;
bool flag;
Map maps(5,5,620,620);

struct coordinates{
    float x;
    float y;
    bool flag=false;
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //tu je napevno nastavena ip. treba zmenit na to co ste si zadali do text boxu alebo nejaku inu pevnu. co bude spravna
    ipaddress="127.0.0.1";
    //cap.open("http://192.168.1.11:8000/stream.mjpg");
    ui->setupUi(this);
    datacounter=0;
  //  timer = new QTimer(this);
 //   connect(timer, SIGNAL(timeout()), this, SLOT(getNewFrame()));
    actIndex=-1;
    useCamera=false;



    datacounter=0;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::black);
    QPen pero;
    pero.setStyle(Qt::SolidLine);
    pero.setWidth(3);
    pero.setColor(Qt::green);
    QRect rect(20,120,700,500);
    rect= ui->frame->geometry();
    rect.translate(0,15);
    painter.drawRect(rect);

  /*  if(useCamera==true)
    {
        std::cout<<actIndex<<std::endl;
        QImage image = QImage((uchar*)frame[actIndex].data, frame[actIndex].cols, frame[actIndex].rows, frame[actIndex].step, QImage::Format_RGB888  );
        painter.drawImage(rect,image.rgbSwapped());
    }
    else*/
    {
        if(updateLaserPicture==1)
        {
            updateLaserPicture=0;

            painter.setPen(pero);
            //teraz tu kreslime random udaje... vykreslite to co treba... t.j. data z lidaru
         //   std::cout<<copyOfLaserData.numberOfScans<<std::endl;
            for(int k=0;k<copyOfLaserData.numberOfScans/*6.2830*/;k++)
            {
                /*  int dist=rand()%500;
            int xp=rect.width()-(rect.width()/2+dist*2*sin((6.2830.0-k)*3.14159/3.1415.0))+rect.topLeft().x();
            int yp=rect.height()-(rect.height()/2+dist*2*cos((6.2830.0-k)*3.14159/3.1415.0))+rect.topLeft().y();*/
                int dist=copyOfLaserData.Data[k].scanDistance/20;
                int xp=rect.width()-(rect.width()/2+dist*2*sin((360.0-copyOfLaserData.Data[k].scanAngle)*3.14159/180.0))+rect.topLeft().x();
                int yp=rect.height()-(rect.height()/2+dist*2*cos((360.0-copyOfLaserData.Data[k].scanAngle)*3.14159/180.0))+rect.topLeft().y();
                if(rect.contains(xp,yp))
                    painter.drawEllipse(QPoint(xp, yp),2,2);
            }
        }
    }
}

void  MainWindow::setUiValues(double robotX,double robotY,double robotFi, float phiFeedback, float distanceFeedback)
{
     ui->lineEdit_2->setText(QString::number(robotX));
     ui->lineEdit_3->setText(QString::number(robotY));
     ui->lineEdit_4->setText(QString::number(robotFi));
     ui->lineEdit_5->setText(QString::number(phiFeedback));
     ui->lineEdit_6->setText(QString::number(distanceFeedback));
}


void MainWindow::processThisRobot()
{


    if(datacounter%5)
    {
        //emit uiValuesChanged(phiFeedback, distanceFeedback, phi); //tuto treba posielat naše vyrátané veci
        emit uiValuesChanged(currentX,currentY,phi*180/3.1415, phiFeedback, distanceFeedback);
    }
    datacounter++;

}

void MainWindow::processThisLidar(LaserMeasurement &laserData)
{
    memcpy( &copyOfLaserData,&laserData,sizeof(LaserMeasurement));
    //tu mozete robit s datami z lidaru.. napriklad najst prekazky, zapisat do mapy. naplanovat ako sa prekazke vyhnut.

    if(flag){
      maps.procesLaserData(laserData,currentX,currentY,phi);
    }

    // ale nic vypoctovo narocne - to iste vlakno ktore cita data z lidaru

    //cout<<"laser data "<<laserData.Data[0].scanDistance;
    updateLaserPicture=1;
    update();//tento prikaz prinuti prekreslit obrazovku.. zavola sa paintEvent funkcia



}


void MainWindow::on_pushButton_9_clicked() //start button
{

    //tu sa nastartuju vlakna ktore citaju data z lidaru a robota
    laserthreadHandle=CreateThread(NULL,0,laserUDPVlakno, (void *)this,0,&laserthreadID);
    robotthreadHandle=CreateThread(NULL,0, robotUDPVlakno, (void *)this,0,&robotthreadID);
    /*  laserthreadID=pthread_create(&laserthreadHandle,NULL,&laserUDPVlakno,(void *)this);
      robotthreadID=pthread_create(&robotthreadHandle,NULL,&robotUDPVlakno,(void *)this);*/
    connect(this,SIGNAL(uiValuesChanged(double,double,double,float,float)),this,SLOT(setUiValues(double,double,double,float,float)));
    maps.updateMap();
}

void MainWindow::on_pushButton_2_clicked() //forward
{
    //pohyb dopredu
    std::vector<unsigned char> mess=robot.setTranslationSpeed(250);
    if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
    {

    }
}

void MainWindow::on_pushButton_3_clicked() //back
{
    std::vector<unsigned char> mess=robot.setTranslationSpeed(-250);
    if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
    {

    }
}

void MainWindow::on_pushButton_6_clicked() //left
{

    std::vector<unsigned char> mess=robot.setRotationSpeed(3.14159/5);
    if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
    {

    }
}

void MainWindow::on_pushButton_5_clicked()//right
{

    std::vector<unsigned char> mess=robot.setRotationSpeed(-3.14159/5);
    if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
    {

    }
}

void MainWindow::on_pushButton_4_clicked() //stop
{
    std::vector<unsigned char> mess=robot.setTranslationSpeed(0);
    if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
    {

    }
}

void MainWindow::laserprocess()
{
    WSADATA wsaData = {0};
    int iResult = 0;



    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    las_slen = sizeof(las_si_other);
    if ((las_s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {

    }

    int las_broadcastene=1;
    setsockopt(las_s,SOL_SOCKET,SO_BROADCAST,(char*)&las_broadcastene,sizeof(las_broadcastene));
    // zero out the structure
    memset((char *) &las_si_me, 0, sizeof(las_si_me));

    las_si_me.sin_family = AF_INET;
    las_si_me.sin_port = htons(52999);
    las_si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    las_si_posli.sin_family = AF_INET;
    las_si_posli.sin_port = htons(5299);
    las_si_posli.sin_addr.s_addr = inet_addr(ipaddress.data());//htonl(INADDR_BROADCAST);
    bind(las_s , (struct sockaddr*)&las_si_me, sizeof(las_si_me) );
    char command=0x00;
    if (sendto(las_s, &command, sizeof(command), 0, (struct sockaddr*) &las_si_posli, las_slen) == -1)
    {

    }
    LaserMeasurement measure;
    while(1)
    {
        if ((las_recv_len = recvfrom(las_s, (char*)&measure.Data, sizeof(LaserData)*1000, 0, (struct sockaddr *) &las_si_other, (int*)&las_slen)) == -1)
        {

            continue;
        }
        measure.numberOfScans=las_recv_len/sizeof(LaserData);
        //tu mame data..zavolame si funkciu

        //     memcpy(&sens,buff,sizeof(sens));


        processThisLidar(measure);




    }
}

bool MainWindow::positioning(struct coordinates coordinates)
{
    //Setting phi

    destinationPhi = atan2((coordinates.y-currentY),(coordinates.x-currentX));




    phiFeedback = destinationPhi - phi;

    if(phiFeedback>3.1415)
       phiFeedback = destinationPhi - phi - 6.2830;

    //setting distance feedback
    distanceFeedback = sqrt((coordinates.y-currentY)*(coordinates.y-currentY)+(coordinates.x-currentX)*(coordinates.x-currentX));

    //regulations+saturations
    //phi regulator+saturation(2pi)
    float phiRegulator=0.7*phiFeedback;

    if(phiRegulator>6.2830){
        phiRegulator=6.2830;
    }else if(phiRegulator<-6.2830){
        phiRegulator=-6.2830;
    }

    //distance saturation (500 mm/sec)
   float distanceRegulator=1200*distanceFeedback;

   if(distanceRegulator>500){
        distanceRegulator=500;
   }

    if ((abs(phiFeedback)>0.09)&&(abs(distanceFeedback)>0.01))
    {
    flag=0;
        std::vector<unsigned char> mess=robot.setRotationSpeed(phiRegulator);
        if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
        {

        }

    }
    else
    {
        if (abs(distanceFeedback)>0.01)
        {
flag=1;
            std::vector<unsigned char> mess=robot.setTranslationSpeed(distanceRegulator);
            if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
            {

            }

        }
        else
        {
            flag=0;
            std::vector<unsigned char> mess=robot.setTranslationSpeed(0);
            if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
            {

            }
            return true;
        }
    }
    return false;

}
void MainWindow::setCoordinates(){
    //function for setting and adding coordinates to struct - in future live adding to it

    numberOfCoordinates=7;

    coor =  (coordinates *) malloc(sizeof(coordinates)*numberOfCoordinates);

    coor[0].x=0;
    coor[0].y=3.5;

    coor[1].x=1.2;
    coor[1].y=3.5;

    coor[2].x=1.2;
    coor[2].y=1.4;

    coor[3].x=2.7;
    coor[3].y=1.4;

    coor[4].x=2.7;
    coor[4].y=3.5;

    coor[5].x=0;
    coor[5].y=3.5;

    coor[6].x=0;
    coor[6].y=0;


}

void MainWindow::robotprocess()
{
    WSADATA wsaData = {0};
    int iResult = 0;



    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if ((rob_s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {

    }

    char rob_broadcastene=1;
    setsockopt(rob_s,SOL_SOCKET,SO_BROADCAST,&rob_broadcastene,sizeof(rob_broadcastene));
    // zero out the structure
    memset((char *) &rob_si_me, 0, sizeof(rob_si_me));

    rob_si_me.sin_family = AF_INET;
    rob_si_me.sin_port = htons(53000);
    rob_si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    rob_si_posli.sin_family = AF_INET;
    rob_si_posli.sin_port = htons(5300);
    rob_si_posli.sin_addr.s_addr =inet_addr(ipaddress.data());//inet_addr("10.0.0.1");// htonl(INADDR_BROADCAST);
    rob_slen = sizeof(rob_si_me);
    bind(rob_s , (struct sockaddr*)&rob_si_me, sizeof(rob_si_me) );

    std::vector<unsigned char> mess=robot.setDefaultPID();
    if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
    {

    }
    Sleep(100);
    mess=robot.setSound(440,1000);
    if (sendto(rob_s, (char*)mess.data(), sizeof(char)*mess.size(), 0, (struct sockaddr*) &rob_si_posli, rob_slen) == -1)
    {

    }
    unsigned char buff[50000];


    setCoordinates();


    while(1)
    {
        memset(buff,0,50000*sizeof(char));
        if ((rob_recv_len = recvfrom(rob_s, (char*)&buff, sizeof(char)*50000, 0, (struct sockaddr *) &rob_si_other,(int*) &rob_slen)) == -1)
        {

            continue;
        }
        //tu mame data..zavolame si funkciu

        //     memcpy(&sens,buff,sizeof(sens));
        //struct timespec t;
        //      clock_gettime(CLOCK_REALTIME,&t);

        int returnval=robot.fillData(robotdata,(unsigned char*)buff);
        if(returnval==0)
        {
            processThisRobot();
            odometry(robotdata.EncoderLeft, robotdata.EncoderRight);

            if(cnt<numberOfCoordinates){
                if((coor[cnt].flag!=true)){


                    coor[cnt].flag=positioning(coor[cnt]);
                }else{
                cnt=cnt+1;
                }
            }

        }
    }
}




void MainWindow::on_pushButton_clicked()
{
    if(useCamera==true)
    {
        useCamera=false;
        timer->stop();
        ui->pushButton->setText("use camera");
    }
    else
    {
        useCamera=true;
        timer->start(30);
        ui->pushButton->setText("use laser");
    }
}

void MainWindow::getNewFrame()
{

}
