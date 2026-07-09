#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

void read_file(float* input, int height, int width, const char filename[]);
void median_filtering(float* input, float* output, int height, int width, int window_size);
void heap_sort(float* a, int n);
void downheap(float* a, int n, int k);

void read_file(float* input, int height, int width, const char filename[])
{
    int x, y;
    FILE* fp;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File open failed!\n");
        exit(1);
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fscanf(fp, "%f", &input[y * width + x]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);
}

void median_filtering(float* input, float* output, int height, int width, int window_size)
{
    int x, y, xx, yy;
    int len = window_size / 2;
    int cnt;
    float med;

    float* temp = (float*)calloc(window_size * window_size, sizeof(float));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            cnt = 0;

            // data sampling
            for (yy = y - len; yy <= y + len; yy++) {
                for (xx = x - len; xx <= x + len; xx++) {
                    if (yy >= 0 && yy < height && xx >= 0 && xx < width) {
                        temp[cnt] = input[yy * width + xx];
                        cnt++;
                    }
                }
            }

            // sorting
            heap_sort(temp, cnt);

            // median
            med = temp[cnt / 2];

            output[y * width + x] = med;
        }
    }

    free(temp);
}

void downheap(float* a, int n, int k)
{
    int j;
    float v = a[k];

    while (k < n / 2) {
        j = 2 * k + 1;

        if (j < n - 1 && a[j] < a[j + 1]) {
            j++;
        }

        if (v >= a[j]) {
            break;
        }

        a[k] = a[j];
        k = j;
    }

    a[k] = v;
}

void heap_sort(float* a, int n)
{
    int i;
    float t;

    for (i = n / 2 - 1; i >= 0; i--) {
        downheap(a, n, i);
    }

    while (n > 1) {
        t = a[0];
        a[0] = a[n - 1];
        a[n - 1] = t;

        n--;
        downheap(a, n, 0);
    }
}

int main() {
    int height = 44, width = 45;
    int window_size = 3;

    float* input = (float*)malloc(sizeof(float) * height * width);
    float* output = (float*)malloc(sizeof(float) * height * width);

    if (input == NULL || output == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    char cwd[1024];
    _getcwd(cwd, sizeof(cwd));
    printf("Current working directory: %s\n", cwd);

    read_file(input, height, width, "noisy_data.txt");
    printf("Data loaded successfully.\n");

    median_filtering(input, output, height, width, window_size);
    printf("Filtering completed.\n");

    FILE* out_fp = fopen("filtered_result.txt", "w");

    if (out_fp == NULL) {
        printf("Output file open failed!\n");
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(out_fp, "%.0f\t", output[y * width + x]);
        }
        fprintf(out_fp, "\n");
    }

    fclose(out_fp);

    printf("Filtered result saved to filtered_result.txt\n");

    free(input);
    free(output);

    return 0;
}