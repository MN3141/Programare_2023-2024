package library;
public class LibraryCard extends Books{
    private int copies;

    public LibraryCard()
    {
        this.copies=1000000;
    }
    public  LibraryCard(String title,String author,String publisher,int copies) {
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.copies = copies;
    }
    public int getCopies()
    {
        return this.copies;
    }
    public String getTitle()
    {
        return this.title;
    }
}