using System;
using System.Net;
using System.Net.Sockets;

namespace CS_ChatPureClient
{
    class Program
    {
        public static IPAddress GetIPAddress()
        {
            IPHostEntry he = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress iPAddress = null;
            // 처음으로 발견되는 ipv4 주소를 사용한다.
            foreach (IPAddress addr in he.AddressList)
            {
                if (addr.AddressFamily == AddressFamily.InterNetwork)
                {
                    iPAddress = addr;
                    break;
                }
            }

            // 주소가 없다면..
            if (iPAddress == null)
                // 로컬호스트 주소를 사용한다.
                iPAddress = IPAddress.Loopback;

            return iPAddress;
        }

        static public void PureSocketClient()
        {
            Socket socketClient = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);
            IPAddress iPAddress = GetIPAddress();
            int port = 9999;
            IPEndPoint iPEndPoint = new IPEndPoint(iPAddress, port);
            try
            {
                socketClient.Connect(iPEndPoint);
                Console.WriteLine(iPEndPoint.ToString());
            }
            catch (Exception ex)
            {
                Console.WriteLine("Connet Fail!" + ex);
            }

            Console.WriteLine("Connet Server...");
            string msg = null;
            do
            {
                msg = Console.ReadLine();

                if (!socketClient.IsBound)
                {
                    Console.WriteLine("서버가 실행되고 있지 않습니다!");
                }

                string packet = string.Format("{0}:{1}\n", iPAddress, msg);
                byte[] bytes = System.Text.Encoding.UTF8.GetBytes(packet);
                socketClient.Send(bytes);
                Console.WriteLine("Send... " + msg);
            } while (msg != "exit");
        }

        static void Main(string[] args)
        {
            PureSocketClient();
        }
    }
}
