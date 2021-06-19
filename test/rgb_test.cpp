#include <catch2/catch.hpp>
#include <color-vec.hpp>

using namespace Catch::literals;

TEST_CASE("make_rgb single value / alpha constructor", "=") {

    auto test_color = color_vec::make_rgb(255, 0.9f);
    CHECK(test_color.x == 1.0f);
    CHECK(test_color.y == 1.0f);
    CHECK(test_color.z == 1.0f);
    CHECK(test_color.w == 0.9f);
    CHECK(test_color.r == 255.0f);
    CHECK(test_color.g == 255.0f);
    CHECK(test_color.b == 255.0f);
    CHECK(test_color.a == 0.9f);
}

TEST_CASE("color a and w are same", "=") {
    auto test_color = color_vec::make_rgb(255, 0.9f);
    test_color.w += 0.1;
    CHECK(test_color.w == 1.0f);
    CHECK(test_color.a == 1.0f);
}

TEST_CASE("rgb_access +", "=") {
    auto test_color = color_vec::make_rgb(254, 1.0f);
    CHECK(test_color.r == 254.0f);
    REQUIRE(test_color.r + 0 == 254.0f);
    CHECK(test_color.r == 254.0f);
    REQUIRE(test_color.r + 1 == 255.0f);
    CHECK(test_color.r == 254.0f);
}

TEST_CASE("rgb_access +=", "=") {
    auto test_color = color_vec::make_rgb(255, 1.0f);
    REQUIRE_THROWS_AS((test_color.r += 2) == 257.0f, color_vec::rgb_bound_exception);
    REQUIRE((test_color.r += 0) == 255.0f);
    CHECK(test_color.r == 255.0f);
    REQUIRE((test_color.r += -2) == 253.0f);
    CHECK(test_color.r == 253.0f);
    REQUIRE((test_color.r += 1) == 254.0f);
    CHECK(test_color.r == 254.0f);
}

TEST_CASE("rgb_access ++()", "=") {
    auto test_color_1 = color_vec::make_rgb(255.0f, 1.0f);
    REQUIRE_THROWS_AS(++test_color_1.r == 256.0f, color_vec::rgb_bound_exception);

    auto test_color_2 = color_vec::make_rgb(254.0f, 1.0f);
    REQUIRE(++test_color_2.r == 255.0f);
    CHECK(test_color_2.r == 255.0f);

}

TEST_CASE("rgb_access ++(int)", "=") {
    auto test_color_1 = color_vec::make_rgb(255.0f, 1.0f);
    REQUIRE_THROWS_AS(test_color_1.r++ == 255.0f, color_vec::rgb_bound_exception);

    auto test_color_2 = color_vec::make_rgb(254.0f, 1.0f);
    REQUIRE(test_color_2.r++ == 254.0f);
    CHECK(test_color_2.r == 255.0f);
}

TEST_CASE("rgb_access -", "=") {
    auto test_color = color_vec::make_rgb(1.0f, 1.0f);
    CHECK(test_color.r == 1.0f);
    REQUIRE(test_color.r - 0 == 1.0f);
    CHECK(test_color.r == 1);
    REQUIRE(test_color.r - 1 == 0.0f);
    CHECK(test_color.r == 1);
}

TEST_CASE("rgb_access -=", "=") {
    auto test_color = color_vec::make_rgb(1.0f, 1.0f);
    REQUIRE_THROWS_AS((test_color.r -= 2) == -1.0f, color_vec::rgb_bound_exception);
    REQUIRE((test_color.r -= 0) == 1.0f);
    CHECK(test_color.r == 1.0f);
    REQUIRE((test_color.r -= -1) == 2.0f);
    CHECK(test_color.r == 2.0f);
    REQUIRE((test_color.r -= 1) == 1.0f);
    CHECK(test_color.r == 1.0f);
}

TEST_CASE("rgb_access --()", "=") {
    auto test_color_1 = color_vec::make_rgb(0.0f, 1.0f);
    REQUIRE_THROWS_AS(--test_color_1.r == 0.0f, color_vec::rgb_bound_exception);

    auto test_color_2 = color_vec::make_rgb(1.0f, 1.0f);
    REQUIRE(--test_color_2.r == 0.0f);
    CHECK(test_color_2.r == 0.0f);

}

TEST_CASE("rgb_access --(int)", "=") {
    auto test_color_1 = color_vec::make_rgb(0.0f, 1.0f);
    REQUIRE_THROWS_AS(test_color_1.r-- == 255.0f, color_vec::rgb_bound_exception);

    auto test_color_2 = color_vec::make_rgb(1.0f, 1.0f);
    REQUIRE(test_color_2.r-- == 1.0f);
    CHECK(test_color_2.r == 0.0f);
}

TEST_CASE("rgb_access *", "=") {
    auto test_color = color_vec::make_rgb(128, 1.0f);
    CHECK(test_color.r == 128);
    REQUIRE(test_color.r * 1 == 128.0f);
    CHECK(test_color.r == 128.0f);
    REQUIRE(test_color.r * 1.5 == 192.0f);
    CHECK(test_color.r == 128.0f);
}

TEST_CASE("rgb_access /", "=") {
    auto test_color = color_vec::make_rgb(128, 1.0f);
    CHECK(test_color.r == 128);
    REQUIRE(test_color.r / 1 == 128.0f);
    CHECK(test_color.r == 128.0f);
    REQUIRE(test_color.r / 2.0f == 64.0f);
    CHECK(test_color.r == 128.0f);
}

TEST_CASE("rgb_access *=", "=") {
    auto test_color = color_vec::make_rgb(128, 1.0f);
    REQUIRE_THROWS_AS((test_color.r *= 2) == 256.0f, color_vec::rgb_bound_exception);
    REQUIRE_THROWS_AS((test_color.r *= -1) == -128.0f, color_vec::rgb_bound_exception);
    CHECK(test_color.r == 128);
    REQUIRE((test_color.r *= 1) == 128.0f);
    CHECK(test_color.r == 128.0f);
    REQUIRE((test_color.r *= 1.5) == 192.0f);
    CHECK(test_color.r == 192.0f);
}

TEST_CASE("rgb_access /=", "=") {
    auto test_color = color_vec::make_rgb(128, 1.0f);
    REQUIRE_THROWS_AS(test_color.r /= 0.5 == 256.0f, color_vec::rgb_bound_exception);
    REQUIRE_THROWS_AS(test_color.r /= -1 == -128.0f, color_vec::rgb_bound_exception);
    CHECK(test_color.r == 128);
    REQUIRE((test_color.r /= 1) == 128.0f);
    CHECK(test_color.r == 128.0f);
    REQUIRE((test_color.r /= 2.0f) == 64.0f);
    CHECK(test_color.r == 64.0f);
}