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
using System.Windows.Input;
using System.Collections.Specialized;

namespace DBManager
{
    public partial class Form11 : Form
    {

        public Form11()
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
        string sConn= @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=;Integrated Security = True; Connect Timeout = 30";
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
                sbPanel1.BackColor = Color.Green;
            }
            catch(SqlException e1)
            {
                MessageBox.Show(e1.Message);
                sbPanel2.Text = $" DB cannot open";
                sbPanel2.BackColor = Color.Red;
            }
            
        }

        public string GetToken(int index, char deli, string str)
        {
            string[] Strs = str.Split(deli);
            //int n = Strs.Length;
            string ret = Strs[index];
            return ret;
            //this.Text += $"   [{fName2}]";
        }
        string TableName; //다른 메뉴에서 사용할 DB Table 이름. 현재 Open 된 테이블 

        int Runsql(string sql)
        {
            try
            {
                string s1 = sql.Trim();
                sqlCmd.CommandText = sql;
                if (GetToken(0, ' ', sql).ToUpper() == "SELECT")
                {
                    SqlDataReader sr = sqlCmd.ExecuteReader();
                    TableName = GetToken(3, ' ', sql);
                    dataGrid.Rows.Clear();
                    dataGrid.Columns.Clear();
                    for (int i = 0; i < sr.FieldCount; i++) //Header 처리
                    {
                        string ss = sr.GetName(i);
                        dataGrid.Columns.Add(ss, ss);
                    }
                    for(int i=0; sr.Read(); i++)    //1 record read
                    {
                        int rldx = dataGrid.Rows.Add();
                        for (int j=0; j<sr.FieldCount; j++)
                        {
                            object str = sr.GetValue(j);    //1 line 생성
                            dataGrid.Rows[i].Cells[j].Value = str;
                        }
                    }
                    sr.Close();
                }
                else
                {
                    sqlCmd.ExecuteNonQuery();
                }

                sqlCmd.CommandText = sql; //insert into fstatus values(1, 2, 3, 4)
                sqlCmd.ExecuteNonQuery();  //select 문 제외- no return value

                //sqlCmd.ExecuteReader();
                sbPanel2.Text = "success";
                sbPanel2.BackColor = Color.AliceBlue;
            //update, insert, delete, create
            }
            catch (SqlException e1)
            {
                MessageBox.Show(e1.Message);
                sbPanel2.Text = "error";
                sbPanel2.BackColor = Color.Red;
            }
            catch(InvalidOperationException e2)
            {
                MessageBox.Show(e2.Message);
                sbPanel2.Text = "error";
                sbPanel2.BackColor = Color.Red;
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

        private void tbSql_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode != Keys.Enter) return;

            string str = tbSql.Text;
            string[] sArr = str.Split('\n');
            int n = sArr.Length;
            string sql = sArr[n - 1].Trim();
            Runsql(sql);
        }

        private void dataGrid_CellBeginEdit(object sender, DataGridViewCellCancelEventArgs e)
        {
            dataGrid.Rows[e.RowIndex].Cells[e.ColumnIndex].ToolTipText=".";
            //MessageBox.Show(str);
        }

        private void mnuUpdate_Click(object sender, EventArgs e)
        {
            for(int i=0; i<dataGrid.Rows.Count; i++)
            {
                for(int j=0; j<dataGrid.Columns.Count; j++)
                {
                    string s = dataGrid.Rows[i].Cells[j].ToolTipText;
                    if (s == ".")   //update [Table] set [field] = [CellText] where [1st_Col_Name]=[ist_Col.CellText]
                                    //update [fStatus] set [temp]=(10)        where [id]=6
                    {
                        string tn = TableName;
                        string fn = dataGrid.Columns[j].HeaderText;
                        string ct = (string)dataGrid.Rows[i].Cells[j].Value;
                        string kn = dataGrid.Columns[0].HeaderText;
                        string kt = (string)dataGrid.Rows[i].Cells[0].Value;
                        string sql = $"update {tn} set {fn}= {ct} where {kn} ={kt}";
                        Runsql(sql);
                    }
                }
            }
        }
    }
}
