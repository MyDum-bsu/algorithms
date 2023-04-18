#include <iostream>
#include <vector>

int main() {
    std::vector<unsigned long long> frontNUM;
    frontNUM.push_back(80); //0
    frontNUM.push_back(20); //coins
//frontNUM.push_back(32);
    frontNUM.push_back(68); //triangle
//frontNUM.push_back(80);
    frontNUM.push_back(60); //3
//frontNUM.push_back(105) ;
    frontNUM.push_back(40); //4

    frontNUM.push_back(68); //5
    frontNUM.push_back(76); //6
    frontNUM.push_back(36); //7
    frontNUM.push_back(84); //8
    frontNUM.push_back(76); //9
    std::string temp;
    unsigned long long red;
    unsigned long long blue;
    unsigned long long green;
    std::cin >> temp;
    std::cin >> red >> green >> blue;
    unsigned long long usedFront = 0;
    bool can_red = true;
    bool can_green = true;
    bool can_blue = true;
    for (unsigned long long i = 0; i < temp.size(); i++) {
        usedFront += frontNUM[temp[i] - '0'];
        can_red &= usedFront <= red;
        can_green &= usedFront <= green;
        can_blue &= usedFront <= blue;
    }
    if (!can_blue && !can_red && !can_green) {
        std::cout << "No";
        return 0;
    }
    if (can_red) {
        std::cout << "Red" << std::endl;
    }
    if (can_green) {
        std::cout << "Green" << std::endl;
    }
    if (can_blue) {
        std::cout << "Blue" << std::endl;
    }
    return 0;
}