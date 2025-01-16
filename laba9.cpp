#include <vector>
#include <iostream>

std::vector <int> vecX = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, -3, -4, 0};
std::vector <int> vecZ = {5, 7, 84, 543, 1, 0, 45, 10};

void Sum(int C, int D){
    int sumX = 0;
    int sumZ = 0;
    for (int i = 0; i < vecX.size(); ++i){
        if ((vecX[i] >= C) && (vecX[i] <= D)){
            vecX.erase(vecX.begin() + i);
            --i;
        }
    }
    for (int i = 0; i < vecZ.size(); ++i){
        if ((vecZ[i] >= C) && (vecZ[i] <= D)){
            vecZ.erase(vecZ.begin() + i);
            --i;
        }
    }
    for (int i = 0; i < vecX.size(); ++i){
        sumX += vecX[i];
    }
    std::cout << "Sum of VecX: "<< sumX << std::endl;
    for (int i = 0; i < vecZ.size(); ++i){
        sumZ += vecZ[i];
    }
    std::cout << "Sum of VecZ: " <<sumZ << std::endl;
}

int main(){
    int C;
    int D;
    std::cin >> C;
    std::cin >> D;
    Sum(C, D);
}