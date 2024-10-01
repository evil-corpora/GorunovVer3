#include<iostream>
#include<list>
#include<iterator>
#include<cmath>

struct farey_num {
    int nominator;
    int denominator;
};

class FareyNums {
    private:
    std::list<farey_num> farey_nums;

    public:
    int amt;

    FareyNums(int n) {
        amt = n;
    }

    void print_farey_nums() {
        std::list<farey_num>::iterator it;
        for(it = farey_nums.begin(); it != farey_nums.end(); it++) {
            std::cout<< it->nominator << "/" << it->denominator << " ";
        }
        std::cout << "\n";
    }

    void generate_farey() {
        // ИЗМЕНИТЬ КОД
    }

    farey_num approx_using_farey(float f) {
        if(f <= 0 || f >= 1) {
            return {0, 1};
        }
        std::list<farey_num>::iterator first_it, second_it; // итераторы соседних дробей Фарея
        farey_num first_n, second_n;
        for(first_it = farey_nums.begin(); first_it != --farey_nums.end(); first_it++)
        {
        second_it = first_it; ++second_it;
        first_n = *first_it; second_n = *second_it;
        // очевидно, что если a/b < f < c/d,
        // то ad < f * bd < cb
        float ad = first_n.nominator * second_n.denominator;
        float tbd = f * first_n.denominator * second_n.denominator;
        float cb = second_n.nominator * first_n.denominator;
        if((ad < tbd) && (tbd < cb)) {
            return first_n;
        } 
        }
    }
};

farey_num add_farey_nums(farey_num a, farey_num b) {
    farey_num c;
    c.nominator = a.nominator * b.denominator + b.nominator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    return c;
}

farey_num sub_farey_nums(farey_num a, farey_num b) {
    farey_num c;
    c.nominator = a.nominator * b.denominator - b.nominator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    return c;
}

farey_num mul_farey_nums(farey_num a, farey_num b) {
    farey_num c;
    c.nominator = a.nominator * b.nominator;
    c.denominator = a.denominator * b.denominator;
    return c;
}

farey_num div_farey_nums(farey_num a, farey_num b) {
    farey_num c;
    c.nominator = a.nominator * b.denominator;
    c.denominator = a.denominator * b.nominator;
    return c;
}

int main() {
    FareyNums sample(20); 
    sample.generate_farey();
    std::cout << "\n Дроби Фарея порядка " << sample.amt << " ";
    sample.print_farey_nums(); 
    farey_num X, Y;
    float t = (float)1 / 4 / std::cos(-0.385); // 1-е число, 
    X = sample.approx_using_farey(t); 
    std::cout << "\n Дробь "<<X.nominator<<"/"<<X.denominator<<" - приближение " << t;
    t = (float)1 / exp(2.0); // 2-е число, 
    Y = sample.approx_using_farey(t); 
    std::cout << "\n" << Y.nominator << "/" << Y.denominator << " - приближение " << t;
    std::cout << "\n";
    // результаты арифметических операций над приближениями чисел
    // дробями Фарея:
    std::cout << X.nominator << "/" << X.denominator << " * " << Y.nominator << "/" << Y.denominator << " = " << mul_farey_nums(X, Y).nominator << "/" << mul_farey_nums(X, Y).denominator << "\n";
    std::cout << X.nominator << "/" << X.denominator << " / " << Y.nominator << "/" << Y.denominator << " = " << div_farey_nums(X, Y).nominator << "/" << div_farey_nums(X, Y).denominator << "\n";
    std::cout << X.nominator << "/" << X.denominator << " - " << Y.nominator << "/" << Y.denominator << " = " << sub_farey_nums(X, Y).nominator << "/" << sub_farey_nums(X, Y).denominator << "\n";
    std::cout << X.nominator << "/" << X.denominator << " + " << Y.nominator << "/" << Y.denominator << " = " << add_farey_nums(X, Y).nominator << "/" << add_farey_nums(X, Y).denominator << "\n";
    return 0;

}
