#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <fstream>

using namespace std;

double random1 () //The function, which generates a random number.
{
    double R =(double)rand()/((double)RAND_MAX+1.0) ;
    return R;
}
int N = 100;
//I define the number of fleas.
long double H[101] = {0};
//H, which counts how often n fleas are on A dog.
int flea[100] ={0};
//Distribution for the number of fleas n on the dog A.
long double P[100] ={0};
//I define theoretical prediction of P.
long double PT[100];

int main()
{
    fstream plik;
    srand( time(NULL) );
    int time = 10000;
    //I define how many times loop "time" need to be done.
    int NA = N;
    //On the dog A, there is N fleas in time 0.
    int NB = 0;
    //The dog B is clear in zero time.
    double u,p;
    //u is the random number.
    //p is probability that a randomly chosen flea hops from one dog to the other.
    p=0.8;
    int k;
    plik.open("results.txt",ios::out);
    for(int i=0; i<=time; i++)
        //There is a loop which go thought the time.
    {
        u = random1();
        k = floor(u*N);
        u = random1();
        if(p<u) //If random number is bigger then p.
        {
            if(flea[k] == 0)
                //If number of fleas on A dog is equal to 0.
            {
                flea[k]=1;
                NA=NA-1;
                //We substruct 1 to the number of fleas on dog A.
                NB=NB+1;
                //We add 1 to the number of fleas on dog B.
            }
            else{ //If number of fleas on dog A is not equal zero.
                flea[k]=0;
                NA=NA+1;
                //We add 1 to the number of fleas on dog A.
                NB=NB-1;
                //We substruct 1 to the number of fleas on dog B.
            }
        }
        plik<<i<<" "<<NA<<" "<<NB<<endl; /We save results NA and NB to the file.
        //H[NA]=H[NA]+1;
        //cout<<H[NA]<<endl;
    }
   // for(int i=0; i< N+1; i++)
    //{
    //cout<<i<<" "<<H[i]<<endl;
    //P[i] = H[i]/time;
    // cout<<i<<" "<<P[i]<<endl;
    //plik<<i<<" "<<P[i]<<endl;
    //We save results PN and n to the file.
    //}
    plik.close();
    return 0;
}
