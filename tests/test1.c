#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <malloc.h>
#include "../libs/messages_to_console/messages_to_console.h"
#include "../libs/memory/memory.h"

int* ptr;

void TESTCASE_malloc_01(void** state) {
    assert_non_null(ptr = malloc_(4 * sizeof(int)));
    free_(ptr);
}

void TESTCASE_malloc_02(void** state) {
    assert_non_null(ptr = malloc_(8203387535));
    free_(ptr);
}

void TESTCASE_malloc_03(void** state) {
    assert_non_null(ptr = malloc_(33554440));
    free_(ptr);
}

void TESTCASE_malloc_04(void** state) {
    assert_non_null(ptr = malloc_(8 * sizeof(int)));
    free_(ptr);
}

void TESTCASE_malloc_05(void** state) {
    assert_non_null(ptr = malloc_(33554000));
    free_(ptr);
}

void TESTCASE_malloc_06(void** state) {
    assert_non_null(ptr = malloc_(1029 * sizeof(int)));
    free_(ptr);
}

void TESTCASE_malloc_07(void** state) {
    assert_non_null(ptr = malloc_(4 * sizeof(int[4])));
    free_(ptr);
}

int main() {
    PRINT_DBG("Тест 1:");
    const struct CMUnitTest malloc_tests[] = {
        cmocka_unit_test(TESTCASE_malloc_01),
        cmocka_unit_test(TESTCASE_malloc_02),
        cmocka_unit_test(TESTCASE_malloc_03),
        cmocka_unit_test(TESTCASE_malloc_04),
        cmocka_unit_test(TESTCASE_malloc_05),
        cmocka_unit_test(TESTCASE_malloc_06),
        cmocka_unit_test(TESTCASE_malloc_07)
    };

    PRINT_DBG("Запуск тестов");
    cmocka_run_group_tests_name("malloc tests", malloc_tests, NULL, NULL);
    puts("");
    
    return 0;
}