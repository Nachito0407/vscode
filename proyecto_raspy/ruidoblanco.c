#include "dsp.h"

int main(void)
{
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

    // Inicializar la semilla del generador de n�meros aleatorios
    srand(time(NULL));

    for(;;)
        pause();

    return 0;
}

// Funci�n para generar un n�mero flotante aleatorio en un rango
float random_float_in_range(float min, float max) {
    return min + (float)rand() / (float)RAND_MAX * (max - min);
}


void tickHandler(int sig, siginfo_t si, voiduc)
{
    unsigned short registerValue;
    float output;
    // procesamiento de muestras de entrada
    // Generar y mostrar n�meros aleatorios flotantes
    float float_min = 0.0, float_max = 4000.0;
    output = random_float_in_range(float_min, float_max);
    registerValue = (unsigned short)(output);
    DAC121S101_SendRegisterValue(registerValue, myFd_DA);

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