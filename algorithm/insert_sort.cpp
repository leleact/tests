#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

void generateData( std::vector<int>& vec );
std::vector<int> insert_sort( std::vector<int>& input );

int main()
{
    std::vector<int> data;
    generateData( data );

    for( int &i : data ) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::vector<int> output = insert_sort( data );
    for( int &i : output ) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}

void generateData( std::vector<int>& vec )
{
    std::srand( time(NULL) );
    for ( int i = 0; i < 20; i++ )
        vec.push_back( std::rand() );
}

std::vector<int> insert_sort( std::vector<int>& input )
{
    for ( size_t i = 1; i < input.size(); i++ )
    {
        int key = input[ i ];
        int j = i - 1;
        while( j >= 0 && input[j] > key )
        {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = key;
    }

    return input;
}
