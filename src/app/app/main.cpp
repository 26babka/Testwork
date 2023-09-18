#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <random>
#include <memory>
#include <cmath>
#include <omp.h>

#include <curves/curves.h>

int main() {

    try {
        const size_t n = 100000;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> frand(0, 10);

        std::vector<std::shared_ptr<curves::CurvesBase>> curv;

        for (size_t i = 0; i < n; i++) {
            if(i % 3 == 0)
                curv.emplace_back(std::make_shared<curves::Circle>(frand(gen), frand(gen), frand(gen)));
            if(i % 3 == 1)
                curv.emplace_back(std::make_shared<curves::Ellipse>(frand(gen), frand(gen), frand(gen), frand(gen)));
            if(i % 3 == 2)
                curv.emplace_back(std::make_shared<curves::Helix>(frand(gen), frand(gen), frand(gen), frand(gen), frand(gen)));
        }

        for (const auto &item : curv) {
            std::cout << std::fixed << std::setprecision(2) << std::setfill(' ') << std::setw(15) 
            << "Point: " << item->get_point(M_PI_4) << std::setw(20) 
            << "Derivative: " << item->get_derivative(M_PI_4) << "\n";
        }


        std::vector<std::shared_ptr<curves::CurvesBase>> circles;

        std::copy_if(curv.begin(), curv.end(),
                    std::back_inserter(circles),
                    [](const auto &x) { return typeid(*x) ==  typeid(curves::Circle); });

        std::sort(circles.begin(), circles.end(), [](const auto &a, const auto &b) { 
            return dynamic_cast<curves::Circle*>(a.get())->get_radius() < dynamic_cast<curves::Circle*>(b.get())->get_radius(); });

        double sum = 0;
        #pragma omp parallel num_threads(omp_get_thread_num())
        {
            #pragma omp for reduction (+:sum)
            for (const auto &item : circles) {
                sum += dynamic_cast<curves::Circle*>(item.get())->get_radius();
            }
        }
        std::cout << "\n\nSum of radii = " << sum << '\n';
    } catch (std::exception &ex) {
        std::cout << ex.what();
    }
    
}