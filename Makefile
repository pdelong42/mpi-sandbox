CC=/usr/local/software/OpenMPI/openmpi-2.0.0/bin/mpicc

all: hello-simple hello-send-recv hello-send-recv-2 hello-bcast hello-reduce

hello-simple: hello-simple.c
	$(CC) -o $@ hello-simple.c

hello-send-recv: hello-send-recv.c
	$(CC) -o $@ hello-send-recv.c

hello-send-recv-2: hello-send-recv-2.c
	$(CC) -o $@ hello-send-recv-2.c

hello-bcast: hello-bcast.c
	$(CC) -o $@ hello-bcast.c

hello-reduce: hello-reduce.c
	$(CC) -o $@ hello-reduce.c

clean:
	rm -f hello-simple hello-send-recv hello-send-recv-2 hello-bcast hello-reduce
