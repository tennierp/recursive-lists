#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

void testSubset() {
    std::cout << "Testing Subset" << std::endl;

    std::cout << "Enter a list for p: ";
    list p = read_list();
    std::cout << "Enter a list for q: ";
    list q = read_list();

    if (subset(p, q)) {
        std::cout << "True." << std::endl;
    } else {
        std::cout << "False." << std::endl;
    }
}

void testRemove() {
    std::cout << "Testing Remove" << std::endl;

    std::cout << "Enter a list of only atoms for list a: ";
    list p = read_list();
    std::cout << "Enter an atom for q: ";
    list q = read_list();

    write_list(remove(p, q));
}

void testTwoSame() {
    std::cout << "Testing TwoSame" << std::endl;

    std::cout << "Enter a list for list p: ";
    list p = read_list();
    std::cout << "Enter a list for list q: ";
    list q = read_list();

    if (two_the_same(p, q)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}

void testPair() {
    std::cout << "Testing Pair" << std::endl;

    std::cout << "Enter a list of only atoms for list a: ";
    list p = read_list();
    std::cout << "Enter a list of only atoms for list q: ";
    list q = read_list();

    write_list(list_pair(p, q));
}

void testFlat() {
    std::cout << "Testing Flat" << std::endl;

    std::cout << "Enter a list of only atoms for list p: ";
    list p = read_list();

    write_list(flat(p));
}

void testFirsts() {
    std::cout << "Testing Firsts" << std::endl;

    std::cout << "Enter a list a: ";
    list p = read_list();

    write_list(firsts(p));
}

void testLat() {
    std::cout << "Testing Lat" << std::endl;
    std::cout << "Enter a list of only atoms: ";
    list p = read_list();

    if (is_lat(p)) {
        std::cout << "True." << std::endl;
    } else {
        std::cout << "False." << std::endl;
    }
}

void testMember() {
    std::cout << "Testing Member" << std::endl;

    std::cout << "Enter an atom to find: ";
    list p = read_list();

    std::cout << "Enter a list: ";
    list q = read_list();

    if (member(p, q)) {
        std::cout << "Atom found" << std::endl;
    } else {
        std::cout << "Atom not found in q." << std::endl;
    }
}

void testLast() {
    std::cout << "Testing Last" << std::endl;

    std::cout << "Testing last(list p) - ";
    std::cout << "Enter a list: ";
    list p = read_list();

    std::cout << "The last element in the list: ";
    write_list(last(p));
}

void testEqual() {
    std::cout << "Testing Equal" << std::endl;

    std::cout << "Enter a list p: ";
    list p = read_list();

    std::cout << "Enter a list q: ";
    list q = read_list();

    if (equal(p, q)) {
        std::cout << "True." << std::endl;
    } else {
        std::cout << "False." << std::endl;
    }
}

void testTotal_Reverse() {
    std::cout << "Testing Total Reverse" << std::endl;

    std::cout << "Enter a list p: ";
    list p = read_list();

    std::cout << "Outcome: ";
    write_list(total_reverse(p));
}

void testShape() {
    std::cout << "Testing Shape" << std::endl;

    std::cout << "Enter a list p: ";
    list p = read_list();

    std::cout << "Outcome: ";
    write_list(shape(p));
}

void testIntersection() {
    std::cout << "Testing Intersection" << std::endl;

    std::cout << "Enter a list p: ";
    list p = read_list();

    std::cout << "Enter a list q: ";
    list q = read_list();

    std::cout << "Outcome: ";
    write_list(intersection(p, q));
}

void testUnion() {
    std::cout << "Testing Union" << std::endl;

    std::cout << "Enter a list p: ";
    list p = read_list();

    std::cout << "Enter a list q: ";
    list q = read_list();

    std::cout << "Outcome: ";
    write_list(list_union(p, q));
}

void testSub() {
    std::cout << "Testing Substitute" << std::endl;

    std::cout << "Enter an old atom: ";
    list p = read_list();

    std::cout << "Enter a replacement atom: ";
    list q = read_list();

    std::cout << "Enter a list of atoms: ";
    list z = read_list();

    std::cout << "Outcome: ";
    write_list(substitute(p, q, z));
}

int main()
{
    testTwoSame();
    testLat();
    testMember();
    testLast();
    testPair();
    testFirsts();
    testFlat();
    testEqual();
    testTotal_Reverse();
    testShape();
    testIntersection();
    testUnion();
    testSub();
    testRemove();
    testSubset();
    return 0;
}