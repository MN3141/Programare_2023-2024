namespace cs_form1
{
    partial class Window1
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
            this.yesButton = new System.Windows.Forms.Button();
            this.noButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // yesButton
            // 
            this.yesButton.BackColor = System.Drawing.Color.Lime;
            this.yesButton.Location = new System.Drawing.Point(189, 193);
            this.yesButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.yesButton.Name = "yesButton";
            this.yesButton.Size = new System.Drawing.Size(93, 63);
            this.yesButton.TabIndex = 1;
            this.yesButton.Text = "Da";
            this.yesButton.UseVisualStyleBackColor = false;
            this.yesButton.MouseHover += new System.EventHandler(this.yesButton_MouseHover);
            // 
            // noButton
            // 
            this.noButton.BackColor = System.Drawing.Color.Red;
            this.noButton.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.noButton.Location = new System.Drawing.Point(455, 193);
            this.noButton.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.noButton.Name = "noButton";
            this.noButton.Size = new System.Drawing.Size(93, 63);
            this.noButton.TabIndex = 2;
            this.noButton.Text = "Nu";
            this.noButton.UseVisualStyleBackColor = false;
            this.noButton.Click += new System.EventHandler(this.noButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.DarkGray;
            this.label1.Location = new System.Drawing.Point(320, 73);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(116, 15);
            this.label1.TabIndex = 3;
            this.label1.Text = "Doriti bursa copilasi?";
            // 
            // Window1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.ClientSize = new System.Drawing.Size(850, 479);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.noButton);
            this.Controls.Add(this.yesButton);
            this.Cursor = System.Windows.Forms.Cursors.Cross;
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Window1";
            this.Text = "ULBS.com";
            this.Click += new System.EventHandler(this.Window1_Click);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private Button yesButton;
        private Button noButton;
        private Label label1;
    }
}