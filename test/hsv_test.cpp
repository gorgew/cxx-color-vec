#include <catch2/catch.hpp>
#include <color-vec.hpp>

TEST_CASE("hsv make_hsv", "=") {

    auto test_color = color_vec::make_hsv(120, 50, 50, 1.0f);
    CHECK(test_color.x == .25);
    CHECK(test_color.y == .5);
    CHECK(test_color.z == .25);
    CHECK(test_color.w == 1.0f);
    CHECK(test_color.h == 120.0f);
    CHECK(test_color.s == 50.0f);
    CHECK(test_color.v == 50.0f);
    CHECK(test_color.a == 1.0f);
}

TEST_CASE("hsv + operator", "=") {
    auto test_color = color_vec::make_hsv(120, 50, 50, 1.0f);
    CHECK(test_color.h + 1 == 121);
    CHECK(test_color.h + 0 == 120);
    CHECK(test_color.h + -1 == 119);
    CHECK(test_color.h == 120);

    CHECK(test_color.s + 1 == 51);
    CHECK(test_color.s + 0 == 50);
    CHECK(test_color.s + -1 == 49);
    CHECK(test_color.s == 50);

    CHECK(test_color.v + 1 == 51);
    CHECK(test_color.v + 0 == 50);
    CHECK(test_color.v + -1 == 49);
    CHECK(test_color.v == 50);
}

TEST_CASE("hsv - operator", "=") {
    auto test_color = color_vec::make_hsv(120, 50, 50, 1.0f);
    CHECK(test_color.h - 1 == 119);
    CHECK(test_color.h - 0 == 120);
    CHECK(test_color.h - -1 == 121);
    CHECK(test_color.h == 120);

    CHECK(test_color.s - 1 == 49);
    CHECK(test_color.s - 0 == 50);
    CHECK(test_color.s - -1 == 51);
    CHECK(test_color.s == 50);

    CHECK(test_color.v - 1 == 49);
    CHECK(test_color.v - 0 == 50);
    CHECK(test_color.v - -1 == 51);
    CHECK(test_color.v == 50);
}

TEST_CASE("hsv += operator", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_h.h += 60) == 180.0f);
    CHECK(test_color_h.h == 180.0f);
    REQUIRE((test_color_h.h += 0) == 180.0f);
    CHECK(test_color_h.h == 180);
    REQUIRE((test_color_h.h += -60) == 120.0f);
    CHECK(test_color_h.h == 120);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_s.s += 10) == Approx(60.0f));
    CHECK(Approx(test_color_s.s) == 60.0f);
    REQUIRE((test_color_s.s += 0) == Approx(60.0f));
    CHECK(Approx(test_color_s.s) == 60.0f);
    REQUIRE((test_color_s.s += -10) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);

    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_v.v += 10) == Approx(60.0f));
    CHECK(Approx(test_color_v.v) == 60.0f);
    REQUIRE((test_color_v.v += 0) == Approx(60.0f));
    CHECK(Approx(test_color_v.v) == 60.0f);
    REQUIRE((test_color_v.v += -10) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);
}

TEST_CASE("hsv -= operator", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_h.h -= -60) == 180.0f);
    CHECK(test_color_h.h == 180.0f);
    REQUIRE((test_color_h.h -= 0) == 180.0f);
    CHECK(test_color_h.h == 180);
    REQUIRE((test_color_h.h -= 60) == 120.0f);
    CHECK(test_color_h.h == 120);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_s.s -= -10) == Approx(60.0f));
    CHECK(Approx(test_color_s.s) == 60.0f);
    REQUIRE((test_color_s.s -= 0) == Approx(60.0f));
    CHECK(Approx(test_color_s.s) == 60.0f);
    REQUIRE((test_color_s.s -= 10) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);

    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_v.v -= -10) == Approx(60.0f));
    CHECK(Approx(test_color_v.v) == 60.0f);
    REQUIRE((test_color_v.v -= 0) == Approx(60.0f));
    CHECK(Approx(test_color_v.v) == 60.0f);
    REQUIRE((test_color_v.v -= 10) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);
}

TEST_CASE("hsv *= operator", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_h.h *= 2) == 240.0f);
    CHECK(test_color_h.h == 240.0f);
    REQUIRE((test_color_h.h *= 1) == 240.0f);
    CHECK(test_color_h.h == 240.0f);
    REQUIRE((test_color_h.h *= .5) == 120.0f);
    CHECK(test_color_h.h == 120);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_s.s *= 2) == Approx(100.0f));
    CHECK(Approx(test_color_s.s) == 100.0f);
    REQUIRE((test_color_s.s *= 1) == Approx(100.0f));
    CHECK(Approx(test_color_s.s) == 100.0f);
    REQUIRE((test_color_s.s *= 0.5f) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);

    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_v.v *= 2) == Approx(100.0f));
    CHECK(Approx(test_color_v.v) == 100.0f);
    REQUIRE((test_color_v.v *= 1) == Approx(100.0f));
    CHECK(Approx(test_color_v.v) == 100.0f);
    REQUIRE((test_color_v.v *= 0.5f) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);
}

TEST_CASE("hsv /= operator", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_h.h /= 2) == 60.0f);
    CHECK(test_color_h.h == 60.0f);
    REQUIRE((test_color_h.h /= 1) == 60.0f);
    CHECK(test_color_h.h == 60.0f);
    REQUIRE((test_color_h.h /= .5) == 120.0f);
    CHECK(test_color_h.h == 120);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_s.s /= 2) == Approx(25.0f));
    CHECK(Approx(test_color_s.s) == 25.0f);
    REQUIRE((test_color_s.s /= 1) == Approx(25.0f));
    CHECK(Approx(test_color_s.s) == 25.0f);
    REQUIRE((test_color_s.s /= 0.5f) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);

    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_v.v /= 2) == Approx(25.0f));
    CHECK(Approx(test_color_v.v) == 25.0f);
    REQUIRE((test_color_v.v /= 1) == Approx(25.0f));
    CHECK(Approx(test_color_v.v) == 25.0f);
    REQUIRE((test_color_v.v /= 0.5f) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 50.0f);
}

TEST_CASE("hsv operator++(int)", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_h.h++) == 120.0f);
    CHECK(test_color_h.h == 121.0f);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_s.s++) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 51.0f);


    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_v.v++) == Approx(50.0f));
    CHECK(Approx(test_color_v.v) == 51.0f);
}

TEST_CASE("hsv operator++", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((++test_color_h.h) == 121.0f);
    CHECK(test_color_h.h == 121.0f);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((++test_color_s.s) == Approx(51.0f));
    CHECK(Approx(test_color_s.s) == 51.0f);


    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((++test_color_v.v) == Approx(51.0f));
    CHECK(Approx(test_color_v.v) == 51.0f);
}

TEST_CASE("hsv operator--(int)", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_h.h--) == 120.0f);
    CHECK(test_color_h.h == 119.0f);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_s.s--) == Approx(50.0f));
    CHECK(Approx(test_color_s.s) == 49.0f);


    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((test_color_v.v--) == Approx(50.0f));
    CHECK(Approx(test_color_v.v) == 49.0f);
}

TEST_CASE("hsv operator--", "=") {
    auto test_color_h = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((--test_color_h.h) == 119.0f);
    CHECK(test_color_h.h == 119.0f);

    auto test_color_s = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((--test_color_s.s) == Approx(49.0f));
    CHECK(Approx(test_color_s.s) == 49.0f);


    auto test_color_v = color_vec::make_hsv(120, 50, 50, 1.0f);
    REQUIRE((--test_color_v.v) == Approx(49.0f));
    CHECK(Approx(test_color_v.v) == 49.0f);
}