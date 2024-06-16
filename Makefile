CC = g++
CFLAGS = -Wall -Werror

all: loadbalancer

loadbalancer: CurrencyConverter.o LoadBalancer.o main.o Request.o RequestQueue.o WebServer.o
	$(CC) $(CFLAGS) -o loadbalancer CurrencyConverter.o LoadBalancer.o main.o Request.o RequestQueue.o WebServer.o

CurrencyConverter.o: CurrencyConverter.cpp
	$(CC) $(CFLAGS) -c CurrencyConverter.cpp

LoadBalancer.o: LoadBalancer.cpp
	$(CC) $(CFLAGS) -c LoadBalancer.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Request.o: Request.cpp
	$(CC) $(CFLAGS) -c Request.cpp

RequestQueue.o: RequestQueue.cpp
	$(CC) $(CFLAGS) -c RequestQueue.cpp

WebServer.o: WebServer.cpp
	$(CC) $(CFLAGS) -c WebServer.cpp

clean:
	rm -f loadbalancer *.o
