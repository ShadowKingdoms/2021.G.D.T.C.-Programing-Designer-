using System;

namespace BasicCS
{
    class Program
    {
        //프로그램이 실행되면 메인함수가 가장 먼저 실행된다.
        //콘솔: 텍스트명령어를 입력하여 프로그램을 실행함.
        //컴파일러: 코드를 분석하여 exe파일을 만들어준다.(오류가 있으면 알려준다.)
        static void Main(string[] args)
        {//구문: 중괄호. 함수나 클래스와 같이 공간을 구별하는 데 사용됨.
            //ValMain();//함수의 호출
            //BasicTestMain();
            CriticalAttackMain();
            Console.ReadLine();//종료방지
        }//구문끝
        //매개변수: 함수안에 값을 전달하는 변수
        static int Add(int a, int b)
        {
            //지역변수: 함수안에 사용가능한 변수
            int c = a + b;
            return c;//c의 값을 외부에 전달한다.
        }

        static void BasicTestMain()
        {
            Console.WriteLine("Hello World!");//세미콜론: 문장가장끝에 들어가는 문자.
            Console.WriteLine("Add:" + Add(80, 20));
        }

        static void ValMain()
        {
            //내용을 작성하세요.
            int nScore = 0;
            float fRat = 1 / 4; //정수형끼리계산하면 결과가 정수가 나온다.
            //float fRat = 1.0f/4.0f;

            Console.WriteLine("Score:" + nScore);
            Console.WriteLine("Rat:" + fRat);
        }

        static void CriticalAttackMain()
        {
            //
        }
    }
}
