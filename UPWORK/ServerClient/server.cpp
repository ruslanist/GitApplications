#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <mutex>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#define MSG_BUF_LEN 1024
std::mutex log_file_mutes;
std::ofstream log_file("./log.txt");

void handle_client_msg(int client_fd) {
    char buf[MSG_BUF_LEN];
    memset(buf, 0, MSG_BUF_LEN);
    read(client_fd, buf, MSG_BUF_LEN);
    log_file_mutes.lock();
    log_file << buf << std::endl;
    log_file_mutes.unlock();
    close(client_fd);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << " Usage: port" << std::endl;
        return -1;
    }

    const int TOTAL_WORKERS = 50;

    if(!log_file.is_open()) {
        std::cerr << "fail to open log file" << std::endl;
        return -1;
    }

    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;
    std::vector<std::thread> workers;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if(listen(listenfd, 50) != 0) {
        std::cerr << "fail to listen" << std::endl;
    }

    while(1)
    {
        if(workers.size() == TOTAL_WORKERS) {
            for(int i = 0; i < workers.size(); i++) {
                workers[i].join();
            }
            workers.clear();
        }

        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        workers.push_back(std::thread(handle_client_msg, connfd));
    }
}
