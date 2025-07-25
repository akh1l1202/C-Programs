#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void decToBinary(int n, char *binaryNum, int bits) {
    int i = 0;
    int abs_n = abs(n);

    for (i = bits - 1; i >= 0; i--) {
        binaryNum[i] = (abs_n % 2 == 0) ? '0' : '1';
        abs_n /= 2;
    }
    binaryNum[bits] = '\0';

    if (n < 0) {
        for (i = 0; i < bits; i++) {
            binaryNum[i] = (binaryNum[i] == '0') ? '1' : '0';
        }

        int carry = 1;

        for (i = bits - 1; i >= 0; i--) {
            if (binaryNum[i] == '1' && carry == 1) {
                binaryNum[i] = '0';
            } else if (binaryNum[i] == '0' && carry == 1) {
                binaryNum[i] = '1';
                carry = 0;
            } else {
                break;
            }
        }
    }
}

char* addBinary(const char *a, const char *b) {
    int len = strlen(a);
    char *sum = (char *)malloc((len + 1) * sizeof(char));
    sum[len] = '\0';

    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int bit_a = a[i] - '0';
        int bit_b = b[i] - '0';

        int r = bit_a + bit_b + carry;
        sum[i] = (r % 2) + '0';
        carry = r / 2;
    }
    return sum;
}


void arithmeticRightShift(char *binary_str, int bits) {
    if (bits <= 0) return;

    char sign_bit = binary_str[0];
    for (int i = bits - 1; i > 0; i--) {
        binary_str[i] = binary_str[i - 1];
    }
    binary_str[0] = sign_bit;
}


long long binaryToDec(const char *binaryNum, int bits) {
    long long decimal = 0;
    if (binaryNum[0] == '1') {
        char *temp_binary = strdup(binaryNum);

        for (int i = 0; i < bits; i++) {
            temp_binary[i] = (temp_binary[i] == '0') ? '1' : '0';
        }
        int carry = 1;
        for (int i = bits - 1; i >= 0; i--) {
            if (temp_binary[i] == '1' && carry == 1) {
                temp_binary[i] = '0';
            } else if (temp_binary[i] == '0' && carry == 1) {
                temp_binary[i] = '1';
                carry = 0;
            } else {
                break;
            }
        }

        for (int i = 1; i < bits; i++) {
            if (temp_binary[i] == '1') {
                decimal += pow(2, bits - 1 - i);
            }
        }
        free(temp_binary);
        return -decimal;
    } else {
        for (int i = 0; i < bits; i++) {
            if (binaryNum[i] == '1') {
                decimal += pow(2, bits - 1 - i);
            }
        }
        return decimal;
    }
}


void booth_algorithm(int multiplicand_val, int multiplier_val, int num_bits) {
    char M[num_bits + 1];
    char neg_M[num_bits + 1];
    char Q[num_bits + 1];
    char A[num_bits + 1];

    char Q_minus_1 = '0';

    decToBinary(multiplicand_val, M, num_bits);
    decToBinary(-multiplicand_val, neg_M, num_bits);
    decToBinary(multiplier_val, Q, num_bits);

    for (int i = 0; i < num_bits; i++) {
        A[i] = '0';
    }
    A[num_bits] = '\0';

    printf("\n--- Booth's Algorithm (M=%d, Q=%d, bits=%d) ---\n", multiplicand_val, multiplier_val, num_bits);
    printf("M  : %s (%d)\n", M, multiplicand_val);
    printf("-M : %s (%d)\n", neg_M, -multiplicand_val);
    printf("Q  : %s (%d)\n", Q, multiplier_val);
    printf("Initial: A=%s, Q=%s, Q_1=%c\n", A, Q, Q_minus_1);

    for (int i = 0; i < num_bits; i++) {
        printf("\nIteration %d:\n", i + 1);
        char last_Q_bit = Q[num_bits - 1];
        char pair_str[3];
        pair_str[0] = last_Q_bit;
        pair_str[1] = Q_minus_1;
        pair_str[2] = '\0';

        printf("  Current A=%s, Q=%s, Q_1=%c. Pair (Q0Q-1): %s\n", A, Q, Q_minus_1, pair_str);

        char *temp_sum = NULL;
        if (strcmp(pair_str, "01") == 0) {
            // Case 01: A = A + M
            printf("  Case '01': A = A + M (%s + %s)\n", A, M);
            temp_sum = addBinary(A, M);
            strncpy(A, temp_sum, num_bits);
            A[num_bits] = '\0';
            free(temp_sum);
            printf("  A after addition: %s\n", A);
        } else if (strcmp(pair_str, "10") == 0) {
            // Case 10: A = A - M (A = A + (-M))
            printf("  Case '10': A = A - M (%s + %s)\n", A, neg_M);
            temp_sum = addBinary(A, neg_M);
            strncpy(A, temp_sum, num_bits);
            A[num_bits] = '\0';
            free(temp_sum);
            printf("  A after subtraction: %s\n", A);
        } else {
            // Case 00 or 11: No operation on A
            printf("  Case '%s': No operation on A.\n", pair_str);
        }
        Q_minus_1 = last_Q_bit;

        char last_A_bit = A[num_bits - 1];
        arithmeticRightShift(Q, num_bits);
        Q[0] = last_A_bit;

        arithmeticRightShift(A, num_bits);

        printf("  After shift: A=%s, Q=%s, Q_1=%c\n", A, Q, Q_minus_1);
    }

    char result_binary[2 * num_bits + 1];
    strcpy(result_binary, A);
    strcat(result_binary, Q);

    long long result_decimal = binaryToDec(result_binary, 2 * num_bits);

    printf("\n--- Final Result ---\n");
    printf("Binary result: %s\n", result_binary);
    printf("Decimal result: %lld\n", result_decimal);
}

int main() {
    int multiplicand;
    int multiplier;
    int bits;

    printf("Enter multiplicand: ");
    scanf("%d",&multiplicand);
    printf("Enter multiplier: ");
    scanf("%d",&multiplier);
    printf("Enter number of bits: ");
    scanf("%d",&bits);

    booth_algorithm(multiplicand, multiplier, bits);

    return 0;
}
