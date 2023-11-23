package library;
public class Books{
    protected String title;
    protected String author;
    protected String publisher;
    public
    Books()
    {
        this.title="Imperium";
        this.author="Francis Parker Yockey";
        this.publisher="US Gov";
    }
    Books(String title,String author,String publisher)
    {
        this.title=title;
        this.author=author;
        this.publisher=publisher;
    }
}