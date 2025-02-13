#include "dsp.h"
#include <sched.h>
#include <stdio.h>

#define PROCESS 0
#define PRIO 99

int main(void)
{
    int j, pol;
    struct sched_param sp;

    pol = SCHED_RR; // SCHED_OTHER, SCHED_FIFO, SCHED_RR

    sp.sched_priority = PRIO;

    if (sched_setscheduler(PROCESS, pol, &sp) == -1)
        printf("error sched_setscheduler\n");

    gpioInitialise();

    if((myFd_AD = spiOpen(AD_SPI_CHAN,SPI_SPEED,SPI_MODE)) < 0){
        fprintf(stderr, "no se puede abrir el bus SPI: %s\n", strerror (errno));
        exit(EXIT_FAILURE);
    }

    if((myFd_DA = spiOpen(DA_SPI_CHAN,SPI_SPEED,SPI_MODE)) < 0){
        fprintf(stderr, "no se puede abrir el bus SPI: %s\n", strerror (errno));
        exit(EXIT_FAILURE);
    }

    tickConfig(TS);

    for(;;)
        pause();

    return 0;
}


void tickHandler(int sig, siginfo_t si, voiduc)
{
    static int n=0;
    // Frecuencia: 100Hz
    // Generaci�n de se�al senoidal
    if(n<FS){
        n=n+1;
        float output = Ampsin(2PInFrec/FS);
        unsigned short registerValue = (unsigned short)(output+AD_DA_OFFSET);
        DAC121S101_SendRegisterValue(registerValue, myFd_DA);
    }
    else
        n=0;

    return;
}


void tickConfig(unsigned int sampling_period){

    timer_t timerid;
    struct sigevent sev;
    struct itimerspec its;
    struct sigaction sa;

    sa.sa_flags = 0;
    sa.sa_sigaction = tickHandler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) == -1)
        printf("error sigaction");

    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGALRM;
    sev.sigev_value.sival_ptr = &timerid;
    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1)
        printf("error timer_create");

    its.it_value.tv_sec = 1;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = sampling_period;

    if (timer_settime(timerid, 0, &its, NULL) == -1)
        printf("error timer_settime");

    return; 
}