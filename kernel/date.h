#ifndef XV6_KERNEL_DATE_H
#define XV6_KERNEL_DATE_H

struct rtcdate {
  uint second;
  uint minute;
  uint hour;
  uint day;
  uint month;
  uint year;
};

#endif
