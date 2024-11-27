#include <jni.h>
#include <stdio.h>

JNIEXPORT void JNICALL Java_TestJNIExceptionHandling_triggerException(JNIEnv *env, jobject obj) {
    // Step 1: Simulate an error condition
    printf("Triggering exception in JNI...\n");

    // Step 2: Find the Java exception class
    jclass exceptionClass = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
    if (exceptionClass == NULL) {
        // If the exception class is not found, JNI cannot proceed
        printf("Exception class not found\n");
        return;
    }

    // Step 3: Throw the exception
    (*env)->ThrowNew(env, exceptionClass, "This is a JNI exception example");

    // Step 4: Optionally check and clear the exception
    if ((*env)->ExceptionCheck(env)) {
        printf("Exception has been thrown\n");

        // Clear the exception if you want to handle it differently
        (*env)->ExceptionClear(env);
        printf("Exception cleared in JNI\n");
    }
}
