#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cerrno>

using namespace std;


void createDataShards(const string& fileLocation, const string& outputDir, int shardSize) {
    ifstream file(fileLocation);

    if (!file) {
        string error_msg = fileLocation + " was not opened properly!";
        throw runtime_error(error_msg);
    }

    string line;
    //get the first line that contains all the attribute' titles
    getline(file, line);
    string header = line; // Store the header for reuse in each shard file

    vector<string> samples;
    // Read all data lines
    while (getline(file, line)) {
        samples.push_back(line);
    }

    file.close();

    int totalSamples = samples.size();
    int numShards = ceil(static_cast<double>(totalSamples) / shardSize);


    // Create shard files
    for (int i = 0; i < numShards; ++i) {
        //shard file name
        string shardFile = outputDir + "/shard_" + to_string(i + 1) + ".txt";

        ofstream shard(shardFile);
        if (!shard) {
            cerr << "Error: Unable to create file: " << shardFile << endl;
            continue;
        }

        //header
        shard << header << endl;

        // Write rows for this shard
        for (int j = 0; j < shardSize && (i * shardSize + j) < totalSamples; ++j) {
            string row = samples[i * shardSize + j];

            // Format the row like in the given example Data:...
            stringstream ss(row);
            string token;
            shard << "Data: [";
            bool first = true;

            while (getline(ss, token, ',')) {
                if (!first) {
                    shard << ", ";
                }
                shard << token;
                first = false;
            }
            shard << "]" << endl;
        }

        shard.close();
        cout << "Created shard file: " << shardFile << endl;
    }
}

int main() {
    // Set the file location and output directory
    string fileLocation = "/Users/riyadrajan/Downloads/iot-shard.txt"; 
    string outputDir = "./shards";                                   

    int shardSize;
    cout << "Enter the size of each shard (number of samples per shard): ";
    cin >> shardSize;

    try {
        createDataShards(fileLocation, outputDir, shardSize);
        cout << "Data sharding completed successfully!" << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
