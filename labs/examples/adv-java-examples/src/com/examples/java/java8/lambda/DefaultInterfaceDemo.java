package com.examples.java.java8.lambda;

public interface DefaultInterfaceDemo {
     public default int compute(int a, int b) {
        return sum(a,b);
    }

    static void print() {

    }

    private int sum(int a, int b) {
         return a + b;
    }
}
