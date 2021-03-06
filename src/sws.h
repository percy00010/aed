#ifndef _SWS_H_
#define _SWS_H_

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <mutex>

using namespace std;

void swap1(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

bool compare(int a, int b){
    if(a>b)    return  true;
    else    return false;
    //return (v_ab<int>(a)<v_ab<int>(b))? true: false;
}

void print(int *a, int t){
    for(int i=0; i<t; i++)  cout << *(a+i) << " ";
    cout << endl;
}

void pull_al(int *a, int *b, int t){
    srand(time(NULL));
    int tm;
    for(int i=0; i<t; i++){
        tm = rand()%t;
        *(a+i) = tm;
        *(b+i) = tm;
    }
}

void p(int *a, int t){
    srand(time(NULL));
    for(int i=0; i<t; i++){
        *(a+i) = rand()%t;
    }
}

void pull(int *a, int *b, int *c, int*d, int t){
    int temp;
    for(int i=0; i<t; i++){
        temp = rand()%t;
        *(a+i) = temp;
        *(b+i) = temp;
        *(c+i) = temp;
        *(d+i) = temp;
    }
}

double time(int *a, int t, void (*p)(int *, int)){
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);
    p(a, t);
    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    return tiempo;
}

void dat(FILE *a, int *A, int t, void (*p)(int *, int)){
    double tim = (time(A, t,p)/1000);
    fprintf(a, "%d\t", t);
    fprintf(a, "%lf\n", tim);
}

void dat_t(FILE *a, int *A, int t, void (*p)(int *, int)){
    double tim = (double)(time(A, t,p)/1000);
    fprintf(a, "%lf\t", tim);
}

template<class T, class C>
double time_insert(T *&a, C t){
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);
    
    srand(time(NULL));
    for(C i=0; i<t; i++){
        a->insert(rand()%t);
    }

    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    return tiempo;
}

void timestamp(){
# define TIME_SIZE 29
  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  size_t len;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );
  if ( len != 0 ) cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}

#endif