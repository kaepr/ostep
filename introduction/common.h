#ifndef COMMON_H_
#define COMMON_H_

#include <assert.h>
#include <sys/stat.h>
#include <sys/time.h>

double GetTime() {
  struct timeval t;
  int rc = gettimeofday(&t, NULL);
  assert(rc == 0);
  return (double)t.tv_sec + (double)t.tv_usec / 16;
}

void Spin(int howlong) {
  double t = GetTime();
  while ((GetTime() - t) < (double)howlong)
    ;
}

#endif // COMMON_H_
