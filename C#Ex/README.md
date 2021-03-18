
#### 03/18
*C# windows form edit* 창을 사용해서 editor를 메모장과 같은 동작을 하게끔 직접 동작시킴
```
using myLibrary;
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

namespace WindowsFormsEdit
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void mnuFileOpen_Click(object sender, EventArgs e)
        {
            DialogResult ret = openFileDialog1.ShowDialog(); //C++ DoModal
            if (ret == DialogResult.OK)
            {
                string fName=openFileDialog1.FileName; //full path
                string fName1 = openFileDialog1.SafeFileName;
                StreamReader sr = new StreamReader(fName);///c:File* c++:CFile
                string buf = sr.ReadToEnd();
           
                tbMemo.Text = buf;
                sr.Close();
                //fName.
                int n = myLib.Count('\\', fName);
                string fName2 = myLib.GetToken(n, '\\', fName);
                this.Text += $"    [{fName2}]";
            }
        }

        //Save As....
        private void mnuFileSave_Click(object sender, EventArgs e)
        {

            DialogResult ret = saveFileDialog1.ShowDialog();
            if (ret == DialogResult.OK)
            {
                string fName = saveFileDialog1.FileName;    // File full path
                StreamWriter sw = new StreamWriter(fName);  // save 이므로 Write
                                                        // StreamWriter sw = new StreamWriter(saveFileDialog1.FileName);
                string buf = tbMemo.Text;                   // 굳이 필요 없는 단계임
                sw.Write(buf);                              // 한줄로 sw.Write(tbMemo.text); 로 쓸 수 있음
                sw.Close();          
            }                      
        }


        //1. file open 후 Memo 창에 표시한 경우- 확인 O 수정 X
        //2. New 메뉴 선택 후 문서 편집- file 명 없음
        //3. 기존 문서 중 일부 수정-file명 있음

        int txtChanged = 0;
        private void tbMemo_TextChanged(object sender, EventArgs e)
        {
            if (true) txtChanged = 1;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (txtChanged == 1)
            {

            }
        }

        private void SetFontInfo()
        {
            sbLabel1.Text = tbMemo.Font.Name+$",  {tbMemo.Font.Height}";
        }
        private void mnuViewFont_Click(object sender, EventArgs e)
        {
            DialogResult ret = fontDialog1.ShowDialog();
            if (ret == DialogResult.Cancel) return;

            Font fnt=fontDialog1.Font;
            tbMemo.Font = fnt;
            SetFontInfo();
        }

        private void mnuViewChline_Click(object sender, EventArgs e)
        {
            //줄바꿈이 눌렸을 때 해야하는 동작
            string buf = "\n\n";
            tbMemo.Text = buf;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            SetFontInfo();
        }

    }
}

```
  
    사용한 myLib내용
  ```
  namespace myLibrary
{
    class myLib
    {
        public static int Count(char deli, string str)
        {
            string[] Strs = str.Split(deli);
            int n = Strs.Length;
            return n - 1;
        }

        public static string GetToken(int index, char deli, string str)
        {
            string[] Strs = str.Split(deli);
            //            int n = Strs.Length;
            string ret = Strs[index];
            return ret;
            //this.Text += $"   [{fName2}]";
        }
    }
}
  ```
  
