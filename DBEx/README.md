
#### 03/22
SQL언어에 대한 문법적인 내용을 배웠고 C#환경에서 Grid를 이용하는 법을 다룸

```
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsDBManager
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnInput_Click(object sender, EventArgs e)
        {
            string str = tbInput.Text; 
            
            dbGrid.Columns.Add(str, str);
            dbGrid.Rows.Add( );
        }

        private void btnValue_Click(object sender, EventArgs e)
        {
            string str = tbValue.Text;
            dbGrid.Rows[1].Cells[2].Value = str;
        }

    }
}

```

#### 03/23

직접적으로 sql문을 만들고 해당 데이터를 불러오고 SQL언어를 이용해 update하고 insert하는 법에 대해 배움

```
using System;
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

```

#### 03/24
select 문을 통해 값을 받아와 dataGrid 창에 변수명과 값 띄우기
Header Text 를 getName 함수를 통해 추가하고 각 열들의 값들을 추가해줌
```
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
```
엔터키가 입력되면 직전 줄의 동작수행하게 하기
```
private void tbSql_KeyDown(object sender, KeyEventArgs e)
{
            if (e.KeyCode != Keys.Enter) return;

            string str = tbSql.Text;
            string[] sArr = str.Split('\n');
            int n = sArr.Length;
            string sql = sArr[n - 1].Trim();
            Runsql(sql);
}
```
수정된 사항이 있으면 dataGrid.Rows의 해당 부분의 tooltiptext가 '.'으로 나타나게 함\
전체 cell을 검색해서 수정된 사항이 있으면(tooltiptext가 .이면) update에 필요한 변수 세팅 후 update문을 보관문자열로 작성한 뒤 동작 수행하게 함
```
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
```

#### 03/25
dropdown 버튼이 눌렸을 때 해당 table 값 grid에 출력하게 하기
```
       private void sbButton1_DropDownItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            string s = e.ClickedItem.Text;
            string sql = $"select * from {s}";
            sbButton1.Text = s;
            Runsql(sql);
        }
```
새로운 열 이름 입력받아서 해당 테이블에 추가하기
 ```
 private void mnuEditColumn_Click(object sender, EventArgs e)
        {
            //메뉴상에서 column 추가를 눌렀을 때!
            //Form2라는 팝업창 하나 생성
            Form2 dlg = new Form2("new column name");
            DialogResult ret = dlg.ShowDialog();
            if (ret == DialogResult.OK)
            {
                string nw = dlg.NewColumn;
                dataGrid.Columns.Add(nw, nw);
                //열 추가하기
            }
        }
```
database 닫는 창 만들기
```
 private void mnuDBClose_Click(object sender, EventArgs e)
        {
            sqlCon.Close();
            sbPanel1.Text = "DB File Name";
            sbPanel2.Text = $" DB closed";
            sbPanel1.BackColor = Color.Gray;


            sbButton1.DropDownItems.Clear();
        }
```
신규 테이블명 입력받아서 그 이름으로 테이블을 생성하고 해당 속성들을 신규 테이블에 모두 대입하기
```
//create table [tablename]{
        // [column1] nchar(20),
        // [column2] nchar(20),
        // [column3] nchar(20),
        // ...
        //)

        private void mnuNewTable_Click(object sender, EventArgs e)
        {
            Form2 dlg = new Form2("신규 테이블명");
            if (dlg.ShowDialog() != DialogResult.OK) return;
            string tableName = dlg.NewColumn;
            string sql = $"Create table {tableName} (";
            for(int i=0; i<dataGrid.ColumnCount; i++)
            {
                sql += $"{dataGrid.Columns[i].HeaderText} nchar(20)";
                if (i < dataGrid.ColumnCount - 1) sql += ",";
            }
            sql += ")";
            Runsql(sql);//신규 테이블 생성 완료
            //insert into [tablename] values (
            // [col_val_1], [col_val_2], ...
            // )
            for(int i=0; i<dataGrid.RowCount; i++)
            {
                sql = $"insert into {tableName} values (";

                for(int j=0; j<dataGrid.Columns.Count; j++)
                {
                    sql += $"'{dataGrid.Rows[i].Cells[j].Value}";
                    if (i < dataGrid.ColumnCount - 1) sql += ","; ;
                }
                sql += ")";
                Runsql(sql);
            }
```
