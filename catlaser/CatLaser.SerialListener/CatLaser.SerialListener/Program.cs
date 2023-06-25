using System.IO.Ports;
using static System.Net.Mime.MediaTypeNames;

namespace CatLaser.SerialListener
{
    internal class Program
    {
        const string portName = "COM3";
        const int baudRate = 9600;
        static bool _continue;
        static SerialPort _serialPort;
        static byte[] _writeBuffer = new byte[1];
        static Dictionary<ConsoleKey, char> _keyMappings = new Dictionary<ConsoleKey, char>()
        {
            { ConsoleKey.LeftArrow, 'a' },
            { ConsoleKey.RightArrow, 'd' },
            { ConsoleKey.UpArrow, 'w' },
            { ConsoleKey.DownArrow, 's' },
        };

        static void Main(string[] args)
        {
            Console.WriteLine("Available Ports:");
            foreach (string s in SerialPort.GetPortNames())
            {
                Console.WriteLine("\t{0}", s);
            }

            _serialPort = new SerialPort(portName, baudRate);
            Console.WriteLine(" PortName: {0}", _serialPort.PortName);
            Console.WriteLine(" BaudRate: {0}", _serialPort.BaudRate);

            var readThread = new Thread(ReadRaw);
            _serialPort.Open();
            _continue = true;
            readThread.Start();

            Console.WriteLine("ESC to exit");

            while (_continue)
            {
                while (Console.KeyAvailable)
                {
                    var key = Console.ReadKey(true);
                    if (key.Key == ConsoleKey.Escape)
                    {
                        _continue = false;
                    }
                    else if (_keyMappings.ContainsKey(key.Key))
                    {
                        var code = _keyMappings[key.Key];
                        _writeBuffer[0] = (byte)code;
                        _serialPort.Write(_writeBuffer, 0, _writeBuffer.Length);
                    }
                }               
            }

            readThread.Join();
            _serialPort.Close();
        }

        public static void ReadRaw()
        {
            while (_continue)
            {
                try
                {
                    while (_serialPort.BytesToRead > 0)
                    {
                        var next = (char)_serialPort.ReadByte();
                        Console.Write(next);
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex);
                }
            }
        }
    }
}