#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <vecX.hpp>
#include <unordered_map>
#include <utility>

int iter = 0;

std::vector<int> SplitWord(std::string line, std::unordered_map<std::string, int> &hash)
{
    std::vector<int> vec;
    std::string crnt = "";
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ',')
        {
            try
            {
                vec.push_back(std::stoi(crnt));
            }
            catch (const std::exception &e)
            {
            }
            crnt = "";
            continue;
        }
        crnt += line[i];
    }
    if (crnt.size())
    {
        if (hash.find(crnt) == hash.end())
        {
            hash[crnt] = iter;
            iter++;
        }
        vec.push_back(hash[crnt]);
    }
    return vec;
}

std::vector<std::vector<int>> ReadFile(std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "File Not Open" << std::endl;
        std::exit(0);
    }

    std::string line;
    std::unordered_map<std::string, int> hash;
    std::vector<std::vector<int>> fileData;
    while (std::getline(file, line))
    {
        fileData.push_back(SplitWord(line, hash));
    }
    return fileData;
}

std::vector<std::pair<vecX<double>, vecX<int>>> CreateBatch(std::vector<std::vector<int>> &data, int batchSize)
{
    std::vector<std::pair<vecX<double>, vecX<int>>> batchData;
    int inputIndex = 1; // first entry is not true entry
    while(inputIndex < data.size())
    {
        int batchLen = std::min((int)data.size(), inputIndex + batchSize);
        vecX<double> tempData(batchSize, 4, 0);
        vecX<int> tempTarget(batchSize, 1, 0);
        
        // Extract batch size input
        for(int i = 0; i < batchSize; i++)
        {
            if(inputIndex + i >= batchLen)
                break; 
            for(int j = 1; j < 5; j++)
            {    
                tempData.push(i, j - 1, data[inputIndex + i][j]);
            }
            tempTarget.push(i, 0, (int)data[inputIndex + i][5]);
        }
        inputIndex += batchSize;
        std::pair<vecX<double>, vecX<int>> temp = {tempData, tempTarget};
        batchData.push_back(temp);
    }
    return batchData;
}