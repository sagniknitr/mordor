#ifndef __EVENTS_H__
#define __EVENTS_H__


#include "./datatypes.hpp"
#include <pthread.h>



class  mordor_event {
 
 public::
    mordor_status mordorEventCreate();
    mordor_status mordorEventPost();
    mordor_status mordorEventWait();
    mordor_status morodrEventClear();

 private:
  uint16_t is_set;
  pthread_mutex_t lock;
  pthread_cond_t cond;

}


extern 
#endif