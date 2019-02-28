all: 
	g++ -std=c++11 main.cpp $(CPPFLAGS) httpquery.cpp -lcurl -ljsoncpp -lmongoclient -lboost_filesystem -lboost_program_options -lboost_system
	g++ main2analyst.cpp API_KEY exchangeanalyst2.cpp -pthread -lmongoclient -lboost_filesystem -lboost_program_options -lboost_system -o tutorial
