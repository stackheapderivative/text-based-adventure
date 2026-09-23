#include <iostream>
#include <vector>

struct RoomNode {
    public:
        //room id
        int roomID;

        //pointers
        RoomNode* left;
        RoomNode* right;

        //constructor
        RoomNode() : roomID(0), left(nullptr), right(nullptr) {}
};

class WorldMap {
    private:
        RoomNode* root;
        int counter;

    public:
        //constructor
        WorldMap() : root(nullptr), counter(0) {}
        //destructor
        ~WorldMap() {
            if (root != nullptr) {
                deleteStructure(root);
            }
        }

        //functions to create the tree
        void generateStructure(int depth); // for root
        void generateStructure(RoomNode* room, int depth);
        void deleteStructure(RoomNode* room);
};
