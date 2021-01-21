package io.lanza;

public class HiJNI {
  static {
    System.loadLibrary("HiJNINative");
    System.loadLibrary("PersonJNI");
  }

  public static void main(String[] args) {
    HiJNI main = new HiJNI();
    main.sayHello();

    main.printPerson("Muffin", 17);
  }

  private native void sayHello();
  private native String makePersonString(String name, int age);

  public void printPerson(String name, int age) {
    System.out.println(makePersonString(name, age));
  }
}
