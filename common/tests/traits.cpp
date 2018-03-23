
#include <catch.hpp>
#include <serial/aggregate_traits.hpp>


namespace {
    struct empty {};
    class priv { priv() {} };
    struct person {
        int age;
        const char* name;
    };
    struct family {
        person persons[5];
        int years;
    };
}

TEST_CASE("aggregates", "[traits]") {
    static_assert(traits::arity_of<empty>  == 0, "");
    static_assert(traits::arity_of<priv>  == -1, "");
    static_assert(traits::arity_of<person> == 2, "");
    static_assert(traits::arity_of<family> == 6, "");
}
