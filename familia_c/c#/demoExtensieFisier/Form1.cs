using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization.Formatters.Binary;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using static System.IO.FileStream;
namespace demoExtensieFisier
{
    struct Figure{ // incalc principiul incapsularii
        public int code;//0 pt triunghi;1 pt patrat;2 pt cerc
        public int x;//--------------
        public int y;//coordonatele
                     //--------------
    };
    //CODIFICARE:codFigura_coordonataX_coordonataX,unde _ denota spatiu intre
    //EX:1 100 100->patrat cu centru in (100,100)
    //EX2:0 200 500->triunghi cu centrul in (200,500)
    //Ramane dupa tine sa faci maparea dintre nr si figuri
    public partial class fMain : Form
    {
        static int counter = 0;//folosit pt indexare
        static Figure[] tabFiguri=new Figure[100];//folosit pt a transmite figurile inspre fisier sau invers
        public fMain()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnSquare_Click(object sender, EventArgs e)//in loc de label se vor instantia patrate/cercuri etc implementate
        {
            Label labelSquare = new Label();
            labelSquare.Location = new Point(100+40*counter,100+ 40*counter);
            labelSquare.Text = "Patrat"+counter.ToString();
            labelSquare.Click += nameLabel_Click;
            labelSquare.Name = counter.ToString();//in Name voi pastra nr figurii curente pt indexare
            this.Controls.Add(labelSquare);
            tabFiguri[counter].code=1;
            tabFiguri[counter].x = labelSquare.Location.X;
            tabFiguri[counter].y = labelSquare.Location.Y;
            counter++;
        }
        private void nameLabel_Click(object sender, EventArgs e)
        {
            int index =Int32.Parse(((Label)sender).Name);//s-ar putea si mai elegant cred
            MessageBox.Show(tabFiguri[index].code.ToString()+" "+tabFiguri[index].x.ToString()+" "+tabFiguri[index].y.ToString());
        }

        private void btnTriangle_Click(object sender, EventArgs e)
        {
            Label labelTriangle = new Label();
            labelTriangle.Location = new Point(100 + 50 * counter, 100 + 50 * counter);
            labelTriangle.Text = "Triunghi" + counter.ToString();
            labelTriangle.Click += nameLabel_Click;
            labelTriangle.Name = counter.ToString();
            this.Controls.Add(labelTriangle);
            tabFiguri[counter].code = 0;
            tabFiguri[counter].x = labelTriangle.Location.X;
            tabFiguri[counter].y = labelTriangle.Location.Y;
            counter++;
        }

        private void btnCircle_Click(object sender, EventArgs e)
        {
            Label labelCircle = new Label();
            labelCircle.Location = new Point(100 + 60 * counter, 100 + 60 * counter);
            labelCircle.Text = "Cerc" + counter.ToString();
            labelCircle.Click += nameLabel_Click;//asociere eveniment
            labelCircle.Name = counter.ToString();
            this.Controls.Add(labelCircle);
            tabFiguri[counter].code = 2;
            tabFiguri[counter].x = labelCircle.Location.X;
            tabFiguri[counter].y = labelCircle.Location.Y;
            counter++;
        }

        private void btnSave_Click(object sender, EventArgs e)
        { 
            String path = System.IO.Path.GetDirectoryName(Application.ExecutablePath);//vezi ca iti va salva in bin\Debug
            path = path + "\\test.estera";
            FileStream fin = new FileStream(path, FileMode.Truncate);//resetare fisier pt a nu avea dubluri
            fin.Close();//OBS:daca uiti sa inchizi fisierul crapa tot!
            //OBS:daca fisierul nu exista initial,el va fi creat automat
            fin = new FileStream(path, FileMode.Append);
            for(int i=0;i<counter;i++)
           {
               byte[] temp = Encoding.ASCII.GetBytes(tabFiguri[i].code.ToString() + " " + tabFiguri[i].x.ToString() + " " + tabFiguri[i].y.ToString()+" ");
               fin.Write(temp, 0,temp.Length);
            }
            fin.Close();
        }

        private void btnLoad_Click(object sender, EventArgs e)
        {
            //preluam elementele asa cum preluam date pt structuri de tip Student anul trecut
            String path = System.IO.Path.GetDirectoryName(Application.ExecutablePath);
            path = path + "\\test.estera";
            FileStream fout = new FileStream(path, FileMode.Open);//pare-se ca 1 figura ocupa 10 octeti
            byte[] temp = new byte[10];
            int i = 0;
            for (int j=0;j<fout.Length;j=j+10)
            {
                fout.Seek(j, SeekOrigin.Begin);
                fout.Read(temp, 0, 10);
                string bufferRead = Encoding.ASCII.GetString(temp);
                string[] strinkToken = bufferRead.Split(' ');       
                tabFiguri[i].code = Int32.Parse(strinkToken[0]);
                tabFiguri[i].x = Int32.Parse(strinkToken[1]);
                tabFiguri[i].y = Int32.Parse(strinkToken[2]);
                i++;
            }
            counter = i;
            fout.Close();
            for (int j = 0; j <i; j++)
                MessageBox.Show(tabFiguri[j].code.ToString() + " " + tabFiguri[j].x.ToString() + " " + tabFiguri[j].y.ToString());

        }
    }
}
