/*****************************************************************************************
 * 
 * Find peak and troughs in 60 items where,
 *      1) Each peak/troughs should have been atleast +/- 10 days
 * 
 *****************************************************************************************/

#include "iostream"


float prices[] = {341, 328.85, 353,
 355.6,
358.55,
350.55,
353.55,
370.65,
 364.3,
 360.8,
 357.2,
 355.2,
359.85,
 372.7,
   367,
371.15,
 367.1,
368.15,
378.55,
 383.9,
 381.1,
 387.7,
 387.6,
 389.6,
383.65,
395.65,
405.05,
 394.2,
394.95,
390.15,
407.25,
406.25,
 395.6,
 389.5,
399.55,
 415.2,
411.75,
402.35,
406.95,
393.15,
390.15,
392.25,
 394.8,
397.05,
 393.1,
 355.1,
335.95,
 333.1,
 310.7,
 282.1,
282.35,
275.65,
280.95,
 283.7,
294.85,
302.55,
 298.6,
294.45,
303.85,
307.25};

#define DISTANCE 10
#define CHECK_RANGE(X) (X > peak_1_low && X < peak_1_high) || ((X > peak_2_low && X < peak_2_high))
#define CHECK_RANGE_TROUGH(X) (X > trough_1_low && X < trough_1_high) || ((X > trough_2_low && X < trough_2_high))
#define ASSIGN_VALUE(X) (X == 1 ? peak_1: X == 2 ? peak_2: peak_3)
#define ASSIGN_VALUE_TROUGH(X) (X == 1 ? trough_1: X == 2 ? trough_2: trough_3)

using namespace std;

void find_peak_troughs (float* arr, int size)
{
    /* Below items will contain the indexes */
    int peak_1 = 0;
    int peak_2 = 0;
    int peak_3 = 0;
    int trough_1 = 0;
    int trough_2 = 0;
    int trough_3 = 0;

    for (int i = 1; i < 4; i++)
    {
        int index = -1;
        int peak_1_low = (peak_1 == 0 ? 0 : peak_1 - DISTANCE);
        int peak_1_high = (peak_1 == 0 ? 0 : peak_1 + DISTANCE);
        int peak_2_low = (peak_2 == 0 ? 0 : peak_2 - DISTANCE);
        int peak_2_high = (peak_2 == 0 ? 0 : peak_2 + DISTANCE);
        for (int j = 0; j < size; j++)
        {
            if (CHECK_RANGE (j)) {
                continue;
            }
            if (index == -1 || arr[index] < arr[j]) {
                index = j;
            }
        }
        ASSIGN_VALUE(i) = index;
    }

    for (int i = 1; i < 4; i++)
    {
        int index = -1;
        int trough_1_low = (trough_1 == 0 ? 0 : trough_1 - DISTANCE);
        int trough_1_high = (trough_1 == 0 ? 0 : trough_1 + DISTANCE);
        int trough_2_low = (trough_2 == 0 ? 0 : trough_2 - DISTANCE);
        int trough_2_high = (trough_2 == 0 ? 0 : trough_2 + DISTANCE);
        for (int j = 0; j < size; j++)
        {
            if (CHECK_RANGE_TROUGH (j)) {
                cout << j << " ";
                continue;
            }
            if (index == -1 || arr[index] > arr[j]) {
                index = j;
            }
        }
        ASSIGN_VALUE_TROUGH(i) = index;
        cout << endl;
    }
    cout << peak_1 << "   " << peak_2 << "   " << peak_3 << endl;
    cout << arr[peak_1] << "   " << arr[peak_2] << "   " << arr[peak_3] << endl;

    cout << trough_1 << "   " << trough_2 << "   " << trough_3 << endl;
    cout << arr[trough_1] << "   " << arr[trough_2] << "   " << arr[trough_3] << endl;
}

int main ()
{
    find_peak_troughs (prices, sizeof(prices)/sizeof(prices[0]));
}