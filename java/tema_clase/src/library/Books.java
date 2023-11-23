package library;
public class Books{
    private String title;
    private String author;
    private String publisher;
    public Books()
    {
        this.title="Imperium";
        this.author="Francis Parker Yockey";
        this.publisher="US Gov";
    }
    public Books(String title,String author,String publisher)
    {
        this.title=title;
        this.author=author;
        this.publisher=publisher;
    }
    public String Title()
    {
        return this.title;
    }
}