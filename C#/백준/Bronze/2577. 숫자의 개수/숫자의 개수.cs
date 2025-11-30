using System;

namespace Baekjoon
{
    class Program
    {
        static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());
            int B = int.Parse(Console.ReadLine());
            int C = int.Parse(Console.ReadLine());
            string result = (A*B*C).ToString();

            int[] count = new int[10] {0,0,0,0,0,0,0,0,0,0};

            for(int i=0; i<result.Length; i++)
            {
                count[int.Parse(result[i].ToString())]++;
            }

            for(int i=0; i<=9; i++)
            {
                Console.WriteLine(count[i]);
            }
        }
    }
}