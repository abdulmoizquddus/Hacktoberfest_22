using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace FactorialExample
{
class Program
{
static void Main()
{
Console.WriteLine("Enter the number");
int n = Convert.ToInt32(Console.ReadLine());
long fact = Fact(n);
Console.WriteLine("factorial is {1}", n, fact);
Console.ReadKey();
}
private static long Fact(int n)
{
if (n == 0)
{
return 1;
}
return n * Fact(n - 1);
}
}
}