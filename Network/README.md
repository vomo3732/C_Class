#### 04/06

통신을 위한 프로토타입을 만들어서 시험해보았다. IP 주소와 Port 번호를 이용해 client에서 입력한 값을 server에 출력시켜주었다.
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
#### 04/15
Socket을 활용한 통신
```
using jsLibrary;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ChatSocket
{
    public partial class frmSocket : Form
    {
        public frmSocket()
        {
            InitializeComponent();
        }

        //byte[] sAddress = { 0, 0, 0, 0 };  // (127.0.0.1 XXX) : 서버에서 Bind 하기 위한 포트 어드레스
        string sAddress = "0.0.0.0";  // (127.0.0.1 XXX) : 서버에서 Bind 하기 위한 포트 어드레스
        string sPort = "9001";

        string cAddress = "";
        string cPort = "";

        Socket sockServer = null; // Socket을 이용한 서버 프로그램 (Listener 미사용)
        Socket sock = null;
        Thread threadServer = null;
        Thread threadRead = null;
        Thread threadSession = null;
        private void mnuStart_Click(object sender, EventArgs e)
        {
            mnuClientStart.Enabled = false;
            mnuClientStop.Enabled = false;
            this.Text = "Socket Manager - Server Mode";
            if(sockServer == null)
            {
                sockServer = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            }
            else
            {
                if (threadServer != null)
                    threadServer.Abort();
                if (threadRead != null)
                    threadRead.Abort();
                if (threadSession != null)
                    threadSession.Abort();

                sockServer.Close();
                sockServer = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            }
            if(threadServer == null)
            {
                threadServer = new Thread(ServerProcess);
                threadServer.Start();
            }
            if(threadRead == null)
            {
                threadRead = new Thread(ReadProcess);
                threadRead.Start();
            }
            if (threadSession == null)
            {
                threadSession = new Thread(SessionProcess);
                threadSession.Start();
            }
            AddText($"Chat server가 [{sPort}] 포트에서 시작되었습니다.\r\n");
        }

        private void MnuStop_Click(object sender, EventArgs e)
        {
            this.Text = "Socket Manager";
            sock.Close();
            sockServer.Close();
            threadServer.Abort();
            threadRead.Abort();
            mnuClientStart.Enabled = true;
            mnuClientStop.Enabled = true;
            AddText($"Chat server가 종료되었습니다.\r\n");
        }

        byte[] GetIPBytes(string str)  // str "127.0.0.1"  ==> byte[] bArr { 127, 0, 0, 1 }
        {
            string[] sa = str.Split('.');
            byte[] ba = new byte[4];
            if (sa.Length != 4) return null;  // 문자열 오류
            for(int i=0;i<4;i++)
            {
                ba[i] = byte.Parse(sa[i]);
            }

            return ba;

        }

        bool Pending = false;   // 외부로부터의 접속 요청 수신중
        IAsyncResult ar;
        private void OnAccept(IAsyncResult iar)
        {
            Pending = true;
            ar = iar;
        }
        private Socket acceptSocket()
        {
            Socket sock1 = sockServer.EndAccept(ar);                // non Blocking method End  :  실제 소켓을 전달     
            sockServer.BeginAccept(new AsyncCallback(OnAccept), null); // Start listening for next clients requirement
            Pending = false;
            return sock1;
        }

        void DoSession()  // 쓰레드 재 설정
        {
            if (threadSession != null)
            {
                threadSession.Abort(); threadSession = null;
            }
            threadSession = new Thread(SessionProcess);
            threadSession.Start();
        }

        void DoRead()  // 쓰레드 재 설정
        {
            if(threadRead != null)
            {
                threadRead.Abort(); threadRead = null;
            }
            threadRead = new Thread(ReadProcess);
            threadRead.Start();
        }

        //TcpListener listener;
        void ServerProcess()
        {
            //listener.Start();
            IPAddress IP = new IPAddress(GetIPBytes(sAddress));
            IPEndPoint ep = new IPEndPoint(IP, int.Parse(sPort));
            sockServer.Bind(ep);
            sockServer.Listen(10);
            
            sockServer.BeginAccept(new AsyncCallback(OnAccept),null);   // non Blocking method Start
            while (true)
            {
                if (Pending)
                {
                    sock = acceptSocket(); DoRead();
                    AddText($"Remote EndPoint {sock.RemoteEndPoint.ToString()} 로부터 접속되었습니다.\r\n");
                }
                Thread.Sleep(100);
            }
        }

        delegate void cbAddText(string str);
        void AddText(string str)
        {
            if(tbReceive.InvokeRequired)
            {
                cbAddText cb = new cbAddText(AddText);
                Invoke(cb, new object[] { str });
            }
            else
            {
                tbReceive.AppendText(str);
            }
        }

        void ReadProcess()
        {
            while(true)
            {
                if(sock != null && sock.Available > 0)
                {
                    byte[] bArr = new byte[sock.Available]; // 필요한 만큼 배열 선언
                    sock.Receive(bArr);
                    AddText($"{sock.RemoteEndPoint.ToString()}>{Encoding.Default.GetString(bArr)}\r\n");
                }
            }
        }

        void SendText(string str)
        {
            sock.Send(Encoding.Default.GetBytes(str));
            AddText($"=======> {tbSend.Text}\r\n");
        }

        private void Send_Click(object sender, EventArgs e)   // PopupMenu - Send (selected Text)
        {
            if(tbSend.SelectionLength > 0)
                SendText(tbSend.SelectedText);
            else SendText(tbSend.Text);
        }

        iniFile ini = new iniFile(".\\ChatSocket.ini");

        private void frmSocket_FormClosing(object sender, FormClosingEventArgs e)
        {

            ini.GetString("Server", "Port", sAddress);
            ini.GetString("Client", "Port", sPort);
            ini.GetString("Server", "IP", cAddress);
            ini.GetString("Client", "IP", cPort);

            ini.SetString("Server", "Port", sPort);
            ini.SetString("Form", "LocationX", $"{Location.X}");
            ini.SetString("Form", "LocationY", $"{Location.Y}");
            ini.SetString("Form", "SizeX", $"{Size.Width}");
            ini.SetString("Form", "SizeY", $"{Size.Height}");

            if (threadServer != null)
                threadServer.Abort();
            if (threadRead != null)
                threadRead.Abort();
        }

        private void frmSocket_Load(object sender, EventArgs e)
        {
            int x1, x2, y1, y2;
            sPort = ini.GetString("Server", "Port", "9001");
            cPort = ini.GetString("Client", "Port", "9001");
            sAddress = ini.GetString("Server", "IP", "0.0.0.0");
            cAddress = ini.GetString("Client", "IP", "127.0.0.1");

            sbLabel1.Text = sAddress;
            sbLabel2.Text = sPort;
            sbLabel3.Text = cAddress;
            sbLabel4.Text = cPort;

            x1 = int.Parse(ini.GetString("Form", "LocationX", "0"));
            y1 = int.Parse(ini.GetString("Form", "LocationY", "0"));
            this.Location = new Point(x1, y1);

            x2 = int.Parse(ini.GetString("Form", "SizeX", "500"));
            y2 = int.Parse(ini.GetString("Form", "SizeY", "500"));
            this.Size = new Size(x2, y2);
        }

        private void tbSend_KeyUp(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                SendText(tbSend.Text);
                tbSend.Clear();
            }
        }

        private void mnuServerIP_Click(object sender, EventArgs e)
        {
            string str = jslib.GetInput("Server IP Address");
            if (str != "")  //  DialogResult.OK
                sAddress = str;

            sbLabel1.Text = sAddress;
            
        }
        
        private void mnuServerPort_Click(object sender, EventArgs e)
        {
            string str = jslib.GetInput("Server Port");
            if (str != "")  //  DialogResult.OK
            {
                try
                {
                    int n = int.Parse(str);
                    sPort = str;
                }
                catch(Exception e1)
                {
                    MessageBox.Show("포트 입력값에 문제가 있습니다.");
                }
            }
            sbLabel2.Text = sPort;
        }

        private void mnuClientIP_Click(object sender, EventArgs e)
        {
            string str = jslib.GetInput("Client IP Address");
            if (str != "")  //  DialogResult.OK
                cAddress = str;
            sbLabel3.Text = cAddress;
        }

        private void mnuClientPort_Click(object sender, EventArgs e)
        {
            string str = jslib.GetInput("Clien Port");
            if (str != "")  //  DialogResult.OK
            {
                try
                {
                    int n = int.Parse(str);
                    cPort = str;
                }
                catch(Exception e1)
                {
                    MessageBox.Show("포트 입력값에 문제가 있습니다.");
                }
                sbLabel4.Text = cPort;
            }
        }

        private void SbLabel1_DoubleClick(object sender, EventArgs e)
        {
            mnuServerIP_Click(sender, e);
        }

        private void SbLabel2_DoubleClick(object sender, EventArgs e)
        {
            mnuServerPort_Click(sender, e);
        }

        private void SbLabel3_DoubleClick(object sender, EventArgs e)
        {
            mnuClientIP_Click(sender, e);
        }

        private void SbLabel4_DoubleClick(object sender, EventArgs e)
        {
            mnuClientPort_Click(sender, e);
        }

        Socket cSock = null;
        private void MnuClientStart_Click(object sender, EventArgs e)
        {
            mnuStart.Enabled = false;
            mnuStop.Enabled = false;
            this.Text = "Socket Manager - Client Mode";
            if (cSock == null)
            {
                cSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            }
            cSock.Connect(cAddress, int.Parse(cPort));  //blocking method
            sock = cSock;
            DoRead();
            DoSession();
        }

        
        private void MnuClientStop_Click(object sender, EventArgs e)
        {
            this.Text = "Socket Manager";
            mnuStart.Enabled = true;
            mnuStop.Enabled = true;

            
        }
        delegate void cbThread(int n);

        void ChangeColor(int n)
        {
            if (statusStrip1.InvokeRequired)
            {
                cbThread cb = new cbThread(ChangeColor);
                Invoke(cb, new object[] { n });
            }
            else
            {
                if (n==1)
                {
                    sbLabel1.BackColor = Color.GreenYellow;
                }
                else
                {
                    sbLabel1.BackColor = Color.PaleVioletRed;
                    sock = null;
                }
            }
            
        }
        void SessionProcess()
        {
            while (true)
            {
                if (sock != null && sock.Connected)
                {
                    ChangeColor(1);
                }
                else
                {
                    ChangeColor(2);
                    sock = null;
                }
                Thread.Sleep(100);
            }
           
        }
    }
}
```
#### 05/03 
Encrypt 함수를 이용한 암호화에 대해 배웠다. 해당 함수에서 제대로 동작하지 않는 부분이 있는데 내일 해결해보기로 했다!
```
string GetEncrypt(string str)
        {
            MD5 md = new MD5CryptoServiceProvider();
            byte[] bArr = md.ComputeHash(Encoding.Default.GetBytes(str));
            string sRet = "";
            for (int i = 0; i < bArr.Length; i++)
            {
                sRet += $"{bArr[i]:x2}";
            }
            return sRet;
        }
```

