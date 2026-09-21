#include <iostream>
#include <queue>
#include <vector>

struct RoomNode {
    std::vector<std::string> enemies;
    std::vector<std::string> items;
    bool hasChest;
    bool hasLockedDoor;

    //room structure
    RoomNode* left;
    RoomNode* right;

    //constructor
    RoomNode() : hasChest(false), hasLockedDoor(false), left(nullptr), right(nullptr) {}

class MapTree {
    private:
        RoomNode* root;

    public:
        //constructor
        MapTree() : root(nullptr) {}

        //insert node into binary tree
        void insertNode(RoomNode) {
            RoomNode* newNode = new RoomNode();

            if (root == nullptr) {
                root = newNode;
                return;
            }

            std::queue<RoomNode*> q;
            q.push(root);

            while(!q.empty()) {
                RoomNode* current = q.front();
                q.pop();

                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                } else {
                    q.push(current->left);
                }

                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                } else {
                    q.push(current->right);
                }
            }
        }


}
