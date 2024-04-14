#include <random>

using namespace std;

//This creates a seed for the GetRandomNumberByRange function
random_device randomDevice;
mt19937 generator(randomDevice());

int GetRandomNumberByRange(int minNum, int maxNum)
{
    //Gets a random number in the given range (inclusive)
    uniform_int_distribution<int> distribution(minNum, maxNum);
    return distribution(generator);
}