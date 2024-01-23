#include "solvers.hpp"

algebra::vector solvers::simple_iteration_solver(algebra::vector x0, algebra::vector &b, algebra::matrix &a, const double &t = 0.1)
{
    if (x0.size() != b.size() || x0.size() != a.size_rows() || x0.size() != a.size_cols())
    {
        throw std::invalid_argument("Incorrect vector or matrix size!\n");
    }
    if (fabs(t) < 1e-9)
    {
        throw std::invalid_argument("Incorrect thau coefficient!\n");
    }
    
    for(size_t iteration = 0; iteration < 500; iteration++)
    {
        algebra::vector temp = (a * x0) - b;
        if (temp.norm() / b.norm() < eps)
        {
            break;
        }
        x0 = x0 - (temp * t);
    }
    return x0;
}