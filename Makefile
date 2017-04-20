CC=/usr/local/software/OpenMPI/openmpi-2.0.0/bin/mpicc

all: hello-simple hello-send-recv

hello-simple: hello-simple.c
	$(CC) -o $@ hello-simple.c

hello-send-recv: hello-send-recv.c
	$(CC) -o $@ hello-send-recv.c

clean:
	rm -f hello-simple hello-send-recv
