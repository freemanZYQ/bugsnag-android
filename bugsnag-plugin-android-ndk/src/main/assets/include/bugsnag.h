/** Public API for interacting with Bugsnag */
#ifndef BUGSNAG_ANDROID_NDK_BUGSNAG_API_H
#define BUGSNAG_ANDROID_NDK_BUGSNAG_API_H

#include <jni.h>
#include "event.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef bool (*bsg_on_error)(void *);

/**
 * Configure the Bugsnag interface, optionally including the JNI environment.
 * @param env  The JNI environment to use when using convenience methods
 */
void bugsnag_init(JNIEnv *env);
/**
 * Sends an error report to Bugsnag
 * @param name     The name of the error
 * @param message  The error message
 * @param severity The severity of the error
 */
void bugsnag_notify(char* name, char* message, bsg_severity_t severity);
void bugsnag_notify_env(JNIEnv *env, char* name, char* message, bsg_severity_t severity);
/**
 * Set the current user
 * @param id    The identifier of the user
 * @param email The user's email
 * @param name  The user's name
 */
void bugsnag_set_user(char* id, char* email, char* name);
void bugsnag_set_user_env(JNIEnv *env, char* id, char* email, char* name);
/**
 * Leave a breadcrumb, indicating an event of significance which will be logged in subsequent
 * error reports
 */
void bugsnag_leave_breadcrumb(char *message, bsg_breadcrumb_t type);
void bugsnag_leave_breadcrumb_env(JNIEnv *env, char *message, bsg_breadcrumb_t type);

void bugsnag_add_on_error(bsg_on_error on_error);
void bugsnag_add_on_error_env(JNIEnv *env, bsg_on_error on_error);
void bugsnag_remove_on_error(bsg_on_error on_error);
void bugsnag_remove_on_error_env(JNIEnv *env, bsg_on_error on_error);

char *bugsnag_event_get_context(void *event_ptr);
void bugsnag_event_set_context(void *event_ptr, char *value);


/* Accessors for event.app */


char *bugsnag_app_get_binary_arch(void *event_ptr);
void bugsnag_app_set_binary_arch(void *event_ptr, char *value);

char *bugsnag_app_get_build_uuid(void *event_ptr);
void bugsnag_app_set_build_uuid(void *event_ptr, char *value);

char *bugsnag_app_get_id(void *event_ptr);
void bugsnag_app_set_id(void *event_ptr, char *value);

char *bugsnag_app_get_release_stage(void *event_ptr);
void bugsnag_app_set_release_stage(void *event_ptr, char *value);

char *bugsnag_app_get_type(void *event_ptr);
void bugsnag_app_set_type(void *event_ptr, char *value);

char *bugsnag_app_get_version(void *event_ptr);
void bugsnag_app_set_version(void *event_ptr, char *value);

int bugsnag_app_get_version_code(void *event_ptr);
void bugsnag_app_set_version_code(void *event_ptr, int value);

time_t bugsnag_app_get_duration(void *event_ptr);
void bugsnag_app_set_duration(void *event_ptr, time_t value);

time_t bugsnag_app_get_duration_in_foreground(void *event_ptr);
void bugsnag_app_set_duration_in_foreground(void *event_ptr, time_t value);

bool bugsnag_app_get_in_foreground(void *event_ptr);
void bugsnag_app_set_in_foreground(void *event_ptr, bool value);

#ifdef __cplusplus
}
#endif

#endif //BUGSNAG_ANDROID_NDK_BUGSNAG_API_H
