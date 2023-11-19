namespace afisaz_baze_nr
{
    partial class form
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
            this.numPrompt = new System.Windows.Forms.TextBox();
            this.labelBinary = new System.Windows.Forms.Label();
            this.okButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // numPrompt
            // 
            this.numPrompt.Location = new System.Drawing.Point(86, 116);
            this.numPrompt.Name = "numPrompt";
            this.numPrompt.Size = new System.Drawing.Size(164, 27);
            this.numPrompt.TabIndex = 0;
            this.numPrompt.Text = "Enter a positive integer";
            // 
            // labelBinary
            // 
            this.labelBinary.AutoSize = true;
            this.labelBinary.Location = new System.Drawing.Point(440, 146);
            this.labelBinary.Name = "labelBinary";
            this.labelBinary.Size = new System.Drawing.Size(41, 20);
            this.labelBinary.TabIndex = 1;
            this.labelBinary.Text = "0000";
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(106, 217);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(94, 29);
            this.okButton.TabIndex = 2;
            this.okButton.Text = "Ok";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.labelBinary);
            this.Controls.Add(this.numPrompt);
            this.Name = "form";
            this.Text = "Base converter";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private TextBox numPrompt;
        private Label labelBinary;
        private Button okButton;
    }
}