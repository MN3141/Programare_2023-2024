namespace cs_form2
{
    partial class f1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.label0 = new System.Windows.Forms.Label();
            this.button0 = new System.Windows.Forms.Button();
            this.textBox0 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(503, 37);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(145, 81);
            this.button1.TabIndex = 0;
            this.button1.Text = "Unu";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(503, 124);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(145, 81);
            this.button2.TabIndex = 1;
            this.button2.Text = "Doi";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label0
            // 
            this.label0.AutoSize = true;
            this.label0.Location = new System.Drawing.Point(139, 37);
            this.label0.Name = "label0";
            this.label0.Size = new System.Drawing.Size(64, 15);
            this.label0.TabIndex = 2;
            this.label0.Text = "Semigrupa";
            // 
            // button0
            // 
            this.button0.Location = new System.Drawing.Point(503, 225);
            this.button0.Name = "button0";
            this.button0.Size = new System.Drawing.Size(145, 81);
            this.button0.TabIndex = 3;
            this.button0.Text = "Exit";
            this.button0.UseVisualStyleBackColor = true;
            this.button0.Click += new System.EventHandler(this.button0_Click);
            // 
            // textBox0
            // 
            this.textBox0.Location = new System.Drawing.Point(108, 95);
            this.textBox0.Name = "textBox0";
            this.textBox0.Size = new System.Drawing.Size(113, 23);
            this.textBox0.TabIndex = 4;
            // 
            // f1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBox0);
            this.Controls.Add(this.button0);
            this.Controls.Add(this.label0);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "f1";
            this.Text = "Fereastra";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Button button1;
        private Button button2;
        private Label label0;
        private Button button0;
        private TextBox textBox0;
    }
}