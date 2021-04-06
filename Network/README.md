#### 04/06

통신을 위한 프로토타입을 만들어서 시험해보았다. IP 주소와 Port 번호를 이용해 client에서 입력한 값을 server에 출력시켜주었다.\n
FormServer.cs
```
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConTest
{
    public partial class FormServer : Form
    {
        public FormServer()
        {
            InitializeComponent();
        }


        private void BtnSend_Click(object sender, EventArgs e) // send 1 packet : 통신 메시지 단위 1024Byte= 1K LTE
        {
            // 1. Socket 생성 : 주소가 없음
            // 2. Socket Open - Connection 수립 - 주소 부여
            // 3. 메시지 전송 : Message - 문자열 외에 이미지나 동영상도 가능, 단 양측이 서로 약속된 규약에 의해서...==> 프로토콜 제정
            Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp); //Tcp: 수신 확인, Udp: 수신 확인 없음(방송)
            sock.Connect(tbIP.Text, int.Parse(tbPort.Text));
            string str = tbClient.Text;
            byte[] bArr = Encoding.Default.GetBytes(str); //char[] == string
            sock.Send(bArr);
        }

        private void BtnStart_Click(object sender, EventArgs e)
        {
            // 1. 무한 수신 대기 wait
            // 2. 기존 이벤트 처리
            // 3. 외부 접속 요청 수신시 해당 요청 처리
            if (thread == null)
            {
                thread = new Thread(ServerProcess);
                thread.Start();
            }
            else
            {
                thread.Resume();
            }
            sbServerMessage.Text = "thread on running";
            timer1.Enabled = true;

            //ServerProcess();
           
        }
        Thread thread = null;
        string MainMsg;
        TcpListener listener = null;
        byte[] bArr = new byte[200];
        private void ServerProcess()
        {
            while (true)
            {
                if(listener==null) listener= new TcpListener(int.Parse(tbServerPort.Text));
                //TcpListener listener = new TcpListener(int.Parse(tbServerPort.Text));
                listener.Start(); //listener 는 계속 수행 - stop 명령까지
                //sbServerMessage.Text = "Listening.....";
                //this.Invalidate();
                if (listener.Pending())
                {
                    TcpClient tcp = listener.AcceptTcpClient(); //외부로부터의 접속 요청 수신
                    //sbServerMessage.Text = "Connected";
                    //sbServerLabel2.Text = "Connected";
                    NetworkStream ns = tcp.GetStream();
                    while (ns.DataAvailable)
                    {
                        ns.Read(bArr, 0, 200);
                        MainMsg += Encoding.Default.GetString(bArr);
                    }

                }
                
    //          Socket sock = listener.AcceptSocket();
                listener.Stop();
            }
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
            tbServer.Text = MainMsg;
        }

        private void BtnStop_Click(object sender, EventArgs e)
        {
            thread.Suspend();
            if (thread.IsAlive) sbServerMessage.Text = "Thread alived";
            else sbServerMessage.Text = "thread not alived";
        }

        private void FormServer_FormClosed(object sender, FormClosedEventArgs e)
        {
            thread.Abort();
            // ThreadState threadstate = 
        }
    }
}

```

FormClient.cs
```
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConClient
{
    public partial class FormClient : Form
    {
        public FormClient()
        {
            InitializeComponent();
        }

        private void BtnSend_Click(object sender, EventArgs e)
        {
            Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            sock.Connect(tbIP.Text, int.Parse(tbPort.Text));
            //string str= tbclient.text;
            //byte[] bArr=encoding.default.getbytes(str);
            //sock.send(barr);
            int ret = sock.Send(Encoding.Default.GetBytes(tbClient.Text));
            if (ret > 0) sbMessage.Text = $"{ret} byte(s) send success";
        }
    }
}

```
