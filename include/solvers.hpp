#pragma once

#include "matrix.hpp"

class solvers
{
    static constexpr double eps = 1e-9;
public:
    solvers() = delete;

    static algebra::vector simple_iteration_solver(algebra::vector x0, algebra::vector &b, algebra::matrix &a, const double &t);
};
