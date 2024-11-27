## JNI Example
This is a simple example of how to use JNI to call a C function from Java.

### Compile the Java file
```bash
javac HelloWorldJNI.java
```

### Generate the header file
```bash 
javac -h jni -d bin src/HelloWorldJNI.java
```

### Generate the shared library for Linux OS
```bash
gcc -shared -o bin/libhelloworld.so -fPIC jni/HelloWorldJNI.c -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux"
```

### Generate the shared library for Mac OS
```bash
gcc -shared -o bin/libhelloworld.dylib -fPIC jni/HelloWorldJNI.c -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin"
```
```bash
ls /Library/Java/JavaVirtualMachines/jdk-17.jdk/Contents/Home/include/darwin/jni_md.h\n
```

### Generate the shared library for Windows OS
```bash
gcc -shared -o bin/helloworld.dll -fPIC jni/HelloWorldJNI.c -I"%JAVA_HOME%/include" -I"%JAVA_HOME%/include/win32"
```

### Run the Java program
```bash
java -cp bin -Djava.library.path=bin HelloWorldJNI
```
