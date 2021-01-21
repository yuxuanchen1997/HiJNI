#include <iostream>
#include <jni.h>
#include <jsrc/io_lanza_HiJNI.h>

JNIEXPORT void JNICALL Java_io_lanza_HiJNI_sayHello(JNIEnv *env,
                                                    jobject thisObject) {
  std::cout << "Hi JNI" << std::endl;
}
