using System;
using System.Diagnostics;

namespace TermMod
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Threading.Thread.Sleep(1000);

            while (true)
            {
                System.Threading.Thread.Sleep(500);

                Process[] taikou5List = Process.GetProcessesByName("taikou5");

                // すでに１つも無い
                if (taikou5List.Length == 0)
                {
                    return;
                }

                // Test to see if the process is responding.
                foreach (Process taikou5 in taikou5List)
                {
                    if (!taikou5.Responding)
                    {
                        taikou5.Kill();
                    }
                }
            }
        }
    }
}
