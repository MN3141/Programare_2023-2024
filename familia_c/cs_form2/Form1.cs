namespace cs_form2
{
    public partial class f1 : Form
    {
        public f1()
        {
            InitializeComponent();
        }

        private void button0_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label0.Text = "Modificat";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            String text;
            text = textBox0.Text;
            label0.Text = text;
        }
    }
}