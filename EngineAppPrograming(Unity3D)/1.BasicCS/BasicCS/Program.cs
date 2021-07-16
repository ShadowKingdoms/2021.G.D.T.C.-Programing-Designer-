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
            PlayerAttackMonsterMain();
            //CriticalAttackMain();
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
        //(플레이어?)가 (몬스터?)를 공격한다.
        //플레이어가 몬스터를 공격하면 (몬스터의 체력)이 (플레이어의 데미지)만큼 감소한다.
        //(단, 플레이어의 데미지는 10이고 몬스터의 체력은 100이다)
        //데이터: 몬스터의체력, 플레이어의 공격력 -> 변수: 정수형->int
        //알고리즘: 몬스터체력 - 플레이어공격력 = 몬스터체력
        //1.습관적으로 코드를 짜고 있다면 입력,출력을 생각없이 넣고있을수있다. 
        //2.데이터의 출력은 연산전 모든변수의 값과 연산후의 모든변수의 값을 출력하면, 프로그램이 정상작동하는가 확인할수있다.
        static void PlayerAttackMonsterMain()
        {
            int nPlayerDemage = 10;
            int nMonsterHp = 100;
            Console.WriteLine("1.MonsterHP:" + nMonsterHp +",PlayerDemage:"+nPlayerDemage);
            nMonsterHp = nMonsterHp - nPlayerDemage;
            Console.WriteLine("2.MonsterHP:" + nMonsterHp + ",PlayerDemage:" + nPlayerDemage);
        }

        static void CriticalAttackMain()
        {
            //
        }
    }
}
