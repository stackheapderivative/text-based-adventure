#include "dungeon.hpp"

void WorldMap::generateStructure(int depth) {

    if (root == nullptr) {
       root = new RoomNode;
    }
    std::cout << "Root made: ID_" << root->roomID << std::endl;
    if (depth > 0) {
        if (root->left == nullptr) {
            counter++;
            root->left = new RoomNode;
            root->left->roomID = counter;
            std::cout << "Node made: ID_" << root->left->roomID << "\nDepth: "<< depth << std::endl;
            generateStructure(root->left, depth - 1);
        }

        if (root->right == nullptr) {
            counter++;
            root->right = new RoomNode;
            root->right->roomID = counter;
            std::cout << "Node made: ID_" << root->right->roomID << "\nDepth: "<< depth << std::endl;
            generateStructure(root->right, depth - 1);
        }
    }

}

void WorldMap::generateStructure(RoomNode* room, int depth) {

    if (depth > 0) {
        if (room->left == nullptr) {
            counter++;
            room->left = new RoomNode;
            room->left->roomID = counter;
            std::cout << "Node made: ID_" << room->left->roomID << "\nDepth: "<< depth << std::endl;
            generateStructure(room->left, depth - 1);
        }

        if (room->right == nullptr) {
            counter++;
            room->right = new RoomNode;
            room->right->roomID = counter;
            std::cout << "Node made: ID_" << room->right->roomID << "\nDepth: "<< depth << std::endl;
            generateStructure(room->right, depth - 1);
        }
    }
}

void WorldMap::deleteStructure(RoomNode* room) {
    if (room->left != nullptr) {
        deleteStructure(room->left);
    }

    if (room->right != nullptr) {
        deleteStructure(room->right);
    }

    std::cout << "Successfully deleted: ID_" << room->roomID << std::endl;
    delete room;
}
