/**
 * Student Name: Haisheng Shi
 * Semester: Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library
#include <math.h>
#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

int test_swap_two() {
    printf("2. test_swap_two()\n");
    int a = 8;
    int b = -2;
    swap(&a, &b);
    if (a == -2 && b == 8) {
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib() {
    printf("3. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

int test_create_array_of_ints_fib2() {
    printf("4. test_create_array_of_ints_fib2()\n");
    int* arr = create_array_of_ints_fib(7);
    int expected[] = {1, 1, 2, 3, 5 ,8 ,13};
    for (int i = 0; i < 7; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

int test_reverse_array() {
    printf("5. test_reverse_array()\n");
    int *arr = create_array_of_ints_fib(5);
    reverse_array(arr, 5);
    int expected[] = {5, 3, 2, 1, 1};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

int test_reverse_array2() {
    printf("6. test_reverse_array2()\n");
    int *arr = create_array_of_ints_fib(7);
    reverse_array(arr, 7);
    int expected[] = {13, 8, 5, 3, 2, 1, 1};
    for (int i = 0; i < 7; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}

int test_double_array_size() {
    printf("7. test_test_double_array_size()\n");
    int arr[5] = {1, 3, 5, 7, 9};
    int *p = arr;
    int expected[] = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0};
    int *testarr = double_array_size(p, 5);
    for (int i = 0; i < 10; i++) {
        if (testarr[i] != expected[i]) {
            free(testarr);
            return 0;
        }
    }
    free(testarr);
    return 1;

}

int test_double_array_size2() {
    printf("8. test_test_double_array_size2()\n");
    int arr[6] = {1, 3, 5, 7, 9, 11};
    int *p = arr;
    int expected[] = {1, 3, 5, 7, 9, 11, 0, 0, 0, 0, 0, 0};
    int *testarr = double_array_size(p, 6);
    for (int i = 0; i < 12; i++) {
        if (testarr[i] != expected[i]) {
            free(testarr);
            return 0;
        }
    }
    free(testarr);
    return 1;

}

int test_copy_array_start_end_loop() {
    printf("9. test_copy_array_start_end_loop()\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    int b = 0;
    int *a = &b;
    int expected[] = {2, 3, 4};
    int expected_size = 3;
    int *arrtest = copy_array_start_end_loop(p, 5, 1, 3 ,&b);
    if (b != expected_size) {
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (arrtest[i] != expected[i]) {
            free(arrtest);
            return 0;
        }
    }
    free(arrtest);
    return 1;


}



int test_copy_array_start_end_loop2() {
    printf("10. test_copy_array_start_end_loop2()\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    int b = 0;
    int expected_size = 4;
    int *a = &b;
    int expected[] = {4, 5, 1, 2};
    int *arrtest = copy_array_start_end_loop(p, 5, 3, 1 ,&b);
    if (b != expected_size) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (arrtest[i] != expected[i]) {
            free(arrtest);
            return 0;
        }
    }
    free(arrtest);
    return 1;
}

int test_create_point1() {
    printf("11. test_create_point1()\n");
    Point* p = create_point(100, 0);
    if ((*p).x != 100 || (*p).y != 0) {
        free(p);
        return 0;
    }
    free(p);
    return 1;
}

int test_create_point2() {
    printf("12. test_create_point2()\n");
    Point* p = create_point(-10, 28);
    if ((*p).x != -10 || (*p).y != 28) {
        free(p);
        return 0;
    }
    free(p);
    return 1;
}

int test_create_polygon1() {
    printf("13. test_create_polygon1()\n");
    Polygon* test = create_polygon(5);
    if (test == NULL || (*test).points == NULL || (*test).size != 5) {
        free(test);
        return 0;
    }
    free(test);
    return 1;
}

int test_create_polygon2() {
    printf("14. test_create_polygon2()\n");
    Polygon* test = create_polygon(6);
    if (test == NULL || (*test).points == NULL || (*test).size != 6) {
        free(test);
        return 0;
    }
    free(test);
    return 1;
}

int test_free_polygon1() {
    printf("15. test_free_polygon1()\n");
    free_polygon(NULL);
    return 1;
}

int test_free_polygon2() {
    Polygon *rect = create_rectangle(10, 5);
    printf("16. test_free_polygon2()\n");
    free_polygon(rect);
    return 1;
}

int test_create_rectangle1() {
    printf("17. test_create_rectangle1()\n");
    Polygon* rect = create_rectangle(6, 2);
    if (rect->size != 4) { free_polygon(rect); return 0; }
    if (rect->points[0]->x != 0 || rect->points[0]->y != 0) {
        free_polygon(rect);
        return 0;
    }
    if (rect->points[1]->x != 6 || rect->points[1]->y != 0) {
        free_polygon(rect);
        return 0;
    }
    if (rect->points[2]->x != 6 || rect->points[2]->y != 2) {
        free_polygon(rect);
        return 0;
    }
    if (rect->points[3]->x != 0 || rect->points[3]->y != 2) {
        free_polygon(rect);
        return 0;
    }
    free_polygon(rect);
    return 1;
}

int test_create_rectangle2() {
    printf("18. test_create_rectangle2()\n");
    Polygon* rect = create_rectangle(22, 11);
    if (rect->size != 4) {
        free_polygon(rect);
        return 0;
    }
    if (rect->points[0]->x != 0 || rect->points[0]->y != 0) {
        free_polygon(rect);
        return 0;
    }
    if (rect->points[1]->x != 22 || rect->points[1]->y != 0) {
        free_polygon(rect);
        return 0;
    }
    if (rect->points[2]->x != 22 || rect->points[2]->y != 11) {
        free_polygon(rect);
        return 0;
    }
    if (rect->points[3]->x != 0 || rect->points[3]->y != 11) {
        free_polygon(rect);
        return 0;
    }
    free_polygon(rect);
    return 1;
}

int test_create_triangle1() {
    printf("19. test_create_triangle1()\n");
    Polygon* tri = create_triangle(3, 4);
    if (tri->size != 3) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[0]->x != 0 || tri->points[0]->y != 0) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[1]->x != 3 || tri->points[1]->y != 0) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[2]->x != 3 || tri->points[2]->y != 4) {
        free_polygon(tri);
        return 0;
    }
    free_polygon(tri);
    return 1;
}

int test_create_triangle2() {
    printf("20. test_create_triangle2()\n");
    Polygon* tri = create_triangle(100, 200);
    if (tri->size != 3) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[0]->x != 0 || tri->points[0]->y != 0) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[1]->x != 100 || tri->points[1]->y != 0) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[2]->x != 100 || tri->points[2]->y != 200) {
        free_polygon(tri);
        return 0;
    }
    free_polygon(tri);
    return 1;
}

int test_calculate_polygon_area1() {
    printf("21. test_calculate_polygon_area1()\n");
    Polygon* rect = create_rectangle(10, 20);
    double area = calculate_polygon_area(rect);
    free_polygon(rect);
    // Use fabs for float comparison to handle small precision errors
    if (fabs(area - 200.0) > 0.001) {
        return 0;
    }
    return 1;
}

int test_calculate_polygon_area2() {
    printf("22. test_calculate_polygon_area2()\n");
    Polygon* tri = create_triangle(3, 4);
    double area = calculate_polygon_area(tri);
    free_polygon(tri);
    if (fabs(area - 6.0) > 0.001) {
        return 0;
    }
    return 1;
}








// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_swap_two,
        test_create_array_of_ints_fib,
        test_create_array_of_ints_fib2,
        test_reverse_array,
        test_reverse_array2,
        test_double_array_size,
        test_double_array_size2,
        test_copy_array_start_end_loop,
        test_copy_array_start_end_loop2,
        test_create_point1,
        test_create_point2,
        test_create_polygon1,
        test_create_polygon2,
        test_free_polygon1,
        test_free_polygon2,
        test_create_rectangle1,
        test_create_rectangle2,
        test_create_triangle1,
        test_create_triangle2,
        test_calculate_polygon_area1,
        test_calculate_polygon_area2,






        // add more test function names here
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
