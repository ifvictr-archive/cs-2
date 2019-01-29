/*
 * Author      : Victor Truong
 * CS 2        : MTWR, 7:30a – 12:30p
 * Assignment 8: Noise Signals
 * Due date    : 1/30/19
 */
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void runPart1();
void runPart2();
void runPart3();
void runPart4();
void printSequenceResults(double sequence[],   // IN: Sequence array to process
                          int size,            // IN: Size of sequence
                          double a,            // IN: Lower limit of the floats
                          double b);           // IN: Upper limit of the floats
double getPracticalMean(double sequence[],     // IN: Sequence array to process
                        int size);             // IN: Size of sequence
double getPracticalVariance(double sequence[], // IN: Sequence array to process
                            int size);         // IN: Size of sequence
double getTheoreticalMean(double a,            // IN: Lower limit of the floats
                          double b);           // IN: Upper limit of the floats
double getTheoreticalVariance(double a,        // IN: Lower limit of the floats
                              double b);       // IN: Upper limit of the floats
void setRandomSequence(double sequence[],      // IN: Sequence array to be populated
                       int size,               // IN: Size of sequence
                       double a,               // IN: Lower limit of the floats
                       double b);              // IN: Upper limit of the floats
double randFloat(double a,                     // IN: Lower limit of the floats
                 double b);                    // IN: Upper limit of the floats
double rand_mv(double mean,                    // IN: Desired mean
               double variance);               // IN: Desired variance

/*
 * Noise Signals
 *
 * This program calculates both the mean and variance of a sequence of numbers,
 * with all the numbers falling within a specified range. Additionally, it can
 * derive the lower and upper limits needed to generate certain random float
 * values using mean and variance inputs.
 */
int main()
{
    // cout <<
    //     "*****************************************\n"
    //     "  Author    : Victor Truong\n"
    //     "  ID        : 10180511\n"
    //     "  CS 2      : MTWR, 7:30a – 12:30p\n"
    //     "  Assignment: Noise Signals\n"
    //     "*****************************************\n";
    srand(500);

    // PROC: Run all components of the program
    runPart1();
    runPart2();
    runPart3();
    runPart4();

    return 0;
}

/*
 * FUNCTION: runPart1
 */
void runPart1()
{
    const int SEQ1_SIZE = 100;    // IN: Size of first sequence
    const int SEQ2_SIZE = 10000;  // IN: Size of second sequence
    const int LOWER_LIMIT = 4;    // IN: Lower limit of the random float
    const int UPPER_LIMIT = 10;   // IN: Upper limit of the random float
    double sequence1[SEQ1_SIZE];  // PROC: First sequence
    double sequence2[SEQ2_SIZE];  // PROC: Second sequence

    // PROC: Populate sequences with random floats
    setRandomSequence(sequence1, SEQ1_SIZE, LOWER_LIMIT, UPPER_LIMIT);
    setRandomSequence(sequence2, SEQ2_SIZE, LOWER_LIMIT, UPPER_LIMIT);

    // OUT: Print practical and theoretical mean and variance
    printSequenceResults(sequence1, SEQ1_SIZE, LOWER_LIMIT, UPPER_LIMIT);
    printSequenceResults(sequence2, SEQ2_SIZE, LOWER_LIMIT, UPPER_LIMIT);
}

/*
 * FUNCTION: runPart2
 */
void runPart2()
{
    const int SEQ_SIZE = 500;                   // IN: Size of sequences
    const double SEQ1_LOWER_LIMIT = 2.77525513; // IN: Lower limit of sequence 1
    const double SEQ1_UPPER_LIMIT = 5.22474487; // IN: Upper limit of sequence 1
    const double SEQ2_LOWER_LIMIT = 1.55051025; // IN: Lower limit of sequence 2
    const double SEQ2_UPPER_LIMIT = 6.44948974; // IN: Upper limit of sequence 2
    double sequence1[SEQ_SIZE];                 // PROC: First sequence
    double sequence2[SEQ_SIZE];                 // PROC: Second sequence

    // PROC: Populate sequences with random floats
    setRandomSequence(sequence1, SEQ_SIZE, SEQ1_LOWER_LIMIT, SEQ1_UPPER_LIMIT);
    setRandomSequence(sequence2, SEQ_SIZE, SEQ2_LOWER_LIMIT, SEQ2_UPPER_LIMIT);

    // OUT: Print practical and theoretical mean and variance
    printSequenceResults(sequence1, SEQ_SIZE, SEQ1_LOWER_LIMIT, SEQ1_UPPER_LIMIT);
    printSequenceResults(sequence2, SEQ_SIZE, SEQ2_LOWER_LIMIT, SEQ2_UPPER_LIMIT);
}

/*
 * FUNCTION: runPart3
 */
void runPart3()
{
    const int SEQ_SIZE = 500;        // IN: Size of sequences
    const int SEQ1_LOWER_LIMIT = -3; // IN: Lower limit of sequence 1
    const int SEQ1_UPPER_LIMIT = 3;  // IN: Upper limit of sequence 1
    const int SEQ2_LOWER_LIMIT = -7; // IN: Lower limit of sequence 2
    const int SEQ2_UPPER_LIMIT = -1; // IN: Upper limit of sequence 2
    double sequence1[SEQ_SIZE];      // PROC: First sequence
    double sequence2[SEQ_SIZE];      // PROC: Second sequence

    // PROC: Populate sequences with random floats
    setRandomSequence(sequence1, SEQ_SIZE, SEQ1_LOWER_LIMIT, SEQ1_UPPER_LIMIT);
    setRandomSequence(sequence2, SEQ_SIZE, SEQ2_LOWER_LIMIT, SEQ2_UPPER_LIMIT);

    // OUT: Print practical and theoretical mean and variance
    printSequenceResults(sequence1, SEQ_SIZE, SEQ1_LOWER_LIMIT, SEQ1_UPPER_LIMIT);
    printSequenceResults(sequence2, SEQ_SIZE, SEQ2_LOWER_LIMIT, SEQ2_UPPER_LIMIT);
}

/*
 * FUNCTION: runPart4
 */
void runPart4()
{
    double mean;     // IN: Mean to calculate limits
    double variance; // IN: Variance to calculate limits

    // IN: Prompt user for mean and variance
    cout << "Enter Mean: ";
    cin >> mean;
    cout << endl;
    cout << "Enter Variance: ";
    cin >> variance;
    cout << endl;

    // OUT: Print resulting limit values from input mean and variance
    rand_mv(mean, variance);
}

/*
 * FUNCTION: printSequenceResults
 * 
 * IN:
 *   sequence[]: Sequence array to be populated
 *   size      : Size of sequence
 *   a         : Lower limit of the random float
 *   b         : Upper limit of the random float
 */
void printSequenceResults(double sequence[], int size, double a, double b)
{
    cout << getTheoreticalMean(a, b) << " "
        << getPracticalMean(sequence, size) << " "
        << getTheoreticalVariance(a, b) << " "
        << getPracticalVariance(sequence, size)
        << endl;
}
/*
 * FUNCTION: getPracticalMean
 * 
 * IN:
 *   sequence[]: Sequence array to process
 *   size      : Size of sequence
 * OUT:
 *   The calculated mean based on probability
 */
double getPracticalMean(double sequence[], int size)
{
    double sum;  // PROC: Total sum of all numbers in sequence
    double mean; // PROC: Mean of sequence

    sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += sequence[i];
    }
    mean = sum / size;

    return mean;
}

/*
 * FUNCTION: getPracticalVariance
 * 
 * IN:
 *   sequence[]: Sequence array to process
 *   size      : Size of sequence
 * OUT:
 *   The calculated variance based on probability
 */
double getPracticalVariance(double sequence[], int size)
{
    double difference; // IN: Total difference between sequence and mean
    double mean;       // IN: Mean of sequence
    double variance;   // PROC: Calculated average difference

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

/*
 * FUNCTION: rand_mv
 * 
 * IN:
 *   mean    : Desired mean
 *   variance: Desired variance
 * OUT:
 *   Outputs a random float between a and b (calculated from mean and variance).
 */
double rand_mv(double mean, double variance)
{
    double a; // PROC: Lower limit of the random float
    double b; // PROC: Upper limit of the random float

    b = (mean * 2 + sqrt(12 * variance)) / 2;
    a = (2 * mean) - b;

    cout << a << " " << b << endl; // OUT: Print limit values (for testing)
    return randFloat(a, b);
}