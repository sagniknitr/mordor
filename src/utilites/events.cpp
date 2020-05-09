#include "events.hpp"

mordor_status mordor_event::mordorEventCreate() {
  pthread_mutexattr_t mutex_attr;
  pthread_condattr_t cond_attr;
  mordor_event tmp_event;
  mordor_status status = MORDOR_SUCCESS;

  tmp_event = (mordor_event)malloc(sizeof(mordor_event_t));
  if (tmp_event == NULL) {
    *event = NULL;
    status = MORDOR_ERROR_NO_MEMORY;
  } else {
    status |= pthread_mutexattr_init(&mutex_attr);
    status |= pthread_condattr_init(&cond_attr);

    status |= pthread_mutex_init(&tmp_event->lock, &mutex_attr);
    status |= pthread_cond_init(&tmp_event->cond, &cond_attr);

    tmp_event->is_set = 0;

    if (status != 0) {
      free(tmp_event);
      *event = NULL;
      status = MORDOR_ERROR_NO_MEMORY;
    } else {
      *event = tmp_event;
    }

    pthread_condattr_destroy(&cond_attr);
    pthread_mutexattr_destroy(&mutex_attr);
  }

  return (status);
}

mordor_status mordor_event::mordorEventDelete() {
  mordor_status status = MORDOR_FAILURE;

  if (*event) {
    pthread_cond_destroy(&(*event)->cond);
    pthread_mutex_destroy(&(*event)->lock);
    free(*event);
    *event = NULL;
    status = MORDOR_SUCCESS;
  }

  return (status);
}

mordor_status mordor_event::mordorEventPost() {
  mordor_status status = MORDOR_ERROR_INVALID_PARAMETERS;

  if (event) {
    status = pthread_mutex_lock(&event->lock);
    if (status == 0) {
      event->is_set = 1;

      status |= pthread_cond_signal(&event->cond);
      status |= pthread_mutex_unlock(&event->lock);
    }
    if (status != 0) {
      status = MORDOR_FAILURE;
    }
  }

  return (status);
}

mordor_status mordor_event::mordorEventWait( uint32_t timeout) {
  mordor_status status = MORDOR_ERROR_INVALID_PARAMETERS;

  if (event) {
    status = pthread_mutex_lock(&event->lock);
    if (status == 0) {
      vx_bool done = vx_false_e;

      while (!done) {
        if (event->is_set == 1) {
          /* clear event */
          event->is_set = 0;
          status = MORDOR_SUCCESS;
          done = vx_true_e;
        } else if (timeout == MORDOR_EVENT_TIMEOUT_NO_WAIT) {
          status = MORDOR_FAILURE;
          done = vx_true_e;
        } else {
          pthread_cond_wait(&event->cond, &event->lock);
        }
      }
      status |= pthread_mutex_unlock(&event->lock);
    }
    if (status != 0) {
      status = MORDOR_FAILURE;
    }
  }

  return (status);
}

mordor_status mordor_event::mordorEventClear() {
  mordor_status status = MORDOR_ERROR_INVALID_PARAMETERS;

  if (event) {
    status = pthread_mutex_lock(&event->lock);
    if (status == 0) {
      event->is_set = 0;
      status = pthread_mutex_unlock(&event->lock);
    }
    if (status != 0) {
      status = MORDOR_FAILURE;
    }
  }

  return status;
}
