#include <Person.hpp>
#include <jni.h>
#include <jsrc/io_lanza_HiJNI.h>
#include <sstream>

void Person::createDog(std::string Name, int Age) {
  Dogs.emplace_back(Name, Age);
}

void Person::printDogs() const {
  std::cout << Name << ":\n";
  for (auto const &Dog : Dogs)
    std::cout << "    " << Dog.getName() << ":" << Dog.getAge() << '\n';
}

std::ostream &operator<<(std::ostream &O, Person const &P) {
  return O << P.getName() << " : " << P.getAge();
}

JNIEXPORT jstring JNICALL Java_io_lanza_HiJNI_makePersonString(JNIEnv *env,
                                                               jobject ojbect,
                                                               jstring name,
                                                               jint age) {

  jboolean is_copy;
  const char *theName = env->GetStringUTFChars(name, &is_copy);
  std::string cname = std::string(theName, env->GetStringUTFLength(name));

  Person p{cname, age};

  std::stringstream ss;
  ss << "Person(name: " << p.getName() << ", age: " << p.getAge() << ")";

  auto s = ss.str();
  return env->NewStringUTF(s.c_str());
}
