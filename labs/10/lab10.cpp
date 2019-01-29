/*
 * Author  : Victor Truong & Nicholas Spector
 * CS 2    : MTWR, 7:30a – 12:30p
 * Lab 10  : Arrays
 * Due date: 1/28/19
 */
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

double getPracticalMean(double sequence[], // IN: Sequence array to be populated
                        int size);         // IN: Size of sequence
double getPracticalVariance(double sequence[], // IN: Sequence array to be populated
                            int size);         // IN: Size of sequence
double getTheoreticalMean(double a,  // IN: Lower limit of the random float
                          double b); // IN: Upper limit of the random float
double getTheoreticalVariance(double a,  // IN: Lower limit of the random float
                              double b); // IN: Upper limit of the random float
void setRandomSequence(double sequence[], // IN: Sequence array to be populated
                       int size,          // IN: Size of sequence
                       double a,          // IN: Lower limit of the random float
                       double b);         // IN: Upper limit of the random float
double randFloat(double a,  // IN: Lower limit of the random float
                 double b); // IN: Upper limit of the random float

/*
 * Functions with Pass by Reference Parameters
 *
 * This program
 *
 * IN:
 *   S1_SIZE    : Size of first sequence
 *   S2_SIZE    : Size of second sequence
 *   LOWER_LIMIT: Lower limit of the random float
 *   UPPER_LIMIT: Upper limit of the random float
 * OUT:
 *   Outputs theoretical mean and variance, and practical mean and variance.
 */
int main()
{
    // cout <<
    //     "*****************************************\n"
    //     "  Author: Victor Truong & Nicholas Spector\n"
    //     "  ID    : 10180511\n"
    //     "  CS 2  : MTWR, 7:30a – 12:30p\n"
    //     "  Lab 10: Array\n"
    //     "*****************************************\n";
    srand(500);

    const int S1_SIZE = 100;    // IN: Size of first sequence
    const int S2_SIZE = 10000;  // IN: Size of second sequence
    const int LOWER_LIMIT = 4;  // IN: Lower limit of the random float
    const int UPPER_LIMIT = 10; // IN: Upper limit of the random float
    double sequence1[S1_SIZE];  // PROC: First sequence
    double sequence2[S2_SIZE];  // PROC: Second sequence

    // PROC: Populate sequences with random floats
    setRandomSequence(sequence1, S1_SIZE, LOWER_LIMIT, UPPER_LIMIT);
    setRandomSequence(sequence2, S2_SIZE, LOWER_LIMIT, UPPER_LIMIT);

    // OUT: Print practical and theoretical mean and variance
    cout << getTheoreticalMean(LOWER_LIMIT, UPPER_LIMIT) << " "
        << getPracticalMean(sequence1, S1_SIZE) << " "
        << getTheoreticalVariance(LOWER_LIMIT, UPPER_LIMIT) << " "
        << getPracticalVariance(sequence1, S1_SIZE)
        << endl;
    cout << getTheoreticalMean(LOWER_LIMIT, UPPER_LIMIT) << " "
        << getPracticalMean(sequence2, S2_SIZE) << " "
        << getTheoreticalVariance(LOWER_LIMIT, UPPER_LIMIT) << " "
        << getPracticalVariance(sequence2, S2_SIZE)
        << endl;

    return 0;
}

double getPracticalMean(double sequence[], int size)
{
    double mean;
    double sum;

    mean = 0;
    sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += sequence[i];
    }
    mean = sum / size;

    return mean;
}

double getPracticalVariance(double sequence[], int size)
{
    double variance;
    double difference;
    double mean;

    variance = 0;
    difference = 0;
    mean = getPracticalMean(sequence, size);

    for(int i = 0; i < size; i++)
    {
        difference += pow(sequence[i] - mean, 2);
    }
    variance = difference / size;

    return variance;
}

/*
 * FUNCTION: getTheoreticalMean
 * 
 * IN:
 *   a: Lower limit of the random float
 *   b: Upper limit of the random float
 * OUT:
 *   The theoretical mean of a and b using formula.
 */
double getTheoreticalMean(double a, double b)
{
    return (a + b) / 2.0;
}

/*
 * FUNCTION: getTheoreticalVariance
 * 
 * IN:
 *   a: Lower limit of the random float
 *   b: Upper limit of the random float
 * OUT:
 *   The theoretical variance of a and b using formula.
 */
double getTheoreticalVariance(double a, double b)
{
    return pow(b - a, 2) / 12.0;
}

/*
 * FUNCTION: setRandomSequence
 * 
 * IN:
 *   sequence[]: Sequence array to be populated
 *   size      : Size of sequence
 *   a         : Lower limit of the random float
 *   b         : Upper limit of the random float
 * OUT:
 *   Populated sequence with random float values between a and b.
 */
void setRandomSequence(double sequence[], int size, double a, double b)
{
    for (int i = 0; i < size; i++)
    {
        sequence[i] = randFloat(a, b);
    }
}

/*
 * FUNCTION: randFloat
 * 
 * IN:
 *   a: Lower limit of the random float
 *   b: Upper limit of the random float
 * OUT:
 *   Outputs a random float between a and b.
 */
double randFloat(double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}