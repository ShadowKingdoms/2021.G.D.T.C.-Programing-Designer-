using System;
using System.Net;
using System.Net.Sockets;

namespace CS_ChatPureServer
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

        static public void PureSocketServer()
        {
            Socket socketServer = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.IP);

            IPAddress iPAddress = GetIPAddress();
            int port = 9999;
            IPEndPoint serverEP = new IPEndPoint(iPAddress, port);
            socketServer.Bind(serverEP);
            Console.WriteLine("Server Bind...");
            socketServer.Listen(10);
            Console.WriteLine("Server Listening...");
            Console.WriteLine("Client Waiting...");
            Socket socketClient = socketServer.Accept();
            Console.WriteLine("socket Client Accept!!");

            string data = null;
            do
            {
                byte[] bytes = new byte[1024];
                Array.Clear(bytes, 0, 1024);

                socketClient.Receive(bytes);

                data = System.Text.Encoding.UTF8.GetString(bytes);
                Console.WriteLine(data);
                Array.Clear(bytes, 0, 1024);
            }
            while (data != "exit");
            socketServer.Close();
            string msg = Console.ReadLine();
        }

        static void Main(string[] args)
        {
            PureSocketServer();
        }
    }
}
