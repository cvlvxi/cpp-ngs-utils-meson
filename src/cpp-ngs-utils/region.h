#pragma once

#include <intervaltree.hpp>
#include <iostream>

using namespace Intervals;
using std::cout;

using std::cout;


namespace cngs {
    class Region {
    public:
        static void test() {
            IntervalTree<int> tree;

            // Insert intervals to the tree
            tree.insert({20, 30});
            tree.insert({40, 60});
            tree.insert({70, 90});
            tree.insert({60, 70});
            tree.insert({40, 90});
            tree.insert({80, 90});

            cout << tree << "\n";
        }

    private:
    };
}// namespace cngs
