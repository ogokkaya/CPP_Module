#pragma once

template <typename Swap>
void swap(Swap &a, Swap &b)
{
    Swap temp = a;
    a = b;
    b = temp;
}

template <typename MAX>
MAX max(MAX a, MAX b){
    return ((a > b) ? a : b);
}

template <typename MIN>
MIN min(MIN a, MIN b){
    return ((a < b) ? a : b);
}
