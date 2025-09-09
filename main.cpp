#include "Time_.h"
#include <iomanip>

int main()
{
    Time_ exmp1;
    Time_ exmp2(15, 34, 3, true);
    Time_ exmp3(15, 34, 3, false);

    exmp1.showTime();
    exmp2.showTime();
    exmp3.showTime();
    cout << "======================================================\n\n";

    exmp2.setHour(19);
    exmp2.setMinutes(12);
    exmp2.setSeconds(1);
    exmp2.setFormat(false);
    exmp2.showTime();
    cout << exmp3.valid();
    cout << "\n======================================================\n\n";

    Time_ exmp4(23, 59, 59, true);
    exmp4.tickTime();
//    exmp4.showTime();

    Time_ exmp5(23, 59, 59, false);
    Time_ exmp6(0, 0, 0, true);
    Time_ exmp7(1, 0, 0, false);
    exmp5.tickTime();
    exmp6.untickTime();
    exmp7.untickTime();
//    exmp5.showTime();
//    exmp6.showTime();
    exmp7.showTime();

    cout << "\n======================================================\n\n";

}