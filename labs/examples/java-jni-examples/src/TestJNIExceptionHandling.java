public class TestJNIExceptionHandling {
    static {
        System.loadLibrary("jniexception"); // Load the shared native library
    }

    public native void triggerException();


    public static void main(String[] args) {
        TestJNIExceptionHandling example = new TestJNIExceptionHandling();

        try {
            example.triggerException();
        } catch (Exception e) {
            System.out.println("Caught exception in Java triggered from C++: " + e.getMessage());
        }
    }
}

