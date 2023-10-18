namespace cs_form1
{
    public partial class Window1 : Form
    {
        int x = 0;
        String str;
        
        public Window1()
        {
            InitializeComponent();
        }

        private void Window1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Nici aici nu vei gasi ceva.");
        }

        private void noButton_Click(object sender, EventArgs e)
        {
            switch(x%4)
            {
                case 0:str = "Trist"; break;
                case 1: str = "Ce credeai,amigo?"; break;
                case 2: str = "Teapa"; break;
                case 3: str = "Inca incerci?"; break;
            }
            MessageBox.Show(str);
            x = x + 1;
        }

        private void yesButton_MouseHover(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            int x = b.Location.X;
            int y = b.Location.Y;
            yesButton.Location = new Point(x+15,y+15);
        }
    }
}