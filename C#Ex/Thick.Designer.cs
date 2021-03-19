
namespace WindowsFormsGraph
{
    partial class Thick
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tbThick = new System.Windows.Forms.TextBox();
            this.thickButton = new System.Windows.Forms.Button();
            this.tbRow = new System.Windows.Forms.TextBox();
            this.tbCol = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.Cancelbutton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbThick
            // 
            this.tbThick.Location = new System.Drawing.Point(83, 30);
            this.tbThick.Name = "tbThick";
            this.tbThick.Size = new System.Drawing.Size(117, 21);
            this.tbThick.TabIndex = 0;
            // 
            // thickButton
            // 
            this.thickButton.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.thickButton.Location = new System.Drawing.Point(220, 30);
            this.thickButton.Name = "thickButton";
            this.thickButton.Size = new System.Drawing.Size(91, 44);
            this.thickButton.TabIndex = 1;
            this.thickButton.Text = "OK";
            this.thickButton.UseVisualStyleBackColor = true;
            this.thickButton.Click += new System.EventHandler(this.thickButton_Click);
            // 
            // tbRow
            // 
            this.tbRow.Location = new System.Drawing.Point(83, 69);
            this.tbRow.Name = "tbRow";
            this.tbRow.Size = new System.Drawing.Size(117, 21);
            this.tbRow.TabIndex = 4;
            // 
            // tbCol
            // 
            this.tbCol.Location = new System.Drawing.Point(83, 112);
            this.tbCol.Name = "tbCol";
            this.tbCol.Size = new System.Drawing.Size(117, 21);
            this.tbCol.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 12);
            this.label1.TabIndex = 6;
            this.label1.Text = "thickness";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 72);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 12);
            this.label2.TabIndex = 7;
            this.label2.Text = "X-Axis";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 115);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(44, 12);
            this.label3.TabIndex = 8;
            this.label3.Text = "Y-Axis";
            // 
            // Cancelbutton
            // 
            this.Cancelbutton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.Cancelbutton.Location = new System.Drawing.Point(220, 95);
            this.Cancelbutton.Name = "Cancelbutton";
            this.Cancelbutton.Size = new System.Drawing.Size(91, 44);
            this.Cancelbutton.TabIndex = 9;
            this.Cancelbutton.Text = "취소";
            this.Cancelbutton.UseVisualStyleBackColor = true;
            // 
            // Thick
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(323, 151);
            this.Controls.Add(this.Cancelbutton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbCol);
            this.Controls.Add(this.tbRow);
            this.Controls.Add(this.thickButton);
            this.Controls.Add(this.tbThick);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Thick";
            this.Text = "Thick";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbThick;
        private System.Windows.Forms.Button thickButton;
        private System.Windows.Forms.TextBox tbRow;
        private System.Windows.Forms.TextBox tbCol;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Cancelbutton;
    }
}