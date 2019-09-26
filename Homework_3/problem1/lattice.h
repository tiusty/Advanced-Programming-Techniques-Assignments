/*
Author: Alex Agudelo
Class: ECE 6122
Last date modified: 9/25/2019
Description: 
*/

#ifndef HOMEWORK_3_LATTICE_H
#define HOMEWORK_3_LATTICE_H

#include <array>

class Lattice {

public: // Methods
    Lattice() = default;
    Lattice(unsigned int height, unsigned width);
    void findNumberOfPaths();
    void findNumberOfPathsSingleThread();
    void findNumberOfPathsOpenMp();
    unsigned int numLatNodes();
    unsigned int getNode(unsigned int row, unsigned int col);
    unsigned long long int getParentSum(unsigned int row, unsigned int col);
    void outputResults();
public: // Members
    static constexpr unsigned int maxLatElem{400000};
    std::array<unsigned long long int, maxLatElem> latNodes{0};
private: // Methods
private: // Members
    static constexpr bool openMPSupport{true};
    /**
     * Constexpr for the output file name
     */
    static constexpr const char* outputFileName{"output1.txt"};
    unsigned int latHeight{0};
    unsigned int latWidth{0};
    unsigned int latHeightNodes{0};
    unsigned int latWidthNodes{0};
};


#endif //HOMEWORK_3_LATTICE_H
