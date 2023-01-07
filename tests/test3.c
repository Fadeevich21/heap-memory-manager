#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../libs/messages_to_console/messages_to_console.h"

int sum(int a, int b) {
    return a + b;
}

void TESTCASE_sum(void** state) {
    assert_int_equal(sum(1, 2), 3);
    assert_int_equal(sum(4, 5), 9);
    assert_int_equal(sum(4, 6), 10);
}

int main() {
    PRINT_DBG("Тест 3:");
    const struct CMUnitTest sum_tests[] = {
        cmocka_unit_test(TESTCASE_sum)
    };
    cmocka_run_group_tests_name("sum_tests", sum_tests, NULL, NULL);
    puts("");

    return 0;
}