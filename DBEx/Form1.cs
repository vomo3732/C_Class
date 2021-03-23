﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace DBManager
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void mnuMigration_Click(object sender, EventArgs e)
        {
            DialogResult ret = openFileDialog1.ShowDialog();
            if (ret != DialogResult.OK) return;
            string nFile = openFileDialog1.FileName;

            StreamReader sr = new StreamReader(nFile);
            //=============================================================
            //    Header 처리 프로세스
            //========================================================
            string buf = sr.ReadLine(); //1 line read: Header Line
            if (buf == null) return;
            string[] sArr = buf.Split(',');
            for (int i = 0; i < sArr.Length; i++)
            {
                dataGrid.Columns.Add(sArr[i], sArr[i]);
            }
            //====================================================
            //      Row 데이터 처리 프로세스
            //=======================================================

            while (true)
            {
                buf = sr.ReadLine(); //1 line read
                if (buf == null) break;
                sArr = buf.Split(',');
                //dataGrid.Rows.Add(sArr);
                int rldx = dataGrid.Rows.Add();  //1 line 생성
                for(int i=0; i<sArr.Length; i++)
                {
                    dataGrid.Rows[rldx].Cells[i].Value = sArr[i];
                }
            }
            
        }
        
        SqlConnection sqlCon = new SqlConnection();
        SqlCommand sqlCmd = new SqlCommand();
        string sConn= @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=;Integrated Security=True;Connect Timeout=30";
        private void mnuDBOpen_Click(object sender, EventArgs e)
        {
            try
            {
                DialogResult ret = openFileDialog1.ShowDialog(); //db file
                if (ret != DialogResult.OK) return;
                string nFile = openFileDialog1.FileName;
                string[] ss = sConn.Split(';');
                //string s1 = $"{ss[1]}{nFile}";
                
                sqlCmd.Connection = sqlCon;
                sqlCon.ConnectionString = $"{ss[0]};{ss[1]}{nFile};{ss[2]};{ss[3]}";
                sqlCon.Open();
                sbPanel1.Text = openFileDialog1.SafeFileName;
                sbPanel2.Text = $" DB open success";
                sbPanel2.BackColor = Color.Green;
            }
            catch(SqlException e1)
            {
                MessageBox.Show(e1.Message);
                sbPanel2.Text = $" DB cannot open";
                sbPanel2.BackColor = Color.Red;
            }
            
        }
        int Runsql(string sql)
        {
            try
            {
                sqlCmd.CommandText = sql;
                sqlCmd.ExecuteNonQuery();//select 문 제외- no return value
            //update, insert, delete, create
            }
            catch (SqlException e1)
            {
                MessageBox.Show(e1.Message);
            }
            catch(InvalidOperationException e2)
            {
                MessageBox.Show(e2.Message);
            }
            return 0;
        }
        private void mnuSql_Click(object sender, EventArgs e)
        {
            Runsql(tbSql.Text);
        }

        private void mnuSelSql_Click(object sender, EventArgs e)
        {
            Runsql(tbSql.SelectedText);
        }
    }
}
