#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <pigpio.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include "pmodAD1.h"
#include "pmodDA2.h"

#define	TRUE	(1==1)
#define	FALSE	(!TRUE)
#define	SPI_CHAN 0 // canal SPI de la RPi B.
#define SPI_MODE 1 // modo SPI.
#define	AD_SPI_CHAN 0 // canal SPI del AD.
#define	DA_SPI_CHAN 1 // canal SPI del DA.
#define SPI_SPEED 20000000 // velocidad de reloj SPI.
#define AD_DA_OFFSET 2048 
#define TS 125000 // periodo de muestreo en nanosegundos

#define FS 8000
#define Frec 100
#define Amp 2000
#define PI 3.14159265358979323846

int myFd_AD;
int myFd_DA;

void spiSetup(int speed);
void tickConfig(unsigned int sampling_period);
void tickHandler(int sig, siginfo_t *si, void *uc);