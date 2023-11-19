/*
The current program is only works for positive integer numbers in base 10
*/
using System;
namespace afisaz_baze_nr
{
    public partial class form : Form
    {
        public form()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        public class Functions
        {
            public int digits_BCD(int n) //determines the number of necessary bits
            {                   //for the bcd array
                n = (int)Math.Pow(2, n);
                int k = 0;
                while (n > 0)
                {
                    n = n / 10;
                    k++;
                }
                return k * 4;
            }
            public int digits(int n) //determines the number of digits for
            {               // the input number
                int ct = 0;
                while (n > 0)
                {
                    n = n / 10;
                    ct++;
                }
                return ct;
            }
        }
        class Num
        {
            Functions f;
            public int num_bits;
            public char[] symbols = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
            public char[] binary;
            public char[] bcd;
            public char[] octal;
            public char[] hex;
            public
                  Num()
            {
                num_bits = 8;
                binary = new char[num_bits];
               
            }
            public Num(int n)
            {
                num_bits = n;
                binary = new char[num_bits];
                
            }
            public void toBinary(int dec_num)
            {
                for (int i = num_bits - 1; i >= 0; i--)
                {
                    binary[i] = symbols[dec_num % 2];
                    dec_num = dec_num / 2;
                }
            }
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            Num x = new Num();
            int temp_num = 0;
              try
            {
                temp_num= int.Parse(numPrompt.Text);
            }
            catch(System.FormatException exception)
            {
                MessageBox.Show(exception.Message);
            }
            if(temp_num<0)
                MessageBox.Show("Enter positive integer");
            else if(temp_num>=Math.Pow(2,x.num_bits))
                MessageBox.Show("The number is not in domain");
            else
            {
                x.toBinary(temp_num);
                string temp_string = new string(x.binary);
                labelBinary.Text=temp_string;
            }
        }
    }
   
    }
