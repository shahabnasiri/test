#include <iostream>
using namespace std;

// تابع برای تقسیم کردن آرایه
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // انتخاب Pivot (عنصر آخر آرایه)
    int i = (low - 1);  // نشانگر برای مکان صحیح Pivot

    for (int j = low; j <= high - 1; j++) {
        // اگر عنصر کنونی کمتر از یا مساوی Pivot باشد
        if (arr[j] <= pivot) {
            i++;    // افزایش نشانگر i
            swap(arr[i], arr[j]);  // جابجایی عناصر
        }
    }
    swap(arr[i + 1], arr[high]);  // جابجایی Pivot به موقعیت صحیح
    return (i + 1);  // بازگرداندن ایندکس Pivot
}

// تابع برای پیاده‌سازی الگوریتم Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // پیدا کردن نقطه تقسیم (Pivot)
        int pi = partition(arr, low, high);

        // بازگشت باز هم به قسمت‌های چپ و راست
        quickSort(arr, low, pi - 1);  // چپ
        quickSort(arr, pi + 1, high); // راست
    }
}

// تابع اصلی برای تست الگوریتم
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "آرایه قبل از مرتب سازی: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);  // فراخوانی تابع Quick Sort

    cout << "آرایه بعد از مرتب سازی: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
