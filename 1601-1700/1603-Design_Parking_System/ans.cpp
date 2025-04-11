class ParkingSystem {
public:
    vector<int> v;
    vector<int> limit;

    ParkingSystem(int big, int medium, int small) : v(3, 0) {
        limit.emplace_back(big);
        limit.emplace_back(medium);
        limit.emplace_back(small);
    }
    
    bool addCar(int carType) {
        --carType;
        if (v[carType] < limit[carType]) {
            ++v[carType];
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

