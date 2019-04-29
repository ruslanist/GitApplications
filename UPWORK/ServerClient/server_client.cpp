#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

int main(int argc, char *argv[])
{
    std::this_thread::sleep_for (std::chrono::seconds(atoi(argv[3])));

    int sockfd = 0;
    struct sockaddr_in serv_addr;

    if(argc != 4)
    {
        std::cerr << " Usage: client_name, port, period" << std::endl;
        return -1;
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Could not create socket" << std::endl;
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        std::cerr << "inet_pton error occured" << std::endl;
        return -1;
    }

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       std::cerr << "connect Failed" << std::endl;
       return -1;
    }

    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d %X",timeinfo);
    std::string time_str(buffer);

    std::string msg = time_str + " " + argv[1];

    write(sockfd, msg.data(), msg.size());

    return 0;
}
