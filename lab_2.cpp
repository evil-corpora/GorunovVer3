#include <iostream>
#include <vector>
#include <random>

struct Node {
    float value;
    Node* rhs;
    Node* lhs;
};

void add_node(Node*& root, float value) {
    Node* new_node = new Node();
    new_node->value = value;
    new_node->lhs = nullptr;
    new_node->rhs = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (value < current->value) {
            if (current->lhs == nullptr) {
                current->lhs = new_node;
                return;
            } else {
                current = current->lhs;
            }
        } else {
            if (current->rhs == nullptr) {
                current->rhs = new_node;
                return;
            } else {
                current = current->rhs;
            }
        }
    }
    }

Node* create_binary_tree(std::vector<float>& values) {
    Node* root = new Node();
    root->value = values[0];
    root->lhs = nullptr;
    root->rhs = nullptr;

    for (int i = 1; i < values.size(); i++) {
        add_node(root, values[i]);
    }
    return root;
}

bool find(Node* root, float value) {
    if (root == nullptr) {
        return false;
    }
    Node* current = root;
    while (current != nullptr) {
        if (value == current->value) {
            return true;
        }
        if (value < current->value) {
            current = current->lhs;
        }
        else {
            current = current->rhs;
        }
    }
    return false;
}

std::vector<float> get_sorted_values(Node* root, std::vector<float>& vec) {
    if (root == nullptr) {
        return vec;
    }
    get_sorted_values(root->lhs, vec);
    vec.push_back(root->value);
    get_sorted_values(root->rhs, vec);
    return vec;
}

void print_vector(std::vector<float> vec) {
    std::cout << "Первые и последние 10 элементов массива: { ";
    for (int i = 0; i < 10; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "... ";
    for (int i = vec.size() - 10; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "}" << std::endl;
}

std::vector<float> initialize_vector(int size) {
    std::random_device rd;  // Получаем случайное значение из устройства
    std::mt19937 gen(rd());  // Инициализируем генератор
    std::uniform_real_distribution<double> dis(-50.0, 50.0);  // Определяем распределение
    
    std::vector<float> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = dis(gen);
    }
    return vec;
}

int main() {
    std::vector<float> vec = initialize_vector(50000);
    std::cout << "Изначальный массив:\n";
    print_vector(vec);
    Node* root = create_binary_tree(vec);
    vec.clear();
    get_sorted_values(root, vec);
    std::cout << "Массив, полученный из БДП:\n";
    print_vector(vec);
    return 0;
}

