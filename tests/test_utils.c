#include <stdio.h>
#include <assert.h>
#include "utils.h"

void test_formatData() {
    char output[50];
    int result = formatData(123.456, output, sizeof(output));
    assert(result == 0);
    assert(strcmp(output, "123.46") == 0);
}

void test_handleError() {
    int errorCode = -1;
    char errorMessage[100];
    handleError(errorCode, errorMessage, sizeof(errorMessage));
    assert(strcmp(errorMessage, "Error: Unknown error occurred") == 0);
}

int main() {
    test_formatData();
    test_handleError();
    printf("All tests passed!\n");
    return 0;
}