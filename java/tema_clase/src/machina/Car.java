package machina;
public class Car extends Vehicle {
    private String model;
    private float length;
    private float maxSpeed;
    private float price;
    public Car()
    {
        super();
        this.model="Panzerkampfwagen 38(t)";
        this.length=4.61f;
        this.maxSpeed=42f;
        this.price=1000;
    }
 public Car(String manufacturer,String model,float length,float maxSpeed, float price)
 {
     super(manufacturer);
     this.model=model;
     this.length=length;
     this.maxSpeed=maxSpeed;
     this.price=price;
 }
 public float getPrice()
 {
     return this.price;
 }
 public String getModel()
 {
     return this.model;
 }
}