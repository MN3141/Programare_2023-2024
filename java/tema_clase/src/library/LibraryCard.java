package library;
public class LibraryCard extends Books{
    private int copies;

    public LibraryCard()
    {
        super();
        this.copies=1000000;
    }
    public  LibraryCard(String title,String author,String publisher,int copies) {
        super(title,author,publisher);
        this.copies = copies;
    }
    public int getCopies()
    {
        return this.copies;
    }
    public String getTitle()
    {

        return this.Title();
    }
}