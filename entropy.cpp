#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include <cmath>
using namespace std;



int main(void)
{
    string input_string = "Hello world";
    size_t length = input_string.length();

    ostringstream output_stream;
    
    double entropy = 0.0;
    
    if(length > 0)
    {
        map<char, size_t> input_map;

        for(size_t i = 0; i < length; i++)
            input_map[input_string[i]]++;
        
        for(map<char, size_t>::const_iterator ci = input_map.begin(); ci != input_map.end(); ci++)
        {
            double probability = ci->second / static_cast<double>(length);
            
            output_stream << "Character: \'" << ci->first << "\', Count: " << ci->second << ", Probability: " << probability << endl;
            
            entropy += probability * log(probability);
        }
        
        entropy = -entropy;

    }

    cout << output_stream.str() << endl;
    cout << "Entropy: " << entropy << endl;
    
    
    return 0;
}
