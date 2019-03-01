all: 
	g++ -std=c++11 main.cpp $(CPPFLAGS) httpquery.cpp -lcurl -ljsoncpp -lmongoclient -lboost_filesystem -lboost_program_options -lboost_system
	g++ -I /ExchengeAnalyst/main.cpp $(CPPFLAGS) -I /ExchengeAnalyst/analyst.cpp -pthread -lmongoclient -lboost_filesystem -lboost_program_options -lboost_system -o tutorial
