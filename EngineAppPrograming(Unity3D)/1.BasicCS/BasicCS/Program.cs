using System;
using System.Collections.Generic;

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
            //PlayerAttackMonsterMain();
            //CriticalAttackMain();
            //StageMain();
            //CriticalAttackWhileMain();
            //BattleMain();
            RPGMain();
            //Console.ReadLine();//종료방지
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
        //크리티컬데미지? 확률적으로 발생한다. 곱셈? -> 일정확률로 데미지가 150%의 데미지로 공격한다.
        //플레이어가 몬스터를 공격하면 (몬스터의 체력)이 (일정확률)로 만약 [크리티컬데미지가 발생하면 (플레이어의 데미지*1.5)만큼 하고], 아니라면 데미지만큼 감소한다..
        //플레이어가 몬스터를 공격하면 몬스터의 체력이 감소하는데, 이때 (일정확률)로 (크리니컬데미지가 발생하면 데미지의 1.5배만큼 감소)하고, 아니라면 데미지만큼 감소한다.
        //일정확률? 사건이 일어날 확률? 상자안에 공을 준비한 것중에서 1개를 뽑을 확률. -> 랜덤
        static void CriticalAttackMain()
        {
            int nPlayerDemage = 10;
            int nMonsterHp = 100;
            Random cRadom = new Random();
            int nRandom = cRadom.Next(0, 3);//프로그래밍에서는 항상0부터 시작한다.
            Console.WriteLine("1.MonsterHP:" + nMonsterHp );
            if (nRandom == 1)
            {
                nMonsterHp = nMonsterHp - (int)((float)nPlayerDemage * 1.5f);
                Console.WriteLine("Critical!!!:" + nPlayerDemage*1.5f);
            }
            else 
            {
                nMonsterHp = nMonsterHp - nPlayerDemage;
                Console.WriteLine("PlayerDemage:" + nPlayerDemage);
            }
            Console.WriteLine("2.MonsterHP:" + nMonsterHp);
            Console.WriteLine("Random:" + nRandom);
        }
        //가고 싶은장소를 입력받아, 입력받은 장소의 이름이 (마을,상점,필드)중 하나를 입력하면 ~입니다 라고 출력하고, 아니라면 !?!?!?!를 출력하라.
        //데이터: 입력장소를 저장할 변수 -> 문자열: string
        //알고리즘: 마을이면 마을입니다. 상점이면 상점입니다. 필드이면 필드입니다.
        static void StageMain()
        {
            string strInput;
            Console.WriteLine("가고싶은곳을 선택하세요!(마을,상점,필드)");
            strInput = Console.ReadLine();
            //Console.WriteLine(strInput + " 입니다."); //잘못입력한경우 정상적인 출력이 아님.
            //if (strInput == "마을")
            //    Console.WriteLine("마을 입니다.");
            //else if (strInput == "상점")
            //    Console.WriteLine("상점 입니다.");
            //else if (strInput == "필드")
            //    Console.WriteLine("필드 입니다.");
            //else
            //    Console.WriteLine("!?!?!?!?!?");
            switch(strInput)
            {
                case "마을":
                    Console.WriteLine(strInput + " 입니다.");
                    break;
                case "상점":
                    Console.WriteLine(strInput + " 입니다.");
                    break;
                case "필드":
                    Console.WriteLine(strInput + " 입니다.");
                    break;
                default:
                    Console.WriteLine("!?!?!?!?!?");
                    break;
            }
        }

        //플레이어가 몬스터를 공격하면 몬스터의 체력이 감소하는데, 이때 (일정확률)로 (크리니컬데미지가 발생하면 데미지의 1.5배만큼 감소)하고, 아니라면 데미지만큼 감소한다.
        //몬스터가 죽을때까지 -> 체력이 0이 된다. -> 몬스터가 살아있을때 공격한다. 죽으면 공격을 안함.
        //1.반복문의 조건을 적을때, 우선 무한 루프 돌리고 브레이크로 종료한다.
        //2.브레이크의 반대조건을 반복문의 조건으로 설정한다.
        static void CriticalAttackWhileMain()
        {
            int nPlayerDemage = 10;
            int nMonsterHp = 100;
            Random cRadom = new Random();
            //while (true)
            while (nMonsterHp > 0)
            {
                //if (nMonsterHp <= 0) break;
                int nRandom = cRadom.Next(0, 3);//프로그래밍에서는 항상0부터 시작한다.
                Console.WriteLine("1.MonsterHP:" + nMonsterHp);
                if (nRandom == 1)
                {
                    nMonsterHp = nMonsterHp - (int)((float)nPlayerDemage * 1.5f);
                    Console.WriteLine("Critical!!!:" + nPlayerDemage * 1.5f);
                }
                else
                {
                    nMonsterHp = nMonsterHp - nPlayerDemage;
                    Console.WriteLine("PlayerDemage:" + nPlayerDemage);
                }
                Console.WriteLine("2.MonsterHP:" + nMonsterHp);
                Console.WriteLine("Random:" + nRandom);
            }
        }

        //플레이어가 몬스터를 공격하면, 몬스터는 반격한다.
        //몬스터가 플레이어를 반격하면 몬스터의 공격력만큼 플레이어의 체력이 감소한다.
        //한쪽이 죽을때 까지 -> 몬스터가 죽거나, 플레이어가 죽으면 끝난다.
        //언제죽는가? 상대에게 공격당한 뒤
        static void BattleMain()
        {
            int nPlayerDemage = 10;
            int nMonsterHp = 100;

            int nMonsterDemage = 10;
            int nPlayerHP = 100;

            Random cRadom = new Random();
            while (true)
            {
                //플레이어가 몬스터를 공격한다.
                //if (nMonsterHp <= 0) break;
                int nRandom = cRadom.Next(0, 3);//프로그래밍에서는 항상0부터 시작한다.
                Console.WriteLine("1.MonsterHP:" + nMonsterHp);
                if (nRandom == 1)
                {
                    nMonsterHp = nMonsterHp - (int)((float)nPlayerDemage * 1.5f);
                    Console.WriteLine("Critical!!!:" + nPlayerDemage * 1.5f);
                }
                else
                {
                    nMonsterHp = nMonsterHp - nPlayerDemage;
                    Console.WriteLine("PlayerDemage:" + nPlayerDemage);
                }
                Console.WriteLine("2.MonsterHP:" + nMonsterHp);
                Console.WriteLine("Random:" + nRandom);
                if (nMonsterHp <= 0)
                {
                    Console.WriteLine("Player Win!");
                    break;
                }

                //몬스터가 플레이어를 공격한다.
                nRandom = cRadom.Next(0, 3);//프로그래밍에서는 항상0부터 시작한다.
                Console.WriteLine("1.PlayerHP:" + nPlayerHP); ;
                if (nRandom == 1)
                {
                    nPlayerHP = nPlayerHP - (int)((float)nMonsterDemage * 1.5f);
                    Console.WriteLine("Critical!!!:" + nMonsterDemage * 1.5f);
                }
                else
                {
                    nPlayerHP = nPlayerHP - nMonsterDemage;
                    Console.WriteLine("MonsterDemage:" + nMonsterDemage);
                }
                Console.WriteLine("2.PlayerHP:" + nPlayerHP);
                Console.WriteLine("Random:" + nRandom);
                if (nPlayerHP <= 0)
                {
                    Console.WriteLine("Monster Win!");
                    break;
                }

            }
        }
        //구조체: 정적할당된다. 값을 다른변수에 받을때 복사
        struct Player
        {
            public string strName;
            public int nHP;
            public int nDemage;
            public Player(string name, int hp, int dem)
            {
                strName = name;
                nHP = hp;
                nDemage = dem;
            }
            public void Attack(ref Player target)
            {
                target.nHP = target.nHP - this.nDemage;
            }
            public bool Death()
            {
                if (nHP > 0)
                    return false;
                else
                    return true;
            }
            public void Display(string msg)
            {
                Console.WriteLine("##### " + msg + " #######");
                Console.WriteLine("Name:" + strName);
                Console.WriteLine("Demage:" + nDemage);
                Console.WriteLine("HP:" + nHP);
                Console.WriteLine("###################");
            }
        }

        static void RPGMain()
        {
            Player sPlayer = new Player("player",100,10);

            List<Player> listMonsters = new List<Player>();
            listMonsters.Add(new Player("slime",100,10));
            listMonsters.Add(new Player("skeleton", 100, 10));
            listMonsters.Add(new Player("zombie", 100, 10));
            listMonsters.Add(new Player("dragon", 100, 10));

            while (true)
            {
                for (int i = 0; i < listMonsters.Count; i++)
                {
                    Console.WriteLine("[" + i + "]:" + listMonsters[i].strName);
                }
                int nIdx = int.Parse(Console.ReadLine());
                Console.WriteLine("Idx:" + nIdx);

                if (nIdx >= 0 && nIdx < listMonsters.Count) // 0 < idx < conut
                {
                    Player sMonster = listMonsters[nIdx];

                    Battle(sPlayer, sMonster);
                    Battle(sPlayer.nDemage, sPlayer.nHP, sMonster.nDemage, sMonster.nHP);
                }
                else
                {
                    Console.WriteLine("Exit");
                    break;
                }
            }

        }

        static void Battle(Player player, Player monster)
        {
            while (true)
            {
                if (player.Death() == false)
                {
                    player.Attack(ref monster);
                    monster.Display("Player Attack!");
                }
                else
                {
                    Console.WriteLine(monster.strName + " Win!");
                    break;
                }
                if (monster.Death() == false)
                {
                    monster.Attack(ref player);
                    player.Display("Monster Attack!");
                }
                else
                {
                    Console.WriteLine(player.strName + " Win!");
                    break;
                }
            }
        }

        static void Battle(int nPlayerDemage,int nPlayerHP, int nMonsterDemage, int nMonsterHp)
        {
            Random cRadom = new Random();
            while (true)
            {
                //플레이어가 몬스터를 공격한다.
                //if (nMonsterHp <= 0) break;
                int nRandom = cRadom.Next(0, 3);//프로그래밍에서는 항상0부터 시작한다.
                Console.WriteLine("1.MonsterHP:" + nMonsterHp);
                if (nRandom == 1)
                {
                    nMonsterHp = nMonsterHp - (int)((float)nPlayerDemage * 1.5f);
                    Console.WriteLine("Critical!!!:" + nPlayerDemage * 1.5f);
                }
                else
                {
                    nMonsterHp = nMonsterHp - nPlayerDemage;
                    Console.WriteLine("PlayerDemage:" + nPlayerDemage);
                }
                Console.WriteLine("2.MonsterHP:" + nMonsterHp);
                Console.WriteLine("Random:" + nRandom);
                if (nMonsterHp <= 0)
                {
                    Console.WriteLine("Player Win!");
                    break;
                }

                //몬스터가 플레이어를 공격한다.
                nRandom = cRadom.Next(0, 3);//프로그래밍에서는 항상0부터 시작한다.
                Console.WriteLine("1.PlayerHP:" + nPlayerHP); ;
                if (nRandom == 1)
                {
                    nPlayerHP = nPlayerHP - (int)((float)nMonsterDemage * 1.5f);
                    Console.WriteLine("Critical!!!:" + nMonsterDemage * 1.5f);
                }
                else
                {
                    nPlayerHP = nPlayerHP - nMonsterDemage;
                    Console.WriteLine("MonsterDemage:" + nMonsterDemage);
                }
                Console.WriteLine("2.PlayerHP:" + nPlayerHP);
                Console.WriteLine("Random:" + nRandom);
                if (nPlayerHP <= 0)
                {
                    Console.WriteLine("Monster Win!");
                    break;
                }

            }
        }

        //몬스터의 리스트를 만들고 슬라임,스켈레톤,좀비,드래곤을 저장하고,(이름)
        //리스트의 첫번째 마지막값을 확인한다.
        //리스트를 반복문을 이용해 리스트의 모든값을 출력한다.
        static void MonsterListMain()
        {
            List<string> listMonsters = new List<string>();
            listMonsters.Add("slime");
            listMonsters.Add("skeleton");
            listMonsters.Add("zombie");
            listMonsters.Add("Dragon");

            Console.WriteLine("[0]:"+listMonsters[0]);
            Console.WriteLine("[3]:" + listMonsters[3]);

            for(int i = 0; i < listMonsters.Count; i++)
            {
                Console.WriteLine("["+i+"]:" + listMonsters[i]);
            }
        }
    }
}
 