
class Animal {
    private String name;
    public Animal(String name) {
        this.name = name; 
    }
    public void display() {
        System.out.println("Animal name: " + this.name);
    }
}

class Dog extends Animal {
    protected String breed;
    public Dog(String name) {
        
        super(name);
    }

    public Dog(String name, String breed) {
        super(name);
        this.breed = breed;
    }
    public void display() {
        super.display();
        System.out.println("Dog breed: " + this.breed);
    }
}

public class homewrok_3 {
    public static void main(String[] args) {
        Animal myAnimal = new Animal("Wangcai");
        Animal myDog = new Dog("Wangcai", "Samoyed");
        myAnimal.display();
        myDog.display();
    }
}