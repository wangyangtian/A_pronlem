

interface MyInterface {
    void doSomething();
}

abstract class AbstractClass implements MyInterface {
    abstract void doSomethingElse();
}

class ConcreteClass extends AbstractClass {
    public void doSomething() {
        System.out.println("Doing something...");
    }

    void doSomethingElse() {
        System.out.println("Doing something else...");
    }
}

public class homework_4 {
    public static void main(String[] args) {
        ConcreteClass cc = new ConcreteClass();

        if (cc instanceof AbstractClass) {
            cc.doSomething();
            cc.doSomethingElse();
        }

        try {
            throw new Exception("An exception occurred!");
        } catch (Exception e) {
            System.out.println("Caught exception: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed.");
        }
    }
}