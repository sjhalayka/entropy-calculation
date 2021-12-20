#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;




int main(void)
{
    vector<long signed int> input = {102, 102, 102, 1, 0, -1, -2000, -3, 3, 102, 1, 0, -1, -1, -2000, -2000, -2000, -2000, -1, -1, 0, 0, 1, 3};
    
    size_t length = input.size();

    double entropy = 0.0;

    if (length > 0)
    {
        map<long signed int, size_t> input_map;

        for (size_t i = 0; i < length; i++)
            input_map[input[i]]++;

        for (map<long signed int, size_t>::const_iterator ci = input_map.begin(); ci != input_map.end(); ci++)
        {
            double probability = ci->second / static_cast<double>(length);

            cout << "Number: \'" << ci->first << "\', Count: " << ci->second << ", Probability: " << probability << endl;

            entropy += probability * log(probability);
        }

        entropy = -entropy;
    }

    cout << "Entropy: " << entropy << endl;



    return 0;
}